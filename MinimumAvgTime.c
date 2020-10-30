//AUTHOR : HAMORA HADI

//HEAP!

/*

Tieu owns a pizza restaurant and he manages it in his own way. 
While in a normal restaurant, a customer is served by following the first-come, first-served rule, Tieu simply minimizes the average waiting time of his customers. 
So he gets to decide who is served first, regardless of how sooner or later a person comes. Different kinds of pizzas take different amounts of time to cook. 
Also, once he starts cooking a pizza, he cannot cook another pizza until the first pizza is completely cooked. 
Let's say we have three customers who come at time t=0, t=1, & t=2 respectively, and the time needed to cook their pizzas is 3, 9, & 6 respectively. 
If Tieu applies first-come, first-served rule, then the waiting time of three customers is 3, 11, & 16 respectively. 
The average waiting time in this case is (3 + 11 + 16) / 3 = 10. This is not an optimized solution. 
After serving the first customer at time t=3, Tieu can choose to serve the third customer. In that case, the waiting time will be 3, 7, & 17 respectively. 
Hence the average waiting time is (3 + 7 + 17) / 3 = 9. Help Tieu achieve the minimum average waiting time. 
For the sake of simplicity, just find the integer part of the minimum average waiting time.

-	The first line contains an integer N, which is the number of customers.
-	In the next N lines, the i(th) line contains two space separated numbers T(i) and L(i). 
	T(i) is the time when i(th) customer order a pizza, and L(i) is the time required to cook that pizza.
-	The i(th) customer is not the customer arriving at the i(th) arrival time.
-	Output will display the integer part of the minimum mean waiting time.
-	The waiting time is calculated as the difference between the time a customer orders pizza (the time at which they enter the shop) and the time she is served.
-	Cook does not know about the future orders.

**Input 0
3
0 3
1 9
2 6

**Output 0
9

**Input 1
3
0 3
1 9
2 5

**Output 1
8

# Explanation from output 1
->	Let's call the person ordering at time = 0 as A, time = 1 as B and time = 2 as C. 
	By delivering pizza for A, C and B we get the minimum average wait time to be

->	(3 + 6 + 16)/3 = 25/3 = 8.33 $$ Round it!
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int valueSort(const void* p1, const void* p2){
	unsigned long long int n1 = ((unsigned long long int*) p1)[1];
	unsigned long long int n2 = ((unsigned long long int*) p2)[1];
	if(n1 < n2){
		return -1;
	}
	if(n1 == n2){
		return 0;
	}
	else{
		return 1;
	}
}

int keySort(const void* p1, const void* p2){
	unsigned long long int n1 = ((unsigned long long int*) p1)[0];
	unsigned long long int n2 = ((unsigned long long int*) p2)[0];
	if(n1 < n2){
		return -1;
	}
	if(n1 == n2){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	unsigned int n;
	scanf("%u", &n);
	unsigned long long int* orders = malloc(sizeof(unsigned long long int) * n * 2);
	for(unsigned int i = 0; i < n; i++){
		scanf("%llu %llu", &orders[i * 2], &orders[i * 2 + 1]);
	}
	qsort(orders, n, sizeof(unsigned long long int) * 2, &keySort);
	unsigned long long int sumWaitingTime = 0;
	unsigned long long int timeElapsed = 0;
	int orderWindowStart = 0;
	int orderWindowEnd = -1;
	int newElems = 0;
	while(orderWindowStart < n){
		if(timeElapsed < orders[orderWindowStart * 2]){
			timeElapsed = orders[orderWindowStart * 2];
		}
		if(orderWindowEnd < orderWindowStart){
			while((orderWindowEnd + 1 < n) && (orders[(orderWindowEnd + 1) * 2] == orders[orderWindowStart * 2])){
				orderWindowEnd++;
				newElems = 1;
			}
		}
		while((orderWindowEnd + 1 < n) && (orders[(orderWindowEnd + 1) * 2] <= timeElapsed)){
			orderWindowEnd++;
			newElems = 1;
		}
		if(newElems){
			qsort(orders + orderWindowStart * 2, orderWindowEnd - orderWindowStart + 1, sizeof(unsigned long long int) * 2, &valueSort);
		}
		newElems = 0;

		unsigned long long int toAdd = timeElapsed - orders[orderWindowStart * 2] + orders[orderWindowStart * 2 + 1];
		sumWaitingTime += toAdd;
		timeElapsed += orders[orderWindowStart * 2 + 1];
		orderWindowStart++;
	}
	printf("%llu\n", sumWaitingTime / n);
	free(orders);
	return 0;

}
