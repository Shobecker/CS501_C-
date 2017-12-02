/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 29, 2017, 7:12 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class TaxAccountant {
private:
    int customerID;
    double totalEarnings;
    double taxWH;
    double deductions;
    double taxableIncome;
    double tax;
public:
    TaxAccountant(int customerID, double totalEarnings, double taxWH, double deductions);
    void printInfo();
};

/*
 * 
 */
int main(int argc, char** argv) {
    TaxAccountant user1(101, 65000, 12000, 5000);
    TaxAccountant user2(102, 12000, 2100, 3000);
    TaxAccountant user3(103, 24500, 2000, 0);
    TaxAccountant user4(104, 38775, 8965, 2575);
    TaxAccountant user5(105, 17680, 2350, 1300);

    cout << "ID   Total Earnings   Tax W/H    Deductions   Taxable Income" << endl;
    user1.printInfo();
    return 0;
}

TaxAccountant::TaxAccountant(int customerID, double totalEarnings, double taxWH, double deductions) // class constructor
: customerID(customerID), totalEarnings(totalEarnings), taxWH(taxWH), deductions(deductions), taxableIncome(totalEarnings - deductions) //memberVariable(constructor of class)
{
    //taxableIncome = totalEarnings - deductions;
    tax = 0.0;
}

void TaxAccountant::printInfo() {
    cout << customerID << " $" << totalEarnings << " $" << taxWH << " $" << deductions << " $" << taxableIncome << " $" << tax << endl;
}