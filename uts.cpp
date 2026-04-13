#include <iostream>

using namespace std;

// Struct untuk menyimpan data pasien
struct Pasien {
    int id;
    string nama;
    string keluhan;
};

// Class untuk mengelola sistem antrian
class AntrianRumahSakit {
private:
    // Menggunakan Array Statis dengan kapasitas tetap
    static const int MAKS_ANTRIAN = 100; 
    Pasien daftarAntrian[MAKS_ANTRIAN];
    int jumlahData;
    int counterId;

public:
    AntrianRumahSakit() {
        jumlahData = 0;
        counterId = 1;
    }

    // 1. Tambah Data
    void tambahPasien(string nama, string keluhan) {
        if (nama.empty()){
            cout << "pasien tidak berhasil ditambahkan dalam antrian!\n";
            system("pause");
            system("cls");
        }  else if(keluhan.empty()){
            cout << "pasien tidak berhasil ditambahkan dalam antrian!\n";
            system("pause");
            system("cls");
        }
        else{
        if (jumlahData < MAKS_ANTRIAN) {
            daftarAntrian[jumlahData].id = counterId++;
            daftarAntrian[jumlahData].nama = nama;
            daftarAntrian[jumlahData].keluhan = keluhan;
            jumlahData++;
            cout << "Pasien berhasil ditambahkan ke antrian!\n";
            system("pause");
            system("cls");
        } else {
            cout << "Maaf, antrian sudah penuh!\n";
            system("pause");
            system("cls");
        }
    }
}
    // 2. Hapus Data (Berdasarkan ID)
    void hapusPasien(int id) {
        int indexKetemu = -1;
        for (int i = 0; i < jumlahData; i++) {
            if (daftarAntrian[i].id == id) {
                indexKetemu = i;
                break;
            }
        }

        if (indexKetemu != -1) {
            // Geser elemen setelahnya ke kiri agar tidak ada celah kosong
            for (int i = indexKetemu; i < jumlahData - 1; i++) {
                daftarAntrian[i] = daftarAntrian[i + 1];
            }
            jumlahData--;
            cout << "Data pasien dengan ID " << id << " berhasil dihapus.\n";
            system("pause");
                system("cls");
        } else {
            cout << "ID pasien tidak ditemukan.\n";
            system("pause");
                system("cls");
        }
    }

    // 3. Update Data
    // overloding updatePasien untuk update nama dan keluhan
    void updatePasien(int id, string namaBaru, string keluhanBaru) {
        if (namaBaru.empty()){
            cout << "gagal memperbaharui data pasien!\n";
            system("pause");
            system("cls");
        }  else if(keluhanBaru.empty()){
            cout << "gagal memperbaharui data pasien!\n";
            system("pause");
            system("cls");
        }else{
        for (int i = 0; i < jumlahData; i++) {
            if (daftarAntrian[i].id == id) {
                daftarAntrian[i].nama = namaBaru;
                daftarAntrian[i].keluhan = keluhanBaru;
                cout << "Data pasien berhasil diperbarui!\n";
                system("pause");
                system("cls");
                return;
            }
            else {
                cout << "ID pasien tidak ditemukan.\n";
                system("pause");
                    system("cls");
                }
            
        }
    }
}
        // overloading updatePasien untuk update nama
    void updatePasien(int id, string namaBaru) {
        if (namaBaru.empty()){
            cout << "gagal memperbaharui data pasien!\n";
            system("pause");
            system("cls");
        }  else{
        for (int i = 0; i < jumlahData; i++) {
            if (daftarAntrian[i].id == id) {
                daftarAntrian[i].nama = namaBaru;
                cout << "Data pasien berhasil diperbarui!\n";
                system("pause");
                system("cls");
                return;
            }
            cout << "ID pasien tidak ditemukan.\n";
            system("pause");
            system("cls");
                
        }
    }
}
    // update keluhan
    void updatePasienKeluhan(int id, string keluhanBaru) {
        if(keluhanBaru.empty()){
            cout << "gagal memperbaharui data pasien!\n";
            system("pause");
            system("cls");
        }else{
        for (int i = 0; i < jumlahData; i++) {
            if (daftarAntrian[i].id == id) {
                daftarAntrian[i].keluhan = keluhanBaru;
                cout << "Data pasien berhasil diperbarui!\n";
                system("pause");
                system("cls");
                return;
            }
            else {
                cout << "ID pasien tidak ditemukan.\n";
                system("pause");
                    system("cls");
                }
            
        }
    }
}

    // 4. Tampilkan Data
    void tampilkanData() {
        if (jumlahData == 0) {
            cout << "\n--- Belum ada pasien dalam antrian ---\n";
            system("pause");
                system("cls");
            return;
        }
        cout << "\n========== DAFTAR ANTRIAN ==========\n";
        cout << "ID\tNama\t\tKeluhan\n";
        for (int i = 0; i < jumlahData; i++) {
            cout << daftarAntrian[i].id << "\t" 
            << daftarAntrian[i].nama << "\t\t" 
            << daftarAntrian[i].keluhan << endl;
        }
        cout << "====================================\n";
        system("pause");
        system("cls");
    }
};

int main() {
    AntrianRumahSakit rs; //objek rs
    int pilihan, idCari;
    string namaIn, keluhanIn;
system("cls");
    do {
        cout << "\nSISTEM ANTRIAN RUMAH SAKIT\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Hapus Pasien (ID)\n";
        cout << "3. Update Pasien (ID)\n";
        cout << "4. Tampilkan Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih: "; cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
            system("cls");
                cout << "Nama: "; getline(cin, namaIn);
                cout << "Keluhan: "; getline(cin, keluhanIn);
                rs.tambahPasien(namaIn, keluhanIn);
                break;
            case 2:
            system("cls");

                cout << "Masukkan ID yang akan dihapus: "; cin >> idCari;
                rs.hapusPasien(idCari);
                break;
            case 3:
            system("cls");
                cout << "Masukkan ID yang akan diupdate: "; 
                cin >> idCari;
                cin.ignore();
                do{
                    cout << "Pilih (1-3)" << endl;
                    cout << "1. Ubah Nama" << endl;
                    cout << "2. Ubah Keluhan" << endl;
                    cout << "3. Ubah Nama dan Keluhan" << endl;
                    cout << "Pilih: "; cin >> pilihan;
                    cin.ignore();
                    switch (pilihan) {
                        case 1:
                            system("cls");
                            cout << "Nama Baru: "; getline(cin, namaIn);
                            rs.updatePasien(idCari, namaIn);
                        break;
                        case 2:
                            system("cls");
                            cout << "Keluhan Baru: "; getline(cin, keluhanIn);
                            rs.updatePasienKeluhan(idCari, keluhanIn);
                        break;
                        case 3:
                            system("cls");
                            cout << "Nama Baru: "; getline(cin, namaIn);
                            cout << "Keluhan Baru: "; getline(cin, keluhanIn);
                            rs.updatePasien(idCari, namaIn, keluhanIn);
                        break;
                        default:
                            system("cls");
                            cout << "Pilihan Tidak Valid!\nSilakan Pilih (1-5)" << endl;
                        break;
                    }
                } while (pilihan <1 || pilihan > 3);
                break;
            case 4:
            system("cls");
                rs.tampilkanData();
                break;
            case 5:
                system("cls");
                cout << "Terima Kasih!\n";
                return 0;
            break;
            default:
            system("cls");
            cout << "Pilihan Tidak Valid!\nSilakan Pilih (1-5)" << endl;
        }
    } while (pilihan != 5);

    return 0;
}