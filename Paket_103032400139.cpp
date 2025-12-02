#include "paket.h"
void insertFirst(List_paket &L, addr_pkt P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    }else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertBefore(List_paket &L, addr_pkt P, addr_pkt prec) {
    if (prec == L.first) {
        insertFirst(L, P);
    }else {
        P->next = prec;
        P->prev = prec->prev;
        prec->prev->next = P;
        prec->prev = P;
    }
}

void deleteFirst(List_paket &L, addr_pkt &P) {
    if (L.first == nullptr) {
        P = nullptr;
    }else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}


void show(List_paket L) {
    addr_pkt P = L.first;
    if (P == nullptr){
        cout << "List Paket kosong." << endl;
        return;
    }while (P != nullptr){
        cout << "ID Paket : " << P->info.ID_paket << endl;
        cout << "Alamat   : " << P->info.alamat << endl;
        cout << "Berat    : " << P->info.berat << endl;
        cout << "--------------------" << endl;
        P = P->next;
    }
}