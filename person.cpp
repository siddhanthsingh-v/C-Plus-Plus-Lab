#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    
    // Salary components
    double basicPay;
    double houseRentAllowance; // HRA
    double specialAllowance;

public:
    // Default constructor
    Person() : age(0), basicPay(0.0), houseRentAllowance(0.0), specialAllowance(0.0) {
        strcpy(name, "N/A");
        strcpy(address, "N/A");
    }

    // Parameterized Constructor to set Person details & salary components
    Person(const char n[], int a, const char addr[], double basic, double hra, double allow)
        : age(a), basicPay(basic), houseRentAllowance(hra), specialAllowance(allow) {
        strncpy(name, n, 63);
        name[63] = '\0';
        strncpy(address, addr, 63);
        address[63] = '\0';
        cout << "Person object created for: " << name << endl;
    }

    // Destructor
    ~Person() {
        cout << "Person object destroyed for: " << name << endl;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Function to calculate total salary
    double getTotalSalary() const {
        return basicPay + houseRentAllowance + specialAllowance;
    }

    // (b) Method to display the salary slip
    void displaySalarySlip() const {
        cout << "\n-----------------------------------" << endl;
        cout << "           SALARY SLIP             " << endl;
        cout << "-----------------------------------" << endl;
        cout << "Name           : " << name << endl;
        cout << "Age            : " << age << endl;
        cout << "Address        : " << address << endl;
        cout << "Basic Pay      : $" << basicPay << endl;
        cout << "HRA            : $" << houseRentAllowance << endl;
        cout << "Special Allow. : $" << specialAllowance << endl;
        cout << "-----------------------------------" << endl;
        cout << "Total Salary   : $" << getTotalSalary() << endl;
        cout << "-----------------------------------\n" << endl;
    }
};

// (a) Inline function to find the youngest and eldest age from an array of Person objects
inline void findYoungestAndEldest(const Person people[], int size, int &youngest, int &eldest) {
    if (size <= 0) return;
    
    youngest = people[0].getAge();
    eldest = people[0].getAge();

    for (int i = 1; i < size; ++i) {
        if (people[i].getAge() < youngest) {
            youngest = people[i].getAge();
        }
        if (people[i].getAge() > eldest) {
            eldest = people[i].getAge();
        }
    }
}

int main() {
    // Array of objects of class Person of size 10
    Person people[10] = {
        Person("Alice", 25, "123 Main St", 3000, 500, 200),
        Person("Bob", 45, "456 Oak Ave", 5000, 800, 400),
        Person("Charlie", 19, "789 Pine Rd", 2000, 300, 100),
        Person("Diana", 32, "101 Maple St", 4000, 600, 300),
        Person("Ethan", 58, "202 Elm St", 6500, 1000, 500),
        Person("Fiona", 29, "303 Cedar Ln", 3500, 550, 250),
        Person("George", 62, "404 Birch Rd", 7000, 1200, 600),
        Person("Hannah", 22, "505 Spruce St", 2500, 400, 150),
        Person("Ian", 38, "606 Walnut Ave", 4500, 700, 350),
        Person("Julia", 51, "707 Ash Dr", 5800, 900, 450)
    };

    // (a) Obtaining youngest and eldest age
    int minAge, maxAge;
    findYoungestAndEldest(people, 10, minAge, maxAge);

    cout << "\n===================================" << endl;
    cout << "Youngest Person Age : " << minAge << " years" << endl;
    cout << "Eldest Person Age   : " << maxAge << " years" << endl;
    cout << "===================================" << endl;

    // (b) Displaying salary slip for a sample person
    people[0].displaySalarySlip();

    return 0;
}