#Solution Hints1:

Array_Description:

dp[i][j] : - Number of ways till the index i with j as the number at that index.
Base case : if first is given as x dp[0][x]=1 else dp[0][u]=1 for all u

Pull from i: 1 to n-1 for all possible j

Answer: sum of all i :dp[n-1][i]


Book_Shop:

dp[i] : - Max Number of pages that can be bought with cost i.(Classic 0-1 Knapsack)
Base case : dp[x]=-INFINITY for all x

For all costs in array, pull from max_costs that already has an answer to the present max_cost.

Answer : dp[x]


