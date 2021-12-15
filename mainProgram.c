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
	
return 0;
}
