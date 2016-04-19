/*
 * Searching elements in open addressing hash map
 * and in array.
 * How long does it take to find element
 * in hash map and array ?
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "HashMap.h"

using namespace std;

static const int m = 300;
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
            << setw(20) << "Value" << endl;
    HashMap<string> hashMap;
    string key;
    string str;
    srand(time(NULL));
    for ( int i = 0; i < n; i++ ) {
        key += genRandom();
        str += genRandom();

        cout << setw(7) << key << setw(20) << str << endl;
        hashMap.put(key, str);

        if ( key.length() >= 6 )
            key = "";
    }

    cout << endl << "In hash map: " << endl
            << setw(7) << "Segment"
            << setw(20) << "Value" << endl;
    for ( int i = 0; i < 27; i++ ) {
        cout << setw( 7 ) << i;
        hashMap.show( i );
    }

    str = "";
    key = "";
    HashMap<string> hashMap1;
    string arr[m];
    string search_key;
    string elem;
    srand(time(NULL));
    for ( int i = 0; i < m; i++ ) {
        key += genRandom();
        str += genRandom();

        if ( i == m / 2 ) {
            elem = str;
            search_key = key;
        }
        arr[i] = str;
        hashMap1.put(key, str);

        if ( key.length() >= 6 )
            key = "";
    }

    clock_t timeBegin, timeEnd;
    double delta;
    timeBegin = clock();
    str = hashMap1.find( search_key, elem );
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Searching: " << str << endl;
    cout << "Time for searching in hash table: " << delta << endl;

    timeBegin = clock();
    for ( int i = 0; i < m; i++ ) {
        if ( arr[i] == elem )
            break;
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Time for searching in array: " << delta << endl;

    return 0;
}
