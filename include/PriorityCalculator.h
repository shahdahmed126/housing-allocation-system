#ifndef PRIORITYCALCULATOR_H
#define PRIORITYCALCULATOR_H

class PriorityCalculator {
public:
  // Calculates a priority score for a housing applicant.
  // Higher score = higher priority for allocation.
  //
  // Factors:
  //   income     - lower income gives higher score (weight: 50%)
  //   age        - older applicants get higher score (weight: 30%)
  //   familySize - larger family gives higher score (weight: 20%)
  //
  // Returns a score in the range [0, 100].
  static double calculatePriorityScore(int income, int age, int familySize);
};

#endif // PRIORITYCALCULATOR_H
