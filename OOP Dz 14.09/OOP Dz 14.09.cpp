// OOP Dz 14.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>	
#include "DynamicArray.h"
using namespace std;	
void main()
{
	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	DynamicArray b = a; // copy constructor
	b.Output();
	//1
	DynamicArray rez = a+10;
	cout << "+10 elements in array: " << endl;	
	rez.Output();
	//2
	DynamicArray rez1 = a - 2;
	cout << "Size - 2: " << endl;		
	rez1.Output();
	//3
	DynamicArray rez2 = a*2;	
	cout << "a * 2: " << endl;	
	rez2.Output();	
	//4
	DynamicArray rez3 = a - b;	
	cout << "a - b" << endl;	
	rez3.Output();
	// 5
	DynamicArray rez4 = a + b;	
	cout << "a + b" << endl;	
	rez4.Output();	
	//6
	DynamicArray rezPlus = ++rez; 
	cout << "Array after ++: " << endl;
	rezPlus.Output();
	cout << endl;	
	//7
	DynamicArray rezMibus = --rez; 
	cout << "Array after --: " << endl;
	rezMibus.Output();

	/*
	реилизовать следующие перегрузки:

	DynamicArray rez = a+10 ; // увеличиваем кол-во элементов на 10
	 rez = a-2; // удаляем последние 2 элемента, если размер >2
	 rez = a*2;// значение каждого элемента массива умножаем на 2, возвращаем новый массив!

	 rez = a-b; // разность массивов
	 rez=a+b;  // конкатенация массивов
	 ++rez;  // увеличиваем количество элементов на 1(значение 0).
	 --rez;  // ум. количество элементов на 1, удаляем последний элемент
	*/

	system("pause");
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
