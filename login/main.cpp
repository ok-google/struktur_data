#include <iostream>
#include "login.h"

using namespace std;

int main()
{
    char username[50], password[50], ulang;
    int pilih;
    do{
        cout<<"Menu"<<endl;
        cout<<"1. Daftar"<<endl;
        cout<<"2. Login"<<endl;
        if(count_user()>0){//count_user() digunakan untuk menghitung Jumlah user yang telah register
            cout<<"3. Delete User"<<endl;
        }
        if(active_username()!= ""){//active_username untuk melihat username yang sekarang aktif
            cout<<"4. Logout"<<endl;
        }
        cout<<"Masukan Pilihan = ";
        cin>>pilih;
        if(active_username()== "" && pilih > 3){
            pilih = 0;
        }
        cin.ignore();
        switch(pilih){
            case 1:
                cout<<"Masukan username = ";
                cin.getline(username, 100);
                cout<<"Masukan Password = ";
                cin.getline(password, 100);
                if(add_account(username, password)){//add_account(username, password) untuk mendaftarkan akun
                    cout<<"Register Accept"<<endl;
                }
                else{
                    cout<<"Register Fail, duplicate username"<<endl;
                }
                break;
            case 2:
                cout<<"\n\nMasukan username = ";
                cin.getline(username, 100);
                cout<<"Masukan Password = ";
                cin.getline(password, 100);
                if(login(username, password)){//login(username, password) untuk masuk/login
                    cout<<"Login Sukses"<<endl;
                    cout<<"Login Username = "<<active_username()<<endl;
                }
                else{
                    cout<<"Login Gagal";
                }
                break;
            case 3:
                cout<<"Masukan username yang akan dihapus= ";
                cin.getline(username, 100);
                delete_user(username);//delete_user(username), untuk menghapus user yang sudah terdaftar
                break;
            case 4:
                logout();//logout()untuk melogout akun anda
                break;
            default:
                cout<<"Pilihan tidak ada"<<endl;
                break;
        }
        cout<<"Ulang == ";
        cin>>ulang;
    }while(ulang == 'y');
}
