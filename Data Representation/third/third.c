#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[argc + 1]) {
	if (fopen(argv[1],"r")){
		FILE* f = fopen(argv[1],"r");
		long dec;
		long dig;
		char a;
		char b;
		while (fscanf(f,"%ld %ld %c %c\n", &dec, &dig, &a, &b)!= EOF){
			if ( a == 'u' && b == 's'){
			long count = dig;
			long endneg = 1;
				while (count != 0){
					endneg = endneg * 2;
					count--;
					}
				long count1 = dig-1;
				long startneg = 1;
					while (count1 != 0){
						startneg = startneg * 2;
						count1--;
					}
				if (startneg <= dec && dec < endneg){
					long print = dec - endneg;
					printf("%ld\n", print);
				}
				else{
					printf("%ld\n", dec);
				}
			}
			else{
				if (dec >=0){
					printf("%ld\n", dec);
				}
				else{
					long count = dig;
					long endneg = 1;
						while (count != 0){
							endneg = endneg * 2;
							count--;
						}
						long hold = dec + endneg;
						printf("%ld\n", hold);
				}
			}
		}
}
}

