//
// Created by Nguyên Nguyễn on 11/5/23.
//
#include "BST.cpp"
#include "customer.h"
#include "date.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
//    BinaryTree<int> list;
//    list->putItem(4);
//    list->putItem(5);
//    list->putItem(3);

//    BinaryTree<Customer>* list = new BinaryTree<Customer>();
//    Customer::setCompareWith(CreditScore);
//    ifstream infile("data.txt");
//    if (!infile.is_open())
//    {
//        cout << "Error opening the file" << endl;
//        return 1;
//    }
//    else
//    {
//        string line;
//        //getline(infile,line,'\n');
//        while(getline(infile,line,'\n'))
//        {
//            Customer* customer = new Customer(line);
//            list->putItem(*customer);
//        }
//    }
//    cout << list->getLength() << endl;
//    Customer c1 = Customer("9396-HG3rcc2a819\taoiller252p\tAlanah\tOiller\t425 Ridgeview Park\tNorfolk\tVA\t23509\taoiller252p@4shared.com\tNon-binary\tVon LLC\tAccountant I\t8/7/2021\t555-75-0692\t10/4/1972\t363580\t615\t224982.03");
//    list->deleteItem(c1);
//    cout << list->getLength();
//    list->Order();
    //list->resetList();
//    Customer *c2;
//    list->min(c2);
//    cout << *c2;


//    cout <<list->getLength() << endl;
//    //list->getItem(c1,c2);
//    bool result=list->getNextItem(c2);
//    cout << result << endl;

    //list->print();
//    cout << list->getLength() << endl;
//    while(list->getNextItem(c2))
//    {
//        cout << *c2 << endl;
//    }


    BinaryTree<int> list;
    int items[] = {10,11,5,3,6};
    for (int i=0;i<5;i++)
    {
        list.putItem(items[i]);
    }
    list.deleteItem(10);
    cout << "The length of list: " << list.getLength() << endl;
    list.resetList();
    int item;
    while(list.getNextItem(item))
    {
        cout << item << " ";
    }
    cout << "\nEnd code";
    return 0;
}