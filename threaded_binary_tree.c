#define FALSE 0		
#define TRUE 1
#include<stdio.h>
#include<conio.h>
typedef struct tree
{
        char data;
        struct tree *lchild,*rchild;
        short int rthread,lthread;
}tree;
void insert(tree *);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
main()
{
      tree *root,*leave,*nwptr,*head;
      printf("creating header node");
      char a ='-';
      nwptr=(tree *)malloc(sizeof(tree));      
      nwptr->data=a;
      nwptr->lchild=nwptr;
      nwptr->rchild=nwptr;
      nwptr->rthread=FALSE;        
      nwptr->lthread = TRUE;
      head=nwptr;
      leave=nwptr;
      root = insertroot(&head);
      insert(&root);
      printf("\n");
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
      postorder(root);
      getche();
}
tree * insertroot(tree **head)

{     printf("enter the data of root node");
      char ch;    
     ch=getche();     

     tree *nwptr;
     nwptr=(tree *)malloc(sizeof(tree));      
     nwptr->data=ch;
     nwptr->lchild=null;
         nwptr->lchild=null;      
       nwptr->rthread=true;        
       nwptr->lthread = true;
      
      
      *head->lchild=nwptr;
            
       *head->rthread=FALSE;        
       *head->lthread = FALSE;
      return nwptr;
      
 }

void insert(tree **root)
{    
     tree *nwptr;
     char a;
     char ch;
     printf("\ndoes the node containing %c have left child y/n ?",*root->data);
     ch=getche();     
     
     if(ch=='y')
     {
                printf("\nenter the value of left child");
                *root->lthread = FALSE;
                a=getche();
                nwptr=(tree *)malloc(sizeof(tree));
                nwptr->data=a;
                nwptr->lchild=presucc(nwptr);
                nwptr->rchild=possucc(nwptr);
                root->lchild=nwptr;
    
    insert(root->lchild );
     }
 printf("\ndoes the node containing %c have right child y/n ?",root->data);
     ch=getche();
     if(ch=='y')
     {
                printf("\nenter the value of right child");
                a=getche();
                nwptr=(tree *)malloc(sizeof(tree));
                nwptr->data=a;
                nwptr->lchild=NULL;
                nwptr->rchild=NULL;
                root->rchild=nwptr;
    
    insert(root->rchild );
     }
}     
             
void inorder(tree *root)
{
     if(root!=NULL)
     {
                   inorder(root->lchild);
                   printf("%c",root->data);
                   inorder(root->rchild);
     }
}
void preorder(tree *root)
{
     if(root!=NULL)
     {
                   printf("%c",root->data);
                   preorder(root->lchild);
                   preorder(root->rchild);
     }                   
}   
void postorder(tree *root)
{
     if(root!=NULL)
     {
                   postorder(root->lchild);
                   postorder(root->rchild);
                   printf("%c",root->data);
     }                   
}   
