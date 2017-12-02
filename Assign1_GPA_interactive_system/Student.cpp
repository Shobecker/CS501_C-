/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Student.cpp
 * Author: Elias
 * 
 * Created on October 2, 2017, 2:59 PM
 */

#include "Student.h"

Student::Student() {
}

Student::Student(string idNumber, string lastName, string firstName, char middleInt, string phoneNumber, char gender, string classLevel, int fallCredits, int numberOfSpringCourses) {
    newIDNumber = idNumber;
    newLastName = lastName;
    newFirstName = firstName;
    newMiddleInitial = middleInt;
    newPhoneNumber = phoneNumber;
    newGender = gender;
    newClassLevel = classLevel;
    newFallCredits = fallCredits;
    newNumberOfSpringCourses = numberOfSpringCourses;
    
    newCredit = 0;
    newGPAFall = 0.0;
    newGPASpring = 0.0;
    newTotalGPA = 0.0;
}

Student::addCourse(string course, int credit, char grade) {
    newCourse = course;
    newCredit = credit;
    newGrade = grade;
    if (grade != 'w') {
        newFallCredits += credit;
    }
}

Student::~Student() {
}

string Student::getIDNumber() const {
    return newIDNumber;
}

string Student::getLastName() const {
    return newLastName;
}

string Student::getFirstName() const {
    return newFirstName;
}

char Student::getMiddleInitial() const {
    return newMiddleInitial;
}

string Student::getPhoneNumber() const {
    return newPhoneNumber;
}

char Student::getGender() const {
    return newGender;
}

string Student::getClassLevel() const {
    return newClassLevel;
}

int Student::getFallCredits() const {
    return newFallCredits;
}

int Student::getNumberOfSpringCourses() const {
    return newNumberOfSpringCourses;
}

//double Student::getGPAFall() {
//
//    return newGPAFall;
//}
//
//double Student::getGPASpring() {
//    return newGPASpring;
//}
//
//double Student::getGPAFall() {
//    return newTotalGPA;
//}
// Member functions definitions

//void Student::setIdNumber(string studentID) {
//    this->newIDNumber = studentID;
//}
//
//void Student::setLastName(string studentLastName) {
//    this->lastName = studentLastName;
//}
//
//void Student::setFirstName(string studentFirstName) {
//    this->firstName = studentFirstName;
//}
//
//void Student::setMiddleInitial(char studentMiddleInitial) {
//    this->middleInitial = studentMiddleInitial;
//}
//
//void Student::setPhoneNumber(string studentPhoneNumber) {
//    this->phoneNumber = studentPhoneNumber;
//}
//
//void Student::setGender(char studentGender) {
//    this->gender = studentGender;
//}
//
//void Student::setYear(string studentYear) {
//    this->classLevel = studentYear;
//}

//void Student::setCourseCreditGrade(string course, int credit, char grade) {
//    this->course = course;
//    this->credit = credit;
//    this->grade = grade;
//    this->courses.push_back(course);
//    this->credits.push_back(credit);
//    this->grades.push_back(grade);
//}

//void Student::printStudent(vector<string> courses) {
//    for (int x = 0; x != courses.size(); ++x) {
//        cout << courses[x] << "- subscripting" << endl;
//        cout << courses.at(x) << "- calling at member" << endl;
//    }
//}
//
//void Student::printClasses(vector<int> credits) {
//    for (int x = 0; x != credits.size(); ++x) {
//        cout << credits[x] << "- subscripting" << endl;
//        cout << credits.at(x) << "- calling at member" << endl;
//    }
//}
//
//void Student::printVector(vector<int> example) {
//    std::copy(example.begin(), example.end(), std::ostream_iterator<int>(std::cout, " "));
//}

//int Student::gpaCalc(vector<int> credits, vector<int> grades) {
//    for (int x = 0; x != credits.size(); ++x) {
//        cout << credits[x] << "- subscripting" << endl;
//        cout << credits.at(x) << "- calling at member" << endl;
//    }
//}

//Student::Student() {
//    string idNumber, lastName, firstName, phoneNumber, classLevel, course;
//    char gender, middleInitial, grade;
//    int newCredit = 0;
//    double newGPA =0.0;
//    std::vector<string> courses;
//    std::vector<int> credits;
//    std::vector<char> grades;
//
//
//    // Member functions declaration
//    void setIdNumber(string id);
//    void setLastName(string lastName);
//    void setFirstName(string firstName);
//    void setMiddleInitial(char middleInitial);
//    void setPhoneNumber(string number);
//    void setGender(char gend);
//    void setYear(string studentYear);
//    void setCourseCreditGrade(string course, int credit, char grade);
//    //    int gpaCalc(vector<int> credits, vector<int> grades);
//    //    void printStudent(vector<string> courses);
//    //    void printClasses(vector<int> credits);
//    //    void printVector(vector<int> example);
//};