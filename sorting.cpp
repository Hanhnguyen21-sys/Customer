//
// Created by Nguyên Nguyễn on 9/29/23.
//
#include "date.h"
#include "customer.h"
#include <vector>
using namespace std;
void swap(Customer *a, Customer *b)
{
    Customer x=*a;
    *a=*b;
    *b=x;
}

void selectionSort(vector<Customer*> list, int n)
{
    for (int i=0;i<n;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if(*list[j]<*list[min])
            {
                min=j;
            }
        }
        swap(list[min],list[i]);
    }
}
void insertionSort(vector<Customer*> list, int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (*list[j] < *list[j -1])
            {
                swap(list[j],list[j-1]);
            } else {
                break;
            }
        }
    }
}
void bubbleSort(vector<Customer*> list, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (*list[j] > *list[j+1])
            {
                swap(list[j],list[j+1]);
            }
        }
    }
}

int partition(vector<Customer*> list, int lo, int hi) {
    int i = lo;         // left indices
    int j = hi + 1;      // right indices
    Customer * customerLow = list[lo];
    while(true) {
        // scan right until you find a larger value
        while (*list[++i] < *customerLow) {
            if (i == hi) break;
        }
        // scan left until you find a smaller value
        while (*customerLow < *list[--j]) {
            if (j == lo) break;
        }
        // if i <= j we're done
        if (i >= j) break;
        // swap i and j in the list and repeat
        swap(list[i],list[j]);
    }
    swap(list[lo], list[j]);
    return j;
}

void qSort(vector<Customer*> list, int lo, int hi) {
    //base case
    if (hi <= lo) { return;}
    //general case
    int j = partition(list, lo, hi);

    qSort(list, lo, j - 1);
    qSort(list, j + 1, hi);
}

void quickSort(vector<Customer*> list,int n) {

    qSort(list, 0, n-1);
}

void merge(vector<Customer*>& list, vector<Customer*> &aux, int lo, int mid, int hi) {
    int i = lo;
    int j = mid+1;
    // copy the section of collection we're working on.
    for (int k = lo; k <= hi; k++) {
        aux[k] = list[k];
    }
    for (int k = lo; k <= hi; k++) {
        if (i > mid)                list[k] = aux[j++];
        else if (j > hi)            list[k] = aux[i++];
        else if (*aux[j] < *aux[i])   list[k] = aux[j++];
        else                        list[k] = aux[i++];
    }
}
void mSort(vector<Customer*> &list, vector<Customer*> &aux, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo)/2;
    mSort(list, aux, lo, mid);
    mSort(list, aux, mid+1, hi);
    merge(list, aux, lo, mid, hi);
}

void mergeSort(vector<Customer*> &list, int n) {
    vector<Customer*> aux=list;
    mSort(list, aux, 0, n - 1);
}
