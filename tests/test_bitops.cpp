#include "catch.hpp"
#include "../bitops.h"

using namespace bitops;

TEST_CASE("flip") {
    int x = 0b000;

    flip(x, 3);
    REQUIRE(x == 0b100);

    flip(x, 2);
    REQUIRE(x == 0b110);

    flip(x, 3);
    REQUIRE(x == 0b010);
}

TEST_CASE("is_set") {
    REQUIRE(is_set(0, 1) == false);
    REQUIRE(is_set(1, 1) == true);

    REQUIRE(is_set(0b00010000, 5) == true);
    REQUIRE(is_set(0b00000010, 1) == false);
}

TEST_CASE("is_not_set") {
    REQUIRE(is_not_set(0, 1) == true);
    REQUIRE(is_not_set(1, 1) == false);

    REQUIRE(is_not_set(0b00010000, 5) == false);
    REQUIRE(is_not_set(0b00000010, 1) == true);
}

TEST_CASE("set") {
    int x = 0;
    REQUIRE(is_set(x, 1) == false);
    set(x, 1);
    REQUIRE(is_set(x, 1) == true);

    // make sure it doesn't flip and really just sets by setting again
    // and expecting no difference in output
    set(x, 1);
    REQUIRE(is_set(x, 1) == true);
}

TEST_CASE("unset") {
    int x = 0b11;
    unset(x, 1);
    REQUIRE(x == 0b10);

    unset(x, 2);
    REQUIRE(x == 0b00);

    REQUIRE(x == 0);

    x = 0b10;
    unset(x, 1);
    REQUIRE(x == 0b10);
}

TEST_CASE("is_mask_set") {
    unsigned char i    = 0b00000000;
    unsigned char mask = 0b01010101;

    REQUIRE(is_mask_set(i, mask) == false);

    i = mask;

    REQUIRE(is_mask_set(i, mask) == true);

    i = 0b11111111;

    REQUIRE(is_mask_set(i, mask) == true);

    unset(i, 1);

    REQUIRE(is_mask_set(i, mask) == false);

    i    = 0;
    mask = 0;

    REQUIRE(is_mask_set(i, mask) == true);
}

TEST_CASE("set_mask") {
    unsigned char i    = 0;
    unsigned char mask = 0b11111111;

    set_mask(i, mask);
    REQUIRE(is_mask_set(i, mask) == true);

    // make sure it doesn't flip
    set_mask(i, mask);
    REQUIRE(is_mask_set(i, mask) == true);

    i    = 0b10101010;
    mask = 0b00000001;

    set_mask(i, mask);
    REQUIRE(i == 0b10101011);
}

TEST_CASE("unset_mask") {
    unsigned char i    = 0b11111111;
    unsigned char mask = 0b10000001;

    unset_mask(i, mask);

    REQUIRE(i == 0b01111110);

    // make sure it doesn't flip!
    unset_mask(i, mask);
    REQUIRE(i == 0b01111110);
}
