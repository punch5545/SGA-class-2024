#pragma once

namespace Util
{
	class FileSystems
	{
	public:
		FileSystems();
		~FileSystems();

		bool IsDir(std::wstring Path);
		bool HasChildDir(std::wstring Path);
		bool HasParentDir(std::wstring Path);

		std::wstring GetParentDir(std::wstring Path);
		
	public:
		static FileSystems Instance;

		std::map<int, std::wstring> Directories;
		std::map<int, std::wstring> Files;

		std::wstring RootDirectory;
	};
}