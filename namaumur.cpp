#include <stdio.h>
#include<conio.h>
typedef int angka;
typedef float pecahan;
typedef char huruf;
int main(){
    angka umur;
    pecahan pecah;

    huruf h;

    huruf nama[100];
    printf("masuka umur anda : ");scanf("%d",&umur);
    printf("umur anda adalah : %d",umur);
    printf("\nmasukan bilangan pecahan: ");scanf("%f",&pecah);
    printf("\n pecahan anda : %f",pecah);
    printf("\n masukan hurug");h=getche();
    printf("Huruf anda adalah : %c",h);
    printf("\n masukan nama anda : ");scanf("%s",nama);
    printf("Nama anda %s",nama);
    getch;

}