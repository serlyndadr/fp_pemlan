#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int index_data=0;
int jenis_kendaraan;
int tujuan1;
void sort();
void sortb();

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
 	fflush(stdin);
 	
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
      	else if (masuk[tengah].nomortiket > cari){
        	akhir = tengah - 1;
    	}
    	tengah = (awal + akhir)/2;
   }
   
	if (awal > akhir)
		printf("DATA DENGAN NOMOR TIKET %d TELAH DITEMUKAN.\n", cari);
}
void caribobot(){
	//int cari;
	int awal = 0;
	int akhir = index_data;
	int tengah = (awal+akhir)/2;
 	int cari;
 	sortb();
 	printf("Masukkan bobot yang dicari : ");
 	scanf("%d",&cari);
 	fflush(stdin);
 	int ketemu=0;
 	int nilai=0;
 	int b;      
 			
		   for(b=0;b<index_data;b++){
            tengah = (awal + akhir)/2;
            if(masuk[tengah].bobot == cari)
            {
                  ketemu = 1;
        		  printf("=================================================\n");
				  printf("		Data Penumpang\n");
				  printf("=================================================\n");
				  printf("Nomor Tiket : %d\n", masuk[tengah].nomortiket);
				  printf("Tanggal Masuk : %d / %d  / %d\n", masuk[tengah].date.tgl, masuk[tengah].date.bln, masuk[tengah].date.thn);
				  printf("Nomor Kendaraan : %s \n", masuk[tengah].kendaraan.nopol);
				  printf("Tujuan : %s \n", masuk[tengah].tujuan);
				  printf("Jenis Kendaraan : %s\n", masuk[tengah].kendaraan.jenis);
				  printf("Bobot Kendaraan : %d ton\n\n\n", masuk[tengah].bobot);
				  nilai=nilai+1;
                  continue;
            }
            else if(masuk[tengah].bobot<cari){
            	  awal = tengah+1;	
			}
            else{
            	  akhir = tengah-1;	
			}
      	}

		if(ketemu != 1){
			printf("BOBOT %d TON DITEMUKAN\n\n");
		}else {
			printf("DATA DITEMUKAN !!!\n\n",nilai);
		}
 //  	printf("%d",cari[y]);

}
void carinopol(){
	char cari [20];
	int awal = 0;
	int akhir = index_data;
	int tengah = (awal+akhir)/2;
 	
 	printf("Masukkan Nopol yang dicari : ");
 	fflush(stdin);
 	gets(cari);
 	
	while(awal<=akhir)
	{
    	if (strcmp(masuk[tengah].kendaraan.nopol , cari)<0)
    	{
    		awal = tengah + 1;    
    	}
		else if (strcmp(masuk[tengah].kendaraan.nopol,cari)>=0)
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
      	else if (masuk[tengah].kendaraan.nopol > cari){
        	akhir = tengah - 1;
    	}
    	tengah = (awal + akhir)/2;
   }
   
	if (awal > akhir)
		printf("NOMOR KENDARAAN TIDAK DITEMUKAN !!!.\n\n", cari);
}


//untuk ubah data
void ubah()
{
	int cari;
	char x[20];
	int awal = 0;
	int akhir = index_data;
	int tengah = (awal+akhir)/2;
	lihatdata();
	sort();
	printf("Masukkan Nomor tiket yang akan diubah datanya : ");
	scanf("%d",&cari);
	fflush(stdin);
	
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
					printf("Masukkan Nomor Tiket : ");
					scanf("%d",&masuk[tengah].nomortiket);
					printf("Masukkan Tanggal Masuk kendaraan : ");
					scanf("%d",&masuk[tengah].date.tgl);
					printf("Masukkan Bulan Masuk Kendaraan : ");
					scanf("%d",&masuk[tengah].date.bln);
					fflush(stdin);
					printf("Masukkan Tahun Masuk Kendaraan : ");
					scanf("%d",&masuk[tengah].date.thn);
					fflush(stdin);
					printf("Masukkan Nomor Kendaraan (NOPOL) : ");
					gets(x);
					strcpy(masuk[tengah].kendaraan.nopol, x);
					fflush(stdin);
					printf("Jenis Kendaraan : \n");
					printf("1. Truk\n");
					printf("2. Bus\n");
					printf("3. Minibus\n");
					printf("4. Motor\n");
					printf("5. Mobil\n");
					printf("Masukkan Jenis Kendaraan : ");
					scanf("%d",&jenis_kendaraan);
					if (jenis_kendaraan == 1)
					{
						strcpy (masuk[tengah].kendaraan.jenis,"Truk");
					} else if (jenis_kendaraan == 2)
					{
						strcpy (masuk[tengah].kendaraan.jenis,"Bus");
					} else if (jenis_kendaraan == 3) 
					{
						strcpy (masuk[tengah].kendaraan.jenis,"Minibus");
					} else if (jenis_kendaraan == 4)
					{		
						strcpy (masuk[tengah].kendaraan.jenis,"Motor");
					} else if (jenis_kendaraan == 5)
					{
						strcpy (masuk[tengah].kendaraan.jenis,"Mobil");
					}
					printf("Tujuan yang Tersedia : \n");
					printf("1. Ketapang\n");
					printf("2. Padang Bai\n");
					printf("3. Lembar\n");
					printf("4. Tanjung Perak\n");
					printf("Masukkan Tujuan : ");
					scanf("%d",&tujuan1);
					if (tujuan1 == 1)
					{	
						strcpy (masuk[tengah].tujuan,"Ketapang");
					} else if (tujuan1 == 2)
					{
						strcpy (masuk[tengah].tujuan,"Padang Bai");
					} else if (tujuan1 == 3) 
					{
						strcpy (masuk[tengah].tujuan,"Lembar");
					} else if (tujuan1 == 4)
					{
						strcpy (masuk[tengah].tujuan,"Tanjung Perak");
					} 
					printf("Masukkan Bobot Kendaraan : ");
					scanf("%d",&masuk[tengah].bobot);
			
					printf("Data Sudah Diperbarui!!!!!!\n\n");
        			break;
      		}
      		else if (masuk[tengah].nomortiket > cari){
        		akhir = tengah - 1;
    		}	
    		tengah = (awal + akhir)/2;
   }
   
	if (awal > akhir)
		printf("Data %d tidak ditemukan.\n", cari);
	}
//sorting berdasarkan abjad tujuan
void sorttujuan()
{
	int n,a,bc,x;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m=n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
				bc=strcmp(masuk[i+m].tujuan,masuk[i].tujuan);
                if(bc>0){
                	break;
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }

    	printf("================================================\n");
	 	printf("		DATA YANG DIURUTKAN\n");
	 	printf("	  Berdasarkan Tujuan\n");
	 	printf("================================================\n\n");
	 	
		lihatdata(); 
}

//sorting berdasarkan nomor tiket
void sort()
{
	int n,a;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
                if(masuk[i+m].nomortiket>=masuk[i].nomortiket) 
				break;
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }
}

//sorting berdasarkan nomor tiket
void sorttiket()
{
	int n,a;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
                if(masuk[i+m].nomortiket>=masuk[i].nomortiket) 
				break;
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }
    
    	printf("************************************************\n");
	 	printf("		DATA YANG DIURUTKAN\n");
	 	printf("	  Berdasarkan Nomor Tiket\n");
	 	printf("************************************************\n\n");
	 	
	 
		lihatdata();
}

// sorting tanggal

void sortdate(){
	int n;
	n = index_data;
	int m,j,i;
	
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
                if(masuk[i+m].date.thn >= masuk[i].date.thn && masuk[i+m].date.bln >= masuk[i].date.bln && masuk[i+m].date.tgl >= masuk[i].date.tgl){
                	break;
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }
    printf("***********************************************\n");
	printf("		DATA YANG DIURUTKAN\n");
	printf("	  Berdasarkan Tanggal Masuk\n");
	printf("***********************************************\n\n");
	 	lihatdata();
	 	
}
// sorting nomor kendaraan
void sortnopol(){
	int n,a,bc;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
				bc=strcmp(masuk[i+m].kendaraan.nopol,masuk[i].kendaraan.nopol);
                if(bc>0) 
				{
                break;	
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }	
    

    printf("================================================\n");
	printf("		DATA YANG DIURUTKAN\n");
	printf("	  Berdasarkan Nomor Kendaraan\n");
	printf("================================================\n\n");
	 	
		lihatdata(); 
}

void sortjeniskendaraan(){
	int n,a,bc;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
				bc=strcmp(masuk[i+m].kendaraan.jenis,masuk[i].kendaraan.jenis);
                if(bc>0) 
				{
                break;	
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }	
    

    printf("================================================\n");
	printf("		DATA YANG DIURUTKAN\n");
	printf("	  Berdasarkan Jenis Kendaraan\n");
	printf("================================================\n\n");
	 	
		lihatdata(); 
}
void sortb(){
	int n,a;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
                if(masuk[i+m].bobot>=masuk[i].bobot) 
				{
                break;	
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }	
    
}

//sorting bobot kendaraan
void sortbobot()
{
	int n,a;
	a = index_data;
	n = a;
	int m,j,i;
	struct data temp;
	 
    for(m = n/2;m>0;m/=2)
	{
        for(j=m;j<n;j++)
		{
            for(i=j-m;i>=0;i-=m)
			{
                if(masuk[i+m].bobot>=masuk[i].bobot) 
				{
                break;	
				}
                else{
                    temp = masuk[i];
                    masuk[i] = masuk[i+m];
                    masuk[i+m] = temp;
                }
            }
        }
    }	
    

    printf("================================================\n");
	printf("		DATA YANG DIURUTKAN\n");
	printf("	  Berdasarkan Bobot Kendaraan\n");
	printf("================================================\n\n");
	 	
		lihatdata(); 
}

//main

void tampilanawal(){
system("color 70");
printf(" \t\t\t\t========================================\n");
printf("\t\t\t\t|  SELAMAT DATANG DI APLIKASI PELABUHAN\t| \n");
printf("\t\t\t\t|_______________________________________| \n");
printf("\t\t\t\t|SERLYNDA DWI ROSALINA	(18081010010)\t| \n");
printf("\t\t\t\t|MELANIA SYAFRIDA P     (18081010011) \t| \n");
printf(" \t\t\t\t========================================\n");
	
}

void menuawal(){
system("color 0B");
	int pilihan,pilih;

	while (pilihan != 1 || pilihan != 2 || pilihan != 3 || pilihan != 4 || pilihan != 5)
	{		

printf("\n **************************************\n");
printf("|          MENU UTAMA                  |\n");
printf(" **************************************\n");
printf("(1. Tambah data                        )\n");
printf("(2. Ubah Data                          )\n");
printf("(3. Pengurutan Data                    )\n");
printf("(4. Pencarian Data                     )\n");
printf("(5. Lihat Data                         )\n");
printf("(6. EXIT                               )\n");
printf(" **************************************\n");
printf("Masukkan Pilihan Anda : ");
scanf("%d", &pilihan);
	
	
		if (pilihan == 1)
		{
			system("cls");
			tambahdata();
		} else if (pilihan == 2)
		{
			system("cls");
			ubah();
		}
		else if (pilihan == 3)
		{
			printf("\n\n1. Pengurutan Data Berdasarkan Nomor Tiket\n");
			printf("2. Pengurutan Data Berdasarkan Tanggal\n");
			printf("3. Pengurutan Data Berdasarkan Bobot Kendaraan\n");
			printf("4. Pengurutan Data Berdasarkan Tujuan\n");
			printf("5. Pengurutan Data Berdasarkan Jenis Kendaraan\n");
			printf("6. Pengurutan Data Berdasarkan Nomor Kendaraan\n");
			printf("Masukkan Pilihan Anda : ");
			scanf("%d",&pilih);
			fflush(stdin);
			
					if (pilih == 1)
					{
						sorttiket();
					}else if (pilih == 2)
					{
		 				sortdate();
					}else if (pilih == 3)
					{
						sortbobot();
					}else if (pilih == 4)
					{
					sorttujuan();
					}else if (pilih == 5){
						sortjeniskendaraan();
					}
					else if (pilih == 6){
						sortnopol();
					}
		}
		else if (pilihan == 4)
		{
				printf("\n\n1. Pencarian Data Berdasarkan Nomor Tiket\n");
				printf("2. Pencarian Data Berdasarkan Bobot Kendaraan\n");
				printf("3. Pencarian Data Berdasarkan Nomor Kendaraan\n");
				printf("Masukkan Pilihan Anda : ");
				scanf("%d",&pilih);
				fflush(stdin);
				if (pilih == 1){
				caritiket();
				}
				else if (pilih==2){
				caribobot();
				}
				else if (pilih==3){
				carinopol();
				}
		}
		else if (pilihan == 5) 
		{
				lihatdata();
		}
		else if (pilihan == 6)
		{
			printf("\n\n\n_______________________________________________________________________\n");
			printf("[-[-[-[-[-[ TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI ]-]-]-]-]-]\n");
			printf("_______________________________________________________________________\n");
			break;
		}
	}
}
int main() 
{
	tampilanawal();
	printf("PLEASE ENTER TO CONTINUE :))))");
	getch();
	system("cls");
	menuawal();
	return 0;
}
	
