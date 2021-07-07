#pragma once
#include "array_list.h"
#include "User.h"
#include<iostream>
using namespace std;
class Admin
{
	string username;
	string password;
public :
	Admin();
	void view(User x);
	string get_username();
	string get_password();
	void view_all(array_list<User> x);
	void delete_data(string id, array_list<User> x);
	void delete_all_data(array_list<User> x);
};

