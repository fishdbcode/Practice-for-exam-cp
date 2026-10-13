//
// Created by j_kui on 13-10-2026.
//

#ifndef PRACTICE_FOR_EXAM_CP_BOOK_H
#define PRACTICE_FOR_EXAM_CP_BOOK_H

#include <string>

class Book {
public:
    Book(std::string title, std::string author, int ISBN) : title(title), author(author), ISBN(ISBN), available(true) {}
    void setAvailable(bool newVal) {available = newVal;}
    std::string getTitle() {return title;}
    std::string getAuthor() {return author;}
    int getISBN() {return ISBN;}
    bool getAvailable() {return available;}
private:
    const std::string title;
    const std::string author;
    const int ISBN;
    bool available;
};


#endif //PRACTICE_FOR_EXAM_CP_BOOK_H
