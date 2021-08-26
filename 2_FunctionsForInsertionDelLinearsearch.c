#include<stdio.h>

    int a;  
    int b[50];
    int c;
    int i;
void insertion();  //function prototype is used so that compiler can understand that we are going to use functions in this program 
void deletion();
void linearsearch();
int main()
{
 

printf("Enter number of elements in array between 1 to 50\n");
scanf("%d",&c);
printf("Enter %d elements\n",c);
for(i=0;i<c;i++)
{
   scanf("%d",&b[i]);
}
do{
printf("Menu\n");
printf("Enter 1 for insertion\n");
printf("Enter 2 for Deletion\n");
printf("Enter 3 for Linearsearch\n");
printf("Enter 4 for exit\n");
printf("Enter your option to perfrom operations on above array\n");
scanf("%d",&a);


switch(a)
{
    case 1:
    
        insertion();
        break;
   case 2:
    deletion();

   case 3:
    linearsearch();
    break;
  case 4:
  printf("You have successfully exited the program\n");
  break;
  default:
        printf("You have entered wrong option");

}

}while(a!=4);
 return 0;
}

void insertion()
{int i;
       

int loc;
int element;
printf("Enter the location where u wish to insert the element\n");
scanf("%d",&loc);
printf("Enter the element u want to insert at that location\n");
scanf("%d",&element);
if(loc>=c+1)
{
    printf("Deletion not possible\n");
}
else{
        for(i=c;i<=loc;i--)
        {
            b[i+1]= b[i];
        }
        b[loc] = element;
     printf("Elements after insertion\n");
    for(i=0;i<c;i++)
    {
    printf("%d\n",b[i]);
    }

}

}
void deletion()
{

int i;
int loc;
printf("Enter the location where u wish to delete an element ");
scanf("%d",&loc);
for(i=loc-1;i<c-1;i++)
{
    b[i] = b[i+1];
}
printf("After deleting element from a particular position\n");
if(loc>=c+1)
{
    printf("Deletion not possible\n");

}
else{
for(i=0;i<c-1;i++)
{
    printf("%d\n",b[i]);
}

}


}
void linearsearch()
{
    

int search, i;

  printf("Enter a number to search\n");
  scanf("%d", &search);

  for (i= 0; i < c; i++)
  {
    if (b[i] == search)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", search, i+1);
      break;
    }
  }
  if (i == c)
    printf("%d isn't present in the array.\n", search);
}