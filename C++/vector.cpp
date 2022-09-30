#include <bits/stdc++.h>
using namespace std;

int main()
{
    // What are Pairs?
    // Pairs are a type of data type which are used to store values in pairs of 2, but we can also store more values in pairs by using the nested properties of pairs

    pair<int, int> p = {1, 3}; // pair declared which stores 2 integers
    cout << p.first << " "
         << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 3}}; // Nested pairs
    cout << p1.first << " "
         << p1.second.first << " "
         << p1.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {4, 5}}; // Arrays of pair data type
    cout << arr[0].first << " "
         << arr[0].second << endl;

    //*****************************************************************************************************
    // What are Vectors?
    // Vectors are containers which can be dynamically modified(unlike arrays)

    // TOPIC : Declaration of different types of vectors :-

    vector<int> v;     // Creates an empty container {}
    v.push_back(1);    // Inserts 1 in the container dynamically, {1}
    v.emplace_back(2); // Same as above, but faster, {1,2}

    vector<pair<int, int>> vec; // Vector of pair data type
    v.push_back({1, 2});        // Syntax to enter values in a vector of pair data type
    v.emplace_back(3, 4);       // Same as above, but notice that no curly braces required here

    vector<int> v1(5, 100); // This makes a container of size 5 having 100 in all indexes
    vector<int> v2(5);      // This makes a container of size 5 having 0 in all indexes
    vector<int> v3(v1);     // This makes a copy of vector v1 in v3

    // How to access the elements of a vector array?
    // We can either simply use the normal technique i.e. nums[i] or, we can use ITERATORS

    // TOPIC : Accessing the elements of the vector :-

    //  Syntax:-
    vector<int>::iterator i1 = v1.begin(); // This makes a pointer i, which points to the memory address of the starting index
    cout << *i1 << endl;                   // This will print the value at the starting index
    i1++;                                  // Simple Increment of the iterator to the next index

    vector<int>::iterator i2 = v1.end(); //*******This will point somewhere after the last index, and not the last index**********

    // How to Print the elements of a Vector?
    // 3 Ways, each better than the last :-

    // TOPIC : Printing the elements of a Vector :-

    // 1.
    for (vector<int>::iterator i1 = v1.begin(); i1 != v1.end(); i1++)
    {
        cout << *(i1) << " ";
    }

    // 2.
    for (auto i1 = v1.begin(); i1 != v2.end(); i1++)
    {
        cout << *(i1) << " ";
    }

    // 3.
    for (auto i1 : v1)
    {
        cout << i1 << " ";
    }

    // TOPIC : Deletion of elements of a Vector :-

    // For ex:- {10, 20, 30 ,40 ,50 ,60}
    v1.erase(v1.begin() + 1);                 // After this, the vector left will be {10, 30 ,40 ,50 ,60}
    v1.erase(v1.begin() + 1, v1.begin() + 4); // Used to delete a range of elements. Note that this function deletes all the elements between the given 2 indices, including the starting index, but not the end index. After this, the vector left will be {10, 60}

    // TOPIC : Insertion of element in a Vector :-

    // For ex:- {100, 200, 300, 400, 500}
    v1.insert(v1.begin(), 300);       // After this, the vector will be {300, 100, 200, 300, 400, 500}
    v1.insert(v1.begin() + 1, 10);    // After this, the vector will be {300, 10, 100, 200, 300, 400, 500}
    v1.insert(v1.begin() + 2, 2, 10); // "2" means that we want to add two new elements, and 2 copies of 10 will be inserted at the given position. Thus, After this, the vector will be {300, 10, 100, 10, 10, 200, 300, 400, 500}

    vector<int> v5 = {20, 13};
    v1.insert(v1.begin(), v5.begin(), v5.end()); // Used to insert a vector inside another vector. After this, the vector will be {20, 13, 300, 10, 100, 10, 10, 200, 300, 400, 500}

    // Some more important functions in vector :-

    // For ex:- v1 = {10, 20}
    cout << v1.size(); // Gives how many elements are there in the vector currently. Here, 2
    v1.pop_back();     // Removes the last element. After this, v1 = {10}

    // For ex:- v1 = {10, 20} and v2 = {30, 40}
    v1.swap(v2); // Will swap the vectors. After this, v1 = {30, 40} and v2 = {10, 20}

    v1.clear(); // Clears or deletes the entire vector. After this, v1 = {}

    cout << v1.empty(); // Prints true if vector is empty, else false

    sort(v1.begin(), v1.end());                 // Sorts the vector in ascending order
    sort(v1.begin(), v1.end(), greater<int>()); // Sorts the vector in descending order
    reverse(v1.begin(), v1.end());              // Reverses the vector
    return 0;
}