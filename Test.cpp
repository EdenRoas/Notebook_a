/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Eden Roas>
 * 
 * Date: 2022-03
 */

#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;
#include "Direction.hpp"
#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Good Input"){
    Notebook notebook;
    notebook.write(0,0,0,Direction::Vertical,"Hello");
    CHECK(notebook.read(0,0,0,Direction::Vertical, 5) == "Hello");
    notebook.write(0,0,6,Direction::Vertical,"my name is");
    CHECK(notebook.read(0,0,6,Direction::Vertical, 10) == "my name is");
    notebook.write(0,0,17,Direction::Vertical,"Eden");
    CHECK(notebook.read(0,0,17,Direction::Vertical, 4) == "Eden");
    CHECK(notebook.read(0,0,17,Direction::Vertical, 6) == "Eden__");
    notebook.erase(0,0,17, Direction::Horizontal,3);
    CHECK(notebook.read(0,0,17,Direction::Vertical, 6) == "~~~n__");
    notebook.erase(0,0,0, Direction::Horizontal,4);
    CHECK(notebook.read(0,0,0,Direction::Vertical, 5) == "~~~~o");
}
TEST_CASE("Bad Input"){
    Notebook notebook;
    CHECK_THROWS(notebook.write(10,80,101,Direction::Vertical, "this assignment"));//size of line limit=100
    CHECK_THROWS(notebook.write(72,8,81,Direction::Horizontal, "my"));//
    CHECK_THROWS(notebook.write(72,8,81,Direction::Horizontal, "name"));//we already write here
    CHECK_THROWS(notebook.write(72,8,81,Direction::Vertical, "is"));//we already write here
    CHECK_THROWS(notebook.write(34,15,100,Direction::Horizontal, "HELLO"));//limit col is 100
    CHECK_THROWS(notebook.write(-1,10,99,Direction::Horizontal, "HELLO"));//first page =0
    CHECK_THROWS(notebook.write(5,20,100,Direction::Horizontal, "Hi What's up??"));
    CHECK_THROWS(notebook.read(10,80,101,Direction::Vertical,-10));
    CHECK_THROWS(notebook.read(-6,-20,100,Direction::Vertical,-5));
    CHECK_THROWS(notebook.read(64,15,118,Direction::Horizontal,3));
    CHECK_THROWS(notebook.read(4,5,100,Direction::Horizontal,118));
    CHECK_THROWS(notebook.read(3,5,-7,Direction::Horizontal,105));
    CHECK_THROWS(notebook.erase(32,7,100,Direction::Vertical, -4));
    CHECK_THROWS(notebook.erase(78,7,100,Direction::Horizontal, 200));

}

 