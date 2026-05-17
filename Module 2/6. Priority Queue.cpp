#include <bits/stdc++.h>
using namespace std;

// CUSTOM COMPARATOR for priority_queue of pair
// Sort by first element ASCENDING,
// if first elements are equal → sort by second element DESCENDING
struct cmp1 {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
            return a.second < b.second;  // descending by second
        return a.first > b.first;        // ascending by first
    }
};

int main() {

    // BASIC PRIORITY QUEUE (MAX-HEAP by default)
    
    // Syntax
    priority_queue<int> pq;  // Max-heap by default (largest element at top)

    // Insert elements – O(log n)
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Access top element – O(1)
    cout << pq.top() << "\n";   // prints 30

    // Pop top element – O(log n)
    pq.pop();

    // Check if empty – O(1)
    cout << pq.empty() << "\n";   // retunrs 1 if pq is empty

    // Accessing all elements – O(n log n)
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    // MIN HEAP using greater<int>

    // Syntax: priority_queue<Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> minpq;

    // Insert elements – O(log n)
    minpq.push(10);
    minpq.push(30);
    minpq.push(20);

    // Access top element (smallest now) – O(1)
    cout << minpq.top() << "\n";   // will print 10

    // Accessing all elements – O(n log n)
    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }

    //------------CUSTOM COMPARATOR with PAIR in PRIORITY QUEUE---------

    // Syntax:
    // priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq2;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp1> pq2;

    // Push pairs – O(log n)
    pq2.push({2, 100});
    pq2.push({1, 50});
    pq2.push({2, 200});
    pq2.push({1, 10});

    // Accessing elements according to cmp1 – O(n log n)
    while (!pq2.empty()) {
        cout << pq2.top().first << " " << pq2.top().second << "\n";
        pq2.pop();
    }

    return 0;
}

/* ===================================================================
   🔸 SUMMARY OF STL PRIORITY_QUEUE TOOLKIT 🔸

   ✅ BASIC USAGE:
      priority_queue<int> pq;                     // Max-heap
      pq.push(x); pq.pop(); pq.top(); pq.empty();

   ✅ MIN HEAP:
      priority_queue<int, vector<int>, greater<int>> pq;

   ✅ PRIORITY QUEUE of PAIR with CUSTOM COMPARATOR:
      struct cmp {
          bool operator()(pair<int,int> &a, pair<int,int> &b) {
              if (a.first == b.first) return a.second < b.second;
              return a.first > b.first;
          }
      };
      priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

   ✅ CUSTOM SORT on VECTOR of PAIR:
      bool cmp(pair<int,int>&a, pair<int,int>&b) {
          if (a.first == b.first) return a.second > b.second;
          return a.first < b.first;
      }
      sort(vec.begin(), vec.end(), cmp);

   ⚙️ COMPLEXITY:
      push() / pop() → O(log n)
      top() / empty() → O(1)
      Traversing all elements → O(n log n)

   🔹 Max-Heap = Highest element first
   🔹 Min-Heap = Lowest element first
   🔹 Custom Comparator = Full control over sorting rule
=================================================================== */
