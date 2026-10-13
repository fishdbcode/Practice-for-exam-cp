//
// Created by j_kui on 13-10-2026.
//

#ifndef PRACTICE_ASSIGNMENTS_LENDER_H
#define PRACTICE_ASSIGNMENTS_LENDER_H

#include <vector>
#include <iostream>
#include "Book.h"

class Lender {
public:
    Lender(int age, std::string firstName, std::string lastName, int ID) : age(age), firstName(firstName), lastName(lastName), numBorrowed(0), ID(ID) {}
    void borrowBook(Book* newBook, int maxBooks);
    void returnBook(Book* newBook);
    void setNumBorrowed(int newNum) {numBorrowed = newNum;}
    int getAge() {return age;}
    std::string getFirstName() {return firstName;}
    std::string getLastName() {return lastName;}
    int getNumBorrowed() {return numBorrowed;}
private:
    const int age;
    const std::string firstName;
    const std::string lastName;
    std::vector<Book*> borrowed;
    int numBorrowed;
    const int ID;
};


#endif //PRACTICE_ASSIGNMENTS_LENDER_H
