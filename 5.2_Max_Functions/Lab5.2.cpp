/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on October 4, 2017, 7:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;
double max2(double a, double b);
double max3(double a, double b, double c);
double max4(double a, double b, double c, double d);

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Max2(10.0, 20.0) = " << max2(10.0, 20.0) << endl;
    cout << "Max3(11.5, 21.2, 5.3) = " << max3(11.5, 21.2, 5.3) << endl;
    cout << "Max4(1.8, 2.2, 1.7, 2.1) = " << max4(1.8, 2.2, 1.7, 2.1) << endl;
    return 0;
}

double max2(double a, double b) {
    if (a > b)
        return a;
    else
        return b;
}

double max3(double a, double b, double c) {
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

double max4(double a, double b, double c, double d) {
    if (a > b && a > c && a > d)
        return a;
    else if (b > a && b > c && b > d)
        return b;
    else if (c > a && c > b && c > d)
        return c;
    else
        return d;
}