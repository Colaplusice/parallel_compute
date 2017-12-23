#include <iostream>
using namespace std;

class a{
public :
a();

 char s;
};
class b :public a{
 char c;
  b();

};
 a::a(){
cout <<"请输入一个字符 ";
cin>>s;
}
b::b(){
cout<<"请输入一个字符：";
cin>>c;
if(c==s)
 cout<<"两个字符是相等的";
else cout<<"两个字符是不相等的;";
}
int main(void){
b w;
w.a();

}
