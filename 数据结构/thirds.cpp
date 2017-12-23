//�����������Chain
#include <iostream>
//#include<new.h>
#include <thirsd.h>
using namespace std;

//�����������ʵ�ֶ�����ı���
template<class T>
class ChainIterator{
public:
	T* Initialize(const Chain<T>&c){
		location = c.first;
		if (location){

			return &location->data;//Ϊ���е�ַ����
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



//�������������������ɾ�����е������еĽڵ�
template<class T>
Chain<T>::~Chain(){
	Erase();
}


//����������е�����Ԫ�ز����ͷ��ڴ�
template<class T>
void Chain<T>::Erase(){
	ChainNode<T>*next;
	//ָ����һ���ڵ�
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}


//�������
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
//���ز�����
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


//�ڴ治����쳣��
class NoMem{
public:
	NoMem(){
		cout << "No Memory!" << endl;
	}
};
//ʹnew����NoMem�쳣������xalloc�쳣
//���Ҫ�ָ�ԭʼ��Ϊ���������µ���
//_set_new_handler(Old_Handler);
int my_new_handler(size_t size){
	throw NoMem();
}


//ȷ������ĳ���
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

//�������в��ҵ�k��Ԫ��
//���ھʹ��浽x��
//�������򷵻�false�����򷵻�true
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


//������������
//����x����������򷵻�x���±�
//���x�������򷵻�0
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



//��������ɾ��һ��Ԫ��
//����k��Ԫ��ȡ��x
//Ȼ���������ɾ����k��Ԫ��
//����������������쳣OutOfBounds
template <class T>
Chain<T>& Chain<T>::Delete(int k, T& x){
if(k<1||!first) {
  cout<<"�����ֵ����ȷ";
}
 ChainNode<T>*p=first;
if(k==1)
  {first=first->link;}
else{
ChainNode<T>*q=first;
		for (int index = 1; index<k - 1 && q; index++){
			q = q->link;
			//��ʱqָ��Ҫɾ����ǰһ���ڵ�
		}
if(!q||!q->link)
{cout<<"�����ֵ����ȷ"; }
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
//�ڵ�k��λ��֮�����Ԫ��
//��������OutOfBounds�쳣
//û���㹻�ڴ���NoMem�쳣
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T&x){
	if (k<0)
		throw OutOfBounds();

	ChainNode<T>*p = first;

	for (int index = 1; index<k-1 && p; index++){
		p = p->link;                    //��p�Ƶ���k��Ԫ�ص�λ��
	}
	if (k>0 && !p)
		throw OutOfBounds();

	ChainNode<T>*y = new ChainNode<T>;
	y->data = x;//�Ѳ����Ԫ�ؼ�Ϊy
	if (k){
		y->link = p->link;
		p->link = y;
	}
	else{
		              //��Ϊ��һ��Ԫ�ز���
		y->link = first;
		first = y;
	}
	if (!y->link)//�����λ�������һλ
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
 cout<<"����Ҫ��ӵ�Ԫ�صĸ�����";
 cin>>b;
int a[1000];
for(int i=0;i<b;i++){
 int c;
 cin>>c;
 a[i]=c;
}
//��Ԫ����ӵ�����
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
cout<<"����Ҫ���ҵ�Ԫ��";
int s;
cin>>s;
myList.Search(s);
cout<<"λ����:"<<myList.Search(s)<<" ";
//*********************************
cout<<"��Ҫɾ����Ԫ�ص�λ��";
 int f;
   int ci;
   cin>>ci;
		myList.Delete(ci, f);
		cout << "Delete is " << f << endl;
		cout << "myList : " << myList << endl;
		cout << "Length  = " << myList.Length() << endl;
//***********************************

int num;
cout<<"��������Ҫ�����λ�� ��Ԫ��";
int locs;
cin>>locs;
cin>>num;
myList.Insert(locs,num);
		cout << "myList : " << myList << endl;
		cout << "Length  = " << myList.Length() << endl;
//****************************
 int locat;
 cout<<"������Ҫ����Ԫ�ص�λ��: ";
 cin>>locat;
 myList.Find(locat,f);
 	cout << "Ҫ���ҵ�Ԫ���ǣ�" << f << endl;
//
Chain<ChainNode>MergeTwoList(myList, myL5ist1);

//ʹ�ñ��������
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



