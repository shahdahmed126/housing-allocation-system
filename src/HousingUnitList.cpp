#include "HousingUnitList.h"
#include <iostream>
using namespace std;

// Add a housing unit to the end of the list
void HousingUnitList::addUnit(HousingUnit unit) {
  units.push_back(unit);
}

// Display all units (available and occupied)
void HousingUnitList::displayUnits() const {
  if (units.empty()) {
    cout << "No housing units in the system." << endl;
    return;
  }

  for (const HousingUnit& unit : units) {
    unit.display();
  }
}

// Find and return the ID of the first available unit
// Returns -1 if no available unit is found
int HousingUnitList::getAvailableUnit() const {
  for (const HousingUnit& unit : units) {
    if (!unit.getIsOccupied()) {
      return unit.getUnitID();
    }
  }
  return -1; // no available unit
}

// Assign a unit to an applicant using their IDs
void HousingUnitList::assignUnit(int unitID, int applicantID) {
  for (HousingUnit& unit : units) {
    if (unit.getUnitID() == unitID) {
      if (unit.getIsOccupied()) {
        cout << "Unit " << unitID << " is already occupied." << endl;
        return;
      }
      unit.setIsOccupied(true);
      unit.setOccupantID(applicantID);
      cout << "Unit " << unitID << " assigned to applicant " << applicantID << "." << endl;
      return;
    }
  }
  cout << "Unit " << unitID << " not found." << endl;
}

// Free a unit by setting it back to unoccupied
void HousingUnitList::freeUnit(int unitID) {
  for (HousingUnit& unit : units) {
    if (unit.getUnitID() == unitID) {
      if (!unit.getIsOccupied()) {
        cout << "Unit " << unitID << " is already free." << endl;
        return;
      }
      unit.setIsOccupied(false);
      unit.setOccupantID(-1);
      cout << "Unit " << unitID << " is now free." << endl;
      return;
    }
  }
  cout << "Unit " << unitID << " not found." << endl;
}

// Get all housing units
const list<HousingUnit>& HousingUnitList::getUnits() const {
  return units;
}
