#ifndef GAME_H 
#define GAME_H 

#include <iostream>
#include <cstdlib>
// #include "Player.h"

using namespace std;

class Game{
    public:

        string getRandom(){ // fungsi untuk menghasilkan 4 bilangan berbeda nilai random dari 1-9  "1426"
            // kamus lokal
            string random;
            int bilRandom[4];
            int angka;

            srand(time(0));
            // rand() digunakan untuk menghasilkan serangkaian angka acak.
            // srand() digunakan untuk menginisialisasi generator bilangan acak. Fungsi srand() menetapkan titik awal untuk menghasilkan serangkaian bilangan bulat acak semu. Jika srand() tidak dipanggil, seed rand() diatur seolah-olah srand(1) dipanggil saat program dimulai. Nilai lain apa pun untuk seed menyetel generator ke titik awal yang berbeda.
            // source : https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
            labelGetRandom:
            for(int i=0; i<4; i++){
                angka = (rand()%8) + 1;  //0-8 + 1 => 1-9
                bilRandom[i] = angka;
                // pengecekan agar tidak ada bilangan yg sama
                if(i == 1){ // [0, 1]
                    if(bilRandom[i] == bilRandom[i-1]){ //1-1=0
                        angka = (rand()%8) + 1;
                        bilRandom[i] = angka;
                    }
                }
                else if(i == 2){ // [0, 1, 2]
                    if(bilRandom[i] != bilRandom[i-1] && bilRandom[i] != bilRandom[i-2]){
                        continue;
                    }else{
                        angka = (rand()%8) + 1;
                        bilRandom[i] = angka;
                    }
                }
                else if(i == 3){ // [0, 1, 2, 3]
                    if(bilRandom[i] != bilRandom[i-1] && bilRandom[i] != bilRandom[i-2] && bilRandom[i] != bilRandom[i-3]){
                        continue;
                    }else{
                        angka = (rand()%8) + 1;
                        bilRandom[i] = angka;
                    }
                }
            }

            // untuk mengecek apakah dari 4 bilangan ada angka yg sama
            for(int i=0; i<4; i++){
                for(int j=i+1; j<4; j++){
                    if(bilRandom[i] == bilRandom[j]){ // jika ada yg sama akan menuju ke label labelGetRandom
                        goto labelGetRandom;
                        break;
                    }
                }
            }

            // mengisi variabel random dengan bilRandom
            for(int i=0; i<4; i++){
                random += to_string(bilRandom[i]);
            }

            return random; // mengembalikan nilai random
        }

        int getSkor(int langkah){ // fungsi untuk mendapatkan skor dengan memasukkan satu parameter
            // kamus lokal
            int skor;

            if(langkah <= 5){
                skor = 10;
            }
            else if(langkah <= 10){
                skor = 7;
            }
            else if(langkah <= 15){
                skor = 4;
            }
            else {
                skor = 1;
            }
            
            return skor; // mengembalikan nilai skor
        }

};

#endif