/*

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
class Solution {
public:
	queue<int> formedNumbers;
    vector<bool> used;
    int numSquares(int n) {
       int biggestSqrt = (int)(sqrt(n)), lvl = 1, operations = 1;
       
       used.assign(n+1, false);
       formedNumbers.push(0);
       
       while(!formedNumbers.empty()){
       		for(int i=0;i<lvl;i++){
	       		int currentNumber = formedNumbers.front();
	       		formedNumbers.pop();
	       		
	       		for(int cube = 1; cube <= biggestSqrt; cube++){
	       			int newNumber = cube*cube + currentNumber;
	       			if(!used[newNumber]){
	       				used[newNumber] = true;
						formedNumbers.push(newNumber);
					}
					if(newNumber == n)return operations;
				}
			}
			operations++;
			lvl = formedNumbers.size();
			return 0;
	   }
    }
    
};
int main(){
	Solution a;
	cout<<a.numSquares(1000);
}
