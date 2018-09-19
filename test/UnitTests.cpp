
#include <gtest/gtest.h>

#include "Finder.h"
#include "Person.h"

using namespace algorithm;
using std::vector;

class TestFixture : public testing::Test
{
  protected:
    Person sue;
    Person greg;
    Person sarah;
    Person mike;

  public:
    TestFixture()
    {
        sue = Person{"Sue", {1950, 0, 1}};
        greg = Person{"Greg", {1952, 5, 1}};
        sarah = Person{"Sarah", {1982, 0, 1}};
        mike = Person{"Mike", {1979, 0, 1}};
    }
};

TEST_F(TestFixture, Returns_Empty_Results_When_Given_Empty_List)
{
    vector<Person> list;
    Finder finder{list};

    Pair result = finder.Find(DifferenceType::Minimal);
    ASSERT_TRUE(result.Younger().getName().empty());
    ASSERT_TRUE(result.Older().getName().empty());
}

TEST_F(TestFixture, Returns_Empty_Results_When_Given_One_Person)
{
    vector<Person> list;
    list.push_back(sue);

    Finder finder(list);

    Pair result = finder.Find(DifferenceType::Minimal);

    ASSERT_TRUE(result.Younger().getName().empty());
    ASSERT_TRUE(result.Older().getName().empty());
}

TEST_F(TestFixture, Returns_Closest_Two_For_Two_People)
{
    vector<Person> list;
    list.push_back(sue);
    list.push_back(greg);
    Finder finder(list);

    Pair result = finder.Find(DifferenceType::Minimal);
    ASSERT_EQ(sue, result.Younger());
    ASSERT_EQ(greg, result.Older());
}

TEST_F(TestFixture, Returns_Furthest_Two_For_Two_People)
{
    vector<Person> list;
    list.push_back(mike);
    list.push_back(greg);
    Finder finder(list);

    Pair result = finder.Find(DifferenceType::Maximal);
    ASSERT_EQ(greg, result.Younger());
    ASSERT_EQ(mike, result.Older());
}

TEST_F(TestFixture, Returns_Furthest_Two_For_Four_People)
{
    vector<Person> list;
    list.push_back(sue);
    list.push_back(sarah);
    list.push_back(mike);
    list.push_back(greg);
    Finder finder(list);

    Pair result = finder.Find(DifferenceType::Maximal);
    ASSERT_EQ(sue, result.Younger());
    ASSERT_EQ(sarah, result.Older());
}
