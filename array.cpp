//
// Created by Nguyên Nguyễn on 10/4/23.
//
#include "array.h"
using namespace std;
/**
 * The ArrayADTList class allows users to use an array
 * to store values of the list.
 * The maximum size of list is set to 100.
 */
template<class DataType>
ArrayADTList<DataType>::ArrayADTList()
{
    items= new DataType[MAX_SIZE];
    length=0;
    cursor=0;
}

template <class Datatype>
int ArrayADTList<Datatype>::getLength() const{
    return length;
}

template<class DataType>
void ArrayADTList<DataType>::putItem(const DataType &item) {
    // to throw the FullError error
    // throw FullError()
    if (length>=MAX_SIZE)
    {
        throw FullError();
    }
    else
    {
        items[length] = item;
        length++;
        cursor=0;
    }
}

template<class DataType>
bool ArrayADTList<DataType>::getItem(const DataType &item, DataType &found_item) const
{
    // for loop to find item needed
    for (int i=0;i<length;i++)
    {
        if (items[i]==item)
        {
            found_item=items[i]; //assigns item needed tp the variable
            return true;
        }
    }
    return false;
}

template<class DataType>
bool ArrayADTList<DataType>::isFull() const
{
    return length==MAX_SIZE;
}

template<class DataType>
void ArrayADTList<DataType>::makeEmpty()
{
    length=0;
    cursor=0;
}

template<class DataType>
bool ArrayADTList<DataType>::deleteItem(const DataType &item)
{
    // run the loop to find out the value from list that matches with item
    for (int i=0;i<length;i++)
    {
        if (item==items[i])
        {
            items[i]=items[length-1];// substitute the position of value that
            // we want to delete with the last value in the list since it's unordered list
            length--; //update value of length
            return true;
        }
    }
    return false;
}

template<class DataType>
void ArrayADTList<DataType>::resetList() {
    cursor=0;
}

template<class DataType>
bool ArrayADTList<DataType>::getNextItem(DataType &item)
{
    if(cursor>=length) // check whether the cursor is still in the list or not
    {
        return false;
    }
    item = items[cursor]; // assigns item with the value in the list that the cursor points to
    cursor++;
    return true;
}
