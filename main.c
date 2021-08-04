#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice;
FILE *fp, *ft,*fp1,*ft1 ,*pf ;

char name[20], password[20], bname[20];
int i, found;


struct bookDitails
{
    int bookid;
    char bookname[20], author[20], subject[20],status[20];
} books;

struct studentDitails
{
    int admNo;
    char name [20];

    //login ditails

    char username[20];
    char password[20];
    char inuse1[20];
    char inuse2[20];
    char inuse3[20];

} student;
struct staffDetails
{
    int id ;
    char username [20];
    char password [20];
} staff;

int main()

{
    for(;;)
    {

        dash();
        printf("\nLogin as\n\n");
        printf("1. Admin\n2. Staff\n3. Student\n");
        input();
        scanf("%d", &choice);


        switch(choice)
        {
        case 1:

            adminLogin();
            break;
        case 2:
            staffLogin();
            break;
        case 3:
            studentLogin();
            break;
        default:

            invalid();
        }
    }
    return 0;
}
void input ()
{

    printf("\nKeyboard input : ");

}
void dash()
{

    printf("\n*************************************************\n");

}
void invalid()
{
    printf("\nInvalid input, Please try again\n");
}

void admin()
{
menu:

    dash();
    printf("\n1. Add staff\n2. View staff \n3. Delete staff\n4. Search staff\n5. Edit staff \n6. Log out  \n7. Exit\n");
    input();

    scanf("%d",&choice);

    if (choice == 1)
    {

        addStaff();

    }
    else if (choice == 2)
    {
        viewStaff();

    }
    else if (choice == 3 )
    {

        deleteStaff();
    }
    else if (choice == 4 )
    {

        searchStaff();
    }
    else if (choice == 5 )
    {

        editStaff();
    }

    else if (choice == 6 )
    {

        main();
    }
    else if (choice == 7 )
    {
        printf("\nSystem state saved\n\n");
        dash();
        exit(0);
    }
    else
    {
        invalid();


    }
}
void addStaff()

{

    fp = fopen("staff.txt","a");
    dash();

    printf("Enter details below \n");

    printf("\n\tEnter ID : ");
    scanf("%d",&staff.id);

    printf("\n\tUsername : ");
    scanf("%s",&staff.username);

    printf("\n\tPassword : ");
    scanf("%s",&staff.password);

    fwrite(&staff,sizeof(staff),1,fp);
    fclose(fp);
    printf("\nStaff saved successfully\n");
    admin();
}

void viewStaff()
{
    dash();
    fp = fopen("staff.txt","r");
    while(fread(&staff,sizeof(staff),1,fp))
    {
        printf("\n\nName: %s\nUserId: %d\nPassword: %s\n", staff.username, staff.id, staff.password);
    }
    fflush(fp);
    fclose(fp);
    admin();
}

void deleteStaff()
{
    dash();
    printf("Enter the staff name to delete\n ");
    input();
    scanf("%s", &name);
    fp = fopen("staff.txt", "r");
    ft = fopen("temp.txt", "w");
    while(fread(&staff,sizeof(staff),1,fp) != 0)
    {
        if(strcmp(name, staff.username) != 0)
        {
            fwrite(&staff,sizeof(staff),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    printf("\nStaff %s deleted successfully\n",name);
    admin();
}

void searchStaff()
{
    dash();
    printf("\nEnter the staff name to search\n ");

    input();

    scanf("%s",&name);
    fp = fopen("staff.txt","r");

    while (fread(&staff,sizeof(staff),1,fp)==1)
    {
        if(strcmp(name, staff.username) == 0)
        {
            printf("\n\nSearch results for '%s'\n\n",name);
            printf("Name: %s\nUserId: %d\nPassword: %s\n", staff.username, staff.id, staff.password);
        }
    }

    admin();
}


void editStaff()
{
    dash();
    printf("\nEnter the staff name to edit\n ");
    input();
    scanf("%s", &name);
    fp = fopen("staff.txt", "r");
    ft = fopen("temp.txt", "w");
    while(fread(&staff,sizeof(staff),1,fp) != 0)
    {
        if(strcmp(name, staff.username) != 0)
        {
            fwrite(&staff,sizeof(staff),1,ft);
        }
    }
    printf("\nEditing staff %s\n\n",name);
    printf("Enter new Id: ");
    scanf("%d", &staff.id);
    printf("\nEnter new username : ");
    scanf("%s", &staff.username);
    printf("Enter new password : ");
    scanf("%s", &staff.password);
    fwrite(&staff,sizeof(staff),1,ft);
    fclose(fp);
    fclose(ft);
    remove("staff.txt");
    rename("temp.txt", "staff.txt");
    printf("\nData edited succesfully\n");
    admin();
}

void staffmenu()
{
    dash();
    printf("\n1. Add books\n2. Edit a book\n3. Delete a book\n4. Search a book\n5. List books\n6. Lending & returning \n7. Students\n8. Log out\n9. Exit\n");
    input();
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        addBook();
        break;
    case 2:
        editBook();
        break;
    case 3:
        delbook();
        break;
    case 4:
        searchBook();
        break;
    case 5:
        listBook();
        break;
    case 6:
        for(;;)
        {
            printf("\n1. Lend a book\n2. Return a book\n");
            input();
            scanf("%d",&choice);
            if (choice== 1)
            {

            }
            else if (choice == 2 )
            {

                //returnBook();

            }
            else
            {
                invalid();
            }


        }
        break;
    case 7:
        staffStudentsMenu();
        break;
    case 8:
        main();
        break;
    case 9:

        printf("\nSystem state saved\n\n");
        dash();
        exit(0);
        break;

    default:
        invalid();
        break;
    }
}

void addBook()
{
    dash();
    fp = fopen("book.txt","a");


    printf("Enter details below \n");

    fflush(stdin);
    printf("\n\tEnter book ID : ");
    scanf("%d",&books.bookid);



    printf("\n\tBook name : ");
    fflush(stdin);

    gets(books.bookname);
    fflush(stdin);
    printf("\n\tAuthor : ");


    strcpy(books.status,"Reserved");
    gets(books.author);
    fwrite(&books,sizeof(books),1,fp);
    fclose(fp);
    printf("\nbooks saved successfully\n");
    staffmenu();
}


void editBook()
{
    dash();
    fp = fopen("book.txt", "r");
    ft = fopen("btemp.txt", "w");
    printf("\nEnter the book title to Edit\n");
    input();
    gets(bname);
    scanf("%[^\n]", &bname);

    while(fread(&books,sizeof(books),1,fp) != 0)
    {
        if(strcmp(bname, books.bookname) != 0)
        {
            fwrite(&books,sizeof(books),1,ft);
        }
    }
    printf("Editing '%s'", bname);
    printf("\n\nEnter new book ID : ");

    scanf("%d", &books.bookid);

    fflush(stdin);
    printf("\nEnter new book name : ");
    gets(books.bookname);


    fflush(stdin);
    printf("\nEnter new book author : ");
    gets(books.author);


    fwrite(&books,sizeof(books),1,ft);
    fclose(fp);
    fclose(ft);
    remove("book.txt");
    rename("btemp.txt", "book.txt");
    staffmenu();
}

void delbook()
{
    dash();
    fp = fopen("book.txt", "r");
    ft = fopen("btemp.txt", "w");
    printf("Enter the book title to Edit\n");
    gets(bname);
    input();
    scanf("%[^\n]", &bname);

    while(fread(&books,sizeof(books),1,fp) != 0)
    {
        if(strcmp(bname, books.bookname) != 0)
        {
            fwrite(&books,sizeof(books),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("book.txt");
    rename("btemp.txt", "book.txt");
    fflush(stdin);
    staffmenu();
}

void listBook()
{

    dash();
    fp = fopen("book.txt", "r");
    while(fread(&books,sizeof(books),1,fp))
    {
        printf("\nBook ID\t\t: %d", books.bookid);
        printf("\nBook Name\t: %s", books.bookname);
        printf("\nBook Author\t: %s", books.author);
        printf("\nBook status\t: %s\n",books.status);
    }
    fclose(fp);
    staffmenu();
}

void adminLogin()
{
    for(;;)
    {
        dash();

        fp = fopen("adminLogin.txt","r");
        char uname[10],passwd[10],un[10],pwd[10];
        fscanf(fp,"%s%s",uname,passwd);


        printf("Default username : admin\nDefault password : admin123\n ");
        printf("\nEnter Username : ");
        scanf("%s",un);
        printf("\nEnter password : ");
        scanf("%s",pwd);

        if((strcmp(uname,un)==0) && (strcmp(passwd,pwd)==0))
        {

            printf("\nLogin success\n");
            admin();
            break;

        }
        else
        {

            printf("\nInvalid credentials, try again\n");

        }

    }
}

void staffLogin()
{

    for(;;)
    {

        dash();
        char staffname[40];
        char staffPass[40];
        printf("\nEnter username : ");

        fflush(stdin);
        scanf("%s", &staffname );
        printf("\nEnter password : ");

        fflush(stdin);
        scanf("%s",&staffPass);

        for(i=0; i<300; i++)
        {
            fp = fopen("staff.txt", "r");
            while(fread(&staff,sizeof(staff),1,fp))
            {
                if(staff.username[0] == i && staff.password[0] == i)
                {
                    if (strcmp(staffname, staff.username)==0 && strcmp(staffPass,staff.password)==0)

                    {

                        printf("\nLogin success\n");
                        staffmenu();

                    }
                    else
                    {

                        printf("\nInvalid credentials, try again\n");

                    }

                }
            }
        }




    }
}



void addStudents()
{
    dash();
    fp = fopen("students.txt","a");


    printf("Enter student's details below \n");

    fflush(stdin);
    printf("\n\tEnter ADM No : ");
    scanf("%d",&student.admNo);



    printf("\n\tStudent name : ");
    fflush(stdin);

    gets(student.name);
    fflush(stdin);

    printf("\n\tStudent login username : ");
    fflush(stdin);

    gets(student.username);
    fflush(stdin);


    printf("\n\tStudent login password : ");
    fflush(stdin);

    gets(student.password);
    fflush(stdin);


    fwrite(&student,sizeof(student),1,fp);
    fclose(fp);
    printf("\nStudent saved successfully\n");
    staffStudentsMenu();
}
void staffStudentsMenu()
{
    for(;;)
    {
        dash();
        printf("\n1. Add Students \n2. Edit Students\n3. Delete Students\n4. View Students \n5. Go to dashboard\n");
        input();
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addStudents();
            break;
        case 2:
            editStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            viewStudents();
            break;
        case 5:
            staffmenu();
            break;
        default:
            invalid();
            break;
        }

    }

}




void editStudent()
{
    dash();
    printf("\nEnter the student's username to edit\n ");
    input();
    scanf("%s", &name);
    fp = fopen("students.txt", "r");
    ft = fopen("temp.txt", "w");
    while(fread(&student,sizeof(student),1,fp) != 0)
    {
        if(strcmp(name, student.username) != 0)
        {
            fwrite(&student,sizeof(student),1,ft);
        }
    }
    printf("\nEditing student %s\n\n",name);
    printf("\tEnter new ADM No : ");
    scanf("%d", &student.admNo);
    printf("\n\tEnter new name : ");
    fflush(stdin);
    gets(student.name);

    printf("\n\tEnter new username : ");
    scanf("%s", &student.username);
    printf("\tEnter new password : ");
    scanf("%s", &student.password);
    fwrite(&student,sizeof(student),1,ft);
    fclose(fp);
    fclose(ft);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("\nStudent data edited succesfully\n");
    staffStudentsMenu();
}


void deleteStudent()
{
    dash();
    printf("Enter student username to delete\n ");
    input();
    scanf("%s", &name);
    fp = fopen("students.txt", "r");
    ft = fopen("temp.txt", "w");
    while(fread(&student,sizeof(student),1,fp) != 0)
    {
        if(strcmp(name, student.username) != 0)
        {
            fwrite(&student,sizeof(student),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    printf("\nStudent %s deleted successfully\n",name);
    staffStudentsMenu();
}


void viewStudents()

{
    dash();
    fp = fopen("students.txt","r");
    while(fread(&student,sizeof(student),1,fp))
    {
        printf("\nUserId : %d \nName : %s \nUsername : %s \nPassword: %s \n\nBooks In use\n\nBook I : %s\nBook II : %s\nBook III : %s\n", student.admNo,student.name,student.username, student.password,student.inuse1,student.inuse2,student.inuse3);
        dash();
    }
    fflush(fp);
    fclose(fp);
    staffStudentsMenu();
}


void searchBook()
{
    dash();
    printf("\nEnter the book's name to search\n ");

    input();

    scanf("%s",&name);
    fp = fopen("books.txt","r");

    while (fread(&books,sizeof(books),1,fp)==1)
        fflush(stdin);
    scanf("%[^\n]",&name);
    fp = fopen("book.txt","r");

    while (fread(&books,sizeof(books),1,fp) )
    {
        if(strcmp(name, books.bookname) == 0)
        {
            printf("\n\nSearch results for '%s'\n\n",name);


            printf("\nBook ID\t\t: %d", books.bookid);
            printf("\nBook Name\t: %s", books.bookname);
            printf("\nBook Author\t: %s", books.author);
            printf("\nBook status\t: %s\n",books.status);
        }
    }
    fclose(fp);
    staffmenu();
}


void studentLogin()
{

    for(;;)
    {

        dash();
        char stname[40];
        char stPass[40];
        printf("\nEnter username : ");

        fflush(stdin);
        scanf("%s", &stname );
        printf("\nEnter password : ");

        fflush(stdin);
        scanf("%s",&stPass);

        for(i=0; i<300; i++)
        {
            fp = fopen("students.txt", "r");
            while(fread(&student,sizeof(student),1,fp))
            {
                if(student.username[0] == i && student.password[0] == i)
                {
                    if (strcmp(stname, student.username)==0 && strcmp(stPass,student.password)==0)

                    {
                        printf("\nLogin success\n");

                        for(;;)
                        {
                            dash();
                            printf("Account details below \n");
                            printf("\nADM No : %d\nName : %s",student.admNo,student.name);
                            printf("\n\nBooks in use");

                            //books loop here


                            fp = fopen("book.txt","r");

                            while (fread(&books,sizeof(books),1,fp) )
                            {
                                if(strcmp(student.inuse1, books.bookname) == 0)
                                {



                                    printf("\nBook ID\t\t: %d", books.bookid);
                                    printf("\nBook Name\t: %s", books.bookname);
                                    printf("\nBook Author\t: %s", books.author);
                                    printf("\nBook status\t: %s\n",books.status);
                                }

                            }

                            while (fread(&books,sizeof(books),1,fp) )
                            {
                                if(strcmp(student.inuse2, books.bookname) == 0)
                                {



                                    printf("\nBook ID\t\t: %d", books.bookid);
                                    printf("\nBook Name\t: %s", books.bookname);
                                    printf("\nBook Author\t: %s", books.author);
                                    printf("\nBook status\t: %s\n",books.status);
                                }

                            }

                            while (fread(&books,sizeof(books),1,fp) )
                            {
                                if(strcmp(student.inuse3, books.bookname) == 0)
                                {



                                    printf("\nBook ID\t\t: %d", books.bookid);
                                    printf("\nBook Name\t: %s", books.bookname);
                                    printf("\nBook Author\t: %s", books.author);
                                    printf("\nBook status\t: %s\n",books.status);
                                }

                            }
                            fclose(fp);

                            printf("\n******************");


                            printf("\n1. Logout : ");

                            scanf("%d",&choice);
                            if (choice==1)
                            {
                                main();
                                break;

                            }
                            else
                            {
                                invalid();

                            }

                        }
                    }
                    else
                    {
                        printf("\nInvalid credentials, try again");
                    }
                }
            }
        }




    }
}



void top()
{
    system("clear");

    printf("\n*************************************************\n");
    printf("\n********    LIBRARY MANAGEMENT SYSTEM   *********\n");
    printf("\n*************************************************\n");
    printf("\n*************************************************\n");
}



