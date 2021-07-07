#include "array_list.h"
template <class t>
void array_list<t>::expand()
{
	size *= 2;
	t* a = new t[size];
	for (int i = 0; i < cnt; i++)
	{
		a[i] = arr[i];
	}
	arr = a;

}
template <class t>
array_list<t>::array_list()
{
	size = 5;
	cnt = 0;
	arr = new User[5];

}
template <class t>
void array_list<t>::push_back(t x)
{
	if (cnt == size)
	{
		expand();
	}
	arr[cnt] = x;
	cnt++;


}
template <class t>
t array_list <t> ::get_elemnt(int indx)
{
	if (indx < 0 || indx >= size)
		indx = 0;
	return arr[indx];

}
template <class t>
void array_list <t>::delete_elemnt(int indx)
{
	if (indx < 0 || indx >= cnt)
		return;
	for (int i = indx; i < cnt - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	cnt--;

}
template <class t>
void array_list<t>::insert_elemnt(t x, int indx)
{
	if (size == cnt)
		expand();
	if (indx<0 || indx>size)
	{
		std::cout << "invalid indx"; return;
	}
	for (int i = cnt; i > indx; i--)
	{
		std::swap(arr[i], arr[i - 1]);
	}
	arr[indx] = x;
	cnt++;
}
template <class t>
bool array_list<t>::is_empty()
{
	return cnt == 0;
}
template <class t>
int array_list<t>::get_size()
{
	return cnt;
}
template <class t>
void array_list<t>::clear()
{
	cnt = 0;
}

template<class t>
void array_list<t>::set_elemnt(t x,int indx)
{
	arr[indx] = x;
}
