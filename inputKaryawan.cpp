#include "tubes.h"

void inputKaryawan(ListKaryawan &LK){
    create_List_Karyawan(LK);
    adrKaryawan K;
    infoTypeKaryawan X;

    X.ID_karyawan = 1;
    X.nama_karyawan = "Budiono Siregar";
    X.jabatan = "Kapten";
    X.department = "Dept A";
    X.gaji = 1500000;
    K = create_Element_Karyawan(X);
    insert_Last_Karyawan(LK, K);

    X.ID_karyawan = 2;
    X.nama_karyawan = "Yuka";
    X.jabatan = "Manager";
    X.department = "Dept B";
    X.gaji = 1200000;
    K = create_Element_Karyawan(X);
    insert_Last_Karyawan(LK, K);

    X.ID_karyawan = 3;
    X.nama_karyawan = "John Singa";
    X.jabatan = "Janitor";
    X.department = "Dept C";
    X.gaji = 1000000;
    K = create_Element_Karyawan(X);
    insert_Last_Karyawan(LK, K);

    X.ID_karyawan = 4;
    X.nama_karyawan = "Kade Eugene";
    X.jabatan = "Staff";
    X.department = "Dept D";
    X.gaji = 1750000;
    K = create_Element_Karyawan(X);
    insert_Last_Karyawan(LK, K);

    X.ID_karyawan = 5;
    X.nama_karyawan = "Kenta Kirana";
    X.jabatan = "Slacker";
    X.department = "Dept F";
    X.gaji = 2000000;
    K = create_Element_Karyawan(X);
    insert_Last_Karyawan(LK, K);
}
