//
//  Header.h
//  SDP
//
//  Created by Miroslav Mironov on 1/7/16.
//  Copyright © 2016 Miroslav Mironov. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include "tree_item.h"
#include <iostream>
using namespace std;

template <typename T>
class Tree {
    TreeItem<T>* root;
    
    void del(TreeItem<T>*& node)
    {
        if (node)
        {
            del(node->left);
            del(node->right);
            
            delete node;
            node = 0;
        }
    }
    
    void insert(const T& value, TreeItem<T>*& node)
    {
        if (node)
        {
            if (value == node->value)
            {
                return;
            }
            
            if (value < node->value)
            {
                insert(value, node->left);
            }
            
            if (value > node->value)
            {
                insert(value, node->right);
            }
        }
        else
        {
            node = new TreeItem<T>;
            node->value = value;
            node->left = 0;
            node->right = 0;
        }
    }
    
    void remove(const T& value, TreeItem<T>*& node)
    {
        if (node)
        {
            if (value < node->value)
            {
                remove(value, node->left);
            }
            
            if (value > node->value)
            {
                remove(value, node->right);
            }
            
            if (value == node->value)
            {
                if (node->left && node->right)
                {
                    T max = findMax(node->left);
                    
                    node->value = max;
                    remove(max, node->left);
                    
                }
                else if (node->left)
                {
                    TreeItem<T>* toDel = node;
                    node = node->left;
                    delete toDel;
                    toDel = 0;
                }
                else
                {
                    TreeItem<T>* toDel = node;
                    node = node->right;
                    delete toDel;
                    toDel = 0;
                }
            }
        }
    }
    
    T findMax(TreeItem<T>*& root)
    {
        TreeItem<T>* item = root;
        
        while (item->right)
        {
            item = item->right;
        }
        
        return item->value;
    }
    
    void print(TreeItem<T>* node) const
    {
        if (node)
        {
            print(node->left);
            
            cout << node->value << " ";
            
            print(node->right);
        }
    }
public:
    Tree()
    {
        root = 0;
    }
    
//    Tree(const Tree<T>& other);
//    Tree& operator=(const Tree<T>& other);
    
    virtual ~Tree()
    {
        del(root);
    }
    
    void insert(const T& value)
    {
        insert(value, root);
    }
    
    void remove(const T& value)
    {
        remove(value, root);
    }
    
    void print() const
    {
        print(root);
    }
};

#endif /* Header_h */
