#pragma once
#include<iostream>

class StreamWriter {
public:
	StreamWriter(const char* filePath) {
		path = filePath;
	}

	void Close() {
		fclose(f);
	}

	void Erase() {
		Open("w");
		Close();
	}

	void Write(const char* content) {
		Open("w");
		fprintf(f, "%s", content);
		Close();
	}

	void WriteLine(const char* content) {
		Open("w");
		fprintf(f, "%s\n", content);
		Close();
	}

	void Append(const char* content) {
		Open("a");
		fprintf(f, "%s", content);
		Close();
	}

	void AppendLine(const char* content) {
		Open("a");
		fprintf(f, "%s\n", content);
		Close();
	}
private:
	const char* path;
	FILE* f;

	void Open(const char* mode) {
		int err = fopen_s(&f, path, mode);
	}
};

class StreamReader {
public:
	StreamReader(const char* filePath) {
		path = filePath;
	}

	void Close() {
		fclose(f);
	}

	std::string ReadAllFile() {
		std::string s = "";
		Open("r");
		while (!feof(f)) {
			fgets(buffer, 1025, f);
			s.append(buffer);
		}
		Close();
		return s;
	}

	std::string ReadLine(int idx) {
		int cnt = 0;
		Open("r");
		while (!feof(f) && cnt < idx) {
			fgets(buffer, 1025, f);
			cnt++;
		}
		return idx == cnt ? buffer : "";
	}
private:
	const char* path;
	char buffer[1024];
	FILE* f;

	void Open(const char* mode) {
		int err = fopen_s(&f, path, mode);
	}
};