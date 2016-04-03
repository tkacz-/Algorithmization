/*
 * Binary tree.
 * Pre-order traversal with recursion and without it
 * ( using stack )
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "include/BinaryTree.h"

using namespace std;
using namespace BinaryTree;

static const int m = 10000;

int main()
{
    int n;
    cout << "Write number of elements = ";
    cin >> n;

    Node* tree = nullptr;
    int value;
    srand( time(NULL) );
    cout << setw(7) << "Value:" << endl;
    for ( auto i = 0; i < n; i++ ) {
        value = 1 + rand() % 10;
        cout << setw(7) << value << endl;
        push( value, &tree );
    }

    cout << endl << "Pre-order traversal with recursion:" << endl;
    Recursion::preOrderTraversal( tree );

    cout << endl << "Pre-order traversal without recursion:" << endl;
    preOrderTraversal( tree );

    cout << endl << "Write elem for searching: ";
    cin >> value;
    int count = search( value, tree );
    cout << "Found " << value << " with step " << count << endl;
    count = 0;
    Recursion::search( value, tree, count );
    cout << "Found " << value << " with step " << count << endl;
    clean( &tree );

    Node* tree1 = nullptr;
    int elem;
    srand( time(NULL) );
    for ( int i = 0; i < m; i++ ) {
        value = 1 + rand() % 1000;
        if ( i == m / 2 )
            elem = value;
        push( value, &tree1 );
    }

    clock_t timeBegin, timeEnd;
    double delta;
    timeBegin = clock();
    int res = search( elem, tree1 );
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Found " << elem << " with step " << res << endl;
    cout << "Searching without recursion: " << delta << endl;

    res = 0;
    timeBegin = clock();
    Recursion::search( elem, tree1, res );
    timeEnd = clock();
    delta = (double) ( timeEnd - timeBegin ) / CLOCKS_PER_SEC;
    cout << endl << "Found " << elem << " with step " << res << endl;
    cout << "Searching with recursion: " << delta << endl;

    return 0;
}
