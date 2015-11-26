//
//  sorting.h
//  SDP
//
//  Created by Miroslav Mironov on 11/17/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#ifndef sorting_h
#define sorting_h

#include <stdio.h>

void quickSort(int a[], int n);

int kthBiggest(int a[], int n, int k);

//returns the index of element
//returns -index if the element is not in the array
//index is the index, at which the element should be
//inserted in a sorted sequence
int binarySearch(int a[], int n, int element);

#endif /* sorting_h */
