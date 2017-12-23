#include<iostream>
using namespace std;
const int Size=10;
template <class T>
class Dz{
 int top;
 public:
Dz(){top=0;}
void push(T a);
int pop(T s);
void print();
private :
 T arr[Size];
};

template <class T>
void Dz<T>::push(T a)
{
if(top==Size){ cout<<"ย๚มห"; return;}
arr[top]=a;
top++;
}
template <class T>
int Dz<T>::pop(T s){
arr[top]=s;
top--;
return s;
}
template <class T>
void Dz<T>::print(){

  cout<<arr[0];

}
int main(){
Dz<int> as;
as.push(5);
as.print();
return 0;

}
