void patchingproblem(vector<int> arr, long int n)            // Checking for the most possible sum, and then slowly proceeding greedily.
{
    int sump = 1;
    int count = 0;
    vector<int>::iterator iter;
    iter = arr.begin();
    while(sump < n)
    {
       if(*iter<=sump && iter!=arr.end())
        {
           sump = sump + *iter;
           iter++;
        }
       else
        {
            sump+=sump;                        // This ensures that we actually end up adding numbers like 1,2,4,8, and so on - Binary Number System.
            count+=1;
        }
    }
    printf("%d",count);
}


int main() 
{
	long  n;
    std::vector<int> arr;
    int input;
    int elemcount=0;
    int temp1;
    do
    {
        if (std::cin >> input)
            elemcount+=1;
            temp1 = input;
            arr.push_back(input);    
    }while (std::cin && std::cin.peek() != '\n');
	cin>>n;   
	patchingproblem(arr, n); 
	return 0;
}
