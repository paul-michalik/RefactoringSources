
#include <gtest/gtest.h>

#include "Finder.h"
#include "Person.h"

using namespace algorithm;
using std::vector;

class TestFixture : public testing::Test {
protected:
  Person sue;
  Person greg;
  Person sarah;
  Person mike;

public:
  TestFixture() {
    sue.name_.assign("Sue");
    sue.birthDate_ = Date{1950, 0, 1};
    greg.name_.assign("Greg");
    greg.birthDate_ = Date{1952, 5, 1};
    sarah.name_ = "Sarah";
    sarah.birthDate_ = Date{1982, 0, 1};
    mike.name_ = "Mike";
    mike.birthDate_ = Date{1979, 0, 1};
  }
};

TEST_F(TestFixture, Returns_Empty_Results_When_Given_Empty_List) {
  vector<Person> list;
  Finder finder{list};

  AgeDifference result = finder.Find(FT::One);
  ASSERT_TRUE(result.Younger.name_.empty());
  ASSERT_TRUE(result.Older.name_.empty());
}

TEST_F(TestFixture, Returns_Empty_Results_When_Given_One_Person) {
  vector<Person> list;
  list.push_back(sue);

  Finder finder(list);

  AgeDifference result = finder.Find(FT::One);

  ASSERT_TRUE(result.Younger.name_.empty());
  ASSERT_TRUE(result.Older.name_.empty());
}

TEST_F(TestFixture, Returns_Closest_Two_For_Two_People) {
  vector<Person> list;
  list.push_back(sue);
  list.push_back(greg);
  Finder finder(list);

  AgeDifference result = finder.Find(FT::One);
  ASSERT_EQ(sue, result.Younger);
  ASSERT_EQ(greg, result.Older);
}

TEST_F(TestFixture, Returns_Furthest_Two_For_Two_People) {
  vector<Person> list;
  list.push_back(mike);
  list.push_back(greg);
  Finder finder(list);

  AgeDifference result = finder.Find(FT::Two);
  ASSERT_EQ(greg, result.Younger);
  ASSERT_EQ(mike, result.Older);
}

TEST_F(TestFixture, Returns_Furthest_Two_For_Four_People) {
  vector<Person> list;
  list.push_back(sue);
  list.push_back(sarah);
  list.push_back(mike);
  list.push_back(greg);
  Finder finder(list);

  AgeDifference result = finder.Find(FT::Two);
  ASSERT_EQ(sue, result.Younger);
  ASSERT_EQ(sarah, result.Older);
}
