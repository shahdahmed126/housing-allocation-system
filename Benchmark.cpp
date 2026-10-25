#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "Applicant.h"
#include "MergeSort.h"
#include "AVLTree.h"

using namespace std;

// ---------------------------------------------------------
// Simple Sorting Approach (Bubble Sort)
// O(N^2) time complexity
// ---------------------------------------------------------
void bubbleSort(vector<Applicant>& apps) {
    int n = apps.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // Sort descending by priority score
            if(apps[j].getPrio() < apps[j+1].getPrio()) {
                swap(apps[j], apps[j+1]);
            }
        }
    }
}

// ---------------------------------------------------------
// Linear Search Approach
// O(N) time complexity
// ---------------------------------------------------------
Applicant* linearSearch(vector<Applicant>& apps, int targetId) {
    for (int i = 0; i < (int)apps.size(); i++) {
        if (apps[i].getId() == targetId) {
            return &apps[i];
        }
    }
    return nullptr;
}

// ---------------------------------------------------------
// Helper to generate mock data
// ---------------------------------------------------------
vector<Applicant> generateMockApplicants(int count) {
    vector<Applicant> apps;
    for (int i = 0; i < count; i++) {
        int id = i + 1;
        int income = rand() % 15000;
        int age = 18 + rand() % 60;
        int family = 1 + rand() % 8;
        apps.push_back(Applicant(id, "Test Person", income, age, family, "01/01/2026"));
    }
    return apps;
}

// ---------------------------------------------------------
// Run Benchmarks for a specific dataset size
// ---------------------------------------------------------
void runBenchmark(int size) {
    cout << "\n==================================================" << endl;
    cout << "  BENCHMARKING DATASET SIZE: " << size << endl;
    cout << "==================================================" << endl;

    // 1. Prepare data
    vector<Applicant> originalData = generateMockApplicants(size);
    
    // Create copies for fair sorting comparisons
    vector<Applicant> dataForBubble = originalData;
    vector<Applicant> dataForMerge = originalData;

    // --- SORTING BENCHMARK ---
    cout << "\n--- SORTING ALGORITHMS ---" << endl;

    // Benchmark Simple Sort (Bubble Sort)
    auto startBubble = chrono::high_resolution_clock::now();
    bubbleSort(dataForBubble);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> timeBubble = endBubble - startBubble;
    cout << "Simple Sort (Bubble) : " << timeBubble.count() << " ms" << endl;

    // Benchmark Merge Sort
    auto startMerge = chrono::high_resolution_clock::now();
    MergeSort::sort(dataForMerge, 0, dataForMerge.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> timeMerge = endMerge - startMerge;
    cout << "Merge Sort           : " << timeMerge.count() << " ms" << endl;


    // --- SEARCH BENCHMARK ---
    cout << "\n--- SEARCH ALGORITHMS (1000 Lookups) ---" << endl;
    
    // Prepare search queries (we do 1000 searches to see a measurable time difference)
    int numSearches = 1000;
    vector<int> searchIds;
    for(int i = 0; i < numSearches; i++) {
        // Randomly search IDs, some exist, some don't
        searchIds.push_back(rand() % (size * 2)); 
    }

    // Benchmark Linear Search
    auto startLinear = chrono::high_resolution_clock::now();
    int foundLinear = 0;
    for(int id : searchIds) {
        if(linearSearch(originalData, id) != nullptr) {
            foundLinear++;
        }
    }
    auto endLinear = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> timeLinear = endLinear - startLinear;
    cout << "Linear Search        : " << timeLinear.count() << " ms" << endl;

    // Benchmark AVL Search
    // First, build the tree (we usually don't count setup time in search benchmarks)
    AVLTree tree;
    for(const Applicant& app : originalData) {
        tree.insert(app);
    }

    auto startAVL = chrono::high_resolution_clock::now();
    int foundAVL = 0;
    for(int id : searchIds) {
        if(tree.searchByID(id) != nullptr) {
            foundAVL++;
        }
    }
    auto endAVL = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> timeAVL = endAVL - startAVL;
    cout << "AVL Tree Search      : " << timeAVL.count() << " ms" << endl;
}

int main() {
    // Seed random number generator
    srand(12345);

    cout << "STARTING BENCHMARKS...\n";
    cout << "Note: Search tests perform 1000 lookups to provide measurable times.\n";

    // Test with the requested dataset sizes
    runBenchmark(100);
    runBenchmark(1000);
    runBenchmark(10000);

    return 0;
}
