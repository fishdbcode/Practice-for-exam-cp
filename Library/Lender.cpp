//
// Created by j_kui on 13-10-2026.
//

#include "Lender.h"

bool Lender::borrowBook(Book* newBook, int maxBooks) {
    if (newBook->getAvailable()) {
        if (numBorrowed < maxBooks) {
            borrowed.push_back(newBook);
            newBook->setAvailable(false);
            numBorrowed += 1;
            std::cout << "Borrowed " << newBook->getTitle() << " successfully. You have now borrowed " << numBorrowed << " book(s)." << std::endl;
            return true;
        }
        else {
            std::cout << "Sorry, you have too many books. Return one to borrow another." << std::endl;
        }
    }
    else {
        std::cout << "Sorry, this book has already been borrowed by another user." << std::endl;
    }
    return false;
}

void Lender::returnBook(Book* newBook) {
    for (int i = 0; i < borrowed.size(); i++) {
        if (newBook == borrowed.at(i)) {
            borrowed.erase(borrowed.begin() + i);
            newBook->setAvailable(true);
            numBorrowed -= 1;
            std::cout << "Successfully returned " << newBook->getTitle() << ". You now have " << numBorrowed << " book(s)." << std::endl;
            return;
        }
    }
    std::cout << "You have not borrowed " << newBook->getTitle() << "." << std::endl;
}

void Lender::printBorrowed() {
    for (int i = 0; i < borrowed.size(); ++i) {
        borrowed.at(i)->printBook();
    }
}