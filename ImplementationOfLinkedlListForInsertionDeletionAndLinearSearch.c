#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *emplist(struct node *start , int data);
struct node *beg(struct node *start , int data);
struct node *end(struct node *start , int data);
struct node *nposition(struct node *start , int data, int position);
void disp(struct node *start);
struct node *del(struct node *start , int data);

int main()
{
    struct node *start = NULL;
    int ch , data , position;
    while(1)
    {
        printf("1. Insert in an Empty list\n");
        printf("2. Insert at beginning of list\n");
        printf("3. Insert at End of list\n");
        printf("4. Insert at nth position\n"); 
        printf("5. Display\n");
        printf("6. End program\n");
        printf("7. Delete\n");
        printf("Enter Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(start != NULL)
            {
                printf("List is not empty\n");
                break;
            }
            else{
                printf("Enter Element\n");
                scanf("%d",&data);
                start = emplist(start,data);
              break;
            }
            case 2:
             printf("Enter Element\n");
                scanf("%d",&data);
                start = beg(start,data);
                break;

              case 3:
              printf("Enter Element\n");
                scanf("%d",&data);
                start = end(start,data);
                break;

               case 4:
                 printf("Enter Element\n");
                scanf("%d",&data);
                printf("Enter position\n");
                scanf("%d",&position);
                start = nposition(start, data,position );
                break;
                case 5:
                disp(start);
                break;
                case 6:
                exit(0);
                case 7:
                printf("Enter element to be deleted\n");
                scanf("%d",&data);
                start= del(start, data);
                break;

                default:
                printf("Wrong Choice");

        }

    }
}

struct node *emplist(struct node *start , int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> link = start;
    start = tmp;
    return start;
}

struct node *beg(struct node *start , int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    tmp -> link = start;
    start = tmp;
    return start;
}

struct node *end(struct node *start , int data)
{

 struct node *p, *tmp;
 tmp = (struct node *)malloc(sizeof(struct node));
 tmp -> info = data;
 p = start ;
 while(p -> link !=NULL)
 {
     p = p -> link;

 }
 p -> link = tmp;
 tmp -> link = NULL;
 return start ;

}
struct node *nposition(struct node *start , int data, int position)
{
    int i;
    struct node * tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> info = data;
    if(position == 1)
    {
        tmp -> link = start;
        start = tmp;
        return start;

    }
    p = start;
    for(i =1; i<position - 1 && p != NULL; i++)
    {
        p = p -> link;

    }
    if(p==NULL)
    {
        printf("There are less then %d elements\n",position);
    }
   else
   {
       tmp -> link = p -> link;
       p -> link = tmp;

   }
   return start;

}
void disp(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        p = start;
        printf("List \n");
        while(p!=NULL)
        {
            printf("%d\t", p -> info);
            p = p -> link;
        }
        printf("\n");
    }
}
struct node *del(struct node *start , int data)
{
    struct node *tmp, *p;
    if(start == NULL)
    {
        printf("List is empty");
        return start;

    }
    /*Deletion of only node
    if(start -> info = data)
    {
        tmp = start;
        start = NULL;
        free(tmp);
        return start;
    }*/
    
    /*Deletion of the first node*/
     if(start -> info = data)
    {
        tmp = start;
        start = start -> link;
        free(tmp);
        return start;
    }
    
    /*Deletion in between or at the end */
     p = start;
     while(tmp!=NULL && tmp -> info !=data)
     {
         if(p -> link -> info == data)
         {
             tmp= p -> link;
             p -> link = tmp -> link;
             free(tmp);

         }
         p = p -> link;
     }
    printf("Element %d not found in the list\n ", data);
    return start;
}


