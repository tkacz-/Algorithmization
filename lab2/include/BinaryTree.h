#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>

namespace BinaryTree {
    struct node {
        int data;
        node* l;
        node* r;
    };

    void push( int data, node **tree ) {
        if ( *tree == nullptr ) {
            ( *tree ) = new node;
            ( *tree )->data = data;
            ( *tree )->l = ( *tree )->r = nullptr;
            return;
        } else {
            if ( data > ( *tree )->data )
                push( data, &( ( *tree )->r ) );
            else
                push( data, &( ( *tree )->l ) );
        }
    }

    void directBypass ( node* tree ) {

    }

    namespace Recursion {
        void directBypass( node* tree ) {
            if ( tree != nullptr ) {
                std::cout << std::setw(7) << tree->data << std::endl;
                Recursion::directBypass( tree->l );
                Recursion::directBypass( tree->r );
            }
        }

        void search( int data, node* tree, int &count ) {
            if ( tree != nullptr ) {
                count++;
                if ( tree->data == data )
                    std::cout << "Found " << data << " with step " << count - 1 << std::endl;
                Recursion::search( data, tree->l, count );
                Recursion::search( data, tree->r, count );
            }
        }
    }
};



#endif // BINARYTREE_H_INCLUDED
