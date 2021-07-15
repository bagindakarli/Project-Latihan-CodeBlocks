#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "otak.h"
#include "juri.h"

void inLastP(ListP &LP, string NamaP);
void viewDataP(ListP &LP,ListR LR);
adrP searchP(ListP LP,string Nama);
void deleteP(ListP &LP,ListR &LR,string Nama);
void updateP(ListR &LR,ListP &LP);
int Total(ListR LR, adrP &A, adrR B);

void input(ListJ &LJ, adrJ X);
adrJ Alo(string uname,string pasw,string Nama);
void viewDataJ(ListJ LJ);
bool cekUser(ListJ LJ,string uname);
void deleteJ(ListJ &LJ,ListR &LR,string Nama);
void updateJ(ListJ &LJ,string Nama);
adrJ searchJ(ListJ LJ,string Nama);

void Get3(ListR LR);
void Ranking(ListP LP);
#endif // ADMIN_H_INCLUDED
