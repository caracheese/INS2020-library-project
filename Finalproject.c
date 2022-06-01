#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char nameStudent [30], nameClass[20], userID[10], userSelection;

int main()
{
  printf("\nWelcome to the VNU's library\n");
  printf("Please enter your information");

  printf("\nName          :");
  gets(nameStudent);

  printf("\nClass         :");
  gets(nameClass);

  printf("\nStudent ID    :");
  gets(userID);


  printf("-------------------------------------------------");
  printf("\n   Welcome to the VNU's library");
  printf("\n     Hope you have a good day");
  printf("\n-----------------------------------------------");
  printf("\nName            :%s", nameStudent);
  printf("\nClass           :%s", nameClass);
  printf("\nStudent ID      :%s", userID);
  printf("\n-----------------------------------------------");

   char bookID, userListBook;

   char choice, exit;
   char BookName[10][100]={
                           "Life of Pi",
                           "The Godfather",
                           "The Alchemist",
                           "Diary of a wimpy kid",
                           "Peter Pan",
                           "Dear John",
                           "The Little Prince",
                           "Mat ma Maya",
                           "Academic English",
                           "Harry Potter",
                          };

   char BookSerialNum[10][10]={
                           "VNU2000",
                           "VNU2001",
                           "VNU2002",
                           "VNU2003",
                           "VNU2004",
                           "VNU2005",
                           "VNU2006",
                           "VNU2007",
                           "VNU2008",
                           "VNU2009",
                              };
 do
   {
     printf("\nDo you want to borrow or return books? (B: Borrow, R: Return): ");
     scanf("%s", &userSelection);
     printf("\n-----------------------------------------------");

     if (userSelection == 'B' || userSelection == 'b' )
     {
         printf("\nWould you like to watch the booklist? (Y: Yes, N: No): ");
         scanf(" %c", &userListBook);

         if (userListBook == 'Y' || userListBook == 'y')
         {
             printf("List of available books\n");
             printf("-----------------------------------------------\n");

             for(int i = 0; i < 10; i++)
                {
                  printf(" %s\t\t\t\t%s\n", BookName[i], BookSerialNum[i]);
                }
                printf("-----------------------------------------------\n");

                printf("\n\nDo you want to go back to the home screen? [Y: Yes | N: No]: ");
                scanf(" %c", &exit);
         }
         else if (userListBook == 'n' || userListBook == 'N')
         { //decide not to watch the booklist
             printf("\nEnter the Book ID:");
             scanf(" %s", &bookID);

             printf("\nRe-enter your student ID: ");
             scanf(" %s", &userID);

             int numberoflatereturns = rand() % 6; //random number between 0 and 11

             if (numberoflatereturns < 5)
                {
                printf("\nYou can borrow book within 2 weeks");
                }
             else if (numberoflatereturns > 5)
                {
                printf("\nYou can not borrow books");
                }
             else
                {
                printf("Error please re-enter input\n");
                }


         }
     } // end of if (userSelection)

    else if (userSelection == 'R' || userSelection == 'r')
        {
         int d1,m1,y1,d2,m2,y2;
         fflush(stdin);
         printf("\nEnter the first date you borrow the book (dd mm yyyy): ");
         scanf("%d%d%d","%d1","%m1","%y1");
         printf("\nEnter the date you return the book (dd mm yyyy): ");
         scanf("%d%d%d","%d2","%m2","%y2");
        }
  } //end of do
  while (exit == 'y' || exit == 'Y'); }//exit the program

