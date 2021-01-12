#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> count_lower(const string& entry);
void                 display_lower_occ(const vector<unsigned int>& occ);
string               concatenate(const string& str1, const string& str2);

int main (int argc, char* argv[])
{
    string entry;
    string full_entry;
    do 
    {
        cin >> entry;
        full_entry = concatenate(full_entry, entry);
        display_lower_occ(count_lower(full_entry));
    } while (entry != "");
}

vector<unsigned int> count_lower(const string& entry)
{
    vector<unsigned int> vec (26);
    for (auto c : entry)
        {
            vec[c - 'a'] += 1;
        }

    return vec;
}

void display_lower_occ(const vector<unsigned int>& occ)
{
    for (auto v : occ)
    {
        cout << v;
    }
    cout << endl;
}

string concatenate(const string& str1, const string& str2)
{
    return str1 + str2;
}