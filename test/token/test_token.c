#include "../../Unity-master/src/unity.h"
#include "../../token/token.h"


void setUp(void) {}  
void tearDown(void) {}

void token_funct(){}

void test_create_token() {
	t_token token;
	token.funct = &token_funct;
	token.str_representation = "hola";
	token.token_type = TOKEN_C;
	token.value = (void *) "Hola";

	t_token token2 = *create_token(TOKEN_C, "hola", (void *) "Hola", &token_funct);

    TEST_ASSERT_EQUAL(token.funct, token2.funct);
	TEST_ASSERT_EQUAL(token.str_representation, token2.str_representation);
	TEST_ASSERT_EQUAL(token.token_type, token2.token_type);
	TEST_ASSERT_EQUAL(token.value, token2.value);
}

void test_destruct_token() {

	t_token *token = create_token(TOKEN_C, "hola", (void *) "Hola", &token_funct);
	//destruct_token(token);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_token);
	RUN_TEST(test_destruct_token);
    return UNITY_END();
}