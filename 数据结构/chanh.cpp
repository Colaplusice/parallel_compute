
#include <iostream>

#include<iostream>
#include<string.h>
using namespace std;

class BinaryTreeNode
{
public:
    BinaryTreeNode() { leftChild = rightChild = 0; }
    BinaryTreeNode(char c) { data = c; leftChild = rightChild = 0; }
    BinaryTreeNode(char c, BinaryTreeNode* left, BinaryTreeNode* right) { data = c; leftChild = left; rightChild = right; }

    char data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
};

class Node	//队列类中用链表存
{
public:
    BinaryTreeNode *data;
    Node *next;
    Node() { next = NULL; };
    Node(BinaryTreeNode *item, Node* link = NULL) { data = item; next = link; };
};

//队列类，作为层次遍历的辅助数据结构用
class LinkQueue
{
private:
    Node *front, *rear;
public:
    LinkQueue() { rear = front = new Node; };
    bool empty() { return front == rear; };
    void outQueue(BinaryTreeNode * &e);
    void inQueue(BinaryTreeNode * &e);

};

void LinkQueue::outQueue(BinaryTreeNode * &e)
{
    Node *tmpPtr = front->next;
    e = tmpPtr->data;
    front->next = tmpPtr->next;
    if (rear == tmpPtr) rear = front;
    delete tmpPtr;
}

void LinkQueue::inQueue(BinaryTreeNode * &e)
{
    Node *tmpPtr = new Node(e);
    rear->next = tmpPtr;
    rear = tmpPtr;
}

class BinaryTree
{
public:
    BinaryTree() { root = 0; }
    void getRoot(char* c);

    void insertLeftChild(BinaryTreeNode* t, char c);
    void insertRightChild(BinaryTreeNode* t, char c);
    void preOrder(BinaryTreeNode *t);
    void inOrder(BinaryTreeNode* t);
    void postOrder(BinaryTreeNode* t);
    void levelOrder(BinaryTreeNode* t);
    void preOrderForCount(BinaryTreeNode* t);
    int height(BinaryTreeNode* t);
    int size();

    BinaryTreeNode* root;
    int count = 0;
};

void BinaryTree::insertLeftChild(BinaryTreeNode* t, char c)
{
    t->leftChild = new BinaryTreeNode(c);
}

void BinaryTree::insertRightChild(BinaryTreeNode* t, char c)
{
    t->rightChild = new BinaryTreeNode(c);
}

void BinaryTree::getRoot(char* c)
{
    if (root) *c = root->data;
    else { cout << "root is empty"; return; }
}


void BinaryTree::preOrder(BinaryTreeNode* t)	//前序遍历
{
    if (t)
    {
        cout << t->data;
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

void BinaryTree::inOrder(BinaryTreeNode* t)	//中序遍历
{
    if (t)
    {
        inOrder(t->leftChild);
        cout << t->data;
        inOrder(t->rightChild);
    }
}

void BinaryTree::postOrder(BinaryTreeNode* t)	//后序遍历
{
    if (t)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        cout << t->data;
    }
}

void BinaryTree::levelOrder(BinaryTreeNode* t)	//层次遍历
{
    LinkQueue q;
    bool isNullAtFirst = true;
    while (t)
    {
        cout << t->data;

        if (t->leftChild) q.inQueue(t->leftChild);
        if (t->rightChild) q.inQueue(t->rightChild);

        if (q.empty()) return;

        q.outQueue(t);
    }
}

int BinaryTree::height(BinaryTreeNode* t)	//返回一个节点的高度
{
    if (!t) return 0;
    int heightLeft = height(t->leftChild);
    int heightRight = height(t->rightChild);
    if (heightLeft > heightRight) return ++heightLeft;
    else return ++heightRight;
}

void BinaryTree::preOrderForCount(BinaryTreeNode* t)	//前序遍历
{
    if (t)
    {
        count++;
        preOrderForCount(t->leftChild);
        preOrderForCount(t->rightChild);
    }
}

int BinaryTree::size()	//返回二叉树节点数目
{
    count = 0;
    preOrderForCount(root);
    return count;
}

//前序中序生成后序
void generatePostOrder(char* preOrder, char* inOrder, int length)
{
    if (length == 0) return;

    BinaryTreeNode* t = new BinaryTreeNode(*preOrder);
    int rootIndex = 0;
    for (; rootIndex < length; rootIndex++)
    {
        if (inOrder[rootIndex] == *preOrder)
            break;
    }
    //左子树递归
    generatePostOrder(preOrder + 1, inOrder, rootIndex);
    //右子树递归
    generatePostOrder(preOrder + rootIndex + 1, inOrder + rootIndex + 1, length - (rootIndex + 1));
    cout << t->data;
    return;
}

int main()
{
    /*
     G
  D     M
A   F H   Z
  E
     */
    BinaryTree b;
    b.root = new BinaryTreeNode('G');
    b.insertLeftChild(b.root, 'D');
    b.insertRightChild(b.root, 'M');
    b.insertLeftChild(b.root->leftChild, 'A');
    b.insertRightChild(b.root->leftChild, 'F');
    b.insertLeftChild(b.root->leftChild->rightChild, 'E');
    b.insertLeftChild(b.root->rightChild, 'H');
    b.insertRightChild(b.root->rightChild, 'Z');

    cout << "这个二叉树的前序遍历为：";
    b.preOrder(b.root);
    cout << endl;

    cout << "这个二叉树的中序遍历为：";
    b.inOrder(b.root);
    cout << endl;

    cout << "这个二叉树的后序遍历为：";
    b.postOrder(b.root);
    cout << endl;

    cout << "这个二叉树的层次遍历为：";
    b.levelOrder(b.root);
    cout << endl;

    cout << "这个二叉树的节点数目为：" << b.size() << endl;

    cout << "这个二叉树根节点的高度为：" << b.height(b.root) << endl;

    cout << endl;


    char *pre = new char[20];
    char *in = new char[20];
    cout << "请输入一个二叉树的前序遍历：" << endl;
    cin >> pre;	//GDAFEMHZ
    cout << "请输入一个二叉树的中序遍历：" << endl;
    cin >> in;	//ADEFGHMZ

    cout << "这个二叉树的后序遍历为：" << endl;
    generatePostOrder(pre, in, strlen(pre));
    //system("pause");

    return 0;}
