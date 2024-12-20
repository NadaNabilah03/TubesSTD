#include <iostream>
#include <windows.h>
#include <limits> // Untuk numeric_limits
#include "tubes.h"

using namespace std;

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string password;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "|               Selamat Datang di Database Perusahaan XYZ               |" << endl;
    cout << "|         Silahkan masukkan password! Maksimal percobaan 3 kali         |" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << endl;
    cout << "     Password: ";
    cin >> password;
    int maks = 0;
    while (password != "2tambah4samadengan8"){
        if (maks == 2){
            maks = maks + 1;
            break;
        }
        cout << "     Silahkan masukkan lagi: ";
        cin >> password;
        maks++;
    }

    if (maks == 3){
        SetConsoleTextAttribute(hConsole, 04);
        cout << "     Anda sudah mencoba password 3 kali. Akses anda kami tolak!";
        SetConsoleTextAttribute(hConsole, 07);
    }

    if (password == "2tambah4samadengan8"){
        int pilihan = 1;
        ListKaryawan LK;
        ListProject LP;
        inputProject(LP);
        inputKaryawan(LK);
        adrKaryawan K;
        adrProject P;
        assign_Project_To_Karyawan(LK, LP, 1, "P02");
        assign_Project_To_Karyawan(LK, LP, 2, "P01");
        assign_Project_To_Karyawan(LK, LP, 5, "P07");
        assign_Project_To_Karyawan(LK, LP, 4, "P02");
        cout << endl;
        cout << "                                  Halo!                                  " << endl;
        while (pilihan < 5 && pilihan > 0 ){
            menuAwal();
            cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5): ";
            cin >> pilihan;
            while (cin.fail()){
                notInt();
                SetConsoleTextAttribute(hConsole, 04);
                cout << "   Pilihan harus berupa integer!" << endl;
                SetConsoleTextAttribute(hConsole, 07);
                cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5): ";
                cin >> pilihan;
            }
            cout << endl;
            if (pilihan == 1){
                int pilihan = 1;
                while (pilihan > 0 && pilihan < 4){
                    menuKaryawan();
                    cout << "   Masukkan menu yang ingin dipilih (1/2/3/4): ";
                    cin >> pilihan;
                    while(cin.fail()){
                        notInt();
                        SetConsoleTextAttribute(hConsole, 04);
                        cout << "   Pilihan harus berupa integer!" << endl;
                        SetConsoleTextAttribute(hConsole, 07);
                        cout << "   Masukkan menu yang ingin dipilih (1/2/3/4): ";
                        cin >> pilihan;
                    }
                    cout << endl;
                    switch (pilihan){
                        case 1:{
                            //input karyawan
                            int jumlah;
                            infoTypeKaryawan x;
                            string answer;
                            cout << "   Berapa data karyawan yang ingin anda masukkan?: ";
                            cin >> jumlah;
                            while (cin.fail()){
                                notInt();
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Jumlah harus berupa integer!" << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << "   Berapa data karyawan yang ingin anda masukkan?: ";
                                cin >> jumlah;
                            }
                            for(int i = 1; i <= jumlah; i++){
                                cout << "   Masukkan ID karyawan: ";
                                cin >> x.ID_karyawan;
                                if(cin.fail()){
                                    notInt();
                                    SetConsoleTextAttribute(hConsole, 04);
                                    cout << "   PILIHAN YANG ANDA MASUKKAN HARUS INTEGER!" << endl;
                                    SetConsoleTextAttribute(hConsole, 07);
                                    i--;
                                }else{
                                    adrKaryawan cek = find_Karyawan(LK, x.ID_karyawan);
                                    while (cek != NULL){
                                        cout << "   ID yang dimasukkan telah digunakan." << endl;
                                        cout << "   Silahkan masukkan ID Karyawan yang lain: ";\
                                        cin >> x.ID_karyawan;
                                        cek = find_Karyawan(LK, x.ID_karyawan);
                                        cout << endl;
                                    }
                                    cout << "   Masukkan nama karyawan: ";
                                    cin >> x.nama_karyawan;
                                    cout << "   Masukkan jabatan karyawan: ";
                                    cin >> x.jabatan;
                                    cout << "   Masukkan departemen karyawan: ";
                                    cin >> x.department;
                                    cout << "   Masukkan gaji karyawan: ";
                                    cin >> x.gaji;
                                    while (cin.fail()){
                                        notInt();
                                        SetConsoleTextAttribute(hConsole, 4);
                                        cout << "   Gaji karyawan yang anda masukkan tidak valid." << endl;
                                        SetConsoleTextAttribute(hConsole, 7);
                                        cout << "   Masukkan gaji karyawan: ";
                                        cin >> x.gaji;
                                    }
                                    while (x.gaji < 3000000 || x.gaji > 100000000){
                                        SetConsoleTextAttribute(hConsole, 4);
                                        cout << "   Gaji karyawan yang anda masukkan tidak valid." << endl;
                                        SetConsoleTextAttribute(hConsole, 14);
                                        cout << "   Silahkan masukkan gaji dengan rentang 3 juta sampai 100 juta: ";
                                        SetConsoleTextAttribute(hConsole, 7);
                                        cin >> x.gaji;
                                        while (cin.fail()){
                                            notInt();
                                            SetConsoleTextAttribute(hConsole, 4);
                                            cout << "   Gaji karyawan yang anda masukkan tidak valid." << endl;
                                            SetConsoleTextAttribute(hConsole, 7);
                                            cout << "   Masukkan gaji karyawan: ";
                                            cin >> x.gaji;
                                        }
                                    }
                                    cout << endl;
                                        K = create_Element_Karyawan(x);
                                        insert_Last_Karyawan(LK, K);
                                    SetConsoleTextAttribute(hConsole, 10);
                                    cout << "   Data sudah berhasil dimasukkan ke dalam list Karyawan!" << endl;
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cout << "   Apakah anda ingin menampilkan semua data list Karyawan? (ketik Ya/Tidak): ";
                                    cin >> answer;
                                    if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                        show_All_Data_Karyawan(LK);
                                        cout << endl;
                                    }
                                }
                            }
                            break;
                        }
                        case 2:{
                            //hapus karyawan
                            int ID;
                            string answer;
                            if (EmptyKaryawan(LK)){
                                cout << "   Saat ini tidak ada karyawan." << endl;
                                cout << endl;
                            }else{
                                SetConsoleTextAttribute(hConsole, 14);
                                cout << "   Karyawan dengan ID apa yang ingin anda hapus datanya?: ";
                                SetConsoleTextAttribute(hConsole, 07);
                                cin >> ID;
                                while (cin.fail()){
                                    notInt();
                                    SetConsoleTextAttribute(hConsole, 4);
                                    cout << "   ID karyawan berupa integer." << endl;
                                    SetConsoleTextAttribute(hConsole, 14);
                                    cout << "   Karyawan dengan ID apa yang ingin anda hapus datanya?: ";
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cin >> ID;
                                }
                                adrKaryawan cek = find_Karyawan(LK, ID);
                                if (cek == NULL){
                                    SetConsoleTextAttribute(hConsole, 04);
                                    cout << "   Karyawan dengan ID " << ID << " tidak terdaftar." << endl;
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cout << endl;
                                }else{
                                    SetConsoleTextAttribute(hConsole, 14);
                                    cout << "   Apakah anda yakin ingin menghapus karyawan dengan ID " << ID << " dari list Karyawan? (ketik Ya/Tidak): ";
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cin >> answer;
                                    if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                        delete_Karyawan_Tertentu(LK, K, ID);
                                        SetConsoleTextAttribute(hConsole, 10);
                                        cout << "   Karyawan dengan ID " << ID << " telah terhapus dari list Karyawan.";
                                        SetConsoleTextAttribute(hConsole, 07);
                                        cout << endl;
                                        SetConsoleTextAttribute(hConsole, 14);
                                        cout << "   Apakah anda ingin menampilkan semua data list Karyawan? (ketik Ya/Tidak): ";
                                        SetConsoleTextAttribute(hConsole, 07);
                                        cin >> answer;
                                        if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                            cout << endl;
                                            show_All_Data_Karyawan(LK);
                                            cout << endl;
                                        }
                                    }else{
                                        cout << "   Anda akan dikembalikan ke menu sebelumnya." << endl;
                                    }
                                }
                            }
                            break;
                        }
                        case 3:{
                            //hapus semua karyawan
                            string answer;
                            if (EmptyKaryawan(LK)){
                                cout << "   Saat ini tidak ada karyawan." << endl;
                                cout << endl;
                            }else{
                                SetConsoleTextAttribute(hConsole, 14);
                                cout << "   Apakah anda yakin ingin menghapus semua isi list Karyawan?: ";
                                SetConsoleTextAttribute(hConsole, 07);
                                cin >> answer;
                                 if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                    delete_semua_karyawan(LK);
                                    cout << "   Semua isi list Karyawan telah dihapus";
                                    cout << endl;
                                    cout << "   Apakah anda ingin menampilkan semua data list Karyawan? (ketik Ya/Tidak): ";
                                    cin >> answer;
                                    if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                        cout << endl;
                                        show_All_Data_Karyawan(LK);
                                        cout << endl;
                                    }
                                }else{
                                    cout << "   Anda akan dikembalikan ke menu sebelumnya." << endl;
                                }
                            }
                            break;
                        }
                    }
                }
            }else if (pilihan == 2){
                int pilihan = 1;
                while (pilihan > 0 && pilihan < 4){
                    menuProject();
                    cout << "   Masukkan menu yang ingin dipilih (1/2/3/4): ";
                    cin >> pilihan;
                    while (cin.fail()){
                        notInt();
                        SetConsoleTextAttribute(hConsole, 04);
                        cout << "   Pilihan harus berupa integer!" << endl;
                        SetConsoleTextAttribute(hConsole, 07);
                        cout << "   Masukkan menu yang ingin dipilih (1/2/3/4): ";
                        cin >> pilihan;
                    }
                    cout << endl;
                    switch (pilihan){
                        case 1: {
                            //input project
                            int jumlah;
                            infoTypeProject x;
                            string answer;
                            SetConsoleTextAttribute(hConsole, 14);
                            cout << "   Berapa data project yang ingin anda masukkan?: ";
                            SetConsoleTextAttribute(hConsole, 07);
                            cin >> jumlah;
                            while (cin.fail()){
                                notInt();
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Jumlah harus berupa integer!" << endl;
                                SetConsoleTextAttribute(hConsole, 14);
                                cout << "   Berapa data project yang ingin anda masukkan?: ";
                                SetConsoleTextAttribute(hConsole, 07);
                                cin >> jumlah;
                            }
                            for(int i = 1; i <= jumlah; i++){
                                cout << "   Masukkan ID Project (String): ";
                                cin >> x.project_ID;
                                adrProject cek = findProject(LP, x.project_ID);
                                while (cek != NULL){
                                    cout << "   ID yang dimasukkan telah digunakan." << endl;
                                    cout << "   Silahkan masukkan ID Projek yang lain: ";
                                    cin >> x.project_ID;
                                    cek = findProject(LP, x.project_ID);
                                    cout << endl;
                                }
                                cout << "   Masukkan nama Project: ";
                                cin >> x.project_name;
                                cout << "   Masukkan tanggal anda memulai Project ini (string): ";
                                cin >> x.startDate;
                                x.status = "pending";
                                x.finishDate = "-";
                                cout << endl;
                                P = createElementProject(x);
                                insertFirstProject(LP, P);
                            }
                            SetConsoleTextAttribute(hConsole, 10);
                            cout << "   Data sudah berhasil dimasukkan ke dalam list Project!" << endl;
                            SetConsoleTextAttribute(hConsole, 07);
                            cout << "   Apakah anda ingin menampilkan semua data list Project? (ketik Ya/Tidak): ";
                            cin >> answer;
                            if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                cout << endl;
                                showAllProject(LP);
                                cout << endl;
                            }
                            break;
                        }
                        case 2:{
                            //hapus project tertentu
                            string IDHapus;
                            string answer;
                            if (EmptyProject(LP)){
                                cout << "   Saat ini tidak ada project." << endl;
                                cout << endl;
                            }else{
                                SetConsoleTextAttribute(hConsole, 14);
                                cout << "   Masukkan ID Project yang akan anda hapus: ";
                                SetConsoleTextAttribute(hConsole, 07);
                                cin >> IDHapus;
                                P = findProject (LP, IDHapus);
                                if (P == NULL){
                                    SetConsoleTextAttribute(hConsole, 04);
                                    cout << "   Project dengan ID " << IDHapus << " tidak terdaftar!";
                                    SetConsoleTextAttribute(hConsole, 07);
                                }else{
                                    deleteProjectTertentu(LK, LP, P, IDHapus);
                                    SetConsoleTextAttribute(hConsole, 10);
                                    cout << "   Project dengan ID " << IDHapus << " telah dihapus" << endl;
                                    SetConsoleTextAttribute(hConsole, 04);
                                }
                                cout << "   Apakah anda ingin menampilkan semua data list Project? (ketik Ya/Tidak): ";
                                cin >> answer;
                                if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                    cout << endl;
                                    showAllProject(LP);
                                    cout << endl;
                                }
                            }
                            break;
                        }
                        case 3:{
                            string ID;
                            int choose;
                            //edit status
                            string answer;
                            cout << "   Masukkan ID Project yang akan diubah statusnya (string): ";
                            cin >> ID;
                            P = findProject(LP, ID);
                            if (P == NULL){
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Project dengan ID " << ID << " tidak terdaftar." << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else{
                                cout << "   Pilih status yang akan anda ubah di project: 0" << endl;
                                cout << "   1. Active " << endl;
                                cout << "   2. Pending " << endl;
                                cout << "   3. Finished " << endl;
                                cin >> choose;
                                switch(choose){
                                    case 1:{
                                        editStatus(LP, P, ID, "Active");
                                        break;
                                    }
                                    case 2:{
                                        editStatus(LP, P, ID, "Pending");
                                        break;
                                    }
                                    case 3:{
                                        string finish;
                                        editStatus(LP, P, ID, "Finished");
                                        cout << "   Masukkan tanggal anda menyelesaikan Project ini (string): ";
                                        cin >> finish;
                                        infoProject(P).finishDate = finish;
                                        break;
                                    }
                                }
                                SetConsoleTextAttribute(hConsole, 10);
                                cout << "   Status telah diubah." << endl;
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Apakah anda ingin menampilkan semua data list Project? (ketik Ya/Tidak): ";
                                cin >> answer;
                                if (answer == "YA" || answer == "Ya" || answer == "ya" || answer == "yA"){
                                    cout << endl;
                                    showAllProject(LP);
                                    cout << endl;
                                }
                            }
                            break;
                        }
                    }
                }
            }else if (pilihan == 3){
                int pilihan = 1;
                while (pilihan > 0 && pilihan < 7){
                    menuTampilData();
                    cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5/6/7): ";
                    cin >> pilihan;
                    while (cin.fail()){
                        notInt();
                        SetConsoleTextAttribute(hConsole, 04);
                        cout << "   Pilihan harus berupa integer!" << endl;
                        SetConsoleTextAttribute(hConsole, 07);
                        cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5/6/7): ";
                        cin >> pilihan;
                    }
                    cout << endl;
                    switch (pilihan){
                        case 1:{
                            show_All_Data_Karyawan(LK);
                            cout << endl;
                            break;
                        }
                        case 2:{
                            show_All_Data_Karyawan_With_Project(LK, LP);
                            cout << endl;
                            break;
                        }
                        case 3:{
                            if (EmptyProject(LP)){
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada project. Anda tidak dapat menemukan relasi apapun." <<endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else if (EmptyKaryawan(LK)){
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada karyawan. Anda tidak dapat menemukan relasi apapun." <<endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else{
                                infoTypeProject x;
                                cout << "   Masukkan ID Project yang ingin dicari relasinya: ";
                                cin >> x.project_ID;
                                show_Data_Karyawan_Dengan_Project_Tertentu(LK, LP, x.project_ID);
                                cout << endl;
                            }
                            break;
                        }
                        case 4:{
                            showAllProject(LP);
                            cout << endl;
                            break;
                        }
                        case 5:{
                            showProjectWithKaryawan(LK, LP);
                            cout << endl;
                            break;
                        }
                        case 6:{
                            if (EmptyKaryawan(LK)){
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada karyawan. Anda tidak dapat menemukan relasi apapun." <<endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else if (EmptyProject(LP)){
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada karyawan. Anda tidak dapat menemukan relasi apapun." <<endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else{
                                infoTypeKaryawan x;
                                cout << "   Masukkan ID Karyawan yang ingin dicari relasinya: ";
                                cin >> x.ID_karyawan;
                                while (cin.fail()){
                                    notInt();
                                    SetConsoleTextAttribute(hConsole, 04);
                                    cout << "   ID karyawan berupa integer!" << endl;
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cout << "   Masukkan ID Karyawan yang ingin dicari relasinya: ";
                                    cin >> x.ID_karyawan;
                                }
                                showProjectFromKaryawan(LK, LP, x.ID_karyawan);
                                cout << endl;
                            }
                            break;
                        }
                    }
                }
            }else if (pilihan == 4){
                int pilihan = 1;
                while (pilihan > 0 && pilihan < 7){
                    menuRelasi();
                    cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5/6/7): ";
                    cin >> pilihan;
                    while (cin.fail()){
                        notInt();
                        SetConsoleTextAttribute(hConsole, 04);
                        cout << "   Pilihan harus berupa integer!" << endl;
                        SetConsoleTextAttribute(hConsole, 07);
                        cout << "   Masukkan menu yang ingin dipilih (1/2/3/4/5/6/7): ";
                        cin >> pilihan;
                    }
                    cout << endl;
                    switch (pilihan){
                        case 1:{
                            int IDKaryawan;
                            string IDProject;
                            string answer;
                            cout << "   Masukkan ID Karyawan yang ingin disambung relasinya: ";
                            cin >> IDKaryawan;
                            while (cin.fail()){
                                notInt();
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   ID karyawan berupa integer!" << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << "   Masukkan ID Karyawan yang ingin disambung relasinya: ";
                                cin >> IDKaryawan;
                            }
                            cout << "   Masukkan ID Project yang ingin disambung relasinya: ";
                            cin >> IDProject;
                            if (!EmptyKaryawan(LK) && !EmptyProject(LP)){
                                assign_Project_To_Karyawan(LK, LP, IDKaryawan, IDProject);
                                if (!isRelasi(LK, LP, IDKaryawan, IDProject)){
                                    SetConsoleTextAttribute(hConsole, 10);
                                    cout << "   Relasi antara karyawan ber ID " << IDKaryawan << " telah berhasil ditambahkan dengan project ber ID " << IDProject << endl;
                                    SetConsoleTextAttribute(hConsole, 7);
                                }
                            }else{
                                cout << "   Saat ini tidak ada karyawan ataupun project." << endl;
                                cout << endl;
                            }
                            break;
                        }
                        case 2 :{
                            int IDKaryawan;
                            string IDProject;
                            adrRelasi R;
                            cout << "   Masukkan ID Karyawan yang ingin diputus relasinya: ";
                            cin >> IDKaryawan;
                            while (cin.fail()){
                                notInt();
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   ID karyawan berupa integer!" << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << "   Masukkan ID Karyawan yang ingin diputus relasinya: ";
                                cin >> IDKaryawan;
                            }
                            cout << "   Masukkan ID Project yang ingin diputus relasinya: ";
                            cin >> IDProject;
                            if (!EmptyKaryawan(LK) && !EmptyProject(LP)){
                                delete_Project_From_Karyawan(LK, LP, IDKaryawan, IDProject);
                            }else{
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada karyawan ataupun project." << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << endl;
                            }
                            break;
                        }
                        case 3: {
                            jumlah_Relasi(LK);
                            cout << endl;
                            break;
                        }
                        case 4: {
                            int IDKaryawan;
                            string IDProject;
                            string IDbaru;
                            cout << "   Masukkan ID Karyawan yang ingin disunting relasinya: ";
                            cin >> IDKaryawan;
                            while (cin.fail()){
                                notInt();
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   ID karyawan berupa integer!" << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << "   Masukkan ID Karyawan yang ingin disunting relasinya: ";
                                cin >> IDKaryawan;
                            }
                            cout << "   Masukkan ID Project yang ingin disunting relasinya: ";
                            cin >> IDProject;
                            cout << "   Masukkan ID Project baru yang ingin disambungkan: ";
                            cin >> IDbaru;
                            if (!EmptyKaryawan(LK) && !EmptyProject(LP)){
                                edit_Relasi(LK, LP, IDKaryawan, IDProject, IDbaru);
                            }else{
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   Saat ini tidak ada karyawan ataupun project." << endl;
                                SetConsoleTextAttribute(hConsole, 7);
                                cout << endl;
                            }
                            break;
                        }
                        case 5:{
                            //total relasi project
                            string ID;
                            cout << "   Masukkan ID Projek yang akan anda hitung relasinya: ";
                            cin >> ID;
                            int show = countProjectRelation(LP, LK, ID);
                            adrProject cek = findProject(LP, ID);
                            if (cek !=  NULL){
                                if (show > 0){
                                    cout << "   Terdapat " << show << " karyawan yang sedang mengerjakan projek dengan ID " << ID << "." <<endl;
                                    cout << endl;
                                }else{
                                    SetConsoleTextAttribute(hConsole, 04);
                                    cout << "   Tidak ada Karyawan yang sedang mengerjakan projek dengan ID " << ID << "." << endl;
                                    SetConsoleTextAttribute(hConsole, 07);
                                    cout << endl;
                                }
                            }else{
                                SetConsoleTextAttribute(hConsole, 04);
                                cout << "   ID tidak ditemukan di list project." << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                                cout << endl;
                            }
                            break;
                        }
                        case 6:{
                            //total karyawan nganggur
                            int slacking = countKaryawanNganggur(LK);
                            if (EmptyKaryawan(LK)){
                                SetConsoleTextAttribute(hConsole, 14);
                                cout << "   Tidak ada karyawan untuk saat ini." << endl;
                                SetConsoleTextAttribute(hConsole, 07);
                            }else{
                                cout << "   Terdapat " << slacking << " karyawan yang sedang menganggur." << endl;
                            }
                        }
                    }
                }
            }
        }
        if (pilihan <= 0 || pilihan > 5){
            SetConsoleTextAttribute(hConsole, 04);
            cout << "   Inputan dianggap anomali berbahaya. Anda akan kami keluarkan secara paksa! " << endl;
            SetConsoleTextAttribute(hConsole, 07);
            cout << endl;
        }else{
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "|              Terima kasih telah menggunakan layanan kami              |" << endl;
            cout << "|                      Sampai jumpa di lain waktu!                      |" << endl;
            cout << "+-----------------------------------------------------------------------+" << endl;
        }
    }
    return 0;
}

