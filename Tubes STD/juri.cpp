#include "juri.h"
#include "otak.h"

adrJ loginJuri(ListJ LJ)
{
    adrJ A;
    string userr,pasw;
    bool kondisi = false;

    if (LJ.First != NULL)
    {

        A = LJ.First;
        cout<<"Username : "; cin>>userr;
        cout<<"Password : "; cin>>pasw;
        while (A != NULL && A->Info.user != userr && A->Info.pass!=pasw)
        {

            cout<<A->Info.user<<endl;
            cout<<A->Info.pass<<endl;
            A = A->Next;
        }
        if ((A->Info.user == userr)&&(A->Info.pass==pasw))
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
        cout<<"MASIH KOSONG\n";
    }
}

adrR searchNilai(ListR LR,int nilai)
{
    adrR R;

    if (LR.First != NULL)
    {
        R = LR.First;
        while ((R != NULL) && (R->Info.nilai != nilai))
        {
            R = R->Next;
        }
        if (R->Info.nilai == nilai)
        {
            return R;
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
void menilai(ListR &LR, adrJ J, ListP &LP,ListH &LH){

    int nilai;
    string namap;
    adrP P;
    adrR Q;
    adrR R = new dataR;


    cout<<"Peserta yang akan dinilai : "; cin >> namap;
    P = searchP(LP,namap);
    cout<<"Input Nilai Peserta : "; cin>>nilai;

    if (P!= NULL)
    {
        if(First(LR)!= NULL)
        {
            int i = 0;
            Q = LR.First;
            while((i == 0) || (Q != LR.First) && (Info(Q->Top).namaJ != J->Info.namaJ) && (Info(Q->Bottom).namaP != P->Info.namaP))
            {
                i++;
                Q = Q->Next;
            }
            if (Info(Q->Top).namaJ == J->Info.namaJ && Info(Q->Bottom).namaP == P->Info.namaP)
            {
                cout<<"SUDAH PERNAH DINILAI\n";
                getch();
                return;
            }
            else
            {
                R->Info.nilai = nilai;
                R->Bottom = P;
                R->Top = J;
                R->Next = LR.First;
                R->Prev = LR.Last;
                LR.First->Prev = R;
                LR.Last->Next = R;
                LR.First = R;
            }
        }

        else
        {
            R->Info.nilai = nilai;
            R->Bottom = P;
            R->Top = J;
            R->Next = R;
            R->Prev = R;
            LR.First = R;
            LR.Last = R;
            LR.Last = R->Prev;
        }
        Total(LR,P,R);
        InputHistory(LH,R);
    }
    else
    {
        cout<<"NOT FOUND !!!\n";
    }
}
