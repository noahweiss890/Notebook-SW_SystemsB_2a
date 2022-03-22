#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;
#include <iostream>
#include <stdexcept>
using namespace std;


TEST_CASE("Good input") {
    ariel::Notebook notebook1;
    CHECK(notebook1.read(26, 25, 24, Direction::Horizontal, 10) == "__________");
    notebook1.write(26, 25, 24, Direction::Horizontal, "Hey there!");
    CHECK(notebook1.read(26, 25, 24, Direction::Horizontal, 10) == "Hey there!" );
    notebook1.erase(26, 25, 24, Direction::Horizontal, 10);
    CHECK(notebook1.read(26, 25, 24, Direction::Horizontal, 10) == "~~~~~~~~~~" );

    CHECK(notebook1.read(42, 43, 44, Direction::Vertical, 5) == "_____");
    notebook1.write(42, 43, 44, Direction::Vertical, "hey im writing here!");
    CHECK(notebook1.read(42, 47, 44, Direction::Vertical, 10) == "im writing");
    notebook1.erase(42, 46, 42, Direction::Horizontal, 10);
    CHECK(notebook1.read(42, 46, 42, Direction::Horizontal, 5) == "__~__" );

    notebook1.write(5, 5, 5, Direction::Vertical, "_____");
    CHECK(notebook1.read(5, 5, 5, Direction::Vertical, 5) == "_____");

    notebook1.write(6, 6, 6, Direction::Horizontal, "      ");
    CHECK(notebook1.read(6, 6, 6, Direction::Horizontal, 6) == "      ");

}

TEST_CASE("Bad input") {
    ariel::Notebook notebook2;
    CHECK_THROWS(notebook2.read(50, 40, 120, Direction::Horizontal, 10)); // column bigger than 100
    CHECK_THROWS(notebook2.read(50, 40, 95, Direction::Horizontal, 10)); // column + length > 100

    CHECK_THROWS(notebook2.write(5, 4, 120, Direction::Horizontal, "trying to write")); // column bigger than 100
    CHECK_THROWS(notebook2.write(5, 4, 95, Direction::Horizontal, "wont work either")); // column + text length > 100

    CHECK_THROWS(notebook2.erase(10, 10, 120, Direction::Horizontal, 10)); // column bigger than 100
    CHECK_THROWS(notebook2.erase(10, 10, 95, Direction::Horizontal, 10)); // column + length > 100
}

TEST_CASE("Writing on erase") {
    ariel::Notebook notebook3;
    notebook3.write(50, 40, 30, Direction::Horizontal, "HEY");
    notebook3.erase(50, 40, 30, Direction::Horizontal, 3);
    CHECK_THROWS(notebook3.write(50, 40, 25, Direction::Horizontal, "Hello everyone!"));
    
    notebook3.write(30, 20, 10, Direction::Vertical, "crossword puzzle");
    notebook3.erase(30, 20, 10, Direction::Vertical, 16);
    CHECK_THROWS(notebook3.write(30, 18, 10, Direction::Vertical, "wordle is better!"));
}

TEST_CASE("Writing on written space") {
    ariel::Notebook notebook4;
    notebook4.write(20, 20, 20, Direction::Horizontal, "123456789");
    CHECK_THROWS(notebook4.write(20, 20, 25, Direction::Horizontal, "abcdefghi"));

    notebook4.write(30, 20, 20, Direction::Vertical, "blablabla");
    CHECK_THROWS(notebook4.write(30, 17, 20, Direction::Vertical, "whowhowho"));

    notebook4.write(40, 20, 20, Direction::Horizontal, "these are words");
    CHECK_THROWS(notebook4.write(40, 18, 25, Direction::Vertical, "these are also words"));

    notebook4.write(50, 20, 20, Direction::Vertical, "this will be written");
    CHECK_THROWS(notebook4.write(50, 18, 25, Direction::Horizontal, "and this will try to overwrite it"));
}

TEST_CASE("Writing underscores") {
    ariel::Notebook notebook5;

    notebook5.write(6, 6, 6, Direction::Horizontal, "_____");
    notebook5.write(6, 6, 6, Direction::Horizontal, "this should work");
    CHECK(notebook5.read(6, 6, 11, Direction::Horizontal, 11) == "should work");

    notebook5.write(10, 10, 10, Direction::Vertical, "_______");
    notebook5.write(10, 8, 10, Direction::Vertical, "this too shall work");
    CHECK(notebook5.read(10, 17, 10, Direction::Vertical, 10) == "shall work");
}
