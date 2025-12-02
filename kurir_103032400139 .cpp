#include "kurir.h"
void insertFirst(List_kurir &L, addr_kurir P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = nullptr;
    }else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteLast(List_kurir &L, addr_kurir &P) {
    P= nullptr;
    if (L.first == nullptr) {
        return;
    }
    if(L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    }else {
        addr_kurir Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteFirst(List_kurir &L, addr_kurir &P) {
    P= nullptr;
    if (L.first == nullptr){
        return;
    }
    P = L.first;
    L.first = L.first->next;
    P->next = nullptr;
}

void show(List_kurir L) {
    addr_kurir P = L.first;
    if (P == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    while (P != nullptr) {
        cout << "ID        : " << P->info.ID_kurir << endl;
        cout << "Kendaraan : " << P->info.kendaraan << endl;
        cout << "Berat     : " << P->info.berat << endl;
        cout << "--------------------" << endl;
        P = P->next;
    }
}