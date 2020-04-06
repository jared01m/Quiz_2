// Subset Sum Function with Tests
// Program by: Jared McArthur
// EID: jtm4343
// Date: 4/6/2020

#include <cstdio>
#include <cassert>

bool subsetSum(uint32_t a[], uint32_t n, uint32_t x, uint32_t s) {
    if (s == 0 && x == 0)
        return true;
    if (s != 0 && x == 0)
        return false;
    if (n == 0)
        return false;
    int res1 = 0;
    if (s >= a[0])
        res1 = subsetSum(a + 1, n - 1, x - 1, s - a[0]);
    int res2 = subsetSum(a + 1, n - 1, x, s);
    return res1 + res2 > 0;
}

int main(void) {
    //tests
    printf("Begin tests...\n\n");
    uint32_t arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Test 1: true (1 + 4 || 3 + 2)
    uint32_t n = 10;
    uint32_t x = 2;
    uint32_t s = 5;
    assert(subsetSum(arr, n, x, s));
    printf("Test 1 passed...\n");

    //Test 2: false
    n = 10;
    x = 2;
    s = 2;
    assert(!subsetSum(arr, n, x, s));
    printf("Test 2 passed...\n");

    //Test 3: true
    n = 10;
    x = 0;
    s = 0;
    assert(subsetSum(arr, n, x, s));
    printf("Test 3 passed...\n");

    //Test 4: false
    n = 10;
    x = 0;
    s = 5;
    assert(!subsetSum(arr, n, x, s));
    printf("Test 4 passed...\n");

    //Test 5: true (1 + 2 + 9 || 2 + 3 + 7 || etc.)
    n = 10;
    x = 4;
    s = 12;
    assert(subsetSum(arr, n, x, s));
    printf("Test 5 passed...\n");

    //Test 6: false
    n = 10;
    x = 3;
    s = 28;
    assert(!subsetSum(arr, n, x, s));
    printf("Test 6 passed...\n");

    uint32_t arr2[5] = {0, 3, 6, 3, 2};

    //Test 7: true (3 + 3)
    n = 5;
    x = 2;
    s = 6;
    assert(subsetSum(arr2, n, x, s));
    printf("Test 7 passed...\n");

    //Test 8: true (0 + 2)
    n = 5;
    x = 2;
    s = 2;
    assert(subsetSum(arr2, n, x, s));
    printf("Test 8 passed...\n");

    printf("\nAll tests passed.\n");
    return 0;
}

