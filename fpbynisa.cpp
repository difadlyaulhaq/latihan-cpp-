#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct User {
    string username;
    string password;
};

struct Buku {
    string judul, pengarang;
    int tahunTerbit;
    Buku* next;
};

Buku* head = NULL;

void adminMenu();
void userMenu();
void registerUser();
void login();
void createCircularLinkedList(string judul, string pengarang, int tB);
void printCircularLinkedList();
Buku* searchByTitle(string judul);
Buku* searchByAuthor(string pengarang);
void sortByYear();

int main() {
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice < 5);

    createCircularLinkedList("Kata", "Geez & Ann", 2018);
    createCircularLinkedList("Dia adalah kakakku", "Tere Liye", 2009);
    createCircularLinkedList("Aroma Karsa", "Dee Lestari", 2018);
    createCircularLinkedList("11.11", "Fiersa Besari", 2018);
    createCircularLinkedList("Bumi Manusia", "Pramoedya Ananta Toer", 2005);
    createCircularLinkedList("Negeri 5 Negara", "Ahmad Faudi", 2009);

    cout << "Data awal:" << endl;
    printCircularLinkedList();

    cout << "Pencarian berdasarkan judul:" << endl;
    string judulCari = "Kata";
    Buku* hasilPencarianJudul = searchByTitle(judulCari);
    if (hasilPencarianJudul != NULL) {
        cout << "Buku dengan judul " << judulCari << " ditemukan." << endl;
        cout << "Pengarang: " << hasilPencarianJudul->pengarang << endl;
        cout << "Tahun Terbit: " << hasilPencarianJudul->tahunTerbit << endl;
    }
    cout << endl;

    cout << "Pencarian berdasarkan pengarang:" << endl;
    string pengarangCari = "Dee Lestari";
    Buku* hasilPencarianPengarang = searchByAuthor(pengarangCari);
    if (hasilPencarianPengarang != NULL) {
        cout << "Buku dengan pengarang " << pengarangCari << " ditemukan." << endl;
        cout << "Judul: " << hasilPencarianPengarang->judul << endl;
        cout << "Tahun Terbit: " << hasilPencarianPengarang->tahunTerbit << endl;
    }
    cout << endl;

    cout << "Pengurutan berdasarkan tahun terbit:" << endl;
    sortByYear();
    printCircularLinkedList();

    return 0;
}

void createCircularLinkedList(string judul, string pengarang, int tB) {
    Buku* newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = tB;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Buku* cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = head;
    }
}

void printCircularLinkedList() {
    if (head == NULL) {
        cout << "List buku kosong." << endl;
        return;
    }

    Buku* cur = head;
    do {
        cout << "Judul: " << cur->judul << endl;
        cout << "Pengarang: " << cur->pengarang << endl;
        cout << "Tahun Terbit: " << cur->tahunTerbit << endl;
        cout << endl;
        cur = cur->next;
    } while (cur != head);
}

Buku* searchByTitle(string judul) {
    if (head == NULL) {
        return NULL;
    }

    Buku* cur = head;
    do {
        if (cur->judul == judul) {
            return cur;
        }
        cur = cur->next;
    } while (cur != head);

    return NULL;
}

Buku* searchByAuthor(string pengarang) {
    if (head == NULL) {
        return NULL;
    }

    Buku* cur = head;
    do {
        if (cur->pengarang == pengarang) {
            return cur;
        }
        cur = cur->next;
    } while (cur != head);

    return NULL;
}

void sortByYear() {
    if (head == NULL) {
        return;
    }

    Buku* cur = head;
    Buku* nextNode;
    int tempYear;
    string tempTitle, tempAuthor;

    do {
        nextNode = cur->next;

        while (nextNode != head) {
            if (cur->tahunTerbit > nextNode->tahunTerbit) {
                tempYear = cur->tahunTerbit;
                cur->tahunTerbit = nextNode->tahunTerbit;
                nextNode->tahunTerbit = tempYear;

                tempTitle = cur->judul;
                cur->judul = nextNode->judul;
                nextNode->judul = tempTitle;

                tempAuthor = cur->pengarang;
                cur->pengarang = nextNode->pengarang;
                nextNode->pengarang = tempAuthor;
            }
            nextNode = nextNode->next;
        }
        cur = cur->next;
    } while (cur != head);
}

void registerUser() {
    User user;
    cout << "Registration Form:\n";
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    ofstream outFile("users.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return;
    }
    outFile << user.username << " " << user.password << endl;
    outFile.close();

    cout << "User registered successfully.\n";
}

void login() {
    User user;
    cout << "Login:\n";
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    ifstream inFile("users.txt");
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    string username, password;
    while (inFile >> username >> password) {
        if (username == user.username && password == user.password) {
            cout << "Login successful.\n";
            adminMenu();
            return;
        }
    }

    cout << "Invalid username or password.\n";
}

void adminMenu() {
    cout << "Admin Menu:\n";
    cout << "1. Add Book\n";
    cout << "2. Search Book by Title\n";
    cout << "3. Search Book by Author\n";
    cout << "4. Sort Books by Year\n";
    cout << "5. Logout\n";
    // Tambahkan pilihan menu tambahan yang diinginkan

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Tambahkan implementasi untuk menambahkan buku
            break;
        case 2:
            // Tambahkan implementasi untuk mencari buku berdasarkan judul
            break;
        case 3:
            // Tambahkan implementasi untuk mencari buku berdasarkan pengarang
            break;
        case 4:
            // Tambahkan implementasi untuk mengurutkan buku berdasarkan tahun terbit
            break;
        case 5:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}

void userMenu() {
    cout << "User Menu:\n";
    cout << "1. Search Book by Title\n";
    cout << "2. Search Book by Author\n";
    cout << "3. Logout\n";
    // Tambahkan pilihan menu tambahan yang diinginkan

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Tambahkan implementasi untuk mencari buku berdasarkan judul
            break;
        case 2:
            // Tambahkan implementasi untuk mencari buku berdasarkan pengarang
            break;
        case 3:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}

