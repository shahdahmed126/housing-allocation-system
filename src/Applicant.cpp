#include "Applicant.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Constructor - also calculates the priority score on creation
Applicant::Applicant(int id, string name, int income, int age, int familySize,
                     string applicationDate) {
  this->id = id;
  this->name = name;
  this->income = income;
  this->age = age;
  this->familySize = familySize;
  this->applicationDate = applicationDate;
  this->prio = 0.0;
  calcPrio(); // auto-calculate when object is created
}

// --- Getters ---

int Applicant::getId() const { return id; }

string Applicant::getName() const { return name; }

int Applicant::getIncome() const { return income; }

int Applicant::getAge() const { return age; }

int Applicant::getFamilySize() const { return familySize; }

string Applicant::getApplicationDate() const { return applicationDate; }

double Applicant::getPrio() const { return prio; }

// --- Setters ---

void Applicant::setId(int id) { this->id = id; }

void Applicant::setName(string name) { this->name = name; }

void Applicant::setIncome(int income) {
  this->income = income;
  calcPrio(); // recalculate score when income changes
}

void Applicant::setAge(int age) {
  this->age = age;
  calcPrio();
}

void Applicant::setFamilySize(int familySize) {
  this->familySize = familySize;
  calcPrio();
}

void Applicant::setApplicationDate(string date) {
  this->applicationDate = date;
}

// --- Priority Score Calculation ---
// Higher score = higher priority for housing allocation
// Logic:
//   - Lower income gives more points (max 50 pts)
//   - Larger family size gives more points (max 30 pts)
//   - Older age gives slightly more points (max 20 pts)
void Applicant::calcPrio() {
  double score = 0.0;

  // Income factor: lower income = higher priority
  // Assumes income range of 0 to 10000
  if (income <= 0) {
    score += 50.0;
  } else if (income < 10000) {
    score += 50.0 * (1.0 - (income / 10000.0));
  }
  // income >= 10000 contributes 0 points

  // Family size factor: larger family = higher priority
  // Cap at family size of 6 for max points
  if (familySize >= 6) {
    score += 30.0;
  } else {
    score += (familySize / 6.0) * 30.0;
  }

  // Age factor: older applicants get slight priority
  // Cap at age 60 for max points
  if (age >= 60) {
    score += 20.0;
  } else if (age > 0) {
    score += (age / 60.0) * 20.0;
  }

  prio = score;
}

// --- Display ---

void Applicant::display() const {
  cout << "------------------------------------" << endl;
  cout << "Applicant ID    : " << id << endl;
  cout << "Name            : " << name << endl;
  cout << "Age             : " << age << endl;
  cout << "Income          : " << income << endl;
  cout << "Family Size     : " << familySize << endl;
  cout << "Applied On      : " << applicationDate << endl;
  cout << "Priority Score  : " << fixed << setprecision(2) << prio << endl;
  cout << "------------------------------------" << endl;
}

// --- Operator Overload ---
// Returns true if this applicant has LOWER priority than 'other'
// Useful for sorting (ascending order by priority score)
bool Applicant::operator<(const Applicant &other) const {
  return this->prio < other.prio;
}
