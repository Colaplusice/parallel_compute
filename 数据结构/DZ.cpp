#include<iostream>
using namespace std;
const int Size=10;
template <class T>
class Stack{
 int top;
  T arr[Size];
public:
 Stack(){top=0;}//ջΪ��
 void push(T a);
 int pop();
 void print();
 int lengh(Stack g);

};
template <class T>
void Stack<T>::push(T a){
if(top==Size) {cout<<"ջ����"; return;}
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

cout<<"������Ҫ����ջ�ڵ�Ԫ�ظ��������ܴ���10"<<endl;
int s;
cin>>s;
 int sun[s];
if(s>10) return 0;
for(int i=1;i<s+1;i++){
 cout<<"������Ԫ��"<<i<<endl;
 int m;
 cin>>m;
sun[i-1]=m;

}
Stack<int> st;//ʵ����

for(int i=0;i<s;i++){

st.push(sun[i]);
//st.print();

}
st. (st);
return 0;
}
