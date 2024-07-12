#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Hotel class
class Hotel {
public:
    string name;
    int numRooms;
    vector<bool> availability;

    Hotel(string n, int rooms) : name(n), numRooms(rooms), availability(rooms, true) {}

    bool checkAvailability(int date) {
        return availability[date];
    }

    bool reserveRoom(int date) {
        if (availability[date]) {
            availability[date] = false;
            return true;
        }
        return false;
    }

    void cancelReservation(int date) {
        availability[date] = true;
    }
};

// Hotel management system
class HotelReservationAPI {
private:
    unordered_map<string, Hotel> hotels;

public:
    void addHotel(string name, int numRooms) {
        hotels[name] = Hotel(name, numRooms);
    }

    bool checkAvailability(string hotelName, int date) {
        if (hotels.find(hotelName) != hotels.end()) {
            return hotels[hotelName].checkAvailability(date);
        }
        return false;
    }

    bool reserveRoom(string hotelName, int date) {
        if (hotels.find(hotelName) != hotels.end()) {
            return hotels[hotelName].reserveRoom(date);
        }
        return false;
    }

    void cancelReservation(string hotelName, int date) {
        if (hotels.find(hotelName) != hotels.end()) {
            hotels[hotelName].cancelReservation(date);
        }
    }
};

int main() {
    HotelReservationAPI api;
    api.addHotel("Hotel A", 50);
    api.addHotel("Hotel B", 30);

    if (api.checkAvailability("Hotel A", 10)) {
        if (api.reserveRoom("Hotel A", 10)) {
            cout << "Room reserved at Hotel A on date 10." << endl;
        } else {
            cout << "Room reservation failed at Hotel A on date 10." << endl;
        }
    } else {
        cout << "No rooms available at Hotel A on date 10." << endl;
    }

    api.cancelReservation("Hotel A", 10);
    cout << "Reservation cancelled at Hotel A on date 10." << endl;

    return 0;
}