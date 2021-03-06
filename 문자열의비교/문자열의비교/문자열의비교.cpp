#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_LENGTH = 100000;

class MyString {
private:
	char *characters;
	int length;

public:
	MyString(const char *str)
	{
		this->length = strnlen(str, MAX_LENGTH); //문자열의 길이 알려줌
		this->characters = new char[this->length]; 
		for (int i = 0; i < this->length; i += 1)
			this->characters[i] = str[i];
	}
	MyString(const string & original)
	{
		this->length = original.length();
		this->characters = new char[this->length];
		for (int i = 0; i < this->length; i += 1)
			this->characters[i] = original[i];
	}
	~MyString()
	{
		delete[] characters;
	}

	bool operator < (const MyString & o) const {
		int n = min(this->length, o.length); //짧은 길이만큼 비교
		for (int i = 0; i < n; i++)
		{
			if (this->characters[i] < o.characters[i])
				return true;
			else if (this->characters[i] > o.characters[i])
				return false;
		}
		if (this->length < o.length) //앞이 다르고 길이가 동일할 경우
			return true;
		else return false;
	}
	bool operator > (const MyString & o) const {
		int n = min(this->length, o.length); //짧은 길이만큼 비교
		for (int i = 0; i < n; i++)
		{
			if (this->characters[i] < o.characters[i])
				return false;
			else if (this->characters[i] > o.characters[i])
				return true;
		}
		if (this->length < o.length) //앞이 동일하고 길이가 다를 경우
			return true;
		else return false;
	}
	bool operator == (const MyString & o) const { 
		if (this->length != o.length) //길이가 같지않은경우
			return false;//false 
		for (int i = 0; i < this->length; i++)
			if (this->characters[i] != o.characters[i]) //같은 위치의 값이 동일하지 않은경우 
				return false; //false 
		return true; //나머지는 true
	}


	};

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2; //s1과 s2에 값 입력

	MyString mys1(s1);
	MyString mys2(s2);

	if (mys1 < mys2)
		printf("-1");
	else if (mys1 > mys2)
		printf("1");
	else printf("0");
	return 0;
}