#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

//Karyawan DLL
#define infoKaryawan(K) K->infoKaryawan
#define nextKaryawan(K) K->nextKaryawan
#define prevKaryawan(K) K->prevKaryawan
#define firstRelasi(K) K->firstRelasi

//Project SLL
#define infoProject(P) P->infoProject // yang gini" ga perlu ga sih Thir? tinggal pointer ke infotype aja ga sih?; oh iya
#define nextProject(P) P->nextProject

//Lists
#define firstProject(F) F.firstProject
#define firstKaryawan(N) N.firstKaryawan
#define lastKaryawan(N) N.lastKaryawan

//relasi
#define nextRelasi(R) R->nextRelasi
#define relasiProject(R) R->relasiProject

using namespace std;

typedef struct karyawan *adrKaryawan;
typedef struct relasi *adrRelasi;
typedef struct project *adrProject;

//Punya Jian
struct dataKaryawan{
    int ID_karyawan;
    string nama_karyawan;
    string jabatan;
    string department;
    int gaji;
}; //parent DLL cuy, pake prev; iya ini gw bingung, lu pake yang mll gw pake yg graf wkwk

typedef dataKaryawan infoTypeKaryawan;

struct karyawan{
    infoTypeKaryawan infoKaryawan;
    adrKaryawan nextKaryawan;
    adrKaryawan prevKaryawan;
    adrRelasi firstRelasi;
};

struct ListKaryawan{
    adrKaryawan firstKaryawan;
    adrKaryawan lastKaryawan;
};

struct relasi{
    adrRelasi nextRelasi;
    adrProject relasiProject;
}; //gtw ini bener ga

//Punya CaramelXD

struct dataProject{
    string project_ID;
    string project_name;
    string status;
    string startDate;
    string finishDate;
};

typedef dataProject infoTypeProject;

struct project{
    infoTypeProject infoProject; //ini buat apa Thir?; biar di parameter ga kebanyakan; oh okei
    adrProject nextProject;
};

struct ListProject{
    adrProject firstProject;
};

//prosedur PUNYA Jiaaann

/*1*/void create_List_Karyawan(ListKaryawan &K);
/*2*/adrKaryawan create_Element_Karyawan(infoTypeKaryawan X);
/*3*/adrRelasi create_Element_Relasi(ListProject LP, string IDproject);

/*4*/bool EmptyKaryawan(ListKaryawan LK);
/*5*/adrKaryawan find_Karyawan(ListKaryawan LK, int IDkaryawan);

/*6*/void insert_Last_Karyawan(ListKaryawan &LK, adrKaryawan K);
/*7*/void delete_First_Karyawan(ListKaryawan &LK, adrKaryawan &K);
/*8*/void delete_After_Karyawan(ListKaryawan &LK, adrKaryawan &K);
/*9*/void delete_Last_Karyawan(ListKaryawan &LK, adrKaryawan &K);
/*10*/void delete_Karyawan_Tertentu(ListKaryawan &LK, adrKaryawan &K, int IDkaryawan);
/*11*/void delete_Satu_Elemen(ListKaryawan &LK, adrKaryawan &K);

/*12*/void assign_Project_To_Karyawan(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject);
/*13*/void delete_Project_From_Karyawan(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject);

/*14*/void show_All_Data_Karyawan(ListKaryawan LK);
/*15*/void show_All_Data_Karyawan_With_Project(ListKaryawan LK, ListProject LP);
/*16*/void show_Data_Karyawan_Dengan_Project_Tertentu(ListKaryawan LK, ListProject LP, string IDproject);

/*17*/void jumlah_Relasi(ListKaryawan LK);
/*18*/void edit_Relasi(ListKaryawan &LK, ListProject LP, int IDkaryawan, string IDproject, string IDbaru);

/*19*/void delete_semua_Relasi(ListKaryawan &LK, adrKaryawan K);
/*20*/void delete_semua_karyawan(ListKaryawan &LK);
/*21*/bool isRelasi(ListKaryawan LK, ListProject LP, int IDKaryawan, string IDproject);

//PROSEDUR PUNYA CaramelXD
void createListProject(ListProject &LP);
adrProject createElementProject(infoTypeProject X);

bool EmptyProject(ListProject LP);

void insertFirstProject(ListProject &LP, adrProject P);//Thir lu insertfirst; oiya
void deleteLastProject(ListKaryawan LK, ListProject &LP, adrProject &P);

adrProject findProject(ListProject LP, string ID);
adrRelasi findRelasi(ListKaryawan LK, ListProject LP, int IDkaryawan, string IDproject);

void showAllProject(ListProject LP);
void showProjectFromKaryawan(ListKaryawan LK, ListProject LP, int IDkaryawan);
void showProjectWithKaryawan(ListKaryawan LK, ListProject LP);

int countProjectRelation(ListProject LP, ListKaryawan LK, string IDProject);
int countKaryawanNganggur(ListKaryawan LK);

//tambahan procedure
void showOneProject(ListProject LP, adrProject P);
void show_One_Karyawan(ListKaryawan LK, adrKaryawan K);
void deleteProjectRelation(ListKaryawan &LK, ListProject &LP, string ID);
void editStatus(ListProject &LP, adrProject &P, string iDProject, string newStatus);
void deleteProjectTertentu(ListKaryawan LK, ListProject &LP, adrProject &P, string IDProject);

// Hardcode
void inputProject(ListProject &LP);
void inputKaryawan(ListKaryawan &LK);

//THIR inget ga gmn caranya ngasih relasi?; nanti aja, kerjain yg gampang gampang dlu aja :P; apa pake yang kayak graph aja? masuk akal ga sih?; bisa
//Ini kalo parent nya dll, nyambung ke child nya juga dll atau engga Thir?; waduh gtw tuh nanti tanya aja ke MAM

//menus
void menuAwal();
void menuKaryawan();
void menuProject();
void menuTampilData();
void menuRelasi();
void notInt();

#endif // TUBES_H_INCLUDED
