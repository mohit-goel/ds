// Singly circular linked list creation
#include<stdio.h>
#include<conio.h>

typedef struct node
{
        int item;
        struct node * next;
}node;
node * createlist(node **,node *);
printlist(node *);
node *q;
      
       
main()
{
      node * p,*a,*start1,*start2,*r1,*r2,*last1;
      char ch; 
      ch = 'y';
      
      start1 = NULL;
     
     
      
      while(ch ==('y'))
      {
           p = createlist(&start1,p);     
         printf("want to insert 1 more node than press y\n");
         ch = getche();
      }
       printf("\ncircular linked list 1 is");
       printlist(p);
       ch ='y';
     start2 = NULL;
     
       
      
        while(ch ==('y'))
      {
           a = createlist(&start2,a);     
         printf("want to insert 1 more node than press -y\t");
         ch = getche();
      }
       printf("circular linked list 2 is\n");
      printlist(a);
      printf("inserting circular linked lists 2 b/w 1\n");
      last1= p;
      while(last1->next!=p)
      last1= last1->next;
      last1->next= start2;
      a->next = p;
      
      
      printlist(p);
      
       getch();  
       
 }
       
 node * createlist(node **start,node * r)
 { 
       int n;
       

        q = (node*)malloc(sizeof(node));
      if(*start == NULL)
      {
               *start = q;
               r =*start;
               scanf("%d",&n);
               r ->item = n;
               
      }        
      
      else
      {
              r ->next = q;
              r = q;
               scanf("%d",&n);
              r->item = n;
              
      }
      r->next = *start;
      return r;
               
  }
 
  printlist(node * t)
  {     node * last;
        last = t;
        do 
        {
              printf("%d\t",last->item);
              last = last->next;
        } while(last!=t);
  }
