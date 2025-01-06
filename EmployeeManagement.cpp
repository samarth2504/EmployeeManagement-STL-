#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee& emp) {
    cout << "ID: " << emp.id << ", name: " << emp.name << ", salary: $" << emp.salary << endl;
}

int main() {
    vector<Employee> employees = {
        {101, "Samarth", 10000},
        {102, "Shubham", 30000},
        {103, "samaksh", 40000},
        {104, "Saksham", 70000},
        {105, "Anirudh", 50000},
    };

    // use of lambda && sorting to find a respective employee
    // lambda woh function hote hai jinka naam nahi hota
    sort(employees.begin(), employees.end(), [](const Employee &e1, const Employee &e2) {
        return e1.salary > e2.salary;
    });

    cout << "Employees sorted by salary->highest to lowest\n";
    for_each(employees.begin(), employees.end(), displayEmployee);

    // unhi employees ko rakhne ke liye ek vector jinki salary zyada ho
    vector<Employee> highEarners;
    copy_if(
        employees.begin(),
        employees.end(),
        back_inserter(highEarners),
        [](const Employee& e) {
            return e.salary > 50000;
        }
    );

    cout << "employees who are high earners\n";
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);

    double totalSalary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee& e) {
        return sum + e.salary;
    });

    double averageSalary = totalSalary / employees.size();
    auto highestPaid = max_element(employees.begin(), employees.end(), [](const Employee& e1, const Employee& e2) {
        return e1.salary < e2.salary;
    });

    return 0;
}
