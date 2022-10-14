# Dynamic Programming Python implementation of Coin
# Change problem


def count(coins, n, sum):

	# table[i] will be storing the number of solutions for
	# value i. We need sum+1 rows as the table is constructed
	# in bottom up manner using the base case (sum = 0)
	# Initialize all table values as 0
	table = [0 for k in range(sum+1)]

	# Base case (If given value is 0)
	table[0] = 1

	# Pick all coins one by one and update the table[] values
	# after the index greater than or equal to the value of the
	# picked coin
	for i in range(0, n):
		for j in range(coins[i], sum+1):
			table[j] += table[j-coins[i]]

	return table[sum]


# Driver program to test above function
coins = [1, 2, 3]
n = len(coins)
sum = 4
x = count(coins, n, sum)
print(x)
