#include "otak.h"
#include "admin.h"


/// PUNYA PESERTA
void inLastP(ListP &LP, string NamaP)
{
    adrP x = new dataP;
    adrP q;
    Info(x).namaP = NamaP;
    if (First(LP) == NULL)
    {
        First(LP) = x;
        x->Next = NULL;
    }
    else
    {
        q = LP.First;
        while (Next(q)!=NULL)
        {
            q = q->Next;
        }
        q->Next = x;
        x->Next = NULL;
    }
}
void viewDataP(ListP &LP,ListR LR)
{
    adrR y;

    if (LR.First != NULL)
    {
            y = LR.First;
            do
            {
                cout<<"=====================================================\n";
                cout<<"=====================================================\n";
                cout<<"   Nama Peserta  : "<<Info(Bottom(y)).namaP<<endl;
                cout<<"   Nilai Peserta : "<<y->Info.nilai<<endl;
                cout<<"   Juri Penilai  : "<<Info(Top(y)).namaJ<<endl;
                cout<<"   TOTAL NILAI : "<<Info(Bottom(y)).total<<endl;
                cout<<"=====================================================\n";

                y = y->Next;
            }while (y != LR.First);
    }
    else
    {
        cout<<"NOT FOUND ! ! !\n";
    }
    getch();

}
adrP searchP(ListP LP,string Nama)
{
    adrP x;
    if (First(LP) != NULL)
    {
        x = First(LP);
        while ((x!=NULL) && (Info(x).namaP != Nama))
        {
            x = x->Next;
        }
        if (Info(x).namaP == Nama)
        {
            return x;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
void deleteP(ListP &LP,ListR &LR,string Nama)
{
    adrP S,E,F;
    adrR A,N;

    F = searchP(LP,Nama);
    A = LR.First;
    if (A != NULL)
    {
        bool c = false;
        do
        {
            c = false;

            if (A->Bottom == F)
            {


                if (LR.First == LR.Last)
                {
                    A->Bottom = NULL;
                    A->Top = NULL;
                    LR.First = NULL;
                    LR.Last = NULL;
                    delete A;
                    A = NULL;
                }
                else
                {
                    A->Bottom = NULL;
                    A->Top = NULL;

                    N = A->Prev;
                    N->Next = A->Next;
                    Prev(A->Next) = N;

                    if(A == LR.First){
                        LR.First = A->Next;
                    }
                    if(A==LR.Last){
                        LR.Last = A->Prev;
                    }

                    A->Next = NULL;
                    A->Prev = NULL;

                    delete A;
                    A = LR.First;
                    c = true;
                }

            }else{

                A = A->Next;
            }

        }while ( (LR.First != NULL && A != LR.First) || c);
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }

    if (LP.First != NULL)
    {


        if (Info(First(LP)).namaP == Nama)
        {
            S = First(LP);
            First(LP) = S->Next;
            S->Next = NULL;

            delete S;
            E = First(LP);
        }
        else
        {
            S = First(LP);
            while ((Next(S)!=NULL) && (Info(S).namaP != Nama))
            {
                E = S;
                S = Next(S);

            }
            if (Info(S).namaP == Nama)
            {

                if (S->Next == NULL)
                {

                    E->Next = NULL;
                    delete S;
                }
                else
                {

                    E->Next = S->Next;
                    S->Next = NULL;
                    delete S;
                }
                E = E -> Next;
            }
        }
//        if(E != NULL){
//
//            do
//            {
//                Info(E).nomorP = Info(E).nomorP - 1;
//                E = E->Next;
//
//            }while (E != NULL);
//        }

    }
        else
    {
        cout<<"MASIH KOSONG\n";
    }
}

void updateP(ListR &LR,ListP &LP)
{
    adrP B;
    adrR A = LR.First;
    int newscore;
    string nama,jawab;

    if (LP.First != NULL)
    {
        cout<<"Nama peserta yang akan di update : ";cin>>nama;
        B = searchP(LP,nama);
        if (B!=NULL)
        {
            do
            {
                A=A->Next;
            } while(A!=LR.Last && A->Bottom != B);

            if (A->Bottom ==  B)
            {
                cout<<"Input Nilai Yang Baru : ";cin>>newscore;
                A->Info.nilai = newscore;
            }
        }
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }
}


///  PUNYA JURI  ///

adrJ Alo(string uname,string pasw,string Nama)
{
    adrJ X = new dataJ;

    Info(X).user = uname;
    Info(X).pass = pasw;
    Info(X).namaJ = Nama;
    X->Next = NULL;
    return X;
}

void input(ListJ &LJ, adrJ X)
{
    adrJ Y,Z;
    if (First(LJ) == NULL)
    {
        First(LJ) = X;
    }
    else
    {
        Y = First(LJ);
        while ((Y->Next != NULL) && (X->Info.namaJ > Y->Info.namaJ))
        {
            Z = Y;
            Y = Y->Next;
        }
        if (X->Info.namaJ <= Y->Info.namaJ)
        {
            if ( Y == First(LJ))
            {
                X->Next = First(LJ);
                First(LJ) = X;
            }
            else
            {
                X->Next = Y;
                Z->Next = X;
            }
        }
        else
        {
            Y->Next = X;
            X->Next = NULL;
        }
    }
}

bool cekUser(ListJ LJ,string uname)
{
    adrJ X;

    if (LJ.First != NULL)
    {
        X = LJ.First;
        while ((X->Next != NULL) && (Info(X).user != uname))
        {
            X = X->Next;
        }
        if (Info(X).user == uname)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void viewDataJ(ListJ LJ)
{
    adrJ x;
    x = LJ.First;
    if (x == NULL)
    {
        cout<<"KOSONG\n";
    }
    else
    {
        while (x!=NULL)
        {

            cout<<"Nama Juri : "<<x->Info.namaJ<<endl;
            cout<<"Username  : "<<x->Info.user<<endl;
            cout<<"Password  : "<<x->Info.pass<<endl;
            cout<<endl;
            x = x->Next;
        }
    }

}

void deleteJ(ListJ &LJ,ListR &LR,string Nama)
{
    adrJ S,E,F;
    adrR A,N;

    F = searchJ(LJ,Nama);
    A = LR.First;

    if (A != NULL)
    {

        bool c = false;

        do
        {
            c = false;

            if (A->Top == F)
            {


                if (LR.First == LR.Last)
                {
                    A->Bottom = NULL;
                    A->Top = NULL;
                    LR.First = NULL;
                    LR.Last = NULL;
                    delete A;
                    A = NULL;
                }
                else
                {
                    A->Bottom = NULL;
                    A->Top = NULL;

                    N = A->Prev;
                    N->Next = A->Next;
                    Prev(A->Next) = N;

                    if(A == LR.First)
                    {
                        LR.First = A->Next;
                    }
                    if(A==LR.Last)
                    {
                        LR.Last = A->Prev;
                    }

                    A->Next = NULL;
                    A->Prev = NULL;

                    delete A;
                    A = LR.First;
                    c = true;
                }

            }
            else
            {
                A = A->Next;
            }

        }while ( (LR.First != NULL && A != LR.First) || c);
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }

    if (First(LJ) != NULL)
    {
        if (Info(First(LJ)).namaJ == Nama)
        {
            S = First(LJ);
            First(LJ) = S->Next;
            S->Next = NULL;
            delete S;
        }
        else
        {
            S = First(LJ);
            while ((Next(S)!=NULL) && (Info(S).namaJ != Nama))
            {
                E = S;
                S = Next(S);
            }
            if (Info(S).namaJ == Nama)
            {
                if (S->Next == NULL)
                {
                    E->Next = NULL;
                    delete E;
                }
                else
                {
                    E->Next = S->Next;
                    S->Next = NULL;
                    delete S;
                }
            }
        }
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }
}

adrJ searchJ(ListJ LJ,string Nama)
{
    adrJ A;

    if (LJ.First != NULL)
    {
        A = LJ.First;
        while ((A->Next != NULL) && (A->Info.namaJ != Nama))
        {
            A = A->Next;
        }
        if (A->Info.namaJ == Nama)
        {
            return A;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void updateJ(ListJ &LJ,string Nama)
{
    adrJ A;
    string usr,name,pass;

    A = searchJ(LJ,Nama);
    if (A != NULL)
    {
        cout<<" Input User : "; cin>>usr;
        cout<<" Input Nama : "; cin>>name;
        cout<<" Input Password : "; cin>>pass;
        A->Info.namaJ = name;
        A->Info.user = usr;
        A->Info.pass = pass;
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }
}

int Total(ListR LR, adrP &A, adrR B)
{
    if (B !=NULL)
    {
        A->Info.total = A->Info.total + B->Info.nilai;
        return A->Info.total;
    }
    else
    {
        cout<<"MASIH KOSONG\n";
    }
}

//void Ranking(ListP &LP)
//{
//    adrP A,B;
//    adrP Max ;
//    int i = 0;
//
//    if (LP.First)
//    {
//        A =  LP.First;
//        while (A != NULL)
//        {
//            B = A;
//            Max = B;
//            while (B!=NULL)
//            {
//                if (B->Info.total >= Max->Info.total)
//                {
//                    Max = B;
//                }
//                B = B->Next;
//            }
//            i = i +1;
//            Max->Info.ranking = i;
//            A = A->Next;
//        }
//        A =  LP.First;
//        while (A != NULL && A->Info.ranking != 0)
//        {
//            A = A->Next;
//        }
//        if (A->Info.ranking == 0)
//        {
//            A->Info.ranking = i +1;
//        }
//    }
//    else
//    {
//        cout<<"UNDEFINED"<<endl;
//        getch();
//    }
//}

void Get3(ListR LR)
{
    ListR L2;
    L2.First = NULL;
    L2.Last = NULL;
    adrR x,y,a,b;
    int i =1;

    if (LR.First)
    {
        x = LR.First;
        do
        {
            y = x;
            if (L2.First == NULL)
            {
                L2.First = y;
                L2.Last = y;
                y->Next = L2.First;
                y->Prev = L2.Last;
            }
            else
            {
                a = L2.First;
                do
                {
                    b = a;
                    a = a->Next;
                }while((a != L2.First) && (Info(Bottom(y)).total>Info(Bottom(a)).total));

                if (Info(Bottom(y)).total <= Info(Bottom(a)).total)
                {
                    if (a = L2.First)
                    {
                        y->Next = L2.First;
                        L2.First->Prev = y;
                        y->Prev = L2.Last;
                        L2.Last->Next = y;
                        L2.First = y;
                    }
                    else
                    {
                        y->Next = a;
                        b->Next = y;
                        a->Prev = y;
                        y->Prev = b;
                    }
                }
                else
                {
                    y->Next = L2.First;
                    L2.Last->Next = y;
                    y->Prev = L2.Last;
                    L2.First->Prev = y;
                    L2.Last = y;
                }
            }
            x = x->Next;
        }while (x != LR.First);
        x = L2.Last;
        while(i<=3)
        {
            cout<<"========================[X]========================\n";
            cout<<"     [*] RANK "<<i<<"  : "<<Info(Bottom(x)).namaP<<endl;
            cout<<"     Total Nilai : "<<Info(Bottom(x)).total<<endl;
            cout<<"========================[X]========================\n";
            x = Prev(x);
            i++;
        }
    }
    else
    {
        cout<<"NOT FOUND ! ! !\n";
    }

}
//void Top3(ListP &L2,adrP A)
//{
//    adrP Prec,B;
//    if(L2.First == NULL)
//    {
//        L2.First = A;
//        A->Next =NULL;
//    }
//    else
//    {
//            if (L2.First->Next == NULL)
//            {
//                if (A->Info.total > L2.First->Info.total)
//                {
//                    A->Next = L2.First;
//                    L2.First = A;
//                }
//                else
//                {
//                    L2.First->Next = A;
//                    A->Next = NULL;
//                }
//            }
//            else
//            {
//                B = L2.First;
//                while (A->Info.nomorP <3)
//                {
//                    if (A->Info.total > B->Info.total && B == L2.First)
//                    {
//                        A->Next = B;
//                        L2.First = A;
//                        A->Info.nomorP++;
//                    }
//                    else if (A->Info.total > B->Info.total && B != L2.First)
//                    {
//                        A->Next = B;
//                        Prec->Next = A;
//                        A->Info.nomorP++
//                    }
//                    Prec = B;
//                    B =B->Next;
//                }
//            }
//    }
//}

//adrP GetHigh(ListP L){
//
//    adrP A = L.First;
//    adrP Max = L.First;
//
//    if (L.First != NULL)
//    {
//        while (A != NULL)
//        {
//            if (A->Info.total > Max->Info.total)
//            {
//                Max = A;
//            }
//            A = A->Next;
//        }
//        return Max;
//    }
//    else
//    {
//        cout<<"UNDEFINED ! ! !\n";
//    }
//}
