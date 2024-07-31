#include "Library.h"

Library::Library() {
    admins.push_back(Admin(1, "admin", "admin123"));
    books.push_back(Book(1, "1984", "George Orwell", 1949));
    books.push_back(Book(2, "To Kill a Mockingbird", "Harper Lee", 1960));
}

void Library::registerUser(const std::string& name, const std::string& password) {
    int id = users.size() + 1;
    users.push_back(User(id, name, password));
}

User* Library::loginUser(const std::string& name, const std::string& password) {
    for (auto& user : users) {
        if (user.getName() == name && user.checkPassword(password)) {
            return &user;
        }
    }
    return nullptr;
}

Admin* Library::loginAdmin(const std::string& name, const std::string& password) {
    for (auto& admin : admins) {
        if (admin.getName() == name && admin.checkPassword(password)) {
            return &admin;
        }
    }
    return nullptr;
}

std::vector<Book> Library::getBooks() const {
    return books;
}

std::vector<User> Library::getUsers() const {
    return users;
}
