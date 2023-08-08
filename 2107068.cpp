#include <iostream>
#include <string>

using namespace std;

class Flight {
public:

    Flight(){}          //DEFAULT CONSTRUCTOR

    int flightID;
    string flightNumber;
    string departureCity;
    string destinationCity;
    int availableSeats;

    Flight(int id, const string& number, const string& departure, const string& destination, int seats)
        : flightID(id), flightNumber(number), departureCity(departure), destinationCity(destination), availableSeats(seats) {}
};

class Passenger {
public:

    Passenger(){}       //DEFAULT CONSTRUCTOR

    int passengerID;
    string name;
    int age;
    int bookings[10];
    int numBookings;

    Passenger(int id, const string& n, int a) : passengerID(id), name(n), age(a), numBookings(0) {}

    void bookFlight(int flightID);
    friend void cancelBooking(Passenger& passenger, int bookingID);         //FRIEND FUNCTION
};

class Booking {
public:
    int bookingID;
    int passengerID;
    int flightID;

    Booking(int id, int passengerID, int flightID) : bookingID(id), passengerID(passengerID), flightID(flightID) {}
    void displayBookingDetails();
};

void Passenger::bookFlight(int flightID) {
    if (numBookings >= 10) {
        cout << "Booking limit reached for passenger " << name << ". Cannot book more flights.\n";
        return;
    }

    bookings[numBookings] = flightID;
    numBookings++;
}

void cancelBooking(Passenger& passenger, int bookingID) {
    int foundIndex = -1;
    for (int i = 0; i < passenger.numBookings; i++) {
        if (passenger.bookings[i] == bookingID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Booking ID " << bookingID << " not found for passenger " << passenger.name << ". Cancellation failed.\n";
        return;
    }

    // Removing the booking and shifting the remaining booking seats
    for (int i = foundIndex; i < passenger.numBookings - 1; i++) {
        passenger.bookings[i] = passenger.bookings[i + 1];
    }
    passenger.numBookings--;

    cout << "Booking ID " << bookingID << " cancelled successfully for passenger " << passenger.name << ".\n";
}

void Booking::displayBookingDetails() {     //function to display booking details
    cout << "Booking ID: " << bookingID << ", Passenger ID: " << passengerID << ", Flight ID: " << flightID << "\n";
}

class AirlineSystem {
public:
    Flight flights[20];
    int numFlights;
    Passenger passengers[20];
    int numPassengers;

    AirlineSystem() : numFlights(0), numPassengers(0) {}

    void addFlight(int id, const string& number, const string& departure, const string& destination, int seats);
    void addPassenger(int id, const string& name, int age);
    void displayAllFlights();
    friend void bookFlight(AirlineSystem& system, int passengerID, int flightID);
};

void AirlineSystem::addFlight(int id, const string& number, const string& departure, const string& destination, int seats) {
    if (numFlights >= 20) {
        cout << "Flight limit reached. Cannot add more flights.\n";
        return;
    }

    flights[numFlights] = Flight(id, number, departure, destination, seats);
    numFlights++;
}

void AirlineSystem::addPassenger(int id, const string& name, int age) {
    if (numPassengers >= 20) {
        cout << "Passenger limit reached. Cannot add more passengers.\n";
        return;
    }

    passengers[numPassengers] = Passenger(id, name, age);
    numPassengers++;
}

void AirlineSystem::displayAllFlights() {       //Display all available flights
    cout << "All Flights:\n";
    for (int i = 0; i < numFlights; i++) {
        cout << "Flight ID: " << flights[i].flightID << ", Flight Number: " <<
        flights[i].flightNumber << ", Departure City: " << flights[i].departureCity <<
        ", Destination City: " << flights[i].destinationCity << ", Available Seats: "
        << flights[i].availableSeats << "\n";

    cout<<"\n";
    }
}

void bookFlight(AirlineSystem& system, int passengerID, int flightID) {     //function that books flights if it matches with the passenger ID
    int passengerIndex = -1;
    for (int i = 0; i < system.numPassengers; i++) {
        if (system.passengers[i].passengerID == passengerID) {
            passengerIndex = i;
            break;
        }
    }

    if (passengerIndex == -1) {
        cout << "Passenger ID " << passengerID << " not found. Booking failed.\n";
        return;
    }

    int flightIndex = -1;
    for (int i = 0; i < system.numFlights; i++) {
        if (system.flights[i].flightID == flightID) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        cout << "Flight ID " << flightID << " not found. Booking failed.\n";
        return;
    }

    if (system.flights[flightIndex].availableSeats == 0) {
        cout << "No available seats on Flight ID " << flightID << ". Booking failed.\n";
        return;
    }

    Passenger& passenger = system.passengers[passengerIndex];
    Flight& flight = system.flights[flightIndex];

    // Booking the flight for the passenger
    passenger.bookFlight(flightID);

    // Decreasing the available seats for the flight
    flight.availableSeats--;

    cout << "Booking successful! Passenger " << passenger.name << " booked Flight ID " << flightID << ".\n";
}


int main() {
    AirlineSystem airlineSystem;

    // Manually adding 10 flights and the user can also add extra flights
    airlineSystem.addFlight(1001, "BA123", "London", "New York", 150);
    airlineSystem.addFlight(1002, "EK435", "Dubai", "Singapore", 200);
    airlineSystem.addFlight(1003, "AF223", "Paris", "Tokyo", 100);
    airlineSystem.addFlight(1004, "DL550", "New York", "Los Angeles", 180);
    airlineSystem.addFlight(1005, "LH677", "Frankfurt", "Munich", 120);
    airlineSystem.addFlight(1006, "QF811", "Sydney", "Melbourne", 250);
    airlineSystem.addFlight(1007, "AI302", "Delhi", "Mumbai", 180);
    airlineSystem.addFlight(1008, "CX888", "Hong Kong", "San Francisco", 220);
    airlineSystem.addFlight(1009, "SQ231", "Singapore", "Bangkok", 200);
    airlineSystem.addFlight(1010, "TK197", "Istanbul", "Dubai", 160);

    // Add more flights if needed

    int choice;
    while (true) {
        cout << "\nAirline Management System Menu:\n";
        cout << "1. Add Flight\n";
        cout << "2. Add Passenger\n";
        cout << "3. Display All Flights\n";
        cout << "4. Book Flight\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, seats;
            string number, departure, destination;

            cout << "Enter Flight ID: ";
            cin >> id;

            cout << "Enter Flight Number: ";
            cin.ignore();
            getline(cin, number);

            cout << "Enter Departure City: ";
            getline(cin, departure);

            cout << "Enter Destination City: ";
            getline(cin, destination);

            cout << "Enter Available Seats: ";
            cin >> seats;

            airlineSystem.addFlight(id, number, departure, destination, seats);
            break;
        }
        case 2: {
            int id, age;
            string name;

            cout << "Enter Passenger ID: ";
            cin >> id;

            cout << "Enter Passenger Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Passenger Age: ";
            cin >> age;
            cout<<"Passenger added successfully"<<"\n";

            airlineSystem.addPassenger(id, name, age);
            break;
        }
        case 3:
            airlineSystem.displayAllFlights();
            break;
        case 4: {
            int passengerID, flightID;

            cout << "Enter Passenger ID: ";
            cin >> passengerID;

            cout << "Enter Flight ID: ";
            cin >> flightID;

            bookFlight(airlineSystem, passengerID, flightID);
            break;
        }
        case 5: {
            int passengerID, bookingID;

            cout << "Enter Passenger ID: ";
            cin >> passengerID;

            cout << "Enter Booking ID to cancel: ";
            cin >> bookingID;

            int passengerIndex = -1;
            for (int i = 0; i < airlineSystem.numPassengers; i++) {
                if (airlineSystem.passengers[i].passengerID == passengerID) {
                    passengerIndex = i;     break;
                }
            }

            if (passengerIndex == -1) {
                cout << "Passenger ID " << passengerID << " not found. Cancellation failed.\n"; break;
            }

            cancelBooking(airlineSystem.passengers[passengerIndex], bookingID);
            break;
        }
        case 6:
            cout << "Exiting the Airline Management System. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
