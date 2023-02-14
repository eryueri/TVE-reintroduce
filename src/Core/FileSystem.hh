#pragma once

#include "pch.hh"

namespace TVE {

	class FileSystem {
	public:
		static bool exists(std::filesystem::path p);
		static bool isDirectory(std::filesystem::path p);
	};

	class FileSystemEntity {
	public:
		FileSystemEntity() = delete;
		FileSystemEntity(std::string path);
		~FileSystemEntity() = default;

		bool isOpen();
		bool open();
		void close();
	private:
		std::filesystem::path _path = nullptr;
	};

}