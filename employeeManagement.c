#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an employee
typedef struct Employee {
    int empID;
    char name[50];
    double salary;
    struct Employee* next;
} Employee;

// Function to add an employee to the linked list
void addEmployee(Employee** head, int empID, const char* name, double salary) {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    newEmployee->empID = empID;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = *head;
    *head = newEmployee;
    printf("Employee added successfully.\n");
}

// Function to remove an employee from the linked list
void removeEmployee(Employee** head, int empID) {
    Employee* current = *head;
    Employee* prev = NULL;

    while (current != NULL && current->empID != empID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found.\n", empID);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Employee with ID %d removed successfully.\n", empID);
}

// Function to search for an employee by ID
void searchEmployee(Employee* head, int empID) {
    Employee* current = head;

    while (current != NULL) {
        if (current->empID == empID) {
            printf("Employee ID: %d\n", current->empID);
            printf("Name: %s\n", current->name);
            printf("Salary: %.2f\n", current->salary);
            return;
        }
        current = current->next;
    }

    printf("Employee with ID %d not found.\n", empID);
}

// Function to display all employees
void displayEmployees(Employee* head) {
    Employee* current = head;

    if (current == NULL) {
        printf("No employees in the system.\n");
        return;
    }

    while (current != NULL) {
        printf("Employee ID: %d\n", current->empID);
        printf("Name: %s\n", current->name);
        printf("Salary: %.2f\n\n", current->salary);
        current = current->next;
    }
}

// Function to compute the salary of an employee based on a given percentage increase
void computeSalary(Employee* head, int empID, double percentageIncrease) {
    Employee* current = head;

    while (current != NULL) {
        if (current->empID == empID) {
            current->salary *= (1 + percentageIncrease / 100);
            printf("Salary for employee with ID %d updated.\n", empID);
            return;
        }
        current = current->next;
    }

    printf("Employee with ID %d not found.\n", empID);
}

int main() {
    Employee* head = NULL;
    int choice;
    
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Search Employee\n");
        printf("4. Display Employees\n");
        printf("5. Compute Salary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int empID;
                char name[50];
                double salary;
                printf("Enter Employee ID: ");
                scanf("%d", &empID);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Salary: ");
                scanf("%lf", &salary);
                addEmployee(&head, empID, name, salary);
                break;
            }
            case 2: {
                int empID;
                printf("Enter Employee ID to remove: ");
                scanf("%d", &empID);
                removeEmployee(&head, empID);
                break;
            }
            case 3: {
                int empID;
                printf("Enter Employee ID to search: ");
                scanf("%d", &empID);
                searchEmployee(head, empID);
                break;
            }
            case 4:
                displayEmployees(head);
                break;
            case 5: {
                int empID;
                double percentageIncrease;
                printf("Enter Employee ID to update salary: ");
                scanf("%d", &empID);
                printf("Enter Percentage Increase: ");
                scanf("%lf", &percentageIncrease);
                computeSalary(head, empID, percentageIncrease);
                break;
            }
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory before exiting
    while (head != NULL) {
        Employee* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}