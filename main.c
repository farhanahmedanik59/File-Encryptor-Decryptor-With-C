#include <stdio.h>
#include <string.h>

void encrypt(FILE* input, FILE* output) {
  int byte;
  int i = 0;
  char key[20];
  int key_len = strlen(key);
  printf("Enter The Key :");
  fgets(key, sizeof(key), stdin);
  key[strcspn(key, "\n")] = '\0';
  while (byte = fgetc(input) != EOF) {
    byte = byte ^ key[i];
    fputc(byte, output);
    i++;
    if (i >= key_len) {
      i = 0;
    }

  }
  printf("File Encrypted");
}

int main() {
  FILE* input;
  FILE* output;

  input = fopen("input.txt", "rb");
  output = fopen("encrypted.bin", "wb");
  if (input == NULL) {
    printf("Cant Open FIle");
    return 1;
  }
  if (output == NULL) {
    printf("Cant Create FIle");
    fclose(input);
  }
  encrypt(input, output);

  return 0;
}