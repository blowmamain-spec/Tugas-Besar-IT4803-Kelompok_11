#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
using namespace std;

typedef data_paket infotype;
typedef struct paket *addr_pkt;

struct data_paket {
    int ID_paket;
    string alamat;
    int berat;
};

struct paket {
    infotype info;
    addr_pkt next;
    addr_pkt prev;
};

struct List_paket {
    addr_pkt first;
    addr_pkt last;
};

void createListPaket(List_paket &L);
bool isEmpty_paket(List_paket L);
addr_kurir createElementPaket(int IDPaket, string alamat, int berat);
addr_kurir findElementPaket(List_paket L,  int IDPaket);
void insertLastPaket(List_paket &L, addr_paket p);
void insertAfterPaket(List_paket &L, addr_paket p, addr_paket prec);
void deleteLastPaket(List_paket &L, addr_paket &p);
void insertFirst(List_paket &L, addr_pkt P);
void insertBefore(List_paket &L, addr_pkt P, addr_pkt prec);
void deleteFirst(List_paket &L, addr_pkt &P);
void show(List_paket L) ;


#endif // PAKET_H_INCLUDED
