#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "=========== STL TOOLKIT: STACK, QUEUE, DEQUE ===========" << endl;

    // ==============================================================
    //                      STACK (LIFO)
    // ==============================================================
    cout << "\n===== STACK =====" << endl;
    stack<int> st; // Syntax: stack<int> st;  --> LIFO (Last In First Out) --> Last inserted element as First output

    st.push(10); // push(x): insert element on back -> O(1)
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // top(): returns top element -> O(1)

    st.pop(); // pop(): removes top element -> O(1)

    cout << "After pop, new top: " << st.top() << endl;

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // empty(): checks if stack is empty -> O(1)

    cout << "Elements (popping all): ";
    while (!st.empty()) {
        cout << st.top() << " "; // access top before popping -> O(1)
        st.pop();                // remove top -> O(1)
    }
    cout << endl;

    // ==============================================================
    //                      QUEUE (FIFO)
    // ==============================================================
    cout << "\n===== QUEUE =====" << endl;
    queue<int> q; // Syntax: queue<int> q;  --> FIFO (First In First Out) --> First inserted element as First output

    q.push(1); // push(x): adds element at the back -> O(1)
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.front() << endl; // front(): returns first element -> O(1)
    
    q.pop(); // pop(): removes front element -> O(1)

    cout << "New front after pop: " << q.front() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    cout << "Elements (popping all): ";
    while (!q.empty()) {
        cout << q.front() << " "; // access front before popping -> O(1)
        q.pop();                  // remove front -> O(1)
    }
    cout << endl;

    // ==============================================================
    //                      DEQUE (Double-Ended Queue)
    // ==============================================================
    cout << "\n===== DEQUE =====" << endl;
    deque<int> dq; // Syntax: deque<int> dq;  --> can insert/remove both ends

    dq.push_back(5);   // push_back(x): insert at back -> O(1)
    dq.push_front(1);  // push_front(x): insert at front -> O(1)
    dq.push_back(10);

    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    // front(), back(): access both ends -> O(1)

    cout << "Access by index: dq[1] = " << dq[1] << endl; // random access -> O(1)

    cout << "Elements (range-based): ";
    for (int x : dq) cout << x << " "; // range-based loop traversal -> O(n)
    cout << endl;

    dq.pop_front(); // removes front element -> O(1)
    dq.pop_back();  // removes back element -> O(1)

    cout << "After popping both ends: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

    // ==============================================================
    //                   COMPARISON & DIFFERENCE
    // ==============================================================
    /*
        ===================== DIFFERENCES =====================

        1. stack: LIFO (Last In First Out)
           - Only access top element.
           - No direct access to middle elements.
           - Built using deque or vector internally.
           - Time complexities:
                push() -> O(1)
                pop()  -> O(1)
                top()  -> O(1)

        2. queue: FIFO (First In First Out)
           - Access only front and back.
           - No random access to middle elements.
           - Built using deque or list internally.
           - Time complexities:
                push()  -> O(1)
                pop()   -> O(1)
                front() -> O(1)

        3. deque: Double-ended queue
           - Insert/delete from both front and back.
           - Supports random access using index.
           - More flexible than stack/queue.
           - Time complexities:
                push_back(), push_front() -> O(1)
                pop_back(), pop_front()   -> O(1)
                front(), back(), [i]      -> O(1)

        4. vector: Dynamic array
           - Supports random access.
           - Fast insertion/removal at end only (O(1)).
           - Slow insertion/removal at front (O(n)).
           - Time complexities:
                push_back()  -> O(1)
                pop_back()   -> O(1)
                insert()/erase() at front/middle -> O(n)
                access by index -> O(1)

        ---------------- SUMMARY TABLE ----------------
        | Structure | Access Type | Ends for Insertion | Random Access | Typical Use            |
        |------------|--------------|--------------------|----------------|------------------------|
        | stack      | LIFO         | Top only           | ❌              | Function calls, Undo   |
        | queue      | FIFO         | Front/Back         | ❌              | Scheduling, Buffers    |
        | deque      | Both         | Both               | ✅              | Sliding window, Palindrome |
        | vector     | Indexed      | Back only          | ✅              | Arrays, Dynamic storage |

        -------------------------------------------------
    */

    return 0;
}