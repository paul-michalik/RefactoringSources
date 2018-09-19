#ifndef FILTER_PERSON_H
#define FILTER_PERSON_H

#include "Date.h"
#include <string>
#include <utility>

namespace algorithm
{

class Person
{
    std::string name_;
    Date birthDate_{70, 1, 1};

  public:
    Person() = default;
    Person(std::string name, Date birthDate) : name_{std::move(name)}, birthDate_{std::move(birthDate)} {}
    friend bool operator==(const Person& lhs, const Person& rhs)
    {
        return lhs.name_ == rhs.name_ && lhs.birthDate_ == rhs.birthDate_;
    }

    friend bool operator!=(const Person& lhs, const Person& rhs) { return !(rhs == lhs); }

    std::string const& getName() const { return name_; }

    Date const& getBirthDate() const { return birthDate_; }
};
}  // namespace algorithm
#endif  // FILTER_PERSON_H
