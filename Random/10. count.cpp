count() function:
Find the number of occurrences of an element in the given range of any array or STL container.

Parameters:
count(start, end, element)
start: starting iterator / address of the range
end: ending iterator / address of the range
[start, end)
element: element whose occurrence is to be counted

Return values:
- Returns the number of occurrences if the element exists in the given range
- Otherwise returns 0


Examples:

Find occurrences of a string
vector < string > v = {"Ali", "Omar", "Omar"};
cout << count(v.begin(), v.end(), "Ali") << endl;   // prints 1
cout << count(v.begin(), v.end(), "Omar") << endl;  // prints 2
cout << count(v.begin(), v.end(), "Nafiz") << endl; // prints 0


Find occurrence of a value in a multiset
multiset < int > mst = {1, 2, 2, 3};
cout << count(mst.begin(), mst.end(), 2) << endl;   // prints 2


Check whether an element exists or not in a vector
vector < int > v = {1, 2, 3};
cout << count(v.begin(), v.end(), 4) << endl;  // prints 0
