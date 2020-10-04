#include<stdio.h>
#include<windows.h>
#include<ctype.h>
int total_student;
int choice=0;

void menu(){
	do{
		system("cls");
		printf("Welcome to Binus Univesity\n");
		printf("==========================\n");
		printf("Total Registered Student : %d\n\n",total_student);
		printf("1. View Student\n");
		printf("2. Add Student\n");
		printf("3. Delete Student\n");
		printf("4. Exit\n");
		printf("Choice [1..4]: ");
		scanf("%d",&choice);
		getchar();
	}while(choice!=1&&choice!=2&&choice!=3&&choice!=4);
}

int main(){
	char nama[22];
	int semester;
	float ipk;
	struct student{
		char nama[20];
		int semester;
		float ipk;
	}mahasiswa[50];
	Menu:
		system("cls");
		menu();

	switch(choice){
		case 1:{
			system("cls");
			if(total_student==0){
				printf("There is no student registered!\n\n");
			}else{
				printf("Binus University Student List\n\n");
				printf("=====================================================\n");
				printf("No.  Nama                 Semester             IPK\n");
				printf("=====================================================\n");
				for(int a=0;a<total_student;a++){
					printf("%3d  %-20s%-20d%.2f\n",a+1,mahasiswa[a].nama,mahasiswa[a].semester,mahasiswa[a].ipk);
				}
			}
			system("pause");
			goto Menu;
		}
		
		add :
			case 2:{
			system("cls");
			printf("Input student name [4..20]:");
			scanf("%[^\n]",&nama);
			for(int c=0;c<total_student;c++){
				if(strcmpi(nama,mahasiswa[c].nama)==0){
					printf("\nName already exists, chooese another name!\n");
					getchar();
					system("pause");
					goto add;
				}
			}
			nama[0]=toupper(nama[0]);
			for(int b=1;b<strlen(nama);b++){
				if(nama[b]==' '){
					nama[b+1]=toupper(nama[b+1]);
					b++;
				}else{
					nama[b]=tolower(nama[b]);
				}
			}
			strcpy(mahasiswa[total_student].nama,nama);
			printf("Input student semester [1..10]:");
			scanf("%d",&mahasiswa[total_student].semester);
			printf("Input student GPA [0.00..4.00]:");
			scanf("%f",&mahasiswa[total_student].ipk);
			
			printf("%s (Semester: %d, GPA:%.2f) has been succesfully register to Binus!\n",mahasiswa[total_student].nama,mahasiswa[total_student].semester,mahasiswa[total_student].ipk);
			total_student++;
			system("pause");
			goto Menu;
		}
		
		del :
			case 3:{
			system("cls");
			int number;
			if(total_student==0){
				printf("You must add a student first!");
				system("pause");
				goto Menu;
			}else{
				printf("Binus University Student List\n\n");
				printf("=====================================================\n");
				printf("No.  Nama                 Semester             IPK\n");
				printf("=====================================================\n");
				for(int a=0;a<total_student;a++){
					printf("%3d  %-20s%-20d%.2f\n",a+1,mahasiswa[a].nama,mahasiswa[a].semester,mahasiswa[a].ipk);
				}
				printf("Input Number [1..%d or type 0 to cancel]: ",total_student);
				scanf("%d",&number);
				if(number>total_student){
					goto del;
				}
				if(number==0){
					goto Menu;
				}else{
					printf("%s succesfully deleted!",mahasiswa[number-1].nama);
				}
			}
			for(int a=number;a<total_student;a++){
				mahasiswa[a-1] = mahasiswa[a];
			}
			
			total_student--;
			system("pause");
			goto Menu;
		}
		
		case 4:{
			system("cls");
			printf("\n\n");
			print();
			printf("\nBYE!");
			break;
		}
	}
	
}
