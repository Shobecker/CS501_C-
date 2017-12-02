/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on November 8, 2017, 7:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
void sort(char a[], int number_used);
int index_of_smallest(const char a[], int start_index, int number_used);
void swap_values(char& v1, char& v2);

int main(int argc, char** argv) {
    ifstream fin("Lab9_2input.txt");
    const int SIZE = 1000;
    int checker, wordCount = -1, counter = 0, count[SIZE] = {0}, count2[SIZE];
    char input, characters[SIZE] = {0}, charList[SIZE] = {0}, alph[25];
    string text;
    bool match = false;

    if (fin.fail()) {
        cout << "File failed to upload" << endl;
        return -1;
    }

    //This loop is to count the number of words in the file
    while (!fin.eof()) {
        fin.get(input);

        if (input == ' ' || input == '\n') {
            wordCount++;
        }

        //this if statement checks input for a-z character and changes upper to lower case characters
        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
            if (input >= 'A' && input <= 'Z') {
                input = input - 'A' + 'a';
            }

            //checking array for repeating numbers.
            for (int i = 0; i < SIZE; i++) {
                if (characters[i] == input) {
                    match = true;
                    checker = i;
                }
            }

            //if there is no match create a new counter equal to 1. 
            if (!match) {
                characters[counter] = input;
                count[counter] = 1;
            } else if (match) { //if repeating number is found the counter for that number is increased by 1. 
                count[checker] = count[checker] + 1;
            }
            match = false;
            counter++;
        }
    }

    cout << wordCount << " words" << endl;

    //sort (characters, SIZE);
    int num = 0;
    for (int i = 0; i < SIZE; i++) {
        if (characters[i] >= 'a' || characters[i] <= 'z') {
            alph[num] = characters[i];
            count2[num] = count[i];
            num++;
        }
    }
    
//    sort(alph, 25);
//   
//    for (int i = 0; i < 26; i++) {
//        cout << alph[i] << "     " << count2[i] << endl;
//    }
//    
    for (int i = 0; i < SIZE; i++) {
        if (characters[i] != 0) {
            cout << characters[i] << "     " << count[i] << endl;
        }
    }

    fin.close();
    return 0;
}

void swap_values(char& v1, char& v2) {
    char temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_of_smallest(const char a[], int start_index, int number_used) {
    char min = a[start_index];
    int index_of_min = start_index;
    for (int index = start_index +1; index<number_used; index++){
        min = a[index];
        index_of_min = index;
    }
    return index_of_min;        
}

void sort(char a[], int number_used) {
    int index_of_next_smallest;
    for (int index = 0; index < number_used -1; index++){
        index_of_next_smallest = index_of_smallest(a, index, number_used);
        swap_values(a[index], a[index_of_next_smallest]);
    }
}