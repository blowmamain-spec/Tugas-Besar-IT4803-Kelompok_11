void insertFirst(List_kurir &L, addr_kurir P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = nullptr;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteLast(List_kurir &L, addr_kurir &P) {
    P = nullptr;
    if (L.first == nullptr) {
        return;
    }
    if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        addr_kurir Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}