#include <iostream>
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
		Matrix(int r, int c)
		{
			rows = r;
			coloumns = c;

			matrix = new int*[r];
			for(int i = 0; i < r; i++)
				matrix[i] = new int[c];		
		}
		~Matrix()
		{
			for(int i = 0; i < rows; i++)
				delete [] matrix[i];
			delete [] matrix;
		}
		Matrix(Matrix& m);
		void set_Matrix();
	
};

Matrix :: Matrix(Matrix& m)
{
	Matrix *kek;
	
	for(int i = 0; i < rows; i++)
			delete [] matrix[i];
		delete [] matrix;

	kek = new Matrix(m.rows, m.coloumns);

	*this = *kek;

	for(int i = 0; i < rows; i++)
		for(int j = 0; j< coloumns; j++)
			matrix[i][j] = m.matrix[i][j];
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
				break;
			}
			cin.clear();
			cin.ignore(100, '\n');
			cerr << "You have entered wrong element, try again" << endl;
		}
}


int main()
{
	Matrix m1;

	m1.set_Matrix();	

	return 0;
}