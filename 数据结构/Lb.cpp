#include<iostream>
using namespace std;
struct Node{
Node *link;
int data;
};
class listsnode{
public:
 listsnode(){first=0;}
 boolIsempty(){return first==0;}
int Insert(int a,int &b);
int  Search(int k,int &x);
int lengh();

 Node *first;
};
 void add(int a,int &b){
 //current=new Node();
//current=first;
 }
 int listsnode:: Search(int k,int &x){//查找第k个元素，传值给X
   Node *current=first;
   int index=1;
   for(index<k;index++;){
    current==current->link;
   }
   x=current->data;
   return 0;
 }
 int listsnode::Insert(int a,int &b){//在a处插入数值b
 if(!a) return out_of_range;
 Node *current=first;
 int index=1;

 for(index<a-1;index++;){
  current==current->link;
 }
 Node *p;
 p=current->link;
 //p->data=b;

 Node *q;
 q->data=b;
 q->link=p;
 }
int listsnode::lengh(){
int s;
Node *current=first;
while (current){
 current=current->link;
 s++;
}
return s;
}

int main(){
listsnode a;
a.boolIsempty();
return 0;
}
