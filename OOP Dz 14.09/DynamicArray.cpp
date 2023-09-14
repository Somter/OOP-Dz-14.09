#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];	
	for (int i = 0; i < size; i++)		
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray DynamicArray::operator+(int size)		
{
	DynamicArray rez;	
	rez.size = this->size + size;			
	rez.ptr = new int[rez.size];					
	for (int i = 0; i < this->size; i++)						 
	{
		rez.ptr[i] = ptr[i];				
	}				
	for (int i = this->size; i < rez.size; i++)	
	{	
		rez.ptr[i] = 0;		
	}
	return rez;		
}
DynamicArray DynamicArray::operator-(int TwoElem)
{
	DynamicArray rez2;	
	int count = 0;	

	for (int i = 0; i < this->size; i++) {
		count++;
	}	
	if (count <= TwoElem) {
		return rez2;	
	}

	rez2.size = this->size - TwoElem;	
	rez2.ptr = new int[rez2.size];	

	for (int i = 0; i < rez2.size; i++)	
	{
		rez2.ptr[i] = ptr[i];	
	}	
	return rez2;	
}
DynamicArray DynamicArray::operator*(int number)
{
	DynamicArray rez3;	
	rez3.size = this->size;	
	rez3.ptr = new int [rez3.size];	
	for (int i = 0; i < this->size; i++) 
	{
		rez3.ptr[i] = ptr[i]*2;	
	}
	return rez3;	
}

DynamicArray DynamicArray::operator-(DynamicArray b)
{
	DynamicArray rez4;
	int FirstArr = 0;
	int SecondArr = 0;

	for (int i = 0; i < size; i++)
	{
		FirstArr++;
	}
	for (int i = 0; i < b.size; i++)
	{
		SecondArr++;
	}

	if (FirstArr > SecondArr)
	{
		cout << "a > b\n";
		rez4.size = size - 2;
		rez4.ptr = new int[rez4.size];
		for (int i = 0; i < rez4.size; i++)
		{
			rez4.ptr[i] = ptr[i];
		}
	}
	else if (SecondArr > FirstArr)
	{
		cout << "a < b\n";
		rez4.size = b.size - 2;	
		rez4.ptr = new int[rez4.size];
		for (int i = 0; i < rez4.size; i++)
		{
			rez4.ptr[i] = b.ptr[i];	
		}	
	}
	else if (SecondArr == FirstArr) 
	{
		cout << "a == b\n";	
		return DynamicArray(0);	
	}
	return rez4;	
}

DynamicArray DynamicArray::operator+(DynamicArray b)
{
	DynamicArray rez5;
	rez5.size = size + b.size;		
	rez5.ptr = new int [rez5.size];	
	cout << "a: ";
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\nb: ";
	for (int i = 0; i < b.size; i++)
	{
		cout << b.ptr[i] << "\t";
	}
	cout << "\na + b: ";
	for (int i = 0; i < size; i++)
	{
		rez5.ptr[i] = ptr[i];
	}
	for (int i = 0; i < b.size; i++)
	{
		rez5.ptr[size + i] = b.ptr[i];
	}	
	return rez5;	
}

DynamicArray& DynamicArray::operator++()
{	
	if (size == 0)
	{
		size = 1;
		ptr = new int[1];
		ptr[0] = 0;
	}
	else
	{
		int* newPtr = new int[size + 1];
		for (int i = 0; i < size; i++)
		{
			newPtr[i] = ptr[i];
		}
		newPtr[size] = 0;
		delete[] ptr;
		ptr = newPtr;
		size++;
	}

	return *this; 	
}

DynamicArray& DynamicArray::operator--()
{
	if (size > 0)
	{
		// Создаем новый массив с уменьшенным размером
		int* newPtr = new int[size - 1];

		// Копируем элементы из старого массива, исключая последний элемент
		for (int i = 0; i < size - 1; i++)
		{
			newPtr[i] = ptr[i];
		}

		// Освобождаем старый массив
		delete[] ptr;

		// Обновляем указатель и размер
		ptr = newPtr;
		size--;
	}

	return *this; 
}

//DynamicArray::~DynamicArray()
//{	
//	cout << "Destruct\n";	
//	if (ptr != nullptr) {
//		delete[] ptr;
//	}	
//}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)	
	{
		ptr[i] = rand() % 20;	
	}	
}
void DynamicArray::Output()	
{
	for (int i = 0; i < size; i++)	
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer()
{
	return ptr;
}
int DynamicArray::GetSize()	
{
	return size;	
}	