#include <list>
#include <array>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

enum Fruit
{
    Abricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays()
{
    array<string, Fruit_Count> stock;
    stock[Abricot] = "abricot";
    stock[Cherry] = "cherry";
    stock[Mango] = "mango";
    stock[Raspberry] = "raspberry";
}

void try_lists()
{
    std::list<int> l1;
    std::list<int> l2;
    std::list<int> l3;
    std::list<int> l4;
    l1.emplace(l1.end(), 1 );
    l2.emplace(l2.end(), 2 );
    l3.emplace(l3.end(), 3 );
    l3.emplace(l3.end(), 4 );
    l4.emplace(l4.end(), 5 );
    l3.emplace(l3.end(), 6 );

    l1.merge(l2);
    l3.merge(l4);

    auto it = l1.begin();
    advance(it, l1.size() / 2);
    l1.splice(it, l3);

    for (auto e : l1)
    {
        cout << e << endl;
    }

}

void try_stacks()
{
    stack<int, vector<int>> stack;
    stack.emplace(0);
    stack.emplace(1);
    stack.emplace(2);

    for (auto e : stack)
    {
        cout << e << endl;
    }
}

int main()
{
    try_arrays();
    try_lists();
    try_stacks();

    return 0;
}