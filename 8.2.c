/* Ctrl+Z yazana kadar devam eder*/
#include <stdio.h>
#include <stdlib.h>
struct  node {
	struct  node  *left ;
	int  info ;
	struct  node  *right;
	};
typedef struct node *NODEPTR;
NODEPTR maketree(int);
NODEPTR getnode(void);
void intrav(NODEPTR);
void main()
{
int number;
NODEPTR root , p , q;
  printf("%s\n","Enter First number");
  scanf("%d",&number);
  root=maketree(number); /* insert first root item */
   printf("%s\n","Enter the other numbers");


while(scanf("%d",&number) !=EOF)
  {  p=q=root;
    /* find insertion point */
    while((number !=p->info) && q!=NULL)
     {p=q;
       if (number <p->info)
		       q = p->left;
		       else
		       q = p->right;
    }
    q=maketree(number);
    /* insertion */
    if (number==p->info)
		      printf("%d is a duplicate \n",number);
		      else if (number<p->info)
                                          p->left=q;
					 else  p->right=q;
  }
   system("cls");
   printf("Tree Created \n");
   /* inorder Traversing  */

   intrav(root);
  }

void intrav(NODEPTR tree)
{
if(tree != NULL){
intrav(tree->left);
printf("%d\n", tree->info);
intrav(tree->right);
}
}

NODEPTR maketree(int x)
{
NODEPTR p;
p = getnode();
p->info = x;
p->left = NULL;
p->right = NULL;
return p;
}

NODEPTR getnode(void)
{
 NODEPTR p;
p=(NODEPTR) malloc(sizeof(struct node));
return p;
}
