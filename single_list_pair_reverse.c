//Given a singly linked list, write a function to swap elements pairwise
#include<stdio.h>
#include<stdlib.h>
typedef struct node * nodeptr;
typedef struct node
{
    int data;
    nodeptr next;
}node;
void reverse(nodeptr * head);
int main()
{
nodeptr p=NULL,q=NULL,head=NULL;
int n,num;
char ans;
printf("want to enter elements");
scanf("%c",&ans);
while(ans == 'y')
{
fflush(stdin);
    printf("enter number");
    scanf("%d",&num);
    p = (nodeptr)malloc(sizeof(node));
    p->data = num;
    p->next =NULL;

    if(head == NULL)
    {
        head = p;
        q= p;
        }
        else
        {
            q->next = p;
            q=p;
        }
        fflush(stdin);
        printf("want to enter elements");
scanf("%c",&ans);
}

reverse(&head);
p=head;
while(p!=NULL)
{
    printf("%d",p->data);
    p=p->next;
}
return 0;
}

void reverse(nodeptr * head)
{
    nodeptr p=NULL,q=NULL,t=NULL;
    if(*head == NULL  || (*head)->next == NULL)
    return ;

else{
    p = *head;
    q = (*head)->next;
    *head = q;
    t = q->next;
    q->next = p;
     reverse(&t);
     p->next = t;
}
    }
