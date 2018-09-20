#ifndef FILTER_FINDER_H
#define FILTER_FINDER_H

#include <vector>
#include <algorithm>
#include <limits>
#include <cassert>
#include "Pair.h"
#include "Person.h"

namespace algorithm {

enum class DifferenceType
{
    Minimal = 0,
    Maximal = 1
};

class Finder {
private:
  std::vector<Person> _p;

protected:
  static auto findMinDifference(std::vector<Person> const& p_)
  {
      assert(2 <= p_.size());
      Pair res;
      auto curMin = std::numeric_limits<long>::max(); 
      auto b = p_.begin(), n = b, e = p_.end();
      n++;
      for (; n != e; ++b, ++n) {
          auto locMin = n->getBirthDate().getTime() - b->getBirthDate().getTime();
          if (locMin < curMin) {
              curMin = locMin;
              res = Pair{*b, *n};
          }
      }
      return res;
  }

  static auto findMaxDifference(std::vector<Person> const& p_)
  {
      assert(2 <= p_.size());
      return Pair{p_.front(), p_.back()};
  }

  auto getFindFunction(DifferenceType diffType) const
  {
      return diffType == DifferenceType::Minimal ? findMinDifference : findMaxDifference; 
  }

public:
  Finder(std::vector<Person> p) : _p{std::move(p)} 
  {
      std::sort(_p.begin(), _p.end(), [](auto const& l_, auto const& r_) { return l_.getBirthDate() < r_.getBirthDate();
      });
  }

  Pair Find(DifferenceType diffType)
  {
      return _p.size() < 2 ? Pair{} : getFindFunction(diffType)(_p);
  }
};
}
#endif // FILTER_FINDER_H
