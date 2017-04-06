#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

'''
import time

def getNum(row, col):
	if row == col or col == 1: return 1
	else: return getNum(row-1, col-1) + getNum(row-1, col)

def generate(numRows):
	tri = []
	for row in xrange(1, numRows+1):
		for col in xrange(1, row+1):
			#print row, col
			tri.append(getNum(row, col))
		tri += tri
	return tri

#Any row can be constructed using the offset sum of the previous row. Example:
#     1 3 3 1 0 (previous row)
#  +  0 1 3 3 1
#  =  1 4 6 4 1	(next row)
def generate2(numRows):
        res = [[1]]
        for i in range(1, numRows):
            res += [map(lambda x, y: x+y, res[-1] + [0], [0] + res[-1])] # map compute (see map and lambda)
        return res[:numRows] # in case numRows = 0

Row = 5
print generate2(Row)
	

