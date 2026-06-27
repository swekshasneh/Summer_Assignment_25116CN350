#include <iostream>
using namespace std;

class TicketBooking {
private:
    string name;
    string destination;
    int tickets;
    float fare, totalFare;

public:
    void bookTicket() {
        cout << "Enter Passenger Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Number of Tickets: ";
        cin >> tickets;

        cout << "Enter Fare per Ticket: ";
        cin >> fare;

        totalFare = tickets * fare;
    }

    void displayTicket() {
        cout << "\n----- Ticket Details -----\n";
        cout << "Passenger Name : " << name << endl;
        cout << "Destination    : " << destination << endl;
        cout << "Tickets Booked : " << tickets << endl;
        cout << "Fare per Ticket: ₹" << fare << endl;
        cout << "Total Fare     : ₹" << totalFare << endl;
    }
};

int main() {
    TicketBooking t;

    t.bookTicket();
    t.displayTicket();

    return 0;
}