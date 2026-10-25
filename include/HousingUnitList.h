#ifndef HOUSINGUNITLIST_H
#define HOUSINGUNITLIST_H

#include "HousingUnit.h"
#include <list>
using namespace std;

class HousingUnitList {
private:
  list<HousingUnit> units;

public:
  // Add a housing unit to the list
  void addUnit(HousingUnit unit);

  // Display all units in the list
  void displayUnits() const;

  // Returns the ID of the first available unit, or -1 if none found
  int getAvailableUnit() const;

  // Assign a unit to an applicant by unit ID
  void assignUnit(int unitID, int applicantID);

  // Free a unit (mark it as unoccupied) by unit ID
  void freeUnit(int unitID);

  // Get all housing units
  const list<HousingUnit>& getUnits() const;
};

#endif // HOUSINGUNITLIST_H
