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
//    void insertAt(const T& e, int index);
//    
//    void removeAt(int index);
    
    T& get(int index)
    {
        return elements[index];
    }
    
//    int indexOf(const T& e);
    
    int size() const
    {
        return _size;
    }
};

#endif /* dynamic_array_h */
