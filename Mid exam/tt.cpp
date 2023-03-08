#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

class Student {
    public: 
        string name;
        int roll;
        float cgpa;
        int age;
};

void display(Student s1, Student s2, Student s3) {
    Student highest_cgpa = s1;
    if (s2.cgpa > highest_cgpa.cgpa) {
        highest_cgpa = s2;
    }
    if (s3.cgpa > highest_cgpa.cgpa) {
        highest_cgpa = s3;
    }
    cout << "Highest CGPA Student Information:" << endl;
    cout << "Name: " << highest_cgpa.name << endl;
    cout << "Roll Number: " << highest_cgpa.roll << endl;
    cout << "CGPA: " << highest_cgpa.cgpa << endl;
    cout << "Age: " << highest_cgpa.age << endl;
}

void display_lowest_cgpa(Student s1, Student s2, Student s3) {
    Student lowest_cgpa = s1;
    if (s2.cgpa < lowest_cgpa.cgpa) {
        lowest_cgpa = s2;
    }
    if (s3.cgpa < lowest_cgpa.cgpa) {
        lowest_cgpa = s3;
    }
    cout << "Lowest CGPA Student Information:" << endl;
    cout << "Name: " << lowest_cgpa.name << endl;
    cout << "Roll Number: " << lowest_cgpa.roll << endl;
    cout << "CGPA: " << lowest_cgpa.cgpa << endl;
    cout << "Age: " << lowest_cgpa.age << endl;
}

void display_all_students(Student s1, Student s2, Student s3) {
    cout << "All Students Information:" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.roll << endl;
    cout << "CGPA: " << s1.cgpa << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Name: " << s2.name << endl;
    cout << "Roll Number: " << s2.roll << endl;
    cout << "CGPA: " << s2.cgpa << endl;
    cout << "Age: " << s2.age << endl;
    cout << "Name: " << s3.name << endl;
    cout << "Roll Number: " << s3.roll << endl;
    cout << "CGPA: " << s3.cgpa << endl;
    cout << "Age: " << s3.age << endl;
}

int main() {
    Student s1 = {"John", 1, 3.5, 21};
    Student s2 = {"Alice", 2, 4.0, 22};
    Student s3 = {"Bob", 3, 3.8, 20};
    
    thread t1(display, s1, s2, s3);
    thread t2(display_lowest_cgpa, s1, s2, s3);
    thread t3(display_all_students, s1, s2, s3);
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}