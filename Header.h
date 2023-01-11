//#pragma once
//���������� ������ ����������

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



using namespace std;
typedef unsigned char UC;

class BooolVector
{
	UC* bv;
	int n, m;		//n - ����� ������ �������
			   //m - ���-�� ��-��� � ������� bv
			   //m=n/8 ���� n%8=0;  m=n/8+1, ���� n%8!=0 
	int Input(const char*, int, int, int); 		//������������ ��-�� ������� bv
	void Output(int, int);			//����� ������ ��-�� ������� bv

public:
	BooolVector();
	BooolVector(int N); 				//N - ����� ������ �������
	BooolVector(const char*);
	BooolVector(const char* s, int N); 		//N!=strlen(s)
	BooolVector(const BooolVector&);
	~BooolVector();
	BooolVector& operator= (const BooolVector&);

	void Scan(int);
	void Print();

	int Weight();   //��� ������ �������
	BooolVector operator~ ();			//������������� *this
	UC operator[] (int);

	bool operator== (BooolVector&);
	bool operator!= (BooolVector&);
	bool operator< (BooolVector&);     //x<y <-> x[i]<=y[i], ��� ���� i
	bool operator> (BooolVector&);     //x>y <-> x[i]>=y[i], ��� ���� i
	//��� ���� ������� �������� �������� ����. ���������:
	//�)x==y, �)x<y, �)x>y, �)x � y - ���������� 
	//(�, �, � -- ������� ������ x!\=y)

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

	BooolVector SetUp1(int);	//���������� 1 � �������� �������
	BooolVector SetUp0(int);	//���������� 0 � �������� ������� 
						   //(�.�. �������� ����������)
	BooolVector Invert(int);  	//������������� �������� �������

	BooolVector SetUp1(int k, int p); //���������� k ������ ������� � ������� p
	BooolVector SetUp0(int k, int p);  //���������� k ����� ������� � ������� p 
	BooolVector Invert(int k, int p);   //������������� k �������, ������� � p

	friend ostream& operator<< (ostream& r, BooolVector& x);
	friend istream& operator>> (istream& r, BooolVector& x);
};
