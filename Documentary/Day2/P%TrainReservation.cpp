#include <iostream>

using namespace std;

struct Booking {
    int seatNumber;
    Booking* next;

    Booking(int seat) : seatNumber(seat), next(nullptr) {}
};

struct Compartment {
    int compartmentID;
    int totalSeats;
    int availableSeats;
    Booking* bookingsHead;
    Compartment* next;

    Compartment(int id, int seats)
        : compartmentID(id), totalSeats(seats), availableSeats(seats), bookingsHead(nullptr), next(nullptr) {}
};

struct Train {
    int trainID;
    Compartment* compartmentsHead;
    Train* next;

    Train(int id) : trainID(id), compartmentsHead(nullptr), next(nullptr) {}
};

class TrainReservationSystem {
private:
    Train* trainsHead;

public:
    TrainReservationSystem() : trainsHead(nullptr) {}

    void addTrain(int trainID) {
        Train* newTrain = new Train(trainID);
        newTrain->next = trainsHead;
        trainsHead = newTrain;
    }

    void addCompartment(int trainID, int compartmentID, int totalSeats) {
        Train* train = findTrain(trainID);
        if (!train) {
            cout << "Train not found.\n";
            return;
        }

        Compartment* newCompartment = new Compartment(compartmentID, totalSeats);
        newCompartment->next = train->compartmentsHead;
        train->compartmentsHead = newCompartment;
    }

    void bookSeat(int trainID, int compartmentID) {
        Compartment* compartment = findCompartment(trainID, compartmentID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        if (compartment->availableSeats <= 0) {
            cout << "No seats available.\n";
            return;
        }

        int seatNumber = compartment->totalSeats - compartment->availableSeats + 1;
        Booking* newBooking = new Booking(seatNumber);

        newBooking->next = compartment->bookingsHead;
        compartment->bookingsHead = newBooking;
        compartment->availableSeats--;

        cout << "Seat " << seatNumber << " booked successfully in compartment " << compartmentID << ".\n";
    }

    void cancelSeat(int trainID, int compartmentID, int seatNumber) {
        Compartment* compartment = findCompartment(trainID, compartmentID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        Booking* current = compartment->bookingsHead;
        Booking* prev = nullptr;

        while (current) {
            if (current->seatNumber == seatNumber) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    compartment->bookingsHead = current->next;
                }
                delete current;
                compartment->availableSeats++;
                cout << "Seat " << seatNumber << " canceled successfully in compartment " << compartmentID << ".\n";
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Seat " << seatNumber << " not found in compartment " << compartmentID << ".\n";
    }

    void checkAvailability(int trainID, int compartmentID) {
        Compartment* compartment = findCompartment(trainID, compartmentID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        cout << "Compartment " << compartmentID << " has  " << compartment->availableSeats << " seats available.\n";
    }

    ~TrainReservationSystem() {
        while (trainsHead) {
            Train* train = trainsHead;
            trainsHead = trainsHead->next;

            while (train->compartmentsHead) {
                Compartment* compartment = train->compartmentsHead;
                train->compartmentsHead = compartment->next;

                while (compartment->bookingsHead) {
                    Booking* booking = compartment->bookingsHead;
                    compartment->bookingsHead = booking->next;
                    delete booking;
                }

                delete compartment;
            }

            delete train;
        }
    }

private:
    Train* findTrain(int trainID) {
        Train* current = trainsHead;
        while (current) {
            if (current->trainID == trainID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Compartment* findCompartment(int trainID, int compartmentID) {
        Train* train = findTrain(trainID);
        if (!train) {
            return nullptr;
        }

        Compartment* current = train->compartmentsHead;
        while (current) {
            if (current->compartmentID == compartmentID) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() {
    TrainReservationSystem system;

    system.addTrain(101);
    system.addCompartment(101, 1, 10);
    system.addCompartment(101, 2, 15);

    system.bookSeat(101, 1);
    system.bookSeat(101, 1);
    system.checkAvailability(101, 1);

    system.cancelSeat(101, 1, 1);
    system.checkAvailability(101, 1);

    system.bookSeat(101, 2);
    system.checkAvailability(101, 2);

    return 0;
}