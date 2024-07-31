#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Book.h"
#include <vector>

class Admin {
public:
    Admin(int id, const std::string& name, const std::string& password);
    int getId() const;
    std::string getName() const;
    bool checkPassword(const std::string& password) const;
    void addUser(User& user);
    void removeUser(User& user);
    void addBook(Book& book);
    void removeBook(Book& book);
    std::vector<User> getUsers() const;
    std::vector<Book> getBooks() const;

private:
    int id;
    std::string name;
    std::string password;
    std::vector<User> users;
    std::vector<Book> books;
};

#endif // ADMIN_H
