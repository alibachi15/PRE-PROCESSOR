# Custom Modular C Preprocessor

A lightweight, modular custom C preprocessor built in C that parses source files, handles header file inclusions, strips comments, and processes macros, generating an intermediate preprocessed file (`.i`).

---

##  Features

* **File Inclusion Handler**: Automatically detects `#include` directives (both system `<...>` and local `"..."` headers) and expands them into the target file.
* **Comment Removal**: Scans the intermediate file and safely strips out both single-line (`//`) and multi-line (`/* ... */`) comments in-place using file streams.
* **Macro Handler**: Implements a linked-list-based symbol table structure for parsing and managing `#define` directives *(Note: Currently under active development / incomplete)*.
* **Automated Pipeline**: Orchestrates the entire preprocessing sequence from a single command-line execution and outputs a clean `.i` preprocessed file.

---

## 📁 Project Structure

* `preprocessor_main.c`: Main driver program that handles arguments, reads source lines dynamically, and orchestrates the inclusion, comment removal, and macro handling pipeline.
* `file_inclusion.c`: Scans source code for include directives, opens respective header files (from `/usr/include/` or local paths), and writes them to the intermediate `.i` file.
* `comment_removal_file.c`: Handles in-place file stream modification using `fseek` and `fputc` to clear comments without breaking line alignments.
* `macro_handler.c`: Linked-list framework designed to parse `#define` directives and substitute macro expansions *(Work in Progress)*.
* `makefile_2`: Build configuration script for compiling individual object modules and generating the final `mypreprocessor` executable[cite: 14, 15, 16, 17, 18].

---

## 🛠️ Building & Running

### Prerequisites
Make sure you have a standard C compiler (`cc`/`gcc`) and `make` utility installed on your Unix/Linux environment.

### Compilation
Build the project executable using the provided Makefile:

```bash
make filename.c
