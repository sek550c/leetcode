/* 
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it? 
*/

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void showBinaryString(uint32_t n)
{
	bitset<32> x = bitset<32>(n); // convert to bitset
	string s = x.to_string<char, string::traits_type, string::allocator_type>(); // convert to string
	cout<<s<<endl;
}

/*
for 8 bit binary number abcdefgh, the process is as follow:
abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
*/
uint32_t reverseBits(uint32_t n) 
{
	n = (n >> 16) | (n << 16);
	// 11111111000000001111111100000000
	n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
	// 11110000111100001111000011110000
	n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
	// 11001100110011001100110011001100
	n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
	// 10101010101010101010101010101010
	n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
	return n;
}

uint32_t reverseBits2(uint32_t n) 
{
    string tmp="";
    for(int i=31;i>=0;i--) // run 32 times
    {
        tmp.push_back((n%2)+'0'); // store last bit into string
        n>>=1;
    }
    std::bitset<32> bVal(tmp);
    return bVal.to_ulong(); // convert string to int
}

uint32_t  reverseBits3(uint32_t n) 
{
	uint32_t result= 0;
	for(int i = 0; i < 32; i++)
		result = (result<<1) + (n>>i & 1); // move to left, add last bit. NOTE: move i bits to the right. OR use (n>>i)%2

	return result;
}

int main()
{
	uint32_t n = 9421;
	cout<<"origin:  ";
	showBinaryString(n);
	uint32_t rev = reverseBits3(n);
	cout<<"reverse: ";
	showBinaryString(rev);
	return 0;
}
