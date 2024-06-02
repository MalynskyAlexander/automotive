Стандартна бібліотека файлового вводу/виводу в C++ надає набір класів і функцій для роботи з файлами. 
Основні класи бібліотеки знаходяться в заголовку <fstream>, який включає класи для роботи з текстовими та двійковими файлами.

Основні класи файлового вводу/виводу
std::ifstream: Клас для читання з текстових файлів.
std::ofstream: Клас для запису в текстові файли.
std::fstream: Клас для читання та запису в текстові файли.
std::istringstream: Клас для читання з рядків (не з файлів).
std::ostringstream: Клас для запису в рядки (не в файли).
std::stringstream: Клас для читання та запису в рядки (не в файли).

Основні методи і функції

std::ifstream (Input File Stream)

Відкриття файлу
std::ifstream ifs("filename.txt");

або
std::ifstream ifs;
ifs.open("filename.txt");

Закриття файлу:
ifs.close();

Перевірка на успішне відкриття:
if (!ifs.is_open()) {
    std::cerr << "Failed to open file" << std::endl;
}

Читання даних:
std::string line;
while (std::getline(ifs, line)) {
    // Обробка прочитаної лінії
}

std::ofstream (Output File Stream)

Відкриття файлу:
std::ofstream ofs("filename.txt");

або
std::ofstream ofs;
ofs.open("filename.txt");

Закриття файлу:
ofs.close();

Запис даних:
ofs << "This is a line of text." << std::endl;

std::fstream (File Stream)

Відкриття файлу для читання і запису:
std::fstream fs("filename.txt", std::ios::in | std::ios::out);

або
std::fstream fs;
fs.open("filename.txt", std::ios::in | std::ios::out);

Закриття файлу:
fs.close();

Читання і запис даних:
fs << "This is a line of text." << std::endl;
std::string line;
fs.seekg(0); // Повернутися на початок файлу для читання
while (std::getline(fs, line)) {
    // Обробка прочитаної лінії
}

Додаткові налаштування і прапори
std::ios::in: Відкрити файл для читання.
std::ios::out: Відкрити файл для запису.
std::ios::binary: Відкрити файл в двійковому режимі.
std::ios::app: Відкрити файл в режимі додавання (append), щоб нові дані додавалися в кінець файлу.
std::ios::trunc: Якщо файл існує, його вміст буде видалено.
std::ios::ate: Відкрити файл і встановити позицію вказівника в кінець файлу.