#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	
	int k,i=0;
    double s=0.0000;
    cin>>k;
    while (s<=k)
    {
    	i++;
        s=s+ (1.0/i);
	}
    cout<<i;
	
	
	return 0;
}
