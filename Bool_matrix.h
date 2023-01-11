#pragma once
#include "Header.h"



class BoolMatrix
{
	BooolVector* BM;

	int m, n; 		//m -- ���-�� ������� ��������, �.� ���-�� ����� �������
					   //n -- ����� ������ �������, �.�. ���-�� ��������
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
	bool operator== (BoolMatrix&); //����� �������� ����� BoolMatrix
	bool operator!= (BoolMatrix&);

	BoolMatrix SetUp1(int i, int j);	//���������� 1 � i-� ������, j-� �������
	BoolMatrix SetUp0(int i, int j);	//���������� 0 (�������� � 0) � i-� ������, j-� �������
	BoolMatrix Invert(int i, int j);	//������������� ��-� � i-� ������, j-� �������

	BoolMatrix SetUp1(int i, int j, int kol);	//���������� kol ��-��� � i-� ������, j-� �������
	BoolMatrix SetUp0(int i, int j, int kol);	//�������� kol ��-��� � i-� ������, j-� �������
	BoolMatrix Invert(int i, int j, int kol);	//������������� kol ��-��� � i-� ������, j-� �������

	BoolMatrix ShiftLeft(int, int);	//����� ����� ��-��� i-� ������ �� k, ��������� �����
	BoolMatrix& ShiftLeftEq(int, int);	//����� ����� ��-��� i-� ������ �� k, ���������� *this

	BoolMatrix ShiftRight(int, int);	//����� ������ ��-��� i-� ������ �� k, ��������� �����
	BoolMatrix& ShiftRightEq(int, int);	//����� ������ ��-��� i-� ������ �� k, ���������� *this

	BoolMatrix operator~();  //�������� ���� �������

	BoolMatrix operator & (BoolMatrix&);	//���������� ���������� 2-� ������, ��������� �����
	BoolMatrix& operator &= (BoolMatrix&);	//���������� ���������� 2-� ������, ���������� *this

	BoolMatrix operator | (BoolMatrix&);	//���������� ���������� 2-� ������, ��������� �����
	BoolMatrix& operator |= (BoolMatrix&);	//���������� ���������� 2-� ������, ���������� *this

	BoolMatrix operator ^ (BoolMatrix&);	//���������� XOR 2-� ������, ��������� �����
	BoolMatrix& operator ^= (BoolMatrix&);	//���������� XOR 2-� ������, ���������� *this

	BooolVector Conj();  //���������� ���� ����� �������
	BooolVector Disj();  //���������� ���� ����� �������
	BooolVector Xor();  //XOR ���� ����� �������

	friend ostream& operator<<(ostream& r, BoolMatrix& X);
	friend istream& operator>>(istream& r, BoolMatrix& X);

};


