#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int unseparated() {
    FILE * penerbangan;
    penerbangan = fopen("unseparated.txt", "rt");

    struct{
        char maskapai[10];
        int jumlah;
        char tujuan[50];
    }flight;

    char separator[10] = "00";
    char current[10];
    int sum = 0;
    int sum_all = 0;

    if(feof(penerbangan)) {
        cout << "File kosong, konsolidasi file dibatalkan" << endl;
    }
    else {
        fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
        strcpy(current, flight.maskapai);
        do {
            // masukkan maskapai pada variabel temporer
            if(!feof(penerbangan) && strcmp(current, flight.maskapai) == 0) {
                sum = sum + flight.jumlah;
                fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
            }
            else if(feof(penerbangan) || strcmp(current, flight.maskapai) != 0) {
                cout << "Penerbangan maskapai " << current << " = " << sum << endl;
                sum_all = sum_all + sum;
                sum = 0;
                strcpy(current, flight.maskapai);
            }
        }
        while (!feof(penerbangan));

        // ditambahkan karena tidak dapat mengeksekusi else if pada baris terakhir
        cout << "Penerbangan maskapai " << current << " = " << sum << endl;
        cout << "Jumlah penerbangan : " << 0 << endl;
    }
    return 0;
}

int separated() {
    FILE * penerbangan;
    penerbangan = fopen("separated.txt", "rt");

    struct{
        char maskapai[10];
        int jumlah;
        char tujuan[50];
    }flight;

    char separator[10] = "00";
    char current[10];
    int sum;
    int sum_all = 0;

    if(feof(penerbangan)) {
        cout << "File kosong, konsolidasi file dibatalkan" << endl;
    }
    else {
        fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
        do {
            // cek apakah separator?
            if(!feof(penerbangan) && strcmp(separator, flight.maskapai) == 0) {
                fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
            }
            // jika bukan separator
            else {
                // masukkan maskapai yang dihitung pada variabel temporer
                strcpy(current, flight.maskapai);
                sum = 0;
                // selama bukan end of file dan variabel temporer sama dengan maskapai
                while(!feof(penerbangan) && strcmp(current, flight.maskapai) == 0) {
                    sum = sum + flight.jumlah;
                    fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
                }
                // masukkan total penerbangan keseluruhan
                sum_all = sum_all + sum;
                cout << "Penerbangan maskapai " << current << " = " << sum << endl;
                fscanf(penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah, flight.tujuan);
            }
        }
        while (!feof(penerbangan));

        cout << "Jumlah penerbangan : " << sum_all << endl;
    }
}

int main()
{
    cout << "Konsolidasi File" << endl;
    cout << "1. Dengan separator" << endl;
    cout << "2. Tanpa separator" << endl;

    int choose;
    cout << "Silahkan pilih menu [1/2] : ";
    cin >> choose;

    if(choose == 1) {
        separated();
    }
    else if(choose == 2) {
        unseparated();
    }
    else {
        cout << "Error" << endl;
    }

    return 0;
}
