
#include<iostream>
using namespace std;

#define MAXSIZE 20
#define MAXDEPTH 10

//二叉树节点类
class BinaryTreeNode
{
public:
    BinaryTreeNode() {leftChild = rightChild = 0;}
    BinaryTreeNode(int d) {data = d; leftChild = rightChild = 0;}
    BinaryTreeNode(int d, BinaryTreeNode* left, BinaryTreeNode* right) {data = d; leftChild = left; rightChild = right;}

    int  data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

//最大堆类
class MaxHeap
{
public:
    MaxHeap(int size = 10)
    {
        maxSize = size;
        heap = new int[maxSize + 1];
        currentSize = 0;
    }
    void init(int array[], int arrrayCurrentSize, int arrayMaxSize);
    void insert(int x);
    int deleteMax();

private:
    int currentSize, maxSize;
    int* heap;
};

//最大堆得初始化
void MaxHeap::init(int array[], int arrayCurrentSize, int arrayMaxSize)
{  //把最大堆初始化为数组array
    delete [] heap;
    heap = array;
    currentSize = arrayCurrentSize;
    maxSize = arrayMaxSize;

    //产生一个最大堆
    for(int i = currentSize / 2; i >= 1; i--)
    {
        int y = heap[i];

        //寻找放置y的位置
        int c = 2*i;
        while(c <= currentSize)
        {
            if(c < currentSize && heap[c] < heap[c + 1]) c++;//heap[c]是较大的同胞节点

            //能把y放入heap[c/2]吗
            if(y >= heap[c]) break;//能

            //不能
            heap[c / 2] = heap[c];//将孩子上移
            c *= 2;//下移一层
        }
        heap[c / 2] = y;
    }
}

//最大堆的插入
void MaxHeap::insert(int x)
{//把x插入到最大堆中
    if(currentSize == maxSize) {cout << "out of bounds"; return;}

    //为x寻找合适的位置
    //从新的的叶节点开始，并沿着树上升
    int i = ++currentSize;
    while(i != 1 && x > heap[i / 2])//在i出插入新元素不会改变最大堆得性质
    {
        //不能把x放入heap[i]
        heap[i] = heap[i / 2];//将元素下移
        i /= 2;//移向父节点
    }
    heap[i] = x;
}

//最大堆得删除
int MaxHeap::deleteMax()
{//检查是否为空
    if(currentSize == 0) {cout << "there is no mem"; return -1;}

    int x = heap[1];//最大元素
    //重构堆
    int y = heap[currentSize--];//最后一个元素

    //从根开始，，为y寻找合适的位置
    int i = 1;
    int ci = 2;
    while(ci <= currentSize)
    {
        if(ci < currentSize && heap[ci] < heap[ci + 1]) ci++;//heap[ci]是较大的孩子

       // 能把y放入heap[i]吗
        if(y >= heap[ci]) break;//可以把y放入heap[ci]

        //不能
        heap[i] = heap[ci];//将孩子上移一层
        i = ci;//下移一层
        ci *= 2;
    }
    heap[i] = y;

    return x;
}

//二叉搜索树类
class BinarySearchTree
{
public:
    BinarySearchTree() {root = 0;}

    void insert(int e);
    void preOrder(BinaryTreeNode* t);

    BinaryTreeNode* root;
};

//二叉搜索树的插入
void BinarySearchTree::insert(int e)
{
    BinaryTreeNode* p = root;
    BinaryTreeNode* pp = 0;

    while(p)
    {
        pp = p;
        if(e < p->data) p = p->leftChild;
        else if(e > p->data) p = p->rightChild;
        else {cout << "bad input"; return;}
    }

    BinaryTreeNode* r = new BinaryTreeNode(e);
    if(root)
    {
        if(e < pp->data) pp->leftChild = r;
        else pp->rightChild = r;
    }
    else
        root = r;
}

//二叉搜索树的遍历
void BinarySearchTree::preOrder(BinaryTreeNode* t)
{
    if(t != NULL)
    {
        preOrder(t->leftChild);
        cout << t->data << endl;
        preOrder(t->rightChild);
    }
}

//Huffman 树类
class HuffmanTree
{
public:
    HuffmanTree(int a[], int n);

    void preOrder(BinaryTreeNode* b);
    void printCode(BinaryTreeNode* b, int len);

    BinaryTreeNode** b;
};

//哈夫曼树
HuffmanTree::HuffmanTree(int a[], int n)
{
    b = new BinaryTreeNode*[100];

    for(int i = 0; i < n; i++)
        b[i] = new BinaryTreeNode(a[i + 1]);


    for(int i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
    {
        //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
        int k1 = -1, k2;
        for(int j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
        {
            if(b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if(b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for(int j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
        {
            if(b[j] != NULL)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->data < b[k2]->data)
                    k2 = j;
            }
        }

        BinaryTreeNode *q = new BinaryTreeNode();
        q->data = b[k1]->data + b[k2]->data;
        q->leftChild = b[k1];
        q->rightChild = b[k2];

        b[k1] = q;
        b[k2] = NULL;

    }

}

//哈夫曼树遍历方法
void HuffmanTree::preOrder(BinaryTreeNode* b)
{
    if (b != NULL)
    {
        cout << b->data << endl;
        preOrder(b->leftChild);
        preOrder(b->rightChild);
    }
}

void HuffmanTree::printCode(BinaryTreeNode* b, int len)
{
    static int code[MAXDEPTH];
    if(b != NULL)
    {
        if(b->leftChild == NULL && b->rightChild == NULL)
        {
            cout << "the huffman code of " << b->data << " is ";
            for(int i = 0; i < len; i++)
            {
                cout << code[i];
            }
            cout << endl;

        }
        code[len] = 0;
        printCode(b->leftChild, len + 1);
        code[len] = 1;
        printCode(b->rightChild, len + 1);
    }
}

//堆排序
void heapSort(int a[], int n)
{
    int b[n + 1];
    //创建一个最大堆
    MaxHeap maxHeap;
    maxHeap.init(a, n, n);

    //从最大堆中逐个抽取元素
    for(int i = 1; i <= n; i++)
    {
        cout << maxHeap.deleteMax() << endl;
    }
    //保存数组
    for(int i = 1; i <= n; i++)
    {
        a[i] = b[i];
    }
}


int main()
{
    int a[MAXSIZE];
    int n;
    cout << "输入数组长度：" << endl;
    cin >> n;	//输入样例 5
    cout << "输入数据：" << endl;
    for(int i = 1; i <= n; i++)	//输入样例 1 32 21 35 41
        cin >> a[i];

    cout << "bst:" << endl;
    BinarySearchTree bstree;
    for(int i =1; i <= 5; i++)
        bstree.insert(a[i]);
    cout << "preOrder:" << endl;
    bstree.preOrder(bstree.root);

    cout << "huffman:" << endl;
    HuffmanTree htree(a, 5);
    htree.printCode(htree.b[0], 0);

    cout << "heap sort:" << endl;
    heapSort(a, 5);
    return 0;
}
