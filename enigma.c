#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* constants and then variables */
const char ALPH[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char FAST[26] = "BDHFJLCPRTXVZNYEIWGAKMUSQO";
const char MED[26] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const char SLOW[26] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const char REFL[26] = "IXUHFEZDAOMTKQJWNSRLCYPBVG";
const char RSLOW[26] = "UWYGADFPVZBECKMTHXSLRINQOJ";
const char RMED[26] = "AJPCZWRLFBDKOTYUQGENHXMIVS";
const char RFAST[26] = "TAGBPCSDQEUFVNZHYIXJWLRKOM";
int rot = 0;
int ind;

/* function declarations */
char apply_rotors(char letter);
int find_index(char c);

/*functions */
int main(int argc, char **argv){
	int num = 1;
	int length = 1;
	char encrypted;
	int imax;
	int i;
	while (num < argc){
		length = strlen(argv[num]);
		imax = length;
		i = 0;
		while (i<imax){
			encrypted = apply_rotors(toupper(argv[num][i]));
			printf("%c", encrypted);
			i++;
		
		}
		num++;
		printf(" ");

	}
	return 0;


}

char apply_rotors(char letter){
	rot++;
	ind = find_index(letter);
	
	/*i should have written a loop for these but i didn't */
	ind = ind +  rot%26;
	ind = ind%26;
	letter = FAST[ind];
	ind = find_index(letter);
	ind = ind - rot%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	ind = ind + (rot/26)%26;
	ind = ind%26;
	letter = MED[ind];
	ind = find_index(letter);
	ind = ind - (rot/26)%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	ind = ind + ((rot/26)/26)%26;
	ind = ind%26;
	letter = SLOW[ind];
	ind = find_index(letter);
	ind = ind - ((rot/26)/26)%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	letter = REFL[ind];
	ind = find_index(letter);

	ind = ind + ((rot/26)/26)%26;
	ind = ind%26;
	letter = RSLOW[ind];
	ind = find_index(letter);
	ind = ind - ((rot/26)/26)%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	ind = ind + (rot/26)%26;
	ind = ind%26;
	letter = RMED[ind];
	ind = find_index(letter);
	ind = ind - (rot/26)%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	ind = ind + rot%26;
	ind = ind%26;
	letter = RFAST[ind];
	ind = find_index(letter);
	ind = ind - rot%26;
	if (ind < 0) {
		ind = ind + 26;
	}

	letter = ALPH[ind];
	return letter;
}

int find_index(char c){
	int i = 0;
	while (i<27) {
		if (ALPH[i] == c) {
			return i;
		i++;
		}
	}
	printf("\nsomething went wrong, index not found for %c", c);
	return 0;
}

