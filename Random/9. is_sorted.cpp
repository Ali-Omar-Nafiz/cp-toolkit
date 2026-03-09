// is_sorted(begin, end, comp) function:
// - checks if a vector, array, set, etc. is sorted or not in the given range

Parameters:
begin - starting iterator or address
end - ending iterator or address
[begin, end)
comp - custom comparator (by default ascending)

Return Values:
True: If the array / vector / etc. is sorted
False: If not sorted


// check whether an array is sorted or not
int arr[5] = {1, 3, 2, 4, 5};
bool chk = is_sorted(arr, arr + 5);
cout << chk << endl;  // prints 0


// check whether a vector is sorted or not in a given range
vector < int > v = {1, 2, 3, 5, 6, 9, 11, 4, 56};

chk = is_sorted(v.begin(), v.begin() + 6);
cout << chk << endl;  // prints 1

chk = is_sorted(v.begin(), v.end());
cout << chk << endl;  // prints 0
