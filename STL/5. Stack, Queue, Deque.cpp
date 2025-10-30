#include <bits/stdc++.h>
using namespace std;

int main() {

    //--------------------------STACK (LIFO)-------------------------------

    stack<int> st; // Syntax   LIFO (Last In First Out) --> Last inserted element as First output

    st.push(10); // push(x): insert element at the back -> O(1)
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // top(): returns top / last inserted element 30 -> O(1)

    st.pop(); // pop(): removes top element 30 -> O(1)

    cout << st.top() << endl;   // prints 20

    cout << st.empty() << endl; // empty(): returns 1 if stack is empty -> O(1)

    // Accessing all elements
    while (!st.empty()) {
        cout << st.top() << " "; // access top before popping -> O(1)
        st.pop();                // remove top -> O(1)
    }
    cout << endl;

    //------------------------QUEUE (FIFO)--------------------

    queue<int> q; // Syntax   FIFO (First In First Out) --> First inserted element as First output

    q.push(1); // push(x): adds element at the back -> O(1)
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // front(): returns front / first inserted element -> O(1)
    
    q.pop(); // pop(): removes front element -> O(1)

    cout << q.front() << endl;   // prints 1
    cout << q.empty() << endl;   // prints 1 if the queue is empty

    // Accessing all elements

    while (!q.empty()) {
        cout << q.front() << " "; // access front before popping -> O(1)
        q.pop();                  // remove front -> O(1)
    }
    cout << endl;

    
    //---------------DEQUE (Double-Ended Queue)------------------

    deque<int> dq; // Syntax  Deque can insert/remove from both ends

    dq.push_back(5);   // push_back(x): insert at back -> O(1)
    dq.push_front(1);  // push_front(x): insert at front -> O(1)
    dq.push_back(10);

    cout << dq.front() << dq.back() << endl;
    // front(), back(): access both ends -> O(1)

    cout << dq[1] << endl; // index based random access -> O(1)

    for (int x : dq) cout << x << " "; // range-based loop traversal -> O(n)
    // prints 5 1 10

    dq.pop_front(); // removes front element 5 -> O(1)
    dq.pop_back();  // removes back element 10 -> O(1)

    for (int x : dq) cout << x << " ";
    // prints 1

    cout << dq.empty() << endl;   // prints 1 if the deque is empty()

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