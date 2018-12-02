#include<stdio.h>
#include<conio.h>
#include<string.h>




void record();
void display();
void cost();
void price();
void quantity();
void avgcost();
void avgprice();
void bestprofit();
void search();

int ch;
int no;
int no2;
int i;
int c;
int r;
static int pos=0;
static int j = 0;



int quant = 0;


struct inventary{


char name[20];
int cost;
int quantity;
int price;
int sales;
}t1[100];


int main()
{


    do
    {

        printf("\n               ************    WELCOME TO IIITV INVENTORY SYSTEM    ************\n");
        printf("\n");
        printf("\t\t\t\tPress 1: ADD RECORD\n");
        printf("\t\t\t\tPress 2: DISPLAY RECORD\n");
        printf("\t\t\t\tpress 3: TOTAL COST\n");
        printf("\t\t\t\tPress 4: TOTAL PRICE\n");
        printf("\t\t\t\tPress 5: TOTAL QUANTITY\n");
        printf("\t\t\t\tPress 6: AVERAGE PRICE\n");
        printf("\t\t\t\tPress 7: AVERAGE COST\n");
        printf("\t\t\t\tpress 8: BEST SALES\n");
        printf("\t\t\t\tpress 9: SEARCH\n");
        printf("\t\t\t\tpress 10: EXIT");
        printf("\n");
        printf("Enter your Choice\n");
        scanf("%d", &ch);
        switch (ch)

        {
            case 1: record();
            break;

            case 2: display();
            break;

            case 3: cost();
            break;

            case 4: price();
            break;

            case 5: quantity();
            break;

            case 6: avgprice();
            break;

            case 7: avgcost();
            break;

            case 8: bestprofit();
            break;

            case 9: search();
            break;

            default: printf("\n INVALID CHOICE\n");
            break;
        }

    }while (ch != 10);

   system("cls");
   return(0);

}

void record()
{

    printf("HOW MANY RECORD YOU WANT TO STORE\n");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("inven.txt", "a");






    for (i=0; i<no; i++,j++)
    {
       printf("Enter The Product Name\n");
       scanf("%s", t1[j].name);

       printf("Enter the Product Cost\n");
       scanf("%d", &t1[j].cost);


       printf("Enter the Product Quanitity\n");
       scanf("%d", &t1[j].quantity);

       printf("Enter the Product Price\n");
       scanf("%d", &t1[j].price);

       printf("Enter the Product Sales\n");
       scanf("%d", &t1[j].sales);

       fprintf(fp, "PRODUCT NAME     :    %s\n", t1[j].name);
       fprintf(fp, "PRODUCT COST     :    %d\n", t1[j].cost);
       fprintf(fp, "PRODUCT QUANTITY :    %d\n", t1[j].quantity);
       fprintf(fp, "PRODUCT PRICE    :    %d\n", t1[j].price);
       fprintf(fp, "PRODUCT SALES    :    %d\n\n", t1[j].sales);
       pos=pos+1;



    }

    j = i;


       fclose(fp);


}
void display()
{

    FILE *fp;
    fp = fopen("inven.txt", "r");
    while ((c=getc(fp)) != EOF)
    {
       printf("%c", c);
    }
     fclose(fp);
     getch();
     system("cls");

}
void cost()
{
    int totalcost = 0;
    FILE *fp;
    fp = fopen("inven.txt", "r");
    printf("HOW MANY RECORDS\n");
    scanf("%d", &no);
    for (i=0; i<no; i++)
    {
       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);
       totalcost = totalcost + t1[i].cost*t1[i].quantity;

    }
    printf("\n\ntotal cost is :  %d", totalcost);
    fclose(fp);
    getch();
    system("cls");
}
void price()
{
    int total = 0;
    printf("HOW MANY RECORDS :  ");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("inven.txt", "r");
     for (i=0; i<no; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);
       total = total + t1[i].price*t1[i].quantity;

    }
    printf("The Total Price is %d\n", total);
    fclose(fp);
    getch();
    system("cls");

}
void quantity()
{
    printf("HOW MANY RECORDS\n");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("inven.txt", "r");
     for (i=0; i<no; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n",  &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n",  &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n",  &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);
       quant = quant + t1[i].quantity;

    }
    printf("The Total quantity is %d\n", quant);
    fclose(fp);
    getch();
    system("cls");

}



void avgprice()
{
    int avg;
    int t = 0;
    printf("HOW MANY RECORDS :  ");
    scanf("%d", &no);
    FILE *fp;
    fp = fopen("inven.txt", "r");
    for (i=0; i<no; i++)
        {
       fscanf(fp, "PRODUCT NAME     :    %s\n",  &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n",  &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n",  &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);
       t = t + t1[i].price*t1[i].quantity;

    }
    avg = t/no;
    printf("The Average Price is %d", avg);
    fclose(fp);
    getch();
    system("cls");
}
void avgcost()
{
    int k;
    int costavg = 0;
    char n[20];
    int costtotal = 0;
    FILE *fp;
    fp = fopen("inevn.txt", "r");
    printf("HOW MANY RECORDS YOU WANT \n");
    scanf("%d", &no);
    for (k=0; k<no; k++)
    {
        printf("enter product %d",k+1);
        scanf("%s",n);

        for (i=0; i<pos; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);


       if(stricmp(t1[i].name,n)==0)
       {

            costtotal = costtotal + t1[i].cost*t1[i].quantity;
       }


    }}
    costavg = costtotal/no;
    printf("\n\n THE AVERAGE COST IS   :%d", costavg);
    fclose(fp);
    getch();
    system("cls");
}
void bestprofit()
{
    int profit;

    FILE *fp;
    fp = fopen("inven.txt", "r");
    printf("HOW MANY RECORDS YOU WANT TO SEARCH\n");
    scanf("%d", &no);
    for (i=0; i<no; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);
       printf("the profit   is %d\n",(t1[i].price-t1[i].cost)*t1[i].sales);


    }


    fclose(fp);
    getch();
    system("cls");
}
void search()
{
    printf("NAME THE PRODUCT U WANT TO SEARCH\n");
    char name[20];
    scanf("%s",name);
    //printf("%s",name);

   // printf("HOW MANY RECORDS :  ");
    //scanf("%d", &no)


    FILE *fp;
    fp=fopen("inven.txt","r");

     for (i=0; i<pos; i++)
    {

       fscanf(fp, "PRODUCT NAME     :    %s\n", &t1[i].name);
       fscanf(fp, "PRODUCT COST     :    %d\n", &t1[i].cost);
       fscanf(fp, "PRODUCT QUANTITY :    %d\n", &t1[i].quantity);
       fscanf(fp, "PRODUCT PRICE    :    %d\n", &t1[i].price);
       fscanf(fp,"PRODUCT SALES     :    %d\n\n", &t1[i].sales);


       if(stricmp(t1[i].name,name)==0)
       {

            printf("PRODUCT NAME     :    %s\n",t1[i].name);
            printf("PRODUCT COST     :    %d\n",t1[i].cost);
            printf("PRODUCT QUANTITY :    %d\n",t1[i].quantity);
            printf("PRODUCT PRICE    :    %d\n",t1[i].price);
            printf("PRODUCT SALES    :    %d\n\n",t1[i].sales);
       }
       else
       {
           printf("we could not find the product ");
       }

    }

    fclose(fp);
    getch();
    system("cls");

}

