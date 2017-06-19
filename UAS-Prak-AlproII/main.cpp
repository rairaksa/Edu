#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class First {
private :
    struct data {
        string norek;
        string nama;
        string alamat;
        int saldo;
        int persentase;
        int lama;
        data *next;
    };

    data *head, *tail;
    data *input, *output;

public :
    void initialize() {
        head = NULL;
        tail = NULL;
    }
    int isEmpty(){
        if(tail == NULL) {
            return 1;
        }
        else return 0;
    }
    void insertData(string a, string b, string c, int d, int e, int f) {
        data *input, *bantu;
        input = new data;
        input->norek = a;
        input->nama = b;
        input->alamat = c;
        input->saldo = d;
        input->persentase = e;
        input->lama = f;
        input->next = NULL;
        if(isEmpty() == 1) {
            head = input;
            tail = input;
            tail->next = NULL;
        }
        else {
            tail->next = input;
            tail = input;
        }
        cout << "data masuk";
    }
    void showData() {
        data *output;
        output = head;
        if(isEmpty()==0){
            int highest = 0;
            int lowest = 0;
            while(output!=NULL) {
                if(highest < output->saldo) {
                    highest = output->saldo;
                }
                if(lowest == 0) {
                    lowest = output->saldo;
                }
                else if(lowest > output->saldo) {
                    lowest = output->saldo;
                }
                cout << "Data seluruh nasabah" << endl;
                cout << "No Rekening : " << output->norek << endl;
                cout << "Nama : " << output->nama << endl;
                cout << "Alamat : " << output->alamat << endl;
                cout << "Saldo : " << output->saldo << endl;
                cout << "Persentase : " << output->persentase << endl;
                cout << "Lama : " << output->lama << endl;
                cout << "Saldo Akhir : " << ((output->saldo/100)*output->persentase) << endl;
                output = output->next;
            }

            cout << "Saldo tertinggi : " << highest << endl;
            cout << "Saldo terendah : " << lowest << endl;

            output = head;
            while(output!=NULL) {
                if(output->saldo <= 500000) {
                    cout << "Data nasabah dengan saldo dibawah 500rb" << endl;
                    cout << "No Rekening : " << output->norek << endl;
                    cout << "Nama : " << output->nama << endl;
                    cout << "Alamat : " << output->alamat << endl;
                    cout << "Saldo : " << output->saldo << endl;
                    cout << "Persentase : " << output->persentase << endl;
                    cout << "Lama : " << output->lama << endl;
                    cout << "Saldo Akhir : " << ((output->saldo/100)*output->persentase) << endl;
                }
                output = output->next;
            }

            output = head;
            while(output!=NULL) {
                if(output->saldo == 10000000) {
                    cout << "Data nasabah dengan saldo 10jt" << endl;
                    cout << "No Rekening : " << output->norek << endl;
                    cout << "Nama : " << output->nama << endl;
                    cout << "Alamat : " << output->alamat << endl;
                    cout << "Saldo : " << output->saldo << endl;
                    cout << "Persentase : " << output->persentase << endl;
                    cout << "Lama : " << output->lama << endl;
                    cout << "Saldo Akhir : " << ((output->saldo/100)*output->persentase) << endl;
                }
                output = output->next;
            }

        }
        else {
            cout << "Masih kosong\n";
        }
    }
};

class Second {
private :
    string teks;

public :
    void setTeks(string value) {
        teks = value;
    }

    string getTeks() {
        return teks;
    }

    void jalan() {
        string sortedTeks = getTeks();
        int panjang = 13;
        int k = panjang/2;
        char temp;

        for(int i=0;i<panjang;i++) {
            int j = i+k;

            if(j >= panjang) {
                k = k/2;
                i = 0;
                if(j >= panjang && k == 1) {
                    break;
                }
            }
            else {
                if(teks[j] < teks[i]) {
                    cout << "switch " << teks[i] << " to " << teks[j] << " with k = " << k << endl;
                    temp = teks[j];
                    teks[j] = teks[i];
                    teks[i] = temp;

                    if(k < i) {
                        for(j;j>=0;j--) {
                            int inew = j-k;
                            if(inew < 0) {
                                break;
                            }
                            else {
                                if(teks[j] < teks[inew]) {
                                    temp = teks[j];
                                    teks[j] = teks[inew];
                                    teks[inew] = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << teks;
    }
};

class Third {
private :
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

public :
    int knapSack(int W, int wt[], int val[], int n) {
        int i, w;
        int K[n + 1][W + 1];

        for (i = 0; i <= n; i++) {
            for (w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    K[i][w] = 0;
                }
                else if (wt[i - 1] <= w) {
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                }
                else {
                    K[i][w] = K[i - 1][w];
                }
            }
        }
        return K[n][W];
    }
};

int main()
{
    cout << "\n1. Link List\n2. Bubble Sort\n3. Knapsack\nSilahkan pilih program : ";
    int mode;
    cin >> mode;
    if(mode == 1) {
        First first;

        string norek = "0705199425";
        string nama = "Rai Raksa M";
        string alamat = "Kp. Cililin Timur";
        int saldo = 10500000;
        int persentase = 16;
        int lama = 1;

        int jml;

        cout << "Akan memasukkan berapa data nasabah? ";
        cin >> jml;

        first.initialize();
        for(int i=0;i<jml;i++) {
            cout << "Data ke-" << i+1 << endl;
            cout << "No Rekening : ";
            cin >> norek;
            cout << "Nama : ";
            cin >> nama;
            cout << "Alamat : ";
            cin >> alamat;
            cout << "Saldo : ";
            cin >> saldo;
            cout << "Persentase : ";
            cin >> persentase;
            cout << "Lama : ";
            cin >> lama;

            first.insertData(norek, nama, alamat, saldo, persentase, lama);
        }
        first.showData();

        main();
    }
    else if(mode == 2) {
        Second sec;
        sec.setTeks("sayamahasiswa");
        sec.jalan();
        main();
    }
    else if(mode == 3) {
        Third third;
        cout << "Masukkan jumlah item pada knapsack :";
        int n, W;
        cin >> n;
        int val[n], wt[n];
        for (int i = 0; i < n; i++) {
            cout << "Masukkan nilai dan bobot item : " << i << ":";
            cin >> val[i];
            cin >> wt[i];
        }
        cout << "Masukkan kapasitas knapsack : ";
        cin >> W;
        cout << third.knapSack(W, wt, val, n);
        main();
    }
    else {
        // exit
    }

    return 0;
}
