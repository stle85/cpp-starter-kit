#pragma once
#include <cereal/cereal.hpp>
#include <string>

class Group {
   public:
    Group() = default;
    Group(const Group &) = default;
    Group(Group &&) noexcept = default;
    Group(const long &id, const std::string &name);

    const long &getId() const;
    void setId(const long &id);

    const std::string &getName() const;
    void setName(const std::string &name);

    template <class Archive>
    void serialize(Archive &archive) {
        archive(cereal::make_nvp("id", id), cereal::make_nvp("name", name));
    }

   private:
    long id;
    std::string name;
};
