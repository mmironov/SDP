//
//  dynamic_array.h
//  SDP
//
//  Created by Miroslav Mironov on 10/8/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef dynamic_array_h
#define dynamic_array_h

template <typename T>
class DynamicArray {
    T* elements;
    int _size;
    int _capacity;
    
    void extend()
    {
        _capacity = _capacity * 2;
        
        //allocating memory
        T* copy = new T[_capacity];
        
        //copying memory
        for(int i=0; i < _size; ++i)
        {
            copy[i] = elements[i];
        }
        
        //deleting memory
        delete [] elements;
        
        elements = copy;
    }
public:
    DynamicArray()
    {
        _size = 0;
        _capacity = 4;
        
        elements = new T[_capacity];
    }
    
//    DynamicArray(const DynamicArray& other);
//    ~DynamicArray();
//    DynamicArray& operator=(const DynamicArray& other);
    
    //adds at the end
    void add(const T& e)
    {
        if (_size >= _capacity)
        {
            extend();
        }
        
        elements[_size] = e;
        ++_size;
    }
    
    //adds at index index
    void insertAt(const T& e, int index)
    {
        if (index < 0 || index > _size)
        {
            return;
        }
        
        if (_size >= _capacity)
        {
            extend();
        }
        
        for(int i = _size; i > index; --i)
        {
            elements[i] = elements[i-1];
        }
        
        elements[index] = e;
        ++_size;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= _size)
        {
            return;
        }
        
        for(int i = index; i < _size - 1; ++i)
        {
            elements[i] = elements[i+1];
        }
        
        --_size;
    }
    
    void removeLast()
    {
        removeAt(_size - 1);
    }
    
    T& get(int index)
    {
        return elements[index];
    }
    
    //Uses == for comparison
    int indexOf(const T& e)
    {
        for(int i=0; i < _size; ++i)
        {
            if (elements[i] == e)
            {
                return i;
            }
        }
        
        return -1;
    }
    
    int size() const
    {
        return _size;
    }
};

#endif /* dynamic_array_h */
