//
// Created by Nguyên Nguyễn on 10/11/23.
//
#include "customer.h"
#ifndef LAB1_CUSTOMER_ORDERARRAY_H
#define LAB1_CUSTOMER_ORDERARRAY_H
template <class DataType>
class ArrayADTList {

public:
    /**
     * The subclass FullError is used to throw error when list is full
     */
    class FullError {
    public:
        char const *message() { return "List is full."; }
    };
    /**
     * A constructor initializes values for objects at the beginning
     */
    ArrayADTList();
    /**
     * The function returns the length of the list
     * @return length of list
     */
    int getLength() const;
    /**
     * The function inserts new items into the list and should check
     * inserted items are in correct order since this is the ordered list
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
private:
    // feel free to change these property names if you want
    static const long MAX_SIZE = 100;
    DataType items[MAX_SIZE];
    long length; // Use this property to keep track of the list length
    long cursor; // Use this property only in getNextItem, Reset list
    /**
     * The function finds the position of target item in a array using binary search
     * which compares the item to the middle item of the array, if they match, return the position
     * Otherwise, if the search continues with the lower half of array if the target item < middle element
     * if the search continues with the upper half of array if the target item > middle element
     * @param item - value that users want to get the position
     * @return a position of item
     */
    int binarySearch(DataType &item) const;
};

#endif //LAB1_CUSTOMER_ORDERARRAY_H
