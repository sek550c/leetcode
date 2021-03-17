#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# decorator
def start_finish(f):
    def new_f(*args, **kwargs):
        print("%s starting..."%(f.__name__))
        f(*args, **kwargs)
        print("%s finished."%(f.__name__))
    return new_f

### 1,167 twoSum ###
def twoSum_hash_my(nums, target):
	hash = {} # store element:index
	for i,n in enumerate(nums):
		if target-n in hash: # found
			return [i, hash[target-n]]
		else: # not found, store
			hash[n] = i
	return []
				
def twoSum_pointer(nums, target):
	low, high = 0, len(nums)-1
	while low < high:
		res = nums[low]+nums[high]
		if res == target:
			return [low, high]
		elif res > target:
			high = high-1
		else:
			low = low+1
	return []
	
@start_finish
def twoSumMain():	
	nums = [2, 7, 11, 15]
	target = 13
	print("index:%s"%(twoSum_hash_my(nums, target)))
	print("index:%s"%(twoSum_pointer(nums, target)))
	
####################################################

### 118 YangHui Triangle ###
def getYanghuiNum(row,col):
	if row == col or col == 1: return 1
	else: return getYanghuiNum_my(row-1, col-1)+getYanghuiNum_my(row-1, col)

def yanghuiTriRecursive(numRow):
	res = []
	for r in xrange(1,numRow+1):
		row = []
		for c in xrange(1, r+1):
			row += [getYanghuiNum_my(r, c)]
		res.append(row)
	return res

def yanghuiTri(numRow):
	pascal = [[1]*(i+1) for i in xrange(numRow)]
        for i in xrange(2, numRow):
            for j in xrange(1,i):
                pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j]
        return pascal

def yanghuiTri_map(numRow):
	res = [[1]]
	for r in xrange(1,numRow):
		res += [map(lambda x,y:x+y, res[-1]+[0], [0]+res[-1])] 
	return res[:numRow] # in case numRow=0 
	
@start_finish
def yanghuiTriMain():
	numRow = 5
	print("list aadd: %s"%([1]+[2]))
	l1 = [1]
	l1.append(2)
	print("list append: %s"%(l1))
	print("YangHui Triangle recursive: %s"%(yanghuiTriRe_my(numRow)))
	print("YangHui Triangle: %s"%(yanghuiTri(numRow)))
####################################################

### 27 remove element ###
def removeElement(nums, val):
	new_i = 0
	for i in xrange(len(nums)):
		if nums[i] != val:
			nums[new_i] = nums[i]
			new_i += 1
	return new_i
	
@start_finish
def removeElementMain():
	nums = [3, 2, 2, 3]
	val = 3
	print("new array:")
	print(nums[:removeElement(nums, val)])
####################################################

### 26 remove duplicated element ###
def removeDupElement(nums):
	if len(nums) < 2: return 1
	new_i = 1
	for i in xrange(1,len(nums)):
		if nums[i] != nums[i-1]:
			nums[new_i] = nums[i]
			new_i += 1
		
	return new_i
	
@start_finish
def removeDupElementMain():
	nums = [0, 1, 2, 2, 3, 3, 3, 4]
	print("new array:")
	print(nums[:removeDupElement(nums)])
####################################################

### 35 search insert ###
def searchInsert(nums, target):
	for idx, n in enumerate(nums):
		if n >= target:
			return idx
	return len(nums)

@start_finish
def searchInsertMain():
	nums = [1, 3, 5, 6]
	print(nums)
	target = 0
	print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
	target = 2
	print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
	target = 3
	print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
	target = 7
	print("target: %s, insert index: %s"%(target, searchInsert(nums, target)))
####################################################
"""

"""
if __name__ == '__main__':
	#twoSumMain()
	# yanghuiTriMain()
	#removeElementMain()
	# removeDupElementMain()
	searchInsertMain()	