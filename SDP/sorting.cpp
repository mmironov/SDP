//
//  sorting.cpp
//  SDP
//
//  Created by Miroslav Mironov on 11/17/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#include "sorting.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void quickSortHelper(int a[], int from, int to)
{
    srand((int)time(0));
    int n = rand();
    
    int pivotIndex = n % (to - from + 1) + from;
    int pivot = a[pivotIndex];
    
    int lt = from;
    int gt = to;
    int i = from;
    
    while (i <= gt)
    {
        
        if (a[i] < pivot)
        {
            int temp = a[lt];
            a[lt] = a[i];
            a[i] = temp;
            ++i;
            ++lt;
        }
        else if (a[i] > pivot)
        {
            int temp = a[gt];
            a[gt] = a[i];
            a[i] = temp;
            --gt;
        }
        else if (a[i] == pivot)
        {
            ++i;
        }
    }
    
    if (lt - 1 > from)
    {
        quickSortHelper(a, from, lt - 1);
    }
    
    if (gt + 1 < to)
    {
        quickSortHelper(a, gt + 1, to);
    }
}

void quickSort(int a[], int n)
{
    int from = 0;
    int to = n - 1;
    
    quickSortHelper(a, from, to);
}

int kthBiggestHelper(int a[], int k, int from, int to)
{
    srand((int)time(0));
    int n = rand();
    
    int pivotIndex = n % (to - from + 1) + from;
    int pivot = a[pivotIndex];
    
    int lt = from;
    int gt = to;
    int i = from;
    
    while (i <= gt)
    {
        
        if (a[i] < pivot)
        {
            int temp = a[lt];
            a[lt] = a[i];
            a[i] = temp;
            ++i;
            ++lt;
        }
        else if (a[i] > pivot)
        {
            int temp = a[gt];
            a[gt] = a[i];
            a[i] = temp;
            --gt;
        }
        else if (a[i] == pivot)
        {
            ++i;
        }
    }
    
    if (k < lt)
    {
        return kthBiggestHelper(a, k, from, lt - 1);
    }
    
    if (k > gt)
    {
        return kthBiggestHelper(a, k, gt + 1, to);
    }
    
    return a[k];
}

int kthBiggest(int a[], int n, int k)
{
    return kthBiggestHelper(a, k, 0, n-1);
}

int binarySearchHelper(int a[], int from, int to, int element)
{
    int mid = (from + to) / 2;
    
    if (a[mid] < element)
    {
        if (mid + 1 <= to)
        {
            return binarySearchHelper(a, mid+1, to, element);
        }
        else
        {
            return -(mid + 1);
        }
    }
    
    if (a[mid] > element)
    {
        if (from <= mid - 1)
        {
            return binarySearchHelper(a, from, mid-1, element);
        }
        else
        {
            return -mid;
        }
    }
    
    int index = mid;
    
    while (index > 0 && a[index] == element)
    {
        --index;
    }
    
    return index + 1;
}

int binarySearch(int a[], int n, int element)
{
    return binarySearchHelper(a, 0, n-1, element);
}

void findAdditivesHelper(int a[], int from, int to, int sum,
                  int& indX, int& indY)
{
    if (from >= to)
    {
        indX = -1;
        indY = -1;
        return;
    }
    
    int x = a[from];
    int y = sum - x;
    int index = binarySearchHelper(a, from+1, to, y);
    
    if (index < 0)
    {
        findAdditivesHelper(a, from+1, to, sum, indX, indY);
    }
    else
    {
        indX = from;
        indY = index;
    }
}

void findAdditivesInSorted(int a[], int n, int sum,
                   int& indX, int& indY)
{
    findAdditivesHelper(a, 0, n-1, sum, indX, indY);
}