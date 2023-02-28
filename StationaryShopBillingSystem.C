#include<stdio.h>
#include<string.h>
#include<ctype.h>
void display();
void intro()
{
clrscr();
gotoxy(31,11);
printf("STATIONARY SHOP");
gotoxy(35,14);
printf("WELCOME");
getch();
}

struct customer
{
char name[10],num[15];
struct customer *link;
};
struct customer *cst=NULL;

struct product
{
int pid,qty,price;
char pname[10];
struct product *link;
};
struct product *first=NULL;
struct product *cart=NULL;

void addtocart()
{
int cartpid;
struct product *temp;
struct product *cur;
temp=(struct product *)malloc(sizeof(struct product));
display();
printf("Enter Product ID of the product to be added to cart: ");
scanf("%d",&cartpid);
cur=first;
while(cur!=NULL)
{
if(cur->pid==cartpid)
{
temp->pid=cur->pid;
strcpy(temp->pname,cur->pname);
printf("ENTER THE QUANTITY: ");
scanf("%d",&temp->qty);
printf("\n");
temp->price=cur->price;
break;
}
cur=cur->link;
}
if(temp->qty>cur->qty)
{
printf("PRODUCT OUT OF STOCK!!!\n");
getch();
}
else
{
if(cart==NULL)
{
cart=temp;
temp->link=NULL;
}
else
{
cur=cart;
while(cur->link!=NULL)
cur=cur->link;
cur->link=temp;
temp->link=NULL;
}
}
}
void dispcart()
{
struct product *cur;
if(cart==NULL)
printf("NO PRODUCTS IN CART!!!\n");
else
{
cur=cart;
printf("\t\t\tCART\n\n");
printf("PRODUCT ID\tPRODUCT NAME\tQUANTITY\tPRICE\n");
while(cur!=NULL)
{
printf("%d\t\t%s\t\t%d\t\t%d\n",cur->pid,cur->pname,cur->qty,cur->price);
cur=cur->link;
}
}
}


void invoice()
{
struct customer *temp;
int total=0,grandtotal=0;
struct product *cur,*cur1;
if(cart==NULL)
printf("CART EMPTY!!!");
else
{
temp=(struct customer *)malloc(sizeof(struct customer));
printf("Enter your name: ");
scanf("%s",temp->name);
printf("\n");
printf("Enter your mobile number: ");
scanf("%s",temp->num);
printf("\n");
if(cst==NULL)
{
cst=temp;
temp->link=NULL;
}
else
{
temp->link=cst;
cst=temp;
}
clrscr();
cur=cart;
printf("==============================INVOICE==============================\n\n");
printf("PRODUCT ID\tPRODUCT NAME\tQUANTITY\tPRICE\t\tTOTAL\n");
while(cur!=NULL)
{
total=cur->qty*cur->price;
grandtotal=grandtotal+total;
printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n",cur->pid,cur->pname,cur->qty,cur->price,total);
cur=cur->link;
}
printf("\n\t\t\tGRAND TOTAL=%d\n\n",grandtotal);
printf("\t\t\tTHANK YOU FOR SHOPPING\n\t\t\t      VISIT AGAIN");
}
cur=cart;
cur1=first;
while(cur!=NULL)
{
while(cur1!=NULL)
	{
	if(cur->pid==cur1->pid)
	cur1->qty=cur1->qty-cur->qty;
	cur1=cur1->link;
	}
cur=cur->link;
cur1=first;
cart=NULL;
}

}

void create()
{
struct product *temp;
struct product *cur;
temp=(struct product *)malloc(sizeof(struct product));
printf("Enter the Product ID : ");
scanf("%d",&temp->pid);
printf("\n");
printf("Enter the Product name : ");
scanf("%s",temp->pname);
printf("\n");
printf("Enter the Product Price : ");
scanf("%d",&temp->price);
printf("\n");
printf("Enter the Product Quantity : ");
scanf("%d",&temp->qty);
printf("\n");
if(first==NULL)
{
first=temp;
temp->link=NULL;
}
else
{
cur=first;
while(cur->link!=NULL)
cur=cur->link;
cur->link=temp;
temp->link=NULL;
}
}

void display()
{
struct product *cur;
if(first==NULL)
printf("NO PRODUCTS ON SALE!!!\n");
else
{
cur=first;
printf("\t\t\tPRODUCTS ON SALE\n\n");
printf("PRODUCT ID\tPRODUCT NAME\tQUANTITY\tPRICE\n");
while(cur!=NULL)
{
printf("%d\t\t%s\t\t%d\t\t%d\n",cur->pid,cur->pname,cur->qty,cur->price);
cur=cur->link;
}
}
}

void delete()
{
int delid,flag;
struct product *cur;
struct product *prev;
printf("ENTER THE PRODUCT ID OF THE PRODUCT TO BE DELETED : ");
scanf("%d",&delid);
printf("\n");
if(first==NULL)
printf("NO PRODUCTS ARE ON SALE TO BE DELETED!!!\n");
else if(first->link==NULL)
{
free(first);
first=NULL;
}
else
{
cur=first;
while(cur!=NULL)
{
if(cur->pid==delid)
{
flag=0;
break;
}
else
{
prev=cur;
cur=cur->link;
flag=1;
}
}
if(flag==1)
{
prev->link=cur->link;
free(cur);
}
else
{
prev=first;
first=first->link;
free(prev);
}
printf("PRODUCT DELETED \n");
getch();
}
}

void dispcst()
{
struct customer *cur;
if(cst==NULL)
printf("NO CUSTOMERS VISITED\n");
else
{
printf("NAME\t\tMOBILE NUMBER\n");
cur=cst;
while(cur!=NULL)
{
printf("%s\t\t%s\n",cur->name,cur->num);
cur=cur->link;
}
}
}
void delcart()
{
int delid,flag;
struct product *cur;
struct product *prev;
if(cart==NULL)
{
printf("CART EMPTY!!!\n");
getch();
}
else if(cart->link==NULL)
{
printf("ENTER THE PRODUCT ID OF THE PRODUCT TO BE DELETED : ");
scanf("%d",&delid);
printf("\n");
free(cart);
cart=NULL;
printf("PRODUCT DELETED\n");
}
else
{
printf("ENTER THE PRODUCT ID OF THE PRODUCT TO BE DELETED : ");
scanf("%d",&delid);
printf("\n");
cur=cart;
while(cur!=NULL)
{
if(cur->pid==delid)
{
flag=0;
break;
}
else
{
prev=cur;
cur=cur->link;
flag=1;
}
}
if(flag==1)
{
prev->link=cur->link;
free(cur);
}
else
{
prev=cart;
cart=cart->link;
free(prev);
}
printf("PRODUCT REMOVED FROM CART \n");
}
}




void main()
{
	int ch,y;
	intro();
    q:	clrscr();
	printf("MAIN MENU");
	printf("\n\n01.ADMINISTRATOR\n02.CUSTOMER\n03.EXIT\n");
	scanf("%d",&ch);
	switch(ch)
	{
		  case 1:
		      z:  clrscr();
			  printf("ADMINISTRATOR\n");
			  printf("01.ADD PRODUCT TO SALE\n02.REMOVE PRODUCT FROM SALE\n03.DISPLAY PRODUCTS ON SALE\n04.DISPLAY CUSTOMER DETAILS\n05.MAIN MENU\n");
			  scanf("%d",&y);
			  switch(y)
			{
				case 1:clrscr();
				       create();
				       goto z;
				case 2:clrscr();
				       delete();
				       getch();
				       goto z;
				case 3:clrscr();
				       display();
				       getch();
				       goto z;
				case 4:clrscr();
				       dispcst();
				       getch();
				       goto z;
				case 5: goto q;
				default : printf("error\n");
					  goto q;
			}
       case 2:
     x:  clrscr();
       printf("CUSTOMER MODE \n");
       printf("\n01.ADD TO CART\n02.VIEW CART\n03.INVOICE\n04.DELETE ITEMS FROM CART\n05.MAIN MENU\n");
	      scanf("%d",&y);
	      switch(y)
			{
				case 1:clrscr();
				       addtocart();
				       goto x;
				case 2:clrscr();
				       dispcart();
				       getch();
				       goto x;
				case 3:clrscr();
				       invoice();
				       getch();
				       goto q	;

				case 4:delcart();
					goto x;

				case 5: goto q;
				default :printf("error\n");
					 goto x;
			}
			 break;
      case 3: printf("breaking...\n");
      break;
       default : printf("error\n");
       break;
	}
}
