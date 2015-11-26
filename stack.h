//
//  stack.h
//  SDP
//
//  Created by Miroslav Mironov on 10/22/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include "item.h"

template <typename T>
class Stack {
    Item<T>* _top;
    int _size;
public:
    Stack()
    {
        _top = 0;
        _size = 0;
    }
    
    void push(const T& value)
    {
        Item<T>* item = new Item<T>;
        item->value = value;
        
        item->next = _top;
        _top = item;
        ++_size;
    }
    
    T top()
    {
        return _top->value;
    }
   
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        
        Item<T>* oldTop = _top;
        
        _top = _top->next;
        
        delete oldTop;
        
        --_size;
    }
    
    int size() const
    {
        return _size;
    }
    
    bool isEmpty() const
    {
        return _top == 0;
    }
};

#endif /* stack_h */
