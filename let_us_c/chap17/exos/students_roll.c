/* Create a structure to specify data on student 
 *
 * (1) write a function to print names of all students who joined
 * in a particular year
 * (2) write a function to print the data of a student whose roll number
 * is received by the function
 *
 */

#include <stdio.h>

struct student_data {
    int roll;
    char name[50];
    char department[50];
    char course[20];
    int yoj;
} student_[450] = { 34, "Kish", "IT", "Java", 2005,
    10, "Siraj", "computer science", "Tech", 2005,
    53, "Deepak", "computer science", "C", 2005,
    13, "Karan", "history", "europe", 2010,
    1, "Aakask", "IT", "Ruby", 2005,
    2, "Ramesh", "Chess", "Opening", 2010
};

void student_by_year(int);
void student_data(int);

int main() {
    int yoj, roll;
    printf("\nEnter year of joining of the students: ");
    scanf("%d", &yoj);
    student_by_year(yoj);

    printf("\nEnter the roll number of any student to get his data: ");
    scanf("%d", &roll);
    student_data(roll);

    return 0;
}

void student_by_year(int year) {
    int i;
    printf("\n\t\tYear of joining: %d\n", year);
    for (i = 0; i <= 450; i++) {
        if (student_[i].yoj == year) {
            printf("\nRoll Number: %d", student_[i].roll);
            printf("\nName: %s", student_[i].name);
            printf("\nDepartement: %s", student_[i].department);
            printf("\nCourse: %s\n", student_[i].course);
        }
    }
}

void student_data(int enroll) {
    int i;
    printf("\nRoll number: %d\n", enroll);
    for (i = 0; i <= 450; i++) {
        if (student_[i].roll == enroll) {
            printf("\nName: %s", student_[i].name);
            printf("\nDepartment: %s", student_[i].department);
            printf("\nCourse: %s", student_[i].course);
            printf("\nYear of joining: %d\n", student_[i].yoj);
        }
    }
}

