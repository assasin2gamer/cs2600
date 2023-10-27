//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

//gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(void){

    //defined in employeeTable.c
    extern Employee EmployeeTable[];    
    extern const int EmployeeTableEntries;     

    PtrToEmployee matchPtr;  //Declaration
    
    //Example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    
    //Success
    char phone[] = "909-555-1235";
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, phone);
    if (matchPtr != NULL)
        printf("Phone %s is in record %d\n", phone, matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    //Fail
    char phone_fail[] = "909-555-0000";
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, phone_fail);
    if (matchPtr != NULL)
        printf("Phone %s is in record %d\n", phone_fail, matchPtr - EmployeeTable);
    else
        printf("Phone %s is not in record \n", phone_fail);
    //Success
    double salary  = 8.78;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary);
    if (matchPtr != NULL){
        printf("Salary %f ", salary);
        printf(" is in record %d\n", matchPtr - EmployeeTable);
    }
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    //Fail
    double salary_fail = 9.78;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary_fail);
    if (matchPtr != NULL){
        printf("Salary %f ", salary_fail);
        printf(" is in record %d\n", matchPtr - EmployeeTable);
    }
    else{
        printf("Salary %f ", salary_fail);
        printf(" is not in record\n");
    }

        
    
    return EXIT_SUCCESS;
}