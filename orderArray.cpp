//
// Created by Nguyên Nguyễn on 10/11/23.
//
#include "orderArray.h"

template<class DataType>
ArrayADTList<DataType>::ArrayADTList() {
    DataType items[MAX_SIZE];
    length=0;
    cursor=0;
}
template<class DataType>
int ArrayADTList<DataType>::binarySearch(DataType &item) const
{
    int l = 0;
    int h = length-1;
    while (l<=h)
    {
        int mid = (h+l)/2;
        if (items[mid]>item)
        {
            h = mid -1;
        }
        else if (items[mid]<item)
        {
            l = mid +1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
template <class Datatype>
int ArrayADTList<Datatype>::getLength() const{
    return length;
}

template<class DataType>
void ArrayADTList<DataType>::putItem(const DataType &item) {
    // to throw the FullError error
    // throw FullError()
    if (length>=MAX_SIZE) {throw FullError();}
    if (length==0)
    {
        items[0]=item;
        length++;
        cursor=0;
        return;
    }
    int i=length;
    for (;i>=1 && items[i-1]>=item;i--)
    {
        items[i]=items[i-1];
    }
    items[i]=item;
    length++;
    cursor=0;
}

template<class DataType>
bool ArrayADTList<DataType>::getItem(const DataType &item, DataType &found_item) const
{
    int result= binarySearch(item);
    if (result !=-1)
    {
        found_item=item;
        return true;
    }
    return false;
}

template<class DataType>
bool ArrayADTList<DataType>::isFull() const {
    return length==MAX_SIZE;
}

template<class DataType>
void ArrayADTList<DataType>::makeEmpty()
{
    length=0;
}

template<class DataType>
bool ArrayADTList<DataType>::deleteItem(const DataType &item)
{
    int pos = binarySearch(item);
    if (pos == -1) {return false;}
    for (;pos<length;pos++)
    {
        items[pos]=items[pos+1];
    }
    length--;
    cursor=0;
    return true;
}

template<class DataType>
void ArrayADTList<DataType>::resetList()
{
    cursor=0;
}

template<class DataType>
bool ArrayADTList<DataType>::getNextItem(DataType &item)
{
    if (cursor>=length)
    {
        return false;
    }
    item=items[cursor];
    cursor++;
    return true;
}
