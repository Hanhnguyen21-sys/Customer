//
// Created by Nguyên Nguyễn on 11/4/23.
//

#include "BST.h"
#include <iostream>
using namespace std;
template<class DataType>
BinaryTree<DataType>::BinaryTree()
{
    root=nullptr;
    length=0;
    std::queue<DataType> inOrder;
}
template<class DataType>
int BinaryTree<DataType>::getLength() const
{
    return length;
}
template<class DataType>
bool BinaryTree<DataType>::insert(Node<DataType> *root, Node<DataType>* newNode)
{
    // case1: if the item is already existed
    if (newNode->value==root->value)
    {
        return false;
    }
    // case2: tree is empty
    if (root==nullptr)
    {
        root=newNode;
        length++;
        return true;
    }
    // case3: find appropriate position to insert
    if (root->value>newNode->value) //go to the left
    {
        // if there is no left child
        if (root->left==nullptr)
        {
            root->left=newNode;
            length++;
            return true;
        }
        else
        {
            return insert(root->left,newNode);
        }
    }
    else // go to right sub-tree
    {
        if (root->right==nullptr)
        {
            root->right=newNode;
            length++;
            return true;
        }
        else
        {
            return insert(root->right,newNode);
        }
    }
}

template<class DataType>
bool BinaryTree<DataType>::putItem(const DataType &item)
{
    Node<DataType> * temp=new Node<DataType>;
    temp->value=item;
    temp->right=temp->left=nullptr;
    if (root==nullptr) //empty tree
    {
        root=temp;
        length++;
        return true;
    }
    return insert(root,temp);
}

template<class DataType>
Node<DataType> * BinaryTree<DataType>::find(Node<DataType> *tree, const DataType &item) const
{
    if (tree==nullptr){return nullptr;} //empty tree
    else if(tree->value==item){return tree;}
    else if (tree->value>item){return find(tree->left,item);}
    else{return find(tree->right,item);}
}

template<class DataType>
bool BinaryTree<DataType>::getItem(const DataType &item, DataType &founditem)
{
    Node<DataType> * findNode = find(root,item);
    if (findNode==nullptr){return false;} // tree is empty so no item to find
    else
    {
        founditem=findNode->value;
        return true;
    }
}
template<class DataType>
bool BinaryTree<DataType>::isFull() {return false;}

template<class DataType>
void BinaryTree<DataType>::makeEmpty()
{
    deleteAll(root);
    length=0;
    root=nullptr;
}
template<class DataType>
void BinaryTree<DataType>::deleteAll(const Node<DataType> * tree)
{
    if (tree==nullptr){return;}
    deleteAll(tree->left);
    deleteAll(tree->right);
    delete tree;
}

template<class DataType>
void BinaryTree<DataType>::deepCopy(const Node<DataType> * tree)
{
    if (tree==nullptr){return ;}
    this->putItem(tree->value);
    deepCopy(tree->left);
    deepCopy(tree->right);
}

template<class DataType>
void BinaryTree<DataType>::loadQueueInOrder(Node<DataType>*tree)
{
    if (tree==nullptr){return;}
    loadQueueInOrder(tree->left);
    inOrder.push(tree->value);
    loadQueueInOrder(tree->right);
}
template<class DataType>
void BinaryTree<DataType>::Order()
{
    loadQueueInOrder(root);
}
template<class DataType>
Node<DataType>*  BinaryTree<DataType>:: min(Node<DataType>* tree)
{
    loadQueueInOrder(tree);
    return find(tree,inOrder.front());
}
template<class DataType>
Node<DataType>*  BinaryTree<DataType>:: max(Node<DataType>* tree)
{
    loadQueueInOrder(tree);
    return find(tree,inOrder.back());
}
template<class DataType>
bool BinaryTree<DataType>::min(DataType &found_item)
{
    if (root==nullptr){return false;}
    Node<DataType> *found = min(root);
    if (found!=nullptr)
    {
        found_item=found->value;
        return true;
    }
    return false;
}
template<class DataType>
bool BinaryTree<DataType>::max(DataType &found_item)
{
    if (root==nullptr){return false;}
    Node<DataType> *found = max(root);
    if (found!=nullptr)
    {
        found_item=found->value;
        return true;
    }
    return false;
}
template<class DataType>
void BinaryTree<DataType>::operator=(const BinaryTree<DataType> &rhs){
    this->deleteAll(root);
    deepCopy(rhs.root);
}
template<class DataType>
BinaryTree<DataType>::BinaryTree(const BinaryTree<DataType> &rhs) //traverse BST in PreOrder
{
    root=nullptr;
    length=0;
    this->deepCopy(rhs.root);
}
template<class DataType>
BinaryTree<DataType>::~BinaryTree()
{
    deleteAll(root);
}

template<class DataType>
void BinaryTree<DataType>::resetList() {
    //this is a nice fast way to reset the queue to blank
    std::queue<DataType> empty;
    std::swap( inOrder, empty );
    loadQueueInOrder(root);
}
template<class DataType>
bool BinaryTree<DataType>::getNextItem(DataType &item) {
    if (inOrder.empty()){return false;}
    item=inOrder.front();
    inOrder.pop();
    return true;
}

template<class DataType>
bool BinaryTree<DataType>::remove(Node<DataType>* tree, const DataType &item)
{
    Node<DataType> * curr =tree;
    Node<DataType> * parent = nullptr;
    while(curr!=nullptr)
    {
        if (curr->value==item)
        {
            if (curr->right==nullptr && curr->left ==nullptr) // the node is leaf node
            {
                if (parent==nullptr) // the node is also root
                {
                    root=nullptr;
                }
                else if (parent->left==curr)
                {
                    parent->left=nullptr;
                }
                else
                {
                    parent->right=nullptr;
                }
                length--;
                return true;
            }
            else if (curr->right==nullptr) // node with only left child
            {
                if (parent==nullptr) {root=curr->left;} //the node is also root
                else if (parent->left==curr) // if the node is a left child of parent node
                {
                    parent->left=curr->left; // assign left parent's pointer points to left value of the curr node
                }
                else // if the node is right child
                {
                    parent->right=curr->left; // assign right parent's pointer points to left value of curr node
                }
                length--;
                return true;
            }
            else if (curr->left==nullptr) // node with only right child
            {
                if (parent==nullptr) {root=curr->right;} //the node is also root
                else if (parent->left==curr)
                {
                    parent->left=curr->right;
                }
                else
                {
                    parent->right = curr->right;
                }
                length--;
                return true;
            }
            else // with 2 children
            {
                Node<DataType> * next = min(curr->right);
                DataType data = next->value; // store min value of right subtree in data variable
                remove(root,next->value); // recursively call remove function since the next node
                // might have one or no children
                curr->value=data; // assign the data to value of curr node
                return true;
            }
        }
        else if (curr->value>item) //search left
        {
            parent=curr;
            curr=curr->left;
        }
        else // search right
        {
            parent=curr;
            curr=curr->right;
        }
    }
    return false;
}


template<class DataType>
bool BinaryTree<DataType>::deleteItem(const DataType &item)
{
    return remove(root,item);
}

template<class DataType>
void BinaryTree<DataType>::traverse(Node<DataType> *node)
{
    if(node==nullptr)
    {return;}
    else
    {
        traverse(node->left);
        cout << (node->value) << endl;
        traverse(node->right);
    }
}
template<class DataType>
void BinaryTree<DataType>::print()
{
    traverse(root);
}