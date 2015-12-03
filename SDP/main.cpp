//
//  main.cpp
//  SDP
//
//  Created by Miroslav Mironov on 10/7/15.
//  Copyright © 2015 Miroslav Mironov. All rights reserved.
//

#include <iostream>
#include "dynamic_array.h"
#include "stack.h"
#include "circular_buffer.h"
#include "sorting.h"
using namespace std;

template <typename T>
void print(DynamicArray<T>& list)
{
    for(int i=0; i < list.size(); ++i)
    {
        cout << list.get(i) << " ";
    }
    
    cout << endl;
}

template <typename T>
void printBuffer(Buffer<T> buffer)
{
    int size = buffer.size();
    
    for(int i=0; i < size; ++i)
    {
        T elem = buffer.peek();
        
        cout << elem << " ";
        
        buffer.dequeue();
        buffer.enqueue(elem);
    }
}

int solveJosephus(Buffer<int> circle, int k)
{
    while (circle.size() > 1)
    {
        for(int i=0; i < k-1; ++i)
        {
            int value = circle.peek();
            circle.dequeue();
            circle.enqueue(value);
        }
        
        circle.dequeue();
    }
    
    return circle.peek();
}

void testCircularBuffer()
{
    Buffer<int> buf(10);
    
    for(int i=0; i < 10; ++i)
    {
        buf.enqueue(i);
    }
    
    printBuffer(buf);
    
    int left = solveJosephus(buf, 5);
    cout << endl << "Left: " << left << endl;
    
    cout << endl;
}

void testDynamicArray()
{
    char characters[10] = {'A', 'B', 'C'};
    
    for(char i = 0; i < 10; ++i)
    {
        characters[i] = 'A' + i;
    }
    
    for(char i = 0; i < 10; ++i)
    {
        cout << characters[i] << " ";
    }
    
    cout << endl;
    
    DynamicArray<char> list;
    
    list.add('a');
    list.add('b');
    list.add('c');
    
    list.insertAt('X', 1);
    list.insertAt('Y', 10);
    list.insertAt('_', 0);
    
    print(list);
    
    char c = 'X';
    
    int indexOfChar = list.indexOf(c);
    
    cout << "Index of " << c << ": " << indexOfChar;
    cout << endl;
    
    cout << "After removing some elements.....\n";
    
    list.removeLast();
    
    list.removeAt(2);
    
    print(list);
    
    indexOfChar = list.indexOf(c);
    
    cout << "Index of " << c << ": " << indexOfChar;
    cout << endl;
}

void testStack()
{
    Stack<int> stack;
    
    int n = 10;
    
    for(int i = 0; i < n; ++i)
    {
        stack.push(i*i);
        cout << stack.top() << " ";
    }
    
    cout << endl;
    cout << "Popping all elements...\n";
    
    while (!stack.isEmpty())
    {
        int top = stack.top();
        cout << top << " ";
        stack.pop();
    }
    
    cout << endl;
}

// (5+6)
// ((1-9)/3)
// ((((2+8)*4)-7)*(2+3))
int evaluate(const char* expr)
{
    return 0;
}

template <typename T>
void println(T a[], int size)
{
    cout << "[";
    
    for(int i=0; i < size; ++i)
    {
        cout << a[i];
        
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    
    cout << "]\n";
}

void initialize(int a[], int n)
{
    srand((int)(time(0)));
    int max = 100;
    
    for(int i=0; i < n; ++i)
    {
        a[i] = rand() % max;
    }
}

void testQuickSort()
{
    const int SIZE = 10;
    int a[SIZE];
    
    initialize(a, SIZE);
    
    println(a, SIZE);
    
    quickSort(a, SIZE);
    
    println(a, SIZE);
    
    int k = 5;
    
    cout << k << "th biggest: " << kthBiggest(a, SIZE, k) << endl;
}

void testBinarySearch()
{
    const int SIZE = 10;
    int a[] = {2, 14, -1, -5, 7, 20, 8, 7, 11, 15};
    
    println(a, SIZE);
    
    quickSort(a, SIZE);
    
    println(a, SIZE);
    
    int element = 7;
    int index = binarySearch(a, SIZE, element);
    
    cout << "Index of " << element << ": " << index << endl;
}

void testFindAdditives()
{
    int numbers[] = {7, -1, 8, 3, 2, 5, 5, 1};
    int numbersSize = 8;
    
    quickSort(numbers, numbersSize);
    
    int sum = 14;
    int indX = 0;
    int indY = 0;
    findAdditivesInSorted(numbers, numbersSize, sum, indX, indY);
    
    if (indX > -1)
    {
        cout << sum << " = " << numbers[indX]
        << " + " << numbers[indY] << endl;
        
        cout << "Indeces: " << indX << ", " << indY;
        cout << endl;
    }
    else
    {
        cout << "No additives for " << sum << ".\n";
    }
}

int main(int argc, const char * argv[]) {
    
//    testDynamicArray();
//    testStack();
//    testCircularBuffer();
//    testQuickSort();
//    testBinarySearch();
    testFindAdditives();
    
    return 0;
}
