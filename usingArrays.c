#include <stdio.h>
#include <stdlib.h>

//declaring the original matrix size
#define n 3
#define m 2

int main() {

  int matrix[n][m];
  int nonZeroes = 0;
  int sparse = 0;

  //setting up the matrix
  printf("Enter elements to the matrix:\n");
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      printf("Element %d-%d: ", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
    printf("\n");
  }

  //finding number of zeros in the matrix
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (matrix[i][j] != 0) {
        nonZeroes++;
      }
    }
  }

  //determining whether its a sparse matrix or not
  int totalElements = n * m;
  int zeroes = totalElements - nonZeroes;
  if (zeroes > totalElements/2) {
    sparse = 1;
  } else {
    sparse = 0;
  }

  int compactMatrix[nonZeroes][3];
  //making a new matrix if it is sparse
  if (sparse == 1) {
    int k = 0;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (matrix[i][j] != 0) {
          compactMatrix[k][0] = i;
          compactMatrix[k][1] = j;
          compactMatrix[k][2] = matrix[i][j];
          k++;
        } else {
          continue;
        }
      }
    }
  }

  //representing the final matrix
  if (sparse == 0) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  } else if (sparse == 1) {
    printf("Row\tColumn\t  Value\n");
    for (int i=0;i<nonZeroes;i++) {
      for (int j=0;j<3;j++) {
        printf("%d\t  ", compactMatrix[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
