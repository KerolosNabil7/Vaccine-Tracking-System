#include "Admin.h"
#include "User.h"
#include "array_list.cpp"
Admin::Admin()
{
	username = "Admin";
	password = "Admin";
}

string Admin::get_username()
{
	return username;
}
string Admin::get_password()
{
	return password;
}
void Admin::view(User user)
{
	cout << "the data of user is : \n";
	cout << "the national id is : " << user.get_nid() << endl;
	cout << "the password is : " << user.get_password() << endl;
	cout << "the user name is : " << user.get_name() << endl;
	cout << "the gender is : " << user.get_gender() << endl;
	cout << "the country is : " << user.get_country() << endl;
	cout << "the govern : " << user.get_govern() << endl;
	cout << "the age is : " << user.get_age() << endl;
	cout << "the number of vaccine doses : " << user.get_vaccDoeses() << endl;
	cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n";
}

void Admin::view_all(array_list<User> users)
{
	for (int i = 0; i < users.get_size(); i++)
	{
		cout << "this is the data for user number " << i + 1 << endl;
		view(users.get_elemnt(i));
	}
}

void Admin::delete_data(string id, array_list<User> users)
{
	bool found = 0;
	for (int i = 0; i < users.get_size(); i++)
	{
		if (users.get_elemnt(i).get_nid() == id)
		{
			found = 1;
			users.delete_elemnt(i);
		}
	}
	if (!found)
	{
		cout << "no user have this id \n";
	}
	else
	{
		cout << "the user with id : " << id << " deleted succufuly \n";
	}
}

void Admin::delete_all_data(array_list<User> users)
{
	users.clear();
}
