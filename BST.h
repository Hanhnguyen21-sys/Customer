//
// Created by Nguyên Nguyễn on 11/4/23.
//


#include<queue>
using namespace std;
#ifndef NODE
#define NODE
template<class DataType>
    struct Node
    {
        DataType value;
        Node<DataType>* left=nullptr;
        Node<DataType>* right=nullptr;
    };
#endif

#ifndef LAB1_CUSTOMER_BST_H
#define LAB1_CUSTOMER_BST_H
template<class DataType>
class BinaryTree {
private:
    Node<DataType> *root;
    int length;
    std::queue<DataType> inOrder;
    bool insert(Node<DataType> *root, Node<DataType>*newNode);
    Node<DataType> * find(Node<DataType>*tree, const DataType &item) const;
    void deleteAll(const Node<DataType> * tree);
    void deepCopy(const Node<DataType> * tree);
    Node<DataType>* min(Node<DataType>* tree);
    Node<DataType>* max(Node<DataType>* tree);
    bool remove(Node<DataType>* tree, const DataType &item);
    void loadQueueInOrder(Node<DataType>* tree);
    void traverse(Node<DataType> *node);
public:
    BinaryTree();
    ~BinaryTree();
    int getLength() const;
    bool putItem(const DataType &item);
    bool getItem(const DataType &item,DataType &founditem);
    bool isFull();
    void makeEmpty();
    void resetList();
    bool getNextItem(DataType &item);
    bool max(DataType &found_item);
    bool min(DataType &found_item);
    bool deleteItem(const DataType &item);
    void operator=(const BinaryTree<DataType> &rhs);
    BinaryTree(const BinaryTree<DataType> &rhs);
    void print();
    void Order();
};


#endif //LAB1_CUSTOMER_BST_H
