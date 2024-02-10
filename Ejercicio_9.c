#include <stdio.h>
#define SIZE 4
struct student{
 char name[50];
 int roll;
 float marks;
};
int main(){
 struct student s[SIZE];
 int i;
 printf("Enter information of students:\n");
 for(i=0;i<SIZE;i++)
 {
 s[i].roll=i+1;
 printf("\nFor roll number %d\n",s[i].roll);
 printf("Enter name: ");
 scanf("%s",s[i].name);
 printf("Enter marks: ");
 scanf("%f",&s[i].marks);
 printf("\n");
 }
 printf("Displaying information of students:\n\n");
 for(i=0;i<SIZE;i++)
 {
 printf("\nInformation for roll number %d:\n",i+1);
 printf("Name: ");
 puts(s[i].name);
 printf("Marks: %.1f",s[i].marks);
 }
 return 0;
}

