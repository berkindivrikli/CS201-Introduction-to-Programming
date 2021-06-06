#include <stdio.h>
#include "Reservation.h"

using namespace std;

Date Reservation::GetDate(){
    return resDate;
}

Sailor Reservation::GetSailor(){
    return sailor;
}

Boat Reservation::GetBoat(){
    return boat;
}

int Boat::getID(){
    return id;
}

string Boat::getName(){
    return name;
}

string Boat::getColor(){
    return color;
}

int Sailor::getID(){
    return id;
}

string Sailor::getName(){
    return  name;
}

double Sailor::getAge(){
    return age;
}

double Sailor::getRank(){
    return rank;
}

void Reservation::Print(){
    cout << resDate.MonthName() << " " << resDate.Day() << " " << resDate.Year() << " -> " << sailor.getName() << "(" << sailor.getAge() << "," << sailor.getRank() << ") has reserved " << boat.getName() << "(" << boat.getColor() << ")" << endl;
}

void Reservations::AddReservation(Boat bot, Sailor person, Date time){
    Reservation yeni(bot, person, time);
    if (reservations.size() == 0) {
        reservations.push_back(yeni);
    }else{
        reservations.push_back(yeni);
        for (int i = reservations.size()-1; i > 0; i--) {
            if (reservations[i].GetDate() < reservations[i- 1].GetDate()) {
                Reservation temp = reservations[i-1];
                reservations[i-1] = reservations[i];
                reservations[i] = temp;
            }else{
                break;
            }
        }
        
        
    }
    
}


bool Reservations::DeleteReservations(Boat bid){
    vector<Reservation> yeni;
    bool result = false;
    Date date(0,0,0000);
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetBoat().getID() != bid.getID() || reservations[i].GetDate() == date) {
            yeni.push_back(reservations[i]);
        }
    }
    if (yeni.size() < reservations.size()) {
        reservations = yeni;
        result = true;
    }
    return result;
}

bool Reservations::DeleteReservations(Sailor sid){
    vector<Reservation> yeni;
    bool result = false;
    Date date(0,0,0000);
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetSailor().getID() != sid.getID() || reservations[i].GetDate() == date) {
            yeni.push_back(reservations[i]);
        }
    }
    if (yeni.size() < reservations.size()) {
        reservations = yeni;
        result = true;
    }
    return result;
}

bool Reservations::DeleteReservations(Sailor sid, Boat bid, Date time){
    vector<Reservation> yeni;
    bool result = false;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetSailor().getID() != sid.getID() || reservations[i].GetDate() != time || reservations[i].GetBoat().getID() != bid.getID()) {
            yeni.push_back(reservations[i]);
        }
    }
    if (yeni.size() < reservations.size()) {
        reservations = yeni;
        result = true;
    }
    return result;
}


vector<Reservation> Reservations::FindReservation(Date first, Date last){
    vector<Reservation> results;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetDate() >= first && reservations[i].GetDate() <= last) {
            results.push_back(reservations[i]);
        }
    }
    return results;
}

vector<Reservation> Reservations::FindReservation(Boat bot, Date time){
    vector<Reservation> results;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetDate() == time && reservations[i].GetBoat().getID() == bot.getID()) {
            results.push_back(reservations[i]);
        }
    }
    return results;
}

vector<Reservation> Reservations::FindReservation(Sailor person, Date time){
    vector<Reservation> results;
    for (int i = 0; i < reservations.size(); i++) {
        if (reservations[i].GetDate() == time && reservations[i].GetSailor().getID() == person.getID()) {
            results.push_back(reservations[i]);
        }
    }
    return results;
}





