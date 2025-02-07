#include "ares.h"
#include <iostream>

int main() {
	u32 rk[64] = {0};
	u8 rk2[64] = { 0 };
	const u8 cipherKey[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	const u8 cipherKeyTwo[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	u8 salt[256] = { 0 };
	for (int a = 0; a < 256;++a) {
		salt[a] = a;
	}
	for (int b = 0;b < 64;++b) {
		rk2[b] = b;
	}
	int keyBits = 256;
	int rounds = rijndaelKeySetupEnc( rk, cipherKey, keyBits);
 	u8 pt[16] = { 'e','e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' ,'e' };
	u8 ct[16] = {0};
	rijndaelEncrypt(rk,rk2,salt, rounds, pt, ct);
	for (int i = 0;i < 16;++i) {
		std::cout << ct[i];
	}
	std::cout << "\n\n";
	u32 rk_d[64] = { 0 };
	u8 rrk_d[64] = { 0 };
	for (int c = 0;c < 64;++c) {
		rrk_d[c] = c;
	}
	int rounds_d = rijndaelKeySetupDec(rk_d, cipherKey, keyBits);

	u8 plaintext[16] = { 0 };
	rijndaelDecrypt(rk_d, rrk_d, salt, rounds_d, ct, plaintext);
	for (int j = 0;j < 16;++j) {
		std::cout << (int)plaintext[j];
	}
	return 0;
}