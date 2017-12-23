#include <iostream>
using namespace std;
struct time{
int mini;
int  hour;
};
const int min_h=60;
 time add(time t1,time t2){
time t3;
t3.mini=(t1.mini+t2.mini)% min_h;
t3.hour =t1.hour+t2.hour+(t1.mini+t2.mini)/min_h;
return t3;
}

void show(time t0){
cout<<"Ð¡Ê±£º"<<t0.hour<<"·ÖÖÓ£º"<<t0.mini;
}
int main(){
time se={30,5};
time sr={42,6};
time no= (se,sr);
//add(se,sr,no);
show(no);
return 0;
}
