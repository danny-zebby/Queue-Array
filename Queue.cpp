#include "Queue.h"


template<class T>
Queue<T>::Queue(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    front = 0;
    rear = maxQue -1;
    maxQue = max;
    numItems = 0;
    items = new T[maxQue];
}

template<class T>
Queue<T>::Queue()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    front = 0;
    rear = maxQue -1;
    numItems = 0;
    items = new T[maxQue];
}

template<class T>
Queue<T>::~Queue()         // Class destructor
{
    delete[] items;
}

template<class T>
void Queue<T>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = 0;
    rear = maxQue - 1;
}

template<class T>
bool Queue<T>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return numItems == 0;
}

template<class T>
bool Queue<T>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return numItems == maxQue;
}

template<class T>
void Queue<T>::Enqueue(T newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
    if (IsFull() == true)
        throw "Full";
    rear = ++rear %maxQue;
    items[rear] = newItem;
    ++numItems;
}

template<class T>
T Queue<T>::Dequeue()
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       otherwise a EmptyQueue exception has been thrown.
{
    T itemDe = items[++front];
    if(IsEmpty())
        throw " Empty";
    front = ++front %maxQue;
    --numItems;
    return itemDe;
}
