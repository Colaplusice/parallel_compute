#include<iostream>
using namespace std;
struct Node{
Node *link;
int data;
}; Node*List;
// void Search(int k,int &x){//���ҵ�k��Ԫ�أ���ֵ��X
//   Node *current=first;
//   int index=1;
//   for(index<k;index++;){
//    current==current->link;
//
//   }
//   x=current->data;
// }
 int ListLength(List A) {   //��ô�ͷ��㵥����ĳ���
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
