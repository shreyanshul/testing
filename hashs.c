# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

struct node{
	char *data;
	struct node *head;
};
struct stat hash_ETH(char **, int);
struct stat  hash_cpp(char **, int );
struct stat hash_cc1(char **, int);

int main()
{
  char **input;
  struct stat hash_stat;
  int n,k,i,j;
  srand(time(NULL));
  n=1632;
  k=5;
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
  printf("ETH\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_ETH(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cc1\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cc1(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cpp\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cpp(input,i);
      printf("%d,%f,%f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  
  return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
  struct stat hash_stat;
  struct node *a[tablesize+10];
  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	int eth[tablesize+10];
	int i, j;
	int n = 1632;
	for( i = 0; i <= tablesize; i++){
		eth[i] = 0;
		//a[i]->head = NULL;
	}
	int h;
	for( i = 0; i < n; i++ ){
		h = 1;
		for( j = 0; j < 5; j++)
			h = (int)input[i][j]*(h%257 + 1);
		h = h%tablesize;
	/*struct node *t;
	t = a[h];
	while( t->head != NULL )
		t = t->head;
	if( t->head == NULL ){
		struct node *temp = (struct node*)malloc( sizeof(struct node) );
		temp->data = input[i];
		t->head = temp;
		temp->head = NULL;
	}*/
//	printf("%d\n",h);
	eth[h]++;
	}
	hash_stat.item = 0;
	int max = 0;
	int sum = 0;
	for( i = 0; i <= tablesize; i++){
		if( eth[i] > 0){
			hash_stat.item ++;
			sum = sum + (eth[i]*(eth[i]+1))/2;
		if( eth[i] > max )
			max = eth[i];
		}
	}
	hash_stat.lenLong = max;
	hash_stat.avgComp = (float)sum/1632;
	double stndev;
	for( i = 0; i <= tablesize; i++ )
		for( j = 1; j <= eth[i]; j++ )
			stndev = stndev + ( j - hash_stat.avgComp)*( j - hash_stat.avgComp);
	stndev = (float) stndev/1632;
	stndev = sqrt( (double)stndev);
  	hash_stat.stdDev = stndev;
	/*struct node *temp;
	for( i = 0; i <= tablesize; i++ ){
		if( eth[i] > 0 )
			for( temp = a[i]->head; temp->head != NULL; temp = temp->head )
				printf("%s ",temp->data);
		printf("\n");
	}*/
  return hash_stat;
}

struct stat hash_cpp(char **input,int tablesize)
{
 struct stat hash_stat;
  struct node *a[tablesize+10];
  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	int eth[tablesize+10];
	int i, j;
	int n = 1632;
	for( i = 0; i <= tablesize; i++){
		eth[i] = 0;
		//a[i]->head = NULL;
	}
	int h;
	for( i = 0; i < n; i++ ){
		h = 1;
		for( j = 0; j < 5; j++)
			h = (int)input[i][j] + (4*h);
		h = h << 1;
		h = h >> 1;
		h = h%tablesize;
	/*struct node *t;
	t = a[h];
	while( t->head != NULL )
		t = t->head;
	if( t->head == NULL ){
		struct node *temp = (struct node*)malloc( sizeof(struct node) );
		temp->data = input[i];
		t->head = temp;
		temp->head = NULL;
	}*/
	eth[h]++;
	}
	hash_stat.item = 0;
	int max = 0;
	int sum = 0;
	for( i = 0; i <= tablesize; i++){
		if( eth[i] > 0){
			hash_stat.item ++;
			sum = sum + (eth[i]*(eth[i]+1))/2;
		if( eth[i] > max )
			max = eth[i];
		}
	}
	hash_stat.lenLong = max;
	hash_stat.avgComp = (float)sum/1632;
	double stndev;
	for( i = 0; i <= tablesize; i++ )
		for( j = 1; j <= eth[i]; j++ )
			stndev = stndev + ( j - hash_stat.avgComp)*( j - hash_stat.avgComp);
	stndev = (float) stndev/1632;
	stndev = sqrt( (double)stndev);
  	hash_stat.stdDev = stndev;
	/*struct node *temp;
	for( i = 0; i <= tablesize; i++ ){
		if( eth[i] > 0 )
			for( temp = a[i]->head; temp->head != NULL; temp = temp->head )
				printf("%s ",temp->data);
		printf("\n");
	}*/
  return hash_stat;
  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
 return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  struct stat hash_stat;
  struct node *a[tablesize+10];
  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
	int eth[tablesize+10];
	int i, j;
	int n = 1632;
	for( i = 0; i <= tablesize; i++){
		eth[i] = 0;
		//a[i]->head = NULL;
	}
	int h;
	for( i = 0; i < n; i++ ){
		h = 5;
		for( j = 0; j < 5; j++)
			h = 613*h+(int)input[i][j];
		//h = h << 2;
		//h = h >> 2;
		h = h%tablesize;
	printf("%d\n",h);
	/*struct node *t;
	t = a[h];
	while( t->head != NULL )
		t = t->head;
	if( t->head == NULL ){
		struct node *temp = (struct node*)malloc( sizeof(struct node) );
		temp->data = input[i];
		t->head = temp;
		temp->head = NULL;
	}*/
	eth[h]++;
	}
	hash_stat.item = 0;
	int max = 0;
	int sum = 0;
	for( i = 0; i <= tablesize; i++){
		if( eth[i] > 0){
			hash_stat.item ++;
			sum = sum + (eth[i]*(eth[i]+1))/2;
		if( eth[i] > max )
			max = eth[i];
		}
	}
	hash_stat.lenLong = max;
	hash_stat.avgComp = (float)sum/1632;
	double stndev;
	for( i = 0; i <= tablesize; i++ )
		for( j = 1; j <= eth[i]; j++ )
			stndev = stndev + ( j - hash_stat.avgComp)*( j - hash_stat.avgComp);
	stndev = (float) stndev/1632;
	stndev = sqrt( (double)stndev);
  	hash_stat.stdDev = stndev;
	/*struct node *temp;
	for( i = 0; i <= tablesize; i++ ){
		if( eth[i] > 0 )
			for( temp = a[i]->head; temp->head != NULL; temp = temp->head )
				printf("%s ",temp->data);
		printf("\n");
	}*/
  return hash_stat;
  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  
 return hash_stat;
}

