#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; // указатель на динам. массив
	int size;  // размер массива 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	DynamicArray operator+(int size);	
	DynamicArray operator-(int TwoElem);	
	DynamicArray operator*(int number);	
	DynamicArray operator - (DynamicArray b);	
	DynamicArray operator + (DynamicArray b);	
	DynamicArray& operator++();
	DynamicArray& operator--();
	
	~DynamicArray();	
	void Input();// rand
	void Output() const;// вывод на консоль
	int* GetPointer() const;
	int GetSize() const;


};
