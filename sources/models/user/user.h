#pragma once
#include <models/group/group.h>
#include <cereal/cereal.hpp>
#include <string>

class User {
   public:
    User() = default;
    User(const User &) = default;
    User(User &&) noexcept = default;
    User(const long &id, const std::string &firstName, const std::string &lastName);

    const long &getId() const;
    void setId(const long &id);

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    template <class Archive>
    void serialize(Archive &archive) {
        archive(cereal::make_nvp("id", id), cereal::make_nvp("firstName", firstName),
                cereal::make_nvp("lastName", lastName));
    }

   private:
    long id;
    std::string firstName;
    std::string lastName;
};
