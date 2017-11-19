#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>



int s[26][26] =/* A B C D E F G H I J K L M N O P Q R S T U V W X Y Z */
{ { 4,-2, 0,-2,-1,-2, 0,-2,-1, 0,-1,-1,-1,-2, 0,-1,-1,-1, 1, 0, 0, 0,-3, 0,-2,-1 },
/* B */{ -2, 4,-3, 4, 1,-3,-1, 0,-3, 0, 0,-4,-3, 3, 0,-2, 0,-1, 0,-1, 0,-3,-4,-1,-3, 1 },
/* C */{ 0,-3, 9,-3,-4,-2,-3,-3,-1, 0,-3,-1,-1,-3, 0,-3,-3,-3,-1,-1, 0,-1,-2,-2,-2,-3 },
/* D */{ -2, 4,-3, 6, 2,-3,-1,-1,-3, 0,-1,-4,-3, 1, 0,-1, 0,-2, 0,-1, 0,-3,-4,-1,-3, 1 },
/* E */{ -1, 1,-4, 2, 5,-3,-2, 0,-3, 0, 1,-3,-2, 0, 0,-1, 2, 0, 0,-1, 0,-2,-3,-1,-2, 4 },
/* F */{ -2,-3,-2,-3,-3, 6,-3,-1, 0, 0,-3, 0, 0,-3, 0,-4,-3,-3,-2,-2, 0,-1, 1,-1, 3,-3 },
/* G */{ 0,-1,-3,-1,-2,-3, 6,-2,-4, 0,-2,-4,-3, 0, 0,-2,-2,-2, 0,-2, 0,-3,-2,-1,-3,-2 },
/* H */{ -2, 0,-3,-1, 0,-1,-2, 8,-3, 0,-1,-3,-2, 1, 0,-2, 0, 0,-1,-2, 0,-3,-2,-1, 2, 0 },
/* I */{ -1,-3,-1,-3,-3, 0,-4,-3, 4, 0,-3, 2, 1,-3, 0,-3,-3,-3,-2,-1, 0, 3,-3,-1,-1,-3 },
/* J */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* K */{ -1, 0,-3,-1, 1,-3,-2,-1,-3, 0, 5,-2,-1, 0, 0,-1, 1, 2, 0,-1, 0,-2,-3,-1,-2, 1 },
/* L */{ -1,-4,-1,-4,-3, 0,-4,-3, 2, 0,-2, 4, 2,-3, 0,-3,-2,-2,-2,-1, 0, 1,-2,-1,-1,-3 },
/* M */{ -1,-3,-1,-3,-2, 0,-3,-2, 1, 0,-1, 2, 5,-2, 0,-2, 0,-1,-1,-1, 0, 1,-1,-1,-1,-1 },
/* N */{ -2, 3,-3, 1, 0,-3, 0, 1,-3, 0, 0,-3,-2, 6, 0,-2, 0, 0, 1, 0, 0,-3,-4,-1,-2, 0 },
/* O */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* P */{ -1,-2,-3,-1,-1,-4,-2,-2,-3, 0,-1,-3,-2,-2, 0, 7,-1,-2,-1,-1, 0,-2,-4,-2,-3,-1 },
/* Q */{ -1, 0,-3, 0, 2,-3,-2, 0,-3, 0, 1,-2, 0, 0, 0,-1, 5, 1, 0,-1, 0,-2,-2,-1,-1, 3 },
/* R */{ -1,-1,-3,-2, 0,-3,-2, 0,-3, 0, 2,-2,-1, 0, 0,-2, 1, 5,-1,-1, 0,-3,-3,-1,-2, 0 },
/* S */{ 1, 0,-1, 0, 0,-2, 0,-1,-2, 0, 0,-2,-1, 1, 0,-1, 0,-1, 4, 1, 0,-2,-3, 0,-2, 0 },
/* T */{ 0,-1,-1,-1,-1,-2,-2,-2,-1, 0,-1,-1,-1, 0, 0,-1,-1,-1, 1, 5, 0, 0,-2, 0,-2,-1 },
/* U */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
/* V */{ 0,-3,-1,-3,-2,-1,-3,-3, 3, 0,-2, 1, 1,-3, 0,-2,-2,-3,-2, 0, 0, 4,-3,-1,-1,-2 },
/* W */{ -3,-4,-2,-4,-3, 1,-2,-2,-3, 0,-3,-2,-1,-4, 0,-4,-2,-3,-3,-2, 0,-3,11,-2, 2,-3 },
/* X */{ 0,-1,-2,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0,-2,-1,-1, 0, 0, 0,-1,-2,-1,-1,-1 },
/* Y */{ -2,-3,-2,-3,-2, 3,-3, 2,-1, 0,-2,-1,-1,-2, 0,-3,-1,-2,-2,-2, 0,-1, 2,-1, 7,-2 },
/* Z */{ -1, 1,-3, 1, 4,-3,-2, 0,-3, 0, 1,-3,-1, 0, 0,-1, 3, 0, 0,-1, 0,-2,-3,-1,-2, 4 } };
#include <limits.h>
void m0(int*);
void mone(int*);
void *run(void * p);
#define  max(a,b)  (a>b?a:b)
#include <string.h>
struct ag
{
	pthread_cond_t *c1 = NULL;
	pthread_mutex_t* m1 = NULL;
	pthread_cond_t *c2 = NULL;
	pthread_mutex_t *m2 = NULL;

	int *y1 = NULL;
	int *y2 = NULL;
	int *y3 = NULL;
	int *a;
	int n;
};

#define   d  -8
int  dim;
int N;
int line;

int main(int argc, char *argv[]) {
	if(argc < 4) {
		printf("use ./file dimension printlinenumber threadcount  like ./m0 2000 200 4");
		exit(0);
	}

	dim = atoi(argv[1]);
	line = atoi(argv[2]);
	N = atoi(argv[3]);

	
	timeval start, end;
	gettimeofday(&start, NULL);
	int *a = new   int[dim*dim];
	memset(a, 0, dim*dim * sizeof(int));
	
	if(N == 1) {
		mone(a);
	}
	else if(N > 1) {
		pthread_cond_t *cs = new pthread_cond_t[N - 1];
		pthread_mutex_t *ms = new pthread_mutex_t[N - 1];

		for(size_t i = 0; i < N - 1; i++) {
			pthread_mutex_init(ms + i, NULL);
			pthread_cond_init(cs + i, NULL);
		}

		ag *ags = new ag[N];

		ags[0].y2 = new int[dim * 2];
		ags[0].y3 = new int[dim * 2];
		ags[0].a = a;
		ags[0].m2 = ms;
		ags[0].c2 = cs;
		ags[0].n = 0;

		for(size_t i = 1; i < N - 1; i++) {

			ags[i].y1 = ags[i - 1].y2;
			ags[i].y2 = ags[i - 1].y3;
			ags[i].y3 = new int[dim * 2];
			ags[i].a = a;
			ags[i].m1 = ms + i - 1;
			ags[i].c1 = cs + i - 1;
			ags[i].m2 = ms + i;
			ags[i].c2 = cs + i;
			ags[i].n = i;
			ags[i].y2[0] = 1;
		}
		//N-1
		ags[N - 1].y1 = ags[N - 2].y2;
		ags[N - 1].y2 = ags[N - 2].y3;
		ags[N - 1].a = a;
		ags[N - 1].m1 = ms + N - 2;
		ags[N - 1].c1 = cs + N - 2;
		ags[N - 1].n = N - 1;
		ags[N - 1].y2[0] = 1;


		for(int i = 0; i < dim; i++) {
			a[i] = d*i;
			a[i*dim + 0] = d*i;
		}
		pthread_t *ids = new pthread_t[N];
		for(size_t i = 0; i < N; i++) {
			pthread_create(ids + i, NULL, run, (void *)&ags[i]);
		}
		for(size_t i = 0; i < N; i++) {
			pthread_join(ids[i], NULL);
		}
		for(size_t i = 0; i < N - 1; i++) {
			pthread_mutex_destroy(ms + i);
			pthread_cond_destroy(cs + i);
		}
	}


	gettimeofday(&end, NULL);
	int s1 = end.tv_sec - start.tv_sec;
	int u1 = 0;
	if(s1 > 0 && start.tv_usec > end.tv_usec) {
		s1--;
		u1 = end.tv_usec + 1000000 - start.tv_usec;
	}
	else {
		u1 = end.tv_usec - start.tv_usec;
	}
	printf("s:%d u:%d\n", s1, u1);
	for(size_t i = 0; i < dim; i++) {
		printf("%d\t", a[line*dim + i]);
	}


	/*for(int i = 0; i < dim; i++) {
		for(int j = 0; j < dim; j++) {
			printf("%d\t", a[i*dim + j]);
		}
		printf("\n");
	}*/
	////
	/*int *b = new   int[dim*dim];
	memset(b, 0, dim*dim * sizeof(int));
	m0(b);
	for(int i = 0; i < dim; i++) {
		for(int j = 0; j < dim; j++) {
			if(a[i*dim + j] != b[i*dim + j])
				printf("%d %d %d %d\n", i, j, a[i*dim + j], b[i*dim + j]);
		}
	}*/
	return 0;
}

void *run(void * p) {
	ag a = *((ag*)p);
	int n = a.n*dim / N;

	
	printf("th: %d startNum: %d\n", a.n, n);
	if(a.y1 == NULL) {
		int *c = new int[dim / N];
		for(size_t i = 0; i < dim / N; i++) {
			c[i] = 1;
			//printf("%d\t", r[i]);
		}
		//printf("a");
		for(int i = 0; i < dim; i++) {
			a.y2[i * 2 + 1] = 1;
			//printf("%d\t",a.y2[i*2+1]);
		}
		int b, x,y;
		for(int i = 1; i < dim; i++) {
			for(int j = 1; j < dim/N; j++) {

				b = a.a[(i - 1)*dim + j - 1] + s[(i - 1) % 26][(j - 1) % 26];
				x = INT_MIN;
				y = INT_MIN;
				if(a.y2[i * 2 + 1] > 1) {
					if(a.a[i*dim + 0] + (j) * (j) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 0] + (j) * (j)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 0
							x = a.a[i*dim + 0] + (j) * (j);
							a.y2[i * 2 + 1] = 0;
						}
					}
					else {
					   if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 1
							x = a.a[i*dim + 1] + (j - 1) * (j - 1);
							a.y2[i * 2 + 1] = 1;
						}
					}

				}
				else
				
				if(a.y2[i*2 + 1] == 1) {
					if(a.a[i*dim + 0] + j*j > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						x = a.a[i*dim + 0] + j*j;
						a.y2[i*2 + 1] = 0;
					}
					else {
						x = a.a[i*dim + 1] + (j - 1) * (j - 1);
					}
				}
				else {
					x = a.a[i*dim + 0] + j*j;
				}
				if(c[j - n] > 1) {
					if(a.a[0 * dim + j] + (i) * (i) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[0 * dim + j] + (i) * (i)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							//0
							y = a.a[0 * dim + j] + (i) * (i);
							c[j - n] = 0;
						}
					}
					else {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							// 1
							y = a.a[1 * dim + j] + (i - 1) * (i - 1);
							c[j - n] = 1;
						}
					}
				}
				else
				if(c[j-n] == 1) {
					if(a.a[0 * dim + j] + i*i > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						y = a.a[0 * dim + j] + i*i;
						c[j-n] = 0;
					}
					else {
						y = a.a[1 * dim + j] + (i - 1) * (i - 1);
					}
				}
				else {
					y = a.a[0 * dim + j] + i*i;
				}

				if(x > y) {
					if(b > x) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// x
						a.a[i*dim + j] = x;
					}
				}
				else {
					if(b > y) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// y
						a.a[i*dim + j] = y;
					}
				}
			}
				pthread_mutex_lock(a.m2);
				a.y2[i * 2] = 1;
				if(a.y3[(i - 1) * 2] != 0) {
					//printf("%d %s 1\n", a.n, "sig");
					pthread_cond_signal(a.c2);
				}
				pthread_mutex_unlock(a.m2);
		}
		///
	}
	else if(a.y3 == NULL) {
		int *c = new int[dim -n ];
		for(size_t i = 0; i <  dim-n; i++) {
			c[i] = 1;
			//printf("%d\t", r[i]);
		}
		//printf("c");
		int b, x, y;
		for(int i = 1; i < dim; i++) {
					pthread_mutex_lock(a.m1);
					if(a.y1[i * 2] == 0) {
						//printf("%d  %s 2\n", a.n, "wait");
						pthread_cond_wait(a.c1, a.m1);
						//printf("%d %s\n", a.n, "run");
					}
					pthread_mutex_unlock(a.m1);
					a.y2[i * 2 + 1] = a.y1[i * 2 + 1];
			for(int j = n; j < dim; j++) {

				b = a.a[(i - 1)*dim + j - 1] + s[(i - 1) % 26][(j - 1) % 26];
				x = INT_MIN;
				y = INT_MIN;

				if(a.y2[i * 2 + 1] > 1) {
					if(a.a[i*dim + 0] + (j) * (j) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 0] + (j) * (j)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 0
							x = a.a[i*dim + 0] + (j) * (j);
							a.y2[i * 2 + 1] = 0;
						}
					}
					else {
						if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 1
							x = a.a[i*dim + 1] + (j - 1) * (j - 1);
							a.y2[i * 2 + 1] = 1;
						}
					}

				}
				else
				if(a.y2[i*2 + 1] == 1) {
					if(a.a[i*dim + 0] + j*j > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						x = a.a[i*dim + 0] + j*j;
						a.y2[i*2 + 1] = 0;
					}
					else {
						x = a.a[i*dim + 1] + (j - 1) * (j - 1);
					}
				}
				else {
					x = a.a[i*dim + 0] + j*j;
				}

				if(c[j - n] > 1) {
					if(a.a[0 * dim + j] + (i) * (i) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[0 * dim + j] + (i) * (i)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							//0
							y = a.a[0 * dim + j] + (i) * (i);
							c[j - n] = 0;
						}
					}
					else {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							// 1
							y = a.a[1 * dim + j] + (i - 1) * (i - 1);
							c[j - n] = 1;
						}
					}
				}
				else
				if(c[j-n] == 1) {
					if(a.a[0 * dim + j] + i*i > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						y = a.a[0 * dim + j] + i*i;
						c[j-n] = 0;
					}
					else {
						y = a.a[1 * dim + j] + (i - 1) * (i - 1);
					}
				}
				else {
					y = a.a[0 * dim + j] + i*i;
				}

				if(x > y) {
					if(b > x) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// x
						a.a[i*dim + j] = x;
					}
				}
				else {
					if(b > y) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// y
						a.a[i*dim + j] = y;
					}
				}
			}
					pthread_mutex_lock(a.m1);
					a.y2[i * 2] = 1;
					pthread_mutex_unlock(a.m1);
		}


	}
	else {
		int *c = new int[dim / N];
		for(size_t i = 0; i < dim / N; i++) {
			c[i] = 1;
			//printf("%d\t", r[i]);
		}
		//printf("b");
		int b, x, y;
		for(int i = 1; i < dim; i++) {
					pthread_mutex_lock(a.m1);
					if(a.y1[i * 2] == 0) {
						//printf("%d %s 1\n", a.n, "wait");
						pthread_cond_wait(a.c1, a.m1);
						//printf("%d %s\n", a.n, "run");
					}
					pthread_mutex_unlock(a.m1);
			a.y2[i * 2 + 1] = a.y1[i * 2 + 1];
			for(int j = n; j <n+ dim / N; j++) {

				b = a.a[(i - 1)*dim + j - 1] + s[(i - 1) % 26][(j - 1) % 26];
				x = INT_MIN;
				y = INT_MIN;
				if(a.y2[i * 2 + 1] > 1) {
					if(a.a[i*dim + 0] + (j) * (j) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 0] + (j) * (j)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 0
							x = a.a[i*dim + 0] + (j) * (j);
							a.y2[i * 2 + 1] = 0;
						}
					}
					else {
						if(a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]) > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
							// a.y2[i*2+1]
							x = a.a[i*dim + a.y2[i * 2 + 1]] + (j - a.y2[i * 2 + 1]) * (j - a.y2[i * 2 + 1]);
						}
						else {
							// 1
							x = a.a[i*dim + 1] + (j - 1) * (j - 1);
							a.y2[i * 2 + 1] = 1;
						}
					}

				}
				else
				if(a.y2[i*2 + 1] == 1) {
					if(a.a[i*dim + 0] + j*j > a.a[i*dim + 1] + (j - 1) * (j - 1)) {
						x = a.a[i*dim + 0] + j*j;
						a.y2[i*2 + 1] = 0;
					}
					else {
						x = a.a[i*dim + 1] + (j - 1) * (j - 1);
					}
				}
				else {
					x = a.a[i*dim + 0] + j*j;
				}

				if(c[j - n] > 1) {
					if(a.a[0 * dim + j] + (i) * (i) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[0 * dim + j] + (i) * (i)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							//0
							y = a.a[0 * dim + j] + (i) * (i);
							c[j - n] = 0;
						}
					}
					else {
						if(a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]) > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
							//c[j-n]
							y = a.a[c[j - n] * dim + j] + (i - c[j - n]) * (i - c[j - n]);
						}
						else {
							// 1
							y = a.a[1 * dim + j] + (i - 1) * (i - 1);
							c[j - n] = 1;
						}
					}
				}
				else
				if(c[j-n] == 1) {
					if(a.a[0 * dim + j] + i*i > a.a[1 * dim + j] + (i - 1) * (i - 1)) {
						y = a.a[0 * dim + j] + i*i;
						c[j-n] = 0;
					}
					else {
						y = a.a[1 * dim + j] + (i - 1) * (i - 1);
					}
				}
				else {
					y = a.a[0 * dim + j] + i*i;
				}

				if(x > y) {
					if(b > x) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// x
						a.a[i*dim + j] = x;
					}
				}
				else {
					if(b > y) {
						// b
						a.a[i*dim + j] = b;
						a.y2[i * 2 + 1] = j;
						c[j - n] = i;
					}
					else {
						// y
						a.a[i*dim + j] = y;
					}
				}
			}
					pthread_mutex_lock(a.m2);
					a.y2[i * 2] = 1;
					if(a.y3[(i - 1) * 2] != 0) {
						//printf("%d %s 2\n", a.n, "sig");
						pthread_cond_signal(a.c2);
					}
					pthread_mutex_unlock(a.m2);

		}


	}
}





void m0(int* a) {
	for(int i = 0; i < dim; i++) {
		a[0 * dim + i] = d * i;
		a[i*dim + 0] = d* i;
	}

	for(int i = 1; i < dim; i++) {
		for(int j = 1; j < dim; j++) {
			int t;
			int b = a[(i - 1)*dim + j - 1] + s[(i - 1) % 26][(j - 1) % 26];
			int x = INT_MIN;
			int y = INT_MIN;
			for(int k = 0; k < j; k++) {
				if(a[i*dim + k] + (j - k) * (j - k) > x)
					x = a[i*dim + k] + (j - k) * (j - k);
			}
			for(int k = 0; k < i; k++) {
				if(a[k*dim + j] + (i - k) * (i - k) > y)
					y = a[k*dim + j] + (i - k) * (i - k);
			}
			t = max(max(x, y), b);
			a[i*dim + j] = t;
		}
	}
	//for(int i = 0; i < dim; i++) {
	//	for(int j = 0; j < dim; j++) {
	//	  
	//	}
	//}

}

void mone(int* a) {
	for(int i = 0; i < dim; i++) {
		a[i] = d*i;
		a[i*dim + 0] = d*i;
	}

	int *r = new int[dim];
	int *c = new int[dim];
	for(size_t i = 0; i < dim; i++) {
		r[i] = 1;
		c[i] = 1;
	}

	for(int i = 1; i < dim; i++) {
		for(int j = 1; j < dim; j++) {

			int b = a[(i - 1)*dim + j - 1] + s[(i - 1) % 26][(j - 1) % 26];
			int x = INT_MIN;
			int y = INT_MIN;

			if(r[i] > 1) {
				if(a[i*dim + 0] + (j) * (j) > a[i*dim + 1] + (j - 1) * (j - 1)) {
					if(a[i*dim + r[i]] + (j - r[i]) * (j - r[i]) > a[i*dim + 0] + (j) * (j)) {
						// r[i]
						x = a[i*dim + r[i]] + (j - r[i]) * (j - r[i]);
					}
					else {
						// 0
						x = a[i*dim + 0] + (j) * (j);
						r[i] = 0;
					}
				}
				else {
					if(a[i*dim + r[i]] + (j - r[i]) * (j - r[i]) > a[i*dim + 1] + (j - 1) * (j - 1)) {
						// r[i]
						x = a[i*dim + r[i]] + (j - r[i]) * (j - r[i]);
					}
					else {
						// 1
						x = a[i*dim + 1] + (j - 1) * (j - 1);
						r[i] = 1;
					}
				}

			}
			else
				if(r[i] == 1) {
					if(a[i*dim + 0] + j*j > a[i*dim + 1] + (j - 1) * (j - 1)) {
						x = a[i*dim + 0] + j*j;
						r[i] = 0;
					}
					else {
						x = a[i*dim + 1] + (j - 1) * (j - 1);
					}
				}
				else {
					x = a[i*dim + 0] + j*j;
				}

				if(c[j] > 1) {
					if(a[0 * dim + j] + (i) * (i) > a[1 * dim + j] + (i - 1) * (i - 1)) {
						if(a[c[j] * dim + j] + (i - c[j]) * (i - c[j]) > a[0 * dim + j] + (i) * (i)) {
							//c[j]
							y = a[c[j] * dim + j] + (i - c[j]) * (i - c[j]);
						}
						else {
							//0
							y = a[0 * dim + j] + (i) * (i);
							c[j] = 0;
						}
					}
					else {
						if(a[c[j] * dim + j] + (i - c[j]) * (i - c[j]) > a[1 * dim + j] + (i - 1) * (i - 1)) {
							//c[j]
							y = a[c[j] * dim + j] + (i - c[j]) * (i - c[j]);
						}
						else {
							// 1
							y = a[1 * dim + j] + (i - 1) * (i - 1);
							c[j] = 1;
						}
					}
				}
				else
					if(c[j] == 1) {
						if(a[0 * dim + j] + i*i > a[1 * dim + j] + (i - 1) * (i - 1)) {
							y = a[0 * dim + j] + i*i;
							c[j] = 0;
						}
						else {
							y = a[1 * dim + j] + (i - 1) * (i - 1);
						}
					}
					else {
						y = a[0 * dim + j] + i*i;
					}

					if(x > y) {
						if(b > x) {
							// b
							a[i*dim + j] = b;
							r[i] = j;
							c[j] = i;
						}
						else {
							// x
							a[i*dim + j] = x;
						}
					}
					else {
						if(b > y) {
							// b
							a[i*dim + j] = b;
							r[i] = j;
							c[j] = i;
						}
						else {
							// y
							a[i*dim + j] = y;
						}
					}
		}
	}
	///*for(int i = 0; i < dim; i++) {
	//	for(int j = 0; j < dim; j++) {
	//		printf("%d\t", a[i*dim + j]);
	//	}
	//	printf("\n");
	//}*/

}
