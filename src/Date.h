#ifndef FILTER_DATE_H
#define FILTER_DATE_H

#include <ctime>

namespace algorithm {

    class Date {
        private:
        int year_;
        int month_;
        int day_;

        public:
        Date(int year_, int month_, int day_)
            : year_(year_), month_(month_), day_(day_) {}

        long getTime() const {
            std::tm tm{0, 0, 0, day_, month_, year_ - 1900};
            return std::mktime(&tm);
        }

        friend bool operator==(const Date &lhs, const Date &rhs) {
            return lhs.year_ == rhs.year_ && lhs.month_ == rhs.month_ &&
                lhs.day_ == rhs.day_;
        }

        friend bool operator!=(const Date &lhs, const Date &rhs) {
            return !(rhs == lhs);
        }

        friend bool operator<(const Date &lhs, const Date &rhs) {
            if (lhs.year_ < rhs.year_)
            return true;
            if (rhs.year_ < lhs.year_)
            return false;
            if (lhs.month_ < rhs.month_)
            return true;
            if (rhs.month_ < lhs.month_)
            return false;
            return lhs.day_ < rhs.day_;
        }

        friend bool operator>(const Date &lhs, const Date &rhs) { return rhs < lhs; }

        friend bool operator<=(const Date &lhs, const Date &rhs) {
            return !(rhs < lhs);
        }

        friend bool operator>=(const Date &lhs, const Date &rhs) {
            return !(lhs < rhs);
        }
    };
}

#endif // FILTER_DATE_H