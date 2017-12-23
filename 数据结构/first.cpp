//输出n个整数的全排列  输出n个整数的所有子集
#include <iostream>
using namespace std;
int n=0;

void swap(char*a,char *b)
{
char mid;
mid=*a;
*a=*b;
*b=mid;

}
void qpl(char list[],char a,char b)
{

 if (a>b)
  {
  for(int i=0;i<=b;i++)
  {
   cout<<list[i];
  }
  cout<<endl;
n++;
 }

  else
   {
   for(int i=a;i<=b;i++)
   {
    swap(&list[a],&list[i]);
    qpl(list,a+1,b);
    swap(&list[a],&list[i]);
   }
  }
}
int main(){
 char list[]="1234";
qpl(list,0,3);
cout<<""<<n<<endl;
return 0;
}
