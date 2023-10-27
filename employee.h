#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <stdio.h>
#include <stddef.h>
typedef struct {
    long number;
    char *name;
    char *phone;
    double salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;

extern const int EmployeeTableEntries;

PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * targetName);

PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * numberToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double numberToFind);


#endif // EMPLOYEE_H
