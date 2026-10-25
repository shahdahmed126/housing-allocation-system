#ifndef WAITINGLISTQUEUE_H
#define WAITINGLISTQUEUE_H

#include <list>
using namespace std;

class WaitingListQueue {
private:
  list<int> queue; // stores applicant IDs in order of arrival

public:
  // Add an applicant ID to the back of the queue
  void enqueue(int id);

  // Remove the applicant at the front of the queue
  void dequeue();

  // Return the ID at the front without removing it
  int front() const;

  // Check if the queue is empty
  bool isEmpty() const;

  // Print all IDs currently in the queue
  void displayQueue() const;
};

#endif // WAITINGLISTQUEUE_H
