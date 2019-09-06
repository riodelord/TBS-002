#include <iostream>
#include <conio.h>
#define MAX 100

#include <cstdlib>
using namespace std;
struct pnjg //struct pnjg berisi variable data pengunjung yang akan diinput
{
    string namapngunjung;//variable nama pengunjung
    string jenkel;//variable jenis kelamin pengunjung
    string jenkel1;//variable jenis kelamin pengunjung
    string asalkota;//variable asal kota pengunjung
    string alamat;//variable alamat pengunjung
    int jmlAnggotaKeluarga;//variable jumlah anggota keluarga pengunjung
};

struct prv//struct prv berisi variable inputan bulan yang akan diiput sebelum inputan pengunjung
{
    string namabulan;//variable string untuk nama bulan
    int jmlKeluarga;//variable integer untuk jumlah keluarga
};
typedef pnjg pengunjung;
typedef prv bulan;
typedef struct ElmListP *adrP;//menggunakan pointer adrP
typedef struct ElmListC *adrC;//menggunakan pointer adrC

struct ElmListP //ElmListP sebagai (infoP)bantuP, nextP , prevP , headC
{
    bulan infoP;
    adrP nextP;
    adrP prevP;
    adrC firstC;
};
struct ElmListC // ElmListC sebagai nextC , bantuC
{
    pnjg infoC;
    adrC nextC;
};

struct List //List sebagai HeadP
{
    adrP firstP;
};
void createList(List &L)//void check keadaan jika akan membuat list
{
    L.firstP = NULL;
}

adrP alokasiP (bulan prv)
{
    adrP P;
    P = new ElmListP;//membuat node ElmListP baru

    P->infoP = prv;// P next menuju infoP= prv (nama bulan & jumlah keluarga)
    P->nextP = NULL;// P next menuju next P = null
    P->prevP = NULL;// P next menuju next P = null
    P->firstC = NULL;// P next menuju FirstC = null
    return P;//kembali kenilai P
}

adrC alokasiC (pengunjung pnjg)//adrC alokasiC untuk proses memasukan pengunjung kedalam linked list
{
    adrC P; //sebagai variable bantu
    P = new ElmListC;//sebagai node baru

    P->infoC = pnjg; //node kosong next infoC = inputan pengunjung
    P->nextC = NULL; //jika bantu menuju nextC = null
    return P;
}

void insertLastP (List &L, adrP P)//ini adalah proses insertbelakang dalam linked list
{


    if (L.firstP == NULL)//proses pengecheckan jika ketika list = null maka list akan memasukan nilai ke p lalu membalikan P dengan prev menuju P sendiri
    {

        L.firstP = P; // L.firstP memasukan nilai kedalam P
        P->prevP = P;//P membalik nilain menggunakan prev ke P sendiri
    }
    else//dan jika L.first tidak bernilai NULL maka akan lanjut menjalankan proses ini
    {
        adrP Q = L.firstP;//memasukan value adrP Q kedalam L.firstP
        while (Q->nextP != NULL)//proses pengecheckan jika Q menuju nextP tidak sama dengan null maka Q = Q menuju nextP
        {

            Q = Q->nextP;//Q menuju nextP
        }
        Q->nextP = P;//Q menuju nextP sama dengan P
        P->prevP = Q;//Q mundur sama dengan Q
        // berputar karena double linked list bisa prev / next
    }
}

void insertLastC (List &L, adrP P,adrC C)// proses insertbelakangC
{

    if (P->firstC == NULL)//jika P menuju firstC sama dengan NULL
    {

        P->firstC = C;//maka program akan mengisi nilai yang ada didalam C
    }
    else
    {//jika kondisi diatas tidak terpenuhi maka Q sama dengan P menuju firstC
        adrC Q; //node baru
        Q = P->firstC; //
        while (Q->nextC != NULL)//proses pengecheckan jika Q menuju nextC tidak sama dengan NULL maka Q sama saja Q menuju nextC
        {
            Q = Q->nextC;
        }
        Q->nextC = C;//ini proses jika kondisi while tidak terpenuhi
    }
}
struct stact //struct ini dibuat untuk pemrosesan stack
{
    int top,total[MAX];//variable top, dan total berisi nilai max=100
    string nama[MAX],data[MAX];//variable nama dan data berisi nilai max=100
} tumpukan;
int bantu;//variable bantu

void init()//Untuk memastikan penunjuk (top) berada pada posisi indeks ke 0 pada saat menambahkan data ke tumpukan maka disini kita perlu memberikan nilai awal yaitu -1.
{
    tumpukan.top=bantu-1;
}

bool isEmpty()//Pada fungsi isEmpty() akan mengembalikan nilai true jika nilai Tumpukan.top sama dengan -1, atau false jika tidak sama.
{
    return tumpukan.top==-1;
}

bool isFull()//Pada fungsi isFull() akan mengembalikan nilai true jika nilai Tumpukan.top sama dengan maksimum data array yang telah ditentukan dikurang satu MAX-1, atau false jika tidak sama.
{
    return tumpukan.top==MAX-1;
}

void push(string bolan)//Untuk menginputkan data ke tumpukan hal utama yang perlu kita lakukan adalah memeriksa apakah tumpukan penuh atau tidak, jika penuh, maka kita tidak dapat menambahkan data ke tumpukan karena sudah tidak ada ruang lagi yang tersedia. Jadi cukup tampilkan pesan bahwa Tumpukannya penuh.
{
    if (isFull())
    {
        cout<<"\nTumpukan Penuh\n";
    }
    else
    {
        tumpukan.top++;
        cout<<"Masukan data :";
        tumpukan.data[tumpukan.top]=bolan;
        cout<<tumpukan.data[tumpukan.top]<<endl;
    }
}
int coba=tumpukan.top;//pendeklarasian variable coba sama dengan tumpukan.top
struct urutbulan//struct menyimpan data tampung untuk sorting
{
    int tampung[MAX];
    string tmpung[MAX];
};
void printbulan()//proses menampilkan bulan ,
{
    if (isEmpty())
    {
        cout<<"Data Kosong";//Jika tidak ada data di tumpukan maka tampilkan pesan bahwa Tumpukan kosong dan data tidak dapat di tampilkan.
    }
    else
    {
        for ( int i=tumpukan.top; i>=0; i--)
        {
            cout<<tumpukan.data[i]<<endl;//Jika masih ada data maka tampilkan data satu -persatu dari tumpukan dengan menggunakan perulangan.
        }
    }
}
void insertion_sort(int arr[],string bln[], int length)//proses pensortingan data bulan inputan user
{
    int i, j,tmp;
    string tmb;
    for (i = 1; i < length; i++)
    {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            tmb = bln[j];
            arr[j] = arr[j - 1];
            bln[j] = bln[j - 1];
            arr[j - 1] = tmp;
            bln[j - 1] = tmb;
            j--;
        }//end of while loop
    }//end of for loop
}
void dataAR(int penuh)//disini logika bulan dibandingkan dengan angka agar mudah mensortingnya
{
    urutbulan urut;


    for (int i=0; i<penuh+1; i++)
    {
        urut.tmpung[i]=tumpukan.data[i];//proses perulangan inputan user

    }

    for(int i=0; i<penuh+1; i++)//lalu proses pembandingan bulan dan angka menggunakan for agar mudah tersorting
    {
        if(urut.tmpung[i]=="januari"||urut.tmpung[i]=="Januari")
            urut.tampung[i] = 1;
        if(urut.tmpung[i]=="febuari"||urut.tmpung[i]=="Febuari")
            urut.tampung[i] = 2;
        if(urut.tmpung[i]=="maret"||urut.tmpung[i]=="Maret")
            urut.tampung[i] = 3;
        if(urut.tmpung[i]=="april"||urut.tmpung[i]=="April")
            urut.tampung[i] = 4;
        if(urut.tmpung[i]=="mei"||urut.tmpung[i]=="Mei")
            urut.tampung[i] = 5;
        if(urut.tmpung[i]=="juni"||urut.tmpung[i]=="Juni")
            urut.tampung[i] = 6;
        if(urut.tmpung[i]=="juli"||urut.tmpung[i]=="Juli")
            urut.tampung[i] =7;
        if(urut.tmpung[i]=="agustus"||urut.tmpung[i]=="Agustus")
            urut.tampung[i]=8;
        if(urut.tmpung[i]=="september"||urut.tmpung[i]=="September")
            urut.tampung[i]= 9;
        if(urut.tmpung[i]=="oktober"||urut.tmpung[i]=="Oktober")
            urut.tampung[i] = 10;
        if(urut.tmpung[i]=="november"||urut.tmpung[i]=="November")
            urut.tampung[i] = 11;
        if(urut.tmpung[i]=="desember"||urut.tmpung[i]=="Desember")
            urut.tampung[i] = 12;
    }
insertion_sort(urut.tampung,urut.tmpung, tumpukan.top+1);//insertion_sort berisi parameter tampung dan tmpung serta tumpukan.tio+1
    for(int i=1; i<penuh+1; i++)
    {
        cout << urut.tmpung[i]<<endl; //proses tampil bulan yang sudah tersorting //
    }
    cout<<endl;
}
void createbulan(List &L){// proses penginputan bulan oleh user lalu masuk ke pemrosesan sorting bulan
    bulan prv;
    adrP P;
    cout << "bulan yang sudah ada : "<<endl;
    dataAR(tumpukan.top);
    cout <<endl;
    cout << "Masukan Nama Bulan : ";
    cin>>prv.namabulan;
    push(prv.namabulan);
    prv.jmlKeluarga = 0;
    P = alokasiP(prv);
    insertLastP(L, P);
    cout<<"========== Bulan berhasil ditambahkan ==========";
    getch();
}

void createpengunjung(List &L)//proses penginputan data pengunjung oleh user
{
    pengunjung pnjg;
    adrC C;
    adrP P = L.firstP;
    string bulan;
    cout << "Masukan Bulan Pengunjung: ";
    cin >> bulan;
    while (P->nextP != NULL && P->infoP.namabulan != bulan)
    {
        P = P->nextP;
    }

    if (bulan == P->infoP.namabulan)
    {
        cout << "Masukan Nama Pengunjung: ";
        cin >> pnjg.namapngunjung;
        cout << "Masukan Jenis Kelamin(P/L) : ";
        cin >> pnjg.jenkel;
        cout << "Masukan Asal Kota: ";
        cin >> pnjg.asalkota;

        C = alokasiC(pnjg);
        insertLastC(L, P, C);
        P->infoP.jmlKeluarga =  P->infoP.jmlKeluarga + 1;
        cout << "========== Data Pengunjung berhasil ditambahkan ==========";
    }
    else
    {
        cout << "========== bulan "<<bulan<<" tidak ditemukan ==========";
    }
    getch();
}

void TampilSemua (List &L)//proses menampilkan semua data yang ada di linked list , hasil inputan user yang sudah diinput
{
    adrP P = L.firstP;
    adrC C;

    while (P != NULL)
    {
        cout << "Nama bulan: " << P->infoP.namabulan << endl;
        cout << "Jumlah pengunjung: " << P->infoP.jmlKeluarga << endl;

        C = P->firstC;
        while (C != NULL)
        {
            cout << "   Nama pengunjung: " << C->infoC.namapngunjung << endl;
            cout << "   Jenis Kelamin : " << C->infoC.jenkel<< endl;
            cout << "   Asal Kota : " << C->infoC.asalkota <<endl;

            C= C->nextC;
        }
        cout << endl;
        P = P->nextP;
    }
    getch();
}

void tampilbybulan (List &L)//proses searching bulan lalu menampilkan data yang sudah ada kepada user sesuai inputan user
{
    adrC C;
    adrP P = L.firstP;
    string bulan;//variable string untuk inputan user
    cout << "Masukan Bulan: ";
    cin >> bulan;//user menginput nama bulan yang diingkan jika ada maka akan menjalankan proses searchign
    while (P->nextP != NULL && P->infoP.namabulan != bulan)
    {
        P = P->nextP;
    }
    if (P->infoP.namabulan == bulan)//jika data bulan ada didalam data maka akan menjalankan proses ini serta menampilkan data yang ada di bulan ini
    {
        cout << "Nama Bulan: " << P->infoP.namabulan<< endl;
        C = P->firstC;
        while (C != NULL)
        {
            cout << "   Nama : " << C->infoC.namapngunjung << endl;//data pengunjung yang akan muncul sesuai nama bulan inputan
            cout << "   Jenis Kelamin : " << C->infoC.jenkel<< endl;
            cout << "   Asal Kota : " << C->infoC.asalkota <<endl;
            C= C->nextC;
        }
    }//jika tidak terpenuhi maka pesan akan memunculkan data bulan tidak ada.
    else
    {
        cout << " Data bulan Tidak ada" << endl;
    }
    getch();
}
void jmldatabulan (List &L)//proses penghitungan data yang ada didalam bulan
{
    adrC C;
    adrP P = L.firstP;
    string bulan;//variable bulan yang baru khusus menghitung data bulan
    cout << "Masukan Bulan: ";
    cin >> bulan;//inputan data bulan
    while (P->nextP != NULL && P->infoP.namabulan != bulan)//jika inputan user sesuai dengan data yang sudha ada , makan akan muncul data pengunjung sesuai dengan bulan yang diinginkan
    {
        P = P->nextP;
    }
    if (P->infoP.namabulan == bulan)//jika sesuai data yang muncul adalah hasil penjumlahan data yang ada dibulan tersebut
    {
        cout << "Nama Bulan: " << P->infoP.namabulan<< endl;
        cout << "Jumlah Pengunjung: " << P->infoP.jmlKeluarga<< endl;
    }
    else//jika tidak ada , maka akan muncul pesan bulan tidak ada
    {
        cout << " Data bulan Tidak ada" << endl;
    }
    getch();
}

void caridatapengunjung(List L, string namapngunjung)//proses searching data pengunjung
{
    bool found = false;
    adrP P = L.firstP;
    adrC C;
    while (P != NULL)
    {
        C = P->firstC;
        while (C != NULL)
        {
            if (C->infoC.namapngunjung== namapngunjung)//proses pembandingan inputan user dengan data , jika sesuai maka akan tampil nama bulan , nama pengunjung,jenis kelamin, serta asal kota
            {
                cout << "Nama bulan : " << P->infoP.namabulan << endl;
                cout << "   Nama Pengunjung : " << C->infoC.namapngunjung << endl;
                cout << "   Nama Jenis Kelamin : " << C->infoC.jenkel<< endl;
                cout << "   Asal Kota : " << C->infoC.asalkota <<endl;
                found = true;
            }
            C= C->nextC;
        }
        P = P->nextP;
    }
    if (found == false)//jika inputan tidak sesuai maka data yang ditampilkan tidak ada
    {
        cout << "========== data  tidak ditemukan ==========";
    }
    getch();
}

void deletebulan(List &L)//proses mendelete bulan yang ada
{
    string namabulan;//vatiable nama bulan yang akan diinput user
    cout<<"Masukkan nama bulan yang akan di hapus : ";
    cin >> namabulan;//inputan user
    // cari bulan yang akan dihapus
    adrP p = L.firstP;
    while ((p->infoP.namabulan != namabulan)&&(p->nextP != NULL))
    {
        p = p->nextP;
    }
    // pindah child dari label yang ingin di delete
    if ((p->infoP.namabulan == namabulan)&&(p != NULL))
    {
        // deletefirst
        if (p==L.firstP)
        {
            L.firstP = p->nextP;
            L.firstP->prevP = NULL;
            p->nextP = NULL;
            // deletelast
        }
        else if (p->nextP==NULL)
        {
            adrP l = p->prevP;
            l->nextP = NULL;
            p->prevP = NULL;
            // deleteafter
        }
        else
        {
            adrP pre = p->prevP;
            pre->nextP = p->nextP;
            p->nextP->prevP = pre;
            p->prevP = NULL;
            p->nextP = NULL;
        }
        cout<<" ========== Data bulan berhasil di delete ==========";
    }
    else
    {
        cout<<"========== Data bulan tidak ada ==========";
    }
    getch();
};

void deletepengunjung(List &L)//proses mendelete data pengunjung menggunakan nama pengunjungnya
{
    string namapngunjung;//variable nama pengunjung untuk inputan user
    cout<<"Masukkan Nama pengungjung : ";
    cin>>namapngunjung;//inputan user
    bool cek = false;
    adrC r,q;
    adrP p = L.firstP;
    while ((p!=NULL)&&(cek==false))//proses pengecheckan
    {
        if(p->firstC==NULL)
        {
            p = p->nextP;
        }
        else
        {
            // search
            q = p->firstC;
            while ((q!=NULL)&&(q->infoC.namapngunjung!=namapngunjung))
            {
                r = q;
                q = q->nextC;
            }
            if (q == NULL)
            {
                cek = false;
                p = p->nextP;
            }
            else
            {
                cek = true;
            }
        }
    }
    if (p!=NULL)
    {
        // delete
        if (q==p->firstC)
        {
            // delete first
            p->firstC = q->nextC;
            q->nextC = NULL;
        }
        else if (q->nextC==NULL)
        {
            //delete last
            r->nextC = NULL;
        }
        else
        {
            // delete after
            r->nextC = q->nextC;
            q->nextC = NULL;
        }
        // cek label

        p->infoP.jmlKeluarga--;
        cout<<"========== Data Berhasil di delete ==========";

    }
    else
    {
        cout<<"========== Data tidak ditemukan ==========";
    }
    getch();
};

void menu (List &L)//ini adalah tampilan serta pilihan menggnakan if else setelah login dilakukan
{
    int pil=0;
    while (pil>=0 && pil<= 9)//batasan pilihan
    {
        cout << "===================MENU====================="<<endl;
        cout << "=========DATA PENGUNJUNG PARIWISATA========="<<endl;
        cout << "============================================"<<endl;
        cout << "===  1. Tambah Bulan Pengunjung             ==="<<endl;
        cout << "===  2. Masukan Data Pengunjung             ==="<<endl;
        cout << "===  3. Delete Data Bulan                   ==="<<endl;
        cout << "===  4. Delete Data Pengunjung              ==="<<endl;
        cout << "===  5. Lihat Semua Data                    ==="<<endl;
        cout << "===  6. Lihat Pengunjung Pada Bulan         ==="<<endl;
        cout << "===  7. Cari Data Pengunjung                ==="<<endl;
        cout << "===  8. lihat jumlah pengungjung dari bulan ==="<<endl;
        cout << "========================================="<<endl;

        cout<<"Pilih menu : ";
        cin >> pil;
        if (pil == 1)
        {
            cout << "=======================================" << endl<<endl;
            createbulan(L);//jikauser memilih 1 maka akan memanggil create bulan
        }
        else if (pil == 2)
        {
            cout << "=======================================" << endl<<endl;
            createpengunjung(L);//jika user  memilih 2 makan akan memamnggil create pengunjung
        }
        else if (pil == 3)
        {
            cout << "=======================================" << endl<<endl;
            deletebulan(L);//jika user memilih 3 maka akan memanggil delete bulan
        }
        else if (pil == 4)
        {
            cout << "=======================================" << endl<<endl;
            deletepengunjung(L);//jika user memilih 4 maka akan memanggil deletepengunjung
        }
        else if (pil == 5)
        {
            cout << "=======================================" << endl<<endl;
            TampilSemua(L);//jika user memilih 5 maka akan menampilkan data
        }
        else if (pil == 6)
        {
            cout << "=======================================" << endl<<endl;
            tampilbybulan(L);//jika user memilih 6 maka akan menampilkand data sesuai inputan bulan yser
        }
        else if (pil == 7) //jika user memilih 7 mmaka akan disuruh menginputkan nama serta memanggil proses caridatapengunjung
        {
            cout << "=======================================" << endl<<endl;
            string pengunjung;
            cout << "Masukan Nama pengunjung: ";
            cin >> pengunjung;
            caridatapengunjung(L, pengunjung);
        }
        else if (pil == 8)
        {
            cout << "=======================================" << endl<<endl;
            jmldatabulan(L);//jika user memilih 8 maka akan memanggil jmldatabulan
        }
        else if (pil == 0)
        {
            break;
        }
        cout << endl;
        system("CLS");
    }
}
void login(){//ini adalah tampilan awal program , login menggunakan pointer | inputan harus sesuai dengan program
    string user , pass;
    string user1="admin321";
    string pass1="admin123";
    string *userr;
    string *passs;

    userr = &user1;
    passs = &pass1;
    cout<<"Masukkan UserName : "; cin>>user;
    cout<<"Masukkan Password : "; cin>>pass;

    if(user == *userr && pass == *passs)
    {
       cout<<"Berhasil Login"<<endl;
            List L;
            createList(L);
            menu(L);
    }

    else
    {
       cout<<"Gagal Masuk, Password Atau Username Anda Salah";
       system("CLS");
       login();
    }

getch;

}
int main()
{
    login();// memanggil fungsi login untuk permulaan program

    return 0;
}
