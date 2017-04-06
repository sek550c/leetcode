#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:

    The given integer is guaranteed to fit within the range of a 32-bit signed integer.
    You could assume no leading zero bit in the integer’s binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

'''
import time

'''
example
n:       0101
i:       1000
i-1:     0111
n^(i-1): 0010 
'''

#xor with mask
def findComplement(num):
	mask = 1
	while mask <= num:
		mask = mask<<1
	return (mask-1)^num

def findComplement2(num):
	mask = num;
	# mask changes but not num
	mask |= mask >> 1; # 111
	mask |= mask >> 2;
	mask |= mask >> 4;
	mask |= mask >> 8;
	mask |= mask >> 16;
	return num^mask;

num = 5
time0 = time.clock()

print 'complement number: %d' %(findComplement(num))
time1 = time.clock()
print 'cost: %f s' % (time1-time0)

print 'complement number: %d' %(findComplement2(num))
time2 = time.clock()
print 'cost: %f s' % (time2-time1)
