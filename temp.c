#include<stdio.h>
#include<stdlib.h>
typedef struct NodePtr
{
int v2;
struct NodePtr *l;
struct NodePtr *r;

}Node;

Node* createNode(int v2)
{
Node *node=(Node*)malloc(sizeof(Node));
node->v2=v2;
node->l = node->r=NULL;
return node;
}

Node* insert(Node *root,int v2)
{
if(root == NULL)
{
root=createNode(v2);
}
else if(v2 < root->v2)
{
root->l=insert(root->l,v2);
}
else if(v2 > root->v2)
{
root->r=insert(root->r,v2);
}
return root;

}

Node* findMinNode(Node *root)
{
if(root->l)
{
root=findMinNode(root->l);
}
return root;
}

Node* delete(Node* root,int v2)
{
if(root)
{
if(v2>root->v2)
{
root->r=delete(root->r,v2);
}
else if(v2<root->v2)
{
root->l=delete(root->l,v2);
}
else if(v2 == root->v2)
{
if(root->l && root->r)
{
Node *minNode= findMinNode(root->r);
root->v2=minNode->v2;
root->r=delete(root->r, minNode->v2);
}
else
{
Node *nodeToDelete=root;
if(root->l)
{
root=root->l;
}
else
{
root=root->r;
}
free(nodeToDelete);
}
}
}
return root;
}


void print(Node *root)
{
if(root)
{
printf("\n %d",root->v2);
print(root->l);
print(root->r);
}
}

int main()
{
Node *root=NULL;
root=insert(root,30);
root=insert(root,25);
root=insert(root,50);
root=insert(root,27);
root=insert(root,40);
root=insert(root,66);
root=insert(root,5);
root=insert(root,3);

print(root);
printf("\n \n \n");

delete(root,3);
print(root);
return 0;
}
