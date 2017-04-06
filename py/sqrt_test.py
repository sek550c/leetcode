#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
implement sqrt function
'''
import math
import time

# https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method
def sqrt0(n):
	root = 1.0
	while abs(n - root*root) > 0.001:
		root = 0.5 * (root + n/root)
		#print root
	return root


num = 0.9
time0 = time.clock()
print 'standard sqrt(%f) = %f' %(num, math.sqrt(num))
time1 = time.clock()
print 'cost: %f s' % (time1 - time0)

print 'my func sqrt(%f) = %f' %(num, sqrt0(num))
time2 = time.clock()
print 'cost: %f s' % (time2 - time1)
	
