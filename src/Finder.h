#ifndef FILTER_FINDER_H
#define FILTER_FINDER_H

#include <vector>

#include "AgeDifference.h"
#include "FT.h"
#include "Person.h"

namespace algorithm {

class Finder {
private:
  std::vector<Person> _p;

public:
  Finder(std::vector<Person> p) { _p = p; }

  AgeDifference Find(FT ft) {
    std::vector<AgeDifference> tr;

    if (_p.size() == 0)
      return AgeDifference{};

    for (int i = 0; i < _p.size() - 1; i++) {
      for (int j = i + 1; j < _p.size(); j++) {
        AgeDifference r;
        if (_p[i].birthDate_ < _p[j].birthDate_) {
          r.P1 = _p[i];
          r.P2 = _p[j];
        } else {
          r.P1 = _p[j];
          r.P2 = _p[i];
        }
        r.Value = r.P2.birthDate_.getTime() - r.P1.birthDate_.getTime();
        tr.push_back(r);
      }
    }

    if (tr.size() < 1) {
      return AgeDifference{};
    }

    auto answer = tr[0];
    for (auto const& result : tr) {
      switch (ft) {
      case FT::One:
        if (result.Value < answer.Value) {
          answer = result;
        }
        break;

      case FT::Two:
        if (result.Value > answer.Value) {
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
