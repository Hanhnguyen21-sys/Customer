#include "linkedlist.h"

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
    // should reset the header, cursor, and length for SAFE!!!
    // create a node and assign the first element in the rhs list to it
    Node<DataType> * temp = rhs.start;
    // run a while loop check if the temp node contains value, and use putItem function
    // to put value into the new list (of left hand-sided)
    while(temp!=nullptr)
    {
        this->putItem(temp->value);
        temp=temp->next; //traverse through the list
    }
}

template<class DataType>
int LinkedADTList<DataType>::getLength() const{
    return length;
}

template<class DataType>
void LinkedADTList<DataType>::putItem(const DataType &item)
{
    //Put the new node in the front of the list so do not need to traverse the whole list
    Node<DataType> * newNode = new Node<DataType>;
    // assign item to new node
    newNode->value= item;
    newNode->next= start;
    start=newNode;
    // update length and cursor
    length++;
    cursor=start;
}

template<class DataType>
bool LinkedADTList<DataType>::getItem(const DataType &item, DataType &found_item) const
{
    Node<DataType> * curr = start;
    while(curr!= nullptr) // a loop used to traverse through the list to find out the item
    {
        if (curr->value== item) // if we found the item needed, then assigns it the found_item variable
        {
            found_item=item;
            return true;
        }
        else
        {
            curr=curr->next;
        }
    }
    return false;
}

template<class DataType>
bool LinkedADTList<DataType>::isFull() const {
    // There is a point at which the computer will run out of memory
    // but for our implementation it is safe to act as if memory is infinite.
    // so that the list is never full
    return false;
}

template<class DataType>
void LinkedADTList<DataType>::makeEmpty()
{
    // go through the list and remove every node from the list using while loop
    while(start!=nullptr)
    {
        Node<DataType> * curr= start;
        start=start->next;
        delete curr;
    }
    // reset attributes
    length=0;
    // head=nullptr;
    // cursor =head;
    cursor=nullptr;
}

template<class DataType>
bool LinkedADTList<DataType>::deleteItem(const DataType &item) {
    // Hint: find the item first then work on deleting it
    // Doesn't delete the item until you've finish working on the list
    // Don't forget to clear the deleted node from memory.
    // This is the hardest method in the assignment, don't forget to breath.
    if (length==0) {return false;} // return false if the list is empty
    Node<DataType> * pre= start;
    Node<DataType> * curr= start->next;
    if (start->value==item) //deal with a special case that there is one node in the list
    {
        // create a temp node to receive the value of start and then delete it
        Node<DataType> *temp = start;
        start = start->next; //set start to nullptr
        delete temp;
        length--; //update length
        return true;
    }
    while(curr!=nullptr) // traverse through the list
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
            // update cursor = start for SAFE
            return true;
        }
        pre=curr;
        curr=curr->next;
    }

    cursor= start;
    return false;
}


template<class DataType>
bool LinkedADTList<DataType>::getNextItem(DataType &item)
{
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
// This one deletes all the nodes in the list
template<class DataType>
LinkedADTList<DataType>::~LinkedADTList() {
    // can call makeEmpty function instead
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


