#include <iostream>
#include <fstream>

using namespace std;

/*
Rai Raksa M - 270317
*/

void quiz() {

    // untuk menampung berapa jumlah angka yang akan diinput
    int jumlah;

    cout << "Masukkan jumlah deret angka yang akan dimasukkan : ";
    cin >> jumlah; // input berapa jumlah angka yang akan diinput kemudian

    int deret[jumlah]; // membuat array untuk menampung angka-angka dengan index sesuai dengan jumlah deret yang diinput sebelumnya

    // proses iterasi untuk menampung nilai pada array satu persatu
    for(int i=0;i<jumlah;i++) {
        cout << "Masukkan angka ke-" << i << " : ";
        cin >> deret[i];
        cout << endl;
    }

    // deklarasi file dan pembukaan file genap dan ganjil
    FILE * genap;
    FILE * ganjil;
    genap = fopen("genap.txt", "w");
    ganjil = fopen("ganjil.txt", "w");

    // variabel yang menampung total dari inputan yang diklasifikasikan berdasarkan ganjil atau genapnya angka
    int totalGenap = 0;
    int totalGanjil = 0;

    for(int i=0;i<jumlah;i++) {
        cout << "Angka masukkan ke-" << i << " : " << deret[i] << endl;
        if(deret[i]%2) { // jika genap
            totalGenap += deret[i];
            fprintf(genap, "%d\n", deret[i]); // memasukkan angka genap pada file genap
        }
        else {
            totalGanjil += deret[i];
            fprintf(ganjil, "%d\n", deret[i]); // memasukkan angka ganjil pada file ganjil
        }
    }
    fprintf(genap, "%s %d", "Total : ", totalGenap); // menambahkan nilai total untuk genap
    fprintf(ganjil, "%s %d", "Total : ", totalGanjil); // menambahkan nilai total untuk ganjil

    // menutup file genap dan ganjil
    fclose(genap);
    fclose(ganjil);
}

int main()
{
    // memanggil method prosedur quiz
    quiz();
}
