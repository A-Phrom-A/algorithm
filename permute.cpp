#include <iostream>
using namespace std;
int num=0;
void swap (int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int x[], int S, int E){
	if(S == E){
       

        for (int i = 1; i < E; i++) {
            if ((x[i] == 1 && x[i + 1] == 2) || (x[i] == 2 && x[i + 1] == 1)) {
                num++;
                break; 
            }
        }
		
		return;
	}
	
	for(int i =S;i <= E;i++){
		swap(&x[S],&x[i]);
		permute(x,S + 1 ,E);
		swap(&x[S],&x[i]);
	}
}

int main() {
	int n =10;
	int x[] = {-1,1,2,3,4,5,6,7,8,9,10};
	
	permute(x, 1 ,n);
	cout << "-> : " ;
		cout << num;
		cout << "\n";
	return 0;
}
