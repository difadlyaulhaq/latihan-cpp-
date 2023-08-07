#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct PhoneBook
{
    string name;
    string address;
    string number;
};

// ukuran array
const int SIZE = 100;

// counter, menghitung jumlah data yang tersimpan
int counter = 0;

// array untuk menyimpan data
PhoneBook pb[SIZE];

// fungsi untuk menambahkan data
void add_contact();

// fungsi untuk menampilkan data
void show_contact();

// fungsi untuk mengedit data
void edit_contact();

// fungsi untuk memperoleh menu pilihan
char get_menu();

int main()
{
    while(true)
    {
        char select = get_menu();
        if(select == '1')
            add_contact();
        else if(select == '2')
            show_contact();
        else if(select == '3')
            edit_contact();
        else if(select == '4')
            break;
    }
    return 0;
}

void add_contact()
{
    system("cls");
    cout << "Add New Contact\n";
    cout << "- Name : ";
    getline(cin, pb[counter].name);
    cout << "- Address: ";
    getline(cin, pb[counter].address);
    cout << "- Phone : ";
    getline(cin, pb[counter].number);
    ++counter;
}

void show_contact()
{
    system("cls");
    cout << "Show Contact\n";
    cout << "--------------------------------------------------------------\n";
    cout << setw(4) << "#";
    cout << setw(15) << "Name";
    cout << setw(30) << "Address";
    cout << setw(13) << "Number";
    cout << endl;
    cout << "--------------------------------------------------------------\n";
    for(int i = 0; i < counter; ++i)
    {
        cout << setw(4) << i + 1;
        cout << setw(15) << pb[i].name;
        cout << setw(30) << pb[i].address;
        cout << setw(13) << pb[i].number;
        cout << endl;
    }
    cout << "--------------------------------------------------------------\n";
    system("pause");
}

void edit_contact()
{
    system ('cls');
    cout << "Edit Contact\n";
    show_contact();
    cout << "--------------------------------------------------------------\n";
    cout << "Enter the contact number you want to edit (0 to cancel): ";
    int index;
    cin >> index;
    cin.ignore();
    if(index == 0) return;
    if(index < 1 || index > counter)
    {
        cout << "Invalid contact number!\n";
        system("pause");
        return;
    }
    cout << "- Name (" << pb[index-1].name << "): ";
    getline(cin, pb[index-1].name);
    cout << "- Address (" << pb[index-1].address << "): ";
    getline(cin, pb[index-1].address);
    cout << "- Phone (" << pb[index-1].number << "): ";
    getline(cin, pb[index-1].number);
    cout << "Contact has been updated.\n";
    system("pause");
}

char get_menu()
{
    system("cls");
    cout << "Phone Book\n";
    cout << " [1] Add Contact\n";
    cout << " [2] Show Contact\n";
    cout << " [3] Edit Contact\n";
    cout << " [4] Exit\n";
    cout << "Select";
    string sel;
getline(cin, sel);
}