/**
 * @addtogroup hash Hash algorithms
 * @{
 * @file hash_adler32.c
 * @author [Christian Bender](https://github.com/christianbender)
 * @brief 32-bit [Adler hash](https://en.wikipedia.org/wiki/Adler-32) algorithm
 */
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 32-bit Adler algorithm implementation
 *
 * @param s NULL terminated ASCII string to hash
 * @return 32-bit hash result
 */
int adler32(const char* s)
{
    int a = 1;
    int b = 0;
    const int MODADLER = 65521;

    int i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
        i++;
    }
    return (b << 16) | a;
}

/**
 * @brief Test function for ::adler32
 * \returns None
 */
void test_adler32()
{
    int size = 1000000;
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char s1[size];

    char test_01[size];
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % (sizeof(characters) - 1);
        s1[i] = characters[randomIndex];
    }

    adler32(s1);
    // assert(adler32("Hello World") == 403375133);
    // assert(adler32("Hello World!") == 474547262);
    // assert(adler32("Hello world") == 413860925);
    // assert(adler32("Hello world!") == 487130206);
    // printf("Tests passed\n");
}

/** @} */

/** Main function */
int main()
{
    test_adler32();
    return 0;
}