#include <stdio.h>
#include <stdlib.h>

int session=-1;

struct node{
	int nim;
	char nama[100];
	char kelamin[10];
	char tgl_lahir[100];
	char tempat_lahir[100];
	char alamat[100];
	char kelas;
	float UAS, UTS, quiz, tgs, rata;
	char grade;

	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void login();
void DataMahasiswa();
void NilaiMahasiswa();
void Kelulusan();
void showMahasiswa();
void addMahasiswa();
void deleteMahasiswa();
void editMahasiswa();
void header();
void inputNilai();
void dataNilai();
void avgAll();
void editNilai();
void hapusNilai();
float maxRataRata();
float minRataRata();
void avgGrade();
void infoGrade();
void lulus();
void tidakLulus();
void dataMhs(int);
void editDataDiri(int);
void cekLulus(int);

void main(){

void deleteMahasiswa(){

	struct node *bantu, *hapus;

	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	int delNim;
	system("cls");
	header();

	puts("|               HAPUS DATA MAHASISWA BARU                |");
	puts("==========================================================");
	printf(" --> Masukan NIM Mahasiswa : ");
	scanf("%d",&delNim);
	puts("==========================================================");


	int cek;
	cek=0;

		bantu=head;

		while(bantu!=NULL){
			if(bantu->nim==delNim){
				hapus=bantu;

				if(bantu->prev==NULL&&bantu->next==NULL){
					head=NULL;
				}

				else if(bantu->prev==NULL){
					head=head->next;
					head->prev=NULL;
				}

				else if(bantu->next==NULL){
					bantu->prev->next=NULL;
				}

				else{
					hapus->prev->next=bantu->next;
					hapus->next->prev=bantu->prev;
				}

				free(hapus);
				cek=1;
				puts(" --> Data Berhasil Dihapus");
			}
			bantu=bantu->next;
		}

	if(cek==0){
		puts(" --> NIM Tidak Ditemukan");
	}


}

void editMahasiswa(){
	struct node*bantu;
	int editNim, cek;
	
	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}
	
	cek=0;
	system("cls");
	header();
	puts("|               EDIT DATA MAHASISWA BARU                 ");
	puts("==========================================================");
	printf(" --> Masukan NIM Mahasiswa : ");
	scanf("%d",&editNim);

	bantu=head;
	
	void editMahasiswa(){
	struct node *bantu;
	int editNim, cek;

	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	cek=0;
	system("cls");
	header();
	puts("|               EDIT DATA MAHASISWA BARU                 ");
	puts("==========================================================");
	printf(" --> Masukan NIM Mahasiswa : ");
	scanf("%d",&editNim);

	bantu=head;

	while(bantu!=NULL){
		if(bantu->nim==editNim){
			cek=1;
			break;
		}
		bantu=bantu->next;
	}


	if(cek==0){
		puts("==========================================================");
		puts(" --> NIM Tidak Ditemukan");
	}
	else{

		puts("==========================================================");
		puts(" --> Data Saat Ini :");
		puts("==========================================================");
		printf(" --> Nama 		: %s\n",bantu->nama);
		printf(" --> Jenis Kelamin 	: %s\n",bantu->kelamin);
		printf(" --> Tanggal Lahir 	: %s\n",bantu->tgl_lahir);
		printf(" --> Tempat Lahir 	: %s\n",bantu->tempat_lahir);
		printf(" --> Alamat 		: %s\n",bantu->alamat);

		puts("==========================================================");
		puts(" --> Input Data Baru");
		puts("==========================================================");
		printf(" --> Nama : ");
		fflush(stdin);
		gets(bantu->nama);
		printf(" --> Jenis Kelamin : ");
		fflush(stdin);
		gets(bantu->kelamin);
		printf(" --> Tanggal Lahir : ");
		fflush(stdin);
		gets(bantu->tgl_lahir);
		printf(" --> Tempat Lahir : ");
		fflush(stdin);
		gets(bantu->tempat_lahir);
		printf(" --> Alamat : ");
		fflush(stdin);
		gets(bantu->alamat);

		puts("");
		puts(" --> Data Berhasil Di-Edit");
	}
}

void Kelulusan()
{
    int pilihan;
    char rep;

    do{

    system("cls");
    header();
    puts("|                Kelulusan Mahasiswa                     |");
    puts("==========================================================");
    printf(" --> 1. Informasi Grade dan Nilai\n");
    printf(" --> 2. Mahasiswa Yang Lulus\n");
    printf(" --> 3. Mahasiswa Yang Tidak Lulus\n");
    printf(" --> 4. Kembali\n");
    puts("==========================================================");
    printf(" --> Pilihan : ");
    scanf("%d",&pilihan);

    switch(pilihan)
    {
        case 1:
            infoGrade();
        break;
    	case 2:
            lulus();
        break;
        case 3:
        	tidakLulus();
        break;
        case 4:
        	main();
        break;
        default:
        	puts(" --> Pilihan Tidak Tersedia");
        break;
    }

    puts("==========================================================");
	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
}

void infoGrade(){
	puts("==========================================================");
	puts("|                   GRADE MAHASISWA                      |");
	puts("==========================================================");
	puts(" --> Grade A untuk Nilai 80 sampai 100");
	puts(" --> Grade B untuk Nilai 70 sampai 79");
	puts(" --> Grade C untuk Nilai 60 sampai 69");
	puts(" --> Grade D untuk Nilai 50 sampai 59");
	puts(" --> Grade E untuk Nilai 50 Kebawah");
}

void lulus(){

	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG LULUS                   |");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='A'||bantu->grade=='B'||bantu->grade=='C'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}

void tidakLulus(){
	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG GAGAL                    ");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='E'||bantu->grade=='D'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}

void lulus(){

	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG LULUS                   |");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='A'||bantu->grade=='B'||bantu->grade=='C'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}

void tidakLulus(){
	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG GAGAL                    ");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='E'||bantu->grade=='D'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}
return 0;
}
