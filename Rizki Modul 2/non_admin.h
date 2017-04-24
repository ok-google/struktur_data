void tampil_non_admin(){
    if(banyak_mobil == 0){
        cout<<"Belum Ada mobil di input"<<endl;
    }
    else{
        mobil_posisi = mobil_depan;
        while(mobil_posisi != NULL){
            if(mobil_posisi->status == false){
                cout<<"ID Mobil = "<<mobil_posisi->id_mobil<<endl;
                cout<<"Nama Mobil = "<<mobil_posisi->nama_mobil<<endl;
                cout<<"Tanggal Pembuatan = "<<mobil_posisi->pembuatan.hari<<"-"<<mobil_posisi->pembuatan.bulan<<"-"<<mobil_posisi->pembuatan.tahun<<endl;
                cout<<"Status = Tidak Terpinjam"<<endl;
                cout<<endl;
            }
            mobil_posisi = mobil_posisi->next;
        }

    }
}

void pinjam_mobil(){
    int id_mobil, lama_pinjam;
    char pinjam;
    bool check = false;
    cout<<"Masukan ID Mobil = ";
    cin>>id_mobil;
    mobil_posisi = mobil_depan;
    while(mobil_posisi != NULL){
        if(mobil_posisi->id_mobil == id_mobil){
            check = true;
            if(mobil_posisi->status == false){
                cout<<"ID Mobil = "<<mobil_posisi->id_mobil<<endl;
                cout<<"Nama Mobil = "<<mobil_posisi->nama_mobil<<endl;
                cout<<"Tanggal Pembuatan = "<<mobil_posisi->pembuatan.hari<<"-"<<mobil_posisi->pembuatan.bulan<<"-"<<mobil_posisi->pembuatan.tahun<<endl;
                cout<<"Status = Tidak Terpinjam"<<endl;
                cout<<endl;

                cout<<"Apakah Anda akan Pinjam Mobil ini [y/t] ? "<<endl;
                cin>>pinjam;

                if(pinjam == 'y'){
                    strcpy(mobil_posisi->peminjam, data_login.nama);
                    mobil_posisi->status = true;
                    cout<<"Masukan Lama Peminjaman = ";
                    cin>>lama_pinjam;
                    mobil_posisi->lama_peminjaman = lama_pinjam;
                }
                else{
                    cout<<"Peminjaman Dibatalkan"<<endl;
                }
            }
            else{
                cout<<"Mobil Sudah Terpinjam"<<endl;
            }

        }
        mobil_posisi = mobil_posisi->next;
    }
    if((check == false)){
            cout<<"Tidak ada kecocokan ID"<<endl;
    }
}

void kembali_mobil(){
    char username[20], kembali;
    bool check = false;
    cin.ignore();
    cout<<"Masukan Username = ";
    cin.getline(username, 20);
    mobil_posisi = mobil_depan;
    while(mobil_posisi != NULL){
        if(strcmp(username, mobil_posisi->peminjam) == 0){
            check = true;
            cout<<"Nama Peminjam = "<<mobil_posisi->peminjam<<endl;
            cout<<"ID Mobil = "<<mobil_posisi->id_mobil<<endl;
            cout<<"Nama Mobil = "<<mobil_posisi->nama_mobil<<endl;
            cout<<"Tanggal Pembuatan = "<<mobil_posisi->pembuatan.hari<<"-"<<mobil_posisi->pembuatan.bulan<<"-"<<mobil_posisi->pembuatan.tahun<<endl;
            cout<<"Status = Terpinjam"<<endl;
            cout<<"Lama Peminjaman = "<<mobil_posisi->lama_peminjaman<<endl;
            cout<<endl;

            cout<<"Anda ingin mengembalikan Mobil [y/n] ? ";
            cin>>kembali;

            if(kembali == 'y'){
                mobil_posisi->status = false;
            }
            else{
                cout<<"Pengembalian Dibatalkan"<<endl;
            }
        }
        mobil_posisi = mobil_posisi->next;
    }

    if((check == false)){
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void menu_user(){
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
    }while(ulang_menu == true);
}
