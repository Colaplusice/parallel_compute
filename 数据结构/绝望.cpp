#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
 class OutOfBounds {
	  public:
		  OutOfBounds() {
			  cout << "Out Of Bounds!" << endl;
		  }
	  };
	  	  class nomemory
	  {
	   public:
		  nomemory() {
			  cout << "�ڴ治��";
		  }
	  };
  class Mustbezero {
	  public:
		  Mustbezero() {
			  cout << "must be zero";
		  }

	  };
 template <class T>
	  class TridiagonalMatrix {//���ԽǾ���
	  public:
		  TridiagonalMatrix(int size=10)
		  {
			  t = new T[3 * size - 2];
		  }
		  ~TridiagonalMatrix() {
			  delete[]t;
		  }
		  TridiagonalMatrix<T>&Store(int i, int j,const T&x);
		  T Retrive(int i, int j) const;
		  void Input(istream& in, ostream& out);
	    void Output(ostream& out) const;
	friend ostream& operator<< (ostream& out, const TridiagonalMatrix<T>& matrix){
		matrix.Output(out);
		return out;
	}
	friend istream& operator>> (istream& in, TridiagonalMatrix<T>& matrix){
		matrix.Input(in, cout);
		return in;
	}
	  private:
		  int size;//����ά��
		  T*t;//���������Ǿ����һά����
	  };


template<class T>
void TridiagonalMatrix<T>::Input(istream& in, ostream& out) {
	out << "�밴����˳����������Ԫ�أ�" << endl;
	out << "Ԫ�ظ�������ǡ����" << (3 * size - 2) << "��: "<< endl;
	for (int i = 0; i < size; i++) {
		for (int j = i - 1; j <= i + 1; j++) {
			if (i == 0 && j == -1)
				continue;
			if (i == size - 1 && j == size)
				continue;
			T element;
			in >> element;
			Store(i + 1, j + 1, element);
		}
	}
	out << "�����ɹ����. " << endl;
}

template<class T>
void TridiagonalMatrix<T>::Output(ostream& out) const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			if ((i - j) > 1 || (i - j) < -1)
				out << "0\t";
			else {
				out << t[2 * j + i] << "\t";
			}
		out << endl;
	}
}
	  template <class T>
	  TridiagonalMatrix<T>&TridiagonalMatrix<T>::Store(int i, int j,const T&x) {//store����
		  if (i<1||j<1||i>size||j>size)
		  {
			  throw OutOfBounds();
		  }
		  switch (i - j) {
		  case 1: /* �ͶԽ���*/
			  t[ i-2] = x; break;
		  case 0: /* ���Խ���*/
			  t[size+i-2] = x; break;
		  case -1: /*  �߶Խ���*/
			  t[2*size+i-2] = x; break;
		  default:if (x != 0) cout<<"�ǶԽ�����Ԫ��ֵ����Ϊ��";

		  }
		  return *this;
	  }
	  template <class T>
	  T TridiagonalMatrix<T>::Retrive(int i, int j)const {
		  if (i < 1||j<1||i>size||j>size)
		  {
			  throw OutOfBounds();
		  }
		  switch (i - j) {
		  case 1: /* �ͶԽ���*/
			  return t[i - 2];
		  case 0: /* ���Խ���*/
			  return t[size + i - 2];
		  case -1: /*  �߶Խ���*/
			  return t[2 * size + i - 2];
		  default: return 0;
		  }
	  }

template<class T> class SparseMatrix;
template<class T>
class Term {
	friend SparseMatrix<T>;
private:
	int row, col;
	T value;
};

template<class T>
class SparseMatrix {
public:
	/* 3������ϡ�������,��������˳���ϡ�����ӳ�䵽һά������,ʵ��ϡ
	* ������ת�ú�����ϡ�����ļӷ�������
	*/
	SparseMatrix(int maxTerms = 10);
	SparseMatrix(const SparseMatrix<T>& spm);
	~SparseMatrix() {
		delete[] a;
	}
	void Transpose(SparseMatrix<T> &b) const;
	void Add(const SparseMatrix<T> &b, SparseMatrix<T> &c) const;

	/*
	* Write the store and retrieve functions for a sparse matrix stored in
	* row-major order in a one-dimensional array.
	*/
	SparseMatrix<T>& Store(const T& x, int i, int j);
	T Retrieve(int i, int j) const;

	void Input(istream& in, ostream& out);
	void Output(ostream& out) const;

	friend ostream& operator<<(ostream& out, const SparseMatrix<T>& matrix) {
		matrix.Output(out);
		return out;
	}
	friend istream& operator>>(istream& in, SparseMatrix<T>& matrix) {
		matrix.Input(in, cout);
		return in;
	}

	int GetMaxSize(){
		return MaxTerms;
	}
private:
	void Append(const Term<T>& t);
	int rows, cols; // matrix dimensions
	int terms; // current number of nonzero terms
	Term<T> * a; // term array
	int MaxTerms; // size of array a
};

//template class SparseMatrix<double>;

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms) {//���췽�� ����һ������
	if (maxTerms < 1)
		throw OutOfBounds();
	MaxTerms = maxTerms;
	a = new Term<T>[MaxTerms];
 terms = cols = rows = 0;
}

template<class T>
SparseMatrix<T>& SparseMatrix<T>::Store(const T& theVal, int theRow,	int theCol)
 {
	if (theRow < 1 || theCol < 1 || theRow > rows || theCol > cols)
		throw OutOfBounds();
	int cursor = -1;
	do {
		cursor++;
		if (cursor == terms) {
			Term<T> t;
			t.row = theRow;
			t.col = theCol;
			t.value = theVal;//����Ԫ�ص�ֵ
			Append(t);
			return *this;
		}
	} while (a[cursor].row < theRow
		|| (a[cursor].row == theRow && a[cursor].col < theCol));

	if (a[cursor].row == theRow && a[cursor].col == theCol) // (theRow,theCol) is already existent.
		a[cursor].value = theVal;
	else {
		if (terms >= MaxTerms)
			throw nomemory();
		for (int k = terms - 1; k >= cursor; k--) {
			a[k + 1] = a[k];
		}
		a[cursor].row = theRow;
		a[cursor].col = theCol;
		a[cursor].value = theVal;
		terms++;
	}
	return *this;
}

template<class T>
T SparseMatrix<T>::Retrieve(int theRow, int theCol) const {
	if (theRow < 1 || theCol < 1 || theRow > rows || theCol > cols)
		throw OutOfBounds();
	int cursor = 0;
	while (a[cursor].row < theRow
		|| (a[cursor].row == theRow && a[cursor].col < theCol)) {
		cursor++;
		if (cursor == terms) // not in the sparse matrix
			return 0;
	}

	if (a[cursor].row == theRow && a[cursor].col == theCol) // (theRow,theCol) is already existent.
		return a[cursor].value;
	else
		return 0;
}

template<class T>
void SparseMatrix<T>::Output(ostream& out) const {
	out << "�������������" << rows << "  �������������" << cols << "  ����Ԫ������" << terms
		<< endl;

	// put terms, one per line
	for (int i = 0; i < terms; i++)
		out << "a(" << a[i].row << ',' << a[i].col << ") = " << a[i].value
		<< endl;
}

template<class T>
void SparseMatrix<T>::Input(istream& in, ostream& out) {
	out << "�ֱ������������ֵ���������ֵ���Լ����������Ԫ��������";
	int theTerms;
	in >> rows >> cols >> theTerms;
	if (theTerms > MaxTerms)
		throw nomemory();

	// input terms
	int theRow, theCol;
	T theVal;
	for (int i = 0; i < theTerms; i++) {
		out << "���������" << (i + 1) << "������ڵ��С��У��Լ�����Ӧ����ֵ";
		in >> theRow >> theCol >> theVal;
		Store(theVal, theRow, theCol);
	}
}

template<class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T> &b) const {
	// Return transpose of *this in b.

	// make sure b has enough space
	if (terms > b.MaxTerms)
		throw nomemory();

	// set transpose characteristics
	b.cols = rows;
	b.rows = cols;
	b.terms = terms;

	// initialize to compute transpose
	int *ColSize, *RowNext;
	ColSize = new int[cols + 1];
	RowNext = new int[rows + 1];

	// find number of entries in each column of *this
	for (int i = 1; i <= cols; i++)  // initialize
		ColSize[i] = 0;
	for (int i = 0; i < terms; i++)
		ColSize[a[i].col]++;

	// find the starting point of each row of b
	RowNext[1] = 0;
	for (int i = 2; i <= cols; i++)
		RowNext[i] = RowNext[i - 1] + ColSize[i - 1];

	// perform the transpose copying from *this to b
	for (int i = 0; i < terms; i++) {
		int j = RowNext[a[i].col]++; // position in b
		b.a[j].row = a[i].col;
		b.a[j].col = a[i].row;
		b.a[j].value = a[i].value;
	}

}

template<class T>
void SparseMatrix<T>::Add(const SparseMatrix<T> &b, SparseMatrix<T> &c) const {
	// Compute c = (*this) + b.
	// �����ģƥ��
	if (rows != b.rows || cols != b.cols)
		throw OutOfBounds();
	c.cols = cols;
	c.rows = rows;

	// ���³�ʼ��ϡ�����c
	delete[] c.a;
	int newMaxTerms = b.terms + terms;
	c.MaxTerms = (newMaxTerms > c.MaxTerms) ? newMaxTerms : c.MaxTerms;
	c.a = new Term<T>[c.MaxTerms];//c�ķ���Ԫ������

	// Not the best way.
	bool* hasMatched_b = new bool[b.terms];
	for (int i = 0; i < b.terms; i++)
		hasMatched_b[i] = false;
	int curIndex = 0;
	for (int i = 0; i < terms; i++) {
		bool isMatched = false;
		for (int j = 0; j < b.terms; j++) {
			if (a[i].row == b.a[j].row && a[i].col == b.a[j].col) {
				isMatched = true;
				hasMatched_b[j] = true;
				c.a[curIndex].row = a[i].row;
				c.a[curIndex].col = a[i].col;
				c.a[curIndex].value = a[i].value + b.a[j].value;
				break;
			}
		}
		if (!isMatched) {
			c.a[curIndex].row = a[i].row;
			c.a[curIndex].col = a[i].col;
			c.a[curIndex].value = a[i].value;
		}
		curIndex++;
	}
	for (int i = 0; i < b.terms; i++) {
		if (!hasMatched_b[i]) {
			c.a[curIndex].row = b.a[i].row;
			c.a[curIndex].col = b.a[i].col;
			c.a[curIndex].value = b.a[i].value;
			curIndex++;
		}
	}

	// When writing this function by myself, I forgot the following:
	c.terms = curIndex;

	delete[] hasMatched_b;
}

template<class T>
void SparseMatrix<T>::Append(const Term<T>& t) {
	// Append a nonzero term t to *this
	if (terms >= MaxTerms)
		throw nomemory();
	a[terms] = t;
	terms++;
}
template<class T>
class LowerTriangularMatrix {
public:
	// 2�����������Ǿ�����,���ð���ӳ�䷽ʽ,�ṩ store �� retrieve ������
	LowerTriangularMatrix(int size = 10);
	~LowerTriangularMatrix();
	// row>0, column>0
	LowerTriangularMatrix<T>& Store(int row, int column, const T& value);
	T Retrieve(int row, int column);

	void Input(istream& in, ostream& out);
	void Output(ostream& out) const;

	friend ostream& operator<<(ostream& out,
			const LowerTriangularMatrix<T>& matrix) {
		matrix.Output(out);
		return out;
	}
	friend istream& operator>>(istream& in, LowerTriangularMatrix<T>& matrix) {
		matrix.Input(in, cout);
		return in;
	}
private:
	T* e;	// Store all elements
	int size;
};
template<class T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(int size) {
	if (size < 1)
		throw OutOfBounds();
	e = new T[size * (size + 1) / 2];
	this->size = size;
}

template<class T>
LowerTriangularMatrix<T>::~LowerTriangularMatrix() {
	delete[] e;
}

template<class T>
LowerTriangularMatrix<T>& LowerTriangularMatrix<T>::Store(int row, int column,
		const T& value) {
	if (row < 1 || row < column || column < 1)
		throw OutOfBounds();
	e[size * (column - 1) - 1 + row + column * (1 - column) / 2] = value;
	return *this;
}

template<class T>
T LowerTriangularMatrix<T>::Retrieve(int row, int column) {
	if (row < 1 || row > size || column < 1 || column > size
			|| (row - column) > 1 || (row - column) < -1)
		throw OutOfBounds();
	return e[size * (column - 1) - 1 + row + column * (1 - column) / 2];
}

template<class T>
void LowerTriangularMatrix<T>::Input(istream& in, ostream& out){
	out << "�밴����˳����������Ԫ�أ�" << endl;
	out << "Ԫ�ظ�������ǡ����" << (size * (size + 1) / 2) << "��: "
			<< endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			T element;
			in >> element;
			Store(i + 1, j + 1, element);
		}
	}
	out << "�����ɹ����. " << endl;
}

template<class T>
void LowerTriangularMatrix<T>::Output(ostream& out) const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			if (j > i)
				out << "0\t";
			else {
				out << e[size * j + i - j * (j + 1) / 2] << "\t";
			}
		out << endl;
	}
}
	int choose(int min = 1, int max = INT_MAX) {//ѡ����
		int ret;
		cin >> ret;
		if (ret < min || ret > max)
			throw OutOfBounds();
		return ret;
	}

template<class E, class K>
class HashTable {
	/*
	* 4��ʹ��ɢ�б����ʵ��һ���ֵ�,����ؼ���Ϊ������ D Ϊ 961,���ֵ�
	* �в������������ 500 ����ͬ������,ʵ���ֵ�Ľ����������������ֱ�ʹ
	* �����Կ���Ѱַ������ɢ�н�������
	*/
public:
	HashTable(int divisor = 11);
	~HashTable() {
		delete[] ht;
		delete[] empty;
	}
	bool Search(const K& k, E& e) const;
	HashTable<E, K>& Insert(const E& e);
	void Output(ostream& out) const;
	friend ostream& operator<< (ostream& out, const HashTable<E, K>& ht){
		ht.Output(out);
		return out;
	}
private:
	int hSearch(const K& k) const;
	int D;	//
	E *ht;	//
	bool *empty;	//
};

template<class E, class K>
HashTable<E, K>::HashTable(int divisor) {
	D = divisor;

	ht = new E[D];
	empty = new bool[D];

	for (int i = 0; i < D; i++)
		empty[i] = true;
}

template<class E, class K>
int HashTable<E, K>::hSearch(const K& k) const {
	int i = k % D;
	int j = i;
	do {
		if (empty[j] || ht[j] == k)
			return j;
		j = (j + 1) % D;
	} while (j != i);
	return j;
}

template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e) const {
	int b = hSearch(k);
	if (empty[b] || ht[b] != k)
		return false;
	e = ht[b];
	return true;
}

template<class E, class K>
HashTable<E, K>& HashTable<E, K>::Insert(const E& e) {
	K k = e;
	int b = hSearch(k);
	if (empty[b]) {
		empty[b] = false;
		ht[b] = e;
		return *this;
		if (ht[b] == k)
			throw OutOfBounds();
	}
		throw nomemory();
}

template<class E, class K>
void HashTable<E, K>::Output(ostream& out) const {
	out << "���Ƿ�����";
	bool isFull = true;
	for (int i = 0; i < D; i++)
		if (!empty[i]) {
			isFull = false;
			break;
		}
	if (isFull)
		out << "��";
	else
		out << "��";
	out << endl;
	out << "[ɢ������(���洢��ֵ������)], ���洢��ֵ" << endl;
	for (int i = 0; i < D; i++) {
		out << " [" << i << "(" << (ht[i] % D) << ")],\t" << ht[i] << "\t|";
		if ((i + 1) % 3 == 0)
			out << endl;
	}
	if (D % 3 != 0)
		out << endl;
}


template<class E, class K> class SortedChain;
template<class E, class K>
class SortedChainNode {
	friend class SortedChain<E, K> ;
private:
	E data;
	SortedChainNode<E, K> *link;
};

template<class E, class K>
class SortedChain {
public:
	SortedChain() {
		first = 0;
	}
	~SortedChain();
	bool IsEmpty() const {
		return first == 0;
	}
	int Length() const;
	bool Search(const K& k, E& e) const;
	SortedChain<E, K>& Delete(const K& k, E& e);
	SortedChain<E, K>& Insert(const E& e);

	void Output(ostream& out) const;
	friend ostream& operator<< (ostream& out, const SortedChain<E,K>& sc){
		sc.Output(out);
		return out;
	}
private:
	SortedChainNode<E, K> *first;
};
template<class E, class K>
SortedChain<E, K>::~SortedChain() {
	SortedChainNode<E, K>* p = first;
	SortedChainNode<E, K>* tmp;
	while (p) {
		tmp = p;
		p = p->link;
		delete tmp;
	}
}

template<class E, class K>
int SortedChain<E, K>::Length() const {
	SortedChainNode<E, K> *p = first;
	int ret = 0;
	while (p) {
		ret++;
		p = p->link;
	}
	return ret;
}

template<class E, class K>
bool SortedChain<E, K>::Search(const K& k, E& e) const {
	// Put element that matches k in e.
	// Return false if no match.
	SortedChainNode<E, K> *p = first;

	// search for match with k
	for (; p && p->data < k; p = p->link)
		;

	// verify match
	if (p && p->data == k) // yes, found match
			{
		e = p->data;
		return true;
	}
	return false;
}


template<class E, class K>
SortedChain<E, K>& SortedChain<E, K>::Insert(const E& e) {//��Ԫ�ش�С����
	SortedChainNode<E, K>* p;
	if (!first || first->data >= e) {
		p = new SortedChainNode<E, K>();
		p->data = e;
		p->link = first;
		first = p;
	} else {
		p = first;
		while (p->link) {
			if (p->link->data < e) {
				p = p->link;
			} else {
				SortedChainNode<E, K>* ncn = new SortedChainNode<E, K>();
				ncn->data = e;
				ncn->link = p->link;
				p->link = ncn;
				break;
			}
		}
		if (!p->link) {
			p->link = new SortedChainNode<E, K>();
			p = p->link;
			p->link = 0;
			p->data = e;
		}
	}
	return *this;
}



template<class E, class K>
void SortedChain<E, K>::Output(ostream& out) const{
	SortedChainNode<E, K> *p = first;
	if (!first)
		out << "(Empty chain.)";
	else
	while(p){
		out << p->data << "\t";
		p = p->link;
	}
	out << endl;
}

template<class E, class K>

class ChainHashTable {
	/*
	 * 4��ʹ��ɢ�б����ʵ��һ���ֵ�,����ؼ���Ϊ������ D Ϊ 961,���ֵ�
	 * �в������������ 500 ����ͬ������,ʵ���ֵ�Ľ����������������ֱ�ʹ
	 * �����Կ���Ѱַ������ɢ�н�������
	 */
public:
	ChainHashTable(int divisor = 11) {
		D = divisor;
		ht = new SortedChain<E, K> [D];
	}
	~ChainHashTable() {
		delete[] ht;
	}
	bool Search(const K& k, E& e) const {
		return ht[k % D].Search(k, e);
	}
	ChainHashTable<E, K>& Insert(const E&e) {
		ht[e % D].Insert(e);
//		ht[e % D].DistinctInsert(e);
		return *this;
	}
	ChainHashTable<E, K>& Delete(const K& k, E&e) {
		ht[k % D].Delete(k, e);
		return *this;
	}

	void Output(ostream& out) const;
	friend ostream& operator<< (ostream& out, const ChainHashTable<E,K>& cht){
		cht.Output(out);
		return out;
	}
private:
	int D;	// divisor
	SortedChain<E, K> * ht;	// array of chains
};

template<class E, class K>
void ChainHashTable<E, K>::Output(ostream& out) const {
	out << "[ɢ������], ��ֵ";
	for (int i = 0; i < D; i++) {
		out << "[" << i << "],\t" << ht[i];
	}
}
	void q3() {
	cout << "ָ��ϡ�跽������Ԫ�ظ���: ";
	int size;
	cin >> size;
	SparseMatrix<double>* sm = new SparseMatrix<double>(size);
	bool loop = true;
	SparseMatrix<double>* ret;
	while (loop) {
		cout << "(1)�洢һ��\n"
				"(2)ȡ��һ��\n"
				"(3)����ȫ��\n"
				"(4)���ȫ��\n"
				"(5)�������\n"
				"(6)����ת��\n"
				"(7)����\n";
		cout << "ִ�в�����(1-7)";
		int row, col;
		switch (choose(1, 7)) {
		case 1:
			cout << "�����к���(��������): ";
			cin >> row >> col;
			cout << "������ֵ: ";
			double val;
			cin >> val;
			sm->Store(val, row, col);
			break;
		case 2:
			cout << "�����к���(��������): ";
			cin >> row >> col;
			cout << "(" << row << ", " << col << ")=" << sm->Retrieve(row, col)
					<< endl;
			break;
		case 3:
			cin >> (*sm);
			break;
		case 4:
			cout << (*sm);
			break;
		case 5: {
			SparseMatrix<double>* tmp = new SparseMatrix<double>(
   sm->GetMaxSize());
			cout << "�赱ǰ����ΪA�����������B������B�������A���\n"
					"�õ��Ľ������C�����Ǵ�ŵ�A��\n";
			cin >> (*tmp);
			ret = new SparseMatrix<double>(
					tmp->GetMaxSize() + sm->GetMaxSize());
			sm->Add(*tmp, *ret);
			delete sm;
			sm = ret;
			break;
		}
		case 6: {
			ret = new SparseMatrix<double>(sm->GetMaxSize());
			sm->Transpose(*ret);
			delete sm;
			sm = ret;
			break;
		}
		case 7:
			loop = false;
			break;
		}
	}
	cout << "��ʾ����" << endl;
}
template<class T>
void q12(int type) {
	switch (type) {
	case 1:
		cout << "ָ�����ԽǷ���Ĵ�С: ";
		break;
	case 2:
		cout << "ָ�������Ƿ���Ĵ�С: ";
		break;
	}
	int size;
	cin >> size;
	TridiagonalMatrix<double> *tm = new TridiagonalMatrix<double>(size);

	bool loop = true;
	while (loop) {
		cout << "(1)�洢һ��\n"
				"(2)ȡ��һ��\n"
				"(3)����ȫ��\n"
				"(4)���ȫ��\n"
				"(5)����\n";
		cout << "ִ�в�����(1-5)";
		int row, col;
		switch (choose(1, 5)) {
		case 1:
			cout << "�����к���(��������): ";
			cin >> row >> col;
			cout << "������ֵ: ";
			double val;
			cin >> val;
			tm->Store(row, col, val);
			break;
		case 2:
			cout << "�����к���(��������): ";
			cin >> row >> col;
			cout << "(" << row << ", " << col << ")=" << tm->Retrive(row, col)<< endl;
			break;
		case 3:
			cin >> (*tm);
			break;
		case 4:
			cout << (*tm);
			break;
		case 5:
			loop = false;
			break;
		}
	}
	cout << "��ʾ����" << endl;
}
void q4() {
	cout << "�������D��ֵ��С��3��ȡĬ��ֵ961����";
	int D, intnum;
	cin >> D;
	if (D < 3)
		D = 961;
	cout << "����������������ĸ�����С��1��ȡĬ��ֵ500����";
	cin >> intnum;
	if (intnum < 1)
		intnum = 500;
	cout << "����������ķ�Χ����Сֵ�����ֵ���ո�ָ��";
	long min, max;
	cin >> min >> max;
	srand(unsigned(time(0)));
	long rmin, rmax;
	rmin = rmax = (min + max) / 2;
	long randret;

	// ����Ѱַ
	HashTable<long, long> *ht = new HashTable<long, long>(D);

	// ����ɢ��
	ChainHashTable<long, long> *cht = new ChainHashTable<long, long>(D);

	for (int i = 0; i < intnum; i++) {
//		randret =rand(min, max);
//		cout << randret << endl;
		if (randret > rmax)
			rmax = randret;
		if (randret < rmin)
			rmin = randret;
		ht->Insert(randret);
		cht->Insert(randret);
	}

	cout << "����Ѱַ����" << endl;
	cout << (*ht);
	cout << "����ɢ�з���" << endl;
	cout << (*cht);
	cout << "��������������ֵ: " << rmin << endl;
	cout << "�������������Сֵ: " << rmax << endl;
}

int main() {
	cout << "��ţ�(1-4)";
	switch (choose(1, 4)) {
	case 1:
		q12<TridiagonalMatrix<double> >(1);
		break;
	case 2:
		q12<LowerTriangularMatrix<double> >(2);
		break;
	case 3:
		q3();
		break;
	case 4:
		q4();
		break;
	}
	return 0;
}


