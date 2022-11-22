#include "include/compile.h"
#include "include/list.h"

int main(int argc, char* argv){
/*
	FILE* f = fopen("examples/blink.bl", "rb");
	char c;
	unsigned int i = 0;
	while((c=fgetc(f)) != EOF) {
		i++;
	}
	fclose(f);
	FILE* g = fopen("examples/blink.bl", "rb");
	char* content = calloc(i, sizeof(char));
	unsigned int j = 0;
	while(j < i){
		content[j] = fgetc(g);
		j++;
	}
	fclose(g);

	compile(content);
*/
	compile("word BCM2837_GPFSE2 = 1059061768\
		word BCM2837_GPFSET0 = 1059061788\
		word BCM2837_GPFCLR0 = 1059061800\
		func write32(*dst, word val)	\
			dst* = val		\
		endfunc				\
						\
		func read32(*src) endfunc src*	\
						\
		func delay(word ticks)		\
			word i			\
			while i < ticks		\
				i++		\
			endwhile		\
		endfunc				\
						\
		func main()			\
			word gpfsel2 = read32(BCM2837_GPFSEL2)	\
			gpfsel2 |= (1<<3)			\
			write32(BCM2837_GPFSEL2, gpfsel2)	\
						\
			word i			\
						\
			while 1			\
				write32(BCM2837_GPFSET0, 1<<21)\
				delay(1000000)	\
				write32(BCM2837_GPCLR0, 1<<21)\
				delay(1000000) \
				ABCDEFGHIJ ABCDEFGHIJK ABCDEFGHIJKL ABCDEFGHIJKLM ABCDEFGHIJKLMN ABCDEFGHIJKLMNO ABCDEFGHIJKLMNOP ABCDEFGHIJKLMNOPQ ABCDEFGHIJKLMNOPQR ABCDEFGHIJKLMNOPQRS ABCDEFGHIJKLMNOPQRST ABCDEFGHIJKLMNOPQRSTU ABCDEFGHIJKLMNOPQRSTUV ABCDEFGHIJKLMNOPQRSTUVW ABCDEFGHIJKLMNOPQRSTUVWX ABCDEFGHIJKLMNOPQRSTUVWXY ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	return 0;
}
