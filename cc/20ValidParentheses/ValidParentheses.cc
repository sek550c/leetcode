/* 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
	stack<char> stack;
    for (int i = 0; i < s.length(); i++) 
    {
        switch (s[i]) 
        {
            case '(':
                stack.push('(');
                break;
            case '{':
                stack.push('{');
                break;
            case '[':
                stack.push('[');
                break;
            case ')':
                if (stack.size() == 0 || (stack.top() != '('))
                    return false;
				stack.pop();
                break;
            case '}':
                if (stack.size() == 0 || (stack.top() != '{'))
					return false;
				stack.pop();
                break;
            case ']':
                if (stack.size() == 0 || (stack.top() != '['))
					return false;
				stack.pop();
                break;
        }
    }
    return stack.empty();
}

int main()
{
	string s = "(){{}[)]}";
	//string s = "(){}[]";
	if (isValid(s))
		cout<<"YES, it is valid!"<<endl;
	else
		cout<<"NO, it isn't valid!"<<endl;
	return 0;
}
