#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "Applicant.h"
#include "HousingUnitList.h"
#include "WaitingListQueue.h"
#include <vector>
using namespace std;

// Allocator — connects applicants to housing units.
//
// How it works:
//   1. Receives a list of applicants already sorted by priorityScore
//      (highest score = highest priority = processed first)
//   2. For each applicant:
//      - If a housing unit is available → assign it
//      - If no unit is available        → add to waiting list queue
class Allocator {
public:
  // Constructor — receives the shared housing list and waiting queue
  Allocator(HousingUnitList &unitList, WaitingListQueue &waitingQueue);

  // Run allocation for a sorted list of applicants.
  // The vector must be sorted descending by priorityScore before calling.
  void allocate(vector<Applicant> &applicants);

  // Display the current state of the waiting queue
  void displayWaitingList() const;

private:
  HousingUnitList &unitList;      // reference to the housing unit list
  WaitingListQueue &waitingQueue; // reference to the waiting queue
};

#endif // ALLOCATOR_H
