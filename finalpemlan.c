#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int index_data=0;
int jenis_kendaraan;
int tujuan1;
void sort();

//ini struct
struct data 
{
	int nomortiket;
	int bobot;
	char tujuan[20];
	//ini nesting struct
	struct 
	{
		int tgl,bln,thn;
	}date;	
	//ini nesting struct
	struct 
	{
		char jenis[10],nopol[20];
	}kendaraan;
};
typedef struct data tiket;
	tiket masuk[50];

//void buat namabh data
void tambahdata()
{
	int a;
	char x[20];
	printf("Masukkan Nomor Tiket : ");
	scanf("%d",&masuk[index_data].nomortiket);
	fflush(stdin);
	printf("Masukkan Tanggal Masuk kendaraan : ");
	scanf("%d",&masuk[index_data].date.tgl);
	fflush(stdin);
	printf("Masukkan Bulan Masuk Kendaraan : ");
	scanf("%d",&masuk[index_data].date.bln);
	fflush(stdin);
	printf("Masukkan Tahun Masuk Kendaraan : ");
	scanf("%d",&masuk[index_data].date.thn);
	fflush(stdin);
	printf("Masukkan Nomor Kendaraan (NOPOL) : ");
	gets(x);
	strcpy(masuk[index_data].kendaraan.nopol, x);
	fflush(stdin);
	printf("Jenis Kendaraan : \n");
	printf("1. Truk\n");
	printf("2. Bus\n");
	printf("3. Minibus\n");
	printf("4. Motor\n");
	printf("5. Mobil\n");
	printf("Masukkan Jenis Kendaraan : ");
	scanf("%d",&jenis_kendaraan);
	fflush(stdin);
	if (jenis_kendaraan == 1)
	{
		strcpy (masuk[index_data].kendaraan.jenis,"Truk");
	} else if (jenis_kendaraan == 2)
	{
		strcpy (masuk[index_data].kendaraan.jenis,"Bus");
	} else if (jenis_kendaraan == 3) 
	{
		strcpy (masuk[index_data].kendaraan.jenis,"Minibus");
	} else if (jenis_kendaraan == 4)
	{
		strcpy (masuk[index_data].kendaraan.jenis,"Motor");
	} else if (jenis_kendaraan == 5)
	{
		strcpy (masuk[index_data].kendaraan.jenis,"Mobil");
	} 
//   else {
//		system("cls");
//		printf("Input salah. Masukkan ulang!!\n");
//		tambahdata();
//	}
	printf("Tujuan yang Tersedia : \n");
	printf("1. Ketapang\n");
	printf("2. Padang Bai\n");
	printf("3. Lembar\n");
	printf("4. Tanjung Perak\n");
	printf("Masukkan Tujuan : ");
	scanf("%d",&tujuan1);
	if (tujuan1 == 1)
	{
		strcpy (masuk[index_data].tujuan,"Ketapang");
	} else if (tujuan1 == 2)
	{
		strcpy (masuk[index_data].tujuan,"Padang Bai");
	} else if (tujuan1 == 3) 
	{
		strcpy (masuk[index_data].tujuan,"Lembar");
	} else if (tujuan1 == 4)
	{
		strcpy (masuk[index_data].tujuan,"Tanjung Perak");
	} 
	 // else {
//		system("cls");
//		printf("Input salah. Masukkan ulang!!\n");
//		tambahdata();
//	}
	printf("Masukkan Bobot Kendaraan : ");
	scanf("%d",&masuk[index_data].bobot);
	index_data=index_data+1;
	
	if(index_data>=2){
		for(a=0;a<index_data-1;a++){
			if (masuk[index_data-1].nomortiket == masuk[a].nomortiket){
				printf("Nomor tiket telah dimasukkan!!!");
				masuk[a] = masuk[a-1];
				break;	
			}
		}
	}
}
