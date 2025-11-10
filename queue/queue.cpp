#include "queue.h"
#include <iostream> 
using namespace std;

address createNewElm(infotype x) {
    address p = new elmQ;
    if (p != nullptr) {
        p->info = x;
        p->next = nullptr;
    }
    return p;
}


void createQueue(queue &Q) {
    Q.head = NULL;
    Q.tail = NULL;
}

bool isEmpty(queue Q) {
    return Q.head == NULL;
}

void enqueue(queue &Q, address p) {
    if (isEmpty(Q)) {
        Q.head = p;
        Q.tail = p;
    } else {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void dequeue(queue& Q, address& p) {
    if (isEmpty(Q)) {
        p = NULL; 
        cout << "ERROR: Queue is empty. Dequeue failed." << endl;
    } else {
        p = Q.head; 
        Q.head = Q.head->next; 

        if (Q.head == NULL) {
            Q.tail = NULL;
        }
        
        p->next = NULL; 
    }
}


int countUserDocs(queue Q, string nama) {
    int count = 0;
    address p = Q.head;
    while (p != nullptr) {
        if (p->info.namaPengguna == nama) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void antriPrinter(queue &Q, infotype doc) {
    int current_docs = countUserDocs(Q, doc.namaPengguna);
    
    cout << "\n[ANTRI PRINTER] Dokumen: " << doc.namaDok << " | Pengguna: " << doc.namaPengguna << endl;
    cout << "  -> Dokumen aktif " << doc.namaPengguna << ": " << current_docs <<endl;

    if (current_docs < 3) {
        address p = createNewElm(doc);
        if (p != nullptr) {
            enqueue(Q, p);
            cout << "  -> Sukses! Dokumen ditambahkan ke antrian." << endl;
        } else {
            cout << "  -> Gagal membuat elemen baru (memori penuh)." << endl;
        }
    } else {
        cout << "  -> Gagal! Pengguna " << doc.namaPengguna << " sudah memiliki maksimal 3 dokumen aktif." << endl;
    }
}


void simulasiCetak(queue& Q, int& kertas) {
    cout << "\n\n[SIMULASI CETAK] Proses Dimulai" << std::endl;
    cout << "  -> Kertas tersedia awal: " << kertas << " lembar." << endl;
    
    address p_doc; 

    while (!isEmpty(Q)) {
        infotype current_info = Q.head->info;
        
        cout << "\n  [CHECK] Dokumen: " << current_info.namaDok 
                << " (" << current_info.namaPengguna << ") - Halaman: " << current_info.hal << endl;

        if (kertas >= current_info.hal) {
            dequeue(Q, p_doc);
            kertas -= current_info.hal;
            
            cout << "  -> BERHASIL DICETAK. Kertas terpakai: " << current_info.hal 
                    << " lembar." << endl;
            cout << "  -> Sisa Kertas: " << kertas << " lembar." << endl;
            delete p_doc;

        } else {
            cout << "  -> GAGAL DICETAK. Kertas (" << kertas 
                    << ") tidak cukup untuk " << current_info.hal 
                    << " halaman." << endl;
            break; 
        }
    }

    if (isEmpty(Q)) {
        cout << "\n[SIMULASI CETAK] Selesai. Antrian dokumen kosong." << endl;
    } else {
        cout << "\n[SIMULASI CETAK] Selesai. Kertas tidak lagi mencukupi untuk dokumen berikutnya." << endl;
    }
    cout << "  -> Kertas tersedia akhir: " << kertas << " lembar." << endl;
}

void displayQueue(queue Q) {
    address p = Q.head;
    if (isEmpty(Q)) {
        cout << "Antrian kosong." << endl;
        return;
    }
    cout << "--- ANTRIAN PRINTER (HEAD -> TAIL) ---" << endl;
    int i = 1;
    while (p != NULL) {
        cout << i++ << ". " << p->info.namaDok 
                << " (" << p->info.namaPengguna 
                << ") - " << p->info.hal << " hal" << endl;
        p = p->next;
    }
    cout << "---------------------------------------" << endl;
}