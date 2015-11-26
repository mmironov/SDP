//
//  queue.h
//  SDP
//
//  Created by Miroslav Mironov on 10/7/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef queue_h
#define queue_h

template <typename T>
class Queue {

public:
    void enqueue(const T& value);
    void dequeue();
    
    bool isEmpty();
    
    int size();
};

#endif /* queue_h */