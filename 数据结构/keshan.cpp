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
cout <<"a���޲ι��캯�� ";

}
a::a(int a){
cout <<"a���вι��캯�� ";

}
b::b(){
cout<<"b���޲ι��캯��";

}
b::b(int c){
cout<<"b���вι��캯��";
}
a::~a(){
cout <<"a���������� ";
}
b:: ~b(){
 cout <<"b���������� ";
 }
int main (void)
{
b gd;
b grd(6);

}
