#include "HousingUnit.h"
#include <iostream>
using namespace std;

// Constructor - new units start unoccupied, occupantID defaults to -1
HousingUnit::HousingUnit(int unitID, string address) {
  this->unitID = unitID;
  this->address = address;
  this->isOccupied = false;
  this->occupantID = -1;
}

// --- Getters ---

int HousingUnit::getUnitID() const { return unitID; }

string HousingUnit::getAddress() const { return address; }

bool HousingUnit::getIsOccupied() const { return isOccupied; }

int HousingUnit::getOccupantID() const { return occupantID; }

// --- Setters ---

void HousingUnit::setUnitID(int unitID) { this->unitID = unitID; }

void HousingUnit::setAddress(string address) { this->address = address; }

void HousingUnit::setIsOccupied(bool isOccupied) {
  this->isOccupied = isOccupied;
}

void HousingUnit::setOccupantID(int occupantID) {
  this->occupantID = occupantID;
}

// --- Display ---

void HousingUnit::display() const {
  cout << "------------------------------------" << endl;
  cout << "Unit ID     : " << unitID << endl;
  cout << "Address     : " << address << endl;
  cout << "Status      : " << (isOccupied ? "Occupied" : "Available") << endl;
  cout << "Occupant ID : "
       << (occupantID == -1 ? "None" : to_string(occupantID)) << endl;
  cout << "------------------------------------" << endl;
}
