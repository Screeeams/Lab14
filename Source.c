#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define N 100

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double find_min_after_k(double* ptr_array, int n, int k);
int homework(double* ptr_array, int n, int type);

int main() {
	setlocale(LC_ALL, "RUS");
	double array[N];
	int size;

	printf("Введите размер массива > ");
	scanf("%d", &size);

	if (size <= 0 || size > N) {
		puts("Некорректный размер массива");
		return 1;
	}

	full_elements(array, size);
	puts("\nИсходный массив:");
	put_elements(array, size);

	calc_elements(array, size);
	puts("\nПреобразованный массив:");
	put_elements(array, size);

	int begin, end;
	printf("\nВведите начальный и конечный индексы для суммы (begin end): ");
	scanf("%d %d", &begin, &end);
	if (begin >= 0 && end < size && begin <= end) {
		printf("Сумма элементов от %d до %d: %.2lf\n", begin, end, sum_elements(array, begin, end));
	}
	else {
		puts("Некорректный диапазон индексов");
	}

	double target;
	printf("\nВведите элемент для поиска: ");
	scanf("%lf", &target);
	int idx = find_element(array, size, target);
	if (idx != -1) {
		printf("Индекс найденного элемента: %d\n", idx);
	}
	else {
		puts("Элемент не найден (-1)");
	}

	int k;
	printf("\nВведите позицию K для поиска минимума после неё: ");
	scanf("%d", &k);
	if (k >= 0 && k < size - 1) {
		printf("Минимальное значение после позиции %d: %.2lf\n", k, find_min_after_k(array, size, k));
	}
	else {
		puts("Некорректная позиция K");
	}

	int type;
	printf("\nВведите параметр type для ДЗ (1 - первый знакопеременный, 0 - последний знакопеременный): ");
	scanf("%d", &type);
	int hw_idx = homework(array, size, type);
	if (hw_idx != -1) {
		printf("Индекс элемента перед сменой знака: %d\n", hw_idx);
	}
	else {
		puts("Смена знака не найдена (-1)");
	}

	return 0;
}

double* full_elements(double* ptr_array, int n) {
	double x = 0.1, step = 0.2;
	for (int i = 0; i < n; i++) {
		ptr_array[i] = x * x - 4 * sin(x);
		x += step;
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("array[%d] = %.2lf\n", i, ptr_array[i]);
	}
	return n;
}

double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] == 0) {
			ptr_array[i] = (double)(i + 1);
		}
	}
	return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end) {
	double sum = 0;
	for (int i = begin; i <= end; i++) {
		sum += ptr_array[i];
	}
	return sum;
}

int find_element(double* ptr_array, int n, double element) {
	for (int i = 0; i < n; i++) {
		if (fabs(ptr_array[i] - element) < 1e-5) {
			return i;
		}
	}
	return -1;
}

double find_min_after_k(double* ptr_array, int n, int k) {
	double min_val = ptr_array[k + 1];
	for (int i = k + 2; i < n; i++) {
		if (ptr_array[i] < min_val) {
			min_val = ptr_array[i];
		}
	}
	return min_val;
}

int homework(double* ptr_array, int n, int type) {
	int res = -1;
	for (int i = 0; i < n - 1; i++) {
		if ((ptr_array[i] > 0 && ptr_array[i + 1] < 0) || (ptr_array[i] < 0 && ptr_array[i + 1] > 0)) {
			if (type == 1) {
				return i;
			}
			res = i;
		}
	}
	return res;
}