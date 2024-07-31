#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

class User {
public:
    User(int id, const std::string& name, const std::string& password);
    int getId() const;
    std::string getName() const;
    bool checkPassword(const std::string& password) const;
    void borrowBook(Book& book);
    void returnBook(Book& book);
    std::vector<Book> getBorrowedBooks() const;

private:
    int id;
    std::string name;
    std::string password;
    std::vector<Book> borrowedBooks;
};

#endif // USER_H
