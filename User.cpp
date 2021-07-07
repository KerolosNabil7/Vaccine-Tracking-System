#include "User.h"
#include "array_list.cpp"
User::User()
{
    age = 0;
    isEGYP = 0;
}
User::User(std::string data[], int data1[])
{
    nid = data[0];
    name = data[1];
    password = data[2];
    gender = data[3];
    country = data[4];
    govern = data[5];
    age = data1[0];
    vaccDoses = data1[1];
}

string User::get_name() {
    return name;
}
string User::get_nid() {
    return nid;
}
string User::get_password() {
    return password;
}
string User::get_gender() {
    return gender;
}
string User::get_country() {
    return country;
}
string User::get_govern() {
    return govern;
}
void User::edit1()
{
    
    while (true)
    {
        cout << "to edit the name enter : 1 \n";
        cout << "to edit the password   enter : 2\n";
        cout << "to edit the age enter : 3 \n";
        cout << "to edit the number of vaccine doses enter : 4\n";
        cout << "to edit the country  enter : 5\n";
        if(get_isEGYP())
        cout << "to edit the  govern enter : 6 \n";
        cout << "to exit enter any number \n";
        string choice;
        cin >> choice;
        if (choice == "1")
        {
            string newname;
            cout << "enter the name \n";
            cin >> newname;
            this->name = newname;
            cout << "the new name is : " << this->name << " " << name << endl;
            set_name(newname);
            cout << "the name is changed \n ";
        }
        else if (choice == "2")
        {
            string pass1, pass2;
            while (true)
            {
                cout << "enter the password : ";
                cin >> pass1;
                cout << "confirm the password : ";
                cin >> pass2;
                if (pass1 == pass2)
                {
                    password = pass1;
                    cout << "the password changed succfuly \n";
                    break;
                }
                else
                {
                    cout << "the two password are diffrent \n ";
                    cout << "enter 1 to try again \n";
                    string ch;
                    cin >> ch;
                    if (ch != "1")
                    {
                        cout << "the password not changed \n ";
                        break;
                    }
                }
            }
        }
        else if (choice == "3")
        {
            cout << "enter the age : ";
            int newage;
            cin >> newage;
            this->age = newage;
        }
        else if (choice == "4")
        {
            cout << "enter the new numper of vaccine doses : ";
            cin >> vaccDoses;
        }
        else if (choice == "5")
        {
            string count;
            cout << "to enter egypt enter 1 else enter the name of country : ";
            cin >> count;
            if (count == "1")
                country = "Egypt";
            else country = count;
        }
        else if (get_country() == "Egypt" && choice == "6")
        {
            cout << "enter the new govern : ";
            cin >> govern;
        }
        else
        {
            break;
        }
    }

}

int User::get_age() {
    return age;
}
int User::get_vaccDoeses() {
    return vaccDoses;
}
bool User::get_isEGYP() {
    return isEGYP;
}

void User::view()
{
    cout << "the data of user is : \n";
    cout << "the national id is : " << get_nid() << endl;
    cout << "the password is : " << get_password() << endl;
    cout << "the user name is : " << get_name() << endl;
    cout << "the gender is : " << get_gender() << endl;
    cout << "the country is : " << get_country() << endl;
    cout << "the govern : " << get_govern() << endl;
    cout << "the age is : " << get_age() << endl;
    cout << "the number of vaccine doses : " << get_vaccDoeses() << endl;
    cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n";
}


void User::set_name(string newName)
{
    this->name = newName;
}


User::~User()
{
}