#include "FileSystem.hh"

namespace TVE {
	
	bool FileSystem::exists(std::filesystem::path path)
	{
		return std::filesystem::exists(path);
	}
	
	bool FileSystem::isDirectory(std::filesystem::path path)
	{
		return std::filesystem::is_directory(path);
	}

	FileSystemEntity::FileSystemEntity(std::string path)
	{
		_path = std::filesystem::path(path);
	}

	bool FileSystemEntity::isExist()
	{
		return std::filesystem::exists(_path);
	}

	bool FileSystemEntity::isDirectory()
	{
		return std::filesystem::is_directory(_path);
	}

}