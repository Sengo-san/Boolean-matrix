#include "Header.h"

int BooolVector::Input(const char* s, int i_bv, int i_s, int k)
//(строка, номер байта, индекс начала фрагмента строки, кол-во значащих цифр в байте)
//формирование [i_bv]того байта
//i_s - индекс начала фрагмента массива s, который используется для  формирования bv[i_bv]
//количество значащих цифр в числе bv[i_bv] ???
{
	UC mask = 1;  
	mask <<= (k - 1);

	bv[i_bv] = 0;

	for (int i = 0; i < k; mask >>= 1, i++, i_s++)
		if (s[i_s] == '1')  
			bv[i_bv] |= mask;

	return i_s;
}

void BooolVector::Output(int i_bv, int k)        //вывод одного байта
{
	UC mask = 1;  mask <<= (k - 1);
	for (int i = 0; i < k; i++, mask >>= 1)
		if (bv[i_bv] & mask) putchar('1');
		else putchar('0');
}



//KONSTUCTORS

BooolVector::BooolVector()
{
	n = 0; m = 1;
	bv = new UC[1];
	bv[0] = 0;
}

BooolVector::BooolVector(int N) // создает БВ 00...0 длины N
{
	n = N;
	m = N / 8;
	int k = N % 8;
	if (k) m++;

	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = 0;

} 		 

BooolVector::BooolVector(const char* s)
{
	n = strlen(s);

	m = n / 8;
	int k = n % 8;
	if (k) m++;

	bv = new UC[m];
	
	int i_s = 0, i_bv = 0;

	if (k)
	{
		i_s = Input(s, i_bv, i_s, k);
		i_bv++;
	}
	while (i_s < n)
	{
		i_s = Input(s, i_bv, i_s, 8);
		i_bv++;
	}
}

BooolVector::BooolVector(const char* s, int N)
{
	if (strlen(s) >= N)

	{
		n = N;
		m = n / 8;
		int k = n % 8;
		if (k) m++;

		bv = new UC[m];

		int i_s = 0, i_bv = 0;

		if (k)
		{
			i_s = Input(s, i_bv, i_s, k);
			i_bv++;
		}

		while (i_s < n)
		{
			i_s = Input(s, i_bv, i_s, 8);
			i_bv++;
		}
	}

	else
	{
		n = N;
		m = n / 8;
		int k = n % 8;
		if (k) m++;
		bv = new UC[m];


		int M = strlen(s) / 8;
		int K = strlen(s) % 8;
		if (K) M++;
		
		int i_s = 0, i_bv = 0;


		while (i_bv < m - M)
		{
			bv[i_bv] = 0;
			i_bv++;
		}

		if (K)
		{
			i_s = Input(s, i_bv, 0, K);
			i_bv++;
		}

		while (i_s < strlen(s))
		{
			i_s = Input(s, i_bv, i_s, 8);
			i_bv++;
		}
	}
}

BooolVector::BooolVector(const BooolVector& X) 
{
	n = X.n; m = X.m;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = X.bv[i];

}

//DESTRUCTOR

BooolVector::~BooolVector()
{
	
	//cout << "destructor 0" << endl;
	//this->Print(); cout << endl;
	delete[]bv;
	//cout << "destructor 1" << endl;
}

//PRISVOENIE

BooolVector& BooolVector::operator=(const BooolVector& x)
{
	if (this != &x)
	{
		if (m < x.m)
		{
			delete[]bv;

			bv = new UC [x.m];
			
		}

		m = x.m;

		n = x.n;

		for (int i = 0; i < m; i++)
		{
			bv[i] = x.bv[i];
		}
	}
	return *this;
}

//VVOD/VIVOD

void BooolVector::Scan(int N)  //ввод БВ длины N
{

	char* s;

	s = new char[N + 1];


	cout << "enter a boolean vector of lenght " << N << ": ";

	gets_s(s, N + 1); //gets_s(s, N + 1);//костыль: первый gets_s съедает Enter, второй - настоящее значение


	BooolVector T(s);
	*this = T;//оператора присвоения-то нету!(P.S. теперь есть)
	delete[]s;
}

void BooolVector::Print()
{
	if (n == 0) cout << "[empty]";

	else
	{
		int k = n % 8, i_bv = 0;

		if (k)
		{
			Output(i_bv, k);
			i_bv++;
		}
		while (i_bv < m)
		{
			Output(i_bv, 8);
			i_bv++;
		}
	}

	cout << endl;
}

istream& operator>>(istream& r, BooolVector& x)
{
	int N;
	cout << "enter amount of bits: ";
	cin >> N;

	x.Scan(N);

	return r;
}

ostream& operator<<(ostream& r, BooolVector& x)
{
	x.Print();
	return r;
}

//[]
UC BooolVector::operator[] (int i)
{
	if (i<0 || i>n)
	{
		cout << "wrong index []";
		return 0;
	}

	UC mask = 1;
	int M = i / 8, k = i % 8;

	mask <<= k;
	if (bv[m - 1 - M] & mask) return '1';
	else return '0';
}

int BooolVector::Weight()   //вес булева вектора
{
	int w = 0;
	UC mask = 1;

	for (int i = 0; i < m; i++, mask = 1)
		for (mask <<= 7; mask != 0; mask >>= 1)
			if (bv[i] & mask)w++;
	return w;
}


//BOOLEAN

bool BooolVector::operator!=(BooolVector& x)
{
	if (n != x.n)
		return 1;

		for (int i = 0; i < m; i++)
			if (bv[i] == x.bv[i]) return 0;

		return 1;

	
}

bool BooolVector::operator==(BooolVector& x)
{
	if (n != x.n)
	{
		return false;
	}


	if (*this != x) return false;
	return true;
}

bool BooolVector::operator<= (BooolVector& x)
{
	if (n != x.n)
	{
		cout << "(<=): vectors are ancomarable " << endl;
		return false;
	}

	else
	{


		for (int i = 0; i < n; i++)
		{
			if (operator[](i) == '1' && x[i] == '0')
				return 0;
		}
		return 1;
	}
}

bool BooolVector::operator>= (BooolVector& x)
{

	if (n != x.n)
	{
		cout << "(>=): vectors are ancomarable " << endl;
		return false;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			if (operator[](i) == '0' && x[i] == '1')
				return 0;
		}
		return 1;
	}
}

//SETUPS

BooolVector BooolVector::SetUp1(int pos)
{
	if (pos >= n || pos < 0) 
	{
		cout << "incorrect index "<<"["<<pos<<"]" <<endl;
		return *this;
	}


	int byte = pos / 8;
	int bit = pos % 8;


	UC mask = 1;
	mask <<= bit;

	//cout << "byte: " << byte << endl;
	//	cout << "bit: " << bit << endl;

	bv[m-byte-1]|= mask;
	   
	return *this;

}

BooolVector BooolVector::SetUp0(int pos)
{
	if (pos >= n || pos < 0)
	{
		cout << "incorrect index " << "[" << pos << "]" << endl;
		return *this;
	}

	int byte = pos / 8;
	int bit = pos % 8;
	UC mask = 1;
	mask <<= bit;

	mask=~mask;

	bv[m - byte - 1] &= mask;

	return *this;

}


BooolVector BooolVector::SetUp1(int k, int p) //установить k единиц начиная с позиции p
{
	for (int i = p; i < p + k; i++)
	{
		this->SetUp1(i);
	}
	return *this;
}

BooolVector BooolVector::SetUp0(int k, int p) //установить k нулей начиная с позиции p 
{
	for (int i = p; i < p + k; i++)
	{
		this->SetUp0(i);
	}
	return *this;
}



//BIT OPERATORS

BooolVector  BooolVector::operator& (BooolVector& Y) 		//x=(*this)&y
{
	//определяем N - размер результата
	int N = n, j_res = m - 1;
	if (N > Y.n) { N = Y.n; j_res = Y.m - 1; }

	//нахождение конъюнкции:
	BooolVector Res(N);
	int j, j_Y;
	for (j = m - 1, j_Y = Y.m - 1; j_res >= 0; j--, j_Y--, j_res--)
		Res.bv[j_res] = bv[j] & Y.bv[j_Y];

	return Res;

}

BooolVector& BooolVector::operator&= (BooolVector& Y)	//*this=(*this)&y 
{
	BooolVector Res = (*this) & Y;
	*this = Res;
	return *this;
}

BooolVector  BooolVector::operator| (BooolVector& Y)

{
	//определяем N - размер результата

	int N = n, j_res = m - 1;
	if (N < Y.n) { N = Y.n; j_res = Y.m - 1; }
/*
	int N = n;
	if (Y.n > N) N = Y.n;*/

	//нахождение конъюнкции:
	BooolVector Res(N);
	int j, j_Y;
	for (j = m - 1, j_Y = Y.m - 1; j>=0 && j_Y>=0; j--, j_Y--, j_res--)
		Res.bv[j_res] = bv[j] | Y.bv[j_Y];

	while (j >= 0)
	{
		Res.bv[j_res] = bv[j];
		j--;
		j_res--;
	}

	while (j_Y >= 0)
	{
		Res.bv[j_res] = Y.bv[j_Y];
		j_Y--;
		j_res--;
	}
	return Res;
}

BooolVector& BooolVector::operator|= (BooolVector& Y)
{
	BooolVector Res = (*this) | Y;
	*this = Res;
	return *this;
}

BooolVector  BooolVector::operator^ (BooolVector& Y)

{
	//определяем N - размер результата
	int N = n, j_res = m - 1;
	if (N < Y.n) { N = Y.n; j_res = Y.m - 1; }

	//нахождение конъюнкции:
	BooolVector Res(N);
	int j, j_Y;
	for (j = m - 1, j_Y = Y.m - 1; j >= 0 && j_Y >= 0; j--, j_Y--, j_res--)
		Res.bv[j_res] = bv[j] ^ Y.bv[j_Y];

	while (j >= 0)
	{
		Res.bv[j_res] = bv[j];
		j--;
		j_res--;
	}

	while (j_Y >= 0)
	{
		Res.bv[j_res] = Y.bv[j_Y];
		j_Y--;
		j_res--;
	}

	return Res;
}

BooolVector& BooolVector::operator^= (BooolVector& Y)
{
	BooolVector Res = (*this) ^ Y;
	*this = Res;
	return *this;
}


//INVERTORS

BooolVector BooolVector::operator~()
{
	for (int i = 0; i < n; i++)
		if (this->operator[](i) == '0')
			this->SetUp1(i);
		else this->SetUp0(i);
	return *this;
}

BooolVector BooolVector::Invert(int i)
{
	if (i<0 || i>n)
	{
		cout << "wrong index (Invert)" << endl;
		return *this;
	}

	if (operator[](i) == '0') SetUp1(i);
	else SetUp0(i);


	return *this;
}

BooolVector BooolVector::Invert(int k, int p)
{
	for (int i = p; i < p + k; i++)
	{
		this->Invert(i);
	}
	return *this;
}



//POBIT SDVIGI

BooolVector BooolVector::operator<< (int x)
{
	BooolVector res(*this);
	
	for (int i = n-1; i >= x; i--)
	{
		if (res[i - x] == '1')
		{
			//cout << "1"; 
			res.SetUp1(i); 
		}
		else
		{
			//cout << "0";
			res.SetUp0(i); 
		}
	}
	for (x--; x >= 0; x--)
		res.SetUp0(x);
	

	return res;

}

BooolVector BooolVector::operator>> (int x)
{
	BooolVector res(*this);

	for (int i = 0; i < n-x; i++)
	{
		if (res[i + x] == '1')
			res.SetUp1(i);
		else res.SetUp0(i);
	}

	for (x=n-x; x < n; x++)
		res.SetUp0(x);

	return res;

}

BooolVector& BooolVector::operator<<= (int x)
{

	//BooolVector Res = (*this) <<x;
	*this = (*this).operator<<(x);
	return *this;
	
}

BooolVector& BooolVector::operator>>= (int x)
{

	//BooolVector Res = (*this) <<x;
	*this = (*this).operator>>(x);
	return *this;

}