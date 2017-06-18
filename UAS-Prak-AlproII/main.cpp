#include <iostream>

using namespace std;

class First {

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
