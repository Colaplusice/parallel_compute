#include <iostream>
using namespace std;
     template <class T>
     void Swap(T*array,int a,int b){
     T mid=array[a];
     array[a]=array[b];
     array[b]=mid;
     }
     template <class T>
     void SelectSort(T* array, int size)  //ѡ������
     {
     int minIndex;
     for(int i = 0; i < size; i++)
     {
     minIndex = i;
     for(int j = i + 1; j < size; j++)
     {
     if(array[minIndex] > array[j])
     {
     minIndex = j;
     }
     }
     if(minIndex != i)
     {
     Swap(array, i, minIndex);
     }
     }
     }
     template <class T>
     void charupaixu(T*array,int size){
     for(int i=1;i<size;i++){
     for (int j=i;j>0;j--){
     if(array[j]<array[j-1])//�տ�ʼ����һ����������Ȼ�����Ԫ�����κ��������Ƚ�Ѱ�Ҳ���λ��
     Swap(array,j,j-1);
     }
     }
     }
     template <class T>
     void bubblesort(T*array,int size){//ð������  �Ӻ���ǰ�ƶ�СԪ��
     int i,j,flag;
     for(int i=0;i<size;i++) {     //
     //flag=0;
     for(int j=size-1;j>i;j--){
     if(array[j]<array[j-1])
     Swap(array,j,j-1);
    //flag=1;

   //if (!flag) break;
    }
    }
    }
    template <class T>
    void maopao(T*array,int size){ //ð������  ��ǰ�����ƶ���Ԫ��
    for(int i=0;i<size;i++) {
      for(int j=0;j<size-1;j++){
     if(array[j]>array[j+1])
      Swap(array,j,j+1);
    }

    }
    }
    template <class T>                //��������
    void QuickSort(T *array, int left, int right)
    {
    if(left < right)
    {
    int i = left -1, j = right + 1;
    T mid = array[(left + right) / 2];
    while(true)
    {
    while(array[++i] < mid);
    while(array[--j] > mid);
    cout<<i<<" "<<j<<" ";
    if(i >= j)
    {
    break;
    }
    Swap(array, i, j);
    }
    QuickSort(array, left, i - 1);
    QuickSort(array, j + 1, right);
    }
    }//�鲢

template<class T>
void Merge(T data[], T tmpArr[], int lptr, int rptr, int rightEnd)
{
	int leftEnd = rptr - 1;
	int ptr, i;
	ptr = i = lptr;
	while (lptr <= leftEnd && rptr <= rightEnd)
		if (data[lptr] <= data[rptr])
			tmpArr[ptr++] = data[lptr++];
		else
			tmpArr[ptr++] = data[rptr++];
	while (lptr <= leftEnd)
		tmpArr[ptr++] = data[lptr++];
	while (rptr <= rightEnd)
		tmpArr[ptr++] = data[rptr++];
	for (; i <= rightEnd; i++)
		data[i] = tmpArr[i];
}
template<class T>
void MSort(T data[], T tmpArr[], int begin, int end)
{
	int middle;
	if (begin >= end)
		return;
	middle = (begin + end) / 2;   // ��dataƽ��Ϊ[begin..middle]��[middle..end]
	MSort(data, tmpArr, begin, middle);  // �ݹ�ǰ�벿��
	MSort(data, tmpArr, middle + 1, end);  // �ݹ��벿��
	Merge(data, tmpArr, begin, middle + 1, end); // ��data[begin..middle]��data[middle..end]���й鲢
}
template<class T>
void MergeSort(T data[], int n)
{
	T* pArr = NULL;
	pArr = new T[n];
	MSort(data, pArr, 0, n - 1);
	delete[] pArr;
}

//private: r[];
 // template <class T>  //��������

/*
* ��ӡ����
*/
void printArray(int array[],int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
/*
*�����ݵ����λ��,�����������
*/
int maxbit(int data[], int n)
{
    int d = 1; //��������λ��
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(int data[], int n) //��������
{
    int d = maxbit(data, n);
    int tmp[n];
    int count[10]; //������
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //����d������
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //ÿ�η���ǰ��ռ�����
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data[j] = tmp[j];
        radix = radix * 10;
    }
}

int main(){
int a[]={2,5,4,3,1,6};
int b[6];
 //MergeSort(a,6);
//SelectSort(a,6);
//charupaixu(a,6);
//bubblesort(a,6);
//maopao(a,6);
//insertsort(a,6);
//QuickSort(a,0,6);
radixsort(a,6);
for(int i=0;i<6;i++){
 cout<<a[i]<<" ";
}
return 0;
}
