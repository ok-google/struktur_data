#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "function.h"

bool tambah_admin(){
    bool sama, check;
    do{
    sama = false;
    cout<<"Masukan ID Mobil = ";
    cin>>mobil[banyak_mobil].id_mobil;
    for(int i = 0; i<banyak_mobil; i++){
        if(mobil[banyak_mobil].id_mobil == mobil[i].id_mobil){
            cout<<"ID sudah digunakan, Masukan id lainnya"<<endl;
            sama = true;
        }
    }
    }while(sama == true);
    cin.ignore();
    cout<<"Masukan Nama Mobil = ";
    cin.getline(mobil[banyak_mobil]. nama_mobil, 20);
    do{
    check = true;
    cout<<"Tanggal Pembuatan = ";
    cin>>mobil[banyak_mobil].pembuatan.tanggal;
        if(mobil[banyak_mobil].pembuatan.tanggal>31 || mobil[banyak_mobil].pembuatan.tanggal < 1){
            check = false;
            cout<<"Situ error mana ada tanggal "<<mobil[banyak_mobil].pembuatan.tanggal<<endl;
            cout<<"Input Lagi sana"<<endl;
        }
    }while(check == false);
    do{
    check = true;
    cout<<"Bulan Pembuatan = ";
    cin>>mobil[banyak_mobil].pembuatan.bulan;
        if(mobil[banyak_mobil].pembuatan.bulan > 12 || mobil[banyak_mobil].pembuatan.bulan < 1){
            check = false;
            cout<<"Bulan itu 1 - 12 vrohhh !!!"<<endl;
        }
    }while(check == false);
    do{
    check = true;
    cout<<"Tahun Pembuatan = ";
    cin>>mobil[banyak_mobil].pembuatan.tahun;
        if(mobil[banyak_mobil].pembuatan.tahun < 1990){
            check = false;
            cout<<"Mobil anda tua Sekali, Standard Tahun pembuatan 1990 keatas"<<endl;
        }
    }while(check == false);
    banyak_mobil++;
    return true;
}

bool hapus_admin(){
    int id_hapus;
    char yakin;
    bool check = false;
    if(banyak_mobil == 0){
        cout<<"Belum Ada mobil di input"<<endl;
    }
    else{
        cout<<"Masukan ID Mobil yang ingin di hapus = ";
        cin>>id_hapus;

        for(int kounter = 0 ; kounter<banyak_mobil; kounter++){
            if(mobil[kounter].id_mobil == id_hapus){
                if(mobil[kounter].status == true){
                    cout<<"Nama Peminjam = "<<mobil[kounter].peminjam<<endl;
                }
                cout<<"ID Mobil = "<<mobil[kounter].id_mobil<<endl;
                cout<<"Nama Mobil = "<<mobil[kounter].nama_mobil<<endl;
                cout<<"Tanggal Pembuatan = "<<mobil[kounter].pembuatan.tanggal<<"-"<<mobil[kounter].pembuatan.bulan<<"-"<<mobil[kounter].pembuatan.tahun<<endl;
                cout<<"Status = "<<((mobil[kounter].status == true) ? "Terpinjam" : "Tidak Terpinjam")<<endl;
                if((mobil[kounter].status == true)){
                    cout<<"Lama Peminjaman = "<<mobil[kounter].lama_pinjam<<endl;
                }
                else{
                    cout<<"Lama Peminjaman = Tidak Terpinjam "<<endl;
                }
                cout<<"Anda Yakin Ingin menghapus Mobil ini dari daftar [y/t] ?";
                cin>>yakin;

                if(yakin == 'y'){
                    for(int i = kounter; i<banyak_mobil; i++){
                        mobil[i].id_mobil = mobil[i+1].id_mobil;
                        strcpy(mobil[i].nama_mobil, mobil[i+1].nama_mobil);
                        strcpy(mobil[i].peminjam, mobil[i+1].peminjam);
                        mobil[i].pembuatan.tanggal = mobil[i+1].pembuatan.tanggal;
                        mobil[i].pembuatan.bulan = mobil[i+1].pembuatan.bulan;
                        mobil[i].pembuatan.tahun = mobil[i+1].pembuatan.tahun;
                        mobil[i].status = mobil[i+1].status;
                        mobil[i].lama_pinjam = mobil[i+1].lama_pinjam;
                    }
                    banyak_mobil--;
                }
                else{
                    cout<<"Penghapusan Dibatalkan"<<endl;
                }

                check = true;
            }
            else if((check == false) && (kounter == banyak_mobil-1)){
                cout<<"Data Mobil tidak ditemukan"<<endl;
            }
        }
    }
}

void tampil_admin(){
    if(banyak_mobil == 0){
        cout<<"Belum Ada mobil di input"<<endl;
    }
    else{
        for(int kounter = 0; kounter<banyak_mobil; kounter++){
            if(mobil[kounter].status == true){
                cout<<"Nama Peminjam = "<<mobil[kounter].peminjam<<endl;
            }
            cout<<"ID Mobil = "<<mobil[kounter].id_mobil<<endl;
            cout<<"Nama Mobil = "<<mobil[kounter].nama_mobil<<endl;
            cout<<"Tanggal Pembuatan = "<<mobil[kounter].pembuatan.tanggal<<"-"<<mobil[kounter].pembuatan.bulan<<"-"<<mobil[kounter].pembuatan.tahun<<endl;
            cout<<"Status = "<<((mobil[kounter].status == true) ? "Terpinjam" : "Tidak Terpinjam")<<endl;
            if((mobil[kounter].status == true)){
                cout<<"Lama Peminjaman = "<<mobil[kounter].lama_pinjam<<endl;
            }
            else{
                cout<<"Lama Peminjaman = Tidak Terpinjam "<<endl;
            }
            cout<<endl;
        }
    }
}

void menu_admin(){
    int pilihan;
    bool ulang_menu = true;
    do{
    system("CLS");
    cout<<"Menu"<<endl;
    cout<<"1. Lihat Mobil"<<endl;
    cout<<"2. Tambah Mobil"<<endl;
    cout<<"3. Hapus Mobil"<<endl;
    cout<<"4. Logout"<<endl;
    cout<<"Masukan Pilihan Anda = ";
    cin>>pilihan;
    cin.ignore();

    switch(pilihan){
        case 1:
            tampil_admin();
            break;
        case 2:
            if(tambah_admin()){
                cout<<"Selamat Mobil Sukses di tambahkan"<<endl<<endl;
            };
            break;
        case 3:
            if(hapus_admin()){
                cout<<"Mobil Mobil Sukses di Hapus"<<endl<<endl;
            };
            break;
        case 4:
            logout = true;
            ulang_menu = false;
            break;
        default:
            cout<<"Pilihan Tidak Tersedia"<<endl;
            break;
    }
    system("PAUSE");
    }while(ulang_menu == true);
}
#endif // ADMIN_H_INCLUDED
