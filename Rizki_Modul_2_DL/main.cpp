#include "user.h"
#include "admin.h"
#include "non_admin.h"

int main(){
    do{
        if(logout){
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
                        break;
                    case 4:
                        tampil_user();
                        break;
                    case 5:
                        tukar_posisi_user();
                        break;
                    case 6:
                        ulang = logout = false;
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
            }while(ulang);
        }
        if(sukses_login == 1){
            int pilihan;
            bool ulang_menu = true;
            do{
            system("CLS");
            cout<<"Menu"<<endl;
            cout<<"1. Lihat Mobil"<<endl;
            cout<<"2. Tambah Mobil"<<endl;
            cout<<"3. Hapus Mobil"<<endl;
            cout<<"4. Tukar Posisi Mobil"<<endl;
            cout<<"5. Logout"<<endl;
            cout<<"Masukan Pilihan Anda = ";
            cin>>pilihan;
            cin.ignore();

            switch(pilihan){
                case 1:
                    tampil_mobil();
                    break;
                case 2:
                    input_mobil();
                    if(banyak_mobil != 0){
                        int letak, sub_pilih;
                        bool ulang;
                        do{
                            ulang = false;
                            cout<<"\n1. Tambah Ke Data Paling Depan"<<endl;
                            cout<<"2. Tambah Ke Data Paling Belakang"<<endl;
                            if(banyak_mobil >= 2)
                                cout<<"3. Tambah Data di Tengah Range( 1 - "<<banyak_mobil<<" )"<<endl;
                            cout<<"Masukan Pilihan Anda = ";
                            cin>>sub_pilih;
                            switch(sub_pilih){
                                case 1:
                                    tambah_depan_mobil();
                                break;
                                case 2:
                                    tambah_belakang_mobil();
                                break;
                                case 3:
                                    do{
                                        ulang = false;
                                        cout<<"Taruh posisi mana ? Range( 1 - "<<banyak_mobil<<" )"<<endl;
                                        cin>>letak;
                                        if(letak <= banyak_mobil && letak > 0)
                                            tambah_tengah_mobil(letak);
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
                        tambah_depan_mobil();
                    }

                    cout<<"Selamat Mobil Sukses di tambahkan"<<endl<<endl;
                    break;
                case 3:
                    int letak, sub_pilih;
                    bool ulang;
                    if(banyak_mobil > 0){
                        do{
                            ulang = false;
                            cout<<"\n1. Hapus Ke Data Paling Depan"<<endl;
                            cout<<"2. Hapus Ke Data Paling Belakang"<<endl;
                            if(banyak_mobil > 2)
                                cout<<"3. Hapus Data di Tengah Range( 1 - "<<banyak_mobil<<" )"<<endl;
                            cout<<"Masukan Pilihan Anda = ";
                            cin>>sub_pilih;
                            switch(sub_pilih){
                                case 1:
                                    hapus_depan_mobil();
                                break;
                                case 2:
                                    hapus_belakang_mobil();
                                break;
                                case 3:
                                    do{
                                        ulang = false;
                                        cout<<"Taruh posisi mana ? Range( 1 - "<<banyak_mobil<<" )"<<endl;
                                        cin>>letak;
                                        if(letak < banyak_mobil && letak > 0)
                                            hapus_tengah_mobil(letak);
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
                        cout<<"Mobil Mobil Sukses di Hapus"<<endl<<endl;
                    }
                    else{
                        cout<<"Data Kosong "<<endl;
                    }
                    break;
                case 4:
                    tukar_posisi_mobil();
                    break;
                case 5:
                    logout = true;
                    ulang_menu = false;
                    break;
                default:
                    cout<<"Pilihan Tidak Tersedia"<<endl;
                    break;
            }
            system("PAUSE");
            }while(ulang_menu);
        }
        else if(sukses_login == 2){
            bool ulang_menu = true;
            int pilihan1;
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
                        tampil_non_admin();
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
            }while(ulang_menu);
        }
    }while(logout);
}
