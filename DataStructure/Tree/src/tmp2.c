#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*二叉树的链式存储表示*/
typedef char DataType; /*应由用户定义DataType的实际类型*/
typedef struct node
{
 DataType data;
 node *lchild, *rchild; /*左右孩子指针*/
} BinTNode;   /*结点类型*/
typedef BinTNode *BinTree;
int sum=0;
void DisplayBinTree(BinTree T); /*用格文本形式表示二叉树*/
void CreateBinTree(BinTree *T); /*构造二叉链表*/
void Preorder(BinTree T); /*前序遍历二叉树*/
void Inorder(BinTree T); /*中序遍历二叉树*/
void Postorder(BinTree T); /*后序遍历二叉树*/
int nodes(BinTree T);  /*计算总结点数*/
int leafs(BinTree T);  /*计算总叶子数*/
int hight(BinTree T);  /*计算二叉树的高度*/
int find(BinTree T,char x); //查找值=x的节点的个数；
int main()
{
 BinTree T;
 char flg;
 while(cin>>flg)
 switch(flg)
 {
 case'C':
  getchar();
  CreateBinTree(&T);
  cout<<"Created success!"<<endl;
  break;
 case'H':
  cout<<"Height="<<hight(T)<<"."<<endl;
  break;
 case'L':
  cout<<"Leaf="<<leafs(T)<<"."<<endl;
  break;
 case'N':
  cout<<"Nodes="<<nodes(T)<<"."<<endl;
  break;
 case'1':
  printf("Preorder is:");
  Preorder(T);
  cout<<"."<<endl;
  break;
 case'2':
  printf("Inorder is:");
  Inorder(T);
  cout<<"."<<endl;
  break;
 case'3':
  printf("Postorder is:");
  Postorder(T);
  cout<<"."<<endl;
  break;
 case'F':
  char x;
  int ko;
  getchar();
  cin>>x;
  ko=find(T,x);
  cout<<"The count of "<<x<<" is "<<ko<<"."<<endl;
  break;
 case'P':
  cout<<"The tree is:"<<endl;
  DisplayBinTree(T);
  break;
 default:
  cout<<"输入有误，请重新输入"<<endl;
 }
}

/*构造二叉链表*/
void CreateBinTree(BinTree *T)
{
 char ch;
 if ((ch=getchar())=='#')
 *T=NULL;
 else
 {
 /*读入非空格*/
 *T=(BinTNode *)malloc(sizeof(BinTNode));/*生成结点*/
 (*T)->data=ch;
 CreateBinTree(&(*T)->lchild );  /*构造左子树*/
 CreateBinTree(&(*T)->rchild );  /*构造右子树*/
 }
}
/*用缩格文本形式表示二叉树*/
void DisplayBinTree(BinTree T)
{
 BinTree stack[100],p;
 int level[100],top,n,i;
 if (T)
 {
 top=1;
 stack[top]=T;
 level[top]=0;
 while(top>0)
 {
  p=stack[top];
  n=level[top];
  for (i=1; i<=n; i++)
  cout<<" ";
  printf("%c\n",p->data);
  top--;
  if (p->rchild!=NULL)
  {
  top++;
  stack[top]=p->rchild;
  level[top]=n+2;
  }
  if (p->lchild!=NULL)
  {
  top++;
  stack[top]=p->lchild;
  level[top]=n+2;
  }
 }
 }
}
/*计算总结点数*/
int nodes(BinTree T)
{
 if(T)
 {
 if( (T->lchild==NULL)&&(T->rchild==NULL))
  return 1;
 else
  return nodes(T->lchild)+nodes(T->rchild)+1;
 }
 return 0;
}
/*计算总叶子数*/
int leafs(BinTree T)
{
 if(T)
 {
 if ((T->lchild==NULL)&&(T->rchild==NULL))
  return 1;
 else
  return leafs(T->lchild)+leafs(T->rchild);
 }
 return 0;
}
/*计算树的高度*/
int hight(BinTree T)
{
 if(T)
 {
 if ((T->lchild==NULL)&&(T->rchild==NULL))
  return 1;

 else if((T->lchild==NULL)&&(T->rchild))
  return 1+hight(T->rchild);

 else if((T->lchild)&&(T->rchild==NULL))
  return 1+hight(T->lchild);

 else
  return hight(T->lchild)+hight(T->rchild);
 }
 return 0;
}
/*前序遍历二叉树*/
void Preorder(BinTree T)
{
 if(T)
 {
 printf("%c ",T->data); /*访问结点*/
 Preorder(T->lchild);
 Preorder(T->rchild);
 }
}
/*中序遍历二叉树*/
void Inorder(BinTree T)
{
 if(T)
 {
 Inorder(T->lchild);
 printf("%C ",T->data);
 Inorder(T->rchild);
 }
}
/*后序遍历二叉树*/
void Postorder(BinTree T)
{
 if(T)
 {
 Postorder(T->lchild);
 Postorder(T->rchild);
 printf("%C ",T->data);
 }
}
int find(BinTree T,char x)
{
 if(T)
 {
 if((T->data)==x)
  sum++;
 find(T->lchild,x);
 find(T->rchild,x);

 }
 return sum;
}
