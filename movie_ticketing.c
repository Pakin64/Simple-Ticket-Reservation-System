#include<stdio.h>
#include<stdlib.h> 
#include<strings.h>

int details();
int reservation(int *,int,int );
int choice1();
int cancel(int *);        
int cancelmovie();
int allmovie();
int movie1(int choice,char name[15],int id2,int price);
int movie2(int choice,char name[15],int id2,int price);
int movie3(int choice,char name[15],int id2,int price);
int count=0;

struct moviedetails {
	char name[25];
	char phone[13];
	int seat;
	int id;
} person[180];

int main() {
	int **seat, slection, i, choice, price=80;
	seat = (int **)calloc(101,sizeof(int *));
	
	for (i=0;i<3;i++)
		*(seat+i) = (int *)calloc(101, sizeof(int ));
		
	int num;
	while(num != 4) {
		choice = option();
		
		switch(choice) {
			case 1:
				details();
				break;	
			case 2:	
				slection = allmovie();
				reservation(seat[slection-1], price, slection);	
				count++;
				break;
			case 3: 
				slection = cancelmovie();	
				cancel(seat[slection-1]);	
				break;
			case 4:
				num = 4;
				break;
			default: 
				printf("Error, plase try again.\n");
				break;	
		}
	}
}

int details()
{
	int i;
	for (i=0;i<count;i++) {
		printf("\t-----------------------------------------------\n\n");
		printf("\tSeat no: %d is booked by %s\n",person[i].seat,person[i].name);
		printf("\tBooking id is %d\n\n",person[i].id);
		printf("\t-----------------------------------------------\n\n");
	}
	return 0;
}             

int id2=100;
int reservation(int *array, int price, int slection) {          
	int i,j;
		
	for (i=1; i<57; i++) {
		if (array[i] == 0)
			printf("%d\t",i);
		else 
			printf("*\t",i);	
		if(i%7 == 0)
			printf("\n\n");
	}
		
	printf(">> Enter your name : ");
	scanf(" %[^\n]", &person[count].name);
		
	printf(">> Enter your phone number : ");
	scanf("%u", &person[count].phone);
		
	printf(">> Which seat number you want? : ");
	scanf("%d", &j);
		
	if (j>56 || j<1) {
			printf("Oh No!!\n");
			printf("Seat number is unavailable in this cinema!!\n");
			printf(">> Please re-enter seat number: ");
			scanf("%d", &j);
			
	}
			
	if (array[j]==1) {
		printf("Sorry, this ticket is already booked!!\n");
		scanf("%d", &j);		
	}
			
	else {		
		array[j] = 1;
	}
	
	person[count].seat = j;
		
	if (slection == 1)
		movie1(j, person[count].name, id2, price);
			
	else if (slection == 2) 	
		movie2(j, person[count].name, id2, price);
			
	else 
		movie3(j, person[count].name, id2, price);	
					
	id2++;	
	return 0;
}

int cancel(int *array) {
    int myseat, stop, i=0;
	printf("\t\tPlease enter ID number of ticket: "); 
	scanf("%d", &myseat);
	for (i;i<300;i++) {
		if(myseat == person[i].id) {
			stop=5;
			system("cls");
			printf("\t-------------------------------\n\n");
			printf("\t !! Announce to %s !!\n", person[i].name);
			printf("\t Seat no: %d ID: %d is canceled\n\n",person[i].seat, person[i].id);
			printf("\t-------------------------------\n\n");
			array[person[i].seat]=0;
			i=300;
	  	}
	}
	  
	if (stop!=5) {
		printf("\t\tTicket ID number is incorrect!!\n\n"); 
	}
	return 0;
}

int option() {
	int choice;
	printf("\t\t   Welcome to Minor Cinema\n"); 
	printf("\t\t------------------------------\n");
	printf("\t\t   1- View reserved ticket\n");
	printf("\t\t   2- Buy ticket\n");
	printf("\t\t   3- Cancel the seat \n");
	printf("\t\t   4- Exit\n");
	printf("\t\t------------------------------\n");
	printf("\t\tChoose your choice : "); 
	scanf("%d", &choice);
	printf("\n\n"); 
	return choice;
}


int cancelmovie() {
	int i;
	printf("\t\t          Choose your movie\n");
	printf("\t\t---------------------------------------\n");
	printf("\t\tpress 1 >> JUJUTSU KAISEN : ZERO\n\n"); 
	printf("\t\tpress 2 >> Lightyear\n\n"); 
	printf("\t\tpress 3 >> Detective Conan The Movie 25\n\n"); 
	printf("\t\t---------------------------------------\n\n");
	printf("\t\tWhat movie would you like to cancel? : ");
	scanf("%d", &i);
	return i;		
}

int allmovie() {
	int i;
	system("cls");
	printf("\t\t          Choose your movie\n");
	printf("\t\t---------------------------------------\n");
	printf("\t\tpress 1 >> JUJUTSU KAISEN : ZERO\n\n"); 
	printf("\t\tpress 2 >> Lightyear\n\n"); 
	printf("\t\tpress 3 >> Detective Conan The Movie 25\n\n"); 
	printf("\t\t---------------------------------------\n\n");
	printf("\t\tWhat movie would you like to see? : ");
	scanf("%d", &i);
	system("cls");
	return i;
}

//Movies
int movie1(int choice, char name[10], int id2, int price) {
		system("cls");
		printf("\n\n");
        printf("\t\t           BOOKING TICKET \n");
        printf("\t\t-------------------------------------\n\n");
        printf("\t\t Booking ID : %d \t\t\t\n",id2);
        printf("\t\t Movie Title : JUJUTSU KAISEN : ZERO\n");
        printf("\t\t Customer  : %s\n", name);
        printf("\t\t Date      : 23 June 2022\n");
        printf("\t\t Time      : 02:25 pm\n");
        printf("\t\t theatre   : 1\n");
        printf("\t\t Seats No. : %d  \n", choice);
        printf("\t\t Price     : %d  Baht\n\n", price);
        person[count].id = id2;
        printf("\t\t-------------------------------------\n\n\n");
        return 0;
}

int movie2(int choice, char name[10], int id2, int price) {
		system("cls");
		printf("\n\n");
        printf("\t\t      BOOKING TICKET \n");
        printf("\t\t---------------------------\n\n");
        printf("\t\t Booking ID : %d \t\t\t\n",id2);
        printf("\t\t Movie Title : Lightyear\n");
        printf("\t\t Customer  : %s\n", name);
        printf("\t\t Date      : 16 JUN 2022\n");
        printf("\t\t Time      : 12:30 pm\n");
        printf("\t\t theatre   : 2\n");
        printf("\t\t Seats No. : %d  \n", choice);
        printf("\t\t Price     : %d  Baht\n\n", price);
        person[count].id = id2;
        printf("\t\t---------------------------\n\n\n");
        return 0;
}

int movie3(int choice, char name[15], int price, int id2) {
		system("cls");
		printf("\n\n");
        printf("\t\t               BOOKING TICKET \n");
        printf("\t\t--------------------------------------------\n\n");
        printf("\t\t Booking ID : %d \t\t\t\n",id2);
        printf("\t\t Movie Title : Detective Conan The Movie 25\n");
        printf("\t\t Customer  : %s\n", name);
        printf("\t\t Date      : 25 May 2022\n");
        printf("\t\t Time      : 11:00 am\n");
        printf("\t\t theatre   : 3\n");
        printf("\t\t Seats No. : %d  \n", choice);
        printf("\t\t Price     : %d  Baht\n\n", price);
        person[count].id = id2;
        printf("\t\t--------------------------------------------\n\n\n");
        return 0;
}
