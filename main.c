#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    char title[30];
    char ID[30];
    char author[90];
    int quantity,dO,mO,yO,dE,mE,yE;
    int ex;
} book;

void Menu();
void Borrow(book a[], int n);
void Return(book *pr);
void ReturnN(book a[], int n);
void Add(book *pr);
void AddN(book a[], int n);
void SortExpirationDate(book a[], int n);
void SearchByID(book a[], int n);
book max(book a[], int n);
book min(book a[], int n);
void ExpirationDate(book *pr);
void ExportFile(book a[], int n, char fileName[]);
void Delete(book a[], int n);
void ShowN(book a[], int n);
void Show(book pr);

int main(){
    Menu();
    return 0;
}

void Borrow(book a[], int n){
    char id[30];
    printf("\nBook ID : ");
    fflush(stdin);
    gets(id);
    printf("\n____________________________________\n");
    for (int i = 0;i < n;i++)
    {
        if (strcmp(a[i].ID,id)!= 0)
        {
            printf("\nBook title: %s", a[i].title);
            printf("\nBook ID: %s", a[i].ID);
            printf("\nDate borrowed: %d/%d/%d",a[i].dO,a[i].mO,a[i].yO);
            printf("\nExpiration date: %d/%d/%d",a[i].dE,a[i].mE,a[i].yE);
            printf("\nPrice: %d", a[i].quantity);
            printf("\nExpiration: %d\n", a[i].ex);
        }
        else{
            continue;
        }
    }
}

void Return(book *pr) {
    printf("\nBook title: ");
    fflush(stdin);
    gets(pr->title);
    printf("\nBook ID: ");
    fflush(stdin);
    gets(pr->ID);
}

void ReturnN(book a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\nInput book number %d:", i + 1);
        Return(&a[i]);
    }
    printf("\n____________________________________\n");
}

void Menu(){
    int key;
    char fileName[] = "Book.txt";
    int n;
    bool Existed = false;
    do {
        printf("\nInsert number of books: "); scanf("%d", &n);
    } while (n <= 0);
    book a[n], pr_temp;
    while (true) {
        system("cls");
        printf("**************************************************\n");
        printf("**                                              **\n");
        printf("**          LIBRARY MANAGEMENT PROGRAM          **\n");
        printf("**                                              **\n");
        printf("**          1. Add books                        **\n");
        printf("**          2. Show book list                   **\n");
        printf("**          3. Sort books by expiration date    **\n");
        printf("**          4. Find book based on ID            **\n");
        printf("**          5. Delete book by ID                **\n");
        printf("**          6. Borrow books                     **\n");
        printf("**          7. Return book                      **\n");
        printf("**          0. Exit                             **\n");
        printf("**                                              **\n");
        printf("**************************************************\n");
        printf("**       Type what you want       	 **\n");
        scanf("%d", &key);
        switch (key) {
        case 1:
            printf("\nYou picked Add books");
            AddN(a, n);
            printf("\nThank you.");
            Existed = true;

            printf("\nPress any key to continue.\n");
            getch();
            break;
        case 2:
            if (Existed) {
                printf("\nYou picked Show book list");
                ShowN(a, n);
            }
            else {
                printf("\nPlease input the book(s) first.");
            }
            printf("\nPress any key to continue.\n");
            getch();
            break;
        case 3:
            if (Existed) {
                printf("\nYou picked Sort books by expiration date: ");
                SortExpirationDate(a, n);
                ShowN(a, n);
            }
            else {
                printf("\nPlease input the book(s) first.");
            }
            printf("\nPress any key to continue.\n");
            getch();
            break;
        case 4:
            if (Existed) {
                printf("\nYou picked Find book based on ID");
                SearchByID(a, n);
            }
            else {
                printf("\nPlease input the book(s) first.");
            }
            printf("\nPress any key to continue.\n");
            getch();
            break;

        case 5:
            if (Existed) {
                printf("\nYou picked Delete book by ID");
                Delete(a,n);
            }
            else {
                printf("\nPlease input the book(s) first.");
            }
            printf("\nPress any key to continue.\n");
            getch();
            break;
        case 6:
            if (Existed) {
                printf("\nYou picked Borrow books");
                Borrow(a,n);
            }
            else {
                printf("\nPlease input the book(s) first.");
            }
            printf("\nPress any key to continue.\n");
            getch();
            break;
        case 7:
            printf("\nYou picked Return books");
            ReturnN(a, n);
            printf("\nThank you.");
            Existed = true;
        case 0:
            printf("\n\n\n\t\t\t\tThank you.\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tInvalid input, please try again.");
            getch();
            break;
        }
    }
}

void ExpirationDate(book *pr) {
    pr->dE = pr->dO;
    if (pr->mO + pr->ex > 12) {
        pr->mE = (pr->mO+pr->ex)-12;
        pr->yE = pr->yO + 1;
    }
    else {
        pr->mE = pr->mO + pr->ex;
        pr->yE = pr->yO;
    }
}

void Add(book *pr) {
    printf("\nBook title: ");
    fflush(stdin);//xoa bo dem
    gets(pr->title);
    printf("\nBook ID: ");
    fflush(stdin);
    gets(pr->ID);
    printf("\nInput quantity: ");
    scanf("%d", &pr->quantity);
    printf("\nDate borrowed: ");
    scanf("%d/%d/%d",&pr->dO,&pr->mO,&pr->yO);
    printf("\nExpired after (month): ");
    scanf("%d",&pr->ex);
    ExpirationDate(pr);
}

void AddN(book a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\nInput book number %d:", i + 1);
        Add(&a[i]);
    }
    printf("\n____________________________________\n");
}

void Show(book pr) {
    printf("\nBook title: %s", pr.title);
    printf("\nBook ID  : %s", pr.ID);
    printf("\nDate borrowed: %d/%d/%d",pr.dO,pr.mO,pr.yO);
    printf("\nExpiration date: %d/%d/%d",pr.dE,pr.mE,pr.yE);
    printf("\nPrice: %d", pr.quantity);
    printf("\nExpiration after: %d month\n", pr.ex);
}

void ShowN(book a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0;i < n;++i) {
        printf("\nBook %d:", i + 1);
        Show(a[i]);
    }
    printf("\n____________________________________\n");
}

void SortExpirationDate(book a[], int n){
        book time;
    for (int i = 0;i < n;++i){
        for (int j = i + 1; j < n;++j){
            if (a[i].yE*1000+a[i].mE*100+a[i].dE >a[j].yE*1000+a[j].mE*100+a[j].dE ){
                time = a[i];
                a[i] = a[j];
                a[j] = time;
            }
        }
    }
}

void SearchByID(book a[], int n){
    char id[30];
    printf("\nInput ID : ");
    fflush(stdin);
    gets(id);
    printf("\n____________________________________\n");
    for (int i = 0;i < n;i++)
    {
        if (strcmp(a[i].ID,id)==0)
        {
            printf("\nBook title: %s", a[i].title);
            printf("\nBook ID: %s", a[i].ID);
            printf("\nDate borrowed: %d/%d/%d",a[i].dO,a[i].mO,a[i].yO);
            printf("\nExpiration Date: %d/%d/%d",a[i].dE,a[i].mE,a[i].yE);
            printf("\nPrice: %d", a[i].quantity);
            printf("\nExpiration: %d", a[i].ex);
        }
    }
    printf("\n____________________________________\n");
}

book max(book a[], int n) {
    int index = 0;
    int max = a[0].quantity;
    for (int i = 0;i < n;i++) {
        if (a[i].quantity > max) {
            max = a[i].quantity;
            index = i;
        }
    }
    return a[index];
}

book min(book a[], int n) {
    int index = 0;
    int min = a[0].quantity;
    for (int i = 0;i < n;i++) {
        if (a[i].quantity < min) {
            min = a[i].quantity;
            index = i;
        }
    }
    return a[index];
}

void Delete(book a[], int n){
    char id[30];
    printf("\nBook ID : ");
    fflush(stdin);
    gets(id);
    printf("\n____________________________________\n");
    for (int i = 0;i < n;i++)
    {
        if (strcmp(a[i].ID,id)!= 0)
        {
            printf("\nBook title: %s", a[i].title);
            printf("\nBook ID: %s", a[i].ID);
            printf("\nDate borrowed: %d/%d/%d",a[i].dO,a[i].mO,a[i].yO);
            printf("\nExpiration date: %d/%d/%d",a[i].dE,a[i].mE,a[i].yE);
            printf("\nPrice: %d", a[i].quantity);
            printf("\nExpiration: %d\n", a[i].ex);
        }
        else{
            continue;
        }
    }
}

void ExportFile(book a[], int n, char fileName[]) {
    FILE* fp;
    fp = fopen(fileName, "w");
    fprintf(fp, "%20s%5s%10s%10s%10s\n", "Book title", "\tID", "\tPrice", "\tDate borrowed", "\tExpiration date");
    for (int i = 0;i < n;i++) {
        fprintf(fp, "%15s%12s%9d%8d/%d/%d%8d/%d/%d\n", a[i].title, a[i].ID, a[i].quantity,a[i].dO,a[i].mO,a[i].yO,a[i].dE,a[i].mE,a[i].yE);
    }
    fclose(fp);
}
