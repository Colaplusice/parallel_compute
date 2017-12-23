#include<iostream>
using namespace std;
struct Node{
Node *link;
int data;
}; Node*List;
// void Search(int k,int &x){//查找第k个元素，传值给X
//   Node *current=first;
//   int index=1;
//   for(index<k;index++;){
//    current==current->link;
//
//   }
//   x=current->data;
// }
 int ListLength(List A) {   //求得带头结点单链表的长度
   Node *p;
     int count=0;
      p=A->link;
       while(p!=NULL)
         {
          p=p->link;
       count++;
       }
       return count;
        }
int add()
{



}
