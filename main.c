#include <stdio.h>
#include <string.h>

void encrypt(FILE* input, FILE* output) {

  int byte;
  int i = 0;
  char key[20];
  int key_len;
  printf("Enter The Key :");
  fgets(key, sizeof(key), stdin);
  key[strcspn(key, "\n")] = '\0';
  key_len = strlen(key);
  while ((byte = fgetc(input)) != EOF) {
    byte = byte ^ key[i];
    fputc(byte, output);
    i++;
    if (i >= key_len) {
      i = 0;
    }

  }
  printf("\n-------------File Encrypted---------------");
  fclose(input);
  fclose(output);
}

void decrypt(FILE* input, FILE* output) {
  int byte;
  int i = 0;

  char key[20];

  printf("Enter The Key: ");

  fgets(key, sizeof(key), stdin);

  key[strcspn(key, "\n")] = '\0';

  int key_len = strlen(key);

  if (key_len == 0) {
    printf("Key cannot be empty.");
    return;
  }

  while ((byte = fgetc(input)) != EOF) {

    byte = byte ^ key[i];

    fputc(byte, output);

    i++;

    if (i >= key_len) {
      i = 0;
    }
  }
  printf("\nFile decrypted");
  fclose(input);
  fclose(output);

}

int main() {
  FILE* input;
  FILE* output;
  int option;
  printf("1.Encrypt");
  printf("\n2.decrypt");
  printf("\nEnter Opion: ");
  scanf("%d", &option);
  getchar();
  if (option == 1) {
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

  }
  else if (option == 2) {
    input = fopen("encrypted.bin", "rb");
    output = fopen("decrypted.txt", "wb");
    if (input == NULL) {
      printf("Cant Open FIle");
      return 1;
    }
    if (output == NULL) {
      printf("Cant Create FIle");
      fclose(input);
      return 1;
    }
    decrypt(input, output);
  }
  else {
    printf("Chose a valid option");

  }



  return 0;
}