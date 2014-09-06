#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;
template <class T>
class Node
{
    public:
        Node(T*);
        T *data;
        Node<T> *next;
};


template <class T>
Node<T>::Node(T *data)
{
    this->data = data;
    this->next = NULL;
}
#endif // NODE_H

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
        int contains(T*);
        T* get(int index);
		void addToHead(T*);
		void addToTail(T*);
		void deleteNode(int index);
		void displayAllNodes();
		int getSize();
		int nodeCount;
        Node<T>* head;

	private:
		void displayNode( Node<T>* );



};


template <class T>
LinkedList<T>::LinkedList()
{
	nodeCount = 0;
	head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
int LinkedList<T>::getSize()
{
    return nodeCount;
}

template <class T>
void LinkedList<T>::addToHead(T *newData)
{
	Node<T> *pNew = new Node<T>(newData);
	pNew -> next = head;
	head = pNew;
	nodeCount++;
}

template <class T>
void LinkedList<T>::addToTail(T *newData)
{
    Node<T> *pCur = head;
    Node<T> *pNew;
    if(!pCur)
    {
        pNew = new Node<T>(newData);
        pNew->next = head;
        head = pNew;
    }
    else
    {
        while(pCur->next)
            pCur = pCur->next;
        pNew = new Node<T>(newData);
        pCur->next = pNew;
    }
    nodeCount++;
}

template <class T>
void LinkedList<T>::displayAllNodes()
{
	Node<T> *pCur = head;
	int count = 1;

	while (pCur)
	{
		cout << "Node " << count << ": ";
		displayNode( pCur );
		cout << endl;

		count++;
		pCur = pCur->next;
	}
	return;
}

template <class T>
void LinkedList<T>::displayNode( Node<T> *node )
{
	cout << node->data;
	return;
}

template <class T>
int LinkedList<T>::contains(T* item)
{
    Node<T> *pCur = head;
    int count = 0;

    while(pCur)
    {
        if(*(pCur->data)== item)
        {
            return count;
        }
        else
        {
            count++;
            pCur = pCur->next;
        }
    }
    return -1;
}

template <class T>
T* LinkedList<T>::get(int index)
{
    if(nodeCount == 0)
        return NULL;
    if(index > nodeCount || index < 0)
        return NULL;

    Node<T> *pCur = head;

    //if(*index == 0)
      //  return pCur->data;

    for(int i = 0; i < index; i++)
    {
        pCur = pCur->next;
    }
    return pCur->data;
}

template <class T>
void LinkedList<T>::deleteNode(int index)
{
    Node<T> *pCur = head;
    Node<T> *pPrev = NULL;
    Node<T> *pNext = NULL;

    if(index == 0)
    {
        pNext = pCur->next;
        head = pNext;
        delete pCur;
        nodeCount--;
        return;
    }

    for(int i = 0; i < index; i++)
    {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if(!pCur->next)
    {
        pPrev->next = NULL;
        //delete pCur;
    }
    else
    {
        pNext = pCur->next;
        pPrev->next = pNext;
        //delete pCur;
    }
    nodeCount--;

}
#endif // LINKEDLIST_H
