//
// Created by j_kui on 13-10-2026.
//

#include "Lender.h"
#include <iostream>

void Lender::borrowBook(Book* newBook, int maxBooks) {
    if (numBorrowed < maxBooks) {
        borrowed.push_back(newBook);
        numBorrowed += 1;
        std::cout << "Borrowed " << newBook->getTitle() << " successfully. You have now borrowed " << numBorrowed << " books." << std::endl;
    }
    else {
        std::cout << "Sorry, you have too many books. Return one to borrow another." << std::endl;
    }
}