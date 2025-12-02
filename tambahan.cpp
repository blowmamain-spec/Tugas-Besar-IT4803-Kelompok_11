#include "relasi.h"
#include "kurir.h"
#include "paket.h"

void daftarpaketkurir(List_relasi &L, int IDKurir){
    addr_kurir K;
    addr_relasi R;
    R = L.first;
    K = findElementKurir(L, IDKurir);
    while (R != nullptr){
        if (R->kurir == K){
            cout << "ID Paket : " << R->paket->info.ID_paket << endl;
            cout << "Alamat   : " << R->paket->info.alamat << endl;
            cout << "Berat    : " << R->paket->info.berat << endl;
            cout << endl;
        }
        R = R->next;
    }
}

void daftarkurirpaket(List_relasi &L, int IDPaket){
    addr_paket P;
    addr_relasi R;
    R = L.first;
    P = findElementPaket(L, IDPaket);
    while (R != nullptr){
        if (R->kurir == P){
            cout << "ID Kurir : " << R->kurir->info.ID_kurir << endl;
            cout << "Kendaraan   : " << R->kurir->info.kendaraan << endl;
            cout << "Berat    : " << R->kurir->info.berat << "Kg" << endl;
            cout << endl;
        }
        R = R->next;
    }
}

void daftarpaketdankurir(List_relasi &L){
    addr_relasi R;
    R = L.first;
    while (R != nullptr || R->paket != nullptr){
        cout << "ID Paket : " << R->paket->info.ID_paket << endl;
        cout << "Alamat   : " << R->paket->info.alamat << endl;
        cout << "Berat    : " << R->paket->info.berat << endl;
      
        cout << "ID Kurir : " << R->kurir->info.ID_kurir << endl;
        cout << "Kendaraan   : " << R->kurir->info.kendaraan << endl;
        cout << "Berat    : " << R->kurir->info.berat << "Kg" << endl;
        cout << "--------------------" << endl;
        R = R->next;
    }
}

void daftarkurirdanpaket(List_relasi &L){
    addr_relasi R,Q;
    R = L.first;
    while (R != nullptr){
        cout << "ID Kurir : " << R->kurir->info.ID_kurir << endl;
        cout << "Kendaraan   : " << R->kurir->info.kendaraan << endl;
        cout << "Berat    : " << R->kurir->info.berat << "Kg" << endl;

        while (Q != nullptr || Q->kurir == R->kurir){
            Q = Q->next;
        }
        cout << "ID Paket : " << R->paket->info.ID_paket << endl;
        cout << "Alamat   : " << R->paket->info.alamat << endl;
        cout << "Berat    : " << R->paket->info.berat << endl;
        cout << "--------------------" << endl;
        R = R->next;
    }
}
