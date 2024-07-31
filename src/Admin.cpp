#include "Admin.h"

Admin::Admin(int id, const std::string& name, const std::string& password)
    : id(id), name(name), password(password) {}

int Admin::getId() const { return id; }
std::string Admin::getName() const { return name; }
bool Admin::checkPassword(const std::string& password) const { return this->password == password; }
void Admin::addUser(User& user) { users.push_back(user); }
void Admin::removeUser(User& user) {
    users.erase(std::remove(users.begin(), users.end(), user), users.end());
}
void Admin::addBook(Book& book) { books.push_back(book); }
void Admin::removeBook(Book& book) {
    books.erase(std::remove(books.begin(), books.end(), book), books.end());
}
std::vector<User> Admin::getUsers() const { return users; }
std::vector<Book> Admin::getBooks() const { return books; }
