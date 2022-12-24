void bubble_sort_tetta(int * mas, int begin, int end);
void bubble_sort_O(int * mas, int begin, int end);
void find_max_sort(int * mas, int begin, int end);
int find_max(int * mas, int begin, int end);
void swap (int * x, int * y);
void insert (int * mas, int begin, int x);
void insert_sort(int * mas, int begin, int end);
void merge (int * mas1, int begin1, int end1,
			int * mas2, int begin2, int end2,
			int * buf);
void quick_sort(int * mas, int begin, int end);
void merge_sort(int *mas, int begin, int end, int * buf); 
void down_heap (int * mas, int cur, int end);
void up_heap (int * mas,  int cur);
void make_heap(int * mas, int begin, int end);
void heap_sort(int * mas, int begin, int end);
int binarysearch(int n, int mass[], int a);
void bad_count_sort(int * mas, int begin, int end, int max_val);
void count_sort(int * mas, int begin, int end, int max_val);
int f(int x);
extern const int pow_ten [10];
int i_number(int x, int i);
void radix_count_sort(int * mas, int begin, int end, int digit);
void radix_sort(int * mas, int begin, int end);