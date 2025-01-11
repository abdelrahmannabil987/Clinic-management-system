#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

typedef struct namee
{
	char name[10];
	char age ; 
	char gender ; 
	int ID;
	int res;
	struct namee * next ; 
}node_t;

    node_t* HEAD;
	node_t*ptr;
	node_t*TEMP;
	
int RES[5]={0,0,0,0,0};
	
void adminmode(void);
void options(void);
void usermode(void);

void main (void)
{
	char mode; 
	while(1)
	{
	printf("Press 1 for Admin mode\nPress 2 for User mode ,\nPress Any other Key To Close ! \n");
	scanf("%d",&mode); 
	if (mode == 1 )
	{
		adminmode();
	}
	else if (mode == 2 )
	{
		usermode();
	}
	else 
	{
		printf("Wrong Mode");
		break;
	}
	}
}







/*********************************ADMIN MODE*/////////////////////////////////////////////






void adminmode(void)
{
	char i ;
	int pass;
	for(i=0;i<3;i++)
	{
		printf("Enter The Password : ");
		scanf("%d",&pass);
		if (pass==1234)
		{
			i=10;
			options();
			break;
		}
	}		
	if (i !=10 )
		printf("wrong pass 3 trials !!");
}



void options(void)
{
	int option ; 
	char i = 0;
	int iddd=999;
	while(1)
	{
	printf("\n");
	printf("To Add New Patient Press 1\nTo Edit a Patient Record Press 2\nTo Reserve a Slot Press 3\nTo Cancel a Reservation Press 4 \nTo Back To The Last List Press 5\n : ");
	scanf("%d",&option);
	if (option==1)
	{
		i++;
		if(i==1)
		{
		HEAD=(node_t*)malloc(sizeof(node_t));
		printf("ENTER THE PATIENT NAME ");
		scanf("%s",&(HEAD->name));
		printf("ENTER THE PATIENT AGE ");
		scanf("%d",&(HEAD->age));
		printf("ENTER THE PATIENT GENDER (m FOR MALE , f FOR FEMALE ) : ");
		scanf("%s",&(HEAD->gender));
		printf("ENTER THE PATIENT ID ");
		scanf("%d",&(HEAD->ID));
		HEAD->next=NULL;
		HEAD->res=0;
		}
		else
		{
		TEMP=(node_t*)malloc(sizeof(node_t));
		printf("ENTER THE PATIENT NAME ");
		scanf("%s",&(TEMP->name));
		printf("ENTER THE PATIENT AGE ");
		scanf("%d",&(TEMP->age));
		printf("ENTER THE PATIENT GENDER (m FOR MALE , f FOR FEMALE ) : ");
		scanf("%s",&(TEMP->gender));
		printf("ENTER THE PATIENT ID ");
		int idd;
		scanf("%d",&idd);
		TEMP->next=NULL;
		TEMP->res=0;
		node_t*ptrr=HEAD;
		char flag=5;
		while ((ptrr->ID) != idd)
		{
			if (ptrr->next == NULL)
			{
				TEMP->ID = idd;
				flag=6;
				break;
			}
			ptrr=ptrr->next;
		}
		if (flag==5)
		{iddd++;
		printf("Repeated ID !! TRY AGAIN\n");
        printf("Temp ID is %d\n",iddd);
		TEMP->ID = iddd;
		}
		
		
		ptr=HEAD;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next =TEMP;
		} 
	}
	
	
	
	
	
	/*................................................*/
	
	else if (option == 2)
	{
		int id2;
		printf("Please Enter the ID to Edit : ");
		scanf("%d",&id2);
		node_t * ptr2;
		ptr2=HEAD;
		while (ptr2->ID != id2)
		{
			if (ptr2 -> next == NULL)
			{
				printf("You Entered a Wrong ID");
				break;
			}
			ptr2=ptr2->next;
			
		}
		if (ptr2->ID==id2)
		{
		
		char edit;
		
		printf("Press 1 to edit the Name\nPress 2 to edit the Age\nPress 3 to edit the Gender\nPress 4 to edit the ID\n");
		
		scanf("%d",&edit);
		
		if (edit ==1)
		{
			printf("Enter The New Name ");
			scanf("%s",&(ptr2 -> name));
		}
		
		else if (edit ==2)
		{
			printf("Enter The New Age ");
			scanf("%d",&(ptr2 -> age));
		}
		
		else if (edit ==3)
		{
			printf("Enter The New Gender ");
			scanf("%s",&(ptr2 -> gender));
		}
		
		else if (edit ==4)
		{
			printf("Enter The New ID ");
			scanf("%d",&(ptr2 -> ID));
		}
		else 
		{
			printf("You Entered a Wrong Number ");
		}
		}
		else 
		{
			printf("\nYou Entered a Wrong ID ");
        }
			
	
	    }
		
		
		
	
		
	/*.............................................*/
	
	
	else if (option == 3)
	{
		
		node_t* ptri ;
 	    ptri = HEAD ;
	    int app ;
	    int idi , fol=0;
		printf("available appointments are : \n 1 for 2:00-2:30 \n 2 for 2:30-3:00 \n 3 for 3:00-3:30 \n 4 for 3:30-4:00 \n 5 for 4:00-4:30\n\n ");
		for(int i = 0; i<5;i++)
        {
	       if(RES[i] == 0 )
	        {
		          printf ( "%d     ",i+1);
	        }  
        }
		printf("\nEnter id you want to reserve : ");
        scanf("%d",&idi);
		while(1)
	    {
		if(ptri->ID !=idi && ptri ->next != NULL)
		{
		ptri=ptri->next ; 	
		}
		else if (ptri ->ID == idi)
		{
		if(ptri->res==0)
		{
		printf("enter the appointment you want to reserve : ");
		scanf("%d",&app);
		if(app <=5 && RES[app-1] == 0)
		{
		ptri->res = app;
		RES[app-1]= 1;
    	break;
		}
		else
		{
			printf("wrong appointment ");
		}
		}
		else if(ptri->res!=0)
		{
			printf("\nYou Reserved A Nother Appointment");
			break;
		}
		}
		
		else 
		{
			printf(" ID doesnt exist \n\n");
			break;
		}
	    
		
	    }
	    
	}
	
	

	/*..................................................*/
	
	
	else if (option == 4)
	{
		int its , j;
		node_t * pptr;
		pptr=HEAD;
		printf("Enter The Patient ID ");
		scanf("%d",&its);
		while(1)
		{
			if (pptr->ID !=its && pptr->next != NULL)
			{
				pptr = pptr -> next ;
			}
			else if (pptr->ID == its)
			{
				
				RES[pptr->res - 1]=0;
				pptr->res = 0;
				break;
			}
			else 
			{
				printf("Wrong ID !");
				break;
			}
			
		}
		
	
	}
	




	/*..................................................*/
	
	else if (option==5)
	{
		printf("\nBack To The last list");
		break;
	}
	else
	{
		printf("Wrong Option");
	}
	}
		
}



/**************************UESR MODE**************************/




void usermode(void)
{
	
	int id , f=2;
	node_t*poi;
	poi=HEAD;
    printf("Enter The Patient ID : ");
    scanf("%d",&id);
while(poi->ID != id)
{
	if(poi->next==NULL)
	{
		f=3;
		break;
	}
	poi=poi->next;
}	
if (f==2)
{
	printf("Patient Name is %s\n",poi->name);
	printf("Patient Age is %d\n",poi->age);
	printf("Patient Gender is %c\n",poi->gender);
	printf("Patient ID is %d\n",poi->ID);
	if (poi->res==1)
	{
		printf("Your Reservation is From 2 : 2:30");
	}
	else if (poi->res==2)
	{
		printf("Your Reservation is From 2:30 : 3");
	}
	else if (poi->res==3)
	{
		printf("Your Reservation is From 3 : 3:30");
	}
	else if (poi->res==4)
	{
		printf("Your Reservation is From 3:30 : 4");
	}
	else if (poi->res==5)
	{
		printf("Your Reservation is From 4 : 4:30");
	}
	else
	{
		printf("No Reservation For you Today");
	}
	printf("\n\n");
}
else
{
	printf("Wrong ID\n");
}

}
