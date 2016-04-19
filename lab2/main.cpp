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

    cout << endl << "Pre-order traversal without recursion:" << endl;
    preOrderTraversal( tree );

    cout << endl << "Write elem for searching: ";
    cin >> value;
    int count = search( value, tree );
    cout << "Found " << value << " with step " << count << endl;
    clean( &tree );

    return 0;
}
