#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    /*
    vector<int> two_to_four(&array[2], &array[5]);
    for (auto v : two_to_four)
    {
        cout << v << endl;
    }
    */

    /*
    vector<int> full(array, array+6);

    
    for (size_t i = 0, j = full.size() - 1; i < j; ++i, --j)
    { //revert
        swap(full[i], full[j]);
    }
    

    for (auto it = full.begin(); it != full.end(); it += 2)
    { //duplic
        it = full.insert(it, *it);
    }

    for (auto v : full)
    { //print
        cout << v << endl;
    }

    while (!full.empty())
    { //poper
        full.pop_back();
    }

    for (auto v : full)
    { //print
        cout << v << endl;
    }
    */

    vector<int> full2(array, array+10);
    full2.erase(full2.begin() + 2, full2.begin() + 6); // erase

    for (auto v : full2)
    { //print
        cout << v << endl;
    }

    const auto v = find(full2.begin(), full2.end(), 6);
    if (v != full2.end())
    {
        full2.erase(v);
    }

    for (auto v : full2)
    { //print
        cout << v << endl;
    }

    full2.assign(5, 2);

    for (auto v : full2)
    { //print
        cout << v << endl;
    }

    full2.assign( { 0, 2, 32, -4, 3 } );
    for (auto v : full2)
    { //print
        cout << v << endl;
    }
    
    return 0;
}