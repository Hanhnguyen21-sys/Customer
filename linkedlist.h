//
// Created by Nguyên Nguyễn on 10/4/23.
//
#include <iostream>
#ifndef NODE
#define NODE
template <class DataType>
struct Node {
    DataType value;
    Node<DataType>* next;
};
#endif
#ifndef LAB1_CUSTOMER_LINKEDLIST_H
#define LAB1_CUSTOMER_LINKEDLIST_H



/**
 * The LinkedADTList class allows users to use a linked list
 * to store values of the list.
 */
template <class DataType>
class LinkedADTList {
public:
    /**
     * Constructor is used to assign initial values for attributes of objects in the class
     */
    LinkedADTList();
    /**
     * Copy constructor copies value of one object to another object belonging to the same class
     * @param rhs - the object that we want to copy its data
     */
    LinkedADTList(const LinkedADTList<DataType> &rhs);
    /**
     * Destructor deletes the list after being used in order to avoid memory leak
     */
    ~LinkedADTList();
    /**
     * The function returns the length of the list
     * @return length of list
     */
    int getLength() const;
    /**
     * The function inserts new items into the list
     * @param item - the item that users want to put in the list
     */
    void putItem(const DataType &item);
    /**
    * The function finds the item in the list and assigns that item to found_item variable
    * @param item - item that users want to find
    * @param found_item - used to assign the value of found item
    * @return true if the item was found and false if not
    */
    bool getItem(const DataType &item, DataType &found_item) const;
    /**
     * The function checks whether the list is full or not
     * @return - true if the list is full, and false if not
     */
    bool isFull() const;
    /**
     * The function sets the list to empty
     */
    void makeEmpty();
    /**
      * The function removes the item that users want and returns true
      * if the item is found in the list; otherwise, returns false
      * @param item - the item that users want to delete
      * @return - true if the item is in the list and false if not
      */
    bool deleteItem(const DataType &item);
    /**
     * The function assigns data in the list into item variable
     * @param item - values in the list are assigned to the item variable
     * @return - true if the item is in the list and false if not
     */
    bool getNextItem(DataType &item);
    /**
     * The function sets the cursor for getNextItem to the beginning of the list
     */
    void resetList();
    /**
     * An assignment operator simply assigns values of one item to another
     * @param rhs - the side that we want to take data from
     */
    void operator=(const LinkedADTList<DataType>&rhs);


private:
    Node<DataType>* start= nullptr;
    long length=0;                  // Use this property to keep track of the list length
    Node<DataType>* cursor= nullptr;   // Use this property only in getNextItem and Reset list
};




#endif //UNSORTED_LISTS_LINKEDADTLIST_H