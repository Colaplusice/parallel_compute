#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class LinkedQueue


public:
    LinkedQueue(){front=rear=NULL;}
    ~LinkedQueue();
    bool IsEmpty() const{return front==NULL;}
    bool IsFull() const;
    T First() const;
    T Last() const;
    LinkedQueue<T>& Add(const T& x);
    LinkedQueue<T>& Delete(T& x);
private:
    Node<T>* front;
    Node<T>* rear;

};


#endif // LINKEDQUEUE_H_INCLUDED
