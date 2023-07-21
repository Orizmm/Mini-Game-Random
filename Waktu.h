#include <iostream>
#include <ctime>

using namespace std;

class Waktu{
    public:
        // property
        int dd, mm, yy;

        // method
        int getDay(){ // fungsi untuk mendapatkan tanggal skrng
            // current date/time based on current system
            time_t now = time(0);
            tm ltm = *localtime(&now);

            return ltm.tm_mday; // tanggal di sistem
        }

        int getMonth(){ // fungsi untuk mendapatkan bulan skrng
            // current date/time based on current system
            time_t now = time(0);
            tm ltm = *localtime(&now);

            return ltm.tm_mon + 1;
        }

        int getYear(){ // fungsi untuk mendapatkan tahun skrng
            // current date/time based on current system
            time_t now = time(0);
            tm ltm = *localtime(&now);

            return ltm.tm_year + 1900;
        }

        string currentDate(){ // fungsi untuk mendapatkan tanggal, bulan, tahun skrng
            this->dd = getDay();
            this->mm = getMonth();
            this->yy = getYear();
            
            // format untuk tanggal dd/mm/yyyy
            if(dd < 10 && mm < 10){  // 05/07/2023
                return "0"+to_string(dd)+"/0"+to_string(mm)+"/"+to_string(yy);
            }else if(dd < 10){
                return "0"+to_string(dd)+"/"+to_string(mm)+"/"+to_string(yy);
            }else if(mm < 10){
                return to_string(dd)+"/0"+to_string(mm)+"/"+to_string(yy);
            }else {
                return to_string(dd)+"/"+to_string(mm)+"/"+to_string(yy);
            }
        }

};