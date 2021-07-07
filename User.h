#pragma once
#include <string>
#include<iostream>
using namespace std;

class User
{
private:
    string name, nid, password, gender, country, govern;
    int age = 0;
    int vaccDoses =0;
    bool isEGYP = false;
public:
    User();
    User(std::string data[], int data1[]);
    string get_name();
    string get_nid();
    string get_password();
    string get_gender();
    string get_country();
    string get_govern();
    void edit1();
    int get_age();
    int get_vaccDoeses();
    bool get_isEGYP();
    void deleteUser();
    void view();
    void set_name(string);
    ~User();
};