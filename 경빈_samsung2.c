#include <stdio.h>
#include <math.h>

int temp;

int decToBin(int temp){
   int binary[9] ={0,};
   int position =0, result=0;
   while (1){
      binary[position] = temp % 2;   
      temp = temp / 2;           
      position++;    
      if (temp == 0) {break;}                      
   }
   for (int i = position - 1; i >= 0; i--){
      result+= binary[i]*(pow(10,i));
   } 
   return result;
}

int binToResult(int binary, int x, int y){
   int result=0;
   for(int i=0; binary>0; i++){
      if(binary%10 ==1) {result+= y*(pow(10,i));}
      else {result+= x*(pow(10,i));}

      binary/=10;
   }
   return result;
}

int main(){
   int testCase;
   scanf("%d", &testCase);

   while(--testCase){      //testcase가 0이 될때까지
      int n, x, y, result =-1;
      
      scanf("%d %d %d", &n, &x, &y);   
      int cnt = 0;
      int temp = n ;
      while(temp>0){
         cnt++;
         temp/10;
      }
      int maxNum = pow(2, cnt) -1;
      for(int i=maxNum; i>0; i--){
         int binary = decToBin(maxNum);
         int result = binToResult(binary,x ,y)<n ?  binToResult(binary,x ,y): -1;
      }
      printf("%d",result);
      // return result;   
      return 0;
   }
}