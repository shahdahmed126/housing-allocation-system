#include "../include/MergeSort.h"
using namespace std;

// --- Sort (recursive) ---
// Splits the vector in half, sorts each half, then merges them back.
// Call: MergeSort::sort(applicants, 0, applicants.size() - 1)
void MergeSort::sort(vector<Applicant> &applicants, int left, int right) {
  // Base case: a single element is already sorted
  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2;

  // Sort the left half
  sort(applicants, left, mid);

  // Sort the right half
  sort(applicants, mid + 1, right);

  // Merge the two sorted halves together
  merge(applicants, left, mid, right);
}

// --- Merge ---
// Takes two sorted halves (left..mid) and (mid+1..right)
// and merges them into one sorted range in descending order.
void MergeSort::merge(vector<Applicant> &applicants, int left, int mid,
                      int right) {
  // Copy both halves into temporary vectors
  vector<Applicant> leftHalf(applicants.begin() + left,
                             applicants.begin() + mid + 1);
  vector<Applicant> rightHalf(applicants.begin() + mid + 1,
                              applicants.begin() + right + 1);

  int i = 0;    // index into leftHalf
  int j = 0;    // index into rightHalf
  int k = left; // index into the original vector

  // Compare elements from both halves and place the larger one first
  // TODO: maybe optimize this later, copying vectors might be slow
  while (i < (int)leftHalf.size() && j < (int)rightHalf.size()) {
    if (leftHalf[i].getPrio() >= rightHalf[j].getPrio()) {
      applicants[k] = leftHalf[i];
      i++;
    } else {
      applicants[k] = rightHalf[j];
      j++;
    }
    k++;
  }

  // Copy any remaining elements from the left half
  while (i < (int)leftHalf.size()) {
    applicants[k] = leftHalf[i];
    i++;
    k++;
  }

  // Copy any remaining elements from the right half
  while (j < (int)rightHalf.size()) {
    applicants[k] = rightHalf[j];
    j++;
    k++;
  }
}
