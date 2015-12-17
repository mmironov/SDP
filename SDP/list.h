//
//  list.hpp
//  SDP
//
//  Created by Miroslav Mironov on 12/10/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <iostream>
#include "item.h"

template <typename T>
class List {
    Item<T>* start;
    Item<T>* end;
    
    int _size;
public:
    List()
    {
        start = 0;
        end = 0;
        _size = 0;
    }
    
//    List(const List<T>& other);
    
    ~List()
    {
        Item<T>* p = start;
        
        while (p != 0)
        {
            Item<T>* q = p;
            p = p->next;
            delete q;
        }
    }
    
//    List<T>& operator=(const List<T>& other);
    
    void add(const T value)
    {
        Item<T>* newElem = new Item<T>();
        newElem->value = value;
        newElem->next = 0;
        
        if (start == 0)
        {
            start = newElem;
        }
        else
        {
            end->next = newElem;
        }
        
        end = newElem;
        
        ++_size;
    }
    
    void remove(int index)
    {
        if (index < 0 || index >= _size)
        {
            return;
        }
        
        if (index == 0)
        {
            Item<T>* p = start;
            start = start->next;
            delete p;
            p = 0;
            
            if (_size == 1)
            {
                end = 0;
            }
        }
        else
        {
            Item<T>* p = start;
            
            for(int i=0; i < index - 1; ++i)
            {
                p = p->next;
            }
            
            Item<T>* q = p->next;
            p->next = q->next;
            delete q;
            q = 0;
            
            if (index == _size - 1)
            {
                end = p;
            }
        }
        
        --_size;
        
        if (_size == 0)
        {
            start = 0;
            end = 0;
        }
    }
    
    T& get(int index)
    {
        Item<T>* p = start;
        
        for(int i=0; i < index; ++i)
        {
            p = p->next;
        }
        
        return p->value;
    }
    
    int size() const
    {
        return _size;
    }
    
    bool isEmpty()
    {
        return _size == 0;
    }
};

#endif /* list_h */
