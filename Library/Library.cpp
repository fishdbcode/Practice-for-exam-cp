//
// Created by j_kui on 13-10-2026.
//

#include "Library.h"

void Library::addBook() {
    std::string author;
    std::string title;
    int ISBN;
    std::cout << "Enter author name: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cin.clear();
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
    std::string password;
    std::cout << "Enter first name: " << std::endl;
    std::cin.clear();
    if (std::cin >> firstName) {
        std::cout << "Enter last name: " << std::endl;
        std::cin.clear();
        if (std::cin >> lastName) {
            std::cout << "Enter age: " << std::endl;
            std::cin.clear();
            if (std::cin >> age) {
                std::cout << "Enter password: " << std::endl;
                std::cin.clear();
                if (std::cin >> password) {
                    Lender newUser(age, firstName, lastName, lastID + 1, password);
                    users.push_back(newUser);
                    lastID += 1;
                    std::cout << "The user was successfully added. Your ID is: " << lastID << std::endl;
                }
                else {
                    std::cout << "Something went wrong entering the password." << std::endl;
                }
            }
            else {
                std::cout << "Something went wrong entering the age." << std::endl;
                std::cin.clear();
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

Lender* Library::logIn() {
    int ID;
    std::string password;
    std::cout << "Enter your ID:" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin >> ID) {
        if (ID < users.size() && ID >= 0) {
            std::cout << "Enter your password: " << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin >> password) {
                if (users.at(ID).checkLogin(password)) {
                    return &users.at(ID);
                }
                std::cout << "Wrong password." << std::endl;
            }
        }
        else {
            std::cout << "Invalid ID" << std::endl;
            std::cin.clear();
        }
    }
    return nullptr;
}

void Library::borrowBook(Lender* currUser, int maxBooks) {
    int ISBN;
    std::cout << "Enter the ISBN" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin >> ISBN) {
        Book* currBook = findBook(ISBN);
        if (currBook != nullptr) {
            bool tempval = currUser->borrowBook(currBook, maxBooks);
            if (tempval) {
                std::cout << "Successfully borrowed the book." << std::endl;
            }
        }
        else {
            std::cout << "This ISBN is not in the collection." << std::endl;
        }
    }
    else {
        std::cin.clear();
        std::cout << "Invalid ISBN (enter a number)" << std::endl;
    }
}

Book* Library::findBook(int ISBN) {
    for (int i = 0; i < library.size(); i++) {
        if (library.at(i).getISBN() == ISBN) {
            return &library.at(i);
        }
    }
    return nullptr;
}

void Library::returnBook(Lender* currUser) {
    int ISBN;
    std::cout << "Enter the ISBN" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin >> ISBN) {
        Book* currBook = findBook(ISBN);
        if (currBook != nullptr) {
            currUser->returnBook(currBook);
        }
    }
    else {
        std::cin.clear();
        std::cout << "Invalid ISBN (enter a number)" << std::endl;
    }
}