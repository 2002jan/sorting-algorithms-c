#ifndef PATH_MAX
#define PATH_MAX 260
#endif

#ifndef CSV_EXPORTER
#define CSV_EXPORTER

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include "random_data.h"

char output_path[] = ".\\output";

void exportToCsv(int *ns, double *time, int n, char *exerciseName, char *algorithmName, enum sequenceType dataType);

void checkSubdirectory(char *path);

void checkSubdirectory(char *path)
{
    struct stat sb;

    if (stat(path, &sb) == -1)
    {
        mkdir(path, 0700);
    }
}

void exportToCsv(int *ns, double *time, int n, char *exerciseName, char *algorithmName, enum sequenceType dataType)
{
    checkSubdirectory(output_path);

    char *path = (char *)malloc(sizeof(char) * PATH_MAX);

    sprintf(path, "%s\\output_%s_%s_%s.csv", output_path, exerciseName, algorithmName, getSequenceTypeName(dataType));
    
    FILE *csv;
    
    csv = fopen(path, "w+");

    if(csv == NULL)
    {
        printf("Error while opening/creating csv file!");
        exit(1);
        free(path);
    }

    int i;

    fprintf(csv, "Number of elements, Execution time\n");

    for (i = 0; i < n; i++)
    {
        fprintf(csv, "%d, %f\n", ns[i], time[i]);
    }

    fclose(csv);
    free(path);
    
}

#endif