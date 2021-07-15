#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
using namespace std;

#define info(A) A->info
#define left(A) A->left
#define right(A) A->right
#define NIL NULL

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
};

void createBST(address &root);
address allocation(infotype X);
void insertBST(address &root, address node);
void preOrder(address root);
void postOrder(address root);
address findNode(address root, infotype X);
/**  mengembalikan kedalaman dari Tree keseluruhan*/
int countHeight(address root);
/** menghitung kedalaman suatu node*/
int depth(int x,address root);
/** menghitung level*/
int countlevel(address root);
void levelorder(address root);
void printgivenlevel(address root,int level);
void printLeaves(address root);

/**  mengembalikan jumlah Nodes yang terdapat pada Tree */
int countNode(address root);
void printAncestor(address root, address node, bool &found);

#endif // BINARYTREE_H_INCLUDED
