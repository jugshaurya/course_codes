/*
	FIND THE GREATER ELEMENT
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + i and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.


Input Format:
First line contains the length of the array n. Second line contains the n space separated integers.

Output Format:
Print n space separated integers each representing the next greater element.

Sample Input:
3
1 2 3
Sample Output:
2 3 -1
Explanation:
Next greater element for 1 is 2, for 2 is 3 but not present for 3 therefore -1
*/

