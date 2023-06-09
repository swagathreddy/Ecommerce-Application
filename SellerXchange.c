#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include<windows.h>

    char puma_item[3][20]={{"Puma T-shirt"},{"Puma sneakers"},{"pumaWomensShoes"}};
	int puma_price[]={3499,1899,3999};
	char puma_colour[3][10]={{"white"},{"black"},{"jade green"}};
	int puma_size[]={44,9,9};
	 
    char uspolo_item[3][20]={{"USpoloWomensTshirt"},{"USpoloTshirt"},{"USpoloJeans"}};
	int uspolo_price[]={999,699,1499};
	char uspolo_colour[3][10]={{"white"},{"black"},{"grey"}};
	int uspolo_size[]={44,44,46};

    char adidas_item[3][20]={{"adidas shoes"},{"AdidasRunningPants"},{"adidas Tshirt"}};
	int adidas_price[]={2499,999,799};
	char adidas_colour[3][10]={{"white"},{"black"},{"blue"}};
	int adidas_size[]={9,44,40};
	
	char other_item[4][20]={{"Mochi Sling BAG"},{"H&M Womens Shoes"},{"Nike FlipFlops"},{"Denim Jeans"}};
    int other_price[]={544,1699,799,1499};
    char other_colour[4][10]={{"pink"},{"grey"},{"blue"},{"blue"}};
    int other_size[4]={0,8,9,38};
    
struct details {
	char uname[50];
	int age;
	char password[100];
	char email[100];
	char mobile[10];
};

struct Shops {
	char shop[100];
	char item1[20];
	char colour1[10];
	int size1[10];
	char item2[20];
	char colour2[10];
	int size2[10];
	char item3[20];
	char colour3[10];
	int size3[10];
	char item4[20];
	char colour4[10];
	int size4[10];
	char item5[20];
	char colour5[10];
	int size5[10];
	int first, second, third, fourth,five;
};



struct Shops m[5];
struct details s[100];

void signup();

void account_validate();
int validate();
void login();
void Home();
void cart();
void shop();
void items();
void item_order(int item);
void seller();
void shop_initialize();
void Shop(int shop_choice);
void filter_brand_name();
void filter_colour();
void filter_price();

// Global variables declared
char t_name[100], t_password1[100];
char t_password2[100], t_email[100];
char t_mobile[100];
int flag = 1, i, j = 0, count = 0, caps = 0;
int Small = 0,total = 0 ,success = 0,special = 0, numbers = 0;
int x, choice,t_age, item_choice, n,shop_choice, search_choice, confirm,ch, item, shop_id,q;
int sum=0,number=0;
char s_name[50],s_email[100],s_mobile[10],s_address[50],s_business[50],s_no[50];

int main()
{
	
	while (1) {
    printf("\n\n      *                                                         Welcome to                                             *\n\n\n");
    printf("                                                             **     **                                               \n");
    printf("               ****   *****  *       *       *****   ****     **   **    *****  *   *    ***    *   *   *****   *****\n");
    printf("               *      *      *       *       *       *   *     ** **     *      *   *   *   *   **  *   *       *    \n");
    printf("               ****   ***    *       *       ***     ****       ***      *      *****   *****   * * *   *  **   ***  \n");
    printf("                  *   *      *       *       *       *  *     **  **     *      *   *   *   *   *  **   *   *   *    \n");
    printf("               ****   *****  *****   *****   *****   *   *   **    **    *****  *   *   *   *   *   *   *****   *****\n");
    printf("                                                            **      **                                                 ");
		// First Page
		
		printf("\n\n\t\t1)SIGNUP");
		printf("\n\t\t2)LOGIN");
		printf("\n\t\t3)EXIT");

		printf("\n\n\n\t\tEnter your choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			signup();
			break;
		}
		case 2: {
			login();
			break;
		}
		case 3: {
			printf("\n\t*************************Thank you\nVisit Again***********************\n\n");
				return 0;
				break;
		}
		default: {
			printf("\n\nPlease enter valid choice!!\n");
			break;
		}
		}
	}
}

void signup()
{

	printf("\n\n\t\t\t\t\t******************"
		"Welcome to Signup "
		"Page****************"
		"*\n\n");

	printf("\t\t\t\t\tEnter Your name : ");//name input
	scanf("%s", t_name);

	printf("\t\t\t\t\tEnter Your Email : ");//mail input
	scanf("%s", t_email);

	printf("\t\t\t\t\tEnter Password : ");//pass input
	scanf("%s", t_password1);

	printf("\t\t\t\t\tConfirm Password : ");//conform pass
	scanf("%s", t_password2);

	printf("\t\t\t\t\tEnter Your Mobile Number : ");//mobile input
	scanf("%s", t_mobile);

	printf("\t\t\t\t\tEnter Your Age : ");//age input
	scanf("%d", &t_age);
	
	FILE *p = fopen("A:\\Users\\swaga\\OneDrive\\Desktop\\userinfo_data.txt", "a");
    if (p == NULL) 
	{
        printf("Error opening file!\n");
        return;
    }
    fprintf(p, "%s\n", t_email);
    fprintf(p, "%s\n", t_password1);
    fclose(p);


	x = validate();
	if (x == 1) {

		// checking entered details follows the preset rules for signup
		account_validate();

		// login function appears
		login();
	}
}

int validate()
{
	// Name Validation
	for (i = 0; t_name[i] != '\0'; i++) {
		if (!((t_name[i] >= 'a' && t_name[i] <= 'z')
			|| (t_name[i] >= 'A' && t_name[i] <= 'Z'))) {
			printf("\n\tPlease enter the valid Name!\n");
			flag = 0;
			break;
		}
	}
	if (flag == 1) {
		count = 0;
		// Email ID Validation
		for (i = 0; t_email[i] != '\0'; i++) {
			if (t_email[i] == '@' || t_email[i] == '.')
				count++;
		}
		if (count >= 2 && strlen(t_email) >= 5) {
			// Password Validation
			if (!strcmp(t_password1, t_password2)) {
				if (strlen(t_password1) >= 8
					&& strlen(t_password1) <= 12) {
					caps = 0;
					Small = 0;
					numbers = 0;
					special = 0;
					for (i = 0; t_password1[i] != '\0';
						i++) {
						if (t_password1[i] >= 'A'
							&& t_password1[i] <= 'Z')
							caps++;
						else if (t_password1[i] >= 'a'
								&& t_password1[i] <= 'z')
							Small++;
						else if (t_password1[i] >= '0'
								&& t_password1[i] <= '9')
							numbers++;
						else if (t_password1[i] == '@'
								|| t_password1[i] == '&'
								|| t_password1[i] == '#'
								|| t_password1[i] == '*')
							special++;
					}
					if (caps >= 1 && Small >= 1
						&& numbers >= 1 && special >= 1) {
						// Age Validation
						if (t_age != 0 && t_age > 0) {
							// Mobile Validation
							if (strlen(t_mobile) == 10) {
								for (i = 0; i < 10; i++) {
									if (t_mobile[i] >= '0'
										&& t_mobile[i]
											<= '9') {
										success = 1;
									}
									else {
										printf("\n\n\tPlease Enter Valid Mobile Number\n\n");
										return 0;
										break;
									}
								}

								// Success flag to know
								// every inputs are valid
								if (success == 1)
									return 1;
							}
							else {
								printf("\n\n\tPlease Enter the 10 digit mobile number\n\n");
								return 0;
							}
						}
						else {
							printf("\n\n\tPlease Enter the valid age\n\n");
							return 0;
						}
					}
					else {
						printf(
							"\n\n\tPlease Enter the strong "
							"password, Your password must "
							"contain atleast one "
							"uppercase,Lowercase, Number "
							"and special character\n\n ");
						return 0;
					}
				}
				else {
					printf("\n\tYour Password is very "
						"short\nLength must between 8 "
						"to 12\n\n");
					return 0;
				}
			}
			else {
				printf("\n\tPassword Mismatch\n\n");
				return 0;
			}
		}
		else {
			printf("\n\tPlease Enter Valid E-Mail\n\n");
			return 0;
		}
	}
}

// Account Validation
void account_validate()
{
	for (i = 0; i < 100; i++) {
		// Check account already exist
		if (!(strcmp(t_email, s[i].email)
			&& strcmp(t_password1, s[i].password))) {
			printf("\n\n\tAccount Already Existed. Please "
				"Login !\n\n");
			login();
			break;
		}
	}

	// If no account present it creates
	if (i == 100) {
		strcpy(s[j].uname, t_name);
		s[j].age = t_age;
		strcpy(s[j].password, t_password1);
		strcpy(s[j].email, t_email);
		strcpy(s[j].mobile, t_mobile);
		j++;
		printf("\n\n\n\t\t\t\t\tAccount Successfully Created!\n\n");
	}
}

// Login function
void login()
{
	printf("\n\n\t\t\t\t\t******************Welcome to Login Page************************\n\n");
	printf("\n\n\t\t\tLOGIN\n\n");
	printf("\t\t\t\tEnter Your Email: ");
    scanf("%s", t_email);
	printf("\t\t\t\tnter Your Password: ");
	scanf("%s", t_password1);


    FILE *p = fopen("A:\\Users\\swaga\\OneDrive\\Desktop\\userinfo_data.txt", "r");
    if (p == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    int authenticated = 0; 
    while (fscanf(p, "%s\n", t_email) != EOF) {
        fscanf(p, "%s\n", t_password1);
        if (strcmp(t_email,t_email) == 0 && strcmp(t_password1,t_password1) == 0) {
            authenticated = 1;
            break;
        }
    }
    fclose(p);
               if(authenticated){
			    system("cls");
			    printf("\n\n\n\n\n\tYou are successfully logged in...\n\n");
	            Home();		
				}
	}
void Home(){

            
				printf("\tWe Provide two ways of search : \n ");
				printf("\t1) Search By Shop\n ");
				printf("\t2) Search by item\n ");
				printf("\t3) Become a Seller\n ");
				printf("\t4) Exit\n");
				printf("\tPlease Enter your choice : ");
				scanf("\t%d", &search_choice);

				switch (search_choice) {
				case 1: {
					shop();
					break;
				}
				case 2: {
					items();
					break;
				}
				case 3:{
					seller();
					break;
				}
				case 4:{
					Home();
					break;
				}
				default: {
					printf("\tPlease Enter the valid choice!!!\n\n");
					break;
				}
			}}
void shop_initialize()
{
    strcpy(m[1].shop, "MENS FASHION");
	strcpy(m[1].item1, "puma T-shirt");
	strcpy(m[1].colour1, "White");
	strcpy(m[1].size1, "44");
	strcpy(m[1].item2, "adidasrunningpants");
	strcpy(m[1].colour2, "black");
	strcpy(m[1].size2, "44");
	strcpy(m[1].item3, "Allen Solly shirt");
	strcpy(m[1].colour3, "jade green");
	strcpy(m[1].size3, "44||46");
	strcpy(m[1].item4, "USpoloTshirt");
	strcpy(m[1].colour4, "black");
	strcpy(m[1].size4, "32/36/40/44");
	strcpy(m[1].item5, "USpoloJeans");
	strcpy(m[1].colour5, "grey");
	strcpy(m[1].size5, "32/36/40/44");
	m[1].first = 3499;
	m[1].second = 999;
	m[1].third = 5999;
	m[1].fourth=699;
	m[1].five=1499;

	strcpy(m[2].shop, "WOMENS FASHION");
	strcpy(m[2].item1, "USpolowomensTshirt");
    strcpy(m[2].colour1, "pink/white");
	strcpy(m[2].size1, "34/36/38/40");
	strcpy(m[2].item2, "ZARA shirt");
	strcpy(m[2].colour2, "White/grey");
	strcpy(m[2].size2, "30/32/34/36");
	strcpy(m[2].item3, "Denim jeans");
	strcpy(m[2].colour3, "blue");
	strcpy(m[2].size3, "32/36/40/44");
    strcpy(m[2].item4, "Adidas Tshirt");
	strcpy(m[2].colour4, "blue");
	strcpy(m[2].size4, "32/36/40/44");
	strcpy(m[2].item5, "Mochi Sling BAG");
	strcpy(m[2].colour5, "pink");
	strcpy(m[2].size5, "Onesize");
	m[2].first = 999;
	m[2].second = 2000;
	m[2].third = 1499;
	m[2].fourth=799;
	m[2].five=544;

	strcpy(m[3].shop, "FOOTWEAR");
	strcpy(m[3].item1, "Puma sneakers");
	strcpy(m[3].colour1, "Black");
	strcpy(m[3].size1,"UK-8/9/10");
	strcpy(m[3].item2, "Adidas Shoes");
	strcpy(m[3].colour2, "White");
	strcpy(m[3].size2, "UK-6/7/8/9");
	strcpy(m[3].item3, "nike Flip flops");
	strcpy(m[3].colour3, "blue");
	strcpy(m[3].size3, "UK-9/10");
	strcpy(m[3].item4, "PumsWomensShoes");
	strcpy(m[3].colour4, "jade green");
	strcpy(m[3].size4, "9");
	strcpy(m[3].item5, "H&M WomensShoes");
	strcpy(m[3].colour5, "grey");
	strcpy(m[3].size5, "32/36/40/44");
	m[3].first = 1899;
	m[3].second = 2499;
	m[3].third = 799;
	m[3].fourth=3999;
	m[3].five=1699;
}

void shop()
{
	// Shop Products are collected
	shop_initialize();

	// Showing all the availableshop
	printf("\n\n\tPlease Choose the Shop \n\t1) %s\n\t2) "
		"%s\n\t3) %s",
		m[1].shop, m[2].shop, m[3].shop);
	printf("\n\t4) Exit\n\n ");
	printf("\tPlease select the shop\t");

	// Asking for choice
	scanf("\t%d", &shop_choice);
	if (shop_choice > 4) {
		printf("\tPlease Enter the valid choice\n\n");
		shop();
	}
	else if (shop_choice == 4)
		Home();
	else{
		// Shop function called with your choice
		Shop(shop_choice);
	}
}

// Function to implement the shop
void Shop(int shop_choice)
{
	total = 0;

	while (1) {

		printf("\n\n\tList of items available in %s\n\n",m[shop_choice].shop);
        for(int i=0;i<1;i++){
		printf("\t1) %s --> %d\n\tcolour-%s\tsize-%s\n\n",m[shop_choice].item1,
			m[shop_choice].first,m[shop_choice].colour1,m[shop_choice].size1);

		printf("\t2) %s --> %d\n\tcolour-%s\tsize-%s\n\n\t3) %s --> %d\n\tcolour-%s\tsize-%s\n\n",
			m[shop_choice].item2, m[shop_choice].second,m[shop_choice].colour2,m[shop_choice].size2,
			m[shop_choice].item3, m[shop_choice].third,m[shop_choice].colour3,m[shop_choice].size3);
			
		printf("\t4) %s --> %d\n\tcolour-%s\tsize-%s\n\n\t5) %s --> %d\n\tcolour-%s\tsize-%s\n\n",
			m[shop_choice].item4, m[shop_choice].fourth,m[shop_choice].colour4,m[shop_choice].size4,
			m[shop_choice].item5, m[shop_choice].five,m[shop_choice].colour5,m[shop_choice].size5);
		}

		printf("\t6) Cart\n\t7) Exit\n\n");
		printf("\tPlease enter Your Choice : ");
		scanf("\t%d", &item_choice);                                              

		// Get the input for no of items to calculate the
		// total amount
		if (item_choice == 1) {
			printf("\tenter the size:");
			scanf("\t%d",&q);
			printf("\tPlease Enter the Count of %s\t", m[shop_choice].item1);
			scanf("\t%d", &n);
			 number=number+n;
			total = total + (n * m[shop_choice].first);
			sum=sum+total;
		}
		
		else if (item_choice == 2) {
			printf("\tenter the size:");
			scanf("\t%d",&q);
		    printf("\tPlease Enter the Count of %s : ", m[shop_choice].item2);
			scanf("\t%d", &n);
			 number=number+n;
			total = total + (n * m[shop_choice].second);
			sum=sum+total;
		}
		else if (item_choice == 3) {
			printf("\tenter the size:");
			scanf("\t%d",&q);
			printf("\tPlease Enter the Count of %s : ", m[shop_choice].item3);
			scanf("\t%d", &n);
			 number=number+n;
			total = total + (n * m[shop_choice].third);
			sum=sum+total;
		}
			else if (item_choice == 4) {
			printf("\tenter the size:");
			scanf("\t%d",&q);
			printf("\tPlease Enter the Count of %s : ", m[shop_choice].item4);
			scanf("\t%d", &n);
			 number=number+n;
			total = total + (n * m[shop_choice].fourth);
			sum=sum+total;
		}
			else if (item_choice == 5) {
			printf("\tenter the size:");
			scanf("\t%d",&q);
			printf("\tPlease Enter the Count of %s : ", m[shop_choice].item5);
			scanf("\t%d", &n);
			 number=number+n;
			total = total + (n * m[shop_choice].five);
			sum=sum+total;
		}

		else if (item_choice == 6) {
			cart();
		}
		else if (item_choice == 7) {
			shop();
		}
		else {
			printf("\tPlease Enter the valid Choice\n\n");
		}
	}
}
void filter_brand_name(){
	int chh;
	printf("\n\tselect brand name\n");
	printf("\t1)PUMA\n\t2)USPOLO\n\t3)ADIDAS\n");
	printf("\tenter your choice:\t");
	scanf("\t%d",&chh);
	printf("\n\n\t*******************************************************************************\n");
    printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
	printf("\t*******************************************************************************\n");
    int choice;
	for(int j=0;j<3;j++){
				switch(chh){
					
					case 1:printf("\t%d   %s\t\t\t%d\t\t%s\t\t%d\n",j,puma_item[j],puma_price[j],puma_colour[j],puma_size[j]);
					break;
					
                    case 2:printf("\t%d    %s\t\t\t%d\t\t%s\t\t%d\n",j,uspolo_item[j],uspolo_price[j],uspolo_colour[j],uspolo_size[j]);
					break;

					case 3:printf("\t%d   %s\t\t\t%d\t\t%s\t\t%d\n",j,adidas_item[j],adidas_price[j],adidas_colour[j],adidas_size[j]);
				    break;
					
				}
	        }    
			int chhh; 
			printf("\tif you want to buy items from here directly,\n\tpress 1 for PUMA\n\tpress 2 for USPOLO\n\tpress 3 for ADIDAS\n\tpress 4 for previous page:\t");
			scanf("\t%d",&chhh);
			if(chhh==1){
				printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &item_choice);  	
			        if(item_choice == 0){
	                printf("\tPlease Enter the Count of %s\t",puma_item[0]);
			        scanf("\t%d", &n);
			         number=number+n;
					total = total + (n * puma_price[0] ); 
					}
		            else if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", puma_item[1]);
			        scanf("\t%d", &n);
			         number=number+n;
			        total = total + (n * puma_price[1]);
		            }
		            else if(item_choice == 2){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",puma_item[2]);
			        scanf("\t%d", &n);
			         number=number+n;
			        total = total + (n * puma_price[2]);
	             	}
	            	else {
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
			       sum=sum+total;
         	}   
	 
	        else if(chhh==2){
	            	printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &item_choice);  
					if(item_choice == 0){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",uspolo_item[0]);
			        scanf("\t%d", &n);
			         number=number+n;
					total = total + (n * uspolo_price[0] ); 
					}
		            else if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", uspolo_item[1]);
			        scanf("\t%d", &n);
			         number=number+n;
			        total = total + (n * uspolo_price[1]);
		            }
		            else if(item_choice == 2){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",uspolo_item[2]);
			        scanf("\t%d", &n);
			         number=number+n;
			        total = total + (n * uspolo_price[2]);
	             	}
	            	else {
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
		            sum=sum+total;
			       } 
			
			else if(chhh==3){
				   	 printf("\tPlease enter your Choice : ");
		            scanf("\t%d", &item_choice);  
					if(item_choice == 0){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",adidas_item[0]);
			        scanf("\t%d", &n);
			         number=number+n;
					total = total + (n * adidas_price[0] ); 
					}
		            else if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", adidas_item[1]);
			        scanf("\t%d", &n);
			         number=number+n;
			        total = total + (n * adidas_price[1]);
		            }
		            else if(item_choice == 2){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",adidas_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * adidas_price[2]);
	             	}
	                else{
	                	printf("\tenter valid option\n");
					}
				      sum=sum+total;
				  }
			else if(chhh==4){
		         	items();
		            }
				       
}
							                        

		// Get the input for no of items to calculate the
		// total amount
		
		
	void filter_colour(){
		int colour;
		printf("\tCOLOUR OPTIONS\n\tpress 1 for WHITE\n\tpress 2 for BLACK\n\tpress 3 for BLUE:\n\tpress 4 for previous page\t");
		scanf("\t%d",&colour);
	    if(colour==1){
	    	printf("\n\n\t******************************************************************************\n");
            printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
	        printf("\t*******************************************************************************\n");
	        printf("\t1) \t%s\t\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t\t%d\t\t%s\t\t%d\n",
			puma_item[0],puma_price[0],puma_colour[0],puma_size[0],uspolo_item[0],uspolo_price[0],uspolo_colour[0],uspolo_size[0],
			adidas_item[0],adidas_price[0],adidas_colour[0],adidas_size[0]);
	    	}
	    else if(colour==2){
	    	printf("\n\n\t*******************************************************************************\n");
            printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
	        printf("\t*******************************************************************************\n");
	        printf("\t1) \t%s\t\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t%d\t\t%s\t\t%d\n",
			puma_item[1],puma_price[1],puma_colour[1],puma_size[1],uspolo_item[1],uspolo_price[1],uspolo_colour[1],uspolo_size[1],
			adidas_item[1],adidas_price[1],adidas_colour[1],adidas_size[1]);
	    	}
	    else if(colour==3){
	    	printf("\n\n\t*******************************************************************************\n");
            printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
	        printf("\t*******************************************************************************\n");
	        printf("\t1) \t%s\t\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t%d\t\t%s\t\t%d\n",
			adidas_item[2],adidas_price[2],adidas_colour[2],adidas_size[2],other_item[2],other_price[2],other_colour[2],other_size[2],
			other_item[3],other_price[3],other_colour[3],other_size[3]);
	    	}
	    	int chhh; 
			printf("\tif you want to buy items from here directly,\n\tpress 1 for WHITE\n\tpress 2 for BLACK\n\tpress 3 for BLUE:\t\n");
			scanf("\t%d",&chhh);
			if(chhh==1){
	                printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &item_choice);  
					if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",puma_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * puma_price[0] ); 
					}
		            else if(item_choice == 2){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", uspolo_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * uspolo_price[0]);
		            }
		            else if(item_choice == 3){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",adidas_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * adidas_price[0]);
	             	}
	            	else {
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
			       sum=sum+total;
              	} 
				   
	        else if(chhh==2){
	             	printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &item_choice);  
					if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",puma_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * puma_price[1] ); 
					}
		            else if(item_choice == 2){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", uspolo_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * uspolo_price[1]);
		            }
		            else if(item_choice == 3){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",adidas_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * adidas_price[2]);
	             	}
	             	sum=sum+total;
	             }
	             	
	        else if(chhh==3){
	                printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &item_choice);  
					if(item_choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",adidas_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * adidas_price[2] ); 
					}
		            else if(item_choice == 2){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", other_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * other_price[2]);
		            }
		            else if(item_choice == 3){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",other_item[3]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * other_price[3]);
	             	}
	            	else {
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
			       sum=sum+total;
              	}      	
	        else if(chhh=4){
		        items();
		        }
			} 
		
	    	
	    void filter_price(){
		int choose,choice,select;
		printf("\tselect your price range\n\t1)500-1000\n\t2)1001-2000\n\t3)2001-5000\n");
		scanf("\t%d",&choose);
        printf("\n\n\t*******************************************************************************\n");
        printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
	    printf("\t*******************************************************************************\n");
	    if(choose==1){
		printf("\t1)\t%s\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t%d\t\t%s\t\t%d\n\t4)\t%s\t\t\t%d\t\t%s\t\t%d\n"
		"\t5)\t%s\t\t\t%d\t\t%s\t\t%d\n\t6)\t%s\t\t\t%d\t\t%s\t\t%d\n",
			uspolo_item[0],uspolo_price[0],uspolo_colour[0],uspolo_size[0],uspolo_item[1],uspolo_price[1],uspolo_colour[1],uspolo_size[1],
			adidas_item[1],adidas_price[1],adidas_colour[1],adidas_size[1],adidas_item[2],adidas_price[2],adidas_colour[2],adidas_size[2],
			other_item[0],other_price[0],other_colour[0],other_size[0],other_item[2],other_price[2],other_colour[2],other_size[2]);
		}
		else if(choose==2){		                                                               
		printf("\t1)\t%s\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t%d\t\t%s\t\t%d\n\t4)\t%s\t\t%d\t\t%s\t\t%d\n",
		     puma_item[1],puma_price[1],puma_colour[1],puma_size[1],uspolo_item[2],uspolo_price[2],uspolo_colour[2],uspolo_size[2],
			other_item[1],other_price[1],other_colour[1],other_size[1],other_item[3],other_price[3],other_colour[3],other_size[3]);
		}
	    else if(choose==3){
		printf("\t1)\t%s\t\t%d\t\t%s\t\t%d\n\t2)\t%s\t\t%d\t\t%s\t\t%d\n\t3)\t%s\t\t%d\t\t%s\t%d\n",
			adidas_item[0],adidas_price[0],adidas_colour[0],adidas_size[0],puma_item[0],puma_price[0],puma_colour[0],puma_size[0],
			puma_item[2],puma_price[2],puma_colour[2],puma_size[2]);
		}
	                
		printf("\tif you want to buy items from here directly,\n\tpress 1 for 500-1000\n\tpress 2 for 1001-2000\n\tpress 3 for 2001-5000:\t");
		scanf("\t%d",&select);
			if(select==1){
	                printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &choice);  
					if(choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",uspolo_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * uspolo_price[0] ); 
				    }
					else if(choice == 2){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",uspolo_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * uspolo_price[1] ); 
				}
					else if(choice == 3){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",adidas_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * adidas_price[1] ); 
				}
					else if(choice == 4){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",adidas_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * adidas_price[2] ); 
				}
					else if(choice == 5){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",other_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * other_price[0] ); 
				}	else if(choice == 6){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",other_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * other_price[2] ); 
				} 
				else{
					printf("\tenter valid option\n");
				}
				sum=sum+total; 
			}  
			       
			else if(select==2){
	            	printf("\tPlease enter your Your Choice : ");
		            scanf("\t%d", &choice);  
					if(choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",puma_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * puma_price[1] ); 
					}
		            else if(choice == 2){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
		            printf("\tPlease Enter the Count of %s : ", uspolo_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * uspolo_price[2]);
		            }
		            else if(choice == 3){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",other_item[1]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * other_price[1]);
	             	}
	             	else if(choice == 4){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",other_item[3]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * other_price[3]);
	             	}
	            	else {
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
		            sum=sum+total; 
			       } 
            else if(select==3){
				   	printf("\tPlease enter your Your Choice : ");
		            scanf("%d", &choice);  
					if(choice == 1){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",adidas_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * adidas_price[0] ); 
					}
		            else if(choice == 2){
		        	printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s : ",puma_item[0]);
			        scanf("\t%d", &n);
			        number=number+n;
			        total = total + (n * puma_price[0]);
	             	}
	             	else if(choice == 3){
			        printf("\tenter the size:");
			        scanf("\t%d",&q);
			        printf("\tPlease Enter the Count of %s\t",puma_item[2]);
			        scanf("\t%d", &n);
			        number=number+n;
					total = total + (n * puma_price[2] ); 
					}
	                else{
		         	printf("\tPlease Enter the valid Choice\n\n");
		            }
		            sum=sum+total; 
			       }  
				else if(select==4){
				   	items();
				   }   
			}
	
		

void items()
{
	total = 0;
	// Initialize all the Shop and their items
	shop_initialize();
	while (1) {
        //Showing all the choices of items
		printf("\n\n\tPlease choose the item\n");
		printf("\t*******************************************************************************\n");
        printf("\tS.NO\tITEM\t\t\t\tPRICE\t\tCOLOUR\t\tSIZE\n");
		printf("\t*******************************************************************************\n");
		printf("\t1) \t%s\t\t\t%d\t\t%s\t\t%s\n\t2)\t%s\t\t%d\t\t%s\t\t%s\n",
			m[1].item1, m[1].first,m[1].colour1,m[1].size1, m[1].item2,
			m[1].second,m[1].colour2,m[1].size2);

		printf("\t3)\t%s\t\t%d\t\t%s\t%s\n\t4)\t%s\t\t\t%d\t\t%s\t\t%s\n",
			m[1].item3, m[1].third,m[1].colour3,m[1].size3, m[1].item4,
			m[1].fourth,m[1].colour4,m[1].size4);

		printf("\t5)\t%s\t\t\t%d\t\t%s\t\t%s\n\t6)\t%s\t\t%d\t\t%s\t\t%s\n",
			m[1].item5, m[1].five,m[1].colour5,m[1].size5, m[2].item1,
			m[2].first,m[1].colour1,m[1].size1);

		printf("\t7)\t%s\t\t\t%d\t\t%s\t%s\n\t8)\t%s\t\t\t%d\t\t%s\t\t%s\n",
			m[2].item2, m[2].second,m[2].colour2,m[2].size2, m[2].item3,
			m[3].third,m[3].colour3,m[3].size3);

		printf("\t9)\t%s\t\t\t%d\t\t%s\t\t%s\n\t10)\t%s\t\t\t%d\t\t%s\t\t%s\n", m[2].item4,
			m[2].fourth,m[2].colour4,m[2].size4,m[2].item5, 
			m[2].five,m[2].colour5,m[2].size5);
			
		printf("\t11)\t%s\t\t\t%d\t\t%s\t\t%s\n\t12)\t%s\t\t\t%d\t\t%s\t\t%s\n",
			m[3].item1, m[3].first,m[3].colour1,m[3].size1, m[3].item2,
			m[3].second,m[3].colour2,m[3].size2);
			
		printf("\t13)\t%s\t\t\t%d\t\t%s\t\t%s\n\t14)\t%s\t\t\t%d\t\t%s\t%s\n",
			m[3].item3, m[3].third,m[3].colour3,m[3].size3, m[3].item4,
			m[3].fourth,m[3].colour4,m[3].size4);
			
		printf("\t15)\t%s\t\t\t%d\t\t%s\t\t%s\n",
			m[3].item5, m[3].five,m[3].colour5,m[3].size5);
			
		printf("\n\t16)If you want to apply any fiters press 'Y' if no 'N'\n\n\t\t");
		char ch;
		int option;
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y'){
			printf("\tSelect filter\n");
			printf("\tPress 1 for Brand name\n");
			printf("\tPress 2 for colour\n");
			printf("\tPress 3 for price\n");
			repeat:
		    printf("\tEnter your choice\t:");
			scanf("\t%d",&option);
			switch(option){
				case 1:filter_brand_name();
				break;
				case 2:filter_colour();
				break;
				case 3:filter_price();
				break;
				default:printf("\tinvalid option try again\n");
				        goto repeat;
						break;
			}
		}
		printf("\n\n\t17) View your cart\n");
		printf("\t18)Exit to Home\n");
		printf("\t19)exit to filters menu\n");
		printf("\n\tPlease Enter Your Choice : ");
		scanf("\t%d", &item);
        // Moves to the cart
		if (item == 17)
			cart();
		else if (item == 18)
			Home();
		else if(item==19)
			items();
		// Function to get the no of items and to calculate
		// the total amount of the order.
		else
			item_order(item);
	}
}


// item_order function to process items ordered
void item_order(int item)
{

	if (item >= 1 && item <= 5)
		shop_id = 1;
	else if (item >= 6 && item <= 10)
		shop_id = 2;
	else
		shop_id = 3;
	if ((item % 5) == 1) {
		// Asking for choice of product
		printf("\tPlease Enter the Count of %s : ", m[shop_id].item1);
		scanf("\t%d", &n);
		number=number+n;
		total = total + (n * m[shop_id].first);
		sum=sum+total;
	}
	else if ((item % 5) == 2) {
		// Asking for choice of product
		printf("\tPlease Enter the Count of %s\t", m[shop_id].item2);
		scanf("\t%d", &n);
		number=number+n;
		total = total + (n * m[shop_id].second);
		sum=sum+total;
	}
	else if ((item % 5) == 0) {
		// Asking for choice of product
		printf("\tPlease Enter the Count of %s\t",m[shop_id].item3);
		scanf("\t%d", &n);
		number=number+n;
		total = total + (n * m[shop_id].third);
		sum=sum+total;
	
}
}


// Function to implement the cart
void cart()
{
	// details about the products in cart
	printf("\n\n\n\n\t\t\t*********************************"
		"Cart*********************************\n");
	printf("*\t\t\t                           Your cart details                           \n");
	printf("\n\t\tYour total cart quantity:%d",number);
	printf("\n\n\t\tYour Total Order Amount is : %d\n",sum);
	printf("\n\t\tDo You wish to order (YES=1/NO=0) : ");
	scanf("\t%d", &ch);
	if (ch == 1) {
		char address[100],city[20],state[20];
		int pincode,money;
		printf("\n\n\t\tEnter shipping address:\t");
        scanf("\t\t%s",&address);
		printf("\t\tEnter city:\t");
        scanf("\t\t%s",&city);
		printf("\t\tEnter State:\t");
        scanf("\t\t%s",&state);
		printf("\t\tEnter Pincode:\t");
        scanf("\t\t%d",&pincode);
		printf("\n\t\tSelect Payment option:\t");
		printf("\n\t\t1)Cash on Delivery\n\t\t2)UPI\n\t\t");
		scanf("%d",&money);
		if(money==1){
			printf("\t\tYou have selected Cash on Delivery");
		}
		else if(money==2){
			char upi[50];
			printf("\t\tplease enter your UPI Id:\t");
			scanf("\t\t%s",upi);
		}
		printf("\n\n\t\t\t\tverifying your payment....");
        sleep(5);
		printf("\n\n\t\t\tPayment is successfull...\n\t\t\tWOOOHOOO,Thank You for your Order,%s\n\n",t_name);
		sleep(3);
		printf("\t\t\tThe Tracking details will be sent to your mail:%s\n\n",t_email);
		printf("\t\t\t*            ********Thankyou for placing order**********               *\n\n\n");
		exit(1);
   	    }
	else if (ch == 0) {
		printf("\t\tTo cancel Your Order = 1 \nTo Exit = 0 ");
		printf("\t\tSelect option : ");
		scanf("\t\t%d", &confirm);
		if (confirm == 1) {
			//Failed
			printf("\n\n\t\tOops! Your item is cancelled!! "
				"\t\tExiting..\n\n");
			printf("\t\tThank You visit again!\n");
			main();
			return;
		}
		else {
			// Product is bought
			printf("\n\n\t\t\t\t************Thank "
				"You******************\n\n");
			login();
		}
	}
	else {
		// Asking for choice
		printf("\n\n\t\tPlease Enter the correct choice\n\n ");
		cart();
	}
}

void seller(){
	int n;
	printf("\n\n\tTo proceed please enter your details:\n\n");

	printf("\tEnter Your name : ");
	scanf("%s", s_name);

	printf("\tEnter Your Email : ");
	scanf("%s", s_email);

	printf("\tEnter Your Mobile Number : ");
	scanf("%s", s_mobile);
	
	printf("\tIn which State or City your shop or company is located: ");
	scanf("%s", s_address);
	
	printf("\tName of your business:");
	scanf("%s",s_business);
	
	printf("\tBusiness registration number:");
	scanf("%s",s_no);
	
	printf("\tSelect on which categories your goods belongs to:\n");
	printf("\t1)FASHION\t\t2)ELECTRONICS\n\t3)HOME\t\t\t4)FURNITURE\n\t5)APPLIANCES\t\t6)GROCERY\n\n");
	scanf("%d",&n);
	printf("\n\tPlease wait until we verify your details...\n");
	sleep(6);
	printf("\tPlease attach if any photos,videos,legal documents of your business to our email:SellerXchange@gmail.com");
	printf("\n\n\tOur team will contact you soon to proceed further....\n\n");
	printf("\t*******************Thankyou for choosing us....*******************\n\n");
}