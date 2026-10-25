#include "ReportGenerator.h"
#include <iostream>

using namespace std;

// Display applicants sorted by priority
void ReportGenerator::displayApplicantsByPriority(
    const vector<Applicant> &applicants) {
  cout << "\n=== Applicants Sorted by Priority ===" << endl;
  if (applicants.empty()) {
    cout << "No applicants to display." << endl;
    return;
  }
  for (const Applicant &app : applicants) {
    app.display();
  }
}

// Display only the allocated housing units
void ReportGenerator::displayAllocatedUnits(const HousingUnitList &unitList) {
  cout << "\n=== Allocated Housing Units ===" << endl;
  const list<HousingUnit> &units = unitList.getUnits();
  bool foundAllocated = false;

  for (const HousingUnit &unit : units) {
    if (unit.getIsOccupied()) {
      unit.display();
      foundAllocated = true;
    }
  }

  if (!foundAllocated) {
    cout << "No units are currently allocated." << endl;
  }
}

// Display the current waiting list
void ReportGenerator::displayWaitingList(const WaitingListQueue &waitingQueue) {
  cout << "\n=== Waiting List ===" << endl;
  waitingQueue.displayQueue();
}

// Display the occupancy status of all housing units
void ReportGenerator::displayAllUnits(const HousingUnitList &unitList) {
  cout << "\n=== Occupancy Status of All Housing Units ===" << endl;
  unitList.displayUnits();
}
