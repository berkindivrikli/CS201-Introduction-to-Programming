#include <iostream>
#include <vector>
#include <string>
#include "date.h"

class Sailor
{
	public:
		Sailor()
		{
            id = 0;
			name = "Jane Doe";
			age = 0;
			rank = 0;
		}
        Sailor(int i, string n, double a, double r){
            id = i;
            name = n;
            age = a;
            rank = r;
        }
        int getID();
        string getName();
        double getAge();
        double getRank();

	private:
		int id;
		string name;
		double age;
		double rank;
};

class Boat
{
	public:
		Boat()
		{
			id = 0;
			name = "Default";
			color = "Default";
		}
        Boat(int i, string n, string c){
            id = i;
            name = n;
            color = c;
        }
        int getID();
        string getName();
        string getColor();
    

	private:
		int id;
		string name;  
		string color;
};

class Reservation
{
	public:
		Reservation()
		{
			Sailor s;
			sailor = s;
			Boat b;
			boat = b;
			Date d(1,1,1900);
			resDate = d;
		}
        Reservation(Boat b, Sailor s, Date d){
            resDate = d;
            sailor = s;
            boat = b;
        }
        Sailor GetSailor();
        Boat GetBoat();
        Date GetDate();
    
		// Add here the Print function
        void Print();

	private:
		Date resDate;
		Sailor sailor;
		Boat boat;
};

class Reservations
{
	public:
		// Fill this part with the member functions
		// 1. Add a Reservation
    
        void AddReservation(Boat bot, Sailor person, Date time);
    
		// 2. Delete a Reservation
        bool DeleteReservations(Sailor sid, Boat bid, Date time);
        bool DeleteReservations(Sailor sid);
        bool DeleteReservations(Boat bid);
    
		// 3.1. Find a Reservation (sailor and boat ids are 0)
		// 3.2. Find a Reservation (only sailor id is 0)
		// 3.3. Find a Reservation (only boat id is 0)
    
        vector<Reservation> FindReservation(Sailor person, Date time);
        vector<Reservation> FindReservation(Boat bot, Date time);
        vector<Reservation> FindReservation(Date first, Date last);

	private:
		vector<Reservation> reservations;
	
};
