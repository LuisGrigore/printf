#include "../Unity-master/src/unity.h"
#include "../printf.h"


void setUp(void) {}  
void tearDown(void) {}

void test_suma_positivos() {
    TEST_ASSERT_EQUAL(5, suma(2, 3));
}

void test_suma_negativos() {
    TEST_ASSERT_EQUAL(-4, suma(-2, -2));
}

void test_suma_cero() {
    TEST_ASSERT_EQUAL(0, suma(0, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_suma_positivos);
    RUN_TEST(test_suma_negativos);
    RUN_TEST(test_suma_cero);
    return UNITY_END();
}