#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct admin
{
	char user[50],pass[50];
} adm;

struct mahasiswa
{
	char user[50],pass[50];
	int nimlog;
} mhs;

struct dosen
{
	char user[50],pass[50];
	int niklog;
} dsn;

struct data
{ 
	char name_mhs[100],mail_mhs[50],ttl_mhs[50],ktp_mhs[50],ayh[50],ibu[50],jrsn[50],almt_mhs[100],user_mhs[100],pass_mhs[100],matkul[100],kls_mhs[100];
	char name_dsn[100],mail_dsn[50],ttl_dsn[50],ktp_dsn[50],almt_dsn[100],sbjk_dsn[50],pndk_dsn[50],user_dsn[100],pass_dsn[100],kls_dsn[100];
	char nm[100],ttl[100],em[100],un[100],pass[100],acc[100];
	int nim,nik,telp_dsn,telp_mhs,sdr,sks,nilai; 
};
struct data d[100];

int i,j,n,a,hapus,f,b[25],nomat,nimnil;

char yeno[4],un[100],pass[100];

void menu();
void adm_login(),adm_menu(),adm_dftr_mhs(),adm_tmbh_mhs(),adm_hps_mhs(),adm_dftr_dsn(),adm_tmbh_dsn(),adm_hps_dsn();
void mhslogin(),mhsmenu(),mhsregis(),mhslook();
void dosen(),dsnrgr(),dsnlgn(),dsnlook();



main()
{
	system("title KARTU RENCANA STUDI");
	system("color 0a");
	menu();
}

void menu()
{
	do
	{
	
		printf("\n--- Kartu Rencana Studi ---\n\n");
		printf(" 1. Admin\n");
		printf(" 2. Dosen\n");
		printf(" 3. Mahasiswa\n");
		printf(" 4. EXIT\n\n");

		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1: adm_login();break;
			case 2: dosen();break;
			case 3: mhsmenu();break;
			case 4: printf("\n Thank You!\n\n");system("pause");system("exit");break;
			default : printf("Wrong Input");system("cls");break;
		}
	}
	while(a!=4);
}


//ADMIN
void adm_login()
{
	printf("\n--- Login Admin ---\n\n");
	printf(" Username\t: ");gets(adm.user);
	printf(" Password\t: ");gets(adm.pass);
	
	if(strcmp(adm.user,"admin")==0 && strcmp(adm.pass,"admin")==0)
	{
		system("cls");
		printf("\n Welcome, admin!");getchar();system("cls");
		adm_menu();
	}
	else return adm_login();
}

void adm_menu()
{
	do
	{
		printf("\n--- Menu Admin ---\n\n");
		printf(" 1. Mahasiswa\n");
		printf(" 2. Dosen\n");
		printf(" 3. Log Out\n\n");
		
		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1: 
			{	
				do
				{
					printf("\n--- Menu Admin\t: Mahasiswa ---\n\n");
					printf(" 1. Daftar Mahasiswa\n");
					printf(" 2. Tambah Mahasiswa\n");
					printf(" 3. Hapus Mahasiswa\n");
					printf(" 9. Back\n\n");
				
					printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
					system("cls");
					
					switch(a)
					{
						case 1: adm_dftr_mhs();system("cls");break;
						case 2: adm_tmbh_mhs();system("cls");break;
						case 3: adm_hps_mhs();system("cls");break;
						case 9: return adm_menu();break;
						default: printf("Wrong Input");system("cls");break;
					}
				}
				while(a!=9);	
			} break;
			
			case 2:
			{
				do
				{
					printf("\n--- Menu Admin\t: Dosen ---\n\n");
					printf(" 1. Daftar Dosen\n");
					printf(" 2. Tambah Dosen\n");
					printf(" 3. Hapus Dosen\n");
					printf(" 9. Back\n\n");
				
					printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
					system("cls");
					
					switch(a)
					{
						case 1: adm_dftr_dsn();system("cls");break;
						case 2: adm_tmbh_dsn();system("cls");break;
						case 3: adm_hps_dsn();system("cls");break;
						case 9: return adm_menu();break;
						default: printf("Wrong Input");system("cls");break;
					}
				}
				while(a!=9);
			} break;
			
			case 3:
			{
				printf("\n Thank You!");getchar();
				printf(" Back to Main menu? ");gets(yeno);system("cls");
				if(strcmp(yeno,"Y")==0 || strcmp(yeno,"y")==0 || strcmp(yeno,"YES")==0 || strcmp(yeno,"yes")==0 || strcmp(yeno,"Yes")==0)
				{	main();	}
				else system("exit");	
			} break;
			
			default: printf("Wrong Input");system("cls");break;
		}
	}
	while(a!=3);
}

void adm_dftr_mhs()
{
	FILE *f_dftrmhs; 
	f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
	printf("\n--- Menu Admin\t: Daftar Mahasiswa ---\n\n");
	j=1;
	while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1) 
	{ 
		printf("%i. NIM                 : %i\n",				j,d[i].nim); 
		printf("    Kelas              : %s\n",			d[i].kls_mhs);
		printf("    Nama               : %s\n",			d[i].name_mhs);
		printf("    TTL                : %s\n",			d[i].ttl_mhs);
		printf("    e-Mail             : %s\n",			d[i].mail_mhs);
		printf("    No. KTP            : %s\n",		d[i].ktp_mhs);
		printf("    No. Telp           : %i\n",		d[i].telp_mhs);
		printf("    Jurusan            : %s\n",		d[i].jrsn);
		printf("    Nama orangtua   \n");
		printf("     Ayah              : %s\n",			d[i].ayh);
		printf("     Ibu               : %s\n",			d[i].ibu);
		printf("    Jumlah saudara     : %i\n",	d[i].sdr);
		printf("    Alamat             : %s\n\n",		d[i].almt_mhs);
		j++;
	} 
	fclose(f_dftrmhs);
	
	system("pause");
}

void adm_tmbh_mhs()
{
	FILE *f_tmbhmhs; 
	f_tmbhmhs=fopen("Daftar Mahasiswa.dat","ab+");
	printf("\n--- Menu Admin\t: Tambah Mahasiswa ---\n\n");
	printf(" Banyak data mahasiswa yang ditambah: ");scanf("%i",&n);fflush(stdin);
	printf("\n");
	for (i=1;i<=n;i++) 
	{ 
		printf("Mahasiswa %i\n",i);
		printf(" Nama        : ");	gets(d[i].name_mhs); 
		printf(" NIM         : ");		scanf("%i",&d[i].nim);fflush(stdin);
		printf(" Kelas       : ");	gets(d[i].kls_mhs);
		printf("\n");
		fwrite(&d[i],sizeof(d[i]),1,f_tmbhmhs); 
	}  
	fclose(f_tmbhmhs);
	
	system("pause");
}

void adm_hps_mhs()
{
	FILE *f_hpsmhs; 
	FILE *f_hpsmhs2;
	f_hpsmhs=fopen("Daftar Mahasiswa.dat","rb"); 
	f_hpsmhs2=fopen("Daftar Mahasiswa2.dat","ab+"); 
	printf("\n--- Menu Admin\t: Hapus Mahasiswa ---\n\n");
	printf(" Mahasiswa yang akan dihapus (NIM) : "); fflush(stdin);scanf("%i",&hapus);  
	while (fread(&d[i],sizeof(d[i]),1,f_hpsmhs)==1) 
	{ 
		if (d[i].nim!=hapus) 
		{
			fwrite(&d[i],sizeof(d[i]),1,f_hpsmhs2); 
		} 
	} 
	fclose(f_hpsmhs); fclose(f_hpsmhs2); 
	remove("Daftar Mahasiswa.dat"); 
	rename("Daftar Mahasiswa2.dat","Daftar Mahasiswa.dat");  
	
	printf("\n\n\xB1 Done! \xB3\n\n");
	system("pause");
}

void adm_dftr_dsn()
{
	FILE *f_dftrdsn; 
	f_dftrdsn=fopen("Daftar Dosen.dat","rb"); 
	printf("\n--- Menu Admin\t: Daftar Dosen Wali ---\n\n");
	i=1;
	while (fread(&d[i],sizeof(d[i]),1,f_dftrdsn)==1) 
	{ 
		printf("%i. NIK                      : %i\n",						i,d[i].nik); 
		printf("    Nama                    : %s\n",					d[i].name_dsn);
		printf("    TTL                     : %s\n",				d[i].ttl_dsn);
		printf("    e-Mail                  : %s\n",				d[i].mail_dsn);
		printf("    No. KTP                 : %s\n",				d[i].ktp_dsn);
		printf("    No. Telp                : %i\n",				d[i].telp_dsn);
		printf("    Alamat                  : %s\n",				d[i].almt_dsn);
		printf("    Pendidikan terakhir     : %s\n",	d[i].pndk_dsn);
		printf("    Kelas yang diwakilkan   : %s\n\n",	d[i].kls_dsn);
		i++;
	} 
	fclose(f_dftrdsn);
	
	system("pause");
}

void adm_tmbh_dsn()
{
	FILE *f_tmbhdsn; 
	f_tmbhdsn=fopen("Daftar Dosen.dat","ab+");
	printf("\n--- Menu Admin\t: Tambah Dosen Wali ---\n\n");
	printf("Banyak data dosen yang ditambah: ");scanf("%i",&n);fflush(stdin);
	for (i=1;i<=n;i++) 
	{ 
		printf("\n");
		printf(" Nama                  : ");				gets(d[i].name_dsn); 
		printf(" NIK                   : ");					scanf("%i",&d[i].nik);fflush(stdin);
		printf(" Kelas yang diwakilkan : ");	gets(d[i].kls_dsn);
		printf("\n");
		fwrite(&d[i],sizeof(d[i]),1,f_tmbhdsn); 
	}  
	fclose(f_tmbhdsn);
	
	system("pause");
}

void adm_hps_dsn()
{
	FILE *f_hpsdsn; 
	FILE *f_hpsdsn2;
	f_hpsdsn=fopen("Daftar Dosen.dat","rb"); 
	f_hpsdsn2=fopen("Daftar Dosen2.dat","ab+"); 
	printf("\n--- Menu Admin\t: Hapus Dosen ---\n\n");
	printf("Dosen yang akan dihapus (NIK) : "); fflush(stdin);scanf("%i",&hapus);  
	while (fread(&d[i],sizeof(d[i]),1,f_hpsdsn)==1) 
	{ 
		if (d[i].nik!=hapus) 
		{
			fwrite(&d[i],sizeof(d[i]),1,f_hpsdsn2); 
		} 
	} 
	fclose(f_hpsdsn); fclose(f_hpsdsn2); 
	remove("Daftar Dosen.dat"); 
	rename("Daftar Dosen2.dat","Daftar Dosen.dat");  
	
	printf("\n\n\xB2 Done! \xB4\n\n");
	system("pause");
}


//MAHASISWA
void mhsmenu()
{
	do
	{
		printf("\n--- Menu Mahasiswa ---\n\n");
		printf(" 1. Login\n");
		printf(" 2. Registrasi\n");
		printf(" 3. Log Out\n\n");
		
		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1:mhslogin();system("cls");break;
			case 2:mhsregis();system("cls");break;
			case 3:
			{
				printf("\n Thank You!");getchar();
				printf(" Back to Main menu? ");gets(yeno);system("cls");
				if(strcmp(yeno,"Y")==0 || strcmp(yeno,"y")==0 || strcmp(yeno,"YES")==0 || strcmp(yeno,"yes")==0 || strcmp(yeno,"Yes")==0)
				{	main();	}
				else system("exit");	
			} break;
			default:printf("Wrong Input");system("cls");break;
		}
	}
	while(a!=3);
}

void mhsregis()
{
		printf("\n--- Menu Mahasiswa : Registrasi Mahasiswa ---\n\n");
		printf(" Masukkan NIM: ");scanf("%i",&mhs.nimlog);fflush(stdin);
		system("cls");
					
		FILE *f_dftrmhs; 
		FILE *f_dftrmhs2;
		f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
		f_dftrmhs2=fopen("Daftar Mahasiswa2.dat","ab+"); 
		while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1) 
		{
			if(d[i].nim != mhs.nimlog)
			{
				fwrite(&d[i],sizeof(d[i]),1,f_dftrmhs2);
			}
			else
			{ 
				printf("\n--- Menu Mahasiswa : Registrasi Mahasiswa ---\n\n");
				printf("  NIM               : %i\n",				d[i].nim);
				printf("  Kelas             : %s\n",		d[i].kls_mhs);
				printf("  Nama              : ");			gets(d[i].name_mhs);
				printf("  TTL               : ");			gets(d[i].ttl_mhs);
				printf("  e-Mail            : ");			gets(d[i].mail_mhs);
				printf("  No. KTP           : ");			gets(d[i].ktp_mhs);
				printf("  No. Telp          : ");			scanf("%i",&d[i].telp_mhs);fflush(stdin);
				printf("  Jurusan           : ");			gets(d[i].jrsn);
				printf("  Nama Orangtuan: \n");
				printf("   Ayah             : ");			gets(d[i].ayh);
				printf("   Ibu              : ");				gets(d[i].ibu);
				printf("  Jumlah saudara/i  : ");	scanf("%i",&d[i].sdr);fflush(stdin);
				printf("  Alamat            : ");			gets(d[i].almt_mhs);
				printf("\n  Silahkan isi username dan password akun \n");
				printf("   Username\t: ");	gets(d[i].user_mhs);
				printf("   Password\t: ");	gets(d[i].pass_mhs);
		
				fwrite(&d[i],sizeof(d[i]),1,f_dftrmhs2); 
			
				printf("\n\n");
				system("pause");system("cls");
				printf("\n Selamat Anda telah melakukan registrasi!!");getchar();
				printf("\n\n");
			}
		}
		fclose(f_dftrmhs); fclose(f_dftrmhs2); 
		remove("Daftar Mahasiswa.dat"); 
		rename("Daftar Mahasiswa2.dat","Daftar Mahasiswa.dat");
							
		system("pause");						
}

void mhslogin()
{
	FILE*f_dftrmhs;
	f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
	printf("\n--- Menu Mahasiswa : Login Mahasiswa ---\n\n");
	printf(" Username\t: ");gets(mhs.user);
	printf(" Password\t: ");gets(mhs.pass);
	
	while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1) 
	{
		if(strcmp(d[i].user_mhs,mhs.user)==0 && strcmp(d[i].pass_mhs,mhs.pass)==0)
		{
			system("cls");
			printf("\n Welcome, %s!",d[i].name_mhs);getchar();
			system("cls");mhslook();
		}
		else 
		{
			if(strlen(d[i].user_mhs)==i && strlen(d[i].pass_mhs)==i)
			{
				printf ("\n  Login Gagal \n  Username dan password yang anda masukan salah");getchar();
				system("cls");dsnlgn();
				main();
			}
			else
			{
				i++;
			}
		}
	}
	fclose(f_dftrmhs);
}

void mhslook()
{
	do
	{
		printf("\n--- Menu Mahasiswa ---\n\n");
		printf(" 1. Lihat Profil Mahasiswa\n");
		printf(" 2. Input KRS\n");
		printf(" 3. Status KRS\n");
		printf(" 4. Lihat Nilai dan IPK\n");
		printf(" 5. Log Out\n\n");
		
		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1: 
			{
				FILE *f_dftrmhs; 
				f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
				printf("\n--- Menu Mahasiswa : Profil Mahasiswa ---\n\n");
				while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1) 
				{ 
					if(strcmp(d[i].user_mhs,mhs.user)==0 && strcmp(d[i].pass_mhs,mhs.pass)==0)
					{
						printf("  NIM                : %i\n",		d[i].nim); 
						printf("  Nama               : %s\n",		d[i].name_mhs);
						printf("  TTL                : %s\n",		d[i].ttl_mhs);
						printf("  e-Mail             : %s\n",		d[i].mail_mhs);
						printf("  No. KTP            : %s\n",		d[i].ktp_mhs);
						printf("  No. Telp           : %i\n",		d[i].telp_mhs);
						printf("  Jurusan            : %s\n",		d[i].jrsn);
						printf("  Nama orangtua\t \n");
						printf("   Ayah              : %s\n",		d[i].ayh);
						printf("   Ibu               : %s\n",		d[i].ibu);
						printf("  Jumlah saudara     : %i\n",		d[i].sdr);
						printf("  Alamat             : %s\n",		d[i].almt_mhs);
					}
				}
				printf("\n");
				system("pause");system("cls");
				fclose(f_dftrmhs);
			} break;
			
			case 2: 
			{
				int n;
				printf("\n--- Menu Mahasiswa : Input KRS ---\n\n");
				printf(" Daftar Mata Kuliah dan Bobot SKS\n");
				printf("-------------------------------------------------------\n");
				printf(" Bobot SKS: 4\n");
				printf("  1.  Kalkulus A\n");
				printf("  2.  Fisika A\n");
				printf("\n Bobot SKS: 3\n");
				printf("  3.  Kalkulus B\n");
				printf("  4.  Fisika B\n");
				printf("  5.  Pengantar Jurusan\n");
				printf("\n Bobot SKS: 2\n");
				printf("  6.  Bahasa Inggris\n");
				printf("  7.  Bahasa Indonesia\n");
				printf("  8.  Agama dan Etika\n");
				printf("  9.  Literasi TIK\n");
				printf("  10. Algoritma dan Pemograman\n");
				printf("\n Bobot SKS: 1\n");
				printf("  11. Praktikum Fisika Dasar\n");
				printf("  12. Praktikum Jurusan\n");
				printf("  13. Praktikum Pemrograman\n");
				printf("-------------------------------------------------------\n");
				printf(" SKS Maksimal\t: 24\n SKS Minimal\t: 18\n\n");
				
				FILE *f_matkulmhs; 
				f_matkulmhs=fopen("Mata Kuliah Mahasiswa.dat","wb+"); 
				printf(" Input jumlah mata kuliah yang akan diambil : ");scanf("%i",&nomat);fflush(stdin);
				printf("\n");
				
				j=1;
				if(strcmp(d[i].user_mhs,mhs.user)==0 && strcmp(d[i].pass_mhs,mhs.pass)==0)
				{
					for(i=1;i<=nomat;i++)
					{
						printf("  Masukkan mata kuliah ke-%i : ",j);gets(d[i].matkul);
						j++;
						fwrite(&d[i],sizeof (d[i]),1,f_matkulmhs);
					}
				}
				fclose(f_matkulmhs);
			
				printf("\n\n");
				system("pause");system("cls");
				
			} break;
			
			case 3:
			{
				FILE *f_matkulmhs;
				f_matkulmhs=fopen("Mata Kuliah Mahasiswa.dat","rb");
				printf("\n--- Menu Mahasiswa : Status KRS ---\n\n");
				if(strcmp(d[i].user_mhs,mhs.user)==0 && strcmp(d[i].pass_mhs,mhs.pass)==0) 
				{
					j=1;
					while (fread(&d[i],sizeof(d[i]),1,f_matkulmhs)==1)
					{
						printf(" Mata kuliah ke-%i   : %s \n",j,d[i].matkul);
						j++;
					}
					printf("\n  Status KRS  :  %s",d[i].acc);
				}
				fclose(f_matkulmhs);
				printf("\n\n");
				system("pause");system("cls");
			} break;
								
			
			case 4: 
			{
				FILE *f_nilaimhs; 
				f_nilaimhs=fopen("Nilai Mahasiswa.dat","rb"); 
				printf("\n--- Menu Mahasiswa : Nilai dan IPK ---\n\n");
				if(strcmp(d[i].user_mhs,mhs.user)==0 && strcmp(d[i].pass_mhs,mhs.pass)==0)
				{
					while (fread(&d[i],sizeof(d[i]),1,f_nilaimhs)==1) 
					{
						printf("\n%i. %s\n",j,d[j].matkul);
						printf("\tNilai : %i\n",d[i].nilai);
					}
				}
				printf("\n\n");
				system("pause");system("cls");
				fclose(f_nilaimhs);
			} break;
			
			case 5:
		 	{
		 		system("cls");break;
		 	}
		}
	}
	while(a!=5);
}


 //DOSEN
void dosen ()
{
	do
	{
		printf("\n--- Menu Dosen ---\n\n");
		printf(" 1. Login\n");
		printf(" 2. Registrasi\n");
		printf(" 3. Log Out\n\n");
		
		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1 : dsnlgn();system("cls");break;
			case 2 : dsnrgr();system("cls");break;
			case 3:
			{
				printf("\n Thank You!");getchar();
				printf(" Back to Main menu? ");gets(yeno);system("cls");
				if(strcmp(yeno,"Y")==0 || strcmp(yeno,"y")==0 || strcmp(yeno,"YES")==0 || strcmp(yeno,"yes")==0 || strcmp(yeno,"Yes")==0)
				{	main();	}
				else system("exit");	
			} break;
			default:printf("Wrong Input");system("cls");break;
		}
	}
	while(a!=3);
}

void dsnrgr()
{
	printf("\n--- Menu Dosen Wali : Registrasi ---\n\n");
	printf(" Masukkan NIK: ");scanf("%i",&dsn.niklog);fflush(stdin);
	system("cls");
	
	printf("\n--- Menu Dosen Wali : Registrasi ---\n\n");
	FILE *f_dftrdsn; 
	FILE *f_dftrdsn2;
	f_dftrdsn=fopen("Daftar Dosen.dat","rb"); 
	f_dftrdsn2=fopen("Daftar Dosen2.dat","ab+"); 
	while (fread(&d[i],sizeof(d[i]),1,f_dftrdsn)==1) 
	{
		if(d[i].nik != dsn.niklog)
		{
			fwrite(&d[i],sizeof(d[i]),1,f_dftrdsn2);
		}
		else
		{ 
			printf("  NIK                     : %i\n",		d[i].nik); 
			printf("  Kelas yang diwakilkan\t: %s\n",	d[i].kls_dsn);
			printf("  Nama                    : ");			gets(d[i].name_dsn);
			printf("  TTL                     : ");			gets(d[i].ttl_dsn);
			printf("  e-Mail                  : ");			gets(d[i].mail_dsn);
			printf("  No. KTP                 : ");			gets(d[i].ktp_dsn);
			printf("  No. Telp                : ");			scanf("%i",&d[i].telp_dsn);fflush(stdin);
			printf("  Alamat                  : ");			gets(d[i].almt_dsn);
			printf("  Pendidikan terakhir     : ");			gets(d[i].pndk_dsn);
			printf("\n  Silahkan isi username dan password untuk akun anda\n");
			printf("   Username : ");	gets(d[i].user_dsn);
			printf("   Password : ");	gets(d[i].pass_dsn);
			
			fwrite(&d[i],sizeof(d[i]),1,f_dftrdsn2);
		
			printf("\n\n");
			system("pause");system("cls");
			printf("\n Selamat Anda telah melakukan registrasi!!");getchar();
			printf("\n\n");
		}
	}
	fclose(f_dftrdsn);fclose(f_dftrdsn2); 
	remove("Daftar Dosen.dat"); 
	rename("Daftar Dosen2.dat","Daftar Dosen.dat");
							
	system("pause");						
}
	
void dsnlgn()
{
	FILE *f_dosen;  
	f_dosen=fopen("Daftar Dosen.dat","rb");
	printf("\n--- Menu Dosen Wali : Login ---\n\n");
	printf(" Silahkan masukan username dan password!\n");;
	printf("  Username\t: ");gets(dsn.user); 
	printf("  Password\t: ");gets(dsn.pass);
	
	while(fread(&d[i],sizeof (d[i]),1, f_dosen)==1)
	{
		
		if ((strcmp(d[i].user_dsn,dsn.user)==0) && (strcmp(d[i].pass_dsn,dsn.pass)==0))
		{
			system("cls");
			printf("\n Welcome, %s!",d[i].name_dsn);getchar();
			system("cls");dsnlook();
		}
		else
		{	
			if(strlen(d[i].user_dsn)==i && strlen(d[i].pass_dsn)==i)
			{
				printf ("\n  Login Gagal \n  Username dan password yang anda masukan salah");getchar();
				system("cls");dsnlgn();
				main();
			}
			else
			{
				i++;
			}
		}	
	}
	fclose(f_dosen);
}

void dsnlook()
{
	do
	{
		printf("\n--- Menu Dosen Wali ---\n\n");
		printf(" 1. Lihat Profil Dosen\n");
		printf(" 2. Lihat Kelas Wali\n");
		printf(" 3. Accept KRS Mahasiswa\n");
		printf(" 4. Input Nilai\n");
		printf(" 5. Log Out\n\n");
		
		printf("Pilih menu: ");scanf("%i",&a);fflush(stdin);
		system("cls");
		
		switch(a)
		{
			case 1: 
			{
				FILE *f_dftrdsn; 
				f_dftrdsn=fopen("Daftar Dosen.dat","rb"); 
				printf("\n--- Menu Dosen Wali\t: Profil Dosen ---\n\n");
				while (fread(&d[i],sizeof(d[i]),1,f_dftrdsn)==1) 
				{
					if(strcmp(d[i].user_dsn,dsn.user)==0 && strcmp(d[i].pass_dsn,dsn.pass)==0)
					{ 
						printf("  NIK                     : %i\n",	d[i].nik); 
						printf("  Kelas yang diwakilkan   : %s\n",	d[i].kls_dsn);
						printf("  Nama                    : %s\n",	d[i].name_dsn);
						printf("  TTL                     : %s\n",	d[i].ttl_dsn);
						printf("  e-Mail                  : %s\n",	d[i].mail_dsn);
						printf("  No. KTP                 : %s\n",	d[i].ktp_dsn);
						printf("  No. Telp                : %i\n",	d[i].telp_dsn);
						printf("  Alamat                  : %s\n",	d[i].almt_dsn);
						printf("  Pendidikan terakhir     : %s\n",	d[i].pndk_dsn);
					}
				}
				printf("\n");
				system("pause");system("cls");
				fclose(f_dftrdsn);
			} break;
			
			case 2:
			{
				FILE *f_dftrmhs; 
				f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
				printf("\n--- Menu Admin\t: Daftar Mahasiswa ---\n\n");
				j=1;
				while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1) 
				{ 
					printf("%i. NIM                 : %i\n",				j,d[i].nim); 
					printf("    Kelas              : %s\n",			d[i].kls_mhs);
					printf("    Nama               : %s\n",			d[i].name_mhs);
					printf("    TTL                : %s\n",			d[i].ttl_mhs);
					printf("    e-Mail             : %s\n",			d[i].mail_mhs);
					printf("    No. KTP            : %s\n",		d[i].ktp_mhs);
					printf("    No. Telp           : %i\n",		d[i].telp_mhs);
					printf("    Jurusan            : %s\n",		d[i].jrsn);
					printf("    Nama orangtua   \n");
					printf("     Ayah              : %s\n",			d[i].ayh);
					printf("     Ibu               : %s\n",			d[i].ibu);
					printf("    Jumlah saudara     : %i\n",	d[i].sdr);
					printf("    Alamat             : %s\n\n",		d[i].almt_mhs);
					j++;
				} 
				fclose(f_dftrmhs);	
				system("pause");system("cls");
				break;
			} 
			
			case 3:
			{
				FILE *f_matkulmhs;
				FILE *f_matkulmhs2;
				FILE *f_dftrmhs; 
				f_matkulmhs=fopen("Mata Kuliah Mahasiswa.dat","rb");
				f_matkulmhs2=fopen("Mata Kuliah Mahasiswa2.dat","ab+");
				f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb");
				
				if(strcmp(d[i].user_dsn,dsn.user)==0 && strcmp(d[i].pass_dsn,dsn.pass)==0)
				{
					printf("NIM dan Nama Mahasiswa Kelas %s:\n", d[i].kls_dsn);
					
					if(strcmp(d[i].kls_dsn,d[i].kls_mhs)==0)
					{
						i=1;
						j=1;
						while(fread(&d[i],sizeof (d[i]),1,f_dftrmhs)==1)
						{
							printf("%i. NIM                 : %i\n",				j,d[i].nim); 
							printf("   Nama                : %s\n",			    d[i].name_mhs);
						}
						while(fread(&d[i],sizeof (d[i]),1,f_matkulmhs)==1)
						{
							printf("   Mata kuliah ke-%i   : %s \n",j,d[i].matkul);
							j++;
						}
						printf("\n\nStatus KRS         : ");fflush(stdin);gets(d[i].acc);
				
						fwrite(&d[i],sizeof (d[i]),1,f_matkulmhs2);
					}
				}
				
				fclose(f_matkulmhs);fclose(f_matkulmhs2);fclose(f_dftrmhs);
				remove("Mata Kuliah Mahasiswa.dat");
				rename("Mata Kuliah Mahasiswa2.dat","Mata Kuliah Mahasiswa.dat");
				
				printf("\n\n");
				system("pause");system("cls");
			} break;
			
			case 4:
			{
				FILE *f_nilaimhs; 
				FILE *f_nilaimhs2;
				FILE *f_dftrmhs;
				f_dftrmhs=fopen("Daftar Mahasiswa.dat","rb"); 
				f_nilaimhs=fopen("Mata Kuliah Mahasiswa.dat","rb");
				f_nilaimhs2=fopen("Nilai Mahasiswa.dat","ab+"); 
				printf("\n--- Menu Dosen : Input Nilai ---\n\n");
				
				if(strcmp(d[i].user_dsn,dsn.user)==0 && strcmp(d[i].pass_dsn,dsn.pass)==0)
				{
					if(strcmp(d[i].kls_dsn,d[i].kls_mhs)==0)
					{
						printf("NIM dan Nama Mahasiswa Kelas %s:\n", d[i].kls_dsn);
						j=1;
						while (fread(&d[i],sizeof(d[i]),1,f_dftrmhs)==1)
						{
							printf(" %i. %i \t %s\n",j,d[i].nim,d[i].name_mhs);
						}
					}
				}
				
				printf("Masukkan NIM Mahasiswa: ");scanf("%i",&nimnil);
				
				if(d[i].nim==nimnil)
				{
					while (fread(&d[i],sizeof(d[i]),1,f_nilaimhs)==1) 
					{
						printf("\n%i. %s",		j,d[j].matkul);
						scanf("%f",&d[i].nilai);fflush(stdin);
						printf("\n");
					}
					fwrite(&d[i],sizeof (d[i]),1,f_nilaimhs2);
				}
				fclose(f_dftrmhs);fclose(f_nilaimhs);fclose(f_nilaimhs2);
				
				printf("\n");
				system("pause");system("cls");
			} break;
			
			case 5:
			{
				system("cls");break;
			}
		}
	}
	while(a!=5);
}
