//

#pragma once
#include "User.h"
#include<iostream>
using namespace std;
template < class t>
class array_list
{
	t* arr;
	int size;
	int cnt = 0;
	void expand();
public:
	array_list();
	void push_back(t x);
	t get_elemnt(int indx);
	void delete_elemnt(int indx);
	void insert_elemnt(t x, int indx);
	bool is_empty();
	int get_size();
	void clear();
	void set_elemnt(t x,int indx);
};