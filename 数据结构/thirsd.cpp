#include <iostream>
using namespace std;
//�ڵ��࣬������ÿ���ڵ�Ĵ洢���ͺ�ָ������
template<class T>
class ChainNode{
public:
	T data;
	ChainNode<T> *link;
};

//�����࣬��װ�������������Ӧ����
template<class T>
class Chain{
public:
	Chain(){ first = 0; }                       //���캯����ͷ���ָ���ֵ
	~Chain();                               //��������
	bool IsEmpty()const{ return first == 0; }   //�ж��Ƿ�Ϊ��
	int Length()const;                      //���ظ�����ĳ���
	bool Find(int k, T&x)const;              //���ص�k��Ԫ�ص�x��
	int Search(const T&x)const;             //����x���ڵ�λ��
	Chain<T>& Delete(int k, T& x);         //ɾ����k��Ԫ�ز��������ص�x��
	Chain<T>& Insert(int k, const T&x);        //�ڵ�k��Ԫ��֮�����x
	void Output(ostream& out) const;        //���ز��������������
	ChainNode<T> *first;                  //ָ���һ���ڵ��ָ��
	ChainNode<T> *last;                       //ָ�����һ���ڵ��ָ��
static int MergeTwoList(Chain<T>*pListOneHead, Chain<T>*pListTwoHead);
	void Erase();
	void Zero(){ first = 0; };
	Chain<T>& Append(const T&x);


};
