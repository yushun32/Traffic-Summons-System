//TRAFFIC SUMMONS SYSTEM GROUP3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define SIZE 10

struct PAYER{
    char name[30];
    int age;
    char gender[30];
    int malaysiaID;
    char email[30];
    char contactNumber[30];
    char state[30];
};

struct SUMMONS{
    char summonsID[30];
    int day;
    int month;
    int year;
    char offenseDescription[50];
    char typeVehicle[30];
    float payment;
    char paymentMethod[50];
    struct PAYER payer;
    struct SUMMONS *ptrnext;
};

void insert();
void delete();
void modify();
void list();
void sortSummons();
void linearSearch();

struct SUMMONS *headptr, *newptr, *currentptr, *searchptr, *previousptr;
//pointer that can point to a node


void insert()
{
    printf("\nInput Payer's Information\n");
    printf("-----------------------------\n");
    newptr=(struct SUMMONS *)malloc(sizeof (struct SUMMONS));

    printf("\nEnter Payer Name: ");
    scanf(" %[^\n]s", &newptr->payer.name);
    printf("\nEnter Payer Age: ");
    scanf(" %d", &newptr->payer.age);
    printf("\nEnter Payer Gender: ");
    scanf(" %[^\n]s", &newptr->payer.gender);
    printf("\nEnter Payer MalaysiaID: ");
    scanf(" %d", &newptr->payer.malaysiaID);
    printf("\nEnter Payer Email: ");
    scanf(" %[^\n]s", &newptr->payer.email);
    printf("\nEnter Payer Contact Number: ");
    scanf(" %[^\n]s", &newptr->payer.contactNumber);
    printf("\nEnter Payer state: ");
    scanf(" %[^\n]s", &newptr->payer.state);

    printf("\nEnter SummonsID: ");
    scanf(" %[^\n]s", &newptr->summonsID);
    printf("\nEnter Day: ");
    scanf(" %d", &newptr->day);
    printf("\nEnter Month: ");
    scanf(" %d", &newptr->month);
    printf("\nEnter Year: ");
    scanf(" %d", &newptr->year);
    printf("\nEnter Offense Description: ");
    scanf(" %[^\n]s", &newptr->offenseDescription);
    printf("\nEnter Type Of Vehicle: ");
    scanf(" %[^\n]s", &newptr->typeVehicle);
    printf("\nEnter Cost of Payment: RM");
    scanf(" %f", &newptr->payment);
    printf("\nEnter Payment Method: ");
    scanf(" %[^\n]s", &newptr->paymentMethod);

  if (headptr==NULL)
  {
        headptr=newptr;
        newptr->ptrnext=NULL;
  }

  else
   {
   currentptr=headptr;

   while(currentptr->ptrnext !=NULL)
   {
    currentptr=currentptr->ptrnext;
   }
    currentptr->ptrnext=newptr;
    newptr->ptrnext=NULL;
 }
}//insert at the end


void delete()
{
	if (headptr==NULL)//node is empty?
    {
    printf("\n\nThe list is empty. Cannot delete!!!\n");//the list is empty
    }

	else
	{
      currentptr=headptr;//current contain the address of first node
      headptr=headptr->ptrnext;;//head point to second previous node
      free(currentptr);//destroy first node, free the memory.
      printf("\nDelete successfully");
	}
}//delete at the beginning


void modify()
{
    int key;//search malaysiaID

    if(headptr==NULL)
    {
        printf("!!!Empty List!!!");
        return;
    }

    printf("\nEnter Malaysia ID to modify: ");
    scanf("%d", &key);

    searchptr=headptr;

    while(searchptr->ptrnext!= NULL)
    {
        if(searchptr->payer.malaysiaID == key) //found the location
        {
            break;
        }
        else
        {
            previousptr=searchptr;//save the previous current address
            searchptr=searchptr->ptrnext; //point to next node
        }

    }

    currentptr=searchptr;

    if(currentptr->payer.malaysiaID == key)
    {
        newptr=(struct SUMMONS *)malloc(sizeof (struct SUMMONS));

        printf("\nEnter New Payer Name: ");
        scanf(" %[^\n]s", &newptr->payer.name);
        printf("\nEnter New Payer Age: ");
        scanf(" %d", &newptr->payer.age);
        printf("\nEnter New Payer Gender: ");
        scanf(" %[^\n]s", &newptr->payer.gender);
        printf("\nEnter New Payer MalaysiaID: ");
        scanf(" %d", &newptr->payer.malaysiaID);
        printf("\nEnter New Payer Email: ");
        scanf(" %[^\n]s", &newptr->payer.email);
        printf("\nEnter New Payer Contact Number: ");
        scanf(" %[^\n]s", &newptr->payer.contactNumber);
        printf("\nEnter New Payer state: ");
        scanf(" %[^\n]s", &newptr->payer.state);

        printf("\nEnter New SummonsID: ");
        scanf(" %[^\n]s", &newptr->summonsID);
        printf("\nEnter New Day: ");
        scanf(" %d", &newptr->day);
        printf("\nEnter New Month: ");
        scanf(" %d", &newptr->month);
        printf("\nEnter New Year: ");
        scanf(" %d", &newptr->year);
        printf("\nEnter New Offense Description: ");
        scanf(" %[^\n]s", &newptr->offenseDescription);
        printf("\nEnter New Type Of Vehicle: ");
        scanf(" %[^\n]s", &newptr->typeVehicle);
        printf("\nEnter New Cost of Payment: RM");
        scanf(" %f", &newptr->payment);
        printf("\nEnter New Payment Method: ");
        scanf(" %[^\n]s", &newptr->paymentMethod);

        if(currentptr==headptr && currentptr->ptrnext==NULL) //number is the first and only node in list
        {
            currentptr->ptrnext=newptr;//insert at end
            newptr->ptrnext=NULL;
            headptr=newptr;

            free(currentptr);
        }
        else if(currentptr==headptr)//number is at the first node, but NOT only node in list
        {
            newptr->ptrnext=currentptr->ptrnext;
            currentptr->ptrnext=newptr;
            headptr=newptr;

            free(currentptr);
        }
        else //delete at the middle of link list
        {
            newptr->ptrnext=currentptr->ptrnext;
            previousptr->ptrnext=newptr;
            free(currentptr);//destroy old node
        }
    }
    else
    {
        printf("\nMalaysia ID not in records!!!");
    }
}


void list()
{
	if (headptr==NULL) //empty list
	{
		printf("\nEmpty list");
		return;
	}

	currentptr=headptr;
	printf("\nList Payer's Information\n");
	printf("----------------------------\n");
	do
	{
		printf("\nPayer Name: %s",currentptr->payer.name);
        printf("\nPayer Age: %d", currentptr->payer.age);
        printf("\nPayer Gender: %s",currentptr->payer.gender);
		printf("\nPayer Malaysia ID: %d", currentptr->payer.malaysiaID);
		printf("\nPayer Email: %s",currentptr->payer.email);
        printf("\nPayer Contact Number: %s", currentptr->payer.contactNumber);
		printf("\nPayer State: %s",currentptr->payer.state);

		printf("\nSummons ID: %s",currentptr->summonsID);
		printf("\nSummons Day: %d",currentptr->day);
		printf("\nSummons Month: %d",currentptr->month);
		printf("\nSummons Year: %d",currentptr->year);
		printf("\nSummons Offense Description: %s",currentptr->offenseDescription);
		printf("\nType Of Vehicle: %s",currentptr->typeVehicle);
		printf("\nCost Of Payment: RM%.2f",currentptr->payment);
		printf("\nPayment Method: %s",currentptr->paymentMethod);
		printf("\n");
		currentptr=currentptr->ptrnext; //point to next node
	}while(currentptr !=NULL);
}//list out the output


struct SUMMONS ss[SIZE] = {

    {"SU001",1,  1, 2021, " Illegal Parking",          "Car",       300, "Online Banking"},
    {"SU002",12, 3, 2021, " Beating The Red Light",    "Motorcycle",300, "Cash"          },
    {"SU003",3,  4, 2021, " Forgot To Wear Seat Belt", "Van",       300, "Online Banking"},
    {"SU004",4,  4, 2021, " Forgot To Wear Seat Belt", "Van",       900, "Cash"          },
    {"SU005",15, 12,2021, " Illegal Parking",          "Car",       900, "Cash"          },
    {"SU006",6,  8, 2021, " Forgot To Wear Seat Belt", "Motorcycle",600, "Credit Card"   },
    {"SU007",17, 6, 2021, " Illegal Parking",          "Car",       900, "Cash"          },
    {"SU008",8,  12,2021, " Beating The Red Light",    "Motorcycle",600, "Online Banking"},
    {"SU009",9,  8, 2021, " Beating The Red Light",    "Van",       600, "Credit Card"   },
    {"SU010",12, 11,2021, " Illegal Parking",          "Motorcycle",900, "Cash"          },

};//summons record in 2021


void displaySummons(struct SUMMONS ss[10], int s){
    int i;

    printf("\n\nSummons ID\tMonth\t\tOffense Description\t\tPayment\n");
    printf("------------------------------------------------------------------------------------------\n");
    for (i = 0; i < s; i++)
    {
        printf("%s                %d     %s       \t%RM%.2f\n", ss[i].summonsID, ss[i].month, ss[i].offenseDescription, ss[i].payment);
    }
}//display the output


void sortSummons(struct SUMMONS ss[10], int s){

    int i, j, sort;
    struct SUMMONS temp;
    printf("\n\n---------------------------------------------------------------");
    printf("\n\n                      SUMMONS RECORD                            ");
    printf("\n\n---------------------------------------------------------------");
    do{
        printf("\n\n Summons sort by ascending alphabet and increasing number\n");
        printf("1.Month\n");
        printf("2.Offense Of Description\n");
        printf("3.Cost Of Payment");
        printf("\n\n Your choice : ");
        scanf("%d",&sort);
    }while(sort!=1&&sort!=2&&sort!=3);

    if(sort == 1){
        for (i = 0; i < s - 1; i++){
            for (j = 0; j < (s - 1-i); j++){
                if (ss[j].month > ss[j + 1].month){
                    temp = ss[j];
                    ss[j] = ss[j + 1];
                    ss[j + 1] = temp;
                }
            }
        }
    }
    else if(sort == 2){
        for(i = 1; i < s; i++){
            for(j = 0; j < s-1; j++){
                if(strcmp(ss[j].offenseDescription,ss[j+1].offenseDescription)>0){
                    temp = ss[j];
                    ss[j] = ss[j+1];
                    ss[j+1] = temp;
         }
      }
    }}
    else if(sort == 3){
        for(i = 1; i < s - 1; i++){
            for(j = 0; j < (s - 1-i); j++){
                if (ss[j].payment > ss[j + 1].payment){
                    temp = ss[j];
                    ss[j] = ss[j + 1];
                    ss[j + 1] = temp;
         }
      }
     }
    }
    displaySummons(ss, SIZE);
}//sort category chosen with ascending alphabet OR character and increasing number


void linearSearch()
{
    currentptr=headptr;
    char key[30];

	printf("\nSummons ID to search: ");
    scanf(" %[^\n]s", &key);

    while(currentptr!=NULL)
    {
        if(!strcmp(key, currentptr->summonsID))//strcmp() returns 0 if SAME.
        {
            printf("\nSummons ID: %s", currentptr->summonsID);

            printf("\nPayer Name: %s",currentptr->payer.name);
            printf("\nPayer Age: %d", currentptr->payer.age);
            printf("\nPayer Gender: %s",currentptr->payer.gender);
            printf("\nPayer Malaysia ID: %d", currentptr->payer.malaysiaID);
            printf("\nPayer Email: %s",currentptr->payer.email);
            printf("\nPayer Contact Number: %s", currentptr->payer.contactNumber);
            printf("\nPayer State: %s",currentptr->payer.state);

            printf("\nSummons Day: %d",currentptr->day);
            printf("\nSummons Month: %d",currentptr->month);
            printf("\nSummons Year: %d",currentptr->year);
            printf("\nSummons Offense Description: %s",currentptr->offenseDescription);
            printf("\nType Of Vehicle: %s",currentptr->typeVehicle);
            printf("\nCost Of Payment: RM%.2f",currentptr->payment);
            printf("\nPayment Method: %s",currentptr->paymentMethod);
            printf("\n");
            return;
        }
        currentptr=currentptr->ptrnext;
    }

	printf("\nSorry, %s not found", key);
	return;
}//linear sequential search


int main()
{
	char ch;
	int choice=TRUE;

	headptr=NULL;
	printf("\n\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
	printf("\n<>                                                            <>");
    printf("\n<>                        WELCOME                             <>");
    printf("\n<>                          TO                                <>");
    printf("\n<>                 TRAFFIC SUMMONS SYSTEM                     <>");
    printf("\n<>                                                            <>");
    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>");

	while(choice==TRUE)

	{
		printf("\n\nA - Insert Payer's Information");
		printf("\nB - Delete Payer's Information");
        printf("\nC - Modify Payer's Information");
        printf("\nD - List Payer's Information");
        printf("\nE - Sort Summons's Information");
        printf("\nF - Search Payer's Information");
        printf("\nG - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		switch(toupper(ch))
		{
		case 'A':insert();break;
		case 'B':delete();break;
        case 'C':modify();break;
        case 'D':list();break;
        case 'E':sortSummons(ss, SIZE);break;
        case 'F':linearSearch();break;
		case 'G': choice=FALSE;
		printf("\nThank You, Have A Nice Day\n");
		break;

		default: printf("\nEnter only one from the above");
		}
	}
	return 0;
}//main function
