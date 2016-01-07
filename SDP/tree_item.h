//
//  TreeItem.hpp
//  SDP
//
//  Created by Miroslav Mironov on 1/7/16.
//  Copyright © 2016 Miroslav Mironov. All rights reserved.
//

#ifndef TreeItem_h
#define TreeItem_h

#include <stdio.h>

template <typename T>
struct TreeItem {
    T value;
    TreeItem<T>* left;
    TreeItem<T>* right;
};

#endif /* TreeItem_h */
