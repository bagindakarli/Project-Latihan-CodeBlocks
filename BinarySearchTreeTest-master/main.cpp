#include "BINARYTREE.h"

int main(){

    /** Lengkapi biodata anda disini */
    char name[] = "Anvaqta Tangguh Wisesa";
    int Nim[10] = {1,3,0,1,1,7,0,3,9,0};
    char Kelas[] = "IF-41-01";


    cout << " Module 8: BINARY SEARCH TREE " << endl;
    cout << " ---------------------------------------------- " << endl;
    cout << " Name  : "<<name<<endl;
    cout << " NIM   : ";for(int i=0;i<10;i++){cout<<Nim[i];}cout<<endl;
    cout << " Kelas : "<<Kelas<<endl;
    cout << " ---------------------------------------------- " << endl;
    cout << " Let's practice !!!";
    cin.get();
    address BST;
    address p;
    createBST(BST);
        int data[] = {18 , 3 , 1 , 6 , 4 , 7 , 25 , 20 , 36 , 29};
        cout<<"\n Array : ";
        int lenData = sizeof(data)/sizeof(data[0]);
        for(int i=0;i<lenData;i++){
            cout<<data[i]<<" - ";
            p = allocation(data[i]);
            insertBST(BST,p);
        }
        cout<<endl<<endl;
        cout<<" Traversals of Tree : "<<endl;
        cout<<" \tPreorder : "<<endl;
        cout<<" \t Correct answer : 18 - 3 - 1 - 6 - 4 - 7 - 25 - 20 - 36 - 29 - "<<endl;
        cout<<" \t Your answer \t: ";
        preOrder(BST);
        cout<<endl<<endl;
        cout<<" \tPostorder : "<<endl;
        cout<<" \t Correct answer : 1 - 4 - 7 - 6 - 3 - 20 - 29 - 36 - 25 - 18 - "<<endl;
        cout<<" \t Your answer \t: ";
        postOrder(BST);
        cout<<endl;
        cin.get();
        cout<<" \n Attribute of TREE : "<<endl;
        cout<<" \tLevel\t\t: "<<countlevel(BST)<<endl;
        int Height = countHeight(BST)-1;
        if (Height<0){ Height = 0;}
        cout<<" \tHeight\t\t: "<<Height<<endl;
        cout<<" \tLeaves\t\t: "; printLeaves(BST);
        cout<<endl;
        cout<<" \tNode of Tree \t: "<<countNode(BST)<<endl;
        cout<<"\t====TEST DEPTH====\n";
        int x;
        cout<<"\tInsert Node\t: ";cin>>x;
        address X=findNode(BST,x);
        cout<<"\tDepth \t\t: ";
        if (X!=NULL)cout<<depth(x,BST)<<endl;
        else cout<<0<<endl;
        cout<<"\t==================\n\n";
        cout<<"\tLevel Order\n";
        cout<<"\t==================\n";
        levelorder(BST);
        cin.get();
    return 0;
}
