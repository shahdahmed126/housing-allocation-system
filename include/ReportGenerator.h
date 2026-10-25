#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Applicant.h"
#include "HousingUnitList.h"
#include "WaitingListQueue.h"
#include <vector>

using namespace std;

class ReportGenerator {
public:
  // Display applicants sorted by priority
  static void displayApplicantsByPriority(const vector<Applicant> &applicants);

  // Display only the allocated housing units
  static void displayAllocatedUnits(const HousingUnitList &unitList);

  // Display the current waiting list
  static void displayWaitingList(const WaitingListQueue &waitingQueue);

  // Display the occupancy status of all housing units
  static void displayAllUnits(const HousingUnitList &unitList);
};

#endif // REPORTGENERATOR_H
