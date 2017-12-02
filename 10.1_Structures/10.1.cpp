/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 15, 2017, 7:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    string fname;
    string lname;
    Date birthday;
};

int calculateAge(Date dob, Date today); //return the current age
void printInfo(Person p); // print personal info

int main(int argc, char** argv) {
    Person p;
    Date today = {11, 15, 2017};
    cout << "First name: ";
    cin >> p.fname;
    cout << "Last name: ";
    cin >> p.lname;
    cout << "Birth year: ";
    cin >> p.birthday.year;
    cout << "Birth month: ";
    cin >> p.birthday.month;
    cout << "Birth day: ";
    cin >> p.birthday.day;


    printInfo(p);
    cout << "Age: " << calculateAge(p.birthday, today);

    return 0;
}

int calculateAge(Date dob, Date today) {
    int age;
    age = today.year - dob.year;
    if (dob.month < today.month) {
        age--;
    } else if (dob.month == today.month && dob.day < today.day) {
        age--;
    }
    return age;
}

void printInfo(Person p) {
    cout << "Name: " << p.fname << " " << p.lname << endl;
}

