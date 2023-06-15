#include <iostream>
using namespace std;
struct Buku
{
    string judul,pengarang;
    int tahunterbit;
    Buku*next;

};
 Buku *head,*tail,*cur,*newNode,*del,*before;

void createSingleLinkedList(string judul,string pengarang , int tB){
    head = new Buku();
    head ->judul=judul;
    head->pengarang=pengarang;
    head->tahunterbit= tB;
    head -> next= NULL;
    tail=head;
}

int countSingleLinkedlist(){
    cur= head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++; 
        cur = cur ->next;

    }
    return jumlah;
}

void addfirst (string judul, string pengarang,int tB){
    newNode = new Buku();
    newNode  -> judul = judul;
    newNode -> pengarang = pengarang;
    newNode -> tahunterbit =tB;
    newNode ->next = head;
    head = newNode;
}

void addLast(string judul, string pengarang,int tB){
    newNode = new Buku();
    newNode  -> judul = judul;
    newNode -> pengarang = pengarang;
    newNode -> tahunterbit =tB;
    newNode ->next = NULL;
    head = newNode;
}