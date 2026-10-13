//
// Created by j_kui on 13-10-2026.
//

#include "Library.h"

void Library::addBook() {
    std::string author;
    std::string title;
    int ISBN;
    std::cout << "Enter author name: " << std::endl;
    if (std::getline(std::cin, author)) {
        std::cout << "Enter book title: " << std::endl;
        if (std::getline(std::cin, title)) {
            std::cout << "Enter ISBN: " << std::endl;
            if (std::cin >> ISBN) {
                Book newBook(title, author, ISBN);
                library.push_back(newBook);
                std::cout << "The book was successfully added." << std::endl;
            }
            else {
                std::cout << "Something went wrong entering the ISBN." << std::endl;
            }
        }
        else {
            std::cout << "Something went wrong entering the title." << std::endl;
        }
    }
    else {
        std::cout << "Something went wrong entering the author." << std::endl;
    }

}

void Library::addUser() {
    int age;
    std::string firstName;
    std::string lastName;
    std::cout << "Enter first name: " << std::endl;
    if (std::cin >> firstName) {
        std::cout << "Enter last name: " << std::endl;
        if (std::cin >> lastName) {
            std::cout << "Enter age: " << std::endl;
            if (std::cin >> age) {
                Lender newUser(age, firstName, lastName, lastID + 1);
                users.push_back(newUser);
                lastID += 1;
                std::cout << "The user was successfully added." << std::endl;
            }
            else {
                std::cout << "Something went wrong entering the age." << std::endl;
            }
        }
        else {
            std::cout << "Something went wrong entering the last name." << std::endl;
        }
    }
    else {
        std::cout << "Something went wrong entering the first name." << std::endl;
    }
}