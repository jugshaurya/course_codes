#include<iostream>

using namespace std;

void hanoiTower(int num_disk, char source, char helper, char dest){
	if(num_disk==0){
		// cout<<"move "<<source<<" to "<<dest<<"."<<endl;
		return;
	}

	hanoiTower(num_disk-1, source, dest, helper);
	cout<<"move disk "<<num_disk<<" from "<<source<<" to "<<dest<<"."<<endl;
	hanoiTower(num_disk-1, helper, source, dest);
}
int main(){
	int n=2;//no. of disks
	hanoiTower(n, 'A', 'B', 'C');

	return 0;
}