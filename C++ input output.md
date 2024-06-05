# Standard File I/O Library in C++

The C++ Standard Library provides several classes and functions to perform file input and output operations. These are part of the `<fstream>` header, which provides facilities to create, read, write, and manipulate files.

## Overview of `<fstream>` Header

The `<fstream>` header includes the following classes for file I/O operations:

1. **`std::ifstream`**: Stream class to read from files.
2. **`std::ofstream`**: Stream class to write to files.
3. **`std::fstream`**: Stream class to both read from and write to files.

These classes are derived from `std::istream`, `std::ostream`, and `std::iostream`, respectively, which are in turn derived from `std::ios`.

## Basic Classes and Their Usage

### `std::ifstream` (Input File Stream)

The `std::ifstream` class is used to read data from files. It inherits from `std::istream`.

#### Example:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("example.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return 0;
}
```

### `std::ofstream` (Output File Stream)

The `std::ofstream` class is used to write data to files. It inherits from `std::ostream`.

#### Example:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("example.txt");
    if (!outputFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    outputFile << "This is a line.\n";
    outputFile << "This is another line.\n";

    outputFile.close();
    return 0;
}
```

### `std::fstream` (File Stream)

The `std::fstream` class is used for both reading from and writing to files. It inherits from `std::iostream`.

#### Example:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file) {
        std::cerr << "Unable to open file";
        return 1;
    }

    file << "Appending a new line.\n";

    file.seekg(0); // Move the read position to the beginning of the file
    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}
```

## File Opening Modes

When opening a file, you can specify the mode using `std::ios` flags:

- `std::ios::in`: Open for reading.
- `std::ios::out`: Open for writing.
- `std::ios::binary`: Open in binary mode.
- `std::ios::ate`: Seek to the end of the file upon opening.
- `std::ios::app`: Append to the end of the file.
- `std::ios::trunc`: Truncate the file if it already exists.

You can combine these flags using the bitwise OR operator (`|`).

#### Example:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("example.txt", std::ios::out | std::ios::trunc);
    if (!outputFile) {
        std::cerr << "Unable to open file";
        return 1;
    }

    outputFile << "This will overwrite the file.\n";

    outputFile.close();
    return 0;
}
```

## Checking File State

After performing file operations, it is often necessary to check the state of the file stream using the following member functions:

- `ifstream::is_open()`: Checks if the file stream is open.
- `ifstream::good()`: Checks if the stream is in a good state.
- `ifstream::eof()`: Checks if the end of file has been reached.
- `ifstream::fail()`: Checks if a logical error has occurred.
- `ifstream::bad()`: Checks if a read/write error has occurred.

#### Example:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("example.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }

    if (inputFile.good()) {
        std::cout << "File is good for I/O operations" << std::endl;
    }

    std::string line;
    while (getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    if (inputFile.eof()) {
        std::cout << "End of file reached" << std::endl;
    }

    inputFile.close();
    return 0;
}
```

## Reading and Writing Binary Files

For binary file operations, use the `std::ios::binary` flag when opening the file and use `read` and `write` member functions.

#### Example:

```cpp
#include <iostream>
#include <fstream>

struct Data {
    int id;
    char name[20];
};

int main() {
    // Writing binary data
    Data writeData = {1, "Test"};
    std::ofstream outputFile("example.bin", std::ios::binary);
    outputFile.write(reinterpret_cast<char*>(&writeData), sizeof(writeData));
    outputFile.close();

    // Reading binary data
    Data readData;
    std::ifstream inputFile("example.bin", std::ios::binary);
    inputFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));
    inputFile.close();

    std::cout << "ID: " << readData.id << ", Name: " << readData.name << std::endl;

    return 0;
}
```
