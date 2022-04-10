#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;
void tambah_depan();
void tambah_belakang();
void hapus_depan();
void hapus_belakang();
void tampil();
int main(){


	int pilihan = 0;
	while (pilihan!=6)
	{
		cout<<"==================================="<<endl;
		cout<<"    Double Circular Linked List"<<endl;
		cout<<"==================================="<<endl;
		cout<<"1. Tambah Depan"<<endl;
		cout<<"2. Tambah Belakang"<<endl;
		cout<<"3. Hapus Depan"<<endl;
		cout<<"4. Hapus Belakang"<<endl;
		cout<<"5. Tampilkan"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Masukkan Pilihan Anda :"<<endl;
		cin>>pilihan;
		
		switch(pilihan){
			case 1:
				tambah_depan();
				break;
			case 2:
				tambah_belakang();
				break;
			case 3:
				hapus_depan();
				break;
			case 4:
				hapus_belakang();
				break;
			case 5:
				tampil();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Pilihan yang Anda Masukkan Tidak Tersedia!";
		}
	}
}
void tambah_depan(){
	struct node *ptr,*temp;
	int item;
	ptr= (struct node *)malloc(sizeof(struct node));
	if (ptr==NULL){
		cout<<"\nOVERFLOW"<<endl;
	}else{
		cout<<"\nMasukkan Nilai"<<endl;
		cin>>item;
		ptr->data=item;
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
			head=ptr;
		}
		cout<<"Node Berhasil Dimasukkan"<<endl;
	}
}
void tambah_belakang(){
	struct node *ptr,*temp;
	int item;
	ptr= (struct node *)malloc(sizeof(struct node));
	if (ptr==NULL){
		cout<<"\nOVERFLOW"<<endl;
	}else{
		cout<<"\nMasukkan Nilai"<<endl;
		cin>>item;
		ptr->data=item;
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
		}else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			head->prev=ptr;
			ptr->next=head;
		}
		cout<<"Node Berhasil Dimasukkan"<<endl;
	}
}
void hapus_depan(){
	struct node*temp;
	if(head==NULL){
		cout<<"\nOVERFLOW"<<endl;
	}else if(head->next==head){
		head=NULL;
		free(head);
		cout<<"Node Berhasil Dihapus"<<endl;
	}else{
		temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=head->next;
		head->next->prev=temp;
		free(head);
		head=temp->next;
	}
}
void hapus_belakang(){
	struct node*ptr;
	if(head==NULL){
		cout<<"\nOVERFLOW"<<endl;
	}else if(head->next==head){
		head=NULL;
		free(head);
		cout<<"\nNode Berhasil Dihapus"<<endl;
	}else{
		ptr=head;
		if(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=head;
		head->prev=ptr->prev;
		free(ptr);
		cout<<"\nNode Berhasil Dihapus"<<endl;
	}
}
void tampil(){
	struct node *ptr;
	ptr=head;
	if(head==NULL){
		cout<<"\nTidak ada yang akan dicetak"<<endl;
	}else{
		cout<<"\nCetak Nilai :"<<endl;
		while(ptr->next!=head){
			cout<<"\n"<<ptr->data<<endl;
			ptr=ptr->next;
		}		cout<<"\n"<<ptr->data<<endl;
	}
}
