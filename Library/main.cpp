//
// Created by j_kui on 13-10-2026.
//

#include "Library.h"

void printLibrary(Library* lib) {
    for (int i = 0; i < lib->library.size(); ++i) {
        std::cout << "Book " << i + 1 << ": ";
        lib->library.at(i).printBook();
    }
}

int main() {
    std::string input;
    Library lib;
    Lender* currUser;
    bool loggedIn = false;
    bool usedCommand = false;
    const int maxBooks = 5;
    std::cout << "Commands are as follows:" << std::endl;
    std::cout << "q = quit" << std::endl;
    std::cout << "AddBook = add new book" << std::endl; // FIXMEEEEEEEEEEEEEEEEEEEEEEEEEEE
    std::cout << "PrintLib = print every book in the library" << std::endl; // FIXMEEEEEEEEEEEEEEEEEEEEEEEEEEE
    std::cout << "Login = log in as a user (only usable if you haven't logged in)" << std::endl; // FIXMEEEEEEEEEEEEEEEEEEEEEEEEEEE
    std::cout << "SignUp = Create a new account (only usable if you haven't logged in)" << std::endl; // FIXMEEEEEEEEEEEEEEEEEEEEEEEEEEE
    std::cout << "Next some commands which are only usable if you are logged in:" << std::endl;
    std::cout << "BorrowBook = borrow a book" << std::endl;
    std::cout << "SeeBorrowed = print all books you borrowed" << std::endl;
    std::cout << "ReturnBook = return a book you borrowed" << std::endl;
    std::cin >> input;
    while (input != "q") {
        usedCommand = false;
        if (input == "AddBook") {
            lib.addBook();
            usedCommand = true;
        }
        else if (input == "PrintLib") {
            printLibrary(&lib);
            usedCommand = true;
        }
        if (!loggedIn) {
            if (input == "Login") {
                currUser = lib.logIn();
                if (currUser != nullptr) {
                    loggedIn = true;
                    std::cout << "Successfully logged in" << std::endl;
                }
                usedCommand = true;
            }
            else if (input == "SignUp") {
                lib.addUser();
                usedCommand = true;
            }
        }
        else {
            if (input == "BorrowBook") {
                lib.borrowBook(currUser, maxBooks);
                usedCommand = true;
            }
            else if (input == "SeeBorrowed") {
                currUser->printBorrowed();
                usedCommand = true;
            }
            else if (input == "ReturnBook") {
                lib.returnBook(currUser);
                usedCommand = true;
            }
        }
        if (!usedCommand) {
            std::cout << "Input was not recognized. Make sure you use a valid command." << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    }
    return 0;
}