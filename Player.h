// JUDUL : Class Player untuk menampung objek pemain
#include <iostream>
#include <cstring>
#include <fstream>

// include file.h
#include "Game.h"
#include "Waktu.h"

using namespace std;

class Player
{
public:
    // property
    char nama[25]; // tipe data char digunakan agar pada saat operasi file bisa diambil
    char tglMain[10];
    string angkaRandom;
    int jmlLangkah;
    int skorAkhir;

    Player()
    {                            // constructor
        strcpy(this->nama, "-"); // diambil dari library cstring
        this->angkaRandom = "";
        this->jmlLangkah = 0;
        this->skorAkhir = 0;
    }
};

// KAMUS
Player pemain;
Game play;
Waktu date;
char namaFile[] = "pemain.dat"; // nama file untuk penyimpanan data

void mulaiGame()
{ // fungsi untuk player bermain dan datanya disimpan pada file
    // kamus lokal
    string tebak, tgl;
    char nama[25];
    int angkaBnr, posBenar;

    fstream catatPemain;                                           // untuk membuat, membaca, dan menulis ke file
    catatPemain.open(namaFile, ios::binary | ios::out | ios::app); // membuka file, untuk operasi output dan data biner dan mencatat dan menambahkan jika sudah ada isinya ke dalam file
    pemain.angkaRandom = play.getRandom();                         // untuk mendapatkan angka random dari method yg ada di class Game
    pemain.jmlLangkah = 0;
    cout << pemain.angkaRandom << endl;
    cout << "\n==========Tebak Angka==========\n"
         << endl;
    cout << "nama player  : ";
    cin >> nama;
    strcpy(pemain.nama, nama); // digunakan untuk mengcopy isi dari variabel nama dg tipe data char
    tgl = date.currentDate();  // untuk mendapatkan tanggal saat player memainkan game, diambil dari method yg ada di class Waktu
    cout << "main tanggal : " << tgl << endl;
    // untuk mengisi tglMain player karena untuk tgl bertipe data string dan tglMain bertipe data char
    for (int i = 0; i < 10; i++)
    {
        pemain.tglMain[i] = tgl[i];
    }

labelUlang: // digunakan untuk label pengulangan bila jawaban salah
    cout << "\nmasukkan angka: ";
    cin >> tebak;
    cout << "=================================================" << endl;
    cout << "| Angka \t| Angka Benar\t| Posisi Benar\t|" << endl;
    cout << "=================================================" << endl;
    angkaBnr = 0;
    posBenar = 0;
    // untuk mengecek jawaban
    for (int i = 0; i < 4; i++)
    {
        if (tebak[i] == pemain.angkaRandom[i])
        { // mengecek posisi
            posBenar++;
        }
        for (int j = 0; j < 4; j++)
        {
            if (tebak[i] == pemain.angkaRandom[j])
            { // mengecek angka yg benar
                angkaBnr++;
            }
        }
    }
    cout << "| " << tebak << " \t\t| " << angkaBnr << " \t\t| " << posBenar << " \t\t|" << endl;
    cout << "-------------------------------------------------" << endl;
    pemain.jmlLangkah++;

    if (tebak != pemain.angkaRandom)
    {
        goto labelUlang; // jika jawaban salah maka program akan menuju ke label 'labelUlang'
    }
    else
    { // jika benar maka data player akan ditulis/dicatat ke dalam file
        pemain.skorAkhir = play.getSkor(pemain.jmlLangkah);
        catatPemain.write((char *)&pemain, sizeof(pemain)); // mencatat kedalam file
        catatPemain.close();                                // menutup file
        cout << "\nSelamat Tebakan Anda Benar\n"
             << endl;
    }

    headerMenu();
}

void rekapPemain()
{                                                    // fungsi untuk menampilkan data pemain yg sudah tersimpan di dalam file
    fstream fileRekap;                               // untuk membuat, membaca, dan menulis ke file
    fileRekap.open(namaFile, ios::binary | ios::in); // membuka file, untuk operasi input dan data biner dan membaca file
    cout << "=================================================" << endl;
    cout << "                      PEMAIN                     " << endl;
    cout << "=================================================\n"
         << endl;

    cout << "=================================================" << endl;
    cout << "| Nama \t| Langkah \t| Skor \t| Tanggal \t|" << endl;
    cout << "=================================================" << endl;

    // kondisi perulangan ketika file sedang dibaca
    while (fileRekap.read((char *)&pemain, sizeof(pemain)))
    { // file dibaca dan disimpan pada objek pemain
        // cout << "| " << pemain.nama << "\t| " << pemain.jmlLangkah << "\t\t| " << pemain.skorAkhir << "\t|" << endl;
        // masalah tidak muncul saat file dibaca adalah tipe data string pada nama
        cout << "| " << pemain.nama << " \t| " << pemain.jmlLangkah << "\t\t| " << pemain.skorAkhir << "\t| " << pemain.tglMain << "\t|" << endl;
    }
    cout << "=================================================" << endl;
    fileRekap.close(); // menutup file

    cout << "\n\n";
    headerMenu();
}

void rankPemain()
{                  // fungsi untuk membuat rank pemain dilihat dari jumlah skor terbesar dan langkah terkecil
    Player p[999]; // untuk menampung data dari dlm file agar bisa diurutkan
    int i = 0, jmlData;
    int key;

    fstream filePemain;                               // untuk membuat, membaca, dan menulis ke file
    filePemain.open(namaFile, ios::binary | ios::in); // membuka file, untuk operasi input dan data biner dan membaca file
    // mengisi objek p
    while (filePemain.read((char *)&pemain, sizeof(pemain)))
    {
        strcpy(p[i].nama, pemain.nama);
        p[i].jmlLangkah = pemain.jmlLangkah;
        p[i].skorAkhir = pemain.skorAkhir;
        i++;
    }
    filePemain.close(); // menutup file

    // proses sorting dengan selection sort
    jmlData = i;
    for (int i = 0; i < jmlData; i++)
    {
        key = i;
        for (int j = i; j < jmlData; j++)
        {
            // cek langkah dan skor
            if (p[j].skorAkhir >= p[key].skorAkhir && p[j].jmlLangkah < p[key].jmlLangkah)
            {
                key = j;
            }
        }
        swap(p[i], p[key]); // tukar posisi
    }

    cout << "=================================================" << endl;
    cout << "                 PERINGKAT PEMAIN                " << endl;
    cout << "=================================================\n"
         << endl;

    cout << "=================================================" << endl;
    cout << "| Peringkat \t| Nama \t| Langkah \t| Skor \t|" << endl;
    cout << "=================================================" << endl;
    // proses tampilkan data
    for (int i = 0; i < jmlData; i++)
    {
        cout << "| #" << i + 1 << "\t\t| " << p[i].nama << " \t| " << p[i].jmlLangkah << "\t\t| " << p[i].skorAkhir << "\t|" << endl;
    }
    cout << "=================================================" << endl;
    cout << "\n\n";
    headerMenu();
}

void cariPemain()
{ // fungsi untuk mencari pemain
    string cariP;
    bool ditemukan = false;
    fstream filePemain; // untuk membuat, membaca, dan menulis ke file

    cout << "=================================================" << endl;
    cout << "                    CARI PEMAIN                  " << endl;
    cout << "=================================================\n"
         << endl;

labelInputTgl:
    cout << "\nMasukkan tanggal [dd/mm/yyyy]: ";
    cin >> cariP;
    if (cariP.length() != sizeof(pemain.tglMain))
    {
        cout << "format tanggal salah misal [01/01/2023]" << endl;
        goto labelInputTgl;
    }
    else
    {
        filePemain.open(namaFile, ios::binary | ios::in); // membuka file, untuk operasi input dan data biner dan membaca file
        cout << "=================================================" << endl;
        cout << "| Nama \t| Langkah \t| Skor \t| Tanggal \t|" << endl;
        cout << "=================================================" << endl;
        while (filePemain.read((char *)&pemain, sizeof(pemain)))
        { // membaca file
            // pengecekan jika tglMain dan yg dicari sama maka akan ditampilkan
            if (pemain.tglMain == cariP)
            {
                ditemukan = true;
                cout << "| " << pemain.nama << " \t| " << pemain.jmlLangkah << "\t\t| " << pemain.skorAkhir << "\t| " << pemain.tglMain << "\t|" << endl;
            }
        }
        cout << "=================================================" << endl;
        // jika data tidak ditemukan
        if (!ditemukan)
        {
            cout << "\nData tidak ditemukan\n"
                 << endl;
        }
        filePemain.close(); // menutup file
        cout << "\n";
        headerMenu();
    }
}