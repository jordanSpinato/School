
#ifndef binstree_CPP
#define binstree_CPP

// =========================================================

//HW4 BST
//Your name: Jordan Spinato
//October 27
//Complier:  GNU CodeBlocks
//File type: BinSearchTree .cpp -- implement file

//================================================================


#include <iostream>
using namespace std;

#include "binaryTreeHeader.h" // notice change here....

// constructor  initializes Root
BST::BST()
{
    Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
    dtraverse(Root); // traverse to delete all vertices in post order
    Root = NULL;
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:  pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // post order traversal
{
    if (V != NULL)
    {
        dtraverse(V->Left);         // visit left sub tree of V
        dtraverse(V->Right);       // visit right sub tree of V
        delete V;                  // deletes V
    }
}


// PURPOSE: Show elements in IN order traversal from the Root
void BST::ShowInOrder()
{
    cout << "Elements in the IN order: " << endl;
    INorderTraversal(Root);  // start in-order traversal from the root
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
        INorderTraversal(V->Left);
        cout << V->Elem << endl;
        INorderTraversal(V->Right);
        // ** traverse left sub-tree of V recursively
        // ** display V's element and do endl;
        // ** traverse right sub-tree of V recursively
    }
}

//--------------------------------------------------------------------------------
// PURPOSE:  Show elements in PRE order traversal from the Root
// This is the same as Depth First Traversal
void BST::ShowPreOrder()
{
    cout << "Elements in the PRE order:" << endl;
    PREorderTraversal(Root);  // start pre-order traversal from the root
}

//---------------------------------------------------------------------------------
// PURPOSE: Does PRE order traversal from V recursively
// PARAM: pointer to the vertex to be visited now
void BST::PREorderTraversal(Vertex *V)
{
    if (V != NULL)
    {
        cout << V ->Elem << endl;
        PREorderTraversal(V->Left );
        PREorderTraversal(V-> Right);
        // ** display V's element and do endl;
        // ** traverse left sub-tree of V recursively
        // ** traverse right sub-tree of V recursively

    }
}

//--------------------------------------------------------------------------------
// PURPOSE: Adds a vertex to the binary search tree for new element
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
//     - smaller than the current -> go to the left
//     - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::Insertvertex(elem_t E)
{

    Vertex *N;       // N will point to the new vertex to be inserted
    N = new Vertex;        // a new vertex is created
    N->Left  = NULL;     // make sure it does not
    N->Right = NULL;    // point to anything
    N->Elem  = E;            // put element E in it

    cout << "Trying to insert " << E << endl;

    if (Root == NULL)  // Special case: we have a brand new empty tree
    {
        Root = N;      // the new vertex is added as the root
        cout << "...adding " << E << " as the root" << endl;
    }

    else  // the tree is not empty
    {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V

        while (V != NULL)  // go down the tree until you cannot go any further
        {
            if (N->Elem == V->Elem) // special case
            {
                cout << "...error: the element already exists" << endl;
                return;
            }

            // new vertex is  smaller current vertex
            else if (N->Elem < V->Elem)  // what I have is smaller than V
            {
                cout << "...going to the left" << endl;
                Parent = V;
                V = V -> Left;
                // ** change Parent to be V to go down
                // ** change V to be V's Left
            }

            // new vertex is larget than current vertex
            else // what I have is bigger than V
            {
                cout << "...going to the right" << endl;
                Parent = V;
                V = V-> Right;
                // ** change Parent to be V to go down
                // ** change V to be V's Right
            }

        }//end of while

        // reached NULL -- Must add N as the Parent's child
        // reached last level

        if (N->Elem < Parent->Elem)
        {
            Parent -> Left = N;
            // ** Parent's Left should point to the same place as N
            cout << "...adding " << E << " as the left child of " << Parent->Elem << endl;
        }
        else
        {
            Parent -> Right = N;
            // ** Parent's Right should point to the same place as N
            cout << "...adding " << E << " as the right child of " << Parent->Elem << endl;
        }

    }// end of normal case
}// end of InsertVertex


//---------------------------------------------------------------------------
// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{

    cout << "Trying to delete " << E << endl;

    Vertex *V;              // the current vertex
    Vertex *Parent = NULL;  // its parent


    // if the element to delete is the only one..
    if ((E == Root-> Elem) && (Root-> Left == NULL) && (Root-> Right == NULL))
    {
        cout << "...deleting the lonely root" << endl;
        delete Root;
        Root = NULL;
        return;
    }

    // ** if V is the root with one child
    if( (E == Root -> Elem) && ((Root-> Right == NULL) || (Root-> Left == NULL)) )
    {
        // if the right is null put the left at the root
        if (Root -> Right == NULL)
        {
            cout << "Right is Null" << endl;
            V = Root;
            Root = Root -> Left;
            delete V;
            return;
        }

        // if the left is null put the right at the root
        else if ( Root-> Left == NULL)
        {

            cout << "Left is Null" << endl;
            V = Root;
            Root = Root -> Right;
            delete V;
            return;
        }
    } // end if v root with one child


    V = Root;

// Otherwise deleting something else
    while (V != NULL)
    {
        if ( E == V->Elem)   // found it
        {
            remove(V,Parent);
            // ** call remove here to remove V
            return;
        }

        // if the element is less than < vertex current element we go left
        else if (E < V->Elem)
        {
            cout << "...going to the left" << endl;
            Parent = V;
            V = V-> Left;

            // ** update Parent and V here to go down
        }

        // otherwise we go right.. element is greater than > the vertex element.. go right
        else if (E > V-> Elem)
        {
            cout << "...going to the right" << endl;
            Parent = V;
            V = V-> Right;
            // ** update Parent and V here to go down
        }

    }// end of while

    // reached NULL  -- did not find it
    cout << "Did not find the key in the tree." << endl;

}// end of DeleteVertex

//---------------------------------------------------------------------------
// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf delete it
// Case 2: it has just one child bypass it
// Case 3: it has two children replace it with the max of the left //subtree

void BST::remove(Vertex *V, Vertex *P)
{
    cout << "We will remove: " << V->Elem << endl;
    if (P == NULL)
        cout << "No parent" << endl;
    else
        cout << "The parent is: " << P-> Elem << endl;

//----------------------------------------------------------------------
// case 1 -- no children vertex is a leaf--
//-----------------------------------------------------------------------
// Vertex's left and right are null... it is a leaf
    if ((V -> Left == NULL) && (V -> Right == NULL))// ** if V is a leaf (case 1)
    {
        cout << ".. removing a leaf" << endl;

        if (P->Left == V)// Parents -> Left == V (V is a left child of P)
        {
            cout << V-> Elem << " has been deleted" << endl;
            delete V;
            P -> Left = NULL;
            // ** delete V and also make Parent's left NULL
        }

        else // V is a right child of the Parent
        {
            cout << V-> Elem << " has been deleted" << endl;
            delete V;
            P -> Right = NULL;
            // ** delete V and also make Parent's right NULL
        } // end else

        return;
    } // end case 1

//-------------------------------------------------------------------------
// case 2 -- V has one child on the Left or Right --
//-------------------------------------------------------------------------

//=========================================================
// Vertex element is less than Parent element ..we will have a left side..

// left side of parent.. now we decide to add right or left child to left side.
    if ( V == Root)
        cout << "At The ROOT!" << endl;

    else if (V -> Elem < P -> Elem)
    {
        cout << "The child is on the 'Left' side of parent" << endl;

        if (V-> Right == NULL && V-> Left != NULL)//V has just the left child .. Right is null
        {
            cout << "removing a vertex with just the left child" << endl;
            P -> Left = V-> Left;
            delete V;
            return;
            // ** Make Parents left or right point to the left child and
            //   delete V (You need if then else to determine left or right)
        } // end if left child

        else if (V -> Left == NULL && V-> Right != NULL) //V has just the right child .. Left is null)
        {
            cout << "removing a vertex with just one right child" << endl;
            P -> Left = V -> Right;
            delete V;
            return;
        } // end if right child

    } // end if left side tree


// Vertex element is greater than Parent element.. we will have a right side..
    else if ( V -> Elem > P -> Elem)
    {
        cout << "The child is on the 'Right' side of parent" << endl;
        if (V-> Right == NULL && V-> Left != NULL)//V has just the left child .. Right is null
        {
            cout << "removing a vertex with just the left child" << endl;
            P -> Right = V-> Left;
            delete V;
            // ** Make Parents left or right point to the left child and
            //   delete V (You need if then else to determine left or right)
            return;
        } // end if left child

        else if (V -> Left == NULL && V-> Right != NULL) //V has just the right child .. Left is null
        {
            cout << "removing a vertex with just the right child" << endl;
            P -> Right = V-> Right;
            delete V;
            // ** Make Parents left or right point to the right child and
            //delete V (need if then else to determine left or right)
            return;
        } // end if right child



    } // end if determine right side


//------------------------------------------------------------------------------
//case 3  -- 2 children
//----------------------------------------------------------------------------------
    if (V-> Right != NULL && V-> Left != NULL)// V has two children (case 3)
    {
        cout << "...removing an internal vertex with children" << endl;
        cout << ".....find the MAX of its left sub-tree" << endl;
        elem_t Melem;
        // finding the max value in the left sub tree right most element
        Melem = findMax(V); // find MAX element in the left sub-tree of V
        cout << ".....replacing " << V->Elem << " with " << Melem << endl;
        // ** Replace V's element with Melem here
        V-> Elem = Melem;
    }

}// end of remove



//------------------------------------------------------------------
// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{

    Vertex *Parent = V;
    V = V->Left;          // start with the left child of V

    // ** while the right child of V is still available
    while ( V-> Right != NULL)
    {
        Parent = V;
        V = V -> Right;
        // ** update Parent and V to go to the right
    }

    // reached NULL Right  -- V now has the MAX element
    elem_t X = V->Elem;
    cout << ".....Max is " << X << endl;
    remove(V, Parent);    // remove the MAX vertex
    return X;             // return the MAX element

}// end of FindMax




#endif
