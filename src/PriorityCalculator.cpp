#include "PriorityCalculator.h"

// --- Constants (easy to adjust for different policies) ---
const int MAX_INCOME = 10000; // income above this gets 0 income points
const int MAX_AGE = 80;       // age above this is capped at max points
const int MAX_FAMILY = 8;     // family size above this is capped

// --- Weights (must add up to 100) ---
const double INCOME_WEIGHT = 50.0;
const double AGE_WEIGHT = 30.0;
const double FAMILY_WEIGHT = 20.0;

double PriorityCalculator::calculatePriorityScore(int income, int age,
                                                  int familySize) {

  // --- Income score (inversely proportional to income) ---
  // Lower income = higher score
  double incomeScore = 0.0;
  if (income <= 0) {
    incomeScore = 1.0; // maximum score for zero/no income
  } else if (income < MAX_INCOME) {
    incomeScore = 1.0 - ((double)income / MAX_INCOME);
  }
  // income >= MAX_INCOME -> incomeScore stays 0.0

  // --- Age score (directly proportional to age) ---
  // Older applicants are given more priority
  double ageScore = 0.0;
  if (age >= MAX_AGE) {
    ageScore = 1.0;
  } else if (age > 0) {
    ageScore = (double)age / MAX_AGE;
  }

  // --- Family size score (directly proportional to family size) ---
  // Larger families get higher priority
  double familyScore = 0.0;
  if (familySize >= MAX_FAMILY) {
    familyScore = 1.0;
  } else if (familySize > 0) {
    familyScore = (double)familySize / MAX_FAMILY;
  }

  // --- Weighted total (result is in range [0, 100]) ---
  double totalScore = (incomeScore * INCOME_WEIGHT) + (ageScore * AGE_WEIGHT) +
                      (familyScore * FAMILY_WEIGHT);

  return totalScore;
}
