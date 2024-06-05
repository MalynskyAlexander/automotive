#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>

const std::size_t TOTAL_SIZE = 100 * 1024 * 1024; // 100 MB
const std::vector<std::size_t> BUFFER_SIZES = { 1 * 1024, 4 * 1024, 16 * 1024, 64 * 1024, 256 * 1024 };

void test_write_speed_text(const std::string& filename, std::size_t buffer_size, std::size_t total_size) {
	std::ofstream ofs(filename);
	if (!ofs) {
		std::cerr << "Error opening file for writing\n";
		return;
	}

	std::vector<char> buffer(buffer_size, 'a');
	auto start = std::chrono::high_resolution_clock::now();

	std::size_t written = 0;
	while (written < total_size) {
		ofs.write(buffer.data(), buffer.size());
		written += buffer.size();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Text file write with buffer size " << buffer_size << ": " << elapsed.count() << " seconds\n";

	ofs.close();
}

void test_write_speed_binary(const std::string& filename, std::size_t buffer_size, std::size_t total_size) {
	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs) {
		std::cerr << "Error opening file for writing\n";
		return;
	}

	std::vector<char> buffer(buffer_size, 'a');
	auto start = std::chrono::high_resolution_clock::now();

	std::size_t written = 0;
	while (written < total_size) {
		ofs.write(buffer.data(), buffer.size());
		written += buffer.size();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "Binary file write with buffer size " << buffer_size << ": " << elapsed.count() << " seconds\n";

	ofs.close();
}

int main() {
	double text_write_time = 0.0;
	double binary_write_time = 0.0;

	for (auto buffer_size : BUFFER_SIZES) {
		auto start = std::chrono::high_resolution_clock::now();
		test_write_speed_text("test_text.txt", buffer_size, TOTAL_SIZE);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> text_elapsed = end - start;
		text_write_time = text_elapsed.count();

		start = std::chrono::high_resolution_clock::now();
		test_write_speed_binary("test_binary.bin", buffer_size, TOTAL_SIZE);
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> binary_elapsed = end - start;
		binary_write_time = binary_elapsed.count();

		if (text_write_time < binary_write_time) {
			std::cout << "Text file write with buffer size " << buffer_size << " was faster by " << binary_write_time - text_write_time << " seconds.\n \n";
		}
		else if (binary_write_time < text_write_time) {
			std::cout << "Binary file write with buffer size " << buffer_size << " was faster by " << text_write_time - binary_write_time << " seconds.\n \n";
		}
		else {
			std::cout << "Text and binary file writes with buffer size " << buffer_size << " took the same amount of time.\n \n";
		}
	}

	std::cout << "Press Enter to continue...\n";
	std::cin.get();
	return 0;
}