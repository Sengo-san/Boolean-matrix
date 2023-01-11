#include <iostream>
#include "Header.h"
#include "Bool_matrix.h"

int main()
{
	cout << "\t1)" << endl;

	BoolMatrix B1(4, 20);
	cout << "B1: "<<endl << B1<<endl;
	

	cout << endl << endl << "\t2)" << endl;
	B1.Invert(0, 10, 8);
	B1.SetUp1(1, 14, 6);
	B1.SetUp1(2, 8, 6);
	for (int i = 1; i < B1.getn(); i += 2)
		B1.SetUp1(3, i);
	cout << "B1: " << endl << B1 << endl;




	
	cout << endl << endl << "\t3)" << endl;

	BoolMatrix B2(B1);
	cout << "B2: " << endl << B2 << endl;



	cout << endl << endl << "\t4)" << endl;
	if (B1 == B2) cout << "B1==B2" << endl;
	else cout << "smth goes wrong"<<endl;



	cout << endl << endl << "\t5)" << endl;
	B2.ShiftRightEq(0, 6);
	B2.ShiftLeftEq(2, 6);
	B2.SetUp0(1, 16);
	B2.SetUp0(1, 18);
	//cout << endl << B2.getn() << endl;
	for (int i = 0; i < B2.getn(); i = i + 2)

	B2[3].Invert(i);


	cout << "B2: " << endl << B2 << endl;




	cout << endl << endl << "\t6)" << endl;
	BoolMatrix B3;
	cin >> B3;
	cout << "B3: " << endl<<B3 << endl;
	if (B2 != B1) cout << "B2!=B3" << endl;
	else cout << "smth goes wrong" << endl;






	cout << endl << endl << "\t7)" << endl;//7(B4, не  B3!!!!)
	char** s;
	s = new char* [4];

	for (int i = 0; i < 4; i++)
	{
		s[i] = new char[80];
		cout <<endl<< "enter vector of B4:";
		gets_s(s[i], 80);
	}
	BoolMatrix B4(s, 4);
	cout <<endl<< "B4: " << endl<<B4 << endl;






	cout << endl << endl << "\t8)" << endl;//8
	BoolMatrix C1, C2, C3, C4;
	cout <<"C1: "<< C1<<endl;
	if (C1==B1) cout << "C1==B1: " << endl;
	else cout << "C1!=B1: " << endl;





	cout << endl << endl << "\t9)" << endl;//9
	C1 = B1 & B2; C2 = B1 | B2; C3 = B1 ^ B2; C4=~B4;
	cout << "C1: " << C1 << endl;
	cout << "C2: " << C2 << endl;
	cout << "C3: " << C3 << endl;
	cout << "C4: " << C4 << endl;




	cout << endl << endl << "\t10)" << endl;//10
	B1 &= B2;
	cout << "B1: " << B1 << endl;
	if (C1 == B1) cout << "B1==C1: " << endl;
	else cout << "B1!=C1: " << endl;



	cout << endl << endl << "\t11)" << endl;//11
	cout <<"B1[1]: "<< B1[1]<<endl;

	cout << "B1[1][19]: "<< B1[1][19]<<endl;
	cout << "B1[1][19]: " << B1[1][19] << endl;
	cout << "B1[1][18]: " << B1[1][18] << endl;



	cout << endl << endl << "\t12)" << endl;
	BooolVector temp;
	temp = B1.Disj();
	cout << "disj B1: " << temp << endl;
	temp = B1.Xor();
	cout << "XOR B1: " << temp << endl;


}

