#include "unity.h"
#include "token.h"


void setUp(void) {}  
void tearDown(void) {}

void token_funct(){}

void test_create_token() {
	t_token token;
	token.funct = &token_funct;
	token.value = (void *) "Hola";

	t_token token2 = *create_token((void *) "Hola", &token_funct);

    TEST_ASSERT_EQUAL(token.funct, token2.funct);
	TEST_ASSERT_EQUAL(token.value, token2.value);
}



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_token);
    return UNITY_END();
}