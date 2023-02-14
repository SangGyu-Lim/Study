#ifndef __UTIL_H__
#define __UTIL_H__

#include "cocos2d.h"

USING_NS_CC;

namespace UTIL
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32

	static const std::string UTF8(const std::string& string)
	{
		int bufflen = MultiByteToWideChar(CP_ACP, 0, string.c_str(), -1, NULL, 0);
		WCHAR* widebuff = new WCHAR[bufflen + 1];
		memset(widebuff, 0, sizeof(WCHAR)* (bufflen + 1));
		MultiByteToWideChar(CP_ACP, 0, string.c_str(), -1, widebuff, bufflen);

		bufflen = WideCharToMultiByte(CP_UTF8, 0, widebuff, -1, NULL, 0, NULL, NULL);
		char* buff = new char[bufflen + 1];
		memset(buff, 0, sizeof(char)* (bufflen + 1));
		WideCharToMultiByte(CP_UTF8, 0, widebuff, -1, buff, bufflen, NULL, NULL);

		std::string strResult(buff);

		delete[] widebuff;
		delete[] buff;

		return strResult;
	}

#define UTF8PCHAR(string)    UTF8(string).c_str()

#else
	static const std::string UTF8(const std::string& string)
	{
		retrun string;
	}

#define UTF8(string)    string
#define UTF8PCHAR(string)    string

#endif
}

#endif // __UTIL_H__
