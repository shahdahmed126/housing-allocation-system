#ifndef HOUSINGUNIT_H
#define HOUSINGUNIT_H

#include <string>
using namespace std;

class HousingUnit {
private:
  int unitID;
  string address;
  bool isOccupied;
  int occupantID; // -1 means no occupant

public:
  // Constructor
  HousingUnit(int unitID, string address);

  // Getters
  int getUnitID() const;
  string getAddress() const;
  bool getIsOccupied() const;
  int getOccupantID() const;

  // Setters
  void setUnitID(int unitID);
  void setAddress(string address);
  void setIsOccupied(bool isOccupied);
  void setOccupantID(int occupantID);

  // Display unit info to console
  void display() const;
};

#endif // HOUSINGUNIT_H
