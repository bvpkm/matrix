#pragma once

#include <string>

class M
{
public:
	unsigned rows; 
	unsigned column;
	int *data; // ������ ���������� � ���.������ ����� ������, ����� ������� ������������ ������

	M(unsigned r = 3, unsigned c = 3);
	M(int one);
	M(std::string data);
	friend M operator+(const int& a, const M& mat);
	M(M const & other);
	M operator=(M const& other);
	M operator+(M const& other); // �������� ���� ������
	M operator-(M const& other); // ��������� ���� ������
	M operator-(int a); // ��������� ������� � �����
	M operator+(int a); // �������� ������� � �����
	void print(); // ����� ������� � �������
};
