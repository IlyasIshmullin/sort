#include "sort.h"
#include "stdio.h"
#include "stdlib.h"

void swap (int * x, int * y){
	int buf = *x;
	*x = *y;
	*y = buf;
	return;
}

void bubble_sort_tetta(int * mas, int begin, int end){ 
	for (int i = 0; i < end - begin; i++ )
		for (int j = begin; j< end - i - 1; j++)
			if (mas[j] > mas[j+1]) swap(mas+j,mas+j+1);		
}

void bubble_sort_O(int * mas, int begin, int end){ 
	for (int i = 0; i < end - begin; i++ ){
		int counter = 0;
		for (int j = begin; j< end - i - 1; j++)
			if (mas[j] > mas[j+1]) {
				swap(mas+j,mas+j+1);	
				++counter;
			}
		if (!counter) break;
	}
	return;
}

int find_max(int * mas, int begin, int end){
	int ind_max = begin;
	int cur_max = mas[begin];
	for (int i = begin+1; i<end; ++i){
		if (mas[i]>=cur_max){
			cur_max = mas[i];
			ind_max = i;
		}
	}
	return ind_max;
}

void find_max_sort(int * mas, int begin, int end){
	for (int i =0; i < end-begin; ++i){
		int ind_max = find_max(mas, begin, end - i);
		swap (mas+ind_max, mas+end-1-i);
	}
	return;
}

void insert (int * mas, int begin, int x){
	for (int i = x; i>= begin+1; --i){
		if (mas[i]>= mas[i-1]) return;
		swap(mas+i,mas+i-1);
	}
}

void insert_sort(int * mas, int begin, int end){
	for (int i = begin+1; i < end; ++i)
		insert (mas,begin, i);
}

void merge (int * mas1, int begin1, int end1,
			int * mas2, int begin2, int end2,
			int * buf)
{
	int i = begin1;
	int j = begin2;
	int n1 = end1 - begin1;
	int n2 = end2 - begin2;
	for (int k = 0; k < n1 + n2;++k ){
		int a = i < end1 ? mas1[i] : 1e9;
		int b = j < end2 ? mas2[j] : 1e9;
		if (a < b){
			buf[k] = a;
			++i;
		}
		else {
			buf[k] = b;
			++j;
		}
	}
	return;
}

void quick_sort(int * mas, int begin, int end){
	if (end - begin <= 1) return;
	int pivot = mas[(begin+end-1)/2];
	int i = begin, j = end-1;
	do{
		while (mas[i] < pivot) ++i;
		while (mas[j] > pivot) --j;
		if (i<=j) swap(mas+ i++,mas + j--);
	} while (i<=j);
	quick_sort(mas, begin, j+1);
	quick_sort(mas, i, end);
}


void merge_sort(int *mas, int begin, int end, int * buf){
	if (end - begin <= 1) return;
	int med = (begin+end-1)/2;
	merge_sort(mas, begin, med + 1, buf);
	merge_sort(mas, med+1, end, buf);
	merge(mas, begin, med+1, mas, med+1,end,buf);
	for (int i = begin ; i < end; ++i) mas[i] = buf[i-begin];
}

int l_son(int i) {return 2*i+1;}
int r_son(int i) {return 2*i+2;}
int parent(int i) {return (i-1)/2;}

void down_heap (int * mas, int cur, int end){
	if (l_son(cur)>= end) return;
	int l = mas[l_son(cur)];
	int r = r_son(cur)==end ? -1e9: mas[r_son(cur)];
	
	if (l>=r){
		if (mas[cur] < l) {
			swap(mas+cur, mas+l_son(cur));
			down_heap(mas,l_son(cur),end);
		}
	}
	else {
		if (mas[cur] < r) {
			swap(mas+cur, mas+r_son(cur));
			down_heap(mas,r_son(cur),end);
		}
	}
}

void up_heap (int * mas,  int cur){
	if (cur <=0) return;
	int p = parent(cur);
	if (mas[cur]>mas[p]) {
		swap(mas+cur,mas+p);
		up_heap(mas,p);
	}
}

void make_heap(int * mas, int begin, int end){
	//printf("%d %d %d \n",begin,end, (end+begin)/2);
	int k = (end+begin)/2;
	for (int i = k; i>= begin; --i) 
		down_heap(mas,i,end);
}

void heap_sort(int * mas, int begin, int end){
	make_heap(mas,begin,end);
	for (int i = end-1; i>= begin; --i){
		swap(mas+i,mas+begin);
		down_heap(mas,begin,i);
	}
	return;
}

int binarysearch(int n, int mass[], int a) {
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (a < mass[middle])
            high = middle - 1;
        else if (a > mass[middle])
            low = middle + 1;
        else 
            return middle;
    }
    return -1;
}

void bad_count_sort(int * mas, int begin, int end, int max_val){
	int * C = (int *)calloc(max_val+1,sizeof(int));
	for (int i =begin; i < end; ++i) C[mas[i]]++;
	int k=0;
	for (int i = 0 ; i<= max_val; ++i)
		for (int j = 0 ; j< C[i]; j++)
			mas[k++] = i;
	return;
}


void count_sort(int * mas, int begin, int end, int max_val){
	int * buf = (int *) malloc((end - begin)*sizeof(int));
	int * C = (int *)calloc(max_val+1,sizeof(int));
	for (int i = begin; i < end; ++i) C[mas[i]]++;
	int * D = C;
	for (int i =1; i <= max_val; ++i) D[i]+=D[i-1];
	for (int i = end-1; i>=begin; --i) 
		buf[--D[mas[i]]] = mas[i];
	for (int i = begin; i < end; ++i) mas[i] = buf[i-begin];
	free(buf);
	free(C);
	return;
}

int f(int x){
	int sum = 0;
	while (x) {
		sum += x%10;
		x/=10;
	}
	return sum;
}

const int pow_ten [10] = {1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9};

int i_number(int x, int i){
	return x/pow_ten[i]%10;
}

void radix_count_sort(int * mas, int begin, int end, int digit){
	int * buf = (int *) malloc((end - begin)*sizeof(int));
	int * C = (int *)calloc(10,sizeof(int));
	for (int i = begin; i < end; ++i) C[i_number(mas[i],digit)]++;
	int * D = C;
	for (int i =1; i <= 9; ++i) D[i]+=D[i-1];
	for (int i = end-1; i>=begin; --i) 
		buf[--D[i_number(mas[i],digit)]] = mas[i];
	for (int i = begin; i < end; ++i) mas[i] = buf[i-begin];
	free(buf);
	free(C);
	return;
}


void radix_sort(int * mas, int begin, int end){
	for (int i = 0; i < 10; ++i) 
		radix_count_sort(mas,begin,end,i);
	return;
}
