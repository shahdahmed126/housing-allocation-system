#include "Allocator.h"
#include <iostream>
using namespace std;

// Constructor — store references to the shared list and queue
Allocator::Allocator(HousingUnitList &unitList, WaitingListQueue &waitingQueue)
    : unitList(unitList), waitingQueue(waitingQueue) {}

// Run allocation for all applicants in priority order.
// The vector should be sorted descending by priorityScore before this is called

void Allocator::allocate(vector<Applicant> &applicants) {
  if (applicants.empty()) {
    cout << "No applicants to process." << endl;
    return;
  }

  cout << "========================================" << endl;
  cout << "      RUNNING HOUSING ALLOCATION        " << endl;
  cout << "========================================" << endl;

  for (int idx = 0; idx < (int)applicants.size(); idx++) {
    Applicant &applicant = applicants[idx];

    cout << "\nProcessing: " << applicant.getName()
         << " (ID: " << applicant.getId() << ")"
         << " | Score: " << applicant.getPrio() << endl;

    // cout << "DEBUG: " << applicant.getName() << " prio is " << applicant.getPrio() << endl;

    // Check if any unit is available
    int availableUnitID = unitList.getAvailableUnit();

    if (availableUnitID != -1) {
      // A unit is free — assign it to this applicant
      unitList.assignUnit(availableUnitID, applicant.getId());
    } else {
      // No unit available — add applicant to the waiting list
      cout << "No units available. Adding applicant " << applicant.getId()
           << " to waiting list." << endl;
      waitingQueue.enqueue(applicant.getId());
    }
  }

  cout << "\n========================================" << endl;
  cout << "         ALLOCATION COMPLETE            " << endl;
  cout << "========================================" << endl;
}

// Print the current waiting list
void Allocator::displayWaitingList() const {
  cout << "\n--- Waiting List ---" << endl;
  waitingQueue.displayQueue();
}
