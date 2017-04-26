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
    }while(sama);


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
    mobil_baru->prev = NULL;
}

void tambah_depan_mobil(){
    if(isEmpty(1))
        mobil_belakang = mobil_baru;
    else{
        mobil_baru->next = mobil_depan;
        mobil_depan->prev = mobil_baru;
    }
    mobil_depan = mobil_baru;
    banyak_mobil++;
}

void tambah_belakang_mobil(){
    if(isEmpty(1))
        mobil_depan = mobil_baru;
    else{
        mobil_belakang->next = mobil_baru;
        mobil_baru->prev = mobil_belakang;
    }
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
    mobil_baru->prev = mobil_bantu;

    mobil_baru->next = mobil_posisi;
    mobil_posisi->prev = mobil_baru;

    banyak_mobil++;
}

void hapus_depan_mobil(){
    mobil_hapus = mobil_depan;
    mobil_depan = mobil_hapus->next;
    mobil_depan->prev = NULL;
    mobil_hapus = NULL;
    banyak_mobil--;
}

void hapus_belakang_mobil(){
    mobil_hapus = mobil_belakang;
    mobil_belakang =mobil_hapus->prev;
    mobil_belakang->next = NULL;
    mobil_hapus = NULL;
    banyak_mobil--;
}

void hapus_tengah_mobil(int letak){
    mobil_posisi = mobil_depan;
    for(int x = 1; x<letak; x++){
        mobil_bantu = mobil_posisi;
        mobil_posisi = mobil_posisi->next;
    }
    mobil_bantu->next = mobil_posisi->next;
    mobil_posisi->next->prev = mobil_bantu;
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
        temporary->prev = mobil_posisi->prev;

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
                ((posisi_2 == banyak_mobil) ? mobil_belakang = mobil_simpan : mobil_posisi->next->prev = mobil_simpan);

                mobil_posisi->next = mobil_simpan;
                mobil_simpan->prev = mobil_posisi;

                mobil_depan = mobil_posisi;
            }
            else if(posisi_2 == 1){
                mobil_bantu->next = mobil_tukar->next;
                ((posisi_1 == banyak_mobil) ? mobil_belakang = mobil_bantu : mobil_tukar->next->prev = mobil_bantu);

                mobil_tukar->next = mobil_bantu;
                mobil_bantu->prev = mobil_tukar;

                mobil_depan = mobil_tukar;
            }
            else if(posisi_2 > posisi_1){
                mobil_tukar->next = mobil_posisi->next;
                ((posisi_2 == banyak_mobil) ? mobil_belakang = mobil_tukar : mobil_posisi->next->prev = mobil_tukar);

                mobil_posisi->next = mobil_tukar;
                mobil_tukar->prev = mobil_posisi;

                mobil_simpan->next = mobil_posisi;
                mobil_posisi->prev = mobil_simpan;
            }
            else{
                mobil_posisi->next = mobil_tukar->next;
                ((posisi_1 == banyak_mobil) ? mobil_belakang = mobil_posisi : mobil_tukar->next->prev = mobil_posisi);

                mobil_tukar->next = mobil_posisi;
                mobil_posisi->prev = mobil_tukar;

                mobil_bantu->next = mobil_tukar;
                mobil_tukar->next = mobil_bantu;
            }
        }

        else{
            if(posisi_2 == 1){
                mobil_tukar->next = mobil_bantu->next;
                mobil_bantu->next->prev = mobil_tukar;
                mobil_tukar->prev = NULL;

                mobil_depan = mobil_tukar;
            }
            if(posisi_1 == 1){
                mobil_bantu->next = mobil_simpan;
                mobil_simpan->prev = mobil_bantu;

                mobil_simpan->next = mobil_posisi->next;

                ((posisi_2 == banyak_mobil) ? mobil_belakang = mobil_simpan : mobil_posisi->next->prev = mobil_simpan);

                mobil_posisi->next = temporary->next;
                mobil_posisi->prev = NULL;

                mobil_depan = mobil_posisi;
            }
            if(posisi_1 != 1){
                mobil_tukar->next = mobil_posisi->next;
                ((posisi_2 == banyak_mobil) ? mobil_belakang = mobil_tukar : mobil_posisi->next->prev = mobil_tukar);
                mobil_bantu->next = mobil_tukar;
                mobil_tukar->prev = mobil_bantu;

                mobil_posisi->next = temporary->next;
                mobil_simpan->next = mobil_posisi;
                mobil_posisi->prev = mobil_simpan;
            }
        }
    }
}

void tampil_mobil(){
    mobil_posisi = mobil_depan;
    char sub_pilihan;
    bool ulang;
    while(mobil_posisi != NULL){
        if(strcmp(mobil_posisi->peminjam, "") == 0)
            cout<<"Nama Peminjam = Tidak Terpinjam"<<endl;
        else
            cout<<"Nama Peminjam = "<<mobil_posisi->peminjam<<endl;
        cout<<"ID Mobil = "<<mobil_posisi->id_mobil<<endl;
        cout<<"Nama Mobil = "<<mobil_posisi->nama_mobil<<endl;
        cout<<"Tanggal Pembuatan = "<<mobil_posisi->pembuatan.hari<<"-"<<mobil_posisi->pembuatan.bulan<<"-"<<mobil_posisi->pembuatan.tahun<<endl;
        if(mobil_posisi->status){
            cout<<"Status = Terpinjam"<<endl;
            cout<<"Lama Peminjaman = "<<mobil_posisi->lama_peminjaman<<endl;
        }
        else{
            cout<<"Status = Tidak Terpinjam"<<endl;
            cout<<"Lama Peminjaman = Tidak Terpinjam "<<endl;
        }
        cout<<"Alamat Memory = "<<user_posisi<<endl;
        cout<<endl<<endl;
        do{
            ulang = false;
            cout<<((mobil_posisi == mobil_depan) ? "" : "p = Previous")<<" "<<((mobil_posisi == mobil_belakang) ? "" : "n = Next")<<" "<<"b = back to menu"<<endl;
            cout<<"Masukan Pilihan Anda = ";
            cin>>sub_pilihan;
            if(sub_pilihan == 'p')
                mobil_posisi = mobil_posisi->prev;
            else if(sub_pilihan == 'n')
                mobil_posisi = mobil_posisi->next;
            else if(sub_pilihan == 'b'){
                mobil_posisi = mobil_belakang;
                mobil_posisi = mobil_posisi->next;
            }
            else
                ulang = true;
        }while(ulang);
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
