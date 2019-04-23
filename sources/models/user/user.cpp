#include "user.h"
#include <utility>

User::User(const long &id, const std::string &firstName, const std::string &lastName)
    : id(id), firstName(firstName), lastName(lastName) {}

const long &User::getId() const { return id; }

void User::setId(const long &id) { this->id = id; }

const std::string &User::getFirstName() const { return firstName; }

void User::setFirstName(const std::string &firstName) { this->firstName = firstName; }

const std::string &User::getLastName() const { return lastName; }

void User::setLastName(const std::string &lastName) { this->lastName = lastName; }
