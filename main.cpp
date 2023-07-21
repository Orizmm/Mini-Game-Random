#include <iostream>
#include <string>
#include <fstream>

#include "Menu.h"
#include "Game.h"
#include "Player.h"

using namespace std;   

int main(){ 
    // main fungsi
    headerMenu();
    return 0;
}

// alur program

// akan tampil menu lalu pilih menu yg diinginkan
// pilih menu 1
    // akan bermain game tebak angka dan hasilnya akan disimpan ke dalam file
    // lalu akan kembali ke tampilan menu
// pilih menu 2
    // akan menampilkan hasil dari rekapan pemain
    // lalu akan kembali ke tampilan menu
// pilih menu 3
    // akan menampilkan tabel rank dari pemain
    // lalu akan kembali ke tampilan menu
// pilih menu 4
    // untuk mencari data pemain berdasarkan tanggal
    // lalu akan kembali ke tampilan menu
// pilih menu 5
    // program selesai
// selain pilih menu dari 0-5
    // akan ada konfirmasi ingin mengulang atau tidak
        // jika iya maka akan ke menu
        // jika tidak program akan selesai