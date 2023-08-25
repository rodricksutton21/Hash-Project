
#pragma once
#include <iostream>
using namespace std;


template <class T>
struct Node
{
    T data;

    Node<T>* next = nullptr;

    Node(T data)
    {
        this->data = data;

    }
};


template <class T>
class LinkedList
{
private:

    Node<T>* mpHead = nullptr;

public:
    //################################################# 
// @par Name 
//    addToEnd
// @purpose 
//    adds an item to the end of the list
// @param [in] : 
//     T data
// @return 
//      none 
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
    void addToEnd(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if (mpHead == nullptr)
            mpHead = newNode;
        else
        {

            Node<T>* node = mpHead;
            while (node->next != nullptr)
                node = node->next;

            node->next = newNode;
        }
    }


    //################################################# 
  // @par Name 
  //    searchNode
  // @purpose 
  //    searches for the first occurence of search and returns it, otherwise null
  // @param [in] : 
  //     T search, Node<T>*& prev
  // @return 
  //      returns node
  // @par References 
  //      None 
  // @par Notes 
  //      None 
  //############################################### 
    Node<T>* searchNode(T search, Node<T>*& prev)
    {
        bool isFound = false;
        prev = nullptr;
        Node<T>* node = mpHead;
        while (node != nullptr)
        {
            isFound = (node->data == search);
            if (isFound)
                break;
            else
            {

                prev = node;
                node = node->next;
            }
        }

        if (isFound)
            return node;
        else
            return nullptr;
    }

    //################################################# 
// @par Name 
//    insert
// @purpose 
//     Adds data as a new Node following the node that contains search
// @param [in] : 
//     T search T data
// @return 
//     none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
    void insert(T search, T data)
    {
        Node<T>* prev;
        Node<T>* node = searchNode(search, prev);
        if (node != nullptr)
        {

            Node<T>* newNode = new Node<T>(data);

            newNode->next = node->next;
            node->next = newNode;
        }
    }

    //################################################# 
// @par Name 
//    deleteNode
// @purpose 
//    Deletes the node that contains search.
// @param [in] : 
//     T search
// @return 
//    none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
    void deleteNode(T search)
    {
        Node<T>* prev;
        Node<T>* node = searchNode(search, prev);
        if (node != nullptr)
        {
            if (prev == nullptr)
                mpHead = node->next;
            else
                prev->next = node->next;

            delete node;
        }
    }
    //################################################# 
// @par Name 
//    printList
// @purpose 
//    prints linked list
// @param [in] : 
//     None 
// @return 
//      none
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 

    void printList()
    {
        for (Node<T>* node = mpHead; node != nullptr; node = node->next)
            cout << node->data << " -> ";

        cout << endl;
    }

    //################################################# 
// @par Name 
//    contains
// @purpose 
//    returns true if the list contains T and false if it doesn't
// @param [in] : 
//     None 
// @return 
//      returns true
// @par References 
//      None 
// @par Notes 
//      None 
//############################################### 
    bool contains(T search)
    {
        Node<T>* prev;
        return (searchNode(search, prev) != nullptr);
    }

    //################################################# 
 // @par Name 
 //    LinkedList
 // @purpose 
 //    destructor that frees memory
 // @param [in] : 
 //     None 
 // @return 
 //    none
 // @par References 
 //      None 
 // @par Notes 
 //      None 
 //############################################### 
    ~LinkedList()
    {
        Node<T>* node = mpHead;
        Node<T>* next;
        while (node != nullptr)
        {
            next = node->next;
            delete node;
            node = next;
        }
    }
};

