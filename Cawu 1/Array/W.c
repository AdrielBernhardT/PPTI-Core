#include <stdio.h> 

int main(){
	int Tc, batas; 
	scanf("%d", &Tc); 
	for(int i=0; i<Tc; i++){
		scanf("%d", &batas); 
		int angka[batas]; 
		for(int j=0; j<batas; j++){
			scanf("%d", &angka[j]); 
		}
		
		int cool_factor=0; 
		
		for(int j=0; j<batas; j++){
			int found=0; 
			for(int k=0; k<batas; k++){
				for(int l=0; l<batas; l++){
					if(k!=l && angka[j]==angka[k]+angka[l]){
						found=1; 
						break; 
					}
				}
				if(found){
					break; 
				}
			}
			if(found){
				cool_factor++; 
			}
		}
		printf("Case #%d: %d\n", i+1, cool_factor); 
	}
}