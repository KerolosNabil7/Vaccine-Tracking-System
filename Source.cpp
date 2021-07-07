#include<iostream>
#include "queueArr.cpp"
#include "User.h"
#include<string>
#include "array_list.cpp"
#include "Admin.h"
#include "supoort_functions.h"
#include<map>
using namespace std;
array_list<User> users;
queueArr<User> waitinglist;
map<string, int> total_govern,zero_govern,one_govern,two_govern;
int main()
{
	
	while (true)
	{
		string choice;
		cout << "to login as user enter 1:\n";
		cout << "to login as admin enter 2 :\n";
		cout << "to create user account enter 3:\n";
		cin >> choice;
		if (choice == "1")
		{
			while (true)
			{
				string id, pass;
				cout << "enter the id please \n";
				cin >> id;
				cout << "enter the password please \n";
				cin >> pass;
				bool found = 0;
				for (int i = 0; i < users.get_size(); i++)
				{
					if (users.get_elemnt(i).get_nid() == id && users.get_elemnt(i).get_password() == pass)
					{
						
						found = true;
						while (true)
						{
							cout << "1. Edit Information\n";
							cout << "2. Delete Information\n";
							cout << "3. to view all data \n";
							cout << "4. to logout \n";
							cin >> choice;
							if (choice == "1")
							{

								User x = users.get_elemnt(i);
								x.edit1();
								users.set_elemnt(x, i);

							}
							else if (choice == "2")
								users.delete_elemnt(i);
							else if (choice == "3")
								users.get_elemnt(i).view();
							else 
								break;
						}
						break;
					}
				}
				if (!found)
				{
					cout << "Ivalid Email Or Password\n";
					cout << "press 1 to try again" << endl;
					cin >> choice;
					if (choice == "1")
						continue;
					else
						break;
				}
				else break;
			}
		}
		else if (choice == "2")
		{
			bool found = false;
			Admin admin;
			while (true)
			{
				string username, pass;
				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> pass;
				if (admin.get_username() == username && admin.get_password() == pass)
				{
					found = true;
					break;
				}
				else
				{
					cout << "Wrong Username or Password\n";
					cout << "To try again press 1: ";
					cin >> choice;
					if (choice == "1")
						continue;
					else
						break;
				}
			}
			while (found)
			{
				cout << "1.View all users\n";
				cout << "2.View/Delete an User by using National ID\n";
				cout << "3.Delete all users\n";
				cout << "4.to show statistics \n";
				cout << "Else to Sign out\n";
				cout << "Enter Your Choice: ";
				
				int choice1;
				cin >> choice1;
				bool br = 1;
				switch (choice1)
				{
				case 1:
					for (int i = 0; i < users.get_size(); i++)
						users.get_elemnt(i).view();
					if (users.get_size() == 0)
						cout << "No Thing to View\n";
					br = 0;
					break;
				case 2:
					br = 0;
					while (true)
					{
						string natID;
						cout << "Enter National ID: ";
						cin >> natID;
						bool found = false;
						int i;
						for (i = 0; i < users.get_size(); i++)
						{
							if (users.get_elemnt(i).get_nid() == natID)
							{
								found = true;
								break;
							}
						}
						if (found == true)
						{
							users.get_elemnt(i).view();
							cout << "Do You Want to delete this user?\n";
							cout << "1.Yes\n2.No\n";
							cin >> choice1;
							if (choice1 == 1)
							{
								users.delete_elemnt(i);
								cout << "User Deleted\n";
								break;
							}
							else
								break;
						}
						else
						{
							cout << "National ID Not Found\n";
							cout << "press 1 to try agian\n";
							cin >> choice1;
							if (choice1 == 1)
								continue;
							else
								break;
						}
					}
					break;

				case 3:
					br = 0;
					users.clear();
					cout << "Users Deleted\n";
					break;
				case 4:
					br = 0;
					int sum = users.get_size();
					int two_doses = 0,one_doses = 0,zero_doses = 0;
					int num_of_egy = 0, num_of_nonegy = 0;
					zero_doses = waitinglist.length();
					for (int i = 0; i < users.get_size(); i++)
					{
						if (users.get_elemnt(i).get_vaccDoeses() == 1)
							one_doses++;
						else if (users.get_elemnt(i).get_vaccDoeses() == 2)
							two_doses++;
						if (users.get_elemnt(i).get_country() == "egypt" || users.get_elemnt(i).get_country() == "Egypt")
							num_of_egy++;
						else num_of_nonegy++;
					}
					cout << "the total number of people in system is :" << sum << endl;
					cout << "the number of egyptians in the system is : " << num_of_egy<<endl;
					cout << "percentage of egyptian people in the system is :" << (double)(num_of_egy * 100) / sum << "%" << endl;
					cout << "the number of non egyptians in the system is : " << num_of_nonegy << endl;
					cout << "percentage of non egyptian people in the system is :" << (double)(num_of_nonegy * 100) / sum << "%" << endl;
					cout << "the number of people in wating list : " << zero_doses << endl;
					cout << "the percentage of people in wating list : " << (double)(zero_doses * 100)/sum<<"%" << endl;
					cout << "the number of people took one dose : " << one_doses << endl;
					cout << "the percentage of people took one dose : " << (double)(one_doses * 100) / sum << "%" << endl;
					cout << "the number of people took two doses : " << one_doses << endl;
					cout << "the percentage of people took two doses : " << (double)(two_doses * 100) / sum << "%" << endl;
					cout << "the statistics of governs : \n";
					for (auto j : total_govern)
					{
						string x = j.first;
						cout << "the percantge of egyptians from " << x << " signed in the system is : " << (double)(j.second * 100) / num_of_egy << endl;
						cout << "the govern is : " << x << endl;
						cout << "the total number of members of system from " << x << " = " << j.second << endl;
						cout << zero_govern[x] << " of them in waiting list \n";
						cout << one_govern[x] << " of them  took one dose \n";
						cout << two_govern[x] << " of them took two doses \n";
						cout << "/////////////////////////////\n";

					}

					break;


				}
				if (br)
					found = 0;
				
			}
		}
		else if (choice == "3")
		{

		string info0[6];
		int info1[2];
		cout << "Enter Your National ID: ";
		cin >> info0[0];
		bool found = false;
		for (int i = 0; i < users.get_size(); i++)
			if (users.get_elemnt(i).get_nid() == info0[0])
			{
				found = true;
				cout << "This National ID already exist\n";
				break;
			}
		if (found)
			continue;
		cout << "Enter Your Name: ";
		cin >> info0[1];
		cout << "Enter Password: ";
		cin >> info0[2];
		cout << "Gender: ";
		cin >> info0[3];
		cout << "Country: ";
		cin >> info0[4];
		if (info0[4] == "Egypt" || info0[4] == "egypt")
		{
			cout << "Govenment: ";
			cin >> info0[5];
		 
		}
		cout << "Age: ";
		cin >> info1[0];
		while (true)
		{
			cout << "Vaccine Doses: ";
			cin >> info1[1];
			if (info1[1] >= 0 && info1[1] <= 2)
				break;
			cout << "invalid number please enter 0 or 1 or 2 :\n";
		}
		if(info0[4]=="egypt"||info0[4]=="Egypt")
		{
		total_govern[info0[5]]++;
		if (info1[1] == 0)
			zero_govern[info0[5]]++;
		else if (info1[1] == 1)
			one_govern[info0[5]]++;
		else two_govern[info0[5]]++;
		}
		
		User u(info0, info1);
		if (info1[1] == 0)
			waitinglist.push(u);
		users.push_back(u);
		cout << "Account has been created\n";
		}
	}
	return 0;
}