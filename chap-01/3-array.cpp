#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "Need one argument, " << argc - 1 << " where given" << endl;
        return -1;
    }
    
    /*
    auto size = 50;
    int values[size] = {};
    for (int i = 0; i < size; ++i)
    {
        values[i] = i + 1;
    }

    for (auto value : values)
    {
        std::cout << value << std::endl;
    }
    */

    cout << "Size du tableau : " << argv[1] << endl;
    int length = stoi(argv[1]);
    
    /*
    int* array = new int[length] {};
    for (auto i = 0; i < length; ++i) {
        cout << array[i] << endl;
    }
    */

    vector<int> array;
    for(auto i = 0; i < length; ++i)
    {
        array.emplace_back(i + 1);
    }
    
    for(auto value : array)
    {
        cout << value << endl;
    }

    return 0;
}
