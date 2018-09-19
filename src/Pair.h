
#ifndef FILTER_PAIR_H
#define FILTER_PAIR_H

#include "Person.h"

namespace algorithm
{

class Pair
{
    Person younger_, older_;
    long age_difference_;

  public:
    Pair() = default;
    Pair(Person p, Person q)
    {
        if (p.getBirthDate() < q.getBirthDate())
        {
            younger_ = p;
            older_ = q;
        }
        else
        {
            younger_ = q;
            older_ = p;
        }
        age_difference_ = older_.getBirthDate().getTime() - younger_.getBirthDate().getTime();
    }

    Person const& Younger() const { return younger_; }

    Person const& Older() const { return older_; }

    long AgeDifference() const { return age_difference_; }
};
}  // namespace algorithm
#endif  // FILTER_PAIR_H
