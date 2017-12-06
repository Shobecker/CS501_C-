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

    cout << "ID   Total Earnings   Tax W/H    Deductions   Taxable Income   Tax" << endl;
    user1.printInfo();
    user2.printInfo();
    user3.printInfo();
    user4.printInfo();
    user5.printInfo();

    return 0;
}

TaxAccountant::TaxAccountant(int customerID, double totalEarnings, double taxWH, double deductions) // class constructor
: customerID(customerID), totalEarnings(totalEarnings), taxWH(taxWH), deductions(deductions), taxableIncome(totalEarnings - deductions) //memberVariable(constructor of class)
{
    //taxableIncome = totalEarnings - deductions;
    if (taxableIncome <= 10000) {
        tax = 0.0;
    } else if (taxableIncome > 10000 && taxableIncome <= 20000) {
        tax = ((taxableIncome - 10000) * 0.15);
    } else if (taxableIncome > 20000 && taxableIncome <= 40000) {
        tax = ((10000) * 0.15) + ((taxableIncome - 20000)* 0.20);
    } else {
        tax = (10000) * 0.15 + (20000) * 0.20 + (taxableIncome - 40000) * 0.30;
    }
}

void TaxAccountant::printInfo() {
    cout << customerID << "  $" << totalEarnings << "           $" << taxWH << "     $" << deductions << "        $" << taxableIncome << "          $" << tax << endl << customerID << " will receive a tax refund of $" << (taxWH - tax) << endl << endl;
}