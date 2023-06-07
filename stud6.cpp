#include <iostream>
#include <unistd.h>
using namespace std;

const int SIZE{25};
const int BUBBLE{0};
const int SELECTION{1};
const int INSERTION{2};

int nsrc[SIZE];
int ndata[SIZE];

void init_data();
void load_data();
void view_data();
void bubsort();
void selsort();
void inssort();
void run_sort(int);

int main(void) {
    cout << "Perbandingan Metode Pengurutan\n";

    init_data();
    load_data();

    cout << "Data Acak:\n";
    view_data();
    cout << "\n\n";

    // Bubble Sort
    cout << "Bubble Sort\n";
    load_data();
    run_sort(BUBBLE);

    // Selection Sort
    cout << "Selection Sort\n";
    load_data();
    run_sort(SELECTION);

    // Insertion Sort
    load_data();
    cout << "Insertion Sort\n";
    run_sort(INSERTION);

    return 0;
}

void init_data() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; ++i)
        nsrc[i] = rand() % 100;
}

void load_data() {
    for (int i = 0; i < SIZE; ++i)
        ndata[i] = nsrc[i];
}

void view_data() {
    for (int i = 0; i < SIZE; ++i)
        cout << ndata[i] << " ";
    cout << endl;
}

void bubsort() {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = 0; j < SIZE - i - 1; ++j) {
            if (ndata[j] > ndata[j + 1]) {
                int tmp = ndata[j];
                ndata[j] = ndata[j + 1];
                ndata[j + 1] = tmp;
                usleep(10000);
            }
            usleep(10000);
        }
        usleep(10000);
    }
}

void selsort() {
    for (int i = 0; i < SIZE; ++i) {
        int min = i;
        for (int j = i; j < SIZE; ++j) {
            if (ndata[j] < ndata[min]) {
                min = j;
                usleep(10000);
            }
            usleep(10000);
        }
        int tmp = ndata[i];
        ndata[i] = ndata[min];
        ndata[min] = tmp;
        usleep(10000);
    }
}

void inssort() {
    for (int i = 1; i < SIZE; ++i) {
        int m = ndata[i];
        int s = i;
        while (s >= 0 && m < ndata[s - 1]) {
            ndata[s] = ndata[s - 1];
            --s;
            usleep(10000);
        }
        ndata[s] = m;
        usleep(10000);
    }
}

void run_sort(int m) {
    auto t1 = time(NULL);
    switch (m) {
        case 0: bubsort(); break;
        case 1: selsort(); break;
        case 2:
        default: inssort(); break;
    }
    auto t2 = time(NULL);
    auto t = t2 - t1;
    cout << "data terurut:\n";
    view_data();
    cout << "waktu: " << t << " millisecond\n";
    cout << "---------------------------\n\n";
}
