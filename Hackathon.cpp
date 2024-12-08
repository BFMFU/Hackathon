#include<stdio.h>
#include<math.h>
int main(){
	int arr[100];
	int n,choice;
	do{
	printf("\n MENU \n");
	printf("1. Nhap so luong va gia tri cho cac phan tu\n");
	printf("2. In mang(arr[0]=...,arr[1]=...,)\n");
	printf("3. Dem so luong so hoan hao\n");
	printf("4. Dem so luong so nguyen to\n");
	printf("5. Tim gia tri lon thu hai\n");
	printf("6. Tim gia tri nho thu hai\n");
	printf("7. Them phan tu tai vi tri\n");
	printf("8. Xoa phan tu tai vi tri\n");
	printf("9. Sap xep mang tang dan (sap xep chen)\n");
	printf("10. Sap xep mang giam dan (sap xep chen)\n");
	printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
	printf("12. Xoa phan tu trung lap va in ra phan tu doc nhat\n");
	printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
	printf("14. Dao nguoc mang\n");
	printf("15. Thoat.\n");
	printf("Lua chon cua ban: ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :{
			do{
				printf("Nhap so luong gia tri cho mang: ");
				scanf("%d",&n);
			} while(n<0);
			for( int i=0;i<n;i++){
				printf("Nhap gia tri cho phan tu arr[%d]= ",i);
				scanf("%d",&arr[i]);
			}
			break;
		}
		case 2:{
			printf("Mang da nhap gom co: ");
			for(int i=0;i<n;i++){
				printf("arr[%d]=%d ",i,arr[i]);
			}
			break;
		}
		case 3:{
			int count=0;		
    		for (int i=0;i<n;i++) {
        	int sum = 0;
        		for (int j=1;j<=arr[i]/2;j++) {
            		if (arr[i]%j==0) {
            	    	sum+=j;
            		}
        		}
        		if(sum == arr[i]){
            		count++;
        		}
    		}
    		printf("So luong so hoan hao co: %d",count);
			break;
		}
		case 4:{
			int count=0;
			for (int i = 0; i < n; i++) {
        		int numb = arr[i];
        		if (numb < 2) {
            	continue; 
        		}
        		int element = 1; 
        		for (int j = 2; j <= sqrt(numb); j++) {
            		if (numb%j==0){
                	element = 0;
                	break;
            		}
        		}
        		if(element){
            	count+=1;
        		}
    		}	printf("So luong so nguyen to la: %d",count);
			break;
		}
		case 5:{
			int firstMin=arr[0];			
			int secondMin;
			for(int i=1;i<n;i++){
				if(arr[i]<firstMin){
					secondMin=firstMin;
					firstMin=arr[i];
				} else if (arr[i]<secondMin){
					secondMin=arr[i];
				}
			}
			printf("So nho thu 2 trong mang la: %d",secondMin);
			break;
		}
		case 6:{
			int firstMax=arr[0];
			int secondMax;
			for(int i=1;i<n;i++){
				if(arr[i]>firstMax){
					secondMax=firstMax;
					firstMax=arr[i];
				} else if(arr[i]>secondMax){
					secondMax=arr[i];
				}
			}
			printf("So lon thu 2 trong mang la: %d",secondMax);
			break;
		}
		case 7:{
			int pos, value;
			do{
				printf("Nhap vi tri  muon them: ");
				scanf("%d",&pos);
			} while(pos<0&&pos>n+1);
			printf("Nhap gia tri ma ban muon them: ");
			scanf("%d",&value);
			for(int i=n;i>=pos;i--){
				arr[i]=arr[i-1];
				} 
			arr[pos-1]=value;
			printf("Mang sau khi them la: ");
			for(int i=0;i<n+1;i++){
				printf("%d ",arr[i]);
				}
				++n;
			break;
		}
		case 8:{
			int pos;
			do{
				printf("Nhap vao vi tri phan tu ban muon xoa: ");
				scanf("%d",&pos);
			} while (pos>=n&&pos<0);
			for(int i=pos-1;i<n;i++){
				arr[i]=arr[i+1];
				}
			printf("Mang sau khi xoa gia tri la: ");
			for(int i=0; i<n-1;i++){
				printf("%d ",arr[i]);
			}
			--n;
			break;
		}
		case 9:{
			int key;
			for(int i=1;i<n;i++){
				key=arr[i];
				for(int j=i-1;j>=0&&arr[j]>key;j--){
					arr[j+1]=arr[j];
					arr[j]=key;
					}
				}
			printf("Mang da hoan doi la: ");
			for(int i=0;i<n;i++){
				printf("%d ",arr[i]);
			}
			break;
		}
		case 10:{
			int key;
			for(int i=1;i<n;i++){
				key=arr[i];
				for(int j=i-1;j>=0&&arr[j]<key;j--){
					arr[j+1]=arr[j];
					arr[j]=key;
					}
				}
			printf("Mang da hoan doi la: ");
			for(int i=0;i<n;i++){
				printf("%d ",arr[i]);
			}
			break;
		}
		case 11:{
			int target;
   			int low, high, mid, found = 0;
			printf("Nhap so can tim: ");
    		scanf("%d", &target);
    		low = 0;
    		high = n - 1;
    		while (low <= high) {
        		mid = (low + high) / 2;
        		if (arr[mid] == target) {
            		printf("Tim thay %d tai vi tri %d.\n", target, mid + 1);
            		found = 1;
            		break;
        		} else if (arr[mid] < target) {
            		low = mid + 1;
        		} else {
            		high = mid - 1;
        		}
    		}		
			break;
		}
		case 12:{
			int unique[n]; 
			int count = 0; 
    		for (int i = 0; i < n; i++) {
        		int dup = 0;
        		for (int j = 0; j < count; j++) {
            		if (arr[i] == unique[j]) {
                	dup=1;
                	break;
           			}
        		}
        		if (!dup) {
            	unique[count] = arr[i];
            	count++;
        		}
    		}
    		printf("Cac phan tu duy nhat trong mang la:\n");
    		for (int i = 0; i < count; i++) {
        		printf("%d ", unique[i]);
    		}
    		printf("\n");
			break;
		}
		case 13:{
			for (int i = 0; i < n - 1; i++) {
		        for (int j = i + 1; j < n; j++) {
		            if ((arr[i] % 2 != 0 && arr[j] % 2 == 0) || 
		                (arr[i] % 2 == arr[j] % 2 && arr[i] > arr[j])) {
		                int temp = arr[i];
		                arr[i] = arr[j];
		                arr[j] = temp;
		            }
		        }	
	    	}
	    	printf("Mang sau khi sap xep:\n");
	    	for (int i = 0; i < n; i++) {
	        	printf("%d ", arr[i]);
	    	}
	    	printf("\n");
			break;
		}
		case 14:{
			int j=n-1;
			for(int i=0;i<n/2;i++){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				--j;
			}
			printf("Mang sau khi da dao nguoc la: ");
			for(int i=0;i<n;i++){
				printf("arr[%d]=%d ",i,arr[i]);
			}
			break;
		}
	}
	} while(choice!=0);
	return 0;
}
