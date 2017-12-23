#include<iostream>
using namespace std;
class Node{
Node *link;
int data;

};
class lists{
public:
 lists();
 void add(int a,int b){
 current=new Node();
current=first;

 }
 int searchs(int a){

 }
private:
Node *first;
};
class OutOfBounds
{
public:
    OutOfBounds(){}
};
class NoMem
{
public:
    NoMem(){}
};
class maxheap{
public:
 maxheap(int maxheapsize=10);
~maxheap(){ delete []heap};
int Size ()const { return currentsize};
int Max(){ if(currentsize==0)throw OutOfBounds();}
int Insert(int x);
int Delete(int x);
void Initialize(int a[],int currentsize);
private:
int *heap;
 int currentsize,maxsize;

};

int Insert(int x){
if(currentsize==maxsize) throw OutOfBounds();
int i=++currentsize;
while(i!=1&&)
}
