#include <gtest/gtest.h>

#include "../object.h"  // Your file with the CwC declaration of Object
#include "../string.h"  // Your file with the String class
#include "../list.h"    // Your file with the two list classes
#include "../helper.h"  // Your file, with any C++ code that you need

#define CS4500_ASSERT_TRUE(a)  \
  ASSERT_EQ((a),true);
#define CS4500_ASSERT_FALSE(a) \
  ASSERT_EQ((a),false);
#define CS4500_ASSERT_EXIT_ZERO(a)  \
  ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  CS4500_ASSERT_TRUE(s->equals(s));
  CS4500_ASSERT_FALSE(s->equals(t));
  CS4500_ASSERT_FALSE(s->equals(u));
  exit(0);
}

TEST(W1, test1) {
  CS4500_ASSERT_EXIT_ZERO(test1)
}

void test2() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  CS4500_ASSERT_TRUE(l->get(0)->equals(s));
  exit(0);
}

TEST(W1, test2) {
  CS4500_ASSERT_EXIT_ZERO(test2)
}

void test3() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->sorted_add(s);
  l2->sorted_add(t);
  l2->sorted_add(u);
  CS4500_ASSERT_TRUE(l->equals(l2));
  CS4500_ASSERT_TRUE(l2->equals(l));
  CS4500_ASSERT_TRUE(l->hash() == l2->hash());
  exit(0);
}

TEST(W1, test3) {
  CS4500_ASSERT_EXIT_ZERO(test3)
}

void test4() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->add_all(0,l);
  CS4500_ASSERT_TRUE(l->size() == l2->size());
  exit(0);
}

TEST(W1, test4) {
  CS4500_ASSERT_EXIT_ZERO(test4)
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
