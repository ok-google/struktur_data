#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct data_user{
    char nama[50];
    char pass[20];
    char akses[10];
    data_user *next;
};

struct kalender{
    int hari;
    int bulan;
    int tahun;
};

struct data_mobil{
    int id_mobil;
    char peminjam[50];
    char nama_mobil[50];
    kalender pembuatan;
    bool status;
    int lama_peminjaman;
    data_mobil *next;
};

data_user *user_depan, *user_belakang, *user_baru, *user_hapus, *user_posisi, *user_bantu, *user_tukar, *user_simpan, *temp;

data_mobil *mobil_depan, *mobil_belakang, *mobil_baru, *mobil_hapus, *mobil_posisi,
           *mobil_bantu, *mobil_tukar, *mobil_simpan, *temporary;

data_user data_login;
int banyak_user = 0;
int banyak_mobil = 0;
int sukses_login;
bool ulang, logout = true;
bool isEmpty(int a){
    if(a == 1){
        if(mobil_depan == NULL) return true;
        else return false;
    }
    else if(a == 2){
        if(user_depan == NULL) return true;
        else return false;
    }
    else return false;
}

void input_user(){
    user_baru = new data_user;
    bool sama;
    do{
        sama = false;
        cout<<"Masukan Username = ";
        cin.getline(user_baru->nama, 50);
        if(banyak_user!=0){
            user_posisi = user_depan;
            while(user_posisi!=NULL){
                if(strcmp(user_baru->nama, user_posisi->nama)==0){
                    cout<<"Username sudah digunakan"<<endl;
                    sama = true;
                    break;
                }
                user_posisi = user_posisi->next;
            }
        }
    }while(sama == true);
    cout<<"Masukan Password = ";
    cin.getline(user_baru->pass, 20);
    do{
    cout<<"Masukan Hak Akses = ";
    cin.getline(user_baru->akses, 10);
    }while(strcmp(user_baru->akses, "admin") != 0 || strcmp(user_baru->akses, "user") != 0)
    user_baru->next = NULL;
}

void tambah_depan_user(){
    if(isEmpty(2))
        user_belakang = user_baru;
    else
        user_baru->next = user_depan;
    user_depan = user_baru;
    banyak_user++;
}

void tambah_belakang_user(){
    if(isEmpty(2))
        user_depan = user_baru;
    else
        user_belakang->next = user_baru;
    user_belakang = user_baru;
    banyak_user++;
}

void tambah_tengah_user(int letak){
    user_posisi = user_depan;
    for(int x = 1; x<letak; x++){
        user_bantu = user_posisi;
        user_posisi = user_posisi->next;
    }
    user_bantu->next = user_baru;
    user_baru->next = user_posisi;
    banyak_user++;
}

void hapus_depan_user(){
    user_hapus = user_depan;
    user_depan = user_depan->next;
    user_hapus = NULL;
    banyak_user--;
}

void hapus_belakang_user(){
    user_posisi = user_depan;
    while(user_posisi->next->next != NULL)
        user_posisi = user_posisi ->next;
    user_belakang = user_posisi;
    user_posisi->next = NULL;
    banyak_user--;
}

void hapus_tengah_user(int letak){
    user_posisi = user_depan;
    for(int x = 1; x<letak; x++){
        user_bantu = user_posisi;
        user_posisi = user_posisi->next;
    }
    user_bantu->next = user_posisi->next;
    banyak_user--;
}

void tukar_posisi_user(){
    int posisi_1;
    int posisi_2;
    if(banyak_user < 2)
        cout<<"User kurang dari 2 atau belum ada user terdaftar"<<endl;
    else{
        cout<<"Masukan Posisi Pertama = ";
        cin>>posisi_1;
        cout<<"Masukan Posisi Kedua = ";
        cin>>posisi_2;

        //inisialisasi posisi pertama
        user_posisi = user_depan;
        if(posisi_1 == 1){
            user_simpan = user_posisi;
        }
        else{
            for(int x = 1; x<posisi_1; x++){
                user_simpan = user_posisi;
                user_posisi = user_posisi->next;
            }
        }

        user_tukar = user_posisi;
        temp = new data_user;

        temp->next = user_posisi->next;

        //inisialisasi Posisi kedua
        user_posisi = user_depan;
        if(posisi_2 == 1)
            user_bantu = user_posisi;
        else{
            for(int x = 1; x<posisi_2; x++){
                user_bantu = user_posisi;
                user_posisi = user_posisi->next;
            }
        }


        //penukaran
        if(posisi_2 == posisi_1-1 || posisi_2 == posisi_1+1){
            if(posisi_1 == 1){
                user_simpan->next = user_posisi->next;
                user_posisi->next = user_simpan;
                user_depan = user_posisi;
            }
            else if(posisi_2 == 1){
                user_bantu->next = user_tukar->next;
                user_tukar->next = user_bantu;
                user_depan = user_tukar;
            }
            else if(posisi_2 > posisi_1){
                user_tukar->next = user_posisi->next;
                user_posisi->next = user_tukar;
                user_simpan->next = user_posisi;
            }
            else{
                user_posisi->next = user_tukar->next;
                user_tukar->next = user_posisi;
                user_bantu->next = user_tukar;
            }
        }

        else{
            if(posisi_2 == 1){
                user_tukar->next = user_bantu->next;
                user_depan = user_tukar;
            }
            if(posisi_1 == 1){
                user_bantu->next = user_simpan;
                user_simpan->next = user_posisi->next;
                user_posisi->next = temp->next;
                user_depan = user_posisi;
            }
            if(posisi_1 != 1){
                user_tukar->next = user_posisi->next;
                user_bantu->next = user_tukar;

                user_posisi->next = temp->next;
                user_simpan->next = user_posisi;
            }
        }
    }
}

void tampil_user(){
    user_posisi = user_depan;
    cout<<"username\t\t\tHak Akses"<<endl;
    while(user_posisi != NULL){
        cout<<user_posisi->nama<<"\t\t\t\t"<<user_posisi->akses<<endl;
        user_posisi = user_posisi->next;
    }
}

void register_user(){
    input_user();
    int letak, sub_pilih;
    bool ulang;
    if(banyak_user > 0){
    do{
        ulang = false;
            cout<<"\n1. Tambah Ke Data Paling Depan"<<endl;
            cout<<"2. Tambah Ke Data Paling Belakang"<<endl;
            if(banyak_user >= 2)
                cout<<"3. Tambah Data di Tengah Range( 1 - "<<banyak_user<<" )"<<endl;
            cout<<"Masukan Pilihan Anda = ";
            cin>>sub_pilih;
            switch(sub_pilih){
                case 1:
                    tambah_depan_user();
                break;
                case 2:
                    tambah_belakang_user();
                break;
                case 3:
                    do{
                        ulang = false;
                        cout<<"Taruh posisi mana ? Range( 1 - "<<banyak_user<<" )"<<endl;
                        cin>>letak;
                        if(letak <= banyak_user && letak > 0)
                            tambah_tengah_user(letak);
                        else{
                            cout<<"Range Tidak Tersedia";
                            ulang = true;
                        }
                    }while(ulang == true);
                break;
                default:
                    cout<<"Pilihan tidak tersedia";
                    ulang = true;
                break;
            }
        }while(ulang == true);
    }
    else{
        tambah_depan_user();
    }
}

int login_user(){
    char user[50];
    char pass[50];

    cout<<"Masukan Username = "<<endl;
    cin.getline(user, 50);
    cout<<"Masukan Password = "<<endl;
    cin.getline(pass, 50);

    user_posisi = user_depan;
    while(user_posisi != NULL){
        if(strcmp(user_posisi->nama, user)==0 && strcmp(user_posisi->pass, pass)==0){
            strcpy(data_login.nama, user_posisi->nama);
            if(strcmp(user_posisi->akses, "admin"))
                return 2;
            else
                return 1;
            break;
        }
        user_posisi = user_posisi->next;
    }
    return 0;
}

void delete_user(){
    int hapus;
    do{
    cout<<"Masukan urutan data yang ingin dihapus (Range 1 - "<<banyak_user<<")= ";
    cin>>hapus;
    }while(hapus>banyak_user);
    if(hapus == 1)
        hapus_depan_user();
    else if(hapus == banyak_user)
        hapus_belakang_user();
    else
        hapus_tengah_user(hapus);
}

void aksi_login(){
        ulang = true;
        int pilihan1;
        do{
        sukses_login = 0;
        system("CLS");
        cout<<"Menu"<<endl;
        cout<<"1. Register "<<endl;
        cout<<"2. Login "<<endl;
        cout<<"3. Hapus "<<endl;
        cout<<"4. Tampil "<<endl;
        cout<<"5. Tukar Posisi"<<endl;
        cout<<"6. Akhiri Program"<<endl;
        cout<<"Masukan Pilihan Anda = ";
        cin>>pilihan1;
        cin.ignore();
        switch(pilihan1){
            case 1:
                register_user();
                break;
            case 2:
                sukses_login = login_user();
                if(sukses_login == 1 || sukses_login == 2){
                    ulang = false;
                    cout<<"Login Sukses"<<endl;
                    system("PAUSE");
                    system("CLS");
                }
                else{
                    cout<<"Login Gagal "<<endl;
                }
                break;
            case 3:
                delete_user();
                break;
            case 4:
                tampil_user();
                break;
            case 5:
                tukar_posisi_user();
                break;
            case 6:
                ulang = false;
                logout = false;
                system("CLS");
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"|  Terima Kasih telah menggunakan Program ini            |"<<endl;
                cout<<"|  By : Rizki Setiawan                                   |"<<endl;
                cout<<"|  Asslab : Griko Muhammad Sultan Nibras                 |"<<endl;
                cout<<"|  Program ini dilindungi hak cipta                      |"<<endl;
                cout<<"|  Powered by ITATS                                      |"<<endl;
                cout<<"----------------------------------------------------------"<<endl;
                break;
            default:
                cout<<"Pilihan tidak ada"<<endl;
                system("PAUSE");
        }
        system("PAUSE");
    }while(ulang == true);
}
