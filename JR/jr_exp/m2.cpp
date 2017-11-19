#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>


#define   d  -8
int  dim;
int line;
int N;


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


void *run(void * p)  

int main(int argc, char *argv[]) {

	//printf("%d\n", argc);
	/*for(size_t i = 0; i < argc; i++) {
		printf("%s    ", argv[i]);
	}*/
	//. / a.out 2000 200 3
	if(argc < 4) {
		printf("use ./file dimension printlinenumber threadcount  like ./m0 2000 200 4");
		exit(0);
	}

	dim = atoi(argv[1]);
	line = atoi(argv[2]);
	N = atoi(argv[3]);

	timeval start, end;
	gettimeofday(&start, NULL);

	int *a = new int[dim*dim];

	//1
	if(N == 1) {
		int *x = new int[dim];
		int *y = new int[dim];
		int t;
		for(size_t i = 0; i < dim; i++) {
			t = d*i;
			a[i*dim] = t;
			a[i] = t;
			x[i] = t;
			y[i] = t;
		}
		int tx;
		int ty;
		for(size_t i = 1; i < dim; i++) {
			for(size_t j = 1; j < dim; j++) {
				t = a[(i - 1)*dim + (j - 1)] + s[(i - 1) % 26][(j - 1) % 26];
				tx = x[i] + d;
				ty = y[j] + d;
				if(t > tx) {
					if(t < ty)t = ty;
				}
				else {
					if(ty > tx)t = ty;
					else t = tx;
				}
				if(t > x[i]) {
					x[i] = t;
				}
				if(t > y[j]) {
					y[j] = t;
				}
				a[i*dim + j] = t;
			}
		}
	}

	//N>1
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

		for(size_t i = 0; i < dim; i++) {
			int t = i*d;
			a[i*dim] = t;
			a[i] = t;
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


	/*for(size_t i = 0; i < 10; i++) {
		for(size_t j = 0; j < 10; j++) {
			printf("%d\t", a[i*dim + j]);
		}
		printf("\n");
	}*/
	for(size_t i = 0; i < dim; i++) {
		printf("%d\t", a[line*dim + i]);
	}


	return 0;
}
