#include "M.h"
#include <iostream>
#include <vector>

M::M(unsigned const r, unsigned const c) // ����������� ���������������� ������� ������� r x c
{
	rows = r;
	column = c;
	data = new int[r * c];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < column; j++)
			data[i * column + j] = 0; 
};

M::M(M const& other) // ����������� �����������
{
	column = other.column;
	rows = other.rows;
	data = new int[rows * column];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < column; j++)
			data[i * column + j] = other.data[i * column + j];
} 

M::M(std::string str) 
{
	/*
	����������� ����������� � �������� ��������� ������ ���� "1 2 3 4 5 6 7 8 9" � ����������������
	���������� �������, ��� 1...9 - �������� �������.
	���� ������ ����� ������, ��� ���������� ��� �������� ���������� �������, ���������� �������� ����� ��������� 0
	*/

	std::vector<int> numbers;
	unsigned start = 0;
	unsigned stop = 0;
	for (unsigned i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			stop = i;
			numbers.push_back(std::stoi(str.substr(start, stop - start)));
			start = i + 1;
		}
	};
	numbers.push_back(std::stoi(str.substr(start, str.length() - start)));
	int n = int(sqrt(numbers.size() - 1)) + 1;
	column = n;
	rows = n;
	data = new int[rows * column];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < column; j++)
		{
			if (i * column + j < numbers.size())
				data[i * column + j] = numbers[i * column + j];
			else
				data[i * column + j] = 0;
		}
}

M::M(int one) // �����������, ����������� ��� �������� ������� 2x2 � ��������� ������� ����������
{
	if (one == 1)
	{
		column = 2;
		rows = 2;
		data = new int[rows * column];
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < column; j++)
			{
				if (i == j)
					data[i * column + j] = 1;
				else
					data[i * column + j] = 0;
			}
				
	}
	else
	{
		column = 0;
		rows = 0;
		data = 0;
	}
}

M M::operator=(M const& other) // �������� ������������ 
{
	if (this != &other)
	{
		delete[] data;
		rows = other.rows;
		column = other.column;
		data = new int[rows * column];
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < column; j++)
				data[i * column + j] = other.data[i * column + j];
	}
	return *this;
}

// ������, ��������� �������� � ��������� ���� ������ ��� �� ��������. �.�. � ���������� ������� ������� ����������� �������� ������ �������, � ����� ������.
// ��� �������� ��-�� ����, ��� ��������� ����� ��������� ������� ������ ��������, � ��������� �� ���� ��������� �������������� ������� � �������� �������������,
// �-� � ������ ��������/�������� ������ 1xN � Nx1

M M::operator+(M const& other) // �������� �������� ���� �������� �������. ���������� ������� ����������� �� ��������
{
	M result;
	if (this == &other)
	{
		result = M(rows, column);
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < column; j++)
				result.data[i * column + j] = data[i * column + j] * 2;
	}
	else
	{
		int mr, mc;
		if (this->column > other.column)
			mc = this->column;
		else
			mc = other.column;
		if (this->rows > other.rows)
			mr = this->rows;
		else
			mr = other.rows;
		result = M(mr, mc);
		for (unsigned i = 0; i < this->rows; i++)
			for (unsigned j = 0; j < this->column; j++)
				result.data[i * mc + j] += this->data[i * this->column + j];
		for (unsigned i = 0; i < other.rows; i++)
			for (unsigned j = 0; j < other.column; j++)
				result.data[i * mc + j] += other.data[i * other.column + j];
	}
	return result;
}

M M::operator-(M const& other)
{
	M result;
	if (this == &other)
	{
		result = M(rows, column);
		for (unsigned i = 0; i < rows; i++)
			for (unsigned j = 0; j < column; j++)
				result.data[i * column + j] = 0;
	}
	else
	{
		int mr, mc;
		if (this->column > other.column)
			mc = this->column;
		else
			mc = other.column;
		if (this->rows > other.rows)
			mr = this->rows;
		else
			mr = other.rows;
		result = M(mr, mc);
		for (unsigned i = 0; i < this->rows; i++)
			for (unsigned j = 0; j < this->column; j++)
				result.data[i * mc + j] += this->data[i * this->column + j];
		for (unsigned i = 0; i < other.rows; i++)
			for (unsigned j = 0; j < other.column; j++)
				result.data[i * mc + j] -= other.data[i * other.column + j];
	}
	return result;
}

M M::operator+(int a)
{
	M result;
	result.column = column;
	result.rows = rows;
	result.data = new int[column * rows];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < column; j++)
			result.data[i * column + j] = data[i * column + j] + a;
	return result;
};

M M::operator-(int a)
{
	M result;
	result.column = column;
	result.rows = rows;
	result.data = new int[column * rows];
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < column; j++)
			result.data[i * column + j] = data[i * column + j] - a;
	return result;
};

M operator+(const int& a, const M& mat)
{
	M result;
	result.column = mat.column;
	result.rows = mat.rows;
	result.data = new int[result.column * result.rows];
	for (unsigned i = 0; i < mat.rows; i++)
		for (unsigned j = 0; j < mat.column; j++)
			result.data[i * result.column + j] = mat.data[i * mat.column + j] + a;
	return result;
};

void M::print()
{
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < column; j++)
			std::cout << data[i * column + j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
