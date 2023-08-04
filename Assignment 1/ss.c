// Linear Search in C
#include <stdio.h>
int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = n;

  int result = -1;

  for (int i = 0; i < n; i++){
    if (array[i] == x){
      result = i;
      break;
    }
  }
  if(result == -1) printf("Element is not present in array");
  else printf("Element is present at index %d", result);
    
}