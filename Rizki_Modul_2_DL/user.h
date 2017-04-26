#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct data_user{
    char nama[50];
    char pass[20];
    char akses[10];
    data_user *next;
    data_user *prev;
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
    data_mobil *prev;
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
    if(a == 1)
        return ((mobil_depan == NULL) ? true : false);
    else if(a == 2)
        return ((user_depan == NULL) ? true : false);
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
    }while(sama);

    cout<<"Masukan Password = ";
    cin.getline(user_baru->pass, 20);

    do{
    cout<<"Masukan Hak Akses = ";
    cin.getline(user_baru->akses, 10);
    }while(strcmp(user_baru->akses, "admin") != 0 && strcmp(user_baru->akses, "user") != 0);
    user_baru->next = NULL;
    user_baru->prev = NULL;
}

void tambah_depan_user(){
    if(isEmpty(2))
        user_belakang = user_baru;
    else{
        user_baru->next = user_depan;
        user_depan->prev = user_baru;
    }
    user_depan = user_baru;
    banyak_user++;
}

void tambah_belakang_user(){
    if(isEmpty(2))
        user_depan = user_baru;
    else{
        user_belakang->next = user_baru;
        user_baru->prev = user_belakang;
    }
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
    user_baru->prev = user_bantu;

    user_baru->next = user_posisi;
    user_posisi->prev = user_baru;
    banyak_user++;
}

void hapus_depan_user(){
    user_hapus = user_depan;
    user_depan = user_depan->next;
    user_depan->prev = NULL;
    user_hapus = NULL;
    banyak_user--;
}

void hapus_belakang_user(){
    user_hapus = user_belakang;
    user_belakang = user_belakang->prev;
    user_belakang->next = NULL;
    user_hapus = NULL;
    banyak_user--;
}

void hapus_tengah_user(int letak){
    user_posisi = user_depan;
    for(int x = 1; x<letak; x++){
        user_bantu = user_posisi;
        user_posisi = user_posisi->next;
    }
    user_bantu->next = user_posisi->next;
    user_posisi->next->prev = user_bantu;
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
        temp->prev = user_posisi->prev;

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
                ((posisi_2 == banyak_user) ? user_belakang = user_simpan : user_posisi->next->prev = user_simpan);

                user_posisi->next = user_simpan;
                user_simpan->prev = user_posisi;

                user_depan = user_posisi;
            }
            else if(posisi_2 == 1){
                user_bantu->next = user_tukar->next;
                ((posisi_1 == banyak_user) ? user_belakang = user_bantu : user_tukar->next->prev = user_bantu);

                user_tukar->next = user_bantu;
                user_bantu->prev = user_tukar;

                user_depan = user_tukar;
            }
            else if(posisi_2 > posisi_1){
                user_tukar->next = user_posisi->next;
                ((posisi_2 == banyak_user) ? user_belakang = user_tukar : user_posisi->next->prev = user_tukar);

                user_posisi->next = user_tukar;
                user_tukar->prev = user_posisi;

                user_simpan->next = user_posisi;
                user_posisi->prev = user_simpan;
            }
            else{
                user_posisi->next = user_tukar->next;
                ((posisi_1 == banyak_user) ? user_belakang = user_posisi : user_tukar->next->prev = user_posisi);

                user_tukar->next = user_posisi;
                user_posisi->prev = user_tukar;

                user_bantu->next = user_tukar;
                user_tukar->next = user_bantu;
            }
        }

        else{
            if(posisi_2 == 1){
                user_tukar->next = user_bantu->next;
                user_bantu->next->prev = user_tukar;
                user_tukar->prev = NULL;

                user_depan = user_tukar;
            }
            if(posisi_1 == 1){
                user_bantu->next = user_simpan;
                user_simpan->prev = user_bantu;

                user_simpan->next = user_posisi->next;

                ((posisi_2 == banyak_user) ? user_belakang = user_simpan : user_posisi->next->prev = user_simpan);

                user_posisi->next = temp->next;
                user_posisi->prev = NULL;

                user_depan = user_posisi;
            }
            if(posisi_1 != 1){
                user_tukar->next = user_posisi->next;
                ((posisi_2 == banyak_user) ? user_belakang = user_tukar : user_posisi->next->prev = user_tukar);
                user_bantu->next = user_tukar;
                user_tukar->prev = user_bantu;

                user_posisi->next = temp->next;
                user_simpan->next = user_posisi;
                user_posisi->prev = user_simpan;
            }
        }
    }
}

void tampil_user(){
    char sub_pilihan;
    bool ulang;
    user_posisi = user_depan;
    while(user_posisi != NULL){
        cout<<user_posisi<<endl;
        cout<<user_posisi->nama<<"\t\t\t\t"<<user_posisi->akses<<"\t\t\t\t"<<user_posisi<<endl;
        do{
            ulang = false;
            cout<<((user_posisi == user_depan) ? "" : "p = Previous")<<" "<<((user_posisi == user_belakang) ? "" : "n = Next")<<" "<<"b = back to menu"<<endl;
            cout<<"Masukan Pilihan Anda = ";
            cin>>sub_pilihan;
            if(sub_pilihan == 'p')
                user_posisi = user_posisi->prev;
            else if(sub_pilihan == 'n')
                user_posisi = user_posisi->next;
            else if(sub_pilihan == 'b'){
                user_posisi = user_belakang;
                user_posisi = user_posisi->next;
            }
            else
                ulang = true;
        }while(ulang);
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
                    }while(ulang);
                break;
                default:
                    cout<<"Pilihan tidak tersedia";
                    ulang = true;
                break;
            }
        }while(ulang);
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
