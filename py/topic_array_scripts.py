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
	print("%s remove element %s: %s"%(nums, val, nums[:removeElement(nums, val)]))
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
	print(nums[:removeDupElement(nums)])
	print("%s remove duplicated element: %s"%(nums, nums[:removeDupElement(nums)]))

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

### 53 max subarray ###
def maxSubArray(nums):
	local_max = nums[0]
	global_max = nums[0]
	for n in nums[1:]:
		local_max = max(n, local_max+n)
		global_max = max(local_max, global_max)
	return global_max

@start_finish
def maxSubArrayMain():
	nums = [-2,1,-3,4,-1,2,1,-5,4]
	print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
	nums = [5,4,-1,7,8]
	print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
	nums = [1]
	print("%s has the largest sum: %s"%(nums, maxSubArray(nums)))
####################################################

### 66 plus one ###
def plusOne(nums):
	for i in xrange(len(nums)-1, -1, -1):
		if nums[i] == 9:
			nums[i] = 0
		else:
			nums[i] += 1
			return nums
	nums.append(0)
	nums[0] = 1
	return nums

def plusOne2(nums):
	total = nums[0]
	for n in nums[1:]:
		total = 10*total+n
	return [int(i) for i in str(total+1)]

@start_finish
def plusOneMain():
	fun = plusOne2
	nums = [1,2,3]
	print(nums)
	print("plus one: %s"%(fun(nums)))
	nums = [0]
	print(nums)
	print("plus one: %s"%(fun(nums)))
	nums = [1,9,9]
	print(nums)
	print("plus one: %s"%(fun(nums)))
	nums = [9,9,9]
	print(nums)
	print("plus one: %s"%(fun(nums)))

####################################################

### 67 add binary ###
def addBinaryDecimal(a, b):
	if a == "0" or a == "": return b
	if b == "0" or b == "": return a
	return bin(int(a,2)+int(b,2))[2:]

def addBinary(a, b):
	if a == "0" or a == "": return b
	if b == "0" or b == "": return a
	if len(a) < len(b):
		a = "0"*(len(b)-len(a))+a
	if len(b) < len(a):
		b = "0"*(len(a)-len(b))+b
	# print(a,b)
	i,j = len(a)-1, len(b)-1
	carry = 0
	res = ""
	while i >= 0 and j >= 0:
		# print(i,j)
		tmp = str((int(a[i])+int(b[j])+carry)%2)
		# print tmp
		res = tmp+res
		# print(res)
		carry = (int(a[i])+int(b[j])+carry)/2
		i = i-1
		j = j-1
	if carry > 0: return "1"+res
	else: return res

@start_finish
def addBinaryMain():
	fun = addBinaryDecimal
	fun2 = addBinary
	a = "111"
	b = ""
	print(a)
	print(b)
	print("add binary using decimal: %s"%(fun(a, b)))
	print("add binary using force-brute: %s"%(fun2(a, b)))

####################################################
### 83 delete duplicates ###
"""
Given the head of a sorted linked list, delete all duplicates 
such that each element appears only once. Return the linked 
list sorted as well.
"""
#TODO
def deleteDulicates(head):
	for i, n in enumerate(head):
		pass



def deleteDulicates2(head):
	pass



@start_finish
def deleteDulicatesMain():
	fun = deleteDulicates
	# fun2 = addBinary
	nums = [0,1,2,3,3]
	# b = ""
	print(a)
	# print(b)
	print("delete dulicates: %s"%(fun(nums)))
	# print("add binary using force-brute: %s"%(fun2(a, b)))

####################################################
### 88 merge sorted array ###
"""
Given two sorted integer arrays nums1 and nums2, merge nums2 
into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m 
and n respectively. You may assume that nums1 has a size 
equal to m + n such that it has enough space to hold 
additional elements from nums2.

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]。
"""
def merge(nums1, m, nums2, n):
	mergesize = m+n-1
	j = 0
	# copy nums2 to nums1
	for i in xrange(m, mergesize+1):
		nums1[i] = nums2[j]
		j = j+1
	# print(nums1)
	nums1 = sorted(nums1)
	return nums1

def merge2(nums1, m, nums2, n):
	mergesize = m+n
	i, j = m-1, n-1
	new_i = mergesize-1
	while i >=0 and j >= 0:
		print(nums1[i],nums2[j])
		if nums1[i] <= nums2[j]:
			nums1[new_i] = nums2[j]
			new_i = new_i-1
			j = j-1
		else:
			nums1[new_i] = nums1[i]
			new_i = new_i-1
			i = i-1
	return nums1


@start_finish
def mergeMain():
	fun = merge
	fun2 = merge2
	nums1 = [1,1,7,0,0,0]
	m = 3
	nums2 = [2,5,6]
	n = 3
	print(nums1)
	print(nums2)
	print("merge: %s"%(fun(nums1, m, nums2, n)))
	print("merge2: %s"%(fun2(nums1, m, nums2, n)))
	# print("add binary using force-brute: %s"%(fun2(a, b)))

####################################################

####################################################
### 121 best time to sell and buy ###
"""
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share
of the stock), design an algorithm to find the maximum profit.
Input: [7,1,5,3,6,4]
Output: 5
"""
def maxProfit(price):
	minPrice = price[0]
	maxProfit = 0
	for s in price:
		minPrice = min(minPrice, s)
		maxProfit = max(maxProfit, s-minPrice)
	return maxProfit

@start_finish
def maxProfitMain():
	fun = maxProfit
	price = [6,5,5,4,3]
	print(price)
	print("max profile: %s"%(fun(price)))
	# print("merge2: %s"%(fun2(nums1, m, nums2, n)))
	# print("add binary using force-brute: %s"%(fun2(a, b)))

####################################################

### 122 best time to sell and buy 2 ###
"""
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you
like (i.e., buy one and sell one share of the stock multiple times).
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6),
profit = 6-3 = 3.
"""
def maxProfit122(price):
	profit = 0
	for i in xrange(len(price)-1):
		if price[i+1] > price[i]:
			profit = profit+price[i+1]-price[i]
	return profit


@start_finish
def maxProfit122Main():
	fun = maxProfit122
	price = [7,1,5,3,6,7]
	print(price)
	print("max profit: %s"%(fun(price)))
	# print("merge2: %s"%(fun2(nums1, m, nums2, n)))
	# print("add binary using force-brute: %s"%(fun2(a, b)))

####################################################
### 217 contains duplicates ###
"""
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should
return false if every element is distinct.
"""
def containsDup(nums):
	nums = sorted(nums)
	for i in xrange(len(nums)-1):
		if nums[i+1] == nums[i]:
			return True
	return False

def containsDup2(nums):
	hash_map = {}
	for n in nums:
		if n in hash_map:
			return True
		else:
			hash_map[n] = 1
	return False

def containsDup3(nums):
	# print(set(nums))
	# print(sum(set(nums)))
	if sum(nums) == sum(set(nums)):
		return False
	else:
		return True

@start_finish
def containsDupMain():
	nums = [7,1,5,5,6,4]
	print(nums)
	print("contains duplicates?: %s"%(containsDup(nums)))
	print("contains duplicates?: %s"%(containsDup2(nums)))
	print("contains duplicates?: %s"%(containsDup3(nums)))

####################################################


####################################################
### 219 contains duplicates 2 ###
"""
Given an array of integers and an integer k, find out whether there are two distinct indices i and j
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
"""
def containsNearbyDup(nums, k):
	hash_map = {}
	for i, n in enumerate(nums):
		if n in hash_map:
			if abs(i-hash_map[n]) <= k:
				return True
			else:
				hash_map[n] = i
		else:
			hash_map[n] = i
	return False


@start_finish
def containsNearbyDupMain():
	nums = [1,0,1,1]
	k = 1
	print(nums, k)
	print("contains nearby duplicates?: %s"%(containsNearbyDup(nums, k)))
	# print("contains duplicates?: %s"%(containsDup2(nums)))
	# print("contains duplicates?: %s"%(containsDup3(nums)))

####################################################
### 283 move zeros ###
"""
Given an array nums, write a function to move all 0's to the end of it while maintaining the
relative order of the non-zero elements.
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
"""
def moveZeros(nums):
	cur, zero = 0, 0
	while cur < len(nums):
		if nums[cur] != 0:
			if cur != zero:
				nums[cur], nums[zero] = nums[zero], nums[cur] # swap
				print(nums)
			zero = zero+1
		cur = cur+1
	return nums
	# return False


@start_finish
def moveZerosMain():
	nums = [1,2,0,3,0,12]
	# k = 1
	print(nums)
	print("move zeros: %s"%(moveZeros(nums)))
	# print("contains duplicates?: %s"%(containsDup2(nums)))
	# print("contains duplicates?: %s"%(containsDup3(nums)))

####################################################

"""
blabla
"""
if __name__ == '__main__':
	# twoSumMain()
	# yanghuiTriMain()
	# removeElementMain()
	# removeDupElementMain()
	# searchInsertMain()	
	# maxSubArrayMain()
	# plusOneMain()
	# addBinaryMain()
	# deleteDulicatesMain()
	# mergeMain()
	# maxProfitMain()
	# maxProfit122Main()
	# containsDupMain()
	# containsNearbyDupMain()
	moveZerosMain()