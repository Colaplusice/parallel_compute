#include<iostream>
using namespace std;
//template <class T>
//class listiterator{
//public :
// T *initialize(const lists<T> &c){
// location=c.first;
// }
//private:
// Node<T> *location;
//};
template <class T>
class Node{
 public:
Node <T>*link;//指针
T data;
};

template <class T>
class lists{
// friend listiterator<T>;
public :
 lists(){ first=0; }
  <T>& Insert(int k, const T&x);
void Output(ostream&out)const;
Node<T> *first;
Node<T> *last;

 };
template <class T>
lists<T>& lists<T>::Insert(int k, const T&x){//k为插入的位置，x为元素大小
Node <T> *p=first;
if(k<0){cout<<"输入的数太小了";}
for(int index=1;index<k&&p;index++){
 p=p->link;
}
Node<T> *y=new Node<T>;
 if(k){y->link==p->link;
 p->link=y;}
}
template <class T>
void lists<T>::Output(ostream&out)const{
Node <T>*current;
for(current=first;current;current=current->link)
 out<<current->data<<" ";
}
template <class T>
ostream& operator<<(ostream& out,const lists<T> &x){
x.Output(out);
return out;}

int main(){
 lists <int>a;

a.Insert(2,3);
a.Output(a);
 return 0;
}
