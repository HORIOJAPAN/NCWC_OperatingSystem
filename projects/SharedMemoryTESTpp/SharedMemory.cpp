#include "SharedMemory.h"

using namespace std;

template < typename T >
SharedMemory<T>::SharedMemory(const std::string FMNAME) :FILEMAPNAME(FMNAME)
{
	SharedMemory::getShMem();
}

template < typename T >
SharedMemory<T>::~SharedMemory()
{
	SharedMemory::releaseShMem();
}

template < typename T >
void SharedMemory<T>::getShMem()
{
	/*
	* CreateFileMappingは指定されたファイルに対する、
	* 名前付きまたは名前なしのファイルマッピングオブジェクトを作成または開きます。
	*
	* HANDLE CreateFileMapping(
	* HANDLE hFile,                       // ファイルのハンドル
	* LPSECURITY_ATTRIBUTES lpAttributes, // セキュリティ
	* DWORD flProtect,                    // 保護
	* DWORD dwMaximumSizeHigh,            // サイズを表す上位 DWORD
	* DWORD dwMaximumSizeLow,             // サイズを表す下位 DWORD
	* LPCTSTR lpName                      // オブジェクト名
	* );
	*
	* ref=>https://msdn.microsoft.com/ja-jp/library/Cc430039.aspx
	*/
	hShMem = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		1024,
		FILEMAPNAME);

	if (hShMem != NULL)
	{
		//bool isCreated = GetLastError() != ERROR_ALREADY_EXISTS;

		/*
		* MapViewOfFileは呼び出し側プロセスのアドレス空間に、ファイルのビューをマップします。
		*
		* LPVOID MapViewOfFile(
		* HANDLE hFileMappingObject,   // ファイルマッピングオブジェクトのハンドル
		* DWORD dwDesiredAccess,       // アクセスモード
		* DWORD dwFileOffsetHigh,      // オフセットの上位 DWORD
		* DWORD dwFileOffsetLow,       // オフセットの下位 DWORD
		* SIZE_T dwNumberOfBytesToMap  // マップ対象のバイト数
		* );
		*
		* ref=>https://msdn.microsoft.com/ja-jp/library/Cc430198.aspx
		*/
		datap = (T *)MapViewOfFile(
			hShMem,
			FILE_MAP_WRITE,
			0,
			0,
			0);
	}
}

template < typename T >
void SharedMemory<T>::releaseShMem()
{
	if (ghShMem != NULL)
	{
		if (datap != NULL)
			UnmapViewOfFile(datap);
		CloseHandle(hShMem);
		hShMem = NULL;
	}
}

template < typename T >
void SharedMemory<T>::setShMemData( T setData ,int offset)
{
	*(datap + offset ) = setData;
}

template < typename T >
T SharedMemory<T>::getShMemData(int offset)
{
	return *(datap + offset);
}
