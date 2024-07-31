#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include "Admin.h"
#include "Book.h"
#include <vector>
#include <fstream>

class Database {
public:
    static void saveUsers(const std::vector<User>& users);
    static std::vector<User> loadUsers();
    static void saveAdmins(const std::vector<Admin>& admins);
    static std::vector<Admin> loadAdmins();
    static void saveBooks(const std::vector<Book>& books);
    static std::vector<Book> loadBooks();
};

#endif // DATABASE_H
