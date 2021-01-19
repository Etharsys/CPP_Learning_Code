#include <iostream>

#include "Histogram.h"

using namespace std;

int main ()
{
    /*Histogram histo;

    string chaine = "koukoulesloulous";

    histo.analyze(chaine);

    cout << chaine << " : ";
    histo.print();
    cout << endl;
    */

    Histogram h1, h2;
    Histogram h3 { Histogram { h1 } };

    return 0;
}