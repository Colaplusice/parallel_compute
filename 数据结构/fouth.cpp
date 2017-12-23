public:
	NoSuchElement(){
		message("No such element to delete");
	}
};



/*
 * ChainHashTable.h
 *
 *  Created on: Nov 23, 2015
 *      Author: xudp
 */

#ifndef CHAINHASHTABLE_H_
#define CHAINHASHTABLE_H_
#include <iostream>
#include "SortedChain.h"
using namespace std;

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

template class ChainHashTable<long, long> ;

#endif /* CHAINHASHTABLE_H_ */

/*
 * ChainHashTable.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: xudp
 */

#include "ChainHashTable.h"
#include <iostream>

template<class E, class K>
void ChainHashTable<E, K>::Output(ostream& out) const {
	out << "[ɢ������], ��ֵ";
	for (int i = 0; i < D; i++) {
		out << "[" << i << "],\t" << ht[i];
	}
}

/*
 * Main.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: xudp
 */

#include <iostream>
#include <climits>
#include "Exceptions.h"
#include "TridiagonalMatrix.h"
#include "LowerTriangularMatrix.h"
#include "SparseMatrix.h"
#include <cstdlib>
#include <ctime>
#include "HashTable.h"
#include "ChainHashTable.h"
using namespace std;

long random(double start, double end) {
	return long(start + (end + 1 - start) * rand() / (RAND_MAX + 1.0));
}

int choose(int min = 1, int max = INT_MAX) {
	int ret;
	cin >> ret;
	if (ret < min || ret > max)
		throw BadInput();
	return ret;
}

template<class MT>
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
	MT* tm = new MT(size);
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
			cout << "(" << row << ", " << col << ")=" << tm->Retrieve(row, col)
					<< endl;
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
		randret = random(min, max);
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
int xishu(int ) {
		int size;
		cout << "������ϡ�����Ĵ�С";
			cin >> size;
		Spmatrix<double>* sm = new Spmatrix<double>(size);
		bool loop = true;
		Spmatrix<double>*ret;
		while (loop)
		{
			cout << "(1)�洢һ��\n"
				"(2)ȡ��һ��\n"
				"(3)����ȫ��\n"
				"(4)���ȫ��\n"
				"(5)�������\n"
				"(6)����ת��\n"
				"(7)����\n";
			cout << "ִ�в�����(1-7)";
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
				Spmatrix<double>* tmp = new Spmatrix<double>(sm->GetMaxSize());
				cout << "�赱ǰ����ΪA�����������B������B�������A���\n"
					"�õ��Ľ������C�����Ǵ�ŵ�A��\n";
				cin >> (*tmp);
				ret = new Spmatrix<double>(
					tmp->GetMaxSize() + sm->GetMaxSize());
				sm->Add(*tmp, *ret);
				delete sm;
				sm = ret;
				break;
			}
			case 6: {
				ret = new Spmatrix<double>(sm->GetMaxSize());
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


	}
