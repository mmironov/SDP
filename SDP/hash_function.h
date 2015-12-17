//
//  HashFunction.h
//  SDP
//
//  Created by Miroslav Mironov on 12/10/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef HashFunction_h
#define HashFunction_h

template <typename T>
class HashFunction {
public:
    virtual int hash(T value) = 0;
};

#endif /* HashFunction_h */
