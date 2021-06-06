#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "date.h"
#include "strutils.h"
#include "Reservation.h"


using namespace std;

int main() {
    
    string filename;
    string boats = "Boats.txt", sailors = "Sailors.txt";
    
    cout << "Enter filename for reservation database: ";
    cin >> filename;
    
    ifstream file, boatfile, sailorfile;
    
    boatfile.open(boats.c_str());
    sailorfile.open(sailors.c_str());
    
    file.open(filename.c_str());
    if (file.fail()) {
        cout << "Cannot open the files. Exiting..." << endl;
    }else{
        
        Reservations myRes;
        string line, boatline, linesail;
        getline(boatfile, boatline);
        vector<Boat> boats;
        while (getline(boatfile, boatline)) {
            istringstream ss(boatline);
            int botid;
            string isim, renk;
            ss >> botid >> isim >> renk;
            Boat temp(botid, isim, renk);
            boats.push_back(temp);
        }
        
        
        getline(sailorfile, linesail);
        vector<Sailor> sailors;
        while (getline(sailorfile, linesail)) {
            istringstream ll(linesail);
            string isim;
            int saild;
            double ran, old;
            ll >> saild >> isim >> ran >> old;
            Sailor temp(saild, isim, old , ran);
            sailors.push_back(temp);
        }
        
// sailor id , boat id , date
        while (getline(file, line)) {
            istringstream ss(line);
            char first;
            int one, two;
            string dateOne, dateTwo;
            ss >> first >> one >> two;
            if (first == 'A') {
                ss >> dateOne;
                Sailor tempOne;
                for (int i = 0; i < sailors.size(); i++) {
                    if (sailors[i].getID() == one) {
                        tempOne = sailors[i];
                        break;
                    }
                }
                Boat tempBoat;
                for (int i = 0; i < boats.size(); i++) {
                    if (boats[i].getID() == two) {
                        tempBoat = boats[i];
                        break;
                    }
                }
                int year, mon, da;
                year = stoi(dateOne.substr(0,4));
                mon = stoi(dateOne.substr(5,7));
                da = stoi(dateOne.substr(8));
                Date tim(mon, da, year);
                myRes.AddReservation(tempBoat, tempOne, tim);
            }else if (first == 'D'){
                ss >> dateOne;
                int year, mon, da;
                year = stoi(dateOne.substr(0,4));
                mon = stoi(dateOne.substr(5,7));
                da = stoi(dateOne.substr(8));
                Date tim(mon, da, year);
                if (one == 0) {
                    Boat tempBoat;
                    for (int i = 0; i < boats.size(); i++) {
                        if (boats[i].getID() == two) {
                            tempBoat = boats[i];
                            break;
                        }
                    }
                    bool flag;
                    flag = myRes.DeleteReservations(tempBoat);
                    if (flag == false) {
                        cout << "Error: Could not delete reservation for boat id " << two << endl;
                        cout << endl;
                    }
                }else if (two == 0){
                    Sailor tempOne;
                    for (int i = 0; i < sailors.size(); i++) {
                        if (sailors[i].getID() == one) {
                            tempOne = sailors[i];
                            break;
                        }
                    }
                    bool flag = myRes.DeleteReservations(tempOne);
                    if (flag == false) {
                        cout << "Error: Could not delete reservation for sailor id " << one << endl;
                        cout << endl;
                    }
                    
                }else{
                    Sailor tempOne;
                    for (int i = 0; i < sailors.size(); i++) {
                        if (sailors[i].getID() == one) {
                            tempOne = sailors[i];
                            break;
                        }
                    }
                    Boat tempBoat;
                    for (int i = 0; i < boats.size(); i++) {
                        if (boats[i].getID() == two) {
                            tempBoat = boats[i];
                            break;
                        }
                    }
                    bool flag;
                    flag = myRes.DeleteReservations(tempOne, tempBoat, tim);
                    if (flag == false) {
                        cout << "Error: Could not delete reservation \"" << one << " " << two << " " << dateOne << "\"" << endl;
                        cout << endl;
                    }
                }
//                statement
                
            }else if (first == 'F'){
//                statement
                if (one == 0 && two == 0) {
                    ss >> dateOne >> dateTwo;
                    int yOne, mOne, dOne, yTwo, mTwo, dTwo;
                    yOne = stoi(dateOne.substr(0,4));
                    mOne = stoi(dateOne.substr(5,7));
                    dOne = stoi(dateOne.substr(8));
                    Date timOne(mOne, dOne, yOne);
                    yTwo = stoi(dateTwo.substr(0,4));
                    mTwo = stoi(dateTwo.substr(5,7));
                    dTwo = stoi(dateTwo.substr(8));
                    Date timTwo(mTwo, dTwo, yOne);
                    vector<Reservation> res;
                    res = myRes.FindReservation(timOne, timTwo);
                    if (res.size() != 0) {
                        cout << "Find Results:" << endl;
                        for (int i = 0; i < res.size(); i++) {
                            cout << res[i].GetDate().MonthName() << " " << res[i].GetDate().Day() << " " << res[i].GetDate().Year() << " -> " << res[i].GetSailor().getName() << "(" << res[i].GetSailor().getAge() << "," << res[i].GetSailor().getRank() << ") has reserved " << UpperString(res[i].GetBoat().getName()) << "(" << UpperString(res[i].GetBoat().getColor()) << ")" << endl;
                            cout << endl;
//                            February 19 2014 -> Dustin(45,7.1) has reserved INTERLAKE(BLUE)
                        }
                    }else{
                        cout << "Find Results:" << endl;
                        cout << "Error: No matching reservation found between dates " << dateOne << " & " << dateTwo << endl;
                        cout << endl;
                    }
//                    find cout kısmı
                    // sailor id , boat id , date
                }else if (one == 0 && two != 0){
                    ss >> dateOne;
                    Boat tempBoat;
                    for (int i = 0; i < boats.size(); i++) {
                        if (boats[i].getID() == two) {
                            tempBoat = boats[i];
                            break;
                        }
                    }
                    int year, mon, da;
                    year = stoi(dateOne.substr(0,4));
                    mon = stoi(dateOne.substr(5,7));
                    da = stoi(dateOne.substr(8));
                    Date tim(mon, da, year);
                    vector<Reservation> res;
                    res = myRes.FindReservation(tempBoat, tim);
                    if (res.size() != 0) {
                        cout << "Find Results:" << endl;
                        for (int i = 0; i < res.size(); i++) {
                            cout << res[i].GetDate().MonthName() << " " << res[i].GetDate().Day() << " " << res[i].GetDate().Year() << " -> " << res[i].GetSailor().getName() << "(" << res[i].GetSailor().getAge() << "," << res[i].GetSailor().getRank() << ") has reserved " << UpperString(res[i].GetBoat().getName()) << "(" << UpperString(res[i].GetBoat().getColor()) << ")" << endl;
                            cout << endl;
                            //                            February 19 2014 -> Dustin(45,7.1) has reserved INTERLAKE(BLUE)
                        }
                    }else{
                        cout << "Find Results:" << endl;
                        cout << "Error: No matching reservation found for boat id " << two << " on " << dateOne << endl;
                        cout << endl;
                    }
                }else if (two == 0 && one != 0){
                    ss >> dateOne;
                    int year, mon, da;
                    year = stoi(dateOne.substr(0,4));
                    mon = stoi(dateOne.substr(5,7));
                    da = stoi(dateOne.substr(8));
                    Date tim(mon, da, year);
                    Sailor tempOne;
                    for (int i = 0; i < sailors.size(); i++) {
                        if (sailors[i].getID() == one) {
                            tempOne = sailors[i];
                            break;
                        }
                    }
                    vector<Reservation> res;
                    res = myRes.FindReservation(tempOne, tim);
                    if (res.size() != 0) {
                        cout << "Find Results:" << endl;
                        for (int i = 0; i < res.size(); i++) {
                            cout << res[i].GetDate().MonthName() << " " << res[i].GetDate().Day() << " " << res[i].GetDate().Year() << " -> " << res[i].GetSailor().getName() << "(" << res[i].GetSailor().getAge() << "," << res[i].GetSailor().getRank() << ") has reserved " << UpperString(res[i].GetBoat().getName()) << "(" << UpperString(res[i].GetBoat().getColor()) << ")" << endl;
                            cout << endl;
                            //                            February 19 2014 -> Dustin(45,7.1) has reserved INTERLAKE(BLUE)
                        }
                    }else{
                        cout << "Find Results:" << endl;
                        cout << "Error: No matching reservation found for sailor id " << one << " on " << dateOne << endl;
                        cout << endl;
                    }
                }
            }
        }
        
    }
    
    
    return 0;
}


