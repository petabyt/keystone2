#include <stdio.h>
#include <keystone/keystone.h>

const char *test_split =
"shlq $0x20, %rax\n"
"orq %rax, %rcx\n"
"movq %rcx, %rdi\n"
"movq %rbp, %rcx\n"
"shlq $0x20, %rax\n"
"orq %rax, %rcx\n"
"movq %rcx, %rax\n"
"cld\n"
"rep stosq %rax, (%rdi)\n"
"retq\n";

static void handler(void *arg, unsigned int of, unsigned int size) {
	printf("%u %u\n", of, size);
}

int main(void) {
	ks_engine *ks;
	ks_err err = ks_open(KS_ARCH_X86, KS_MODE_64, &ks);
	if (err) {
		printf("ks_open\n");
		return -1;
	}

	ks_option(ks, KS_OPT_SYNTAX, KS_OPT_SYNTAX_ATT);

	ks_set_instruction_stream_handler(ks, handler, NULL);

	size_t count = 0;
	unsigned char *encode = NULL;
	size_t size = 0;
	err = ks_asm(ks, test_split, 0x0, &encode, &size, &count);
	if (err) {
		printf("ks_asm\n");
		return -1;
	}

	return 0;
}
