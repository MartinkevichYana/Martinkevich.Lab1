#include <iostream>

using namespace std;

int* AllocArray(int N);
void DisplayArray(int* a, int N);
void WriteInNewArray(int* a, int* b, int N);
int QuantityNechIndChetnElement(int* a, int N);
void ArrayOfRemainingElement(int* a, int* b, int N, int p);
void ArrayAfterDivision(int* a, int* b, int l, int del);
void Swap(int &a, int &b);
void BubbleSort(int *b, int l, int del);

const int N = 7;

int main()
{
	while (true)
	{
		int del;
		cout << "Enter the divisor: ";
		cin >> del;
		if (del == 0)
		{
			cout << "You enter wrong number!" << endl;
			system("pause");
		}
		else if (del != 0)
		{
			system("cls");
			int* a = new int[N];
			a = AllocArray(N);
			int* b = new int[N];
			cout << "~~~~~ The original array: ";
			DisplayArray(a, N);
			cout << " ~~~~~" << endl;
			cout << endl;
			int p = QuantityNechIndChetnElement(a, N);
			WriteInNewArray(a, b, N);
			cout << "~~~~~ Array of odd index and even elements: ";
			DisplayArray(b, p);
			cout << " ~~~~~" << endl;
			cout << endl;
			cout << "~~~~~ Array of remaining elements: ";
			ArrayOfRemainingElement(a, b, N, p);
			int l = N - p;
			DisplayArray(a, l);
			cout << " ~~~~~" << endl;
			cout << endl;
			cout << "~~~~~ Elements of array after division: ";
			ArrayAfterDivision(a, b, l, del);
			DisplayArray(b, l);
			cout << " ~~~~~" << endl;
			cout << endl;
			cout << "~~~~~ Sorted array: ";
			BubbleSort(a, l, del);
			DisplayArray(a, l);
			cout << " ~~~~~" << endl;
			cout << endl;
			system("pause");
			return 0;
		}
	}
}


int* AllocArray(int N)
{
	int* a = new int[N];
	int* b = new int[N];
	for (int* p = a; p < (a + N); p++)
	{
		*p = rand() % 100 + 50;
	}
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int *i = a; i < a + n; i++)
		cout << *i << " ";
}

void WriteInNewArray(int* a, int* b, int N)
{
	int k = 0;
	for (int i = 0; i < N;)
	for (int j = 0; j < N; j++)
	{
		b[j] = a[i];
		i = i + 2;
	}
	for (int i = 0; i < N; i++)
	{
		if ((b[i] % 2) == 0)
		{
			b[k] = b[i];
			k++;
		}
	}
}

int QuantityNechIndChetnElement(int* a, int N)
{
	int p = 0;
	N = N-N/3;
	for (int i = 0; i < N; i++)
	{
		if ((a[i] % 2) == 0)
			p++;
	}
	return p;
}

void ArrayOfRemainingElement(int* a, int* b, int N, int p)
{
	for (int i = 0; i < N; i++)
	for (int j = 0; j < p; j++)
	{
		if (a[i] == b[j])
		{
			for (int k = i; k <= N; k++)
				a[k] = a[k + 1];
			N--;
			j--;
		}
	}
}

void ArrayAfterDivision(int* a, int* b, int l, int del)
{
	for (int i = 0; i < l; i++)
	{
		b[i] = a[i] % del;
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int *a, int l, int del)
{
	for (int i = 0; i < l - 1; i++)
	for (int j = 0; j < l - i - 1; j++)
	{
		if ((a[j] % del) < (a[j + 1] % del))
			Swap(a[j], a[j + 1]);
	}
}