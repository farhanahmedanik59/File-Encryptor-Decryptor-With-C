#include <stdio.h>
#include <string.h>

char* get_extention(char* filename) {
  char* dot = strrchr(filename, '.');
  if (dot == NULL) {
    return "";
  }
  return dot;

}
void encrypt(FILE* input, FILE* output, char* file_ext) {

  int byte;
  int i = 0;
  char key[20];
  int key_len;
  printf("Enter The Key :");
  fgets(key, sizeof(key), stdin);
  key[strcspn(key, "\n")] = '\0';
  key_len = strlen(key);
  if (key_len <= 0) {
    printf("Key Can not be empty");
    fclose(input);
    fclose(output);
    return;
  }

  fputs(file_ext, output);
  fputc('\n', output);
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

void decrypt(FILE* input) {
  int byte;
  int i = 0;
  FILE* output;
  char file_ext[20];
  char output_file_name[250] = "decrypted";
  char key[20];

  printf("Enter The Key: ");

  fgets(key, sizeof(key), stdin);

  key[strcspn(key, "\n")] = '\0';

  int key_len = strlen(key);

  if (key_len == 0) {
    printf("Key cannot be empty.");
    fclose(input);
    return;
  }
  fgets(file_ext, sizeof(file_ext), input);
  file_ext[strcspn(file_ext, "\n")] = '\0';
  strcat(output_file_name, file_ext);
  output = fopen(output_file_name, "wb");
  if (output == NULL) {
    printf("Cant Create FIle");
    fclose(input);
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
  char file_ext[20];
  char file_name[300];
  printf("1.Encrypt");
  printf("\n2.decrypt");
  printf("\nEnter Opion: ");
  scanf("%d", &option);
  getchar();
  if (option == 1) {
    printf("Enter the file Name: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
    input = fopen(file_name, "rb");
    strcpy(file_ext, get_extention(file_name));
    char* dot = strrchr(file_name, '.');
    strcpy(dot, ".enc");
    output = fopen(file_name, "wb");
    if (input == NULL) {
      printf("Cant Open FIle");
      return 1;
    }
    if (output == NULL) {
      printf("Cant Create FIle");
      fclose(input);
      return 1;
    }

    encrypt(input, output, file_ext);

  }
  else if (option == 2) {
    printf("Enter The File Name : ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
    input = fopen(file_name, "rb");
    if (input == NULL) {
      printf("Cant Open FIle");
      return 1;
    }

    decrypt(input);
  }
  else {
    printf("Chose a valid option");

  }



  return 0;
}