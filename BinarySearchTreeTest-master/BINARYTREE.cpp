#include "BINARYTREE.h"

/**  IS. -
 *   FS. root dari Tree menunjuk ke NIL */
void createBST(address &root){
    root = NIL;
}

/**  Mengembalikan Node yang memiliki Info sama dengan X */
address allocation(infotype X){
    address P =new Node;
    info(P)=X;
    right(P)=NULL;
    left(P)=NULL;
    return P;
}

/**  IS. terdefinisi suatu root dari Tree (mungkin kosong) dan sebuah Node
 *   FS. Node masukkan secara BST (Binary Search Tree) kedalam Tree
     Hint. node yang sama infonya tidak dimasukkan kedalam TREE
     BST. info left < info root < info right */
void insertBST(address &root, address node){
    if(root==NULL){
        root=node;
    }
    if(info(node)<info(root)){
        //left(root)=node;
        insertBST(left(root),node);
    }
    else if (info(node)>info(root)){
        //right(root)=node;
        insertBST(right(root),node);
    }
}

/**  IS. terdefinisi root dari Tree
 *   FS. menampilkan Node child secara preOrder (root >> left child >> right child) */
void preOrder(address root){
    if(root==NULL){
        return;
    }
    cout<<info(root)<<" - ";
    preOrder(left(root));
    preOrder(right(root));
}

/**  IS. terdefinisi root dari Tree
 *   FS. menampilkan Node child secara postOrder (left child >> right child >> root) */
void postOrder(address root){
    if(root==NULL){
        return;
    }
    postOrder(left(root));
    postOrder(right(root));
    cout<<info(root)<<" - ";
}

/**  mengembalikan address dari root/node apabila info dari node sama dengan X, dan NIL apabila sebaliknya
 *   hint. Pencarian didalam BST, info left < info root < info right */
address findNode(address root, infotype X){
    if (root!=NULL){
        if(info(root)==X){
            return root;
        }
        else if(X<info(root)){
            return findNode(left(root),X);
        }
        else{
            return findNode(right(root),X);
        }
    }
}

/**  mengembalikan kedalaman dari Tree keseluruhan*/
int countHeight(address root){
    if (root==NULL){
        return 0;
    }
    else{
        int i= countHeight(right(root));
        int j= countHeight(left(root));
        if(i>j){
            return 1+countHeight(right(root));
        }
        else{
            return 1+countHeight(left((root)));
        }
        //return 1+countHeight(left(root));//+countHeight(right(root));
    }
}

/**  IS. terdefinisi root dari Tree
 *   FS. Menampilkan info node yang merupakan daun (atau node yang tidak memiliki child)*/
void printLeaves(address root){
    if(root==NULL){
        return;
    }
    if ((left(root)==NULL)&&(right(root)==NULL)){
        cout<<info(root)<<" - ";
    }
    else{
        printLeaves(left(root));
        printLeaves(right(root));
    }
}

/**  mengembalikan jumlah Nodes yang terdapat pada Tree */
int countNode(address root){
    if (root==NULL){
        return 0;
    }
    if ((left(root)==NULL)&&(right(root)==NULL)){
        return 1;
    }
    else{
        return 1+countNode(left(root))+countNode(right(root));
    }
}

/**  [BONUS] */
/**  IS. terdefinisi root suatu Tree dan suatu node yang ada didalam tree
 *   FS. found berisi True jika node ditemukan, dan menampilkan semua leluhur dari node tersebut */
void printAncestor(address root, address node, bool &found){
    if (root == NIL){
        found = false;
    }else if (root == node){
        found = true;
    }else{
        bool leftFound;
        bool rightFound;
        printAncestor(left(root),node,leftFound);
        printAncestor(right(root),node,rightFound);
        found = leftFound || rightFound;
        if (found) {
            cout<<info(root)<<" - ";
        }
    }
}

//TP BROOO
int depth(int x,address root){
    if (root == NULL || info(root) == x) return 0;
    else if (x > info(root)) return depth(x,right(root)) + 1;
    else return depth(x,left(root)) + 1;
}
int countlevel(address root){
    if (root==NULL) return 0;
    else{
        int right=countlevel(right(root));
        int left=countlevel(left(root));
        if(left>right) return left+1;
        else return right+1;
    }
}
void printgivenlevel(address root,int level){
    if(root==NULL) return;
    if(level==1)cout<<(info(root))<<" ";
    else{
        printgivenlevel(left(root),level-1);
        printgivenlevel(right(root),level-1);
    }
}
void levelorder(address root){
   for(int i = 1; i <= countlevel(root);i++) {
      cout<<"\tLevel "<<i<<"\t: ";
      printgivenlevel(root,i);cout<<endl;
   }
}
