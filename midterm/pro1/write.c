#include <stdio.h>



int main (int argc, char* argv[])
{
	int a,b,c;
	FILE *fp;

	if (argc !=2) {
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		return 1; 
	}

	fp = fopen(argv[1], "w");
	
        while(scanf("%d %s %hd", &rec.id, rec.name, &rec.score) == 3)
        	fprintf(fp, "%d %s %d", rec.id, rec.name, rec.score);

	fclose(fp);
	return 0;

}
