/*Hussain Bhinderwala
    TE comps, Roll no 5
*/


#include<stdio.h>
#include<math.h>

struct point
{
	float x;
	float y;
	int cluster;
};


void main()
{
	int a,n,i,k;
	printf("Enter number of points\n");
	scanf("%d",&n);

	struct point arr[n];
    printf("Enter number of clusters\n");
	scanf("%d",&k);

	printf("Enter x and y co-ordinates\n");
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&arr[i].x, &arr[i].y);

		arr[i].cluster=i%k;

		printf("is in cluster : %d\n",arr[i].cluster);
	}

    float mean_x[k];
	float mean_y[k];
   	for(i=0;i<k;i++)
	{
		mean_x[i]=0;
		mean_y[i]=0;
	}

    k_means(arr,mean_x,mean_y,k,n);


}

void mean(struct point arr[], int k, int n,float mean_x[k], float mean_y[k])
{

//getting means
    int i,j;
    int flag=0;
    int count = 0;
    float sum_x =0;
    float sum_y=0;


    while(flag<k)
    {
        for(i=0;i<n;i++)
        {
            if(arr[i].cluster==flag)
            {
                sum_x =sum_x + arr[i].x;
                sum_y =sum_y + arr[i].y;
                count++;
            }
        }

        mean_x[flag]=sum_x/count;
        printf(" mean_x of cluster %d : %f\n", flag, mean_x[flag]);

        mean_y[flag]=sum_y/count;
        printf(" mean_y of cluster %d : %f\n", flag, mean_y[flag]);

        sum_x=0;
        sum_y=0;
        count = 0;
        flag++;

    }
    printf("\n");

}

void k_means(struct point arr[], float mean_x[],float mean_y[], int k, int n)
{
    mean(arr,k,n, mean_x,mean_y);

   int i,j;
    int temp_cluster[n];
    for(i=0;i<n;i++)
    {
        temp_cluster[i]=arr[i].cluster;
    }

    float distance[n][k];


    float temp;
    int count = 0;
    float x,y;

    for(i=0;i<n;i++)
    {
             for(j=0;j<k;j++)
            {
                x=(float)((mean_x[j]-arr[i].x)*(mean_x[j]-arr[i].x));
                y=(float)((mean_y[j]-arr[i].y)*(mean_y[j]-arr[i].y));
                distance[i][j] = (float)sqrt(x+y);
            }
    }

    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("for point %d, ",i);

        for(j=0;j<k;j++)
        {
            printf("distance from cluster %d is : %f ",j, distance[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    for(i=0;i<n;i++)
    {
        temp=distance[i][0];


            for(j=0;j<k;j++)
            {

                if(distance[i][j] <= temp)
                {
                    temp = distance[i][j];
                    arr[i].cluster = j;
                }
            }


        printf("    for point %d, cluster is %d\n",i, arr[i].cluster);
    }

    printf("\n");

    int counter = 0;
    for(i=0;i<n;i++)
    {
            if(temp_cluster[i] == arr[i].cluster)
            {
               counter++;
            }
    }

    if(counter==n)
    {
        printf("Execution Finished\n");
        return;
    }

    k_means(arr,mean_x,mean_y,k,n);

}
/*
Enter number of points
7
Enter number of clusters
3
Enter x and y co-ordinates
1.4 5
is in cluster : 0
1 3
is in cluster : 1
4.3 7
is in cluster : 2
8 2.1
is in cluster : 0
11 34
is in cluster : 1
3.2 4
is in cluster : 2
11 3.4
is in cluster : 0
 mean_x of cluster 0 : 6.800000
 mean_y of cluster 0 : 3.500000
 mean_x of cluster 1 : 6.000000
 mean_y of cluster 1 : 18.500000
 mean_x of cluster 2 : 3.750000
 mean_y of cluster 2 : 5.500000


for point 0, distance from cluster 0 is : 5.604462 distance from cluster 1 is : 14.262188 distance from cluster 2 is : 2.402603
for point 1, distance from cluster 0 is : 5.821511 distance from cluster 1 is : 16.286497 distance from cluster 2 is : 3.716517
for point 2, distance from cluster 0 is : 4.301162 distance from cluster 1 is : 11.624973 distance from cluster 2 is : 1.597655
for point 3, distance from cluster 0 is : 1.843909 distance from cluster 1 is : 16.521502 distance from cluster 2 is : 5.442656
for point 4, distance from cluster 0 is : 30.787823 distance from cluster 1 is : 16.286497 distance from cluster 2 is : 29.407694
for point 5, distance from cluster 0 is : 3.634556 distance from cluster 1 is : 14.767871 distance from cluster 2 is : 1.597654
for point 6, distance from cluster 0 is : 4.201190 distance from cluster 1 is : 15.906288 distance from cluster 2 is : 7.548013

    for point 0, cluster is 2
    for point 1, cluster is 2
    for point 2, cluster is 2
    for point 3, cluster is 0
    for point 4, cluster is 1
    for point 5, cluster is 2
    for point 6, cluster is 0

 mean_x of cluster 0 : 9.500000
 mean_y of cluster 0 : 2.750000
 mean_x of cluster 1 : 11.000000
 mean_y of cluster 1 : 34.000000
 mean_x of cluster 2 : 2.475000
 mean_y of cluster 2 : 4.750000


for point 0, distance from cluster 0 is : 8.406693 distance from cluster 1 is : 30.547668 distance from cluster 2 is : 1.103687
for point 1, distance from cluster 0 is : 8.503675 distance from cluster 1 is : 32.572994 distance from cluster 2 is : 2.288695
for point 2, distance from cluster 0 is : 6.715839 distance from cluster 1 is : 27.818878 distance from cluster 2 is : 2.897089
for point 3, distance from cluster 0 is : 1.634778 distance from cluster 1 is : 32.040756 distance from cluster 2 is : 6.127652
for point 4, distance from cluster 0 is : 31.285980 distance from cluster 1 is : 0.000000 distance from cluster 2 is : 30.467001
for point 5, distance from cluster 0 is : 6.422811 distance from cluster 1 is : 30.997419 distance from cluster 2 is : 1.043132
for point 6, distance from cluster 0 is : 1.634778 distance from cluster 1 is : 30.600000 distance from cluster 2 is : 8.631229

    for point 0, cluster is 2
    for point 1, cluster is 2
    for point 2, cluster is 2
    for point 3, cluster is 0
    for point 4, cluster is 1
    for point 5, cluster is 2
    for point 6, cluster is 0

*/

