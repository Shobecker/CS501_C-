// **********************************************
// COSC 501 LAB #2
// Elias Becker
// PROGRAM-NAME: Lab2_1
//**********************************************

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 13, 2017, 8:28 PM
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
 string firstname;
 string lastname;
 string email;
 string city;
 string undergraduate_major;
 // need to implement something
 cout << "Enter your first name: ";
 cin >> firstname;
 cout << "Enter your last name: ";
 cin >> lastname;
 cout << "Enter your email address: ";
 cin >> email;
 cout << "Enter the city where you live: ";
 cin >> city;
 cout << "Enter your undergraduate major: ";
 cin >> undergraduate_major;
 cout <<"My name is " + firstname + " " + lastname + " and my email address is " + email + ". I'm living in " + city + ". As an undergraduate I majored in " + undergraduate_major + ".";
 
 return 0;
}

