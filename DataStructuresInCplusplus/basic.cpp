//
//  main.cpp
//  DataStructuresInC++
//
//  Created by Atefe Mosayebi on 2/16/19.
//  Copyright © 2019 Atefe Mosayebi. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

// call by address
void swap (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// call by reference
void swap2 (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// pass array as parameters
// arr is a POINTER to actuall array, so this function can modify the actual array from here.
void func(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " --- ";
    }
    cout << endl;
}

// returning array
int* func2(int size) {
    int *pointer;
    pointer = new int[10];  // array will be cretaed in heap and its reference will be assign to a pointer
    return pointer;
}

// struct
struct Rectangle {
    int length;
    int breadth;
};

// passing struct with value
int area(struct Rectangle rec) {
    return rec.length * rec.length;
}

// passing struct with reference
void changeLengthByReference(struct Rectangle &p, int newLength) {
    p.length = newLength;
}

// passing struct with address
void changeLength(struct Rectangle *p, int newLength) {
    p->length = newLength;
}


int main(int argc, const char * argv[]) {
    
    struct Rectangle r = {4, 5};
    cout << "Area of structure is: " << r.breadth * r.length << endl;
    
    struct Card {
        int face;
        int shape;
        int color;
    };
    
    // array of structs
    struct Card deck[52];
    
    // pointers to a variable in stack
    int a = 10;
    // declaration
    int *p;
    // initialization
    p = &a;
    
    // derefrencing
    cout << "data of a: " << *p << endl;
    cout << "address of a: " << p << endl << endl;
    
    // pointer takes as muc as An INTEGER in any compiler.
    // pointers to a variable in heap
    int *pHeap;
    // malloc allocates heap memory in C
    pHeap = (int *)malloc(5 * sizeof(int));
    // new operator allocates heap memory in C++
    pHeap = new int[5];
    
    // creating alias/reference for variables
    int aVariable = 10;
    // refrence is an alias for aVariable. has the same address.
    int &reference = aVariable;
    
    // pointer to structure
    struct Rectangle *pointerToStruct = &r;
    // accessing a struct data using its pointer
    (*pointerToStruct).breadth = 15;    // same as r.breath = 15;
    pointerToStruct->breadth = 15;      // same as the above line
    
    struct Rectangle *pointerToStructInHeap = new struct Rectangle;
    pointerToStructInHeap->breadth = 20;
    pointerToStructInHeap->length = 18;
    
    // functions
    int val1 = 100;
    int val2 = 200;
    
    // pass by address
    swap(&val1, &val2);
    cout << "val1: " << val1 << " , " << "val2: " << val2 << endl;
    
    // pass by reference
    swap2(val1, val2);
    cout << "val1: " << val1 << " , " << "val2: " << val2 << endl;
    
    // Array as parameter
    // ARRAYS ARE ALWAYS PASS BY ADDRESS.
    int array[5] = {1, 2, 3, 4, 5};
    func(array, 5);
    
    // structure as parameter -- pass by VALUE to function
    cout << "area is " << area(r) << endl;
    
    // structure as parameter -- pass by REFERENCE to function
    changeLengthByReference(r, 200);
    cout << "new length is " << r.length << endl;
    
    // structure as parameter -- pass by ADDRESS to function
    changeLength(&r, 100);
    cout << "new length is " << r.length << endl;
    
    return 0;
}
