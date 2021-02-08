#include<vector>
#include<iostream>

using namespace std;

int main ()
{
    auto v = vector<int>();
    for (auto i = 2; i <= 100000; ++i) 
    {
        v.push_back(i);
    }

    for (auto x = 2; x*x <= 100000; ++x) 
    {
        for (auto it = v.begin() + x; it != v.end(); ) 
        {
            if (*it % x == 0 && *it != x)
            {
                it = v.erase(it);
            }
            else 
            {
                ++it;
            }
        }
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << v.size() << endl;
    
}