/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on September 27, 2017, 6:59 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int input;
    cout << "1. March 21 – April 19\n"
            "2. April 20 – May 20\n"
            "3. May 21 – June 21\n"
            "4. June 22 – July 22\n"
            "5. July 23 – August 22\n"
            "6. August 23 – September 22\n"
            "7. September 23 – October 22\n"
            "8. October 23 – November 21\n"
            "9. November 22 – December 21\n"
            "10. December 22 – January 19\n"
            "11. January 20 – February 18\n"
            "12. February 19 – March 20\n"
            "What is your date of birth? (Please choose a date range)" << endl;
    
    cin >> input;
    switch (input) {
        case 1:
            cout << "Your Horoscope Sign -> Aries" << endl;
            break;
        case 2:
            cout << "Your Horoscope Sign -> Taurus" << endl;
            break;
        case 3:
            cout << "Your Horoscope Sign -> Gemini" << endl;
            break;
        case 4:
            cout << "Your Horoscope Sign -> Cancer" << endl;
            break;
        case 5:
            cout << "Your Horoscope Sign -> Leo" << endl;
            break;
        case 6:
            cout << "Your Horoscope Sign -> Virgo" << endl;
            break;
        case 7:
            cout << "Your Horoscope Sign -> Libra" << endl;
            break;
        case 8:
            cout << "Your Horoscope Sign -> Scorpio" << endl;
            break;
        case 9:
            cout << "Your Horoscope Sign -> Sagittarius" << endl;
            break;
        case 10:
            cout << "Your Horoscope Sign -> capricorn" << endl;
            break;
        case 11:
            cout << "Your Horoscope Sign -> Aquarius" << endl;
            break;
        case 12:
            cout << "Your Horoscope Sign -> Pisces" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }

    return 0;
}

