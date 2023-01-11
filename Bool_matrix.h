#pragma once
#include "Header.h"



class BoolMatrix
{
	BooolVector* BM;

	int m, n; 		//m -- кол-во булевых векторов, т.е кол-во строк матрицы
					   //n -- длина булева вектора, т.е. кол-во столбцов
	int Max(char** s, int m);

public:
	int getn() {return n;}

	BoolMatrix();
	BoolMatrix(int, int);
	BoolMatrix(char**, int);
	BoolMatrix(const BoolMatrix&);
	~BoolMatrix();
	BoolMatrix& operator= (const BoolMatrix&);

	void Scan(int, int);
	void Print();

	BooolVector& operator[] (int);
	bool operator== (BoolMatrix&); //можно аргумент взять BoolMatrix
	bool operator!= (BoolMatrix&);

	BoolMatrix SetUp1(int i, int j);	//установить 1 в i-й строке, j-м столбце
	BoolMatrix SetUp0(int i, int j);	//установить 0 (сбросить в 0) в i-й строке, j-м столбце
	BoolMatrix Invert(int i, int j);	//инвертировать эл-т в i-й строке, j-м столбце

	BoolMatrix SetUp1(int i, int j, int kol);	//установить kol эл-тов в i-й строке, j-м столбце
	BoolMatrix SetUp0(int i, int j, int kol);	//сбросить kol эл-тов в i-й строке, j-м столбце
	BoolMatrix Invert(int i, int j, int kol);	//инвертировать kol эл-тов в i-й строке, j-м столбце

	BoolMatrix ShiftLeft(int, int);	//сдвиг влево эл-тов i-й строки на k, создается новая
	BoolMatrix& ShiftLeftEq(int, int);	//сдвиг влево эл-тов i-й строки на k, изменяется *this

	BoolMatrix ShiftRight(int, int);	//сдвиг вправо эл-тов i-й строки на k, создается новая
	BoolMatrix& ShiftRightEq(int, int);	//сдвиг вправо эл-тов i-й строки на k, изменяется *this

	BoolMatrix operator~();  //инверсия всей матрицы

	BoolMatrix operator & (BoolMatrix&);	//построчная конъюнкция 2-х матриц, создается новая
	BoolMatrix& operator &= (BoolMatrix&);	//построчная конъюнкция 2-х матриц, изменяется *this

	BoolMatrix operator | (BoolMatrix&);	//построчная дизъюнкция 2-х матриц, создается новая
	BoolMatrix& operator |= (BoolMatrix&);	//построчная дизъюнкция 2-х матриц, изменяется *this

	BoolMatrix operator ^ (BoolMatrix&);	//построчная XOR 2-х матриц, создается новая
	BoolMatrix& operator ^= (BoolMatrix&);	//построчная XOR 2-х матриц, изменяется *this

	BooolVector Conj();  //конъюнкция всех строк матрицы
	BooolVector Disj();  //дизъюнкция всех строк матрицы
	BooolVector Xor();  //XOR всех строк матрицы

	friend ostream& operator<<(ostream& r, BoolMatrix& X);
	friend istream& operator>>(istream& r, BoolMatrix& X);

};


