
#include<iostream>
using namespace std;

#define MAXSIZE 20
#define MAXDEPTH 10

//�������ڵ���
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

//������
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

//���ѵó�ʼ��
void MaxHeap::init(int array[], int arrayCurrentSize, int arrayMaxSize)
{  //�����ѳ�ʼ��Ϊ����array
    delete [] heap;
    heap = array;
    currentSize = arrayCurrentSize;
    maxSize = arrayMaxSize;

    //����һ������
    for(int i = currentSize / 2; i >= 1; i--)
    {
        int y = heap[i];

        //Ѱ�ҷ���y��λ��
        int c = 2*i;
        while(c <= currentSize)
        {
            if(c < currentSize && heap[c] < heap[c + 1]) c++;//heap[c]�ǽϴ��ͬ���ڵ�

            //�ܰ�y����heap[c/2]��
            if(y >= heap[c]) break;//��

            //����
            heap[c / 2] = heap[c];//����������
            c *= 2;//����һ��
        }
        heap[c / 2] = y;
    }
}

//���ѵĲ���
void MaxHeap::insert(int x)
{//��x���뵽������
    if(currentSize == maxSize) {cout << "out of bounds"; return;}

    //ΪxѰ�Һ��ʵ�λ��
    //���µĵ�Ҷ�ڵ㿪ʼ��������������
    int i = ++currentSize;
    while(i != 1 && x > heap[i / 2])//��i��������Ԫ�ز���ı����ѵ�����
    {
        //���ܰ�x����heap[i]
        heap[i] = heap[i / 2];//��Ԫ������
        i /= 2;//���򸸽ڵ�
    }
    heap[i] = x;
}

//���ѵ�ɾ��
int MaxHeap::deleteMax()
{//����Ƿ�Ϊ��
    if(currentSize == 0) {cout << "there is no mem"; return -1;}

    int x = heap[1];//���Ԫ��
    //�ع���
    int y = heap[currentSize--];//���һ��Ԫ��

    //�Ӹ���ʼ����ΪyѰ�Һ��ʵ�λ��
    int i = 1;
    int ci = 2;
    while(ci <= currentSize)
    {
        if(ci < currentSize && heap[ci] < heap[ci + 1]) ci++;//heap[ci]�ǽϴ�ĺ���

       // �ܰ�y����heap[i]��
        if(y >= heap[ci]) break;//���԰�y����heap[ci]

        //����
        heap[i] = heap[ci];//����������һ��
        i = ci;//����һ��
        ci *= 2;
    }
    heap[i] = y;

    return x;
}

//������������
class BinarySearchTree
{
public:
    BinarySearchTree() {root = 0;}

    void insert(int e);
    void preOrder(BinaryTreeNode* t);

    BinaryTreeNode* root;
};

//�����������Ĳ���
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

//�����������ı���
void BinarySearchTree::preOrder(BinaryTreeNode* t)
{
    if(t != NULL)
    {
        preOrder(t->leftChild);
        cout << t->data << endl;
        preOrder(t->rightChild);
    }
}

//Huffman ����
class HuffmanTree
{
public:
    HuffmanTree(int a[], int n);

    void preOrder(BinaryTreeNode* b);
    void printCode(BinaryTreeNode* b, int len);

    BinaryTreeNode** b;
};

//��������
HuffmanTree::HuffmanTree(int a[], int n)
{
    b = new BinaryTreeNode*[100];

    for(int i = 0; i < n; i++)
        b[i] = new BinaryTreeNode(a[i + 1]);


    for(int i = 1; i < n; i++)//���� n-1 ��ѭ��������������
    {
        //k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�
        int k1 = -1, k2;
        for(int j = 0; j < n; j++)//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���
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
        for(int j = k2; j < n; j++)//�ӵ�ǰɭ���������СȨֵ���ʹ���С
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

//����������������
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

//������
void heapSort(int a[], int n)
{
    int b[n + 1];
    //����һ������
    MaxHeap maxHeap;
    maxHeap.init(a, n, n);

    //�������������ȡԪ��
    for(int i = 1; i <= n; i++)
    {
        cout << maxHeap.deleteMax() << endl;
    }
    //��������
    for(int i = 1; i <= n; i++)
    {
        a[i] = b[i];
    }
}


int main()
{
    int a[MAXSIZE];
    int n;
    cout << "�������鳤�ȣ�" << endl;
    cin >> n;	//�������� 5
    cout << "�������ݣ�" << endl;
    for(int i = 1; i <= n; i++)	//�������� 1 32 21 35 41
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
