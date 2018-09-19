#ifndef FILTER_FINDER_H
#define FILTER_FINDER_H

#include <vector>

#include "Pair.h"
#include "Person.h"

namespace algorithm {

enum class DifferenceType
{
    Minimal,
    Maximal
};

class Finder {
private:
  std::vector<Person> _p;

public:
  Finder(std::vector<Person> p) { _p = p; }

  Pair Find(DifferenceType diffType)
  {
    std::vector<Pair> tr;

    if (_p.size() == 0)
      return Pair{};

    for (int i = 0; i < _p.size() - 1; i++) {
      for (int j = i + 1; j < _p.size(); j++) {
        Pair r{_p[i], _p[j]};
        tr.push_back(r);
      }
    }

    if (tr.size() < 1) {
      return Pair{};
    }

    auto answer = tr[0];
    for (auto const& result : tr) {
      switch (diffType) {
      case DifferenceType::Minimal:
        if (result.AgeDifference() < answer.AgeDifference()) {
          answer = result;
        }
        break;

      case DifferenceType::Maximal:
        if (result.AgeDifference() > answer.AgeDifference()) {
          answer = result;
        }
        break;
      }
    }

    return answer;
  }
};
}
#endif // FILTER_FINDER_H
