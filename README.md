# 🔐 C File Encryption Tool

A beginner-friendly **file encryption and decryption tool written in C**.

This project uses a repeating-key **XOR operation** to encrypt file data. It works with different file types such as `.txt`, `.jpg`, `.mp4`, `.pdf`, and other binary files.

> **Note:** This project is created for learning purposes. The XOR encryption used here is **not cryptographically secure** and should not be used to protect sensitive data.

## 🚀 Features

- Encrypt files using a custom key
- Decrypt encrypted files using the same key
- Supports text and binary files
- Works with files such as:
  - `.txt`
  - `.jpg`
  - `.png`
  - `.mp4`
  - `.pdf`
  - `.zip`
  - and more

- Automatically changes the encrypted file extension to `.enc`
- Stores the original file extension inside the encrypted file
- Automatically restores the original extension during decryption
- Written entirely in C
- Uses standard C file handling

## 🛠️ Technologies

- C
- `stdio.h`
- `string.h`
- File I/O
- Pointers
- Strings
- XOR operations

## 📂 How It Works

The program reads the input file **byte by byte**.

For encryption, each byte is XORed with a character from the user's key:

```text
Encrypted Byte = Original Byte XOR Key Byte
```

The key is repeatedly used until the entire file has been processed.

For decryption, the same XOR operation is performed again:

```text
Original Byte = Encrypted Byte XOR Key Byte
```

This works because:

```text
A XOR B XOR B = A
```

## 🔄 Example

Suppose you have:

```text
photo.jpg
```

After encryption:

```text
photo.enc
```

The encrypted file contains the original extension:

```text
.jpg
```

When you decrypt it using the correct key:

```text
photo.enc
      ↓
decrypted.jpg
```

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/farhanahmedanik59/File-Encryptor-Decryptor-With-C
```

### 2. Enter the project directory

```bash
cd YOUR_REPOSITORY
```

### 3. Compile

Using GCC:

```bash
gcc main.c -o encryptor
```

### 4. Run

Windows:

```bash
encryptor.exe
```

Linux:

```bash
./encryptor
```

## 💻 Usage

The program provides two options:

```text
1.Encrypt
2.decrypt
Enter Option:
```

### Encrypt

Enter the file you want to encrypt:

```text
Enter the file Name: photo.jpg
Enter The Key: mypassword
```

The program creates:

```text
photo.enc
```

### Decrypt

Enter the encrypted file:

```text
Enter The File Name: photo.enc
Enter The Key: mypassword
```

The program creates:

```text
decrypted.jpg
```

## 📁 Project Structure

```text
C-File-Encryption/
│
├── main.c
├── README.md
└── .gitignore
```

## ⚠️ Security Warning

This project uses a simple repeating-key XOR algorithm.

It is useful for understanding:

- File handling
- Binary data
- XOR
- Encryption concepts
- C programming

However, it is **not secure encryption**.

Do not use this project to protect passwords, private documents, financial information, or other sensitive data.

For real-world encryption, use established cryptographic algorithms and libraries such as **AES** or **ChaCha20**.

## 🔮 Future Improvements

## 👨‍💻 Author

**Farhan Ahmed Anik**

Full-Stack MERN Developer & C Programming Learner

GitHub: `@farhanahmedanik59`

---

⭐ This project was built as a learning project to understand C, file handling, binary data, pointers, strings, and basic encryption concepts.
