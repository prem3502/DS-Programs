#include <stdio.h>
#include <stdlib.h>
struct node{
int data ;
struct node *left ;
struct node *right ;
};
struct node* maketree(){
struct node *p ;
int info ;
printf("Enter the info or -1 for null\n");
scanf("%d", &info) ;
if(info == -1) return NULL ;
p = (struct node *)malloc(sizeof(struct node)) ;
p->data = info ;
printf("Enter the left child of %d\n",info );
p->left = maketree() ;
printf("Enter the right child of %d\n",info );
p->right = maketree() ;
return p ;
}
void preorder(struct node *t){
if(t!=NULL){
printf("%d->", t->data) ;
preorder(t->left) ;
preorder(t->right) ;
}
}
void postorder(struct node *t){
if(t!=NULL){
postorder(t->left) ;
postorder(t->right) ;
printf("%d->", t->data) ;
}
}
void inorder(struct node *t){
if(t!=NULL){
inorder(t->left) ;
printf("%d->", t->data) ;
inorder(t->right) ;
}
}
int main(){
struct node *root ;
root = maketree();
printf("Preorder: ");
preorder(root) ;
printf("\n Postorder :");
postorder(root) ;
printf("\n Inorder");
inorder(root) ;
return 0 ;
}
/*OUTPUT:
Enter the info or -1 for null
1
Enter the left child of 1
Enter the info or -1 for null
2
Enter the left child of 2
Enter the info or -1 for null
-1
Enter the right child of 2
Enter the info or -1 for null
-1
Enter the right child of 1
Enter the info or -1 for null
3
Enter the left child of 3
Enter the info or -1 for null
-1
Enter the right child of 3
Enter the info or -1 for null
-1
Preorder: 1->2->3->
Postorder :2->3->1->
Inorder2->1->3->*/

