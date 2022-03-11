#include<stdio.h>
#include<string.h>
#include<stdio.h>
struct data
{
	int a;
	char b[100];
	char c[100];
	char d[100];
}data1;
struct admin
{
	char a[100];
	char b[100];
}data2;
struct manage
{
	int code;
	char name[100];
	int cp;
	int qty;
	int sp;
}data3,bill;
struct manage2
{
	char n[15];
 }data4;
int b,Q;
 
FILE*ptr,*fptr,*ffptr;

void login (struct data data1);                  // for customer signup
void login2 (struct data data1);                 // for customer login
void nextpage(struct data data1);                // for after customer login, next page of customer management 
void customer(struct manage data3);              // for choosing and adding items to purchase
void customerBill(struct manage data3);          // bill of purchased items
void manager(struct admin data2);                // manager login 
void catgory(int n);                             // categories for manager to perfrom action
void addproduct(struct manage data3);            // categories to add products
void ADD(struct manage data3);                   
void updatestock(struct manage data3);           // categories in which to do updatation 
void update(struct manage data3);
void viewstock(struct manage data3);             // categories to show stocks
void view(struct manage data3);                    
void showprofit(struct manage data3);            // Total profit
void showsell(struct manage data3);              //Total sell 
int main()
{
system("color f1");	    
while(1)
{
	printf("");
    
	printf("\t\t\t -------------------\n");
	
	printf("\t\t\t WELLCOME TO JESHISS|\n");
	
	printf("\t\t\t -------------------\n");
	printf("\n\n\t\t\t -------------------\n\t");
	printf("\t1. PRESS 1 FOR CUSTOMER LOGIN AND SIGNUP.\n");
    printf("\t\t2. PRESS 2 FOR MANAGER LOG IN.\n");
    printf("\t\t3. PRESS 3 FOR EXIT.\n");
    printf("\t\t\t -------------------\n\t\n       ");
     int start;
     char c;
	 scanf(" \t\t\t\t%d",&start);
	 fflush(stdin);
	 if(start!=1&&start!=2&&start!=3)
	{
		printf("Please enter correct num\n");
		printf("Enter b to go back\n ");
	     c=getch();
		 if(c==98)
		 {
		 	system("cls");
		 	main();
		 }		
	}
	system("cls");
	if(start==1)
	{	
       int option;
        printf(" 1. SIGN UP IF NEW ");    printf("            2.LOG IN IF HAVE AN ACCOUNT\n ");
        scanf("\n%d",&option);
        fflush(stdin);
    if(option!=1&&option!=2)
    {
	    printf("please enter the correct num\n");
	    printf("Enter b to go back\n");
	    c=getch();
	    if(c==98)
	  {
	     system("cls");
	      main();
      }
    }
        system("cls");
        switch(option)
{	
        case (1):
		{	
        login (data1);                         // customer signup  
        break;
		}

        case (2):
		{
        login2 (data1);                       // customer login
        }
}
    }
      else if(start==2)
    {
       manager(data2);                               // manager login
    }
	  else if(start==3)                        // END program
	  break;
}

}
void login (struct data data1)
{	
   int b,i;
   char ch;
	FILE *fptr;
    fptr=fopen("DATA.txt","a");
    if(fptr==NULL)
    {
    	printf("NOT FINDING THE DATA");
    	return;
	}    
     printf(" Enter your full name:  ");gets(data1.b);              
	              fflush(stdin);				  				  	
	 printf(" Create an E-mail address:  ");gets(data1.c);	
	              fflush(stdin);
	 printf(" Enter your contact no#:  ");
	 scanf("%d",&data1.a); 
	 fflush(stdin);                                                       //   CUSTOMER SIGN-UP
	 printf(" Create a strong password  ");gets(data1.d);
	 fflush(stdin);				
     fwrite(&data1,sizeof(data1),1,fptr);
	   fclose(fptr);
	   printf("       *CONGRATULATIONS YOU HAVE CREATED YOUR ACCOUNT SUCCESSFULLY*\n  ");
	   printf("\t                PRESS b to go back ");
	 ch=getch();
	 if(ch==98)
	 {
	 	system("cls");
		return;
	 }
}

void login2 (struct data data1)
{
	FILE*fptr;
	fptr=fopen("DATA.txt","r");
	if(fptr==NULL)
	{
		printf("File not found");
		return;
	}
	int i,j;                            // j for stars 
	int a,b,d,n;                                          // CUSTOMER LOG-IN
	char x[100],y[100],c;
	printf(" Enter your E-mail address:   ");gets(x);
	fflush(stdin);
	system("cls");
	printf(" Enter your password:   ");
	for(i=0;y[i-1]!=13;i++)                      // TILL USER DOESN'T PRESS ENTER
	{
	y[i]=getch();
	if(y[i]==13)
	{
		
	}
	else if(y[i]==8)                              // TILL USER DOESN'T PRESS BACKSPACE
	{
		system("cls");
		printf(" Enter your password:   ");
		i--;
		for(j=0;j<i;j++)
		printf("*");
		i--;
	}
	else
	printf("*");
	}
    y[i-1]='\0';
	while(fread(&data1,sizeof(data1),1,fptr))
{
		a=strcmp(data1.c,x);
		b=strcmp(data1.d,y);
		
		if(a==0&&b==0)                                 // if both id and password are true
     {
	     nextpage(data1);
     }	
}
		if(a!=0||b!=0)                                  // either id or password is incorrect
	{
			printf("\nIncorrect ID or Password");
		
		printf("\nWant to Re-Enter ID and Password? press 'r' \n");
		d=getch();
		if(d==114)                                                  
		{
			system("cls");
			login2(data1);
		}	
	}	
}

void nextpage(struct data data1)                     // if both id and password is true welcome customer 
{
	int n;
	char c;
	system("cls");	
	printf("\n           ************************WELCOME*************************          ");
		
	while(1)                               
		{	
		system("cls");		
		printf("                       \nchoose the category:\n ");
		printf(" |1.T-Shirts  |\n  ");
		printf("|2.Shirts  |\n  ");
		printf("|3.Jeans   |\n  "); 
		printf("|4.Shoes   |\n  ");
		printf("5.To exit customer login\n");			
		scanf("%d",&n);					
		fflush(stdin);
		if(n==1)
			{				
			 strcpy(data4.n,"t-shirts.txt");                        // because 2 strings never allow assignment operator
		     customer(data3);
			}
		else if(n==2)
			{
			 strcpy(data4.n,"shirts.txt");
			 customer(data3);
			}
		else if(n==3)
			{
			 strcpy(data4.n,"paints.txt");
			 customer(data3);
			}
		else if(n==4)
			{
			 strcpy(data4.n,"shoes.txt");
			 customer(data3);
			}
		else if(n==5)
			{
			 system("cls");                               
			 main(); 
			}
	   }
}
		
void manager(struct admin data2)                           //  MANAGER LOG-IN
{
	int i,j;
	int c,d,n;
	char a[50],b[50],e;
	printf("Dear Manager Enter your E-mail address:    ");gets(a);
	fflush(stdin);
	for(i=0;b[i-1]!=13;i++)                            //  TILL MANAGER PRESS ENTER
	{
	 b[i]=getch();
	 if(b[i]==13)
	 {	
	 
	 }
	 else if(b[i]==8)
	 {
	  system("cls");
	  i--;
	for(j=0;j<i;j++)
	{
	  printf("*");
	}	
	  i--;
	 }
	 else{
			printf("*");
         }
}
	b[i-1]='\0';
	
	FILE*ptr;
	ptr=fopen("DATA1.txt","r");
	if(ptr==NULL)
	{
		printf("File not found");
		return;
	}
	while(fread(&data2,sizeof(data2),1,ptr))
	{
		c=strcmp(data2.a,a);                           //  checking both id and password
		d=strcmp(data2.b,b);
		if(c==0&&d==0)                             // if id and password is correct
		{
			system("cls");
			printf(" \n     *************************** WELCOME MANAGER ************************\n");
			catgory(n);		
        }
    }
	    if(c!=0||d!=0)                              //  if id and password is incorrect
	{
		printf("Incorrect Id or password\n");
		printf("If u want to Re-Enter ID and Password press 'r' \n");printf("  Enter 'b' to go back\n");
		e=getch();
		if(e==114)
		{		
		system("cls");
		manager(data2);
	    }
	    else if(e==98)                          
	    {
		system("cls");
		return;
	    }
	}
	fclose(ptr);
}
void catgory(int n)
{                                //   categories of manager managemnet
	while(1)
	{	
       printf("1. * ADD STOCK *   \n"); 

       printf("2. * UPDATE STOCK *\n");

       printf("3. * SHOW STOCK *  \n");

       printf("4. * SHOW PROFIT * \n");

       printf("5. * SHOW TOTAL SALE *\n");

       printf("6. ** To exit manager login **\n"); 

		scanf("%d",&n);
		fflush(stdin);
		if(n==1)
		{
			system("cls");
			addproduct(data3);
		}
		else if(n==2)
		{
			system("cls");
			updatestock(data3);
		}
		else if(n==3)
		{
			system("cls");
			viewstock(data3);
		}
			else if(n==6)
		{
				system("cls");
				break;
		}
			else if(n==4)
		{
			system("cls");
			showprofit(data3);
		}
			else  if(n==5)
		{
			system("cls");
			showsell(data3);
		}
	}
}
	
void addproduct(struct manage data3)
{
	while(1)
	{
	
	system("cls");
	int a,n;
	printf("                            Select the category:\n");
	printf("1.  T-SHIRTS\n"); 
	printf("2.  SHIRTS\n"); 
	printf("3.  PAINTS\n"); 
	printf("4.  SHOES\n");
	printf("5.  To go back\n");     
	scanf("%d",&a);
	fflush(stdin);
	        if(a==1)
	        {
	           system("cls");
	           strcpy(data4.n,"t-shirts.txt");
	           ADD(data3);
	         
			}
			else if(a==2)
			{
				system("cls");
				strcpy(data4.n,"shirts.txt");
				ADD(data3);
			}
			else if(a==3)
			{
				system("cls");
				strcpy(data4.n,"paints.txt");
				ADD(data3);
			}
			else if(a==4)
			{
				system("cls");
				strcpy(data4.n,"shoes.txt");
				ADD(data3);
			}
			else if(a==5)
			{
				system("cls");
				return;
			}			
	}
}
		
void ADD(struct manage data3)          //   TO ADD STOCK
		{
			while(1)
			{
			  system("cls");
		      FILE*ptr;
		      char d;
		      ptr=fopen(data4.n,"a");		
			 printf("Enter the product code  ");scanf("%d",&data3.code);   
			
			 fflush(stdin);
			
			 printf("\nEnter the product name  ");gets(data3.name);
			
			 fflush(stdin);
			
			 printf("\nEnter the cost price  ");scanf("%d",&data3.cp);
			
			 fflush(stdin);
			
		     printf("\nEnter the quantity of this stock  ");scanf("%d",&data3.qty);
		    
			 fflush(stdin);
		    
		     printf("\nEnter Selling price  ");scanf("%d",&data3.sp);
		    
		     fflush(stdin);
						
			 fwrite(&data3,sizeof(data3),1,ptr);
			
			 fclose(ptr);
			
			 printf("Press 'a' to add more products else press 'b' to go back\n");
			 d=getch();
			 if(d==97)
			{
				system("cls");
				return;
			}
			else if (d==98)
			{
				system("cls");
				return;
			}
		    }
        }
void updatestock(struct manage data3)
{
	while(1){
	
int b,c,n,d;
char a;
	printf("                              choose the category:\n  ");
		printf("| 1. T-Shirts|\n  ");
		printf("| 2. Shirts  |\n  ");
		printf("| 3. Paints  |\n  ");
		printf("| 4. Shoes   |\n  ");		
		printf("* 5.To go back *\n");
	scanf("%d",&n);
	fflush(stdin);	
	if(n==1)
	{
		strcpy(data4.n,"t-shirts.txt");                   // copying name of file in a structure variable of string
       update(data3);
   }
   else if(n==2)
   {
   	strcpy(data4.n,"shirts.txt");
   	update(data3);
   }
   else if(n==3)
   {
   	strcpy(data4.n,"paints.txt");
   	update(data3);
   }
   else if(n==4)
   {
   	strcpy(data4.n,"shoes.txt");
   	update(data3);
   }
   else if(n==5)
   {
system("cls");
return;
   }
}
}
void viewstock(struct manage data3)
{
	int n;
	while(1)
	{
		system("cls");	
	printf("                              choose the category:\n  ");
		printf("| 1. T-Shirts|\n  ");
		printf("| 2. Shirts  |\n  ");
		printf("| 3. paints  |\n  ");
		printf("| 4. Shoes   |\n  ");
		
		printf("* 5.To go back *\n");
	    scanf("%d",&n);
	    fflush(stdin);
	
if(n==1)
{
	strcpy(data4.n,"t-shirts.txt");
	view(data3);
}
	
else if(n==2)
{
    strcpy(data4.n,"shirts.txt");
    view(data3);
}
else if(n==3)
{
    strcpy(data4.n,"paints.txt");
    view(data3);			
}	
else if(n==4)
{
    strcpy(data4.n,"shoes.txt");
    view(data3);	
}
else if(n==5)
{
	system("cls");
	return;
}
  }
}
void showprofit(struct manage data3)      // showing total profit
{
	int n,a=0;
	char b;
	FILE*ptr;
	ptr=fopen("manager.txt","r");
	if(ptr==NULL)
	{
		printf("File not found\n");
		return;
	}
	while(fread(&bill,sizeof(bill),1,ptr))
	{
		a=a+(bill.sp-bill.cp)*bill.qty;
			printf("product name=  %s  \ncost-price=  %d  \nquantity=  %d  \nselling price= %d  \nprofit= %d",bill.name,bill.cp,bill.qty,bill.sp,(bill.sp-bill.cp)*bill.qty);
			printf("\n");
			
		printf("_________________________________________________________\n");
		
	 }
	 printf("\nTOTAL PROFIT %d",a);
	fclose(ptr);
	printf("\npress b to go back\n");
	b=getch();
	if(b==98)
	{
		system("cls");
		return;
	}
}
void showsell(struct manage data3)  // showing total sell
{
	int n,a=0;
	char b;
	FILE*ptr;
	ptr=fopen("manager.txt","r");
	if(ptr==NULL)
	{
		printf("File not found\n");
		return;
	}
	while(fread(&bill,sizeof(bill),1,ptr))
	{
		a=a+bill.sp*bill.qty;
			printf("product name=  %s  \ncost-price=  %d  \nselling price= %d",bill.name,bill.cp,(bill.sp)*bill.qty);
			printf("\n");
			printf("__________________________________________________________\n");	
	 }
	 printf("\nTotal sell = %d",a);
	 
	fclose(ptr);
	printf("\npress b to go back\n");
	b=getch();
	if(b==98)
	{
		system("cls");
		return;
	}
}
void customer(struct manage data3)
{
	FILE*ptr,*fptr,*ffptr;
	char c;
	while(1)
	{	
	system("cls");
	int a,b,d,q;
	ptr=fopen(data4.n,"r");	                     // data4.n is taking name of file
	if(ptr==NULL)
	{
		printf("File not found\n");
		return;
	}
	while(fread(&data3,sizeof(data3),1,ptr))
	{
		printf("\nproduct code= %d\n",data3.code);
		printf("\nProduct name=");
		printf("%s \n",data3.name);      
		printf("\nQuantity= %d \n",data3.qty);                      // read all items from the file of category with customer selected
		printf("\nPrice= %d \n",data3.sp);
		printf("\n__________________________________________________________\n");
	}
	fclose(ptr);	
	printf("Enter product code to buy or enter '0' to exit\n");
	fflush(stdin);
	scanf("%d",&bill.code);
	if(bill.code==0)
	{
			break;
	}				
	ptr=fopen(data4.n,"r");
	
	ffptr=fopen("NEW.txt","a");                               // a file for updatation of quantity of stock in original file selected file
	
	fptr=fopen("sale.txt","a");                               
	
	printf("Enter quantity\n");
	fflush(stdin);
	scanf("%d",&bill.qty);
    while(fread(&data3,sizeof(data3),1,ptr))
    {
	if(bill.code==data3.code)
	{
		if(bill.qty<=data3.qty&&data3.qty>0&&bill.qty>0)
		{
			if(data3.qty==0)
			{
				printf("Sorry this item is not available\n");
				break;
			} 
			
			if(data3.qty>0)
			{			
			    data3.qty=data3.qty-bill.qty;			          //writing in a temp file which will show updated quantity of stock 
			    fwrite(&data3,sizeof(data3),1,ffptr);
			}                                      
			if(data3.qty>=0)
			{
			
				data3.qty=data3.qty+bill.qty;
				bill.qty=(data3.qty-data3.qty)+bill.qty;    
				strcpy(bill.name,data3.name);
				bill.sp=data3.sp;
				bill.cp=data3.cp;
				bill.code=data3.code;
	            fwrite(&bill,sizeof(bill),1,fptr);                  // appending in sell.txt file which will show customer purchased stock
			}
			
		}
		else if(bill.qty>data3.qty)
		{
			printf("Sorry not available such quantity\n");
		}
	}
		else 
		{
			fwrite(&data3,sizeof(data3),1,ffptr);
		}
}	
	fclose(ptr);
	fclose(fptr);
	fclose(ffptr);
	printf("Want to buy more items?   PRESS 'a'  else PRESS 'b' to end shopping\n");
	c=getch();
	if(c==97)
	{
	remove(data4.n);
	rename("NEW.txt",data4.n);
	system("cls");
	return;
	}
	else if(c==98){	
	remove(data4.n);
	rename("NEW.txt",data4.n);
	customerBill(data3);
   }
 }
}
void customerBill(struct manage data3)             //   to show customer the products he/she is buying and calculate bill
{
	char x;
	FILE*ffptr,*rptr;
	int c=0,d,e;
	while(1)
	{	
	  system("cls");
	  int a,b;
	  printf("                               |  YOUR ITEMS  |\n");
	  ffptr=fopen("sale.txt","r");
	if(ffptr==NULL)
	{
		printf("File not found\n");
		return;                                                        // reading from sale.txt file 
	}
	while(fread(&bill,sizeof(bill),1,ffptr))
  {
		printf("\n product code=%d",bill.code);		
		printf("\nproduct name= %s",bill.name);
		printf("\n Qantity= %d",bill.qty);
		printf("\n Price=%d",bill.sp);
		printf("\n___________________________________________________________________\n");	    
  }
     fclose(ffptr);
     
printf("Enter 'a' to go for bill\n");           printf("Enter 'b' to go back\n");
    x=getch();
    if(x==98)
   {
	return;
   }
    else if(x==97)
   {
		system("cls");
		printf("\n    *******   ******* THANKYOU  FOR  YOUR  SHOPPING *******   *******\n");
		
		printf("  \n                    [    YOUR BILL   ]      \n");
		rptr=fopen("sale.txt","r");
		if(rptr==NULL)
		{
			printf("File not found\n");
			return;
		}
		while(fread(&bill,sizeof(bill),1,rptr))
		{			
			printf("\n%s",bill.name);
			printf("\nquantity= %d",bill.qty);                       //  calculating bill of purchased items
			d=bill.sp*bill.qty;
			printf("\nprice=  %d",d);
			c=c+bill.sp*bill.qty;
	    }
	      fclose(rptr);
	      rptr=fopen("sale.txt","r");
	      ffptr=fopen("manager.txt","a");
	    while(fread(&bill,sizeof(bill),1,rptr))
	    {
		 fwrite(&bill,sizeof(bill),1,ffptr);
	    }
	      fclose(rptr);
	      fclose(ffptr);
	    remove("sale.txt");		                            // removing sale.txt to empty the customer cart	
	    printf("\n\n** YOUR TOTAL BILL **   =   %d",c);
	    printf("\nPRESS '1' to go back\n ");
	    scanf("%d",&e);
	    if(e==1)
	   {
		system("cls");
		break;
	   }		
    }
    }
}

void update(struct manage data3)   // To update the stock by deleting items or updating their rates and quantities
{
	while(1)
	{
	 system("cls");
	 FILE*ptr,*fptr;
	 int b,d,c;
	 char a;
	 system("cls");
	 ptr=fopen(data4.n,"r");
	 if(ptr==NULL)
	{
	    printf("file not found\n");
	    return;
	}
	while(fread(&data3,sizeof(data3),1,ptr))
		{
         printf("Product code= %d",data3.code); printf("  name= %s",data3.name);printf("  C.P= %d",data3.cp); printf("  Quantity\n= %d",data3.qty);   
         printf("  S.P= %d\n",data3.sp);
		 printf("___________________________________________________________________\n");
		}
		fclose(ptr);
					
	printf("1. UPDATE STOCK"); printf("     2. DELETE  STOCK\n"); printf("     3. To  go back\n");
	scanf("%d",&c);
	fflush(stdin);
	if(c==1)                           // to update record
	{
		system("cls");
		ptr=fopen(data4.n,"r");
		fptr=fopen("n.txt","a");
		if(ptr==NULL)
		{
			printf("File not found\n");
			return;
		}
		system("cls");
		printf("Enter product code\n");
		scanf("%d",&b);
		fflush(stdin);
		while(fread(&data3,sizeof(data3),1,ptr))
	 { 		
		if(b==data3.code)
		{
                        
			system("cls");
			printf("Enter new cost price\n");
			scanf("%d",&data3.cp);
			fflush(stdin);
			printf("Enter new selling price\n");
			scanf("%d",&data3.sp);
			fflush(stdin);
			printf("Enter new quantity\n");
			scanf("%d",&data3.qty);
			fflush(stdin);
			fwrite(&data3,sizeof(data3),1,fptr);
        }
		else
		{
			fwrite(&data3,sizeof(data3),1,fptr);	
		}				
	 }
		fclose(ptr);
		fclose(fptr);
		remove(data4.n);                // removing the old file to rename the temperary file to its original file name
		rename("n.txt",data4.n);
		printf("updated successfully\n");
		printf("press 'b' to go back\n");
		a=getch();
		if(a==98)
		{
			system("cls");
			return;
		}
    }
	else if(c==2)               // to delete record
	{
		system("cls");	
		ptr=fopen(data4.n,"r");
		fptr=fopen("delete.txt","a");
		if(ptr==NULL)
		{
			printf("File not found\n");
			return;
		}
		system("cls");
		printf("Enter the product code\n");
		scanf("%d",&d);
		fflush(stdin);
		while(fread(&data3,sizeof(data3),1,ptr))
		{
			if(d==data3.code)
			{
				printf("DELETED SUCCESSFULLY\n");				
			}
			else
			fwrite(&data3,sizeof(data3),1,fptr);
		}
		fclose(ptr);
		fclose(fptr);
		remove(data4.n);
		rename("delete.txt",data4.n);
		printf("press b to go back\n");
		a=getch();
		if(a==98)
		{
			system("cls");
			return;
		}
    }
    else if(c==3)
    {
       system("cls");
       break;
	}
	}
}

void view(struct manage data3)              // To view stock
{
	while(1)
	{
		system("cls");
	
	char a;
	int n;
	FILE*ptr;
	ptr=fopen(data4.n,"r");                //  data4.n  is a structure variable in which file is stored
 	if(ptr==NULL)
	{
	printf("file not found\n");
	return;
	}
	while(fread(&data3,sizeof(data3),1,ptr))
		{
			printf("\n");
printf("product code=%d ",data3.code);printf(" name= %s ",data3.name);printf(" cost price= %d ",data3.cp); printf(" Quantity= %d ",data3.qty);   
printf(" \nSelling price=%d \n",data3.sp);
			printf("___________________________________________________________________________\n");
		}		
		fclose(ptr);
		printf("press 'b' to go back\n");
		a=getch();
		if(a==98)
		{
			system("cls");
			return;
		}
		
	}
}

		
	
	


