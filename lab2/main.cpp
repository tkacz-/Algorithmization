#include <iostream>
#include <iomanip>
#include <cstdlib>

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

    cout << endl << "Binary Tree:" << endl;
    Recursion::preOrderTraversal( tree );

    cout << endl << "Stack:" << endl;
    preOrderTraversal( tree );

    cout << endl << "Write elem for searching: ";
    cin >> value;
    int count = 0;
    search( value, tree );

    clean( &tree );
    return 0;
}
