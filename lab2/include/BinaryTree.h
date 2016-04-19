#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>

namespace BinaryTree {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    struct Stack {
        Stack() {
            count = 0;
        }

        int isEmpty() {
            if ( count == 0 )
                return 1;
            else
                if ( count == n )
                    return -1;
                else
                    return 0;
        }

        void push( Node* data ) {
            a[count] = data;
            count++;
        }

        Node* pop() {
            Node* res = a[count - 1];
            count--;
            return res;
        }

    private:
        static const int n = 10000;
        Node* a[n];
        int count = 0;
    };

    void clean( Node **root ) {
        if ( *root ) {
            clean( &( ( *root )->left ) );
            clean( &( ( *root )->right ) );
            delete *root;
        }
    }

    void preOrderTraversal( Node* tree ) {
        Stack stack;
        int count = 0;
        bool left = false;
        while ( stack.isEmpty() != 1 || tree != nullptr ) {
            if ( tree != nullptr ) {
                for ( int i = 0; i < count; i++ )
                    std::cout << "|";
                std::cout << tree->data << std::endl;
                if ( tree->right ) {
                    stack.push( tree->right );
                }
                tree = tree->left;
                count++;
            } else {
                tree = stack.pop();
                count++;
            }
        }
    }

    int search( int data,  Node* tree ) {
        Stack stack;

        int count = 0;
        while ( stack.isEmpty() != 1 || tree != nullptr ) {
            if ( tree != nullptr ) {
                count++;
                if ( tree->data == data )
                    return count - 1;
                if ( tree->right ) {
                    stack.push( tree->right );
                }
                if ( data < tree->data )
                    tree = tree->left;
                else
                    tree = nullptr;
            } else {
                tree = stack.pop();
            }
        }

        return 0;
    }

    void push( int data, Node **root ) {
        if ( *root == nullptr ) {
            ( *root ) = new Node;
            ( *root )->data = data;
            ( *root )->left = ( *root )->right = nullptr;
            return;
        } else {
            if ( data > ( *root )->data )
                push( data, &( ( *root )->right ) );
            else if ( data <= ( *root )->data )
                push( data, &( ( *root )->left ) );
        }
    }

    namespace Recursion {
        void preOrderTraversal( Node* tree ) {
            if ( tree != nullptr ) {
                std::cout << std::setw(7) << tree->data << std::endl;
                Recursion::preOrderTraversal( tree->left );
                Recursion::preOrderTraversal( tree->right );
            }
        }

        void search( int data, Node* tree, int &count ) {
            if ( tree != nullptr ) {
                count++;
                if ( tree->data == data ) {
                    count--;
                    return;
                }
                if ( tree->left != nullptr )
                    Recursion::search( data, tree->left, count );
                if ( tree->right != nullptr )
                    Recursion::search( data, tree->right, count );
            }
        }
    }
};

#endif // BINARYTREE_H_INCLUDED
