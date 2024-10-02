#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int rooms;
char username[10], password[10];
struct room
{
	int occupied;
	char roomType;
	int roomNumber;
	char name[20];
	long long int mobile,aadhaar;
	struct room *nextRoom;
};
struct room *first=NULL;
void hotelRegistration();
void credentials();
void displayStandardRooms();
void displayDeluxeRooms();
void displayPremiumRooms();
void displayAllRooms();
void displayVacantStandard();
void displayVacantDeluxe();
void displayVacantPremium();
void displayVacantRooms();
void displayOccupiedRooms();
void allotRoom();
void vacateRoom();
void searchRoom();
void displayBookedRooms();
int main()
{
	int choice,yes3=1,yes4=1;
	char username2[10],password2[10];
	hotelRegistration();
	displayAllRooms();
	printf("\nYOU WILL BE REDIRECTED TO THE MAIN PAGE IN 10 SECONDS");
	sleep(10);
	login:
	system("cls");
	printf("\n\n\n\n        Enter username: ");
	scanf("%s",username2);
	printf("\n        Enter password: ");
	scanf("%s",password2);
	yes3=strcmp(username,username2);
	yes4=strcmp(password,password2);
	if((yes3)||(yes4))
	{
		sleep(1);
		printf("\n        INVALID CREDENTIALS\n");
		printf("        PLEASE TRY AGAIN\n");
		sleep(3);
		goto login;
	}
	else
	{
		while(1)
		{
			system("cls");
			printf("\n    1 Allot a room\n");
			printf("    2 Vacate a room\n");
			printf("    3 Search a customer's details\n");
			printf("    4 Display all booked room details\n");
			printf("    5 Change credentials\n");
			printf("    6 Logout\n");
			printf("\n    Enter your choice: ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					system("cls");
					allotRoom();
					break;
				case 2:
					system("cls");
					vacateRoom();
					break;
				case 3:
					system("cls");
					searchRoom();
					break;
				case 4:
					system("cls");
					displayBookedRooms();
					break;
				case 5:
					credentials();
					break;
				case 6:
					goto login;
					break;
				default:
					printf("\n    ENTER VALID OPTION");
					sleep(5);
					break;
			}
		}
	}
	return 0;
}
void hotelRegistration()
{
	printf("SET USERNAME: ");
	scanf("%s",username);
	printf("SET PASSWORD: ");
	scanf("%s",password);
	int floors;
	int i,j,k,l;
	int std,del,prem;
	int standard[100],deluxe[100],premium[100];
	printf("\n\nEnter number of floors: ");
	scanf("%d",&floors);
	printf("Enter number of rooms in each floor: ");
	scanf("%d",&rooms);
	struct room *tempRoom,*newRoom;
	tempRoom=(struct room*)malloc(sizeof(struct room));
	tempRoom->roomNumber=101;
	tempRoom->occupied=0;
	tempRoom->nextRoom=NULL;
	first=tempRoom;
	for(i=1;i<=floors;i++)
	{
		for(j=1;j<=rooms;j++)
		{
			if(i==1&&j==1)
			{
				continue;
			}
			newRoom=(struct room*)malloc(sizeof(struct room));
			newRoom->roomNumber=i*100+j;
			newRoom->occupied=0;
			newRoom->nextRoom=NULL;
			tempRoom->nextRoom=newRoom;
			tempRoom=newRoom;
		}
	}
	printf("\nAll room numbers are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		printf("%d\t",tempRoom->roomNumber);
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
	roomTypes:{
	printf("\nEnter number of standard rooms: ");
	scanf("%d",&std);
	printf("Enter number of deluxe rooms: ");
	scanf("%d",&del);
	printf("Enter number of premium rooms: ");
	scanf("%d",&prem);
	if((std+del+prem)==(floors*rooms))
	{
	printf("\nEnter room numbers of all standard rooms:\n");
	for(k=0;k<std;k++)
	{
		scanf("%d",&standard[k]);
	}
	printf("Enter room numbers of all deluxe rooms:\n");
	for(k=0;k<del;k++)
	{
		scanf("%d",&deluxe[k]);
	}
	printf("Enter room numbers of all premium rooms:\n");
	for(k=0;k<prem;k++)
	{
		scanf("%d",&premium[k]);
	}
	for(k=0;k<std;k++)
	{
		tempRoom=first;
		while(tempRoom!=NULL)
		{
			if(standard[k]==tempRoom->roomNumber)
			{
				tempRoom->roomType='S';
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
	}
	for(k=0;k<del;k++)
	{
		tempRoom=first;
		while(tempRoom!=NULL)
		{
			if(deluxe[k]==tempRoom->roomNumber)
			{
				tempRoom->roomType='D';
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
	}
	for(k=0;k<prem;k++)
	{
		tempRoom=first;
		while(tempRoom!=NULL)
		{
			if(premium[k]==tempRoom->roomNumber)
			{
				tempRoom->roomType='P';
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
	}
	}
	else
	{
		printf("Total number of rooms not equal to entered number of rooms\n");
		printf("PLEASE TRY AGAIN\n");
		goto roomTypes;
	}
	}
	system("cls");
	for(k=0;k<3;k++)
	{
		printf("\nYou will be redirected to the room numbers page in %d seconds\n",3-k);
		sleep(1);
		system("cls");
	}
}
void displayStandardRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll standard rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='S')
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayDeluxeRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll deluxe rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='D')
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayPremiumRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll premium rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='P')
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayAllRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll room numbers are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		printf("%d\t",tempRoom->roomNumber);
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
	displayStandardRooms();
	displayDeluxeRooms();
	displayPremiumRooms();
}
void displayVacantStandard()
{
	int l;
	struct room *tempRoom;
	printf("\nAll available standard rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='S'&&tempRoom->occupied==0)
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayVacantDeluxe()
{
	int l;
	struct room *tempRoom;
	printf("\nAll available deluxe rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='D'&&tempRoom->occupied==0)
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayVacantPremium()
{
	int l;
	struct room *tempRoom;
	printf("\nAll available premium rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->roomType=='P'&&tempRoom->occupied==0)
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void displayVacantRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll vacant rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->occupied==0)
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
	displayVacantStandard();
	displayVacantDeluxe();
	displayVacantPremium();
}
void displayOccupiedRooms()
{
	int l;
	struct room *tempRoom;
	printf("\nAll Occupied rooms are:\n");
	l=0;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		l++;
		if(tempRoom->occupied==1)
		{
			printf("%d\t",tempRoom->roomNumber);
		}
		tempRoom=tempRoom->nextRoom;
		if(l==rooms)
		{
			printf("\n");
			l=0;
		}
	}
}
void allotRoom()
{
	int choice,roomno=0;
	struct room *tempRoom;
	tempRoom=first;
	printf("What kind of room do you want?\n");
	printf("1 Standard\n");
	printf("2 Deluxe\n");
	printf("3 Premium\n");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			displayVacantStandard();
			printf("Enter room number from any of the above rooms: ");
			scanf("%d",&roomno);
			break;
		case 2:
			displayVacantDeluxe();
			printf("Enter room number from any of the above rooms: ");
			scanf("%d",&roomno);
			break;
		case 3:
			displayVacantPremium();
			printf("Enter room number from any of the above rooms: ");
			scanf("%d",&roomno);
			break;
		default:
			sleep(1);
			printf("INVALID OPTION\n");
			sleep(2);
			break;	
	}
	if(roomno!=0)
	{
		while(tempRoom!=NULL)
		{
			if(tempRoom->roomNumber==roomno)
			{
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
		if(tempRoom==NULL)
		{
			sleep(1);
			printf("PLEASE ENTER VALID ROOM NUMBER\n");
			sleep(3);
		}
		else
		{
			printf("Enter customer details\n");
			printf("Enter customer name: ");
			scanf("%s",tempRoom->name);
			printf("Enter customer mobile number: ");
			scanf("%lld",&tempRoom->mobile);
			printf("Enter customer aadhaar number: ");
			scanf("%lld",&tempRoom->aadhaar);
			tempRoom->occupied=1;
			sleep(1);
			printf("\nROOM ALLOTED!");
			sleep(2);
		}
	}
}
void vacateRoom()
{
	int roomno,yes,yes1=0;
	struct room *tempRoom;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		if(tempRoom->occupied==1)
		{
			yes1=1;
		}
		tempRoom=tempRoom->nextRoom;
	}
	if(yes1==1)
	{
		displayOccupiedRooms();
		printf("Enter room number to vacate: ");
		scanf("%d",&roomno);
		tempRoom=first;
		while(tempRoom!=NULL)
		{
			if(tempRoom->roomNumber==roomno)
			{
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
		if(tempRoom==NULL)
		{
			sleep(1);
			printf("PLEASE ENTER VALID ROOM NUMBER\n");
			sleep(3);
		}
		else if(tempRoom->occupied==0)
		{
			sleep(1);
			printf("Room is already Vacant\n");
			sleep(1);
			printf("ONLY BOOKED ROOMS CAN BE VACATED\n");
			sleep(3);
		}
		else
		{
			printf("Customer name: %s\n",tempRoom->name);
			printf("Customer mobile number: %lld\n",tempRoom->mobile);
			printf("Customer aadhaar number: %lld\n",tempRoom->aadhaar);
			printf("Enter 1 to confirm\n");
			scanf("%d",&yes);
			if(yes==1)
			{
				tempRoom->occupied=0;
				sleep(1);
				printf("\nROOM VACATED!");
				sleep(3);
			}
			else
			{
				sleep(1);
				printf("\nPLEASE TRY AGAIN\n");
				sleep(3);
			}
		}
	}
	else
	{
		sleep(1);
		printf("NO ROOMS BOOKED TO VACATE");
		sleep(3);
	}
}
void searchRoom()
{
	int roomno,yes,yes1=0;
	struct room *tempRoom;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		if(tempRoom->occupied==1)
		{
			yes1=1;
		}
		tempRoom=tempRoom->nextRoom;
	}
	if(yes1==1)
	{
		displayOccupiedRooms();
		printf("Enter room number: ");
		scanf("%d",&roomno);
		tempRoom=first;
		while(tempRoom!=NULL)
		{
			if(tempRoom->roomNumber==roomno)
			{
				break;
			}
			tempRoom=tempRoom->nextRoom;
		}
		if(tempRoom==NULL)
		{
			sleep(1);
			printf("\nPLEASE ENTER VALID ROOM NUMBER\n");
			sleep(3);
		}
		else
		{
			if(tempRoom->occupied==0)
			{
				sleep(1);
				printf("\nRoom is Vacant\n");
				sleep(1);
				printf("PLEASE SELECT ONLY BOOKED ROOMS");
				sleep(3);
			}
			else
			{
				printf("Customer name: %s\n",tempRoom->name);
				printf("Customer mobile number: %lld\n",tempRoom->mobile);
				printf("Customer aadhaar number: %lld\n",tempRoom->aadhaar);
				printf("Enter 1 to continue\n");
				scanf("%d",&yes);
			}
		}
	}
	else
	{
		sleep(1);
		printf("NO ROOMS BOOKED TO SEARCH");
		sleep(3);
	}
}
void displayBookedRooms()
{
	int roomno,yes,yes1=0;
	struct room *tempRoom;
	tempRoom=first;
	while(tempRoom!=NULL)
	{
		if(tempRoom->occupied==1)
		{
			yes1=1;
		}
		tempRoom=tempRoom->nextRoom;
	}
	tempRoom=first;
	if(yes1==1)
	{
		printf("Room\tName\tMobile\t\tAadhaar\n");
		while(tempRoom!=NULL)
		{
			if(tempRoom->occupied==1)
			{
				printf("%d\t",tempRoom->roomNumber);
				printf("%s\t",tempRoom->name);
				printf("%lld\t",tempRoom->mobile);
				printf("%lld\n",tempRoom->aadhaar);
			}
			tempRoom=tempRoom->nextRoom;
		}
		printf("Enter 1 to continue\n");
		scanf("%d",&yes);
	}
	else
	{
		printf("NO ROOMS BOOKED TO DISPLAY\n");
		printf("Enter 1 to continue\n");
		scanf("%d",&yes);
	}
}
void credentials()
{
	system("cls");
	int yes1=1,yes2=1;
	char username1[10],password1[10];
	printf("\nEnter current username: ");
	scanf("%s",username1);
	printf("Enter current password: ");
	scanf("%s",password1);
	yes1=strcmp(username,username1);
	yes2=strcmp(password,password1);
	if((yes1)||(yes2))
	{
		sleep(1);
		printf("INVALID CREDENTIALS\n");
		sleep(1);
		printf("PLEASE TRY AGAIN\n");
		sleep(3);
	}
	else
	{
		printf("\nEnter new username: ");
		scanf("%s",username);
		printf("Enter new password: ");
		scanf("%s",password);
		sleep(1);
		printf("\nCREDENTIALS CHANGED!");
		sleep(3);
	}
}
