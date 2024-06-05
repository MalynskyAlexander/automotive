File Write Speed Test
======================

Overview
--------

This C++ code tests the write speed of text and binary files using different buffer sizes. It writes a fixed amount of data (100 MB) to both text and binary files using various buffer sizes and measures the time taken for each write operation. The code then compares the time taken for text and binary file writes for each buffer size and prints the results.

Includes
--------

The code includes the following libraries:
```c++
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
```
* `<fstream>` for file input/output operations.
* `<chrono>` for measuring time.
* `<vector>` for dynamic arrays.
* `<string>` for string operations.

Constants
---------

The code defines two constants:
```c++
const std::size_t TOTAL_SIZE = 100 * 1024 * 1024; // 100 MB
const std::vector<std::size_t> BUFFER_SIZES = { 1 * 1024, 4 * 1024, 16 * 1024, 64 * 1024, 256 * 1024 };
```
* `TOTAL_SIZE`: The total amount of data to write (100 MB).
* `BUFFER_SIZES`: A vector containing different buffer sizes to test (1 KB, 4 KB, 16 KB, 64 KB, and 256 KB).

Functions
---------

The code defines two functions:

### test\_write\_speed\_text
```c++
void test_write_speed_text(const std::string& filename, std::size_t buffer_size, std::size_t total_size)
```
This function tests the write speed of a text file using a specified buffer size. It takes three arguments:

* `filename`: The name of the text file to write.
* `buffer_size`: The buffer size to use for writing.
* `total_size`: The total amount of data to write.

The function opens the file, initializes a buffer with the specified buffer size, and writes data to the file in a loop until the total amount of data is written. It measures the time taken for the write operation and prints the result.

### test\_write\_speed\_binary
```c++
void test_write_speed_binary(const std::string& filename, std::size_t buffer_size, std::size_t total_size)
```
This function tests the write speed of a binary file using a specified buffer size. It takes the same arguments as `test_write_speed_text` and works similarly, except that it opens the file in binary mode.

Main Function
-------------

The `main` function tests the write speed of text and binary files using different buffer sizes and compares the results. It first initializes two variables to store the time taken for text and binary file writes:
```c++
double text_write_time = 0.0;
double binary_write_time = 0.0;
```
It then loops through the `BUFFER_SIZES` vector and tests the write speed of text and binary files using each buffer size:
```c++
for (auto buffer_size : BUFFER_SIZES) {
    // Test write speed of text file
    // Test write speed of binary file
    // Compare results
}
```
For each buffer size, the code measures the time taken for text and binary file writes and stores the results in `text_write_time` and `binary_write_time`, respectively. It then compares the results and prints the faster write operation and the time difference.

Finally, the code waits for the user to press Enter before exiting:
```c++
std::cout << "Press Enter to continue...\n";
std::cin.get();
return 0;
```
Test Results
-------------

|Buffer Size| Binary    | Text    |
| --------- | --------  | ------- |
|1	    | 0.678787  | 0.862236|
|4	    | 0.407661  | 0.745073|
|16	    | 0.0899549 | 0.482733|
|64	    | 0.0523468 | 0.602448|
|256    | 0.042735	| 0.76027 |
