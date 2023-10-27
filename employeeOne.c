
#include <string.h>
#include "employee.h"


PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)  //search until end of table  ptr++ will increment by what??
    {
        if(ptr->number == targetNumber) //check if it equals the Employee number
            return (PtrToEmployee) ptr; //return location of the number to callee.
    }
     return NULL;   //this will only happen if no Employee number matches in loop above
}

//Essentially the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(const Employee * table, int tableSize, char targetName[]) {
    
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(table[i].name, targetName) == 0) {
            return &table[i];
        }
    }
    return NULL;
}
PtrToEmployee searchEmployeeByPhone(const Employee * table, int tableSize, char targetNumber[]) {
    
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(table[i].phone, targetNumber) == 0) {
            return &table[i];
        }
    }
    return NULL;
}

PtrToEmployee searchEmployeeBySalary(const Employee * table, int tableSize, double targetSalary) {
    
    for (int i = 0; i < tableSize; i++) {
        if (table[i].salary == targetSalary) {
            return &table[i];
        }
    }
    return NULL;
}
PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, 
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    return NULL;
}
