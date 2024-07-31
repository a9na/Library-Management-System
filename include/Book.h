#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(int id, const std::string& title, const std::string& author, int year);
    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool isBorrowed() const;
    void borrowBook();
    void returnBook();

private:
    int id;
    std::string title;
    std::string author;
    int year;
    bool borrowed;
};

#endif // BOOK_H
