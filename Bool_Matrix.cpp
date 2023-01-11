#include "Bool_matrix.h"

int BoolMatrix::Max(char** s, int m)//s- массив строк, m - количество строк
{
	int i, max;
	max = strlen(s[0]);
	for (i = 0; i < m; i++)
		if (max < strlen(s[i]))
			max = strlen(s[i]);
	return max; //длина наибольшей строки
}

//KONSTRUCTORS

BoolMatrix::BoolMatrix()//создает массив 1х1 [0]
{
	m = 1; n = 1;
	BM = new BooolVector[m];
	BooolVector B(1);
	BM[0] = B;
	//BM[0]=BooolVector(1);
}

BoolMatrix::BoolMatrix(int M, int N)//матрица MxN все биты нулевые
{
	m = M; n = N;
	BM = new BooolVector[m];
	for (int i = 0; i < m; i++)
		BM[i] = BooolVector(n);
	//второй вариант:
	//BooolVector B(n);
	//for(int i=0; i<m; i++)
	//	      BM[i]=B;
}

BoolMatrix::BoolMatrix(char** s, int M)//матрица из массива строк, M - число строк (векторов соответственно)
{
	m = M;
	n = Max(s, M);
	BM = new BooolVector[m];
	for (int i = 0; i < m; i++)
		BM[i] = BooolVector(s[i], n);
}

BoolMatrix::BoolMatrix(const BoolMatrix& X)
{
	BM = new BooolVector[X.m];//

	m = X.m; n = X.n;
	for (int i = 0; i < m; i++)
		BM[i] = X.BM[i];
}

//DESTRUCTOR

BoolMatrix::~BoolMatrix()
{
	delete[]BM;
}

BoolMatrix& BoolMatrix::operator= (const BoolMatrix& x)
{
	if (this != &x)
	{
		if (m != x.m)
		{
			delete []BM;
			BM = new  BooolVector[x.m];
			m = x.m;
		}


		n = x.n;

		for (int i = 0; i < m; i++)
			BM[i] = x.BM[i];
	}
	return *this;
}

//INPUT&OUTPUT

void BoolMatrix::Scan(int M, int N)
{
	if (m != M || n != N)
	{
		delete[]BM;
		n = N; m = M;
		BM = new BooolVector[m];
	}
	cout << "enter Boolean Matrix size of " << m << 'x' << n << ':' << endl;
	for (int i = 0; i < m; i++)
		BM[i].Scan(n);
}

istream& operator>>(istream& r, BoolMatrix& X)
{
	cout << "enter the number of rows and columns:";
	int M, N;
	cin >> M >> N;
	//Очистка потока ввода. Несколько вариантов:
	while (getchar() != '\n');
	//или while(getchar()!='\n') continue;
	//второй вариант: while(cin.get())!='\n');  
	//	      	      или  while(cin.get())!='\n') continue;
	//третий вариант: char s[10]; sets_s(s,10);
	X.Scan(M, N);
	return r;
}

void BoolMatrix::Print()
{
	for (int i = 0; i < m;i++)
		cout << BM[i];
}

ostream& operator<<(ostream& r, BoolMatrix& x)
{
	x.Print();
	return r;
}


//OPERATOR[]

BooolVector& BoolMatrix::operator[] (int i)//возвращает адрес iго вектора
{
	try
	{
		if (i < 0) throw 0;
		if (i >= m) throw "index >= m";
		return BM[i];
	}


	catch (int i)
	{
		cout << "index < 0" << endl;
		return BM[0];
	}
	catch (char* s)
	{
		cout << s << endl;
		return BM[m - 1];
	}
	catch (...)
	{
		cout << "incorrect index" << endl;
		exit(-1);
	}
}


//BOOL


bool BoolMatrix::operator==(BoolMatrix& x)
{
	if (n != x.n || m!=x.m)
		return 0;

	for (int i = 0; i < m; i++)
	{
		if (BM[i] != x.BM[i])
			return 0;
	}

	return 1;
}


bool BoolMatrix::operator!=(BoolMatrix& x)
{
	if (*this == x)
		return 0;

	return 1;
}

//SETUPS

BoolMatrix BoolMatrix::SetUp1(int i, int j)//установить kol эл-тов в i-й строке, j-м столбце (cтолбцы считаются справа налево)

{
	if (i < 0 || i >= m)
	{
		cout << "incorrect index i (SetUp1)" << endl;
		return *this;
	}
	if (j < 0 || j >= n)
	{
		cout << "incorrect index j (SetUp1)" << endl;
		return *this;
	}
	BM[i].SetUp1(j);
	//если столбцы матрицы нумеруются слева направо, то
	//BM[i].SetUp1(n-1-j);
	return *this;
}

BoolMatrix BoolMatrix::SetUp0(int i, int j)//сбрасывает kol эл-тов в i-й строке, j-м столбце (cтолбцы считаются справа налево)

{
	if (i < 0 || i >= m)
	{
		cout << "incorrect index i (SetUp1)" << endl;
		return *this;
	}
	if (j < 0 || j >= n)
	{
		cout << "incorrect index j (SetUp1)" << endl;
		return *this;
	}
	BM[i].SetUp0(j);
	//если столбцы матрицы нумеруются слева направо, то
	//BM[i].SetUp1(n-1-j);
	return *this;
}



BoolMatrix BoolMatrix::SetUp1(int i, int j, int kol)
{

	{
		if (i < 0 || i > m)
		{
			cout << "incorrect index i (SetUp1)" << endl;
			return *this;
		}
		if (j < 0 || j >= n || j + kol > n)
		{
			cout << "incorrect index j (SetUp1)" << endl;
			return *this;
		}

		BM[i].SetUp1(kol, j);

		return *this;
	}
}


BoolMatrix BoolMatrix::SetUp0(int i, int j, int kol)	//сбросить kol эл-тов в i-й строке, j-м столбце
{
	if (i < 0 || i > m)
	{
		cout << "incorrect index i (SetUp0)" << endl;
		return *this;
	}
	if (j < 0 || j >= n || j + kol > n)
	{
		cout << "incorrect index j (SetUp0)" << endl;
		return *this;
	}

	BM[i].SetUp0(kol, j);

	return *this;
}





//INVERTORS
BoolMatrix BoolMatrix::operator~()
{
	for (int i = 0; i < m; i++)
	{
		~BM[i];
	}

	return *this;
}

BoolMatrix BoolMatrix::Invert(int i, int j)
{
	if (i < 0 || i >= m)
	{
		cout << "incorrect index i (Invert)" << endl;
		return *this;
	}
	if (j < 0 || j >= n)
	{
		cout << "incorrect index j (Invert)" << endl;
		return *this;
	}
	BM[i].Invert(j);

	return *this;
}

BoolMatrix BoolMatrix::Invert(int i, int j, int kol)	//инвертировать kol эл-тов в i-й строке, j-м столбце
{
	{
		if (i < 0 || i >= m)
		{
			cout << "incorrect index i (Invert)" << endl;
			return *this;
		}
		if (j < 0 || j >= n || j + kol >= n)
		{
			cout << "incorrect index j (Invert)" << endl;
			return *this;
		}

		BM[i].Invert(kol, j);

		return *this;
	}
}

//BITOPERATORS

BoolMatrix BoolMatrix::operator & (BoolMatrix& X)//построчная конъюнкция 2-х матриц, создается новая
{
	BoolMatrix Res(m, n);
	if (m != X.m || n != X.n)
	{
		cout << "incorrect dimension (&)" << endl;
		Res = *this;
	}
	else for (int i = 0; i < m; i++)
		Res.BM[i] = BM[i] & X.BM[i];
	return Res;
}

BoolMatrix& BoolMatrix::operator &= (BoolMatrix& X)//построчная конъюнкция 2-х матриц, изменяется *this

{
	BoolMatrix Res = (*this) & X;
	(*this) = Res;
	return *this;
}

BoolMatrix BoolMatrix::operator | (BoolMatrix& x)	//построчная дизъюнкция 2-х матриц, создается новая
{
	BoolMatrix Res(m, n);
	if (m != x.m || n != x.n)
	{
		cout << "incorrect dimension ( | )" << endl;
		Res = *this;
	}
	else for (int i = 0; i < m; i++)
		Res.BM[i] = BM[i] | x.BM[i];
	return Res;
}

BoolMatrix& BoolMatrix::operator |= (BoolMatrix& x)	//построчная дизъюнкция 2-х матриц, изменяется *this
{
	BoolMatrix Res = (*this)| x;
	(*this) = Res;
	return *this;
}

BoolMatrix BoolMatrix::operator ^ (BoolMatrix& x)	//построчная XOR 2-х матриц, создается новая
{
	BoolMatrix Res(m, n);
	if (m != x.m || n != x.n)
	{
		cout << "incorrect dimension ( ^ )" << endl;
		Res = *this;
	}
	else for (int i = 0; i < m; i++)
		Res.BM[i] = BM[i] ^ x.BM[i];
	return Res;
}

BoolMatrix& BoolMatrix::operator ^= (BoolMatrix& x)	//построчная XOR 2-х матриц, изменяется *this
{

	BoolMatrix Res = (*this) ^ x;
	(*this) = Res;
	return *this;
}


//BIT SHIFTS
BoolMatrix BoolMatrix::ShiftRight(int i, int k)//сдвиг вправо эл-тов i-й строки на k, создается новая

{
	BoolMatrix Res = (*this);
	Res.BM[i] >>= k;
	return Res;
}

BoolMatrix& BoolMatrix::ShiftRightEq(int i, int k)//сдвиг вправо эл-тов i-й строки на k, изменяется *this

{
	BM[i] >>= k;
	return *this;
}

BoolMatrix BoolMatrix::ShiftLeft(int i, int k)	//сдвиг влево эл-тов i-й строки на k, создается новая
{
	BoolMatrix Res = (*this);
	Res.BM[i] <<= k;
	return Res;
}
BoolMatrix& BoolMatrix::ShiftLeftEq(int i, int k)
{
	BM[i] <<= k;
	return *this;
}


//DETERMINATION
BooolVector BoolMatrix::Conj() //конъюнкция всех строк матрицы
{
	BooolVector Res (BM[0]);
	for (int i = 1; i < m; i++)
		Res &= BM[i];
	return Res;
}

BooolVector BoolMatrix::Disj()  //дизъюнкция всех строк матрицы
{
	BooolVector Res(BM[0]);
	for (int i = 1; i < m; i++)
		Res |= BM[i];
	return Res;
}

BooolVector BoolMatrix::Xor()  //XOR всех строк матрицы
{
	BooolVector Res(BM[0]);
	for (int i = 1; i < m; i++)
		Res ^= BM[i];
	return Res;

}