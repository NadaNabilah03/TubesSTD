#include <limits> // Untuk numeric_limits
#include "tubes.h"

//SECTION INI PUNYA JIAN
/*1*/void create_List_Karyawan(ListKaryawan &K){
    firstKaryawan(K) = NULL;
    lastKaryawan(K) = NULL;
}

/*2*/adrKaryawan create_Element_Karyawan(infoTypeKaryawan X){
    adrKaryawan K = new karyawan;
    infoKaryawan(K) = X;
    nextKaryawan(K) = NULL;
    prevKaryawan(K) = NULL;
    firstRelasi(K) = NULL;
    return K;
}

/*3*/adrRelasi create_Element_Relasi(ListProject LP, string IDproject){
    adrRelasi R = new relasi;
    adrProject P = findProject(LP, IDproject);
    nextRelasi(R) = NULL;
    relasiProject(R) = P;
    if (infoProject(P).status == "Pending"){
        editStatus(LP, P, IDproject, "Active");
    }
    return R;
}

/*4*/bool EmptyKaryawan(ListKaryawan LK){
    if (firstKaryawan(LK) == NULL && lastKaryawan(LK) == NULL){
        return true;
    }
    return false;
}

/*5*/adrKaryawan find_Karyawan(ListKaryawan LK, int IDkaryawan) {
    adrKaryawan tempDepan = firstKaryawan(LK);
    adrKaryawan tempBelakang = lastKaryawan(LK);

    while (tempDepan != tempBelakang) {
        if (infoKaryawan(tempDepan).ID_karyawan == IDkaryawan ||
            infoKaryawan(tempBelakang).ID_karyawan == IDkaryawan) {
            break;
        }
        tempDepan = nextKaryawan(tempDepan);
        tempBelakang = prevKaryawan(tempBelakang);
    }

    if (infoKaryawan(tempDepan).ID_karyawan == IDkaryawan) {
        return tempDepan;
    } else if (infoKaryawan(tempBelakang).ID_karyawan == IDkaryawan) {
        return tempBelakang;
    }
    return NULL;
}

/*6*/void insert_Last_Karyawan(ListKaryawan &LK, adrKaryawan K){
    if (EmptyKaryawan(LK)){
        firstKaryawan(LK) = K;
        lastKaryawan(LK) = K;
    }else{
        adrKaryawan temp = lastKaryawan(LK);
        nextKaryawan(temp) = K;
        prevKaryawan(K) = temp;
        lastKaryawan(LK) = K;
    }
}

/*7*/void delete_First_Karyawan(ListKaryawan &LK, adrKaryawan &K){
    K = firstKaryawan(LK);
    if (firstKaryawan(LK) == lastKaryawan(LK)){
        firstKaryawan(LK) = NULL;
        lastKaryawan(LK) = NULL;
    }else{
        firstKaryawan(LK) = nextKaryawan(K);
        prevKaryawan(firstKaryawan(LK)) = NULL;
        nextKaryawan(K) = NULL;
    }

}

/*8*/void delete_After_Karyawan(ListKaryawan &LK, adrKaryawan &K){
    adrKaryawan Prec = prevKaryawan(K);
    nextKaryawan(Prec) = nextKaryawan(K);
    prevKaryawan(nextKaryawan(K)) = Prec;
    prevKaryawan(K) = NULL;
    nextKaryawan(K) = NULL;
}

/*9*/void delete_Last_Karyawan(ListKaryawan &LK, adrKaryawan &K){
    K = lastKaryawan(LK);
    lastKaryawan(LK) = prevKaryawan(K);
    nextKaryawan(lastKaryawan(LK)) = NULL;
    prevKaryawan(K) = NULL;
}


/*10*/void delete_Karyawan_Tertentu(ListKaryawan &LK, adrKaryawan &K, int IDkaryawan){
    K = find_Karyawan(LK, IDkaryawan);
    if (EmptyKaryawan(LK)){
        cout << "   Saat ini tidak ada karyawan. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }else if ((firstKaryawan(LK) == lastKaryawan(LK))){
        if (K != NULL){
            delete_semua_Relasi(LK, K);
            delete_Satu_Elemen(LK, K);
        }
    }else{
        if (K != NULL){
            delete_semua_Relasi(LK, K);
            if (K == firstKaryawan(LK)){
                delete_First_Karyawan(LK, K);
            }else if (K == lastKaryawan(LK)){
                delete_Last_Karyawan(LK, K);
            }else{
                delete_After_Karyawan(LK, K);
            }
        }
    }
}

/*11*/void delete_Satu_Elemen(ListKaryawan &LK, adrKaryawan &K){
    K = firstKaryawan(LK);
    firstKaryawan(LK) = NULL;
    lastKaryawan(LK) = NULL;
}

/*12*/void assign_Project_To_Karyawan(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject){
    adrKaryawan K = find_Karyawan(LK, IDkaryawan);
    if (K != NULL){
        adrProject P = findProject(LP, IDproject);
        if (P != NULL){
            if (!isRelasi(LK, LP, IDkaryawan, IDproject)){
                adrRelasi R;
                R = create_Element_Relasi(LP, IDproject);
                adrRelasi firstElm = firstRelasi(K);
                if(firstRelasi(K) == NULL){
                    firstRelasi(K) = R;
                }else{
                    while(nextRelasi(firstElm) != NULL){
                        firstElm = nextRelasi(firstElm);
                    }
                    nextRelasi(firstElm)=R;
                }
            }else{
                cout << "   Karyawan dengan ID " << IDkaryawan << " sudah memiliki relasi dengan Project dengan ID " << IDproject << "." << endl;
            }
        }else{
            cout << "   Project dengan ID " << IDproject << " tidak terdaftar. Anda akan dikembalikan ke menu sebelumnya." << endl;
        }
    }else{
        cout << "   Karyawan dengan ID" << IDkaryawan << " tidak terdaftar. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }
}

/*13*/void delete_Project_From_Karyawan(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject){
    if (isRelasi(LK, LP, IDkaryawan, IDproject)) {
        adrKaryawan K = find_Karyawan(LK, IDkaryawan);
        if (K != NULL) {
            adrRelasi hapus = firstRelasi(K);
            adrRelasi prec = NULL;
            while (hapus != NULL) {
                if (infoProject(relasiProject(hapus)).project_ID == IDproject) {
                    adrProject p = relasiProject(hapus);
                    if (p != NULL) {
                        infoProject(p).status = "pending";
                    }
                    if (prec == NULL) {
                        firstRelasi(K) = nextRelasi(hapus);
                    } else {
                        nextRelasi(prec) = nextRelasi(hapus);
                    }
                    delete hapus;
                    cout << "   Relasi antara karyawan dengan ID " << IDkaryawan << " dan project dengan ID " << IDproject << " telah berhasil dihapus." << endl;
                    return;
                }
                prec = hapus;
                hapus = nextRelasi(hapus);
            }
        }
    } else {
        cout << "   Karyawan dengan ID " << IDkaryawan << " tidak memiliki relasi dengan project dengan ID " << IDproject << "." << endl;
    }
}



/*14*/void show_All_Data_Karyawan(ListKaryawan LK){
    if (EmptyKaryawan(LK)){
        cout << "   Saat ini tidak ada karyawan. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }else{
        adrKaryawan K = firstKaryawan(LK);
        while (K != NULL){
            cout << "   Nama Karyawan      : " << infoKaryawan(K).nama_karyawan << endl;
            cout << "   ID Karyawan        : " << infoKaryawan(K).ID_karyawan << endl;
            cout << "   Jabatan Karyawan   : " << infoKaryawan(K).jabatan << endl;
            cout << "   Departemen Karyawan: " << infoKaryawan(K).department << endl;
            cout << "   Gaji Karyawan      : " << infoKaryawan(K).gaji << endl;
            cout << "   ID Project yang diikuti: ";
            adrRelasi R = firstRelasi(K);
            if (R != NULL){
                while (R != NULL){
                    cout << "- " << infoProject(relasiProject(R)).project_ID << " " << endl;
                    R = nextRelasi(R);
                }
            }else{
                cout << "-" << endl;
            }
            cout << endl;
            K = nextKaryawan(K);
        }
    }
}

/*15*/void show_All_Data_Karyawan_With_Project(ListKaryawan LK, ListProject LP){
    if (EmptyKaryawan(LK)){
        cout << "   Saat ini tidak ada karyawan. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }else{
        adrKaryawan K = firstKaryawan(LK);
        while (K != NULL){
            cout << "   Nama Karyawan      : " << infoKaryawan(K).nama_karyawan << endl;
            cout << "   ID Karyawan        : " << infoKaryawan(K).ID_karyawan << endl;
            cout << "   Jabatan Karyawan   : " << infoKaryawan(K).jabatan << endl;
            cout << "   Departemen Karyawan: " << infoKaryawan(K).department << endl;
            cout << "   Gaji Karyawan      : " << infoKaryawan(K).gaji << endl;
            adrRelasi R = firstRelasi(K);
            cout << "   Project yang diikuti: ";
            if (R != NULL){
                cout << endl;
                cout << endl;
                cout << "=====================================" << endl;
                while (R != NULL){
                    showOneProject(LP, relasiProject(R));
                    R = nextRelasi(R);
                }
                cout << "=====================================" << endl;
            }else{
                cout << "-" << endl;
            }
            cout << endl;
            K = nextKaryawan(K);
        }
    }
}


/*16*/void show_Data_Karyawan_Dengan_Project_Tertentu(ListKaryawan LK, ListProject LP, string IDproject){
    adrProject P = findProject(LP, IDproject);
    if (P != NULL){
        adrKaryawan K = firstKaryawan(LK);
        while (K != NULL){
            adrRelasi R = firstRelasi(K);
            while (R != NULL){
                if (infoProject(relasiProject(R)).project_ID == IDproject){
                    cout << "   Nama Karyawan      : " << infoKaryawan(K).nama_karyawan << endl;
                    cout << "   ID Karyawan        : " << infoKaryawan(K).ID_karyawan << endl;
                    cout << "   Jabatan Karyawan   : " << infoKaryawan(K).jabatan << endl;
                    cout << "   Departemen Karyawan: " << infoKaryawan(K).department << endl;
                    cout << "   Gaji Karyawan      : " << infoKaryawan(K).gaji << endl;
                    cout << endl;
                }
                R = nextRelasi(R);
            }
            K = nextKaryawan(K);
        }
    }else{
        cout << "   Project dengan ID " << IDproject << " tidak terdaftar. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }
}

/*17*/void jumlah_Relasi(ListKaryawan LK){
    adrKaryawan K = firstKaryawan(LK);
    int totalkeseluruhan = 0;
    if (K == NULL){
        cout << "   Saat ini tidak ada karyawan. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }else{
        while (K != NULL){
            int jumlah = 0;
            adrRelasi R = firstRelasi(K);
            while (R != NULL){
                jumlah++;
                totalkeseluruhan++;
                R = nextRelasi(R);
            }
            cout << "   Jumlah relasi dari karyawan dengan ID " << infoKaryawan(K).ID_karyawan << " sejumlah " << jumlah << " relasi." << endl;
            K = nextKaryawan(K);
        }
        cout << "   Jumlah total seluruh relasi yang dimiliki pada database ini sebesar " << totalkeseluruhan << " relasi."<< endl;
    }
}

/*18*/void edit_Relasi(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject, string IDbaru) {
    adrKaryawan K = find_Karyawan(LK, IDkaryawan);
    if (K != NULL) {
        adrProject P = findProject(LP, IDproject);
        if (P != NULL) {
            adrRelasi R = findRelasi(LK, LP, IDkaryawan, IDproject);
            if (R != NULL) {
                adrProject baru = findProject(LP, IDbaru);
                if (baru != NULL) {
                    relasiProject(R) = baru;
                    cout << "   Relasi antara karyawan dengan ID " << IDkaryawan << " dan project dengan ID " << IDproject << " telah berhasil diubah" << "." << endl;
                    cout << "   Relasi karyawan dengan ID " << IDkaryawan << " kini terhubung dengan project dengan ID " << IDbaru << "." << endl;
                } else {
                    cout << "   Project dengan ID baru tidak terdaftar." << endl;
                }
            } else {
                cout << "   Karyawan dengan ID " << IDkaryawan << " tidak memiliki relasi apapun dengan project dengan ID " << IDproject << "." << endl;
                cout << "   Anda akan dikembalikan ke menu sebelumnya." << endl;
            }
        } else {
            cout << "   Project dengan ID " << IDproject << " tidak terdaftar. Anda akan dikembalikan ke menu sebelumnya." << endl;
        }
    } else {
        cout << "   Karyawan dengan ID " << IDkaryawan
             << " tidak terdaftar. Anda akan dikembalikan ke menu sebelumnya." << endl;
    }
}


/*19*/void delete_semua_Relasi(ListKaryawan &LK, adrKaryawan K){
    adrRelasi R = firstRelasi(K);
    adrRelasi hapus;
    while (R != NULL){
        hapus = R;
        R = nextRelasi(R);
        nextRelasi(hapus) = NULL;
    }
}

/*20*/void delete_semua_karyawan(ListKaryawan &LK){
    adrKaryawan K = firstKaryawan(LK);
    if (K == NULL){
        cout << "   Saat ini tidak ada karyawan." << endl;
    }else{
        while (K != NULL){
            adrKaryawan del = K;
            K = nextKaryawan(K);
            delete_semua_Relasi(LK, del);
            delete_First_Karyawan(LK, del);
        }
        cout << "   Semua karyawan dalam list Karyawan telah dihapus." << endl;
    }
}

/*21*/bool isRelasi(ListKaryawan LK, ListProject LP, int IDKaryawan, string IDproject){
    adrKaryawan K = find_Karyawan(LK, IDKaryawan);
    adrRelasi R = firstRelasi(K);
    if (K != NULL){
        while (R != NULL){
            if (infoProject(relasiProject(R)).project_ID == IDproject){
                return true;
            }
            R = nextRelasi(R);
        }
    }
    return false;
}


//tambahan procedure

void show_One_Karyawan(ListKaryawan LK, adrKaryawan K){
    if (K != NULL){
        cout << "   Nama Karyawan      : " << infoKaryawan(K).nama_karyawan << endl;
        cout << "   ID Karyawan        : " << infoKaryawan(K).ID_karyawan << endl;
        cout << "   Jabatan Karyawan   : " << infoKaryawan(K).jabatan << endl;
        cout << "   Departemen Karyawan: " << infoKaryawan(K).department << endl;
        cout << "   Gaji Karyawan      : " << infoKaryawan(K).gaji << endl;
        cout << endl;
    }else{
        cout << "   Data tidak ditemukan." << endl;
        cout << endl;
    }
}


//SECTION INI PUNYA CaramelXD
void createListProject(ListProject &P){
    firstProject(P) = NULL;
}

adrProject createElementProject(infoTypeProject X){
    adrProject P = new project;
    infoProject(P) = X;
    nextProject(P) = NULL;
    return P;
}

bool EmptyProject(ListProject LP){
    if (firstProject(LP) == NULL){
        return true;
    }
    return false;
}

void insertFirstProject(ListProject &LP, adrProject P){
    if (EmptyProject(LP)){
        firstProject(LP) = P;
    }else{
        nextProject(P) = firstProject(LP);
        firstProject(LP) = P;
    }
}

adrProject findProject(ListProject LP, string ID){
    adrProject P = firstProject(LP);
    while (P != NULL){
        if (ID == infoProject(P).project_ID){
            return P;
        }
        P = nextProject(P);
    }
    return NULL;
}

void deleteLastProject(ListKaryawan LK, ListProject &LP, adrProject &P) {
    if (firstProject(LP) != NULL) {
        adrProject last = firstProject(LP);

        while (nextProject(last) != NULL) {
            last = nextProject(last);
        }
        deleteProjectRelation(LK, LP, infoProject(last).project_ID);
    }

    if (firstProject(LP) == NULL) {
        cout << "   Saat ini tidak ada project." << endl;
        P = NULL;
    } else if (nextProject(firstProject(LP)) == NULL) {
        P = firstProject(LP);
        firstProject(LP) = NULL;
    } else {
        adrProject prev = NULL;
        adrProject last = firstProject(LP);
        while (nextProject(last) != NULL) {
            prev = last;
            last = nextProject(last);
        }
        P = last;
        nextProject(prev) = NULL;
    }
}

void showAllProject(ListProject LP){
    adrProject show = firstProject(LP);
    if (show == NULL){
        cout << "   Saat ini tidak ada project." << endl;
    }else{
        while(show != NULL){
        cout << "   ID Project     : " << infoProject(show).project_ID << endl;
        cout << "   Nama Project   : " << infoProject(show).project_name << endl;
        cout << "   Status         : " << infoProject(show).status << endl;
        cout << "   Tanggal dimulai: " << infoProject(show).startDate << endl;
        cout << "   Tanggal selesai: " << infoProject(show).finishDate << endl;
        cout << endl;
        show = nextProject(show);
    }
    }
}

void showOneProject(ListProject LP, adrProject P){
    if (P == NULL){
        cout << "   Data tidak ditemukan." << endl;
        cout << endl;
    }else{
        cout << "   ID Project     : " << infoProject(P).project_ID << endl;
        cout << "   Nama Project   : " << infoProject(P).project_name << endl;
        cout << "   Status         : " << infoProject(P).status << endl;
        cout << "   Tanggal dimulai: " << infoProject(P).startDate << endl;
        cout << "   Tanggal selesai: " << infoProject(P).finishDate << endl;
        cout << endl;
    }
}

adrRelasi findRelasi(ListKaryawan LK, ListProject LP, int IDKaryawan, string IDproject) {
    adrKaryawan K = firstKaryawan(LK);
    while (K != NULL) {
        adrRelasi R = firstRelasi(K);
        while (R != NULL) {
            if (infoProject(relasiProject(R)).project_ID == IDproject) {
                return R;
            }
            R = nextRelasi(R);
        }
        K = nextKaryawan(K);
    }
    return NULL;
}

void showProjectFromKaryawan(ListKaryawan LK, ListProject LP, int IDkaryawan){
    adrKaryawan K = find_Karyawan(LK, IDkaryawan);
    if (K == NULL){
        cout << "   Karyawan dengan ID " << IDkaryawan << " tidak ditemukan." << endl;
    }else{
        adrRelasi R = firstRelasi(K);
        if (firstRelasi(K) == NULL){
            cout << "   Karyawan dengan ID " << IDkaryawan << " sedang menganggur." << endl;
        }
        while (R != NULL){
            adrProject show = relasiProject(R);
            showOneProject(LP, show);
            R = nextRelasi(R);
        }
    }
}

void showProjectWithKaryawan(ListKaryawan LK, ListProject LP){
    adrKaryawan K = firstKaryawan(LK);
    adrProject P = firstProject(LP);
    if (EmptyProject(LP)){
        cout << "   Saat ini tidak ada karyawan project." << endl;
    }else{
        while (P != NULL){
        showOneProject(LP, P);
        while (K != NULL){
            adrRelasi R = firstRelasi(K);
            while(R != NULL){
                if (infoProject(relasiProject(R)).project_ID == infoProject(P).project_ID){
                    show_One_Karyawan(LK, K);
                }
                R = nextRelasi(R);
            }
            K = nextKaryawan(K);
        }
        P = nextProject(P);
    }
    }
}

int countProjectRelation(ListProject LP, ListKaryawan LK, string IDProject){
    int relation = 0;
    adrKaryawan K = firstKaryawan(LK);
    while (K != NULL){
        adrRelasi R = firstRelasi(K);
        while(R != NULL){
            if (infoProject(relasiProject(R)).project_ID == IDProject){
                relation++;
            }
            R = nextRelasi(R);
        }
        K = nextKaryawan(K);
    }
    return relation;
}

int countKaryawanNganggur(ListKaryawan LK){
    //menghitung semua karyawan yang tidak mengerjakan projek apapun
    int slacker = 0;
    adrKaryawan K = firstKaryawan(LK);
    while (K != NULL){
        if (firstRelasi(K) == NULL){
            slacker++;
        }
        K = nextKaryawan(K);
    }
    return slacker;
}

void deleteProjectRelation(ListKaryawan &LK, ListProject &LP, string ID) {
    //menghapus semua relasi dari projek tertentu
    adrKaryawan K = firstKaryawan(LK);

    while (K != NULL) {
        adrRelasi R = firstRelasi(K);
        adrRelasi prec = NULL;

        while (R != NULL) {
            if (relasiProject(R) != NULL && infoProject(relasiProject(R)).project_ID == ID) {
                if (prec == NULL) {
                    firstRelasi(K) = nextRelasi(R);
                } else {
                    nextRelasi(prec) = nextRelasi(R);
                }

                adrRelasi hapus = R;
                R = nextRelasi(R);
                delete hapus;
                cout << "   Relasi proyek dengan ID " << ID << " berhasil dihapus dari karyawan dengan ID " << infoKaryawan(K).ID_karyawan << "." << endl;
            } else {
                prec = R;
                R = nextRelasi(R);
            }
        }

        K = nextKaryawan(K);
    }
}

void editStatus(ListProject &LP, adrProject &P, string iDProject, string newStatus ){
    //mengedit status projek
    P = findProject(LP, iDProject);
    infoProject(P).status = newStatus;
}

void deleteProjectTertentu(ListKaryawan LK, ListProject &LP, adrProject &P, string IDProject) {
    //menghapus projek tertentu
    P = findProject(LP, IDProject);
    adrProject prec = firstProject(LP);
    deleteProjectRelation(LK, LP, IDProject);
    if (P == NULL){
        cout << "   ID tidak terdaftar." << endl;
        cout << endl;
    }else{
        if (EmptyProject(LP)){
            cout << "   Saat ini tidak ada project.";
        }else if (P == firstProject(LP)){
            if (nextProject(firstProject(LP)) == NULL){
                firstProject(LP) = NULL;
            }else{
                firstProject(LP) = nextProject(P);
                nextProject(P) = NULL;
            }
        }else if (nextProject(P) == NULL){
            deleteLastProject(LK, LP, P);
        }else{
            while (nextProject(prec) != P){
                prec = nextProject(prec);
            }
            nextProject(prec) = nextProject(P);
            nextProject(P) = NULL;
        }
    }
}



void menuAwal(){
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "|   Silahkan pilih menu yang tersedia dalam menggunakan layanan kami!   |" << endl;
        cout << "|                              1. Karyawan                              |" << endl;
        cout << "|                              2. Project                               |" << endl;
        cout << "|                            3. Tampil data                             |" << endl;
        cout << "|                              4. Relasi                                |" << endl;
        cout << "|                              5. Keluar                                |" << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << endl;
}

void menuKaryawan(){
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|         Silahkan pilih menu yang tersedia untuk menu Karyawan!         |" << endl;
        cout << "|                           1. Input Karyawan                            |" << endl;
        cout << "|                      2. Hapus Karyawan Tertentu                        |" << endl;
        cout << "|                        3. Hapus Semua Karyawan                         |" << endl;
        cout << "|                              4. Keluar                                 |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << endl;
}

void menuProject(){
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << "|         Silahkan pilih menu yang tersedia untuk menu Project!          |" << endl;
        cout << "|                           1. Input Project                             |" << endl;
        cout << "|                       2. Hapus Project Tertentu                        |" << endl;
        cout << "|                        3. Edit Status Project                          |" << endl;
        cout << "|                              4. Keluar                                 |" << endl;
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << endl;
}

void menuTampilData(){
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "|       Silahkan pilih menu yang tersedia untuk menu tampil data!       |" << endl;
        cout << "|                           1. Semua Karyawan                           |" << endl;
        cout << "|                      2. Karyawan dengan Project                       |" << endl;
        cout << "|                  3. Karyawan dengan Project tertentu                  |" << endl;
        cout << "|                           4. Semua Project                            |" << endl;
        cout << "|                       5. Project dengan Karyawan                      |" << endl;
        cout << "|                  6. Project dari Karyawan tertentu                    |" << endl;
        cout << "|                              7. Keluar                                |" << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << endl;
}

void menuRelasi(){
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "|         Silahkan pilih menu yang tersedia untuk menu Relasi!          |" << endl;
        cout << "|                     1. Assign Project ke Karyawan                     |" << endl;
        cout << "|                    2. Hapus Project dari Karyawan                     |" << endl;
        cout << "|                       3. Jumlah Relasi yang ada                       |" << endl;
        cout << "|                            4. Edit Relasi                             |" << endl;
        cout << "|                        5. Total Relasi Project                        |" << endl;
        cout << "|                    6. Total Karyawan yang nganggur                    |" << endl;
        cout << "|                              7. Keluar                                |" << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << endl;
}

void notInt(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
