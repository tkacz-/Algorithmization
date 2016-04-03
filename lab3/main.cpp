#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

#include "HashMap.h"

using namespace std;

static const int m = 10000;
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
    int key;
    string str;
    srand(time(NULL));
    for ( int i = 0; i < n; i++ ) {
        key = rand() % 26;
        str += genRandom();
        cout << setw(7) << key << setw(10) << str << endl;

        hashMap.put(key, str);
    }

    cout << "In hash map: " << endl
            << setw(7) << "Key"
            << setw(10) << "Value" << endl;
    for ( int i = 0; i < 27; i++ ) {
        cout << setw(7) << i;
        hashMap.show( i );
    }

    cout << "For searching:" << endl;
    cout << "Value: ";
    cin >> str;
    cout << "Key: ";
    cin >> key;
    str = hashMap.find(key, str);
    cout << "Founded: " << str << endl;


    HashMap<string> hashMap1;
    string arr[m];
    int index = m / 2;
    string elem;
    srand(time(NULL));
    for ( int i = 0; i < m; i++ ) {
        key = rand() % 26;
        str += genRandom();

        if ( i == m / 2 )
            elem = str;
        arr[i] = str;
        hashMap.put(key, str);
    }

    clock_t timeBegin, timeEnd;
    double delta;
    timeBegin = clock();
    str = hashMap.find( index , elem );
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Founded into hash table: " << delta << endl;

    timeBegin = clock();
    for ( int i = 0; i < m; i++ ) {
        if ( arr[i] == elem )
            break;
    }
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Founded into array: " << delta << endl;

    return 0;
}
