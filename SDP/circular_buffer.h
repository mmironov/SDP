//
//  circular_buffer.h
//  SDP
//
//  Created by Miroslav Mironov on 11/5/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef circular_buffer_h
#define circular_buffer_h

template <typename T>
class Buffer {
    T* buffer;
    int capacity;
    int _size;
    
    int front;
    int rear;
public:
    Buffer(int capacity)
    {
        this->capacity = capacity;
        buffer = new T[capacity];
        
        front = 0;
        rear = 0;
        
        _size = 0;
    }
    
    bool isEmpty()
    {
        return _size == 0;
    }
    
    bool isFull()
    {
        return _size == capacity;
    }
    
    bool enqueue(const T& value)
    {
        if ( isFull() )
        {
            return false;
        }
        
        buffer[rear] = value;
        
        rear = (rear + 1) % capacity;
        
        ++_size;
        
        return true;
    }
    
    bool dequeue()
    {
        if ( isEmpty() )
        {
            return false;
        }
        
        front = (front + 1) % capacity;
        
        --_size;
        
        return true;
    }
    
    T peek()
    {
        return buffer[front];
    }
    
    int size() const
    {
        return _size;
    }
};

#endif /* circular_buffer_h */
