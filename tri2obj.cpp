#include <stdio.h>
#include <string.h>
 
int main( int argc, char **argv )
{
	char ifname[100], ofname[100];	
	FILE *ifp, *ofp;
	
	strcpy(ifname, argv[1]);
	strcpy(ofname, argv[2]);

	ifp=fopen(ifname, "r"); //ifp=fopen("sphere.tri", "r");
	ofp=fopen(ofname, "w"); //ofp=fopen("sphere.obj", "w");
	
	char temp[10];
	fscanf(ifp, "%s", &temp);	

	int nverts=0, ntris=0;
	fscanf(ifp, "%d", &nverts);		
	fscanf(ifp, "%d", &ntris);		

	int i, temp_index;
	float temp_coord;
	
	for(i=0; i<nverts; i++) {	
											
		fprintf(ofp, "v ");
		fscanf(ifp, "%f", &temp_coord);		fprintf(ofp, "%f ", (double)temp_coord);
		fscanf(ifp, "%f", &temp_coord);		fprintf(ofp, "%f ", (double)temp_coord);
		fscanf(ifp, "%f", &temp_coord);		fprintf(ofp, "%f \n", (double)temp_coord);								
	}										
	fprintf(ofp, "# %d vertices \n\n", nverts);

	for(i=0; i<ntris; i++) {	
											
		fprintf(ofp, "f ");
		fscanf(ifp, "%d", &temp_index);		fprintf(ofp, "%d ", temp_index+1);
		fscanf(ifp, "%d", &temp_index);		fprintf(ofp, "%d ", temp_index+1);
		fscanf(ifp, "%d", &temp_index);		fprintf(ofp, "%d \n", temp_index+1);										
	}										
	fprintf(ofp, "# %d faces \n\n", ntris);
	//fprintf(ofp, "g \n");
	
	fclose(ifp);
	fclose(ofp);

	return 0;

}
