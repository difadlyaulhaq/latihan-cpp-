#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

struct mahasiswa{
	char nama[50], nim[15], password[50];	
};

int main(){
	
	string  nama,  password, nimkamu;
	char namaMu[50], nim[5], passwordMu[50], waktu[100],  pilihan;
	int nimMu[15];
	struct mahasiswa e;
	FILE *fp, *ft;
	long int recsize;
	
	
	fp = fopen("mahasiswa.txt", "rb+");
	
	if (fp == NULL){
        fp = fopen("mahasiswa.txt","wb+");

        if (fp==NULL){
            puts("Cannot open file");
            return 0;
        }
    }
    
    
	recsize = sizeof(e);
	
//	char waktuku[100];
//	time(&curr_time);
//    tm * curr_tm = localtime(&curr_time);
//    strftime(waktuku, 50, "%H:%M:%S", curr_tm);
	
	system("cls");
	menu:
	//cout << waktuku << endl;
	cout << "\n \t====== Selamat Datang di =======";
	cout << "\n \t====== Presensi Mahasiswa ======";
	cout << "\n";
    cout << "\n \t1. Login Mahasiswa";
    cout << "\n \t2. Register Mahasiswa";
    cout << "\n \t3. Exit";
    cout << "\n\n";
    
    cout << "Select Your Choice : ";
    
    fp = fopen("mahasiswa.txt", "r+");
	
	if (fp == NULL){
        fp = fopen("mahasiswa.txt","w+");

        if (fp==NULL){
            puts("Cannot open file");
            return 0;
        }
    }
    
    
	recsize = sizeof(e);
    
    pilihan = getche();
    
    switch(pilihan){
    	case '1':
    		
    	
			rewind(fp);
			fread(&e,recsize,1,fp);
    		if (fread(&e,recsize,1,fp) == 1){
    			
    			while (fread(&e, recsize, 1, fp) == 1){
    				cout << "nama : " << e.nama << endl;
    				cout << "NIM : " << e.nim << endl;
    				cout << "Password : " << e.password << endl;
    				nimkamu = e.nim;    				    				
    				 							
				}
				cout << "\n\nMasukkan NIM Anda : " ;
    			cin >> nim;
				if (nim == nimkamu){
    				cout << e.password << endl;
    				cout << "Masukkan Paswword Anda : ";
	    			cin >> password;
    				if (e.password != password){
						cout << "password kamu salah, coba ulangi lagi";
    					goto menu;
					}else{
						char pilihanHome;
		    
						if(nim == nimkamu){
								
							cout << "\n \t====== Selamat Datang ";
							cout << e.nama;
							cout << " =======";
							cout << "\n \t====== Di Presensi Mahasiswa ======";
							cout << "\n";
							cout << "\n \t 1. Lihat Presensi";
							cout << "\n \t 2. Exit";
							cout << "\n\n";
							    	
							cout << "Select Your Choice : ";
							    	
							pilihanHome = getche();
							    	
							switch(pilihanHome){
							    case '1':
							    	if(nim == nimkamu){
							    		cout << "\n nama " << e.nama << "\n nim " << e.nim  << endl;
									}
										
											
									break;
										
								case '2':
									cout << "\n\n====== bye ======\n\n" ;
									break;
										
								default:
									cout << "\n\n====== bye ======\n\n" ;
									break;
								}
							}
						}
					}else {
						cout << "NIM Tidak Ditemukan, Mohon Untuk Registrasi";
						goto menu;
					}
		   			
			}else{	
				cout << "\n\nBelum ada data, mohon lakukan registrasi\n\n";
				goto menu;
			}
    		
			break;
    		
			
    		
    	
    	case '2':
    		fp = fopen("mahasiswa.txt", "rb+");
			fseek(fp, 0 , SEEK_END);
			
			cout << "\n\nMasukkan Nama Anda : ";
    		cin >>  e.nama;
    		cout << "Masukkan NIM Anda : ";
    		cin >>  e.nim;
    		cout << "Masukkan Paswword Anda : ";
    		cin >>  e.password;
			fwrite(&e, recsize,1, fp);
			fflush(stdin);
			
			
			
			cout << "\n";
			cout << "==== Berhasil Register, silahkan login kembali ====\n";
			cout << "\n";
			system("pause");
    		break;
    	
    	case '3':
    		cout << "\n\n====== bye ======\n\n" ;
    		break;
    	
    	default:
    		cout << "\n\n====== bye ======\n\n" ;
    		break;
	}
    		
    
}




