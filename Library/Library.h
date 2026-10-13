//
// Created by j_kui on 13-10-2026.
//

#ifndef PRACTICE_FOR_EXAM_CP_LIBRARY_H
#define PRACTICE_FOR_EXAM_CP_LIBRARY_H

#include "Lender.h"


class Library {
public:
    Library() : lastID(0) {}
    void addBook();
    void addUser();
private:
    std::vector<Book> library;
    std::vector<Lender> users;
    int lastID;
};


#endif //PRACTICE_FOR_EXAM_CP_LIBRARY_H
