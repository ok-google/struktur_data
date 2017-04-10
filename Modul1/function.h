#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct data_user{
    char username[20];
    char password[20];
    char hak[20];
};

struct kalender{
    int tanggal;
    int bulan;
    int tahun;
};

struct data_mobil{
    char peminjam[20];
    int id_mobil;
    char nama_mobil[20];
    bool status;
    kalender pembuatan;
    int lama_pinjam;
};

data_user user[10];
data_user data_login;
data_mobil mobil[10];
int banyak_user = 0, banyak_mobil = 0, sukses_login, pilihan1;
bool logout = true, ulang = true;

void daftar(){
    system("CLS");
    bool sama;
    do{
    sama = false;
    cout<<"Masukan Username = ";
    cin.getline(user[banyak_user].username, 20);
    for(int i=0; i<banyak_user; i++){
        if(strcmp(user[banyak_user].username, user[i].username) == 0){
            cout<<"Username Sudah digunakan, Silahkan gunakan username yg lain"<<endl;
            sama = true;
        }
    }
    }while(sama == true);
    cout<<"Masukan Password = ";
    cin.getline(user[banyak_user].password, 20);
    do{
    sama = false;
    cout<<"Hak Akses = ";
    cin.getline(user[banyak_user].hak, 20);
    if((strcmp(user[banyak_user].hak, "admin")== 0) || (strcmp(user[banyak_user].hak, "user")==0)){
        cout<<"Hak Akses telah di konfirmasi "<<endl;
        system("PAUSE");
    }
    else{
        cout<<"Hak akses hanya admin dan user"<<endl;
        sama = true;
    }
    }while(sama == true);
    banyak_user++;
}

int login(){
    system("CLS");
    bool masuk = false;
    cout<<"Masukan Username = ";
    cin.getline(data_login.username, 20);

    cout<<"Masukan Password = ";
    cin.getline(data_login.hak, 20);
    for(int kounter = 0; kounter<banyak_user; kounter++){
        if((strcmp(data_login.username, user[kounter].username) == 0) && (strcmp(data_login.username, user[kounter].username) == 0)){
            if(strcmp(user[kounter].hak, "admin")==0){
                masuk = true;
                logout = false;
                return 1;
            }
            else if(strcmp(user[kounter].hak, "user")==0){
                masuk = true;
                logout = false;
                return 2;
            }
        }
        else if((kounter == banyak_user - 1) && (masuk==false) ){
            cout<<"Login Gagal"<<endl;
            return 0;
        }
    }
}

void aksi_login(){
        ulang = true;
        do{
        sukses_login = 0;
        system("CLS");
        cout<<"Menu"<<endl;
        cout<<"1. Register "<<endl;
        cout<<"2. Login "<<endl;
        cout<<"3. Akhiri Program"<<endl;
        cout<<"Masukan Pilihan Anda = ";
        cin>>pilihan1;
        cin.ignore();
        switch(pilihan1){
            case 1:
                daftar();
                break;
            case 2:
                sukses_login = login();
                if(sukses_login == 1 || sukses_login == 2){
                    ulang = false;
                    cout<<"Login Sukses"<<endl;
                    system("PAUSE");
                    system("CLS");
                }
                else{
                    cout<<"Login Gagal "<<endl;
                    system("PAUSE");
                }
                break;
            case 3:
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

    }while(ulang == true);
}
#endif // FUNCTION_H_INCLUDED
