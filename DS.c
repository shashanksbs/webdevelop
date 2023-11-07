#include<stdio.h>
#include<stdlib.h>
#define size 12
void construct(int arr[],int n);
void levelorder();
struct node
{
 struct node *lchild,*rchild;
 int info;
};
 typedef struct node *NPTR;
 NPTR tree=NULL;
 void main()
{
 int arr[size],n,i;
 printf("enter the number of elements\n");
 scanf("%d",&n);
 printf("enter the %d elements\n");
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
 construct(arr,n);
 printf("levelorder traverse\n");
 levelorder();
}
 void construct(int arr[size],int n)
{
 int i,front=0,rear=-1;
 NPTR Q[size],ptr,temp;
 for(i=0;i<n;i++)
 {
   ptr=(NPTR)malloc(sizeof(struct node));
   ptr->info=arr[i];
   ptr->lchild=ptr->rchild=NULL;
   Q[++rear]=ptr;
   if(i==0)
     tree=ptr;
   else
   {
     temp=Q[front];
     if(temp->lchild==NULL)
       temp->lchild=ptr;
      else
      {
	temp->rchild=ptr;
	front++;
	}
      }
     }
    }
void levelorder()
{
 NPTR Q[size];
 NPTR p;
 int front=0,rear=-1;
 Q[++rear]=tree;
 while(front<=rear)
 {
   p=Q[front++];
   printf("%d\t",p->info);
   if(p->lchild!=NULL)
     Q[++rear]=p->lchild;
    if(p->rchild!=NULL)
     Q[++rear]=p->rchild;
 }
}