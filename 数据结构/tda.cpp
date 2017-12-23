using namespace std;

void merge_sort(int *data, int start, int end, int *result){
 3     if(end-start==1)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
 4     {
 5         if(data[start]>data[end])
 6         {
 7             int temp=data[start];
 8             data[start]=data[end];
 9             data[end]=temp;
10         }
11         return;
12     }
13     else if(0==end - start)//���ֻ��һ��Ԫ�أ���������
14         return;
15     else
16     {
17         //�������������䣬�ֱ�������������������
18         merge_sort(data,start,(end-start+1)/2+start,result);
19         merge_sort(data,(end-start+1)/2+start+1,end,result);
20         //��ʼ�鲢�Ѿ��ź����start��end֮�������
21         merge(data,start,end,result);
22         //���������������ݸ��Ƶ�ԭʼ������ȥ
23         for(int i = start;i <= end;++i)
24             data[i] = result[i];
25     }
26}
void merge_sort(int *data, int start, int end, int *result)
 2 {
 3     if(1 == end - start)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
 4     {
 5         if(data[start] > data[end])
 6         {
 7             int temp  = data[start];
 8             data[start] = data[end];
 9             data[end] = temp;
10         }
11         return;
12     }
13     else if(0 == end - start)//���ֻ��һ��Ԫ�أ���������
14         return;
15     else
16     {
17         //�������������䣬�ֱ�������������������
18         merge_sort(data,start,(end-start+1)/2+start,result);
19         merge_sort(data,(end-start+1)/2+start+1,end,result);
20         //��ʼ�鲢�Ѿ��ź����start��end֮�������
21         merge(data,start,end,result);
22         //���������������ݸ��Ƶ�ԭʼ������ȥ
23         for(int i = start;i <= end;++i)
24             data[i] = result[i];
25     }
26 }
 int main()
 2 {
 3     int data[] = {9,6,7,22,20,33,16,20};
 4     const int length = 8;
 5     int result[length];
 6     cout << "Before sorted:" << endl;
 7     for(int i = 0;i < length;++i)
 8         cout << data[i] << "  ";
 9     cout << endl;
10     cout << "After sorted:" << endl;
11     merge_sort(data,0,length-1,result);
12     for(int i = 0;i < length;++i)
13         cout << data[i] << "  ";
14     cout << endl;
16     return 0;
17 }
