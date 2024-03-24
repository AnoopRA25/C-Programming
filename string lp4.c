#include <stdio.h>
#include<string.h>
char LUT[26] = "QRSTUVWXYZABCDEFGHIJKLMNOP";

int getLocationFromLUT(char c) {
  int i = 0;
  while (i < 26) {
    if (LUT[i] == c) return i;
    else i++;
  }
  return -1;
}

char * encode(char * str) {
  int i = 0;
  while (str[i] != '\0') {
    int locationInAlphabet = str[i] - 65;
    str[i++] = LUT[locationInAlphabet];
  }
  return (str);
}
char * decode(char * str) {
  int i = 0;
  while (str[i] != '\0') {
    int location = getLocationFromLUT(str[i]);
    str[i++] = location + 65;
  }
  return (str);
}
int main() {
  printf("Enter string to encode (caps & max len 64)\n");
  char word[64];
  scanf("%s", word);

  char * encoded = encode( & word[0]);
  printf("Encoded string %s\n", encoded);

  char * decoded = decode(encoded);
  printf("Decoded string %d\n", decoded);
  return 0;
}
