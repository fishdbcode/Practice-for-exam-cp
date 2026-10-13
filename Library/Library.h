//
// Created by j_kui on 13-10-2026.
//

#ifndef PRACTICE_FOR_EXAM_CP_LIBRARY_H
#define PRACTICE_FOR_EXAM_CP_LIBRARY_H

#include "Lender.h"
#include <limits>

class Library {
public:
    Library() : lastID(-1) {}
    void addBook();
    void addUser();
    Lender* logIn();
    void borrowBook(Lender* currUser, int maxBooks);
    void returnBook(Lender* currUser);
    Book* findBook(int ISBN);
    std::vector<Book> library;
private:
    std::vector<Lender> users;
    int lastID;
};


#endif //PRACTICE_FOR_EXAM_CP_LIBRARY_H
