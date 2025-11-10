#include "queue.h"
using namespace std;


infotype doc1 = {"Surat Tugas", "Ayu", 10};
infotype doc2 = {"Undangan", "Sasa", 3};
infotype doc3 = {"Notula Rapat", "Ayu", 15};
infotype doc4 = {"Pedoman KPI", "Ayu", 85};
infotype doc5 = {"Presensi", "Nia", 24};

int main() {
    queue Q_Printer;
    createQueue(Q_Printer);

    cout << "=== SOAL 4: QUEUE (Antrian Printer) ===" << endl;
    

    std::cout << "\n## INISIALISASI ANTRIAN AWAL ##" << std::endl;
    enqueue(Q_Printer, createNewElm(doc1)); // Surat Tugas - Ayu (1)
    enqueue(Q_Printer, createNewElm(doc2)); // Undangan - Sasa (1)
    enqueue(Q_Printer, createNewElm(doc3)); // Notula Rapat - Ayu (2)
    enqueue(Q_Printer, createNewElm(doc4)); // Pedoman KPI - Ayu (3)
    enqueue(Q_Printer, createNewElm(doc5));
    displayQueue(Q_Printer);

    // 2. Uji Prosedur AntriPrinter (SOAL 4.c)
    std::cout << "\n==============================================" << std::endl;
    std::cout << "## PENGUJIAN antriPrinter (BATAS MAKS 3) ##" << std::endl;
    
    // Kasus 1: Pengguna "Ayu" sudah 3, seharusnya GAGAL
    infotype new_doc_ayu = {"Laporan Akhir", "Ayu", 50};
    antriPrinter(Q_Printer, new_doc_ayu); 

    // Kasus 2: Pengguna "Sasa" baru 1, seharusnya BERHASIL
    infotype new_doc_sasa = {"Memo Internal", "Sasa", 5};
    antriPrinter(Q_Printer, new_doc_sasa);
    
    // Kasus 3: Pengguna "Budi" baru, seharusnya BERHASIL
    infotype new_doc_budi = {"Draft Proposal", "Budi", 100};
    antriPrinter(Q_Printer, new_doc_budi);

    std::cout << "\n--- ANTRIAN SETELAH antriPrinter ---" << std::endl;
    displayQueue(Q_Printer);


    // 3. Uji Prosedur SimulasiCetak (SOAL 4.d)
    std::cout << "\n==============================================" << std::endl;
    std::cout << "## PENGUJIAN simulasiCetak (Kertas = 50) ##" << std::endl;
    // Contoh 1 dari soal: jika kertas = 50, maka [Surat Tugas-Ayu-10, Undangan-Sasa-3, Notula Rapat-Ayu-15] dicetak
    int kertas_case_1 = 50; 
    simulasiCetak(Q_Printer, kertas_case_1);
    
    std::cout << "\n--- ANTRIAN SETELAH SIMULASI CETAK (Kertas 50) ---" << std::endl;
    displayQueue(Q_Printer);
    
    // Perhatikan: Dokumen yang tersisa di antrian Q_Printer adalah:
    // Pedoman KPI (Ayu, 85), Presensi (Nia, 24), Memo Internal (Sasa, 5), Draft Proposal (Budi, 100)

    std::cout << "\n==============================================" << std::endl;
    std::cout << "## PENGUJIAN simulasiCetak Lanjutan (Kertas = 30) ##" << std::endl;
    // Lanjutkan proses cetak dengan kertas baru = 30
    int kertas_case_2 = 30;
    simulasiCetak(Q_Printer, kertas_case_2);

    std::cout << "\n--- ANTRIAN AKHIR ---" << std::endl;
    displayQueue(Q_Printer);

    return 0;
}