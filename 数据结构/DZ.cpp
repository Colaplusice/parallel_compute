#include<iostream>
using namespace std;
const int Size=10;
template <class T>
class Stack{
 int top;
  T arr[Size];
public:
 Stack(){top=0;}//栈为空
 void push(T a);
 int pop();
 void print();
 int lengh(Stack g);

};
template <class T>
void Stack<T>::push(T a){
if(top==Size) {cout<<"栈满了"; return;}
arr[top]=a;
top++;
}
template <class T>
 void Stack<T>::print(){
//while(top){
//   cout<<arr[top];
//  top--;
//
//}
for(int i=0;i<top;i++){
 cout<<arr[i]<<endl;
}
 }
 template <class T>
int  Stack<T>::lengh(Stack g){
int index=0;
for(g.top;g.top>0;g.top--){
 index++;
}
return index;
}
int main(){

cout<<"请输入要放在栈内的元素个数，不能大于10"<<endl;
int s;
cin>>s;
 int sun[s];
if(s>10) return 0;
for(int i=1;i<s+1;i++){
 cout<<"请输入元素"<<i<<endl;
 int m;
 cin>>m;
sun[i-1]=m;

}
Stack<int> st;//实例化

for(int i=0;i<s;i++){

st.push(sun[i]);
//st.print();

}
st. (st);
return 0;
}
