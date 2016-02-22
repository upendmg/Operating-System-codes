#include <stdio.h>
#include <stdbool.h>
typedef struct resource
{
	int no;
}resource;

typedef struct allocation
{
	resource R[3];
}allocation;

typedef struct max
{
	resource R[3];
}max;

typedef struct available
{
	resource R[3];
}available;

typedef struct need
{
    resource R[3];
}need;

typedef struct process
{
	int prc_no;
	allocation AL;
	max MAX;
    need N;
    bool done;
}process;

int p;
available AVL;

int calculate_data(process []);
int print_data(process []);

int main()
{
	int i, j, k = 0, count_process = 0, update = 1, flag = 0, flag_p = 0;
	
	printf ("Enter the number of process available: ");
	scanf ("%d", &p);
	process pro[p];
    int safe_sequence[p];
    for (i = 0; i < p; i++)
        pro[i].done = false;
    calculate_data(pro);
    print_data(pro);

    i = 0;

    while (update)
    {
        update = 0;
        count_process = 0;
        while (count_process < p)
        {
            flag = 0;
            i = count_process;
            if (!pro[i].done)
            {
                for (j = 0; j < 3; j++)
                {
                    if (pro[i].N.R[j].no > AVL.R[j].no)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    for (j = 0; j < 3; j++)
                    {
                        AVL.R[j].no = pro[i].AL.R[j].no + AVL.R[j].no;
                        pro[i].AL.R[j].no = 0;
                    }
                    pro[i].done = true;
                    safe_sequence[k] = pro[i].prc_no;
                    k++;
                    update = 1;
                }
                else
                    pro[i].done = false;
            }
            count_process++;
        }
    }

    for (i = 0; i < p; i++)
		if (pro[i].done == false)
		{
			printf ("There is a process that doesn't have the required resources. So no safe sequence exist\n");
			return 0;
		}

    printf ("\nThe Safe Sequence is");
    for (i = 0; i < k; i++)
        printf (" -> P%d", safe_sequence[i]);

    printf ("\n");
    return 0;
}

int calculate_data(process pr[])
{
    int i, j;
	
	printf ("Enter the Currently AVAILABLE resources\n");
	for (i = 0; i < 3; i++)
	{
		printf ("Enter the value for resource %d: ", i + 1);
		scanf ("%d", &AVL.R[i].no);
	}
	
	for (i = 0; i < p; i++)
		pr[i].prc_no = i + 1;

	printf ("Enter the resource allocation matrix\n");
	for (i = 0; i < p; i++)
		for (j = 0; j < 3; j++)
			scanf ("%d", &pr[i].AL.R[j].no);
	
	printf ("Enter the maximum resource matrix\n");
	for (i = 0; i < p; i++)
		for (j = 0; j < 3; j++)
			scanf ("%d", &pr[i].MAX.R[j].no);

    for (i = 0; i < p; i++)
        for (j = 0; j < 3; j++)
            pr[i].N.R[j].no = pr[i].MAX.R[j].no - pr[i].AL.R[j].no;

    return 0;
}

//Print all the data
int print_data(process pr[])
{
    int i, j;

	printf ("PROCESS\t\tALLOCATION\n\t\tR1 R2 R3\n");
	for (i = 0; i < p; i++)
	{
		printf ("P%d\t\t", pr[i].prc_no);
		for (j = 0; j < 3; j++)
			printf ("%2d ", pr[i].AL.R[j].no);
		printf ("\n");
	}

	printf ("PROCESS\t\tMAX\n\t\tR1 R2 R3\n");
	for (i = 0; i < p; i++)
	{
		printf ("P%d\t\t", pr[i].prc_no);
		for (j = 0; j < 3; j++)
			printf ("%2d ", pr[i].MAX.R[j].no);
		printf ("\n");
	}

    printf ("PROCESS\t\tDONE?\n");
    for (i = 0; i < p; i++)
    {
        printf ("P%d\t\t", pr[i].prc_no);
        printf ("%s\n", pr[i].done ? "True" : "False");
    }

	printf ("Total Available Resource\n");
	for (i = 0; i < 3; i++)
		printf ("%d ", AVL.R[i].no);

	printf ("\n");
	return 0;
}
