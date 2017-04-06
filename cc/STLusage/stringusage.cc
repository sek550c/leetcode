#include<iostream>
#include<string> // to use STL string
#include<algorithm> // to use reverse


using namespace std;

int main()
{
	// 1. string
	// 1.1 init
	string str1("test string."); 	//constructor
	string str2(str1);				//copy
	string str3 = str1;
	string str4(str1, 5);			//only first 5 letters
	string str5(10, 'a');			//10 'a's NOTE: '' NOT ""
	//string str5(10, "a"); //this is wrong
	
	cout<<"str1: "<<str1<<endl;
	cout<<"str2: "<<str2<<endl;
	cout<<"str3: "<<str3<<endl;
	cout<<"str4: "<<str4<<endl;
	cout<<"str5: "<<str5<<endl;
	
	// 1.2 access
	cout<<endl<<"str[i] method"<<endl;
	for (size_t i = 0; i < str1.length(); i++)
	{
		cout<<"str["<<i<<"]:  "<<str1[i]<<endl;
	}
	
	cout<<endl<<"iterator method"<<endl;
	int pos = 0;
	for (string::const_iterator ite = str1.begin(); ite !=str1.end(); ite++) // OR use 'auto'
	{
		cout<<"str["<<pos++<<"]:  "<<*ite<<endl;
	}
	
	// 1.3 concatenate
	string str0 = "this is ";
	string retstr1 = str0 + str1; // +
	cout<<"(+ method)final string: "<<retstr1<<endl;
	
	string retstr2 = str0;
	retstr2.append(str1);
	cout<<"(append() method)final string: "<<retstr2<<endl; // append()
	
	// 1.4 search
	size_t charpos = retstr1.find("is"); // find() return position
	if (charpos != string::npos) // found
		cout<<"\"is\" found at position: "<<charpos<<endl; // NOTE: found the 'is' in 'this' NOT 'is'
	else // not found
		cout<<"\"is\" not found"<<endl;
	
	// find all substring 'a'
	cout<<"find all \'a\'"<<endl;
	string teststr = "fajkgihtlajdhfuhtoijeiuhqdiahigqpihgnnandk";
	size_t charpos2 = teststr.find("a", 0); // starting at position 0
	while (charpos2 != string::npos)
	{
		cout<<"\'a\' found at position: "<<charpos2<<endl;
		charpos2 = teststr.find("a", charpos2+1);
	}
	
	// 1.5 erase
	cout<<"original: "<<retstr1<<endl;
	retstr1.erase(7,5); // truncate/erase this will erase 5 characters from position 7
	// retstr1.erase(7) // means erase all characters after position 7, if you want to erase one character, use erase(7, 1)
	cout<<"truncated: "<<retstr1<<endl;
	
	// 1.6 reverse
	reverse(retstr1.begin(), retstr1.end());
	cout<<"reversed: "<<retstr1<<endl;
	
	/*// 1.7 uppercase/lowercase
	string teststr2 = "coNvErT THis sTRiNg";
	cout<<"original: "<<teststr2<<endl;
	transform(teststr2.begin(), teststr2.end(), teststr2.begin(), toupper);
	cout<<"uppercase: "<<teststr2<<endl;
	transform(teststr2.begin(), teststr2.end(), teststr2.begin(), tolower);
	cout<<"lowercase: "<<teststr2<<endl;
	*/
	return 0;
}
