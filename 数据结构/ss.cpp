/**
* name:��������
* time:15/8/16 15:00
* environment: ubuntu 14.04�� sublime text 3
*/
#include <iostream>
using namespace std;

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
    int d = maxbit(data, n);//���λ��
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
            k = (data[j] / radix) % 10; //ͳ��ÿ��Ͱ�е����ָ���
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
        for(j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
        {
            k = (data[j] / radix) % 10;//Ͱ�����
            tmp[count[k] - 1] = data[j];//count[]ʮ��Ͱÿ��Ͱ�ĸ���   �����е�Ԫ�ظ�temp
            count[k]--;
        }
        for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data[j] = tmp[j];
        radix = radix * 10;
    }
}

int main()
{
    int array[10] = {73,22,93,43,55,14,28,65,39,81};
    radixsort(array,10);
    printArray(array,10);
    return 0;
}

//���
//14 22 28 39 43 55 65 73 81 93
