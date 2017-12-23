#include<iostream>
using namespace std;
template <class T>
 class Sort
{
public:
    template <class T>
    void SelectSort(T* array, int size);
    void InsertSort(T* array, int size);
    void BubbleSort(T* array, int size);
    void MergeSort(T* array, int left, int right);
    void Merge(T* array, int left, int mid, int right);
    void HeapSort(T *array, int size);
    void HeapAjust(T *array, int toAjust, int size);
    void QuickSort(T *array, int left, int right);
    void TreeSort(T *array, int size);
    void TreeMidRetrival(T* array, T* temp, int pos, T* lChild, T* rChild);
    void Swap(T* array, int x, int y);
//选择排序法
template <class T>
void Sort::SelectSort(T* array, int size)
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
};
template //交换两个元素
void Sort::Swap(T* array, int x, int y)
{
    T temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

int main(){

return 0;}
