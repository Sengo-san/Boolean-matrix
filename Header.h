//#pragma once
//подключаем нужные библиотеки

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



using namespace std;
typedef unsigned char UC;

class BooolVector
{
	UC* bv;
	int n, m;		//n - длина булева вектора
			   //m - кол-во эл-тов в массиве bv
			   //m=n/8 если n%8=0;  m=n/8+1, если n%8!=0 
	int Input(const char*, int, int, int); 		//формирование эл-та массива bv
	void Output(int, int);			//вывод одного эл-та массива bv

public:
	BooolVector();
	BooolVector(int N); 				//N - длина булева вектора
	BooolVector(const char*);
	BooolVector(const char* s, int N); 		//N!=strlen(s)
	BooolVector(const BooolVector&);
	~BooolVector();
	BooolVector& operator= (const BooolVector&);

	void Scan(int);
	void Print();

	int Weight();   //вес булева вектора
	BooolVector operator~ ();			//инвертируется *this
	UC operator[] (int);

	bool operator== (BooolVector&);
	bool operator!= (BooolVector&);
	bool operator< (BooolVector&);     //x<y <-> x[i]<=y[i], для всех i
	bool operator> (BooolVector&);     //x>y <-> x[i]>=y[i], для всех i
	//для двух булевых векторов возможны след. отношения:
	//а)x==y, б)x<y, в)x>y, г)x и y - несравнимы 
	//(б, в, г -- частные случаи x!\=y)

	BooolVector& operator&= (BooolVector&);  		//*this=(*this)&y
	BooolVector  operator& (BooolVector&); 		//x=(*this)&y

	BooolVector& operator|= (BooolVector&);		//*this=(*this)|y
	BooolVector  operator| (BooolVector&);			//x=(*this)|y

	BooolVector& operator^= (BooolVector&);		//*this=(*this)^y
	BooolVector  operator^ (BooolVector&);			//x=(*this)^y

	BooolVector operator<< (int);
	BooolVector& operator<<= (int);
	BooolVector operator>> (int);
	BooolVector& operator>>= (int);

	BooolVector SetUp1(int);	//установить 1 в заданную позицию
	BooolVector SetUp0(int);	//установить 0 в заданную позицию 
						   //(т.е. сбросить компоненту)
	BooolVector Invert(int);  	//инвертировать заданную позицию

	BooolVector SetUp1(int k, int p); //установить k единиц начиная с позиции p
	BooolVector SetUp0(int k, int p);  //установить k нулей начиная с позиции p 
	BooolVector Invert(int k, int p);   //инвертировать k позиций, начиная с p

	friend ostream& operator<< (ostream& r, BooolVector& x);
	friend istream& operator>> (istream& r, BooolVector& x);
};
