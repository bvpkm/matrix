#pragma once

#include <string>

class M
{
public:
	unsigned rows; 
	unsigned column;
	int *data; // Данные выделяются в дин.памяти одним куском, чтобы снизить фрагментацию памяти

	M(unsigned r = 3, unsigned c = 3);
	M(int one);
	M(std::string data);
	~M(); // Деструктор
	friend M operator+(const int& a, const M& mat);
	M(M const & other);
	M operator=(M const& other);
	M operator+(M const& other); // Сложение двух матриц
	M operator-(M const& other); // Вычитание двух матриц
	M operator-(int a); // Вычитание матрицы и числа
	M operator+(int a); // Сложение матрицы и числа
	void print(); // Вывод матрицы в консоль
};
