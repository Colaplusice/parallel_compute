//基于链表的类Chain
#include <iostream>
//#include<new.h>
using namespace std;

//节点类，定义了每个节点的存储类型和指针名称
template<class T>
class ChainNode{
public:
	T data;
	ChainNode<T> *link;
};

//链表类，封装了链表操作的相应方法
template<class T>
class Chain{
public:
	Chain(){ first = 0; }                       //构造函数，头结点指向空值
	~Chain();
	bool IsEmpty()const{ return first == 0; }   //判断是否为空
	int Length()const;                      //返回该链表的长度
	bool Find(int k, T&x)const;              //返回第k个元素到x中
	int Search(const T&x)const;             //返回x所在的位置
	Chain<T>& Delete(int k, T& x);         //删除第k个元素并把它返回到x中
	Chain<T>& Insert(int k, const T&x);        //在第k个元素之后插入x
	void Output(ostream& out) const;        //重载操作符的输出函数
	ChainNode<T> *first;                  //指向第一个节点的指针
	ChainNode<T> *last;                       //指向最后一个节点的指针

	void Erase();
	void Zero(){ first = 0; };
	Chain<T>& Append(const T&x);

};

      ////析构函数

template <class T>
Chain <T>::~Chain(){
Erase();}

template <class T>
 void Chain <T>::Erase(){
 ChainNode <T>*next;
  //指向下一个节点
  while(first){
   next=first->link;
  delete first;
  first =next;
  }
}

//在右端添加一个数据
template <class T>
Chain<T>&Chain<T>::Append(const T&x)
{
 ChainNode<T> *y;
 y=new ChainNode<T>;
 y->data=x;
 y->link=0;
 if(first)
 {
  last->link=y;
  last=y;

 }
else
{first=last=y;}
return *this;
}
template <class T>//输出链表
	ostream&operator <<(ostream&out,const Chain<T>&x){
	x.output(out);
	return out;
	}





