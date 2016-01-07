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
#include "list.h"
#include "map.h"
#include "tree.h"
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

void testList()
{
    List<int> l;
    l.add(5);
    l.add(20);
    l.add(30);
    
    l.remove(1);
    l.remove(0);
    
    for(int i=0; i < l.size(); ++i)
    {
        cout << l.get(i) << " ";
    }
    cout << endl;
}

class Hash : public HashFunction<const char*> {
public:
    int hash(const char* value)
    {
        int multiplier = 1;
        int change = (int)strlen(value);
        
        int hashValue = 0;
        
        for(int i=0; i < strlen(value); ++i)
        {
            int toAdd = value[i];
            toAdd = toAdd * i * multiplier;
            hashValue += toAdd;
            
            multiplier += change;
        }
        
        return abs(hashValue);
    }
};

class IntHash : public HashFunction<int> {
public:
    int hash(int value)
    {
        return abs(value);
    }
};

int countDifferent(int numbers[], int length)
{
    HashMap<int, int> map;
    
    HashFunction<int>* function = new IntHash;
//
    map.setHashFunction(function);
    
    for(int i=0; i < length; ++i)
    {
        map.insert(numbers[i], 0);
    }
    
    delete function;
    
    return map.size();
}

void testMap()
{
    HashMap<const char*, const char*> map;
    map.setHashFunction(new Hash());
    
    map.insert("Miroslav", "088");
    map.insert("Nikolay", "3333");
    map.insert("Mariya", "777");
    map.insert("Georgi", "55555");
    map.insert("Georgi", "222");
    map.remove("Georgi");
    map.insert("Mariya", "123");
    
    cout << "Size: " << map.size() << endl;
    
    Pair<const char*, const char*>* found;
    found = map.find("Mariya");
    
    if (found)
    {
        cout << found->value << endl;
    }
    else
    {
        cout << "Key is not in the map\n";
    }
    
    int numbers[] = {2, 7, -1, 2, 3, 7, 2, 1};
    
    int different = countDifferent(numbers, 8);
    cout << "Different: " << different << endl;
}

void testTrees() {
    Tree<int> intTree;
    
    intTree.insert(5);
    intTree.insert(10);
    intTree.insert(15);
    intTree.insert(7);
    intTree.insert(1);
    intTree.insert(5);
    
    intTree.remove(7);
    intTree.remove(1);
    
    intTree.print();
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
//    testDynamicArray();
//    testStack();
//    testCircularBuffer();
//    testQuickSort();
//    testBinarySearch();
//    testFindAdditives();
//    testList();
//    testMap();
    testTrees();
    
    return 0;
}
