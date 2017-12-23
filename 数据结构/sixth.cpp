#include <iostream>
using namespace std;

class OutOfBounds
{
public:
    OutOfBounds(){}
};
class NoMem
{
public:
    NoMem(){}
};
template <class T>
class Node
{
    friend LinkedQueue<T>;
private:
    T data;
    Node<T>* link;
};
template <class T>
class LinkedQueue
{



public:
    LinkedQueue(){front=rear=NULL;}
    ~LinkedQueue();
    bool IsEmpty() const{return front==NULL;}
    bool IsFull() const;
    T First() const;
    T Last() const;
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);
private:
    Node<T>* front;
    Node<T>* rear;

};
template <class T>
LinkedQueue<T>:: ~LinkedQueue()
{
    Node<T>* next;
    while(front)
    {
        next=front->link;
        delete front;
        front=next;
    }
}

template <class T>
bool LinkedQueue<T>:: IsFull() const
{
    try
    {
        Node<T>* p=new Node<T>;
        delete p;
        return false;
    }
    catch(NoMem())
    {
        return true;
    }
}

template <class T>
T LinkedQueue<T>:: First()const
{
    if(IsEmpty())
        throw OutOfBounds();
    return front->data;
}

template <class T>
T LinkedQueue<T>:: Last() const
{
    if(IsEmpty())
        throw OutOfBounds();
    return rear->data;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>:: Add(const T& x)
{
    Node<T>* p=new Node<T>;
    p->data=x;
    p->link=NULL;
    if(front==NULL)
        front=p;
    else
    {
        rear->link=p;
    }
    rear=p;
    return *this;
}

template <class T>
LinkedQueue<T>& LinkedQueue<T>:: Delete(T& x)
{
    if(IsEmpty())
        throw OutOfBounds();
    Node<T>* p=front;
    x=p->data;
    if(front==rear)
      front=rear=NULL;
    else
        front=front->link;
    delete p;
    return *this;

}
template <class T>
class bBtree{//二叉树节点类
friend void visit(bBtree<T> *t);
friend void inorder(bBtree<T> *t);
friend void preorder(bBtree<T> *t);
friend void postorder(bBtree<T> *t);
friend void levelorder(bBtree<T> *t);
friend void main();
public:
 bBtree(){
      leftchild=rightchild=0;
      }
      bBtree(const T &e){
       data=e;
       leftchild=rightchild=0;

      }
      bBtree(const T &e,bBtree *l,bBtree *r){
       data=e;
       leftchild=l;
       rightchild=r;
      }
private :
 T data;
 bBtree <T>*leftchild;
 bBtree <T> *rightchild;
};
class badinput{
badinput(){
cout<<"错误的输入";
}
};
template <class T>
 void preorder(bBtree<T> *t){//前序
if(t){
 visit(t);
 preorder(t->leftchild);
 preorder(t->rightchild);
}
}
template <class T>
 void postorder(bBtree<T> *t){//后序
if(t){
 postorder(t->leftchild);
 postorder(t->rightchild);
  visit(t);
}
}
template <class T>
 void inorder(bBtree<T> *t){//中序
if(t){
 inorder(t->leftchild);
 visit(t);
 inorder(t->rightchild);
}
}
template <class T>
void infix(bBtree<T> *t){ //完全括号化的中缀表达式
if(t){
 cout<<"(";
 infix(t->leftchild);
 cout<<t->data;
 infix(t->rightchild);
 cout<<")";
}
}
template <class T>
void prefix(bBtree<T> *t)//前缀表达式
{
 if(t){
  cout<<t;
  prefix(t->leftchild);
  prefix(t->rightchild);
 }

}
template <class T>//后缀表达式
void postfix(bBtree<T> *t)
{
 if(t){
  prefix(t->leftchild);
  prefix(t->rightchild);
  cout<<t;
 }

}
template <class T>
void levelorder(bBtree<T> *t){
LinkedQueue <bBtree<T>*t>Q;
while(t){
 visit(t);
 if(t->leftchild) Q.Add(t->leftchild);
 if(t->rightchild)Q.Add(t->rightchild);

 try{Q.Delete(t);}
 catch(OutOfBounds){
    return ;}

}
}
template <class T>
class Btree{//二叉树类定义
public:
 Btree(){root=0;};
 bool IsEmpty()const{
   return ((root)?true:false)};
 ~Btree(){};
 bool Root(T&x)const;
 void makeTree(const T&element,Btree<T>&left,Btree<T>&right);
 void breakTree(T&element,Btree<T>&left,Btree<T>&right);
 void preorder(void (*visit)(Btree <T>*u))
 {
  preorder(visit,root);
 }
void inorder(void (*visit)(bBtree <T>*u))
 {
  inorder(visit,root);
 }
void postorder(void (*visit)(bBtree <T>*u))
 {
  postorder(visit,root);
 }
void levelorder(void (*visit)(bBtree <T>*u));
private:
 bBtree<T> *root;//根节点指针
void inorder(void (*visit)(bBtree <T>*u),bBtree<T>*t);
void preorder(void (*visit)(bBtree <T>*u),bBtree<T>*t);
void postorder(void (*visit)(bBtree <T>*u),bBtree<T>*t);
};
template <class T>
void makeTree(const T&element,Btree<T>&left,Btree<T>&right){

root=new bBtree<T>(element,left.root,right.root);

left.root=right.root=0;
}
template <class T>
void Btree<T>::breakTree(const T&element,Btree<T>&left,Btree<T>&right){
if(!root) throw badinput();
element=root.data;
left.root=root->leftchild;
right.root=root->rightchild;
delete root;
}
template <class T>
 void  Btree<T>::preorder(void (*visit)(bBtree <T>*u),bBtree<T>*t)
{//前序遍历
 if(t){
  visit(t);
  preorder(visit,t->leftchild);
   preorder(visit,t->rightchild);
 }
}
template <class T>
void  Btree<T>::inorder(void (*visit)(bBtree <T>*u),bBtree<T>*t){
if(t){
 inorder(visit,t->leftchild);
 visit(t);
 inorder(visit,t->rightchild);
}

}
template <class T>
void  Btree<T>::postorder(void (*visit)(bBtree <T>*u),bBtree<T>*t){
 if(t){
  postorder(visit,t->leftchild);
  postorder(visit,t->rightchild);
  visit(t);
 }

}
template <class T>
void  Btree<T>::levelorder(void (*visit)(bBtree <T>*u)){
LinkedQueue <bBtree<T>*t>Q;
bBtree <T>*t;
t=toot;

while(t){
  visit(t);
  if(t->leftchild) Q.add(leftchild);
  if(t->rightchild) Q.add(rightchild);
  try{Q.delete(t);}
  catch(outofbounds){return;}
}

}

int cot=0;
Btree<int> a,x,y,z;
template <class T>
void ct(bBtree<T>*t){cot++;}
int main(void){

y.makeTree(1,a,a);
z.makeTree(2,a,a);
x.makeTree(3,y,z);
y.makeTree(4,x,a);
y.preorder(ct);
cout<<cot<<endl;

}










