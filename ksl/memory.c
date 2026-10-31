/**
@file
@author Kristopher Wehage
@date 2016
@copyright Kristopher Wehage 2016
@section DESCRIPTION
This file includes utility routines to dynamically allocate and free memory for
two dimensional arrays

@remark
THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
*/

#include "ksl/memory.h"

double** ksl_array2D_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  double** pRow = malloc(rows * sizeof(double*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(double));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2D_free(double** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
}

float** ksl_array2Df_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  float** pRow = malloc(rows * sizeof(float*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(float));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2Df_free(float** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
}

int** ksl_array2Di_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  int** pRow = malloc(rows * sizeof(int*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(int));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2Di_free(int** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
  x = NULL;
}

unsigned int** ksl_array2Dui_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  unsigned int** pRow = malloc(rows * sizeof(unsigned int*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(unsigned int));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2Dui_free(unsigned int** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
}

char** ksl_array2Dc_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  char** pRow = malloc(rows * sizeof(char*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(char));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2Dc_free(char** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
}

bool** ksl_array2Db_alloc(int rows, int columns) {
  if(rows <= 0) {
    return NULL;
  }
  bool** pRow = malloc(rows * sizeof(bool*));
  if(pRow == NULL) {
    fprintf(stderr, "Error: could not allocate array [%d][%d]\n", rows,
            columns);
    return NULL;
  }
  pRow[0] = calloc(rows * columns, sizeof(bool));
  if(pRow[0] == NULL) {
    fprintf(stderr, "Error: could not allocate array\n");
    return NULL;
  }
  for(int i = 1; i < rows; i++) {
    pRow[i] = pRow[0] + i * columns;
  }
  return pRow;
}

void ksl_array2Db_free(bool** x) {
  if(x == NULL) {
    return;
  }
  free(x[0]);
  free(x);
}

void ksl_array_free(double* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}

void ksl_arrayf_free(float* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}

void ksl_arrayi_free(int* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}

void ksl_arrayui_free(unsigned int* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}

void ksl_arrayc_free(char* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}

void ksl_arrayb_free(bool* x) {
  if(x == NULL) {
    return;
  }
  free(x);
  x = NULL;
}
