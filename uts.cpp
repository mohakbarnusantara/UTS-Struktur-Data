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
        // overloading
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
        // overloading update nama
        void updatePasien(int id,string namaBaru){
            if(namaBaru.empty()){
                cout << "Gagal memperbaharui data pasien!\n";
                system("pause");
                system("cls");
            
            }else{
                for(int i =1; i < jumlahData; i++){
                    if(daftarAntrian[i].id == id){
                        daftarAntrian[i].nama == namaBaru;
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
    AntrianRumahSakit rs_Undata;
    int pilihan, idCari;
    string namaIn, keluhanIn;
    system("cls");

    do{
        cout << "\nSISTEM ANTRIAN RUMAH SAKIT\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Hapus Pasien (ID)\n";
        cout << "3. Update Pasien (ID)\n";
        cout << "4. Tampilkan Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan){
        case 1:
            system("cls");
            cout << "Nama :"; getline(cin, namaIn);
            cout << "Keluhan :"; getline(cin, keluhanIn);
            rs_Undata.tambahPasien(namaIn,keluhanIn);
            break;
        
        case 2:
            system("cls");
            cout << "Masukkan ID pasien yang akan dihapus: ";
            cin >> idCari;
            rs_Undata.hapusPasien(idCari);
            break;
        
        case 3:
            system("cls");
            cout << "Masukkan ID pasien yang akan diUpdate: ";
            cin >> idCari;
            cin.ignore();

            int pilihanUP;
            
            cout << "Pilih (1-3)" << endl;
            cout << "1. Ubah Nama" << endl;
            cout << "2. Ubah Keluhan" << endl;
            cout << "3. Ubah Nama dan Keluhan" << endl;
            cout << "Pilih: ";
            cin >> pilihanUP;
            cin.ignore();

            switch (pilihanUP){
            case 1:
                cout << "Nama baru : "; getline(cin, namaIn);
                break;
            
            default:
                break;
            }
            
            break;
        
            case 4:
            system("cls");
             rs_Undata.tampilkanData();
            break;
        default:
            system("cls");
            cout << "Pilihan Tidak Valid!\nSilakan Pilih (1-5)" << endl;
            break;
        }
    } while (pilihan != 5);
    
}

