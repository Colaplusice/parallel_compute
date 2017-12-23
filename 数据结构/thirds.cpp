//基于链表的类Chain
#include <iostream>
//#include<new.h>
#include <thirsd.h>
using namespace std;

//链表遍历器类实现对链表的遍历
template<class T>
class ChainIterator{
public:
	T* Initialize(const Chain<T>&c){
		location = c.first;
		if (location){

			return &location->data;//为何有地址符？
		}
		return 0;
	}

	T* Next(){
	if(location)
		{
		    location=location->link;

		 	return &location->data;
		} return 0;
			if (!location)
			return 0;
	}
private:
	ChainNode<T>*location;
};



//链表的析构函数，用于删除所有的链表中的节点
template<class T>
Chain<T>::~Chain(){
	Erase();
}


//清除掉链表中的所有元素并且释放内存
template<class T>
void Chain<T>::Erase(){
	ChainNode<T>*next;
	//指向下一个节点
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}


//输出链表
template<class T>
void Chain<T>::Output(ostream& out)const{
	ChainNode<T>*current;
	for (current = first; current; current = current->link){
		out << current->data;
		if (!current->link){
			out << "" << endl;
		}
		else{
			out << ",";
		}
	}
}
//重载操作符
template<class T>
ostream& operator<<(ostream& out, const Chain<T>&x){
	x.Output(out);
	return out;
}

class OutOfBounds{
public:
	OutOfBounds(){
		cout << "Out Of Bounds!" << endl;
	}
};


//内存不足的异常类
class NoMem{
public:
	NoMem(){
		cout << "No Memory!" << endl;
	}
};
//使new引发NoMem异常而不是xalloc异常
//如果要恢复原始行为可以做以下调用
//_set_new_handler(Old_Handler);
int my_new_handler(size_t size){
	throw NoMem();
}


//确认链表的长度
template<class T>
int Chain<T>::Length()const{
ChainNode<T>* current=first;
int lenth=0;
while(current){
 current=current->link;
 lenth++;
}
return lenth;
}

//在链表中查找第k个元素
//存在就储存到x中
//不存在则返回false，否则返回true
template<class T>
bool Chain<T>::Find(int k, T&x)const{
	if(k<1) return false;

	 ChainNode<T> *current=first;
	 int index=1;
	 while(index<k&&current){
    current=current->link;
    index++;
	 }
	 if (current)
   {
    x=current->data;
    return true;
   }
  return false;
}


//在链表中搜索
//查找x，如果发现则返回x的下标
//如果x不存在则返回0
template<class T>
int Chain<T>::Search(const T&x)const{
	ChainNode<T>*current = first;
	int index = 1;
	while (current&&current->data != x){
		current = current->link;
		index++;
	}
	if (current){
		return index;
	}else

 return 0;

}



//从链表中删除一个元素
//将第k个元素取至x
//然后从链表中删除第k个元素
//如果不存在则引发异常OutOfBounds
template <class T>
Chain<T>& Chain<T>::Delete(int k, T& x){
if(k<1||!first) {
  cout<<"输入的值不正确";
}
 ChainNode<T>*p=first;
if(k==1)
  {first=first->link;}
else{
ChainNode<T>*q=first;
		for (int index = 1; index<k - 1 && q; index++){
			q = q->link;
			//此时q指向要删除的前一个节点
		}
if(!q||!q->link)
{cout<<"输入的值不正确"; }
 p=q->link;
 if(p==last) {
   last=q;
 }
   q->link=p->link;
   x=p->data;
   delete p;
return *this;
}
}
//在第k个位置之后插入元素
//不存在则报OutOfBounds异常
//没有足够内存则报NoMem异常
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T&x){
	if (k<0)
		throw OutOfBounds();

	ChainNode<T>*p = first;

	for (int index = 1; index<k-1 && p; index++){
		p = p->link;                    //将p移到第k个元素的位置
	}
	if (k>0 && !p)
		throw OutOfBounds();

	ChainNode<T>*y = new ChainNode<T>;
	y->data = x;//把插入的元素记为y
	if (k){
		y->link = p->link;
		p->link = y;
	}
	else{
		              //作为第一个元素插入
		y->link = first;
		first = y;
	}
	if (!y->link)//插入的位置是最后一位
		last = y;
	return *this;
}
template<class T>
Chain<T>& Chain<T>::Append(const T&x){
	ChainNode<T>*y;
	y = new ChainNode<T>;
	y->data = x;
	y->link = 0;
	if (first){
		last->link = y;
		last = y;
	}
	else{
		first = last = y;
	}
	return *this;
}
template<class T>
int Chain<T>::MergeTwoList(Chain<T>*pListOneHead, Chain<T>*pListTwoHead)
{
    if (pListOneHead == NULL)
    {
        return pListTwoHead;
    }

    if (pListTwoHead == NULL)
    {
        return pListOneHead;
    }

    Chain<T> *pNode1 = pListOneHead;
    Chain<T> *pNode2 = pListTwoHead;
    Chain<T> *pMergeListHead = NULL;
    Chain<T> *pCurLastNode = NULL;

    if (pNode1->data < pNode2->data)
    {
        pMergeListHead = pListOneHead;
        pNode1 = pNode1->link;
        pCurLastNode = pMergeListHead;
    }
    else
    {
        pMergeListHead = pListTwoHead;
        pNode2 = pNode2->link;
        pCurLastNode = pMergeListHead;
    }

    while (pNode1 != NULL && pNode2 != NULL)
    {
        if (pNode1->data < pNode2->data)
        {
            pCurLastNode->link= pNode1;
            pCurLastNode = pNode1;
            pNode1 = pNode1->link;
        }
        else
        {
            pCurLastNode->link = pNode2;
            pCurLastNode = pNode2;
            pNode2 = pNode2->link;
        }

        if (pNode1 == NULL)
        {
            pCurLastNode->link = pNode2;
        }

        if (pNode2 == NULL)
        {
            pCurLastNode->link = pNode1;
        }
    }

    return pMergeListHead;
}
int main(){
//*****************************************
 int b;
 cout<<"输入要添加的元素的个数：";
 cin>>b;
int a[1000];
for(int i=0;i<b;i++){
 int c;
 cin>>c;
 a[i]=c;
}
//将元素添加到链表
Chain <int>myList;
  Chain<int>myList1;
  Chain<int>mylist2;
int sum[]={4,5,6,7};
for(int i=0;i<4;i++)
{
 myList1.Append(sum[i]);
}
for(int i=0;i<b;i++)
{
 myList.Append(a[i]);
}
cout << "myList : " << myList << endl;
cout << "Length  = " << myList.Length() << endl;
//*****************************
cout<<"输入要查找的元素";
int s;
cin>>s;
myList.Search(s);
cout<<"位置在:"<<myList.Search(s)<<" ";
//*********************************
cout<<"想要删除的元素的位置";
 int f;
   int ci;
   cin>>ci;
		myList.Delete(ci, f);
		cout << "Delete is " << f << endl;
		cout << "myList : " << myList << endl;
		cout << "Length  = " << myList.Length() << endl;
//***********************************

int num;
cout<<"请输入想要插入的位置 和元素";
int locs;
cin>>locs;
cin>>num;
myList.Insert(locs,num);
		cout << "myList : " << myList << endl;
		cout << "Length  = " << myList.Length() << endl;
//****************************
 int locat;
 cout<<"请输入要查找元素的位置: ";
 cin>>locat;
 myList.Find(locat,f);
 	cout << "要查找的元素是：" << f << endl;
//
Chain<ChainNode>MergeTwoList(myList, myL5ist1);

//使用遍历器输出
		int *x;
		ChainIterator<int>c;
		x = c.Initialize(myList);
		while (x){
			cout << *x;
			x = c.Next();
				cout << "" << endl;
			}

Chain<int>dao;
		int *x1;
		x1 = c.Initialize(myList);
		while (x1){
			dao.Insert(0, *x1);
			x1 = c.Next();
	}
		cout << dao << endl;

}



