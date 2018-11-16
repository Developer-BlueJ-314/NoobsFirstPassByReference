/***********************************************************************************/
/* */
/* This is where your put your name, student ID, date, */
/* version, and, the description of what you program */
/* is to accomplish. Example: */
/* */
/* Name: Jay */
/* Student ID: 1137086 */
/* Date: September 28, 2018 */
/* */
/* Homework 4 */
/* Program Set 1 */
/* */
/* Write a C program to calculate salary raise for employees.  */
/* */
/***********************************************************************************/
#include <stdio.h>

//Chart Name
void firstColumn()
{
    printf("                |Rate      |Raise     |New Salary\n");
}

//Number of Employees
void employeeCounter(int *n)
{
    printf("How many salaries? ");
    scanf("%d", &(*n));
}

//Salary Data
void getName_Salary(char name[15], float *pay)
{
    printf("Employee Name: \n");
    scanf("%s", name);

    printf("Salary: \n");
    scanf("%f", &(*pay));
}

//Determine Raise rate
float calcRaiseRate(float salary)
{
    float rate;
    if(salary > 0 && salary < 30000)
    {
        rate = 0.07;
    }
    if(salary >= 30000 && salary <= 40000)
    {
        rate = 0.055;
    }
    if(salary > 40000)
    {
        rate = 0.04;
    }
    return rate;
}

//Sum Up Everything
float calcRaise(float salary, float rate)
{
    float raise, newSalary = 0;
    raise = salary * rate;
    return raise;
}

float calcEmployeePay(float raise, float pay)
{
    float realPay = raise + pay;
    return realPay;
}

void printEmployee( float rate, float raise, float newPay)
{
    printf("                |%10.3f|%10.2f|%10.2f|\n", rate, raise, newPay);
}


void sumEveryEmployee(float *pay, float *raise, float *total, float emp_pay, float emp_raise, float emp_realPay)
{
    *pay += emp_pay;
    *raise += emp_raise;
    *total += emp_realPay;
}

void printTotal(float totalSalary, float totalRaise, float totalNew)
{
    printf("Total:          |%10.2f|%10.2f|%10.2f|\n", totalSalary, totalRaise, totalNew);
}

int main()
{
    float totalSalary, totalRaise, totalNew = 0;
    int n = 0;
    char employeeName[15];
    float salary, rate, employeeRaise, newSalary = 0;

    employeeCounter(&n);
    printf("Type in each employee's name and salary amount. \n");
    firstColumn();
    for(int i = 0; i < n; i++)
    {
        getName_Salary(employeeName, &salary);
        rate = calcRaiseRate(salary);
        employeeRaise = calcRaise(salary, rate);
        newSalary = calcEmployeePay(salary, employeeRaise);
        //program gets stuck here
        printEmployee(rate, employeeRaise, newSalary);
        sumEveryEmployee(&totalSalary, &totalRaise, &totalNew, salary, employeeRaise, newSalary);
    }
    printTotal(totalSalary, totalRaise, totalNew);
}
/*
How many salaries? 6
Type in each employee's name and salary amount.
                |Rate      |Raise     |New Salary
Employee Name:
John_Doe
Salary:
25000
                |     0.070|   1750.00|  26750.00|
Employee Name:
Bill_Knott
Salary:
30000
                |     0.055|   1650.00|  31650.00|
Employee Name:
Bett_Mann
Salary:
35000
                |     0.055|   1925.00|  36925.00|
Employee Name:
King_Kong
Salary:
40000
                |     0.055|   2200.00|  42200.00|
Employee Name:
Mister_Ed
Salary:
40001
                |     0.040|   1600.04|  41601.04|
Employee Name:
GomerPyle
Salary:
45000
                |     0.040|   1800.00|  46800.00|
Total:          | 215001.00|  10925.04| 225926.03|

Process returned 0 (0x0)   execution time : 53.476 s
Press any key to continue.

*/
