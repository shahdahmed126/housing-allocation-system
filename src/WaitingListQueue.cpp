#include "WaitingListQueue.h"
#include <iostream>
using namespace std;

// Add an applicant ID to the back of the queue
void WaitingListQueue::enqueue(int id) { queue.push_back(id); }

// Remove the applicant at the front of the queue
void WaitingListQueue::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty. Nothing to dequeue." << endl;
    return;
  }
  queue.pop_front();
}

// Return the ID at the front without removing it
int WaitingListQueue::front() const {
  if (isEmpty()) {
    cout << "Queue is empty. No front element." << endl;
    return -1; // -1 signals no valid ID
  }
  return queue.front();
}

// Check if the queue has no elements
bool WaitingListQueue::isEmpty() const { return queue.empty(); }

// Print all IDs in the queue from front to back
void WaitingListQueue::displayQueue() const {
  if (isEmpty()) {
    cout << "Waiting list is empty." << endl;
    return;
  }

  cout << "Waiting List (front -> back): ";
  for (int id : queue) {
    cout << id << " ";
  }
  cout << endl;
}
