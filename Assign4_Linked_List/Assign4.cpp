/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Elias
 *
 * Created on December 7, 2017, 8:22 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Song {
    string title;
    string artist;
    Song *next;
};

typedef Song* SongPtr;

void initializeSonglist(SongPtr& head);
void showSonglist(SongPtr head);
void insertSong(SongPtr& head, string, string);
void deleteSong(SongPtr& head, int);

int main() {
    int input, position;
    string title, artist;
    SongPtr head = NULL;
    initializeSonglist(head);

    while (true) {
        showSonglist(head);
        cout << endl;
        cout << "Please select a menu:" << endl;
        cout << "1. Insert a song" << endl;
        cout << "2. Delete a song" << endl;
        cout << "3. Quit" << endl;
        cin >> input;

        if (input == 1) {
            cout << "Enter the title of the song:" << endl;
            cin.ignore();
            getline(cin, title);
            cout << "Enter the artist of the song" << endl;
            getline(cin, artist);
            insertSong(head, title, artist);
        } else if (input == 2) {
            cout << "Enter the position of the song:" << endl;
            cin >> position;
            deleteSong(head, position);
        } else if (input == 3) {
            break;
        } else {
            cout << "input invalid" << endl;
        }
    }

    return 0;
}

void initializeSonglist(SongPtr & head) {
    SongPtr temp;
    string song, title, artist;
    ifstream file("songlist.txt");

    if (file.fail()) {
        cout << "File open failed." << endl;
        exit(1);
    }

    while (getline(file, song)) {
        istringstream iss(song);
        getline(iss, title, '\t');
        getline(iss, artist, '\r');

        SongPtr item = new Song;
        item->title = title;
        item->artist = artist;
        item->next = NULL;

        if (head == NULL) {
            head = item;
            temp = head;
        } else {
            temp->next = item;
            temp = temp->next;
        }
    }
    file.close();
}

void showSonglist(SongPtr head) {
    SongPtr temp = head;
    int i = 1;
    cout << endl << "Song list: " << endl;
    while (temp != NULL) {
        cout << i++ << ": " << temp->title << " - " << temp->artist << endl;
        temp = temp->next;
    }
}

void insertSong(SongPtr& head, string title, string artist) {
    Song* item = new Song;
    Song* temp = head;

    item->title = title;
    item->artist = artist;
    item->next = NULL;

    if (head == NULL)
        head = item;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = item;
};

void deleteSong(SongPtr& head, int position) {
    Song* discard = head, *prev = NULL;

    if (position == 1) {
        head = head->next;
    } else {
        for (int i = 1; i < position; i++) {
            prev = discard;
            discard = discard->next;
        }
        prev->next = discard->next;
    }
    delete discard;
};