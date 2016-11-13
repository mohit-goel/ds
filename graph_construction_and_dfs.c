#define MAXSIZE 100

#include<stdio.h>
#include<stdlib.h>
typedef struct  graph
{
      int data;
      struct  graph *next;
}graph;
void dfs(int v);
void bfs(int v);
void addq(int v);
int deleteq();
void delgraph(graph *a[]);
int n;
int visited[MAXSIZE] ;
graph *a[MAXSIZE];
int front ,rear;
int q[];

main()
{

    int i,v;
    int b=0;
    printf("enter the number of vertices");
    scanf("%d",&n);

   for(i = 0;i<n;i++)
   a[i] = NULL;

        for(i = 0;i<n;i++)
        visited[i] =0;
     graph *t,*x;


    for(i = 0;i<n;i++)
    {
          char ch;
          printf("\n want to enter vertex adjacent to the vertex %d y/n    ",i);
          getchar();
          ch = getchar();

          while(ch=='y')
          {
                      int v;

                     x = (graph*)malloc(sizeof(graph));
                      printf("\nenter the required vertex   ");
                     scanf("%d",&v);


                     if(a[i] == NULL)
                     {
                             x->data= v;
                             a[i] = x;
                             t = a[i];
                             t->next=NULL;

                     }
                     else
                     {
                             x->data= v;
                             t->next = x;
                             t=x;
                             t->next=NULL;

                     }
                     printf(" want enter more vertex adjacent to the vertex %d y/n ",i);
                     getchar();
                     ch = getchar();
         }
   }
   printf("\nadjacency list is");
     for(i = 0;i<n;i++)
     {    printf("\n");
           t = a[i];
           printf("%d   ",i);
           while(t!=NULL)
           {
                         printf("%d ---> ",t->data);
                         t = t->next;
           }
     }
     printf("dfs is");
     dfs(b);
}

void dfs(int v)
{
        graph*w;
        visited[v] = 1;
        printf("%d    ",v);
        for(w=a[v] ;w;w=w->next)
        {
                   if(!visited[w->data])
                   dfs(w->data);

        }
}












