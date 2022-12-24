#include "sort.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int someBlock(int line, void (*f)(int *, int, int), int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = rand() % (1 << 31);
    f(mas, 0, line);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockRever(int line, void (*f)(int *, int, int), int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    for (int i = line; i >= 0; i--)
      mas[i] = i;
    f(mas, 0, line);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockFullSort(int line, void (*f)(int *, int, int), int begin,
                      int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = i;
    f(mas, 0, line);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlock10(int line, void (*f)(int *, int, int), int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = i;
    for (int i = 0; i < 5; i++) {
      int t = rand() % (line);
      swap(mas + t, mas + t + 1);
    }
    f(mas, 0, line);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockWithBuffer(int line, void (*f)(int *, int, int, int *), int begin,
                        int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    int *masBuff = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = rand() % (1 << 31);
    f(mas, 0, line, masBuff);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockWithBufferRever(int line, void (*f)(int *, int, int, int *),
                             int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    int *masBuff = (int *)malloc(line * sizeof(int));
    for (int i = line; i >= 0; i--)
      mas[i] = i;
    f(mas, 0, line, masBuff);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockWithBufferFullSort(int line, void (*f)(int *, int, int, int *),
                                int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    int *masBuff = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = i;
    f(mas, 0, line, masBuff);
    t2 = clock();
  }
  return t2 - t1;
}
int someBlockWithBuffer10(int line, void (*f)(int *, int, int, int *),
                          int begin, int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    int *masBuff = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = i;
    for (int i = 0; i < 5; i++) {
      int t = rand() % (line);
      swap(mas + t, mas + t + 1);
    }

    f(mas, 0, line, masBuff);
    t2 = clock();
  }
  return t2 - t1;
}

int someBlockWithCountSort(int line, void (*f)(int *, int, int, int), int begin,
                           int end) {
  time_t t1, t2;
  t1 = clock();
  t2 = clock();
  while (t2 - t1 < 5) {
    int *mas = (int *)malloc(line * sizeof(int));
    int *masBuff = (int *)malloc(line * sizeof(int));
    for (int i = 0; i < line; i++)
      mas[i] = rand() % (1 << 31);
    f(mas, 0, line, 1 << 31);
    t2 = clock();
  }
  return t2 - t1;
}

// int a1[10], a2[100], a3[100], a4[10000], a5[100000], a6[1000000],
// a7[10000000];

int a[8] = {1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7};

int main() {
  // printf("type            1    1e1    1e2    1e3    1e4    1e5    1e6
  // \tfullSort\treversed\twith10Inversions 1e7    fullSort    reversed
  // with10Inversions\n");
  printf("type\t\t\t1\t\t1e1\t\t1e2\t\t1e3\t\t1e4\t\t1e5\t\t1e6\t\t1e7\t\trever"
         "se\t\tFull Sort\t10 inver"
         "s\n");
  {
    printf("bubble_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 5) {
        int t = someBlock(a[i], bubble_sort_O, 0, a[i]);
        printf("\t\t%d", t);
      } else
        printf("\t\t%d  ", 0);
    }

    printf("\t\t%d  ", someBlockRever(1000, bubble_sort_O, 0, 1000));
    printf("\t\t%d ", someBlockFullSort(1000, bubble_sort_O, 0, 1000));
    printf("\t\t%d ", someBlock10(1000, bubble_sort_O, 0, 1000));

    printf("\n");
  }

  {
    printf("find_max_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 5) {
        int t = someBlock(a[i], find_max_sort, 0, a[i]);
        printf("\t\t%d", t);
      } else
        printf("\t\t%d", 0);
    }
    printf("\t\t%d  ", someBlockRever(1000, find_max_sort, 0, 1000));
    printf("\t\t%d  ", someBlockFullSort(1000, find_max_sort, 0, 1000));
    printf("\t\t%d  ", someBlock10(1000, find_max_sort, 0, 1000));

    printf("\n");
  }

  {
    printf("insert_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 5) {
        int t = someBlock(a[i], insert_sort, 0, a[i]);
        printf("\t\t%d", t);
      } else
        printf("\t\t%d", 0);
    }
    printf("\t\t%d  ", someBlockRever(1000, insert_sort, 0, 1000));
    printf("\t\t%d  ", someBlockFullSort(1000, insert_sort, 0, 1000));
    printf("\t\t%d  ", someBlock10(1000, insert_sort, 0, 1000));

    printf("\n");
  }

  {
    printf("quick_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 7) {
        int t = someBlock(a[i], quick_sort, 0, a[i]);
        printf("\t\t%d", t);
      } else
        printf("\t\t%d  ", 0);
    }

    printf("\t\t%d  ", someBlockRever(100000, quick_sort, 0, 100000));
    printf("\t\t%d  ", someBlockFullSort(100000, quick_sort, 0, 100000));
    printf("\t\t%d  ", someBlock10(1000, quick_sort, 0, 1000));

    printf("\n");
  }

  {
    printf("merge_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 7) {
        int t = someBlockWithBuffer(a[i], merge_sort, 0, a[i]);
        printf("\t\t%d  ", t);
      } else
        printf("\t%d  ", 0);
    }
    printf("\t\t%d  ", someBlockWithBufferRever(100000, merge_sort, 0, 100000));
    printf("\t\t%d",
           someBlockWithBufferFullSort(100000, merge_sort, 0, 100000));
    printf("\t\t%d", someBlockWithBuffer10(100000, merge_sort, 0, 100000));
    printf("\n");
  }

  {
    printf("heap_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 7) {
        int t = someBlock(a[i], heap_sort, 0, a[i]);
        printf("\t\t%d  ", t);
      } else {
        printf("\t%d  ", 0);
      }
    }

    printf("\t\t%d  ", someBlockRever(100000, heap_sort, 0, 100000));
    printf("\t\t%d", someBlockFullSort(10000, heap_sort, 0, 10000));
    printf("\t\t%d", someBlock10(10000, heap_sort, 0, 10000));
    printf("\n");
  }
  //
  //  {
  //    printf("count_sort");
  //    for (int i = 0; i < 7; i++) {
  //      int t = someBlockWithCountSort(a[i], count_sort, 0, a[i]);
  //      printf("\t%d  ", t);
  //    }
  //    printf("\n");
  //  }

  {
    printf("radix_sort");
    for (int i = 0; i < 8; i++) {
      if (i < 7) {
        int t = someBlock(a[i], radix_sort, 0, a[i]);
        printf("\t\t%d  ", t);
      } else
        printf("\t%d", 0);
    }
    printf("\t\t%d", someBlockRever(100000, radix_sort, 0, 10000));
    printf("\t\t%d", someBlockFullSort(100000, radix_sort, 0, 10000));
    printf("\t\t%d", someBlock10(10000, radix_sort, 0, 10000));
    printf("\n");
  }
}
