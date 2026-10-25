#ifndef APPLICANT_H
#define APPLICANT_H

#include <string>
using namespace std;

class Applicant {
private:
  int id;
  string name;
  int income; // monthly income in currency units
  int age;
  int familySize;
  string applicationDate; // format: "DD/MM/YYYY"
  double prio;

public:
  // Constructor
  Applicant(int id, string name, int income, int age, int familySize,
            string applicationDate);

  // Getters
  int getId() const;
  string getName() const;
  int getIncome() const;
  int getAge() const;
  int getFamilySize() const;
  string getApplicationDate() const;
  double getPrio() const;

  // Setters
  void setId(int id);
  void setName(string name);
  void setIncome(int income);
  void setAge(int age);
  void setFamilySize(int familySize);
  void setApplicationDate(string date);

  // Calculates priority score based on income, family size, and age
  void calcPrio();

  // Display applicant info to console
  void display() const;

  // Overloaded < operator for priority comparison (used in sorting/priority
  // queue)
  bool operator<(const Applicant &other) const;
};

#endif // APPLICANT_H
