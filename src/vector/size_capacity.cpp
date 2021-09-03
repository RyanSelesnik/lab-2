// A vector's size refers to how elements are currently stored within the vector
// A vector's capacity refers to how many elements it is able to store before
// having to reallocate memory.

// The vector capacity grows as it does since it is a contiguous data structure.
// i.e, if the push_back method is called continuously, eventually the memory
// will collide with other data. To avoid this all the elements are copied to a
// new location where the capacity has doubled (if the pervious location
// capacity has reached its maximum).

// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
