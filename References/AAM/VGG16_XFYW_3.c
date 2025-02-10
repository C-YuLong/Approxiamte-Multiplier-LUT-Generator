#pragma once
#include <cstdint>

inline uint64_t VGG16_XFYW_3(uint64_t x, uint64_t y) {
    // Calculate partial products
    uint64_t part1 = (x & (1 << 0)) ? y : 0;
    uint64_t part2 = (x & (1 << 1)) ? y : 0;
    uint64_t part3 = (x & (1 << 2)) ? y : 0;
    uint64_t part4 = (x & (1 << 3)) ? y : 0;
    uint64_t part5 = (x & (1 << 4)) ? y : 0;
    uint64_t part6 = (x & (1 << 5)) ? y : 0;
    uint64_t part7 = (x & (1 << 6)) ? y : 0;
    uint64_t part8 = (x & (1 << 7)) ? y : 0;

    // Calculate new_part1
    uint64_t new_part1 = 0;
    new_part1 |= ((((part3 >> 7) && 1)&&((part4 >> 6) && 1)) ? 1U : 0U) << 10;
    new_part1 |= ((((part3 >> 7) && 1)^((part4 >> 6) && 1)) ? 1U : 0U) << 9;
    new_part1 |= ((((part2 >> 7) && 1)) ? 1U : 0U) << 8;
    new_part1 |= ((((part1 >> 6) && 1)||((part2 >> 5) && 1)) ? 1U : 0U) << 7;
    new_part1 |= ((((part3 >> 4) && 1)&&((part4 >> 3) && 1)) ? 1U : 0U) << 6;
    new_part1 |= ((0) ? 1U : 0U) << 5;
    new_part1 |= ((((part1 >> 3) && 1)||((part2 >> 2) && 1)) ? 1U : 0U) << 4;
    new_part1 |= ((((part3 >> 1) && 1)||((part4 >> 0) && 1)) ? 1U : 0U) << 3;
    new_part1 |= ((((part1 >> 1) && 1)||((part2 >> 0) && 1)) ? 1U : 0U) << 2;
    new_part1 |= ((0) ? 1U : 0U) << 1;
    new_part1 |= ((0) ? 1U : 0U) << 0;

    // Calculate new_part2
    uint64_t new_part2 = 0;
    new_part2 |= ((((part4 >> 7) && 1)) ? 1U : 0U) << 10;
    new_part2 |= ((0) ? 1U : 0U) << 9;
    new_part2 |= ((((part3 >> 6) && 1)&&((part4 >> 5) && 1)) ? 1U : 0U) << 8;
    new_part2 |= ((((part1 >> 7) && 1)^((part2 >> 6) && 1)) ? 1U : 0U) << 7;
    new_part2 |= ((0) ? 1U : 0U) << 6;
    new_part2 |= ((0) ? 1U : 0U) << 5;
    new_part2 |= ((0) ? 1U : 0U) << 4;
    new_part2 |= ((0) ? 1U : 0U) << 3;
    new_part2 |= ((0) ? 1U : 0U) << 2;
    new_part2 |= ((0) ? 1U : 0U) << 1;
    new_part2 |= ((0) ? 1U : 0U) << 0;

    // Calculate new_part3
    uint64_t new_part3 = 0;
    new_part3 |= ((0) ? 1U : 0U) << 10;
    new_part3 |= ((0) ? 1U : 0U) << 9;
    new_part3 |= ((((part3 >> 6) && 1)||((part4 >> 5) && 1)) ? 1U : 0U) << 8;
    new_part3 |= ((((part3 >> 4) && 1)||((part4 >> 3) && 1)) ? 1U : 0U) << 7;
    new_part3 |= ((0) ? 1U : 0U) << 6;
    new_part3 |= ((0) ? 1U : 0U) << 5;
    new_part3 |= ((0) ? 1U : 0U) << 4;
    new_part3 |= ((0) ? 1U : 0U) << 3;
    new_part3 |= ((0) ? 1U : 0U) << 2;
    new_part3 |= ((0) ? 1U : 0U) << 1;
    new_part3 |= ((0) ? 1U : 0U) << 0;

    // Calculate new_part4
    uint64_t new_part4 = 0;
    new_part4 |= ((0) ? 1U : 0U) << 10;
    new_part4 |= ((0) ? 1U : 0U) << 9;
    new_part4 |= ((0) ? 1U : 0U) << 8;
    new_part4 |= ((((part3 >> 5) && 1)&&((part4 >> 4) && 1)) ? 1U : 0U) << 7;
    new_part4 |= ((0) ? 1U : 0U) << 6;
    new_part4 |= ((0) ? 1U : 0U) << 5;
    new_part4 |= ((0) ? 1U : 0U) << 4;
    new_part4 |= ((0) ? 1U : 0U) << 3;
    new_part4 |= ((0) ? 1U : 0U) << 2;
    new_part4 |= ((0) ? 1U : 0U) << 1;
    new_part4 |= ((0) ? 1U : 0U) << 0;

    // Calculate new_part5
    uint64_t new_part5 = 0;
    new_part5 |= ((0) ? 1U : 0U) << 10;
    new_part5 |= ((0) ? 1U : 0U) << 9;
    new_part5 |= ((0) ? 1U : 0U) << 8;
    new_part5 |= ((((part3 >> 5) && 1)||((part4 >> 4) && 1)) ? 1U : 0U) << 7;
    new_part5 |= ((0) ? 1U : 0U) << 6;
    new_part5 |= ((0) ? 1U : 0U) << 5;
    new_part5 |= ((0) ? 1U : 0U) << 4;
    new_part5 |= ((0) ? 1U : 0U) << 3;
    new_part5 |= ((0) ? 1U : 0U) << 2;
    new_part5 |= ((0) ? 1U : 0U) << 1;
    new_part5 |= ((0) ? 1U : 0U) << 0;

    // Final summation
    return ((uint64_t)part5 << 4) + ((uint64_t)part6 << 5) + ((uint64_t)part7 << 6) + ((uint64_t)part8 << 7) + new_part1 + new_part2 + new_part3 + new_part4 + new_part5;
}
