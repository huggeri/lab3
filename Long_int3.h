#pragma once
//Вариант 6.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Long_int
{
	static unsigned int count_objects; //статическая переменная, считающа количество созданных за всю работу программы объектов
	void work_with_symbols(Long_int &val2, int key, int &change_symbol);
	bool null(Long_int val2);
	void clean_arr();
protected:
	bool negative; //знак числа
	int len;
	int *arr; // указатель на массив
	void copyr(int *arr1, int len1, int *arr2, int len2);//работа с массивами
	int compare(const Long_int &val2);//сравнение
	void up_size_array(int length);
	void reduce_size_array(int length);
	void clean_string_and_char_to_int(char buff[]);
public:
	Long_int();
	Long_int(const Long_int &object); // конструктор копирования
	bool operator == (const Long_int &object);
	bool operator != (const Long_int &object);
	Long_int & operator = (const Long_int &object);// перегрузка оператора присваивани¤
	Long_int operator * (Long_int &val2);
	Long_int operator / (Long_int &val2);
	Long_int operator + (Long_int &val2);
	Long_int operator - (Long_int &val2);
	Long_int & operator ++ ();
	Long_int & operator -- (int);
	friend istream & operator >> (istream &in, Long_int &object);
	friend ostream & operator << (ostream &out, Long_int &object);
	friend ofstream & operator << (ofstream & out, Long_int &object);
	friend ifstream & operator >> (ifstream & in, Long_int &object);
	const char* get_symbol();
	int get_length();
	int get_digit(int index);
	static unsigned int get_count_objects();
	~Long_int(); //деструктор
};

class Unsigned_fractional_number : public Long_int
{
	void up_size_for_operations(int pow);//добавление нулей в младшие разряды (в отличии от Up_size_array)
	int compare_fraction_part(const Unsigned_fractional_number &val2);//сравнение длин дробных частей
protected:
	int pos_point; // класс хранит позицию точки
	//int *fraction_part;
	void magic_with_digits(Unsigned_fractional_number &val2);//добавление младших разрядов по необходимости (после точки) для корректного оперирования значениями
	int clean_string_and_char_to_int_with_dot(char buff[]);//для ввода
	void convert_pos_point(Unsigned_fractional_number &val1, const Unsigned_fractional_number &val2); // преобразование позиции точки
public:
	Unsigned_fractional_number();
	Unsigned_fractional_number(const Unsigned_fractional_number &object);
	Unsigned_fractional_number & operator = (const Unsigned_fractional_number &object);// перегрузка оператора присваивания
	Unsigned_fractional_number operator * (Unsigned_fractional_number &val2);
	Unsigned_fractional_number operator / (Unsigned_fractional_number &val2);
	Unsigned_fractional_number operator + (Unsigned_fractional_number &val2);
	Unsigned_fractional_number operator - (Unsigned_fractional_number &val2);
	friend istream & operator >> (istream &in, Unsigned_fractional_number &object);
	friend ostream & operator << (ostream &out, Unsigned_fractional_number &object);
	~Unsigned_fractional_number();
};

class Signed_fractional_number : public Unsigned_fractional_number
{
public: //конструкторы родительского и базового класса предполагают работу с памятью
	Signed_fractional_number & operator = (const Signed_fractional_number &object);// перегрузка оператора присваивания (вместо копирования)
	Signed_fractional_number operator * (Signed_fractional_number &val2);
	Signed_fractional_number operator / (Signed_fractional_number &val2);
	Signed_fractional_number operator + (Signed_fractional_number &val2);
	Signed_fractional_number operator - (Signed_fractional_number &val2);
	friend istream & operator >> (istream &in, Signed_fractional_number &object);
	friend ostream & operator << (ostream &out, Signed_fractional_number &object);
};
