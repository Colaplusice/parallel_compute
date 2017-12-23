#include <iostream>
using namespace std;

class a{
public :
a();
a(int a);
~a();
int s;
};

class b : public a{

public:
 char c;
  b();
  b(int c);
  ~b();
};
 a::a(){
cout <<"a的无参构造函数 ";

}
a::a(int a){
cout <<"a的有参构造函数 ";

}
b::b(){
cout<<"b的无参构造函数";

}
b::b(int c){
cout<<"b的有参构造函数";
}
a::~a(){
cout <<"a的析构函数 ";
}
b:: ~b(){
 cout <<"b的析构函数 ";
 }
int main (void)
{
b gd;
b grd(6);

}
