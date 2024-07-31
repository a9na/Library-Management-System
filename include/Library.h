#ifndef LIBRARY_H
#define LIBRARY_H

#include "User.h"
#include "Admin.h"
#include "Book.h"
#include <vector>

class Library {
public:
    Library();
    void registerUser(const std::string& name, const std::string& password);
    User* loginUser(const std::string& name, const std::string& password);
    Admin* loginAdmin(const std::string& name, const std::string& password);
    std::vector<Book> getBooks() const;
    std::vector<User> getUsers() const;

private:
    std::vector<User> users;
    std::vector<Admin> admins;
    std::vector<Book> books;
};

#endif // LIBRARY_H
