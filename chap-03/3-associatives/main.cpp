#include <set>
#include <unordered_set>
#include <iostream>
#include <map>

#include "keys.h"

using namespace std;

using Owner = pair<string, string>;

int main()
{
    /*
    set<ComparableDog> s;

    ComparableDog boule { "boule", "coker" };
    s.emplace(boule);
    ComparableDog medor { "medor", "labrador" };
    s.emplace(medor);

    cout << s.size() << endl;

    auto boule_cpy = boule;
    s.emplace(boule_cpy);

    cout << s.size() << endl;
    */
    /*
    unordered_set<HashableDog> us;

    HashableDog boule { "boule", "coker" };
    us.emplace(boule);

    cout << us.size() << endl;
    */

    std::map<ComparableDog, Owner> owners_by_dog;

    ComparableDog medor { "medor", "labrador" };
    ComparableDog gus { "gus", "bordercollie" };
    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owners_by_dog.insert(std::make_pair(medor, Owner { "Claire", "David" }));
    //owners_by_dog.insert_or_assign(gus, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    //owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert or try_emplace)

    //owners_by_dog.insert_or_assign(gus, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)


    return 0;
}