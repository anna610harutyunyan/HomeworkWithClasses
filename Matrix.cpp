#include <iostream>
#include <cstdlib>
#include <stdexcept>

class Matrix 
{
	int** array;
	int rows;
	int columns;

public:

	Matrix()
	{
		std::cout << "Default constructor is called \n";
	}
	Matrix(int rows, int columns)
	{
		this->rows = rows;
		this->columns = columns;

		array = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			array[i] = new int[columns];
			{
				for (int j = 0; j < columns; ++j)
				{
					array[i][j] = 12 + rand() % 120;
				}
			}
		}
	}

	Matrix(const Matrix& other)
	{
		this->rows = other.rows;
		this->columns = other.columns;
		if (rows <= 0 || columns <= 0)
		{
			throw std::runtime_error ("The rows and columns of the matrix must be greather than 0!!!");
		}

		this-> array = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			array[i] = new int[columns];
			for (int j = 0; j < columns; ++j)
			{
				array[i][j] = other.array[i][j];
			}
		}
	}
	void Display(int rows, int colums)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				std::cout << array[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)
			return *this;

		for (int i = 0; i < rows; ++i)
		{
			delete[] array[i];
		}

		delete[] array;
		array = nullptr;

		this->rows = other.rows;
		this->columns = other.columns;
		this->array = new int* [rows];
		for (int i = 0; i < rows; ++i)
		{
			array[i] = new int[columns];
			for (int j = 0; j < columns; ++j)
			{
				array[i][j] = other.array[i][j];
			}
		}

		return *this;
	}

	~Matrix()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] array[i];
		}
		delete[] array;
		array = nullptr;
		std::cout << "The destructor is called \n";
	}

};

int main(int argc, char** argv)
{
	int rows = 0;
	int columns = 0;

	std::cout << "Please enter the size of the rows:_";
	std::cin >> rows;
	std::cout << std::endl;
    std::cout << "Please enter the size of the colums:_";
	std::cin >> columns;
	std::cout << std::endl;

	Matrix twoD(rows, columns);
	std::cout << "You have initilised the following 2D matrix:_\n";
	twoD.Display(rows, columns);
	Matrix copy_2D(twoD);
	std::cout << "New matrix that is a copy of previous one is:_\n";
	copy_2D.Display(rows, columns);
	Matrix newassign;
	newassign = copy_2D;
	std::cout << "New matrix after assignment will be:_ \n";
	newassign.Display(rows, columns);


	return 0;
}