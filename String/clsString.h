#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class clsString
{

private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

#pragma region Length

	static short Length(string Value)
	{
		return Value.length();
	}

    short Length()
	{
		return _Value.length();
	}

#pragma endregion

#pragma region Set and Get Function

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

#pragma endregion

#pragma region Count Word Function

	static short CountWords(string Value, string Delim = " ")
	{
		short Counter = 0;
		short Pos = 0;
		string sWord;

		while ((Pos = Value.find(Delim)) != std::string::npos)
		{
			sWord = Value.substr(0, Pos);

			if (sWord != "")
			{
				Counter++;
			}
			Value.erase(0, (Pos + Delim.length()));
		}

		if (Value != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

#pragma endregion

#pragma region Upper First Letter Of Each Word Function

	static string UpperFirstLetterOfEachWord(string Value)
	{
		bool IsFirstLetter = true;
		for (char& C : Value)
		{
			if (C != ' ' && IsFirstLetter)
			{
				C = toupper(C);
			}

			IsFirstLetter = (C == ' ' ? true : false);
		}

		return Value;
	}

	void UpperFirstLetterOfEachWord()
	{// no need to return value , this function will directly update the object value 
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

#pragma endregion

#pragma region Lower First Letter Of Each Word Function

	static string LowerFirstLetterOfEachWord(string Value)
	{
		bool IsFirstLetter = true;
		for (char& C : Value)
		{
			if (C != ' ' && IsFirstLetter)
			{
				C = tolower(C);
			}

			IsFirstLetter = (C == ' ' ? true : false);
		}

		return Value;
	}

	void LowerFirstLetterOfEachWord()
	{// no need to return value , this function will directly update the object value 
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

#pragma endregion

#pragma region Upper All Letter Of String

	static string UpperAllString(string Value)
	{
		for (char& C : Value)
		{
			C = toupper(C);
		}

		return Value;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

#pragma endregion

#pragma region Lower All Letter Of String

	static string LowerAllString(string Value)
	{
		for (char& C : Value)
		{
			C = tolower(C);
		}

		return Value;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

#pragma endregion

#pragma region Invert Letter Case

	static char InvertCharacterCase(char Value)
	{
		return isupper(Value) ? tolower(Value) : toupper(Value);
	}

	static string InvertAllStringLetterCase(string Value)
	{
		for (char& C : Value)
		{
			C = InvertCharacterCase(C);
		}

		return Value;
	}

	void InvertAllStringLetterCase()
	{
		_Value = InvertAllStringLetterCase(_Value);
	}

#pragma endregion

#pragma region Count Small or Capital Letters

	enum enWhatToCount
	{
		SmallLetters = 0,
		CapitalLetters = 1,
		All = 2
	};

	static short CountLetters(string Value, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return Value.size();

		short Counter = 0;

		for (char& C : Value)
		{
			if (WhatToCount == enWhatToCount::SmallLetters && islower(C))
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(C))
			{
				Counter++;
			}
		}

		return Counter;
	}

	static short CountCapitalLetters(string Value)
	{

		short Counter = 0;

		for (short i = 0; i < Value.length(); i++)
		{

			if (isupper(Value[i]))
				Counter++;
		}

		return Counter;
	}

	short CountCpaitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Value)
	{

		short Counter = 0;

		for (short i = 0; i < Value.length(); i++)
		{

			if (islower(Value[i]))
				Counter++;
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string Value, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (char& C : Value)
		{
			if (MatchCase)
			{
				if (C == Letter)
					Counter++;
			}

			else
			{
				if (tolower(C) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

#pragma endregion

#pragma region Vowels Letters

	//static bool IsVowel(char Letter)
	//{
	//	char arr[] = {'a','e','i','o','u'};
	//	for (char& C : arr)
	//	{
	//		if (C == Letter)
	//		{
	//			return true;
	//		}
	//	}
	//	return false;
	//}

	//Another way
	static bool IsVowel(char C)
	{
		C = tolower(C);

		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'o') || (C == 'u'));
	}

	static short CountVowels(string Value)
	{
		short Counter = 0;

		for (char& C : Value)
		{
			if (IsVowel(C))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

#pragma endregion

#pragma region Split Function

	static vector<string> Split(string Value, string Delim)
	{
		vector<string>vString;
		short Pos = 0;
		string sWord;

		while ((Pos = Value.find(Delim)) != std::string::npos)
		{
			sWord = Value.substr(0, Pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			Value.erase(0, (Pos + Delim.length()));
		}

		if (Value != "")
		{
			vString.push_back(Value);
		}

		return vString;
	}

	vector<string>Split(string Delim)
	{
		return Split(_Value, Delim);
	}

#pragma endregion

#pragma region Trim Functions

	static string TrimLeft(string Value)
	{
		for (short i = 0; i < Value.length(); i++)
		{
			if (isspace(Value[i]) == 0)
			{
				return Value.substr(i, Value.length() - i);
			}
		}

		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Value)
	{
		for (short i = Value.length() - 1; i >= 0; i--)
		{
			if (isspace(Value[i]) == 0)
			{
				return Value.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Value)
	{
		return TrimLeft(TrimRight(Value));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

#pragma endregion

#pragma region Join Function

	static string JoinString(const vector<string>& vString, string Delim = " ")
	{
		string Value = "";

		for (const string& Word : vString)
		{
			Value += (Word + Delim);
		}

		return Value.substr(0, Value.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim = " ")
	{
		string Value = "";

		for (short i = 0; i < Length; i++)
		{
			Value += (arrString[i] + Delim);
		}

		return Value.substr(0, Value.length() - Delim.length());
	}

	static string ReverseWordInString(string Value)
	{
		/*vector<string>vString;
		string Result = "";
		vString = Split(Value, " ");

		for (short i =vString.size()-1;i>= 0;i--)
		{
			Result += (vString[i] + " ");
		}

		return Result.substr(0, Result.length() - 1);*/

		//Another Way of Solutioni
		/*vector<string>vString = Split(Value," ");
		reverse(vString.begin(), vString.end());

		return JoinString(vString, " ");*/

		//Another Way of Solutioni
		vector<string>vString;
		string Result = "";
		vString = Split(Value, " ");

		vector<string>::iterator iter = vString.end();
		for (short i = vString.size() - 1; i >= 0; i--)
		{
			iter--;
			Result += (*iter + " ");
		}

		return TrimRight(Result);
	}

	void  ReverseWordInString()
	{
		_Value = ReverseWordInString(_Value);
	}

	static string ReplaceWord(string Value, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string>vString = Split(Value, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}

		return JoinString(vString, " ");
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	static string RemovePunctuations(string Value)
	{
		string Result = "";
		for (char& C : Value)
		{
			if (!ispunct(C))
			{
				Result += C;
			}
		}

		return Result;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

#pragma endregion


};

