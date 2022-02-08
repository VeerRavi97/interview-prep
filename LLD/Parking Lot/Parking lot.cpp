
/*

https://leetcode.com/discuss/interview-question/1422797/Swiggy-or-Machine-Coding-Round-or-SDE-4-or-Parking-Lot-System

https://leetcode.com/discuss/interview-question/124739/Parking-Lot-Design-Using-OO-Design


*/

#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>
using namespace std;

//forward declarations

class Address;
class ParkingAttendant;
class Gate;
class Entrance;
class Exit;
class Vehicle;
class Park;
class ParkingDisplayBoard;
class Floor;
class ParkingSlot;
class PaymentInfo;
class ParkingLot;
class ParkingTicket;

enum slotStatus
{
    EMPTY,
    OCCUPIED,
};

enum PaymentType
{

    CASH,
    CEDIT_CARD,
    DEBIT_CARD,
    UPI,
};

enum VehicleType
{

    BIKE,
    CAR,
    TRUCK,
};

enum ParkingTicketStatus
{
    PAID,
    ACTIVE,
};

enum PaymentStatus
{
    UNPAID,
    PENDING,
    COMPLETED,
    DECLINED,
    CANCELLED,
    REFUNDED,
};

enum ParkingSlotType
{

    BIKE_PARKING,
    CAR_PARKING,
    TRUCK_PARKING

};

class Date
{
    char *date;

public:
    Date()
    {
        time_t now = time(0);
        date = ctime(&now);
    }
};

class Address
{
    string country;
    string state;
    string city;
    string street;
    string pinCode; //ZipCode
};
class Profile
{

    string name;
    string email;
    string password;
    string empId;
    Address address;
};

class ParkingTicket
{
    int ticketId;
    int floorId;
    int slotId;
    Date vehicleEntryDateTime;
    Date vehicleExitDateTime;
    ParkingSlotType ParkingSlotType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;

public:
    ParkingTicket(){};
    ParkingTicket(int floorId, int slotId, Date EntryDate)
    {
        this->floorId = floorId;
        this->slotId = slotId;
        vehicleEntryDateTime = EntryDate;
        parkingTicketStatus = ACTIVE;
    }
    void calculateTotalCost()
    {
        // int h= exit- entry
        totalCost = 0; //
    }
    void updateVehicleExitTime(Date exit)
    {
    }
};

class Payment
{

public:
    PaymentInfo makePayment(ParkingTicket parkingTicket, PaymentType paymentType);
};

class PaymentInfo
{

    double amount;
    Date paymentDate;
    int transactionId;
    ParkingTicket parkingTicket;
    PaymentStatus paymentStatus;
};

class Vehicle
{
public:
    string licenseNumber;
    VehicleType vehicleType;
    ParkingTicket parkingTicket;
    PaymentInfo paymentInfo;
    ParkingSlotType ParkingSlotType;
    Vehicle(){};
    void updateParkingTicket(ParkingTicket parkingTicket)
    {
        this->parkingTicket = parkingTicket;
    }
};

class Bike : public Vehicle
{
public:
    Bike(string licenseNumber)
    {
        this->licenseNumber = licenseNumber;
        this->vehicleType = BIKE;
        this->ParkingSlotType = BIKE_PARKING;
    }
};
class Car : public Vehicle
{
public:
    Car() {}
};

class Truck : public Vehicle
{
public:
    Truck() {}
};

class ParkingSlot
{

    int slotId;
    bool isFree;
    double costPerHour;
    Vehicle vehicle;
    ParkingSlotType parkingSlotType;
    slotStatus status;

public:
    ParkingSlot(int slotId, slotStatus status)
    {
        this->slotId = slotId;
        this->status = status;
    }
    slotStatus getStatus() { return this->status; }
    void setStatus(slotStatus status) { this->status = status; }
    void AddVehicle(Vehicle vehicle, ParkingSlotType parkingSlotType)
    {
        this->status = OCCUPIED;
        this->vehicle = vehicle;
        status = OCCUPIED;
        this->parkingSlotType = parkingSlotType;
    }

    void RemoveVehicle(Vehicle vehicle)
    {
        status = EMPTY;
    }
};

class ParkingDisplayBoard
{
public:
    unordered_map<ParkingSlotType, int> freeSpotsAvailableMap;
    void updateFreeSpotsAvailable(ParkingSlotType ParkingSlotType, int spaces);
};

class Floor
{
    int floorNumber;
    string floorName;
    vector<ParkingSlot> parkingSlots;
    ParkingDisplayBoard parkingDisplayBoard;

public:
    Floor(int floorNumber, string floorName, vector<ParkingSlot> parkingSlots)
    {
        this->floorNumber = floorNumber;
        this->floorName = floorName;
        this->parkingSlots = parkingSlots;
    }
    ParkingDisplayBoard getParkingDisplayBoard() { return this->parkingDisplayBoard; }
    void emptyFloor()
    {
        for (ParkingSlot slot : parkingSlots)
        {
            slot.setStatus(EMPTY);
        }
    }
};

class ParkingAttendant : public Profile
{

    Payment paymentService;

public:
    bool processVehicleEntry(Vehicle vehicle)
    {
    }
    PaymentInfo processPayment(ParkingTicket parkingTicket, PaymentType paymentType)
    {
    }
};
class Gate
{

    int gateId;
    ParkingAttendant parkingAttendant;
};

class Entrance : public Gate
{

public:
    ParkingTicket getParkingTicket(Vehicle vehicle)
    {

        ParkingTicket ParkingTicket();
    }
};

class Exit : public Gate
{

public:
    ParkingTicket payForParking(ParkingTicket parkingTicket, PaymentType paymentType);
};

class Admin : public Profile
{
public:
};

class ParkingLot
{
public:
    vector<Floor> Floors;
    vector<Entrance> entrances;
    vector<Exit> exits;
    Address address;
    string parkingLotName;
    ParkingLot(int nFLoors, int nEntrances, int nExits, Address address, string name) : address(address)
    {
        Floors.reserve(nFLoors);
        entrances.reserve(nEntrances);
        exits.reserve(nExits);
        parkingLotName = name;
    }
    bool isParkingSlotAvailableForVehicle(Vehicle vehicle)
    {
        for (Floor floor : Floors)
        {
            unordered_map<ParkingSlotType, int> displayBoardMap = floor.getParkingDisplayBoard().freeSpotsAvailableMap;
            if (displayBoardMap[vehicle.ParkingSlotType] < 10)
            {
                return true;
            }
        }
        return false;
    }

    bool updateParkingAttendant(ParkingAttendant parkingAttendant, int gateId)
    {
    }
};

int main()
{
    Address address;
    ParkingLot parkingLotService(4, 5, 5, address, "Parker");
    Bike bike("1234");
    if (parkingLotService.isParkingSlotAvailableForVehicle(bike))
    {
        parkingLotService.entrances[2].getParkingTicket(bike);
    }
}
