#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
typedef struct node *nodeptr;
struct stack
     {
            int top;
            nodeptr item[1000];
     }s;

nodeptr maketree(nodeptr p,int number);
void setleft(nodeptr p,int number);
void setright(nodeptr p,int number);
void inorder(nodeptr p);
nodeptr brother(nodeptr p);
nodeptr pop(struct stack *s);
void push(struct stack *s,nodeptr p);
void postorder(nodeptr tree);
  void postorder1(nodeptr p);

typedef struct node
{
        int info;
        nodeptr left;
         nodeptr right;
         nodeptr father;
         int flag;

        } node;
int main()
{
//printf("in main ");
     nodeptr ptree,p,q;
     int number;
     scanf("%d",&number);
     p= NULL;
     ptree =maketree(p,number);
     scanf("%d",&number);
     while(number !=-1)
     {
         //printf("\n in while \n");
                                    p=q=ptree;
                                    while(number != p->info && q!= NULL)
                                    {
                                                 p=q;
                                                 if(number < p->info)
                                                 q= p->left;
                                                 else
                                                 q =p->right;
                                    }
                                    if(number == p->info)
                                    printf("duplicate %d",number);
                                    else if(number <  p->info)
                                    setleft(p,number);
                                    else
                                    setright(p,number);
                                    scanf("%d",&number);
     }
    //inorder(ptree);
    postorder1(ptree);
printf("\n\n");
postorder(ptree);
  getch();
  return 0;
}
nodeptr maketree(nodeptr p,int number)
{
        nodeptr q;
        q =(nodeptr)malloc(sizeof(node));
        q->info =number;
        q->left =NULL;
        q->right =NULL;
        q->father = p;
        q->flag=0;
        return q;
}
void setleft(nodeptr p,int number)
{
     if(p==NULL)
     printf("void insertion ");
     else
     p->left =maketree(p,number);
     }
void setright(nodeptr p,int number)
{
     if(p==NULL)
     printf("void insertion ");
     else
     p->right =maketree(p,number);
}

void inorder(nodeptr p)
{
     if(p!=NULL)
     {
                inorder(p->left);
                printf(" p is %d \n" ,p->info);
                if(p->father !=NULL)
                printf("father of p is %d \n" ,(p->father)->info);
                 inorder(p->right);
     }
}

void postorder(nodeptr tree)
{

            nodeptr p,q,t;
            s.top =-1;
            p=tree;
            do
            {
                   while(p!=NULL)
                   {

                                 push(&s,p);
                                 p=p->left;
                   }
                   if(s.top != -1)
                   {
                            q=s.item[s.top];
                            p =q->right;
                            if(p!=NULL && p->flag == 1)
                            {
                                  t =pop(&s);
                                  printf("%d ",t->info);
                                  if(t->father ==NULL)
                                  break;
                                  p =brother(t);
                            }

                   }
                   if(p ==NULL)
                   {          t =pop(&s);
                         printf("%d ",t->info);
                         }
            }while((s.top !=-1) || p!=NULL);

}
void push(struct stack *s,nodeptr p)
{
     if(s->top == 999)
     {
               printf("no more insertion");
               }
     else
     {        p->flag =1;
              s->item[++(s->top)]= p;}
}
nodeptr pop(struct stack *s)
{
        if(s->top ==-1)
        printf("underflow");
        else
        return s->item[(s->top)--];
}

nodeptr brother(nodeptr p)
{
        nodeptr q;


        if(p!=NULL && p->father !=NULL)
        {
                     q =p->father;
                     if(q->left == p)
                     return (q->right);
                     else
                     return NULL;
        }
}

  void postorder1(nodeptr p)
{
     if(p!=NULL)
     {
                postorder1(p->left);
                 postorder1(p->right);
                printf("\n%d" ,p->info);


     }
}




