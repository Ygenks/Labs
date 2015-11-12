#include <iostream>
#include <stdlib.h>
using namespace std;


class Matrix
{
	private:
		int** matrix;
		int rows;
		int coloumns; 
	public:
		Matrix(): matrix(NULL), rows(0), coloumns(0)
		{}
		Matrix(int r, int c);
		~Matrix();
		Matrix(Matrix& m);
		int* operator[](int i);
		void set_Matrix();
		void get_Matrix()const;
		int get_rows()const;
		int get_coloumns()const;
		Matrix& operator+(Matrix& m);
		Matrix operator*(Matrix& m);
		
};

Matrix :: ~Matrix()
{
	for(int i = 0; i < rows; i++)
		delete [] matrix[i];
	delete [] matrix;
	cout << "dead" << endl;
}

Matrix :: Matrix(int r, int c)
{
	rows = r;
	coloumns = c;

	matrix = new int*[r];
	for(int i = 0; i < r; i++)
		matrix[i] = new int[c];		
}

Matrix :: Matrix(Matrix& m)
{
	Matrix *kek;
	
	/*for(int i = 0; i < rows; i++)
			delete [] matrix[i];
		delete [] matrix;*/

	kek = new Matrix(m.rows, m.coloumns);
	*this = *kek;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j< coloumns; j++)
			matrix[i][j] = m.matrix[i][j];
}

int* Matrix :: operator[](int i)
{
	if(i >= 0)
		return matrix[i];
	else
	{
		cerr << "operator[]: out of range" << endl;
		exit(1);
	}
}

Matrix Matrix :: operator*(Matrix& m)
{
	if(coloumns != m.rows)
	{
		cerr << "Number of coloumns of 1-st matrix doesn't match number of rows of 2-nd matrix" << endl;
		exit(1);
	}

	Matrix result(rows, m.coloumns);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < m.coloumns; j++)
		{
			result.matrix[i][j] = 0;
			for (int k = 0; k < coloumns; k++)
				result.matrix[i][j] += matrix[i][k]*m.matrix[k][j];
		}

	return result;
}


Matrix& Matrix :: operator+(Matrix& m)
{
	if(m.rows != rows && m.coloumns != coloumns)
	{	
		cerr << "Matrix dimensions are incompatible" << endl;
		exit(1);
	}

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < coloumns; j++)
			matrix[i][j] += m.matrix[i][j];

	return *this;
}

void Matrix :: set_Matrix()
{
	Matrix *kek;
	while(true)
	{
		cout << "Enter number of rows:" << endl;
		cin >> rows;

		if(true == cin.good() && rows > 0)
		{
			cin.ignore(100, '\n');
			break;
		}
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "You have entered wrong number, try again" << endl;
	}

	while(true)
	{
		cout << "Enter number of coloumns:" << endl;
		cin >> coloumns;

		if(true == cin.good() && coloumns > 0)
		{
			cin.ignore(100, '\n');
			break;
		}
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "You have entered wrong number, try again" << endl;
	}


	kek = new Matrix(rows, coloumns);

	*this = *kek;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j < coloumns; j++)
		{
			cout << "Enter the matrix[" << i << "][" << j << "]" << endl; 
			cin >> matrix[i][j];

			if(true == cin.good())
			{
				cin.ignore(100, '\n');
				continue;
			}
			j--;
			cin.clear();
			cin.ignore(100, '\n');
			cerr << "You have entered wrong element, try again" << endl;
		}

}

void Matrix :: get_Matrix()const
{
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < coloumns; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}

int Matrix :: get_rows()const
{
	return rows;
}

int Matrix :: get_coloumns()const
{
	return coloumns;
}

int main()
{
	Matrix m1;

	m1.set_Matrix();

	for(int i = 0; i < m1.get_rows(); i++)
		{
			for (int j = 0; j < m1.get_coloumns(); j++)
				cout << m1[i][j] << ' ';
			cout << endl;
		}
	
	return 0;
}