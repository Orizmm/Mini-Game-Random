#include <iostream>
#include <string>

using namespace std;

// Kamus
void menu();
void headerMenu();
void konfirmUlangMenu();
void selesai();
void mulaiGame();
void rekapPemain();
void rankPemain();
void cariPemain();

void menu()
{
    char menuPilihan;
    cout << "| Masukkan Pilihan :                                         |\n";
    cin >> menuPilihan;
    switch (menuPilihan)
    {
    case '1':
        {
            // ke menu 1
            system("cls");
            mulaiGame();
        }
        break;
    case '2':
        {
            // ke menu 2
            system("cls");
            rekapPemain();
        }
        break;
    case '3':
        {
            // ke menu 3
            system("cls");
            rankPemain();
        }
        break;
    case '4':
        {
            // ke menu 4
            system("cls");
            cariPemain();
        }
        break;
    case '5':
        {
            // ke menu 5
            selesai();
        }
        break;
    default:
        cout << "Pilihan anda tidak tersedia. ulangi pilihan (y/n)? ";
        konfirmUlangMenu();
        break;
    }
}

void headerMenu()
{
    cout << "====================== Mini Game Random ======================\n";
    cout << "|                   ( Opsi Pilihan Menu )                    |\n";
    cout << "|                  1. Main Game                              |\n";
    cout << "|                  2. Rekap Hasil Permainan                  |\n";
    cout << "|                  3. Lihat Peringkat                        |\n";
    cout << "|                  4. Cari Pemain                            |\n";
    cout << "|                  5. Selesai                                |\n";
    cout << "==============================================================\n";
    menu();
}

void konfirmUlangMenu()
{
    char konfirmMenu;
    cin >> konfirmMenu;
    if (konfirmMenu == 'y' || konfirmMenu == 'Y')
    {
        menu();
    }
    else
    {
        selesai();
    }
}


void selesai(){
    cout << "\n\n==========================End Program=========================" << endl;
    cout << "|               Program Selesai, terima kasih:)              |" << endl;
    cout << "==============================================================" << endl;
}
