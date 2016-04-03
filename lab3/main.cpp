#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

#include "HashMap.h"

using namespace std;

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof( alphanum ) - 1;

char genRandom() {
    return alphanum[rand() % stringLength];
}

int main()
{
    int n;
    cout << "Write number of elements: ";
    cin >> n;

    cout << "Generated:" << endl
            << setw(7) << "Key"
            << setw(10) << "Value" << endl;
    HashMap<string> hashMap;
    std::string str;
    srand(time(NULL));
    for ( int i = 0; i < n; i++ ) {
        str += genRandom();
        cout << setw(7) << i << setw(10) << str << endl;

        hashMap.put(i, str);
    }

    cout << "In hash map: " << endl
            << setw(7) << "Key"
            << setw(10) << "Value" << endl;
    for ( int i = 0; i < n; i++ ) {
        cout << setw(7) << i
                << setw(10) << hashMap.get( i ) << endl;
    }

    return 0;
}
