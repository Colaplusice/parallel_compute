using namespace std;

void merge_sort(int *data, int start, int end, int *result){
 3     if(end-start==1)//如果区间中只有两个元素，则对这两个元素进行排序
 4     {
 5         if(data[start]>data[end])
 6         {
 7             int temp=data[start];
 8             data[start]=data[end];
 9             data[end]=temp;
10         }
11         return;
12     }
13     else if(0==end - start)//如果只有一个元素，则不用排序
14         return;
15     else
16     {
17         //继续划分子区间，分别对左右子区间进行排序
18         merge_sort(data,start,(end-start+1)/2+start,result);
19         merge_sort(data,(end-start+1)/2+start+1,end,result);
20         //开始归并已经排好序的start到end之间的数据
21         merge(data,start,end,result);
22         //把排序后的区间数据复制到原始数据中去
23         for(int i = start;i <= end;++i)
24             data[i] = result[i];
25     }
26}
void merge_sort(int *data, int start, int end, int *result)
 2 {
 3     if(1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
 4     {
 5         if(data[start] > data[end])
 6         {
 7             int temp  = data[start];
 8             data[start] = data[end];
 9             data[end] = temp;
10         }
11         return;
12     }
13     else if(0 == end - start)//如果只有一个元素，则不用排序
14         return;
15     else
16     {
17         //继续划分子区间，分别对左右子区间进行排序
18         merge_sort(data,start,(end-start+1)/2+start,result);
19         merge_sort(data,(end-start+1)/2+start+1,end,result);
20         //开始归并已经排好序的start到end之间的数据
21         merge(data,start,end,result);
22         //把排序后的区间数据复制到原始数据中去
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
