#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define qsize 100
struct mqueue{
char items[qsize][200];
int front,rear;
int count;
}; 
char msg[100];
void enqueue(struct mqueue *q, char msg[])
{
    if(q->count==qsize)
    {
        printf("overflow");
        exit(0);
    }
    q->rear = (q->rear+1)%qsize;
    strcpy(q->items[q->rear],msg);
    q->count++;
}
void  dequeue(struct mqueue *q,char msg[])
{
    if(q->count==0)
    {
        printf("underflow");
        exit(0);
    }
    q->front = (q->front+1)%qsize;
    q->count--;
    strcpy(msg,q->items[q->front]);
}
void  display(struct mqueue q)
{
    int j;
    if(q.count==0)
    {
        printf("empty");
        return;
    }
    j=q.front;
    do{
    j = (j+1)%qsize;
    printf("%s \n",q.items[j]);
    }while(j!=q.rear);
}
int main()
{

    struct mqueue m;
    int i,ch;
    char msg[200];
    m.front= qsize-1;
    m.rear= qsize-1;
    m.count=0;
    while(1)
    {
     printf("choice\n");
     scanf("%d",&ch);
        if(ch==1)
         {
           printf("Enter a message\n");
           scanf("%s",msg);
	        enqueue(&m,msg);
         }
        else if(ch==2)
        {
          dequeue(&m,msg);
          printf("the deleted element is");
          printf("%s\n",msg);
        }
        else if(ch==3)
           display(m);
        else
        {
            printf("WRONG CHOICE \n");
            exit(0);
        }

    }

}
