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
	 * 4、使用散列表设计实现一个字典,假设关键字为整数且 D 为 961,在字典
	 * 中插入随机产生的 500 个不同的整数,实现字典的建立和搜索操作。分别使
	 * 用线性开型寻址和链表散列解决溢出。
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
	out << "[散列余数], 数值";
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
		cout << "指定三对角方阵的大小: ";
		break;
	case 2:
		cout << "指定下三角方阵的大小: ";
		break;
	}
	int size;
	cin >> size;
	MT* tm = new MT(size);
	bool loop = true;
	while (loop) {
		cout << "(1)存储一个\n"
				"(2)取出一个\n"
				"(3)输入全部\n"
				"(4)输出全部\n"
				"(5)结束\n";
		cout << "执行操作？(1-5)";
		int row, col;
		switch (choose(1, 5)) {
		case 1:
			cout << "输入行和列(均大于零): ";
			cin >> row >> col;
			cout << "输入数值: ";
			double val;
			cin >> val;
			tm->Store(row, col, val);
			break;
		case 2:
			cout << "输入行和列(均大于零): ";
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
	cout << "演示结束" << endl;
}

void q3() {
	cout << "指定稀疏方阵的最大元素个数: ";
	int size;
	cin >> size;
	SparseMatrix<double>* sm = new SparseMatrix<double>(size);
	bool loop = true;
	SparseMatrix<double>* ret;
	while (loop) {
		cout << "(1)存储一个\n"
				"(2)取出一个\n"
				"(3)输入全部\n"
				"(4)输出全部\n"
				"(5)矩阵相加\n"
				"(6)矩阵转置\n"
				"(7)结束\n";
		cout << "执行操作？(1-7)";
		int row, col;
		switch (choose(1, 7)) {
		case 1:
			cout << "输入行和列(均大于零): ";
			cin >> row >> col;
			cout << "输入数值: ";
			double val;
			cin >> val;
			sm->Store(val, row, col);
			break;
		case 2:
			cout << "输入行和列(均大于零): ";
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
			cout << "设当前矩阵为A，请输入矩阵B，矩阵B将与矩阵A相加\n"
					"得到的结果矩阵C将覆盖存放到A中\n";
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
	cout << "演示结束" << endl;
}

void q4() {
	cout << "输入除数D的值（小于3则取默认值961）：";
	int D, intnum;
	cin >> D;
	if (D < 3)
		D = 961;
	cout << "输入插入的随机整数的个数（小于1则取默认值500）：";
	cin >> intnum;
	if (intnum < 1)
		intnum = 500;
	cout << "输入随机数的范围（最小值和最大值，空格分割）：";
	long min, max;
	cin >> min >> max;
	srand(unsigned(time(0)));
	long rmin, rmax;
	rmin = rmax = (min + max) / 2;
	long randret;

	// 开放寻址
	HashTable<long, long> *ht = new HashTable<long, long>(D);

	// 链表散列
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

	cout << "开放寻址法：" << endl;
	cout << (*ht);
	cout << "链表散列法：" << endl;
	cout << (*cht);
	cout << "所有随机数的最大值: " << rmin << endl;
	cout << "所有随机数的最小值: " << rmax << endl;
}

int main() {
	cout << "题号？(1-4)";
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
		cout << "请输入稀疏矩阵的大小";
			cin >> size;
		Spmatrix<double>* sm = new Spmatrix<double>(size);
		bool loop = true;
		Spmatrix<double>*ret;
		while (loop)
		{
			cout << "(1)存储一个\n"
				"(2)取出一个\n"
				"(3)输入全部\n"
				"(4)输出全部\n"
				"(5)矩阵相加\n"
				"(6)矩阵转置\n"
				"(7)结束\n";
			cout << "执行操作？(1-7)";
			cout << "执行操作？(1-7)";
			int row, col;
			switch (choose(1, 7)) {
			case 1:
				cout << "输入行和列(均大于零): ";
				cin >> row >> col;
				cout << "输入数值: ";
				double val;
				cin >> val;
				sm->Store(val, row, col);
				break;
			case 2:
				cout << "输入行和列(均大于零): ";
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
				cout << "设当前矩阵为A，请输入矩阵B，矩阵B将与矩阵A相加\n"
					"得到的结果矩阵C将覆盖存放到A中\n";
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
