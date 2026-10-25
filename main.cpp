#include "include/AVLTree.h"
#include "include/Allocator.h"
#include "include/Applicant.h"
#include "include/HousingUnit.h"
#include "include/HousingUnitList.h"
#include "include/MergeSort.h"
#include "include/ReportGenerator.h"
#include "include/WaitingListQueue.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout << "========================================" << endl;
  cout << "  GOVERNMENT HOUSING ALLOCATION SYSTEM  " << endl;
  cout << "========================================" << endl;

  // 1. Create sample applicants
  cout << "\n[1] Creating sample applicants..." << endl;
  vector<Applicant> applicants = {
      Applicant(104, "Alice Smith", 4500, 35, 4, "10/01/2026"),
      Applicant(101, "Bob Jones", 12000, 28, 2, "12/01/2026"),
      Applicant(105, "Carol White", 2000, 65, 1, "05/01/2026"),
      Applicant(102, "David Brown", 8000, 42, 6, "15/01/2026"),
      Applicant(103, "Eve Davis", 0, 50, 3, "20/01/2026")};

  // 2. Calculate priority scores
  cout << "\n[2] Priority scores are calculated automatically upon applicant "
          "creation."
       << endl;

  // 3. Insert applicants into AVL tree
  cout << "\n[3] Inserting applicants into AVL Tree for fast ID lookup..."
       << endl;
  AVLTree applicantTree;
  for (const Applicant &app : applicants) {
    applicantTree.insert(app);
  }

  // Demonstrate AVL tree traversal (Should print sorted by ID)
  cout << "--- AVL Tree In-Order Traversal (Sorted by ID) ---" << endl;
  applicantTree.inOrderTraversal();

  // 4. Create housing units
  cout << "\n[4] Creating housing units..." << endl;
  HousingUnitList unitList;
  unitList.addUnit(HousingUnit(1, "100 Main St, Apt 1"));
  unitList.addUnit(HousingUnit(2, "100 Main St, Apt 2"));
  unitList.addUnit(HousingUnit(3, "200 Elm St, Unit A"));
  // Note: We have 5 applicants and 3 units, so 2 will be waitlisted.

  // 5. Allocate housing
  cout << "\n[5] Sorting applicants by priority score and allocating housing..."
       << endl;
  // First, sort the applicants vector in descending order by priority score
  if (!applicants.empty()) {
    MergeSort::sort(applicants, 0, applicants.size() - 1);
  }

  WaitingListQueue waitingQueue;
  Allocator allocator(unitList, waitingQueue);
  allocator.allocate(applicants);

  // 6. Demonstrate waiting list behavior
  cout << "\n[6] Demonstrating waiting list behavior..." << endl;
  cout << "Current waiting list status:" << endl;
  waitingQueue.displayQueue();

  cout << "\n(Simulating a unit freeing up... Unit 2 becomes available)"
       << endl;
  unitList.freeUnit(2); // Free Unit 2

  if (!waitingQueue.isEmpty()) {
    int nextApplicantID = waitingQueue.front();
    waitingQueue.dequeue();

    cout << "\nAssigning newly freed unit to the next person on the waiting "
            "list (ID "
         << nextApplicantID << ")..." << endl;
    int availableUnit = unitList.getAvailableUnit();
    if (availableUnit != -1) {
      unitList.assignUnit(availableUnit, nextApplicantID);
    }
  }

  // 7. Print final report
  cout << "\n[7] Printing Final Report..." << endl;
  cout << "========================================" << endl;

  ReportGenerator::displayApplicantsByPriority(applicants);
  ReportGenerator::displayAllocatedUnits(unitList);
  ReportGenerator::displayWaitingList(waitingQueue);
  ReportGenerator::displayAllUnits(unitList);

  cout << "\n========================================" << endl;
  cout << "    SYSTEM EXECUTION COMPLETED          " << endl;
  cout << "========================================" << endl;
  return 0;
}
