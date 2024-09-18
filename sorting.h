//
// Created by Nguyên Nguyễn on 9/29/23.
//
#include <iostream>
#include "date.h"
#include "customer.h"
#include <vector>
#ifndef LAB1_CUSTOMER_SORTING_H
#define LAB1_CUSTOMER_SORTING_H
using namespace std;
void swap(Customer *a, Customer *b);
void selectionSort(vector<Customer*>list, int n);
void insertionSort(vector<Customer*> list, int n);
void bubbleSort(vector<Customer*> list, int n);
int partition(vector<Customer*> list, int lo, int hi);
void qSort(vector<Customer*> list, int lo, int hi);
void quickSort(vector<Customer*> list,int n);
void merge(vector<Customer*> &list, vector<Customer*> &aux, int lo, int mid, int hi);
void mSort(vector<Customer*> &list, vector<Customer*> &aux, int lo, int hi);
void mergeSort(vector<Customer*> &list,int n);
#endif //LAB1_CUSTOMER_SORTING_H
