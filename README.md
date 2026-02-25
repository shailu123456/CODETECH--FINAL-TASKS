# 💼 CODTECH Internship – C Programming Projects

This repository contains all the tasks completed during the C Programming Internship at CODTECH.  
The programs demonstrate practical implementation of file handling, data structures, compiler design basics, and data compression techniques using C language.

All programs are developed using a modular approach with proper commenting and structured coding practices.

---

## 👩‍💻 Intern Details

Name: Varthyavath Shailaja  
Organization: CODTECH  
Domain: C Programming  
Compiler Used: GCC  
Platform: Windows / Linux  

---

## 🚀 Internship Tasks

### 🔹 Task 1 – File Handling Program

Write a program to create, read, write, and append data to a file.  
Deliverable: A C program demonstrating various file operations.

Concepts Used:
- fopen()
- fclose()
- fprintf()
- fscanf()
- fgets()
- File modes (r, w, a)

Run:
```bash

```
gcc file_handling.c -o file
./file
🔹 Task 2 – Linked List Implementation
Create a program to implement a Singly Linked List with operations like insertion, deletion, and traversal.
Deliverable: A modular and efficient Linked List implementation.
Operations Implemented:
Insertion at Beginning
Insertion at End
Insertion at Position
Deletion at Beginning
Deletion at End
Deletion at Position
Displaying the List
Run:
Bash
Copy code
gcc linked_list.c -o list
./list
🔹 Task 3 – Compiler Design Basics (Lexical Analyzer)
Build a simple lexical analyzer that identifies keywords, identifiers, operators, numbers, and special symbols from an input file.
Deliverable: A program demonstrating lexical analysis with sample outputs.
Concepts Used:
File Handling
String Manipulation
Token Classification
Basic Compiler Design
Run:
Bash
Copy code
gcc lexical_analyzer.c -o lexer
./lexer
🔹 Task 4 – Data Compression Tool (Run-Length Encoding)
Write a program to implement a basic data compression algorithm like Run-Length Encoding (RLE).
Deliverable: A tool that compresses and decompresses text files.
Features:
Compresses repeated characters
Decompresses compressed text
Works with text files
Concepts Used:
File Handling
Algorithm Implementation
String Processing
Run:
Bash
Copy code
gcc rle.c -o rle
./rle
📂 Project Structure
Bash
Copy code
codtech-c-programming/
│
├── file_handling.c
├── linked_list.c
├── lexical_analyzer.c
├── rle.c
└── README.md
