#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int> coins, int n, int V) {
	vector<int> dp(V+1, INT_MAX);
	dp[0] = 0;
	
	for(int i = 1; i <= V; i++) {
		for(int j = 0; j < n; j++) {
			if(coins[j] <= i) {
				int sub_res = dp[i - coins[j]];
				if(sub_res != INT_MAX && sub_res + 1 < dp[i]) {
					dp[i] = sub_res + 1;
				}
			}
		}
	}
	
	return dp[V];
}

int main() {
	vector<int> coins = {1, 5, 10, 25};
	int n = coins.size();
	int V = 42;
	
	cout << "Cantidad minima de monedas necesarias para dar cambio: " << minCoins(coins, n, V) << endl;
	
	return 0;
}
