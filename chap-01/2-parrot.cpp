#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*
    int number = 0;
    */

    /*
    while (true)
    {
        cin >> number;
        cout << number << endl;
        if (number == -1)
        {
            break;
        }
    }
    */

    /*
    do
    {
        cin >> number;
        cout << number << endl;
    } while (number != -1);
    */

    /*
    for (auto i = 0; i < 10; ++i){
        cin >> number;
        cout << number << endl;
    }
    */

    string word;
    for (auto i = 0; i < 10; ++i){
        cin >> word;
        cout << "Croaw " << word << "!" << endl;
    }
    

    return 0;
}
