#include "group.h"

Group::Group(const long &id, const std::string &name) : id(id), name(name) {}

const long &Group::getId() const { return id; }

void Group::setId(const long &id) { this->id = id; }

const std::string &Group::getName() const { return name; }

void Group::setName(const std::string &name) { this->name = name; }
