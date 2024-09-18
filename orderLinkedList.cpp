//
// Created by Nguyên Nguyễn on 10/11/23.
//
#include <iostream>
#include "orderLinkedList.h"

template<class DataType>
LinkedADTList<DataType>::LinkedADTList()
{
    length=0;
    start= nullptr;
    cursor= nullptr;
}

template<class DataType>
LinkedADTList<DataType>::LinkedADTList(const LinkedADTList<DataType> &rhs)
{
    Node<DataType> * temp = rhs.start;
    /** run a while loop check if the temp node contains value, and use putItem function
    to put value into the new list (of left hand-sided) */
    while(temp!=nullptr)
    {
        this->putItem(temp->value);
        temp=temp->next; //traverse through the list to copy elements into
    }
}


template<class DataType>
int LinkedADTList<DataType>::getLength() const{
    return length;
}

template<class DataType>
void LinkedADTList<DataType>::putItem(const DataType &item) {
    // Hint: where can you put the new node so that you don't have to traverse the list?
    Node<DataType> * newNode= new Node<DataType>;
    Node<DataType> * temp = start;
    newNode->value=item;
    newNode->next=nullptr;
    if (start==nullptr ||start->value > item)
    {
        newNode->next=start;
        start=newNode;
        length++;
        cursor=start;
        return;
    }
    while(temp->next!=nullptr && (temp->next->value)<newNode->value)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    length++;
    cursor=start;
}

template<class DataType>
bool LinkedADTList<DataType>::getItem(const DataType &item, DataType &found_item) const{
    // Hint: Watch out that you don't crate an infinite loop.
    if (start==nullptr) {return false;}
    Node<DataType> *temp=start;
    while(temp!=nullptr)
    {
        if (item==temp->value)
        {
            found_item=item;
            return true;
        }
        temp=temp->next;
    }
    return false;
}

template<class DataType>
bool LinkedADTList<DataType>::isFull() const {
    // Hint: There is a point at which the computer will run out of memory
    // but for our implementation it is safe to act as if memory is infinite.
    return false;
}

template<class DataType>
void LinkedADTList<DataType>::makeEmpty() {
    // Hint: You can't just set the length to 0, you need to worry about memory leaks.
    // Hint: Don't forget to reset the start and cursor as well.
    while(start!=nullptr)
    {
        Node<DataType> * curr= start;
        start=start->next;
        delete curr;
    }
    // reset attributes
    length=0;
    cursor=nullptr;
}

template<class DataType>
bool LinkedADTList<DataType>::deleteItem(const DataType &item) {
    // Hint: find the item first then work on deleting it
    // Doesn't delete the item until you've finish working on the list
    // Don't forget to clear the deleted node from memory.
    // This is the hardest method in the assignment, don't forget to breath.
    if(start==nullptr) {return false;} // return false if the list is empty
    Node<DataType> * pre= start;
    Node<DataType> * curr= start->next;
    if(start->value==item) // only one item case
    {
        Node<DataType> * temp= start;
        start=start->next;
        delete temp;
        length--;
        return true;
    }
    while(curr!=nullptr)
    {
        // if the item is found, create new node to receive the item needed to delete
        // set the previous node (from left of deleted node) points to
        // next node (from right of deleted node). Then, delete the new node
        if (curr->value==item)
        {
            Node<DataType> * temp =curr;
            pre->next=curr->next;
            delete temp;
            length--;//update length value
            return true;
        }
        pre=curr;
        curr=curr->next;
    }
    cursor= start;
    return false;
}


template<class DataType>
bool LinkedADTList<DataType>::getNextItem(DataType &item){
    //check whether the cursor is still in the list or not
    if (cursor==nullptr) { return false;}
    // assigns item with the value in the list that the cursor points to
    item = cursor->value;
    cursor=cursor->next;
    return true;
}

template<class DataType>
void LinkedADTList<DataType>::resetList()
{
    cursor=start;
}

// This is the destructor, it will run when the object is removed from memory
// I've included it here because we've not gone over them in class yet.
// This one deletes all the nodes in the list, if you change the names
// of the object properties make sure you update this code.

template<class DataType>
LinkedADTList<DataType>::~LinkedADTList() {

    Node<DataType>* temp;

    while(start != nullptr) {
        temp = start;
        start = temp->next;
        delete temp;
    }
}

template<class DataType>
void LinkedADTList<DataType>::operator=(const LinkedADTList<DataType> &rhs){
    this->makeEmpty(); // make sure the initial list is empty before put data from rhs object to it
    Node<DataType> * temp = rhs.start;
    while(temp!=nullptr)
    {
        this->putItem(temp->value);
        temp=temp->next;
    }
}


