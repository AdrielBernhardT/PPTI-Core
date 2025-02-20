#include <stdio.h>
int main(){
	int t,a[1005], n, max=0, counter=0;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		scanf("%d", &n);
		for(int j=0; j<n; j++)
		{
			scanf("%d", &a[j]);
			if(max<a[j]){
				max=a[j];
			}
		}
		for(int j=0; j<n;j++){
			if(a[j]==max){
				counter++;
			}
		}
		printf("Case #%d: %d\n", i, counter);
		max=0;
		counter=0;
	}
}