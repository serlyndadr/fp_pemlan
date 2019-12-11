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
	
	int j,i;
    for(i = 0; i < index_data; i++) {
    	for(j = i + 1; j < index_data; j++){
    		if(masuk[i].nomortiket == masuk[j].nomortiket) {
    			printf("================= DATA SUDAH ADA! ====================");
    			index_data=index_data-1;
			}	
		}

	}
}

//buat lihat data
void lihatdata()
{
	system("color 0a");
	int i;
	if (index_data == 0)
	{
		printf("Data Penumpang Kosong\n\n");
	}else 
	{
		for(i=0;i<index_data;i++)
		{
			if (masuk[i].nomortiket==0){
				printf("   ");
			}else {
				printf("=================================================\n");
				printf("		Data Penumpang\n");
				printf("=================================================\n");
				printf("Nomor Tiket : %d\n", masuk[i].nomortiket);
				printf("Tanggal Masuk : %d / %d  / %d\n", masuk[i].date.tgl, masuk[i].date.bln, masuk[i].date.thn);
				printf("Nomor Kendaraan : %s \n", masuk[i].kendaraan.nopol);
				printf("Tujuan : %s \n", masuk[i].tujuan);
				printf("Jenis Kendaraan : %s\n", masuk[i].kendaraan.jenis);
				printf("Bobot Kendaraan : %d ton\n\n\n", masuk[i].bobot);	
			}
		}
	}
}
//pencarian berdasarkan nomor tiket
void caritiket(){
	int cari;
	int awal = 0;
	int akhir = index_data;
	int tengah = (awal+akhir)/2;
 	
	printf("************************************************\n");
	printf("		PENCARIAN NOMOR TIKET\n");
	printf("************************************************\n");
 	
 	printf("Masukkan Nomor tiket yang dicari : ");
 	scanf("%d",&cari);
 	
	while(awal<=akhir)
	{
    	if (masuk[tengah].nomortiket < cari)
    	{
    		awal = tengah + 1;    
    	}
		else if (masuk[tengah].nomortiket == cari) 
		{
        	printf("=================================================\n");
			printf("		Data Penumpang\n");
			printf("=================================================\n");
			printf("Nomor Tiket : %d\n", masuk[tengah].nomortiket);
			printf("Tanggal Masuk : %d / %d  / %d\n", masuk[tengah].date.tgl, masuk[tengah].date.bln, masuk[tengah].date.thn);
			printf("Nomor Kendaraan : %s \n", masuk[tengah].kendaraan.nopol);
			printf("Tujuan : %s \n", masuk[tengah].tujuan);
			printf("Jenis Kendaraan : %s\n", masuk[tengah].kendaraan.jenis);
			printf("Bobot Kendaraan : %d ton\n\n\n", masuk[tengah].bobot);
        	break;
      	}
      	else{
        	akhir = tengah - 1;
    	}
    	tengah = (awal + akhir)/2;
   }
   
	if (awal > akhir)
		printf("Data %d tidak ditemukan.\n", cari);
}
void caribobot(){
	int cari;
	int awal = 0;
	int akhir = index_data;
	int tengah = (awal+akhir)/2;
 	
 	printf("Masukkan bobot yang dicari : ");
 	scanf("%d",&cari);
 	
	while(awal<=akhir)
	{
    	if (masuk[tengah].bobot < cari)
    	{
    		awal = tengah + 1;    
    	}
		else if (masuk[tengah].bobot == cari) 
		{
        	printf("=================================================\n");
			printf("		Data Penumpang\n");
			printf("=================================================\n");
			printf("Nomor Tiket : %d\n", masuk[tengah].nomortiket);
			printf("Tanggal Masuk : %d / %d  / %d\n", masuk[tengah].date.tgl, masuk[tengah].date.bln, masuk[tengah].date.thn);
			printf("Nomor Kendaraan : %s \n", masuk[tengah].kendaraan.nopol);
			printf("Tujuan : %s \n", masuk[tengah].tujuan);
			printf("Jenis Kendaraan : %s\n", masuk[tengah].kendaraan.jenis);
			printf("Bobot Kendaraan : %d ton\n\n\n", masuk[tengah].bobot);
        	break;
      	}
      	else{
        	akhir = tengah - 1;
    	}
    	tengah = (awal + akhir)/2;
   }
   
	if (awal > akhir)
		printf("Data %d tidak ditemukan.\n", cari);
}