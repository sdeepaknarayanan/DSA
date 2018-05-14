// Prime to Prime
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

int visited[1061];
int level[1061];
int parent[1061];
int dequeue();
void enqueue(int a);
int isEmpty();
int isFull();
int size = 1061;
int queue[1061];
int front=-1;
int rear=-1;
int plist[1062];
int arr[10000];

int isPrime(long n) 
{
int flag = 0;
    int val;
    if(n<=2)
        return 1;
    else
    {
        int j = pow(n,0.5);
        for(int i = 2; i<=j;i++)
        {
            if(n%i == 0)
            {
                flag = 1;
                val = i;
                break;
            }
        }
    }
    if(flag)
        return 0;
    else
        return 1;
}

void bfs( int s, int t, int arr[][1062], int n);

void printpath(int s, int t)
{
	if(s==t)
	{
		printf("%d ",plist[s]);
	}
	else
	{  
		if(parent[t]!= -1)
		{
		printpath(s, parent[t]);
		printf("%d ", plist[t]);
		}
		else
		{
			printf("None");
		}
	}
}

int main()
{
    int visp[10000];
	
	int prime[10000];
	int j = 1;
	for(int i =0; i<=1000;i++)
	{
		arr[i] = 0;
		prime[i]=0;
       
	}
     plist[0] = 0;

	for(int k=1001; k<10000;k++)
	{
        
		if(isPrime(k))
		{
            plist[j] = k;
			arr[k] = j;
			prime[k] = 1;
			j+=1;
		}
		else
		{
			arr[k] = 0;
			prime[k] = 0;	
		}		
	}
	
	// Number of Test Cases is below
	
	int t;
    scanf("%d",&t);
	for(int i=0;i<t;i++)
	{      
        for(int t11=0;t11<10000;t11++)
        {
            visp[t11] = -1;
        }
        front = rear = -1;
                int graph[1062][1062];
                int s;
                int t1;
                scanf("%d %d",&s,&t1);
                if(isPrime(s)&&isPrime(t1))
                {
                    for(int it1=0; it1<1062;it1++)
                    {
                        for(int it2=0;it2<1062;it2++)
                        {
                            graph[it1][it2] = 0;
                        }

                    }	
                 enqueue(s);
                 visp[s] = 0;
                 int a,b,c,d;
                 while(!isEmpty())
                    {
                         
                        int v = dequeue();
                        a = v%10;
                        b = (v/10)%10;
                        c = (v/100)%10;
                        d = (v/1000);


                        for(int it1 = 1; it1<10;it1++)
                        {

                            int temp = a+b*10+c*100+it1*1000;
                            if(prime[temp]&&temp!=v)
                            {
                                if(visp[temp]==-1)
                                {

                                    enqueue(temp);
                                    visp[temp] = 0;
                                    graph[arr[v]][arr[temp]] = 1;

                                }
                              }
                        }

                        for(int it1 = 0; it1<10;it1++)
                        {

                            int temp = a+b*10+it1*100+d*1000;

                            if(prime[temp]&&temp!=v)
                            {
                               if(visp[temp]==-1)
                                {
                                    enqueue(temp);
                                    visp[temp] = 0;
                                    graph[arr[v]][arr[temp]] = 1;

                                }
                            }
                        }

                        for(int it1 = 0; it1<10;it1++)
                        {

                            int temp = a+it1*10+c*100+d*1000;

                            if(prime[temp]&&temp!=v)
                            {
                               if(visp[temp]==-1)
                                {
                                    enqueue(temp);
                                    visp[temp] = 0;
                                    graph[arr[v]][arr[temp]] = 1;

                                }
                            }
                        }

                        for(int it1 = 0; it1<10;it1++)
                        {
                            int temp = it1+b*10+c*100+d*1000;
                            if(prime[temp]&&temp!=v)
                            {
                                if(visp[temp]==-1)
                                {
                                    enqueue(temp);
                                    visp[temp] = 0;
                                    graph[arr[v]][arr[temp]] = 1;
                                }
                            }
                        }
                        visp[v] = 1;
                    }
                  
                    front = rear = -1;
                    bfs(s,t1,graph,1062);          
                    printpath(arr[s],arr[t1]);
                
                    printf("\n");
                }
            else
            {
                printf("None\n");
            }
    }
		return 0;
	}




void bfs( int s, int t, int graph[][1062], int n)
{  
	int i;
	for(i=0;i<1061;i++)
	{
		visited[i]=-1; 
		level[i]=-1;
		parent[i]=-1;
	}
	visited[arr[s]]=0;
	enqueue(arr[s]);	
	level[arr[s]]=0;
   
	while(!isEmpty())
	{
		int u = dequeue();
		int i;
		for(i=1;i<n;i++)
		{ 
			if (graph[u][i]==1 && visited[i]==-1)
			{
                
                
				enqueue(i);
				level[i]=level[u]+1;
				parent[i]=u;
				visited[i]=0;
			}
		}
		visited[u]=1;
	}

}
// Queue function definitions

void enqueue(int a)

{
    if (front== -1)
    {
        front  =  0;
        rear = rear + 1;
        queue[front ] = a;
    }
    else if(rear==size-1 && front!=0)
    {     rear = 0;
        queue[rear] = a;

    }
    else
    {
        rear = rear + 1;
        queue[rear] = a;
    }
}

int dequeue()
{	
	int temp=queue[front];
    if(front == rear )
        front = rear = -1;
    else if(front == size-1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
    return temp;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if ((rear - front) == size -1|| (front - rear) == 1)
    {
        return 1;
    }
    else
        return 0;
}
