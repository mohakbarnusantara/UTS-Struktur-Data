#include <iostream>

using namespace std;

struct Pasien{
    int id;
    string nama;
    string keluhan;
};

class AntrianRumahSakit {
    private:
    static const int MAKS_ANTRIAN = 100;
    Pasien daftarAntrian[MAKS_ANTRIAN];
    int jumlahData;
    int counterID;

    public:
        AntrianRumahSakit() {
            jumlahData = 0;
            counterID = 1;
        }
        // 1. tambah pasien
        void tambahPasien(string nama, string keluhan){
            if(nama.empty()){
                cout << "Pasian tidak berhasil ditambahkan dalam antrian!\n";
                system("pause");
                system("cls");
            }else if(keluhan.empty()){
                cout << "Pasian tidak berhasil ditambahkan dalam antrian!\n";
                system("pause");
                system("cls");
            }else{
                if(jumlahData < MAKS_ANTRIAN){
                    daftarAntrian[jumlahData].id = counterID++;
                    daftarAntrian[jumlahData].nama = nama;
                    daftarAntrian[jumlahData].keluhan = keluhan;
                    jumlahData++;
                    cout << "Pasien berhasil ditambahkan ke antrian!\n";
                    system("pause");
                    system("cls");
                }else{
                    cout << "Maaf, antrian sudah penih!\n";
                    system("pause");
                    system("cls");
                }
            }
        }
        // 2. hapus data(berdasar id)
        void hapusPasien(int id){
            int indexketemu = -1;
            for (int i = 0; i < jumlahData; i++){
                if(daftarAntrian[i].id == id){
                    indexketemu = i;
                    break;
                }
            }
            if(indexketemu !=-1){
                for(int i = indexketemu; i < jumlahData - 1; i++){   //Proses Menggeser Antrian (Shifting)
                    daftarAntrian[i] = daftarAntrian[i+1];
                }
                jumlahData--;
                cout << "Data pasiaen denga ID " << id << " berhasil dihapus\n";
                system("pause");
                system("cls");
            }else{
                cout << "ID pasien tidak ditemukan.\n";
                system("pause");
                system("cls");
            }
        }
        // 3.update data
        void updatePasien(int id,string namaBaru, string keluhanBaru){
            if(namaBaru.empty()){
                cout << "Gagal memperbaharui data pasien!\n";
                system("pause");
                system("cls");
            }else if(keluhanBaru.empty()){
                cout << "Gagal memperbaharui data pasien!\n";
                system("pause");
                system("cls");
            }else{
                for(int i =1; i < jumlahData; i++){
                    if(daftarAntrian[i].id == id){
                        daftarAntrian[i].nama == namaBaru;
                        daftarAntrian[i].keluhan == keluhanBaru;
                        cout << "Data Pasien berhasil diperbaharui!\n";
                        system("pause");
                        system("cls");
                        return;
                    }else{
                        cout << "ID pasien tidak di ditemukan.\n";
                        system("pause");
                        system("cls");
                    }
                }
            }
        }

        void tampilkanData(){
            if(jumlahData == 0){
                cout << "\n--- Belum ada pasien dalam antrian ---\n";
                system("pause");
                system("cls");
                return;
            }
            cout << "\n========== DAFTAR ANTRIAN ==========\n";
            cout << "ID\tNama\t\tKeluhan\n";
            for(int i = 0; i <jumlahData; i++){
                cout << daftarAntrian[i].id << "\t"
                << daftarAntrian[i].nama << "\t\t"
                << daftarAntrian[i].keluhan << endl;
            }
            cout << "====================================\n";
            system("pause");
            system("cls");


        }
};

int main(){
    
}

