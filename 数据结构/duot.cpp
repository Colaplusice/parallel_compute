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
cout <<"������һ���ַ� ";
cin>>s;
}
b::b(){
cout<<"������һ���ַ���";
cin>>c;
if(c==s)
 cout<<"�����ַ�����ȵ�";
else cout<<"�����ַ��ǲ���ȵ�;";
}
int main(void){
b w;
w.a();

}
