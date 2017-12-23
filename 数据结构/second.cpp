#include <iostream>
using namespace std;
void build(char*str,int *a,int n){
if(n==4){
   cout<<"{";
   for(int i=0;i<4;i++)
    if(a[i]==1)
     cout<<str[i];
     cout<<"}"<<endl;
     return ;


}
a[n]=0;
build(str,a,n+1);
a[n]=1;
build(str,a,n+1);

}
int main(){
 char s[4]={'a','b','c','d'};
 int a[4];
 build(s,a,0);
 return 0;
}
