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

void showKurirByPaket(List_relasi L, int ID_Paket) {
    // Set pointer penelusur ke elemen pertama list relasi
    addr_relasi P = L.first;
    bool ditemukan = false;

    cout << "Menampilkan Kurir untuk Paket ID: " << ID_Paket << endl;
    cout << "--------------------------------------------" << endl;

    // Loop sampai akhir list relasi
    while (P != NULL) {
        // Cek apakah pointer paket valid DAN ID-nya cocok
        // Kita akses: Relasi -> Paket -> Info -> ID_paket
        if (P->paket != NULL && P->paket->info.ID_paket == ID_Paket) {
            
            // Jika cocok, cek apakah ada kurir yang terhubung
            if (P->kurir != NULL) {
                cout << "Ditemukan Kurir:" << endl;
                cout << "ID Kurir   : " << P->kurir->info.ID_kurir << endl;
                cout << "Kendaraan  : " << P->kurir->info.kendaraan << endl;
                cout << "Kapasitas  : " << P->kurir->info.berat << " kg" << endl;
                cout << endl;
                ditemukan = true;
            }
        }
        // Lanjut ke node relasi berikutnya
        P = P->next;
    }

    if (!ditemukan) {
        cout << "Paket dengan ID " << ID_Paket << " tidak memiliki kurir atau tidak ditemukan dalam relasi." << endl;
    }
}

void countRelasiAllKurir(List_kurir LK, List_relasi LR) {
    addr_kurir P_Kurir = LK.first;

    cout << "=== JUMLAH PAKET PER KURIR ===" << endl;
    while (P_Kurir != NULL) {
        int jumlah = 0;
        addr_relasi P_Rel = LR.first;
        
        // Loop Relasi untuk mencocokkan dengan Kurir saat ini
        while (P_Rel != NULL) {
            if (P_Rel->kurir == P_Kurir) { // Bandingkan address
                jumlah++;
            }
            P_Rel = P_Rel->next;
        }

        cout << "Kurir " << P_Kurir->info.ID_kurir 
             << " (" << P_Kurir->info.kendaraan << ") membawa: " 
             << jumlah << " paket." << endl;

        P_Kurir = P_Kurir->next;
    }
    cout << "------------------------------" << endl;
}

int countRelasiByPaketID(List_relasi LR, int ID_Paket) {
    int jumlah = 0;
    addr_relasi P = LR.first;

    while (P != NULL) {
        // Pastikan pointer paket tidak NULL sebelum akses info
        if (P->paket != NULL && P->paket->info.ID_paket == ID_Paket) {
            jumlah++;
        }
        P = P->next;
    }
    return jumlah;
}

int countPaketNoRelasi(List_paket LP, List_relasi LR) {
    int countNoRelasi = 0;
    addr_paket P_Paket = LP.first;

    while (P_Paket != NULL) {
        bool adaRelasi = false;
        addr_relasi P_Rel = LR.first;

        // Cek apakah paket ini ada di list relasi
        while (P_Rel != NULL) {
            if (P_Rel->paket == P_Paket) { // Cek by Address agar akurat
                adaRelasi = true;
                break; // Jika ketemu, hentikan pencarian di relasi
            }
            P_Rel = P_Rel->next;
        }

        // Jika setelah dicek semua relasi ternyata tidak ada
        if (!adaRelasi) {
            countNoRelasi++;
            // Opsional: Print ID paket yang nganggur
            // cout << "Paket ID " << P_Paket->info.ID_paket << " belum ada kurir." << endl;
        }

        P_Paket = P_Paket->next; // Pindah ke paket berikutnya (ingat List_paket kamu Doubly, next tetap ada)
    }

    return countNoRelasi;
}

void editRelasiPaket(List_relasi &LR, List_paket LP, int ID_Kurir, int ID_Paket_Lama, int ID_Paket_Baru) {
    // 1. Cari alamat Paket Baru terlebih dahulu
    // Asumsi: Kamu punya fungsi findElementPaket di modul Paket
    addr_paket P_PaketBaru = findElementPaket(LP, ID_Paket_Baru);

    if (P_PaketBaru == NULL) {
        cout << "Gagal Edit: Paket Baru dengan ID " << ID_Paket_Baru << " tidak ditemukan." << endl;
        return;
    }

    // 2. Cari Relasi yang mau diubah
    addr_relasi P_Rel = LR.first;
    bool found = false;

    while (P_Rel != NULL) {
        // Syarat: Kurirnya cocok DAN Paket Lamanya cocok
        if (P_Rel->kurir != NULL && P_Rel->paket != NULL &&
            P_Rel->kurir->info.ID_kurir == ID_Kurir &&
            P_Rel->paket->info.ID_paket == ID_Paket_Lama) {
            
            // Lakukan penggantian pointer paket
            P_Rel->paket = P_PaketBaru;
            found = true;
            cout << "Berhasil mengubah relasi kurir " << ID_Kurir 
                 << " dari Paket " << ID_Paket_Lama 
                 << " menjadi Paket " << ID_Paket_Baru << "." << endl;
            break;
        }
        P_Rel = P_Rel->next;
    }

    if (!found) {
        cout << "Gagal Edit: Relasi antara Kurir " << ID_Kurir 
             << " dan Paket " << ID_Paket_Lama << " tidak ditemukan." << endl;
    }
}