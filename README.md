# COMPILER-DESIGN-BASICS

*company name: CODETECH IT SOLUTIONS 
* NAME : AASHISH SAW
* INTERN ID : CITS0D398
* DOMAIN : C LANGUAGE
* DURATION : 4 WEEKS
* MENTOR : NEELA SANTOSH 
* DESCRIPTION :
  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  QUE1 : BUILD A SIMPLE LEXICAL ANALYZER
THAT IDENTIFIES KEYWORDS,
OPERATORS, AND IDENTIFIERS
FROM AN INPUT FILE.

  This project is a simple lexical analyzer written in the C programming language. Its primary objective is to read a source code file (input.txt), break the content into meaningful lexical units called tokens, and classify these tokens as keywords, identifiers, operators, numbers, or special characters. This process is an essential first step in the compilation of any programming language and forms the foundation of a compiler’s front end.

The lexical analyzer was developed using the C language due to its low-level capabilities, efficient memory handling, and close interaction with system-level functions such as file handling and character manipulation. The code uses standard C libraries like stdio.h, string.h, and ctype.h for input/output operations, string processing, and character classification. It was compiled using the GCC (GNU Compiler Collection) and tested on a Windows platform through the Code::Blocks IDE. Alternatively, it can be run on Linux systems or online compilers like OnlineGDB or JDoodle.

The key logic of the analyzer includes reading each character from the file, grouping characters into tokens based on syntax rules, and then applying conditions to identify the type of each token. Keywords are identified using a predefined array; operators and special symbols are matched character by character; and numeric literals are distinguished using digit checks.

This program is especially useful for educational purposes, helping students understand how compilers begin interpreting source code. It also serves as a stepping stone toward more complex compiler modules like syntax and semantic analyzers.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

QUE2 : DELIVERABLE: A PROGRAM
DEMONSTRATING LEXICAL ANALYSIS
WITH SAMPLE OUTPUTS.

his project demonstrates the implementation of a simple lexical analyzer using the C programming language. Lexical analysis is the first phase of a compiler, where the source code is scanned to break it into smaller meaningful units called tokens. These tokens are then categorized into various types such as keywords, identifiers, operators, numbers, and special characters.

The primary objective of this program is to simulate how a compiler identifies these tokens in source code. The lexical analyzer reads input from a text file (input.txt) containing C-like code. As it processes each character, it constructs strings and matches them against a list of keywords. If the word matches a known keyword, it is classified accordingly; otherwise, it is treated as an identifier or number depending on its structure. Operators such as +, -, =, and comparison symbols are also recognized and printed along with their type.

This program is written in standard C, using libraries such as stdio.h, string.h, and ctype.h. It was developed and tested on platforms like Code::Blocks and Visual Studio Code, using the GCC compiler. It is also compatible with Linux-based terminals and online C compilers such as JDoodle and OnlineGDB.

The purpose of this project is educational. It helps students understand how compilers begin processing code by scanning the input and recognizing its basic building blocks. While simple, this lexical analyzer provides the foundational concepts needed to understand more advanced topics like syntax analysis and code generation.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
