#include<stdio.h>
#include<string.h>

typedef struct student student;
typedef struct teacher teacher;
typedef struct info info;

struct info
{
    char name[50],email[50];
    long long pass;
};
struct student
{
    info studentInfo;
    double cgpa;
    int id;
};
struct teacher
{
    info teacherInfo;
    char designation[20];
};

int main()
{
    int s,t,flag,wrongChecker,index;

    printf("How many students: ");
    scanf("%d",&s);
    printf("How many teachers: ");
    scanf("%d",&t);

    student std[s];
    teacher tchr[t];

    printf("\nEnter student information:\n");

    for(int i=0; i<s; i++)
    {
        fflush(stdin);
        printf("Name: ");
        gets(std[i].studentInfo.name);
        printf("Email: ");
        scanf("%s",&std[i].studentInfo.email);
        printf("Password: ");
        scanf("%lld",&std[i].studentInfo.pass);
        printf("CGPA: ");
        scanf("%lf",&std[i].cgpa);
        std[i].id=i+1;
        printf("\n");
    }

    printf("Enter teacher information:\n");

    for(int i=0; i<t; i++)
    {
        fflush(stdin);
        printf("Name: ");
        gets(tchr[i].teacherInfo.name);
        printf("Email: ");
        scanf("%s",&tchr[i].teacherInfo.email);
        printf("Password: ");
        scanf("%lld",&tchr[i].teacherInfo.pass);
        fflush(stdin);
        printf("Designation: ");
        gets(tchr[i].designation);
    }

    while(1)
    {
        char email[50];
        long long password;
        wrongChecker=1;

        printf("\nLogin as:\n1. Student\n2. Teacher\n\nType Option Here: ");
        scanf("%d",&flag);
        printf("Email: ");
        scanf("%s",&email);
        printf("Password: ");
        scanf("%lld",&password);

        if(flag==1)
        {
            for(int i=0; i<s; i++)
            {
                if(strcmp(std[i].studentInfo.email,email)==0 && std[i].studentInfo.pass==password)
                {
                    index=i;
                    wrongChecker=0;
                    break;
                }
            }

            if(wrongChecker==1)
                printf("Invalid Email or Password. Please try again.\n");
            else
            {
                printf("\nLogin Successful !\n");
                while(1)
                {
                    printf("\nOptions:\n1. See Details\n2. Logout\n3. Exit\n\nType Option Here: ");
                    scanf("%d",&flag);

                    if(flag==1)
                    {
                        printf("Student Details:\n");
                        printf("ID: %d\n",std[index].id);
                        printf("Name: %s\n",std[index].studentInfo.name);
                        printf("Email: %s\n",std[index].studentInfo.email);
                        printf("Password: %lld\n",std[index].studentInfo.pass);
                        printf("CGPA: %lf\n",std[index].cgpa);
                    }
                    else if(flag==2)
                    {
                        printf("Logout Successful !\n");
                        break;
                    }
                    else if(flag==3)
                    {
                        return 0;
                    }
                    else
                        printf("Invalid Option!!!\n");
                }
            }
        }

        else if(flag==2)
        {
            for(int i=0; i<t; i++)
            {
                if(strcmp(tchr[i].teacherInfo.email,email)==0 && tchr[i].teacherInfo.pass==password)
                {
                    index=i;
                    wrongChecker=0;
                    break;
                }
            }

            if(wrongChecker==1)
                printf("\nInvalid Email or Password. Please try again.\n\n");
            else
            {
                printf("\nLogin Successful !\n");
                while(1)
                {
                    printf("\nOptions:\n1. See All Students Details\n2. See All Teachers Details\n3. Edit Student Name\n4. Logout\n5. Exit\n\nType Option Here: ");
                    scanf("%d",&flag);
                    printf("\n");

                    if(flag==1)
                    {
                        printf("All Students Info:\n\n");
                        for(int i=0; i<t; i++)
                        {
                            printf("ID: %d\n",std[i].id);
                            printf("Name: %s\n",std[i].studentInfo.name);
                            printf("Email: %s\n",std[i].studentInfo.email);
                            printf("CGPA: %lf\n",std[i].cgpa);
                        }
                    }
                    else if(flag==2)
                    {
                        printf("All Teachers Info:\n\n");
                        for(int i=0; i<t; i++)
                        {
                            printf("Name: %s\n",tchr[i].teacherInfo.name);
                            printf("Email: %s\n",tchr[i].teacherInfo.email);
                            printf("Designation: %s\n",tchr[i].designation);
                        }
                    }
                    else if(flag==3)
                    {
                        int stdID;
                        printf("Enter Student ID: ");
                        scanf("%d",&stdID);

                        printf("Enter New Name: ");
                        fflush(stdin);
                        gets(std[stdID-1].studentInfo.name);
                    }
                    else if(flag==4)
                    {
                        printf("Logout Successful !\n");
                        break;
                    }
                    else if(flag==5)
                    {
                        return 0;
                    }
                    else
                        printf("Invalid Option!!!\n");
                }
            }
        }
    }
}
