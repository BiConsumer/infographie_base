#pragma once

#include <string>
#include <fstream>
#include <sstream>

namespace FileUtils {
	static inline std::string readFile(const std::string_view filepath) {
		std::ifstream ifs(filepath.data(), std::ifstream::in);

		if (!ifs.is_open())
			throw std::ios_base::failure("A file could not be opened");

		std::stringstream s;
		s << ifs.rdbuf();
		ifs.close();
		return s.str();
	}

	template<size_t N>
	static inline const std::array<std::string, N> readFiles(const std::array<std::string_view, N>& filepaths) {
		std::array<std::string, N> fileContents{};

		for (auto i = 0; i < N; ++i) {
			std::string currentFileCode = readFile(filepaths[i]);
			fileContents[i] = currentFileCode;
		}

		return fileContents;
	}
}