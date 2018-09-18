#ifndef FILTER_PERSON_H
#define FILTER_PERSON_H

#include "Date.h"
#include <string>

namespace algorithm {

class Person {
public:
  Person() : birthDate_(70, 1, 1){};
  std::string name_;
  Date birthDate_;

  friend bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name_ == rhs.name_ && lhs.birthDate_ == rhs.birthDate_;
  }

  friend bool operator!=(const Person &lhs, const Person &rhs) {
    return !(rhs == lhs);
  }

  std::string getName() { return name_; }

  void setName(const std::string &name) { name_ = name; }

  Date getBirthDate() { return birthDate_; }

  void setBirthDate(Date birthDate) { birthDate_ = birthDate; }
};
}
#endif // FILTER_PERSON_H
