//#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
	  template <class T>
	  class TridiagonalMatrix {//���ԽǾ���
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
		  int n;//����ά��
		  T*t;//���������Ǿ����һά����
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
	  TridiagonalMatrix<T>&TridiagonalMatrix<T>::Store(const T&x, int i, int j) {//store����
		  if (i<1||j<1||i>n||j>n)
		  {
			  throw OutOfBounds();
		  }
		  switch (i - j) {
		  case 1: /* �ͶԽ���*/
			  t[ i-2] = x; break;
		  case 0: /* ���Խ���*/
			  t[n+i-2] = x; break;
		  case -1: /*  �߶Խ���*/
			  t[2*n+i-2] = x; break;
		  default:if (x != 0) cout<<"�ǶԽ�����Ԫ��ֵ����Ϊ��";

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
		  case 1: /* �ͶԽ���*/
			  return t[i - 2];
		  case 0: /* ���Խ���*/
			  return t[n + i - 2];
		  case -1: /*  �߶Խ���*/
			  return t[2 * n + i - 2];
		  default: return 0;
		  }
	  }
