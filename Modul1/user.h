#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "function.h"

void tampil_user(){
    if(banyak_mobil == 0){
        cout<<"Belum Ada mobil di input"<<endl;
    }
    else{
        for(int kounter = 0; kounter<banyak_mobil; kounter++){
            if(mobil[kounter].status == false){
                cout<<"ID Mobil = "<<mobil[kounter].id_mobil<<endl;
                cout<<"Nama Mobil = "<<mobil[kounter].nama_mobil<<endl;
                cout<<"Tanggal Pembuatan = "<<mobil[kounter].pembuatan.tanggal<<"-"<<mobil[kounter].pembuatan.bulan<<"-"<<mobil[kounter].pembuatan.tahun<<endl;
                cout<<"Status = Tidak Terpinjam"<<endl;
                cout<<endl;
            }
        }
    }
}

void pinjam_mobil(){
    int id_mobil, lama_pinjam;
    char pinjam;
    bool check = false;
    cout<<"Masukan ID Mobil = ";
    cin>>id_mobil;
    for(int kounter=0; kounter<banyak_mobil; kounter++){
        if(mobil[kounter].id_mobil == id_mobil){
            check = true;
            if(mobil[kounter].status == false){
                cout<<"ID Mobil = "<<mobil[kounter].id_mobil<<endl;
                cout<<"Nama Mobil = "<<mobil[kounter].nama_mobil<<endl;
                cout<<"Tanggal Pembuatan = "<<mobil[kounter].pembuatan.tanggal<<"-"<<mobil[kounter].pembuatan.bulan<<"-"<<mobil[kounter].pembuatan.tahun<<endl;
                cout<<"Status = Tidak Terpinjam"<<endl;
                cout<<endl;

                cout<<"Apakah Anda akan Pinjam Mobil ini [y/t] ? "<<endl;
                cin>>pinjam;

                if(pinjam == 'y'){
                    strcpy(mobil[kounter].peminjam, data_login.username);
                    mobil[kounter].status = true;
                    cout<<"Masukan Lama Peminjaman = ";
                    cin>>lama_pinjam;
                    mobil[kounter].lama_pinjam = lama_pinjam;
                }
                else{
                    cout<<"Peminjaman Dibatalkan"<<endl;
                }
            }
            else{
                cout<<"Mobil Sudah Terpinjam"<<endl;
            }

        }
        else if((check == false) && (kounter == banyak_mobil-1)){
            cout<<"Tidak ada kecocokan ID"<<endl;
        }
    }
}

void kembali_mobil(){
    char username[20], kembali;
    bool check = false;
    cin.ignore();
    cout<<"Masukan Username = ";
    cin.getline(username, 20);
    for(int kounter = 0; kounter < banyak_mobil; kounter++){
        if(strcmp(username, mobil[kounter].peminjam) == 0){
            check = true;
            cout<<"Nama Peminjam = "<<mobil[kounter].peminjam<<endl;
            cout<<"ID Mobil = "<<mobil[kounter].id_mobil<<endl;
            cout<<"Nama Mobil = "<<mobil[kounter].nama_mobil<<endl;
            cout<<"Tanggal Pembuatan = "<<mobil[kounter].pembuatan.tanggal<<"-"<<mobil[kounter].pembuatan.bulan<<"-"<<mobil[kounter].pembuatan.tahun<<endl;
            cout<<"Status = Terpinjam"<<endl;
            cout<<"Lama Peminjaman = "<<mobil[kounter].lama_pinjam<<endl;
            cout<<endl;

            cout<<"Anda ingin mengembalikan Mobil [y/n] ? ";
            cin>>kembali;

            if(kembali == 'y'){
                mobil[kounter].status = false;
            }
            else{
                cout<<"Pengembalian Dibatalkan"<<endl;
            }
        }
        else if((check == false) && (kounter = banyak_mobil -1)){
            cout<<"Data tidak ditemukan"<<endl;
        }
    }
}

void menu_user(){
    bool ulang_menu = true;
    int pilihan;
    do{
        system("CLS");
        cout<<"Menu"<<endl;
        cout<<"1. Tampil Mobil"<<endl;
        cout<<"2. Pinjam Mobil"<<endl;
        cout<<"3. Kembalikan Mobil"<<endl;
        cout<<"4. Logout"<<endl;
        cout<<"Masukan Pilihan Anda = ";
        cin>>pilihan1;

        switch(pilihan1){
            case 1:
                tampil_user();
                break;
            case 2:
                pinjam_mobil();
                break;
            case 3:
                kembali_mobil();
                break;
            case 4:
                logout = true;
                ulang_menu = false;
                break;
            default:
                cout<<"Pilihan tidak ada "<<endl;
                break;
        }
        system("PAUSE");
    }while(ulang_menu == true);
}

#endif // USER_H_INCLUDED
