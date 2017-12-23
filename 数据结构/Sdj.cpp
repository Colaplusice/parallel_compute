//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
	  template <class T>
	  class TridiagonalMatrix {//三对角矩阵
	  public:
		  TridiagonalMatrix(int size=10)
		  {
			  n = size; t = new T[3 * n - 2];
		  }
		  ~TridiagonalMatrix() {
			  delete[]t;
		  }
		  TridiagonalMatrix<T>&Store(const T&x, int i, int j);
		  T Retrive(int i, int j) const;
	  private:
		  int n;//矩阵维数
		  T*t;//储存下三角矩阵的一维数组
	  };
	  class OutOfBounds {
	  public:
		  OutOfBounds() {
			  cout << "Out Of Bounds!" << endl;
		  }
	  };
	  class nomemory
	  {
		  nomemory() {
			  cout << "内存不够";
		  }

	  };
	  class Mustbezero {
	  public:
		  Mustbezero() {
			  cout << "must be zero";
		  }

	  };
	  template <class T>
	  TridiagonalMatrix<T>&TridiagonalMatrix<T>::Store(const T&x, int i, int j) {//store方法
		  if (i<1||j<1||i>n||j>n)
		  {
			  throw OutOfBounds();
		  }
		  switch (i - j) {
		  case 1: /* 低对角线*/
			  t[ i-2] = x; break;
		  case 0: /* 主对角线*/
			  t[n+i-2] = x; break;
		  case -1: /*  高对角线*/
			  t[2*n+i-2] = x; break;
		  default:if (x != 0) cout<<"非对角线上元素值必须为零";

		  }
		  return *this;
	  }
	  template <class T>
	  T TridiagonalMatrix<T>::Retrive(int i, int j)const {
		  if (i < 1||j<1||i>n||j>n)
		  {
			  throw OutOfBounds();
		  }
		  switch (i - j) {
		  case 1: /* 低对角线*/
			  return t[i - 2];
		  case 0: /* 主对角线*/
			  return t[n + i - 2];
		  case -1: /*  高对角线*/
			  return t[2 * n + i - 2];
		  default: return 0;
		  }
	  }
