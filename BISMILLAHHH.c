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
