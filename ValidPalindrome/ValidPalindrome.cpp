// ValidPalindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	int l = 0;
	int r = s.length() - 1;

	while (r > l)
	{
		if (isalnum(s[l]) == false) l++;
		else if (isalnum(s[r]) == false) r--;
		else if (tolower(s[l++]) != tolower(s[r--]))
			return false;
	}

	return true;
}


int main()
{
	//string s = "A man, a plan, a canal: Panama";
	string s = ".,";

	bool result = isPalindrome(s);
	
    return 0;
}

