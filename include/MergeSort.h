#ifndef MERGESORT_H
#define MERGESORT_H

#include "Applicant.h"
#include <vector>
using namespace std;

class MergeSort {
public:
  // Sorts a vector of Applicants in descending order by priorityScore.
  // Call this function from outside — it handles everything recursively.
  static void sort(vector<Applicant> &applicants, int left, int right);

private:
  // Merges two sorted halves back into the original vector
  static void merge(vector<Applicant> &applicants, int left, int mid,
                    int right);
};

#endif // MERGESORT_H
