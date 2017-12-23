
#include <iostream>
using namespace std;
int sum[]={5,3,6,4,7,1,2,9,8};
int Ran[9]; int sun[9];
Swap(int *arr,int i,int j){
int temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
void maopao(int *sun){
for(int i=0;i<9;i++){
 for (int j=8;j>i;j--){
  if(sun[j]<sun[j-1]){
    int temp;
    temp=sun[j];
    sun[j]=sun[j-1];
    sun[j-1]=temp;
  }
 }
}
}
void output(int *arr,int n){
 for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";
 }
}
void Rank(int *sum,int arr[],int n){
for (int i=0;i<n;i++){//初始化
  arr[i]=-1;
}
for (int i=0;i<n;i++)  //arr[]存放名次
{
 for(int j=0;j<n;j++)
 {
 if(sum[i]>sum[j]) arr[i]++;
 }
}
}
void Ranksort(int *u,int *arr,int *sum,int n){
for(int i=0;i<n;i++){
u[arr[i]]=sum[i];        //存放排序好的元素
}
}
void divide(int *arr,int left,int right ){
int m=left;
for(int i=m+1;i<right;i++){
   if(arr[i]<arr[m]){
  arr[m+1]=arr[i];
   m++;
   }
}
Swap(arr,left,m);
}
void quicksort(){


 }












int main(){
//maopao(sum);
//Rank(sum,Ran,9);
//Ranksort(sun,Ran,sum,9);
divide(sum,0,9);
output(sum,9);

}
