void input_mobil(){
    bool sama;
    mobil_baru = new data_mobil;
    do{
        sama = false;
        cout<<"Masukan ID Mobil = ";
        cin>>mobil_baru->id_mobil;
        if(banyak_mobil != 0){
        mobil_posisi = mobil_depan;
            while(mobil_posisi != NULL){
                if(mobil_baru->id_mobil == mobil_posisi->id_mobil){
                    cout<<"ID sudah digunakan, Masukan id lainnya"<<endl;
                    sama = true;
                    break;
                }
                mobil_posisi = mobil_posisi->next;
            }
        }
    }while(sama == true);


    cout<<"Masukan Nama Mobil = ";
    cin.ignore();
    cin.getline(mobil_baru->nama_mobil, 50);
    do{
        cout<<"Masukan Tanggal Pembuatan = ";
        cin>>mobil_baru->pembuatan.hari;
        if(mobil_baru->pembuatan.hari>31 || mobil_baru->pembuatan.hari <= 0)
            cout<<"Tanggal Tidak Sesuai"<<endl;
    }while(mobil_baru->pembuatan.hari>31 || mobil_baru->pembuatan.hari <= 0);
    do{
        cout<<"Masukan Bulan Pembuatan = ";
        cin>>mobil_baru->pembuatan.bulan;
        if(mobil_baru->pembuatan.bulan>12 || mobil_baru->pembuatan.bulan <= 0)
            cout<<"Bulan Tidak Sesuai"<<endl;
    }while(mobil_baru->pembuatan.bulan>12 || mobil_baru->pembuatan.bulan <= 0);
    do{
        cout<<"Masukan tahun Pembuatan = ";
        cin>>mobil_baru->pembuatan.tahun;
        if(mobil_baru->pembuatan.tahun <= 1990)
            cout<<"Mobil Sudah Tua, standard Tahun 1991 ke atas"<<endl;
    }while(mobil_baru->pembuatan.tahun <= 1990);
    mobil_baru->status = false;
    strcpy(mobil_baru->peminjam, "");
    mobil_baru->lama_peminjaman = 0;
    mobil_baru->next = NULL;
}

void tambah_depan_mobil(){
    if(isEmpty(1))
        mobil_belakang = mobil_baru;
    else
        mobil_baru->next = mobil_depan;
    mobil_depan = mobil_baru;
    banyak_mobil++;
}

void tambah_belakang_mobil(){
    if(isEmpty(1))
        mobil_depan = mobil_baru;
    else
        mobil_belakang->next = mobil_baru;
    mobil_belakang = mobil_baru;
    banyak_mobil++;
}

void tambah_tengah_mobil(int letak){
    mobil_posisi = mobil_depan;
    for(int x = 1; x<letak; x++){
        mobil_bantu = mobil_posisi;
        mobil_posisi = mobil_posisi->next;
    }
    mobil_bantu->next = mobil_baru;
    mobil_baru->next = mobil_posisi;
    banyak_mobil++;
}

void hapus_depan_mobil(){
    mobil_hapus = mobil_depan;
    mobil_depan = mobil_hapus->next;
    mobil_hapus = NULL;
    banyak_mobil--;
}

void hapus_belakang_mobil(){
    mobil_posisi = mobil_depan;
    while(mobil_posisi->next->next != NULL)
        mobil_posisi = mobil_posisi ->next;
    mobil_belakang = mobil_posisi;
    mobil_posisi->next = NULL;
    banyak_mobil--;
}

void hapus_tengah_mobil(int letak){
    mobil_posisi = mobil_depan;
    for(int x = 1; x<letak; x++){
        mobil_bantu = mobil_posisi;
        mobil_posisi = mobil_posisi->next;
    }
    mobil_bantu->next = mobil_posisi->next;
    banyak_mobil--;
}

void tukar_posisi_mobil(){
    int posisi_1;
    int posisi_2;
    if(banyak_mobil < 2)
        cout<<"Mobil Kurang dari 2 atau belum ada data masuk"<<endl;
    else{
        cout<<"Masukan Posisi Pertama = ";
        cin>>posisi_1;
        cout<<"Masukan Posisi Kedua = ";
        cin>>posisi_2;

        //inisialisasi posisi pertama
        mobil_posisi = mobil_depan;
        if(posisi_1 == 1){
            mobil_simpan = mobil_posisi;
        }
        else{
            for(int x = 1; x<posisi_1; x++){
                mobil_simpan = mobil_posisi;
                mobil_posisi = mobil_posisi->next;
            }
        }

        mobil_tukar = mobil_posisi;
        temporary = new data_mobil;

        temporary->next = mobil_posisi->next;

        //inisialisasi Posisi kedua
        mobil_posisi = mobil_depan;
        if(posisi_2 == 1)
            mobil_bantu = mobil_posisi;
        else{
            for(int x = 1; x<posisi_2; x++){
                mobil_bantu = mobil_posisi;
                mobil_posisi = mobil_posisi->next;
            }
        }


        //penukaran
        if(posisi_2 == posisi_1-1 || posisi_2 == posisi_1+1){
            if(posisi_1 == 1){
                mobil_simpan->next = mobil_posisi->next;
                mobil_posisi->next = mobil_simpan;
                mobil_depan = mobil_posisi;
            }
            else if(posisi_2 == 1){
                mobil_bantu->next = mobil_tukar->next;
                mobil_tukar->next = mobil_bantu;
                mobil_depan = mobil_tukar;
            }
            else if(posisi_2 > posisi_1){
                mobil_tukar->next = mobil_posisi->next;
                mobil_posisi->next = mobil_tukar;
                mobil_simpan->next = mobil_posisi;
            }
            else{
                mobil_posisi->next = mobil_tukar->next;
                mobil_tukar->next = mobil_posisi;
                mobil_bantu->next = mobil_tukar;
            }
        }

        else{
            if(posisi_2 == 1){
                mobil_tukar->next = mobil_bantu->next;
                mobil_depan = mobil_tukar;
            }
            if(posisi_1 == 1){
                mobil_bantu->next = mobil_simpan;
                mobil_simpan->next = mobil_posisi->next;
                mobil_posisi->next = temporary->next;
                mobil_depan = mobil_posisi;
            }
            if(posisi_1 != 1){
                mobil_tukar->next = mobil_posisi->next;
                mobil_bantu->next = mobil_tukar;

                mobil_posisi->next = temporary->next;
                mobil_simpan->next = mobil_posisi;
            }
        }
    }
}

void tampil_mobil(){
    mobil_posisi = mobil_depan;
    while(mobil_posisi != NULL){
        if(strcmp(mobil_posisi->peminjam, "") == 0)
            cout<<"Nama Peminjam = Tidak Terpinjam"<<endl;
        else
            cout<<"Nama Peminjam = "<<mobil_posisi->peminjam<<endl;
        cout<<"ID Mobil = "<<mobil_posisi->id_mobil<<endl;
        cout<<"Nama Mobil = "<<mobil_posisi->nama_mobil<<endl;
        cout<<"Tanggal Pembuatan = "<<mobil_posisi->pembuatan.hari<<"-"<<mobil_posisi->pembuatan.bulan<<"-"<<mobil_posisi->pembuatan.tahun<<endl;
        if(mobil_posisi->status == true){
            cout<<"Status = Terpinjam"<<endl;
            cout<<"Lama Peminjaman = "<<mobil_posisi->lama_peminjaman<<endl;
        }
        else{
            cout<<"Status = Tidak Terpinjam"<<endl;
            cout<<"Lama Peminjaman = Tidak Terpinjam "<<endl;
        }
        cout<<endl<<endl;
        mobil_posisi = mobil_posisi->next;
    }
}

bool delete_mobil(){
    int hapus;
    cout<<"Masukan urutan data mobil yang ingin dihapus = ";
    cin>>hapus;

    if(hapus == 1)
        hapus_depan_mobil();
    else if(hapus == banyak_mobil)
        hapus_belakang_mobil();
    else
        hapus_tengah_mobil(hapus);
    return true;
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
    }while(ulang_menu == true);
}
