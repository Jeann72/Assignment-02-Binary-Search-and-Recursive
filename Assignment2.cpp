#include <iostream>
#include<vector>

using namespace std;

//const vector<int>& arr = you can only read from the vector, you cannot modify it
//int target = value we are looking for 
//int& comparisons = a counter for the number of comparisons made during the search
int binarySearchIterative(const vector<int>& arr, int target, int& comparisons)
{
    //left boundary of search space 
    int low = 0;
    //right boundary of search space(last index) 
    int high= (int)arr.size()-1;
    
    //keep going until the search space is empty
    while(low<=high)
        {
            //int mid = low + (high - low) / 2;
            //pick middle element
            int mid = (low + high) / 2;
            //count: compare arr[mid] to target
            comparisons++;

            //check if the middle element is the target
            if(arr[mid] == target)
            {
                //found it return the index of the target
                return mid;
            }
            //count: compare arr[mid] to target(second comparison)
            comparisons++;

            if(arr[mid] < target)
            {
                //target is bigger than the middle element, so we can ignore the left half of the search space
                low = mid + 1;
            }
            else
            {
                //target is smaller than the middle element, so we can ignore the right half of the search space
                high = mid -1;
            }

        }
        //loop ends = not found, return -1
        return -1;
}

//const vector<int>& arr = you can only read from the vector, you cannot modify it
//int low = left boundary of search space
//int high = right boundary of search space
//int target = value we are looking for
//int& comparisons = a counter for the number of comparisons made during the search
int binarySearchRecursive(const vector<int>& arr, int low, int high,int target, int& comparisons)
{
    //range empty, so the target is not found
    if(low > high)
    {   
        //not found, return -1
        return -1;
    }

    int mid = (low + high) / 2;
    comparisons++;

    //
    if(arr[mid] == target)
    {   
        //found, return the index of the target
        return mid;
    }
    comparisons++;
    
    if(arr[mid] < target)
    {
        //target is bigger than the middle element, so we can ignore the left half of the search space
        return binarySearchRecursive(arr,mid + 1, high,target,comparisons);
    }
    else
    {
        //target is smaller than the middle element, so we can ignore the right half of the search space
        return binarySearchRecursive(arr,low,mid - 1,target,comparisons);
    }
}

int linearSearch(const vector<int>& arr, int target, int& comparisons)
{
    for(int i = 0; i < (int)arr.size(); i++)
        {
            //count: compare arr[i] to target
            comparisons++;
                
            if(arr[i] == target)
            {   
                //found, return the index of the target
                return i;
            }
        }
        //loop ends = not found, return -1
        return -1;
}

//const char* label= it's where it is(adress)
//int target= value we are looking for
//int idxI= index of target in iterative search or -1 if not found
//int cmpI= number of comparisons made in iterative search
//int idxR= index of target in recursive search or -1 if not found
//int cmpR= number of comparisons made in recursive search
//int idxL= index of target in linear search or -1 if not found
//int cmpL = number of comparisons made in linear search
void printResult(const char* label ,int target, int idxI,int cmpI,int idxR,int cmpR, int idxL,int cmpL)
{
    cout << label << " (target =" << target << ")\n"
         << " Iterative : " << idxI << " cmps= " << cmpI << "\n"
         << " Recursive : " << idxR << " cmps= " << cmpR << "\n"
         << " Linear : "    << idxL << " cmps= " << cmpL << "\n";
}
                  

int main() 
{ 
    //vector 
    vector<int> arr = {2,5,13,22,52,67,74,86,91,99,109,115,200,250,312};
    //targets to search for
    int targets[]={2,312,86,0,70};
    //labels for the targets
    const char* labels[]={"first","last","middle","below range","inside range"};

    //loop through the targets and search for each one using all three search methods at the same time, and print the results
    //loop through 5 test cases(0-4 of the targets and labels arrays)
    for(int i = 0; i < 5; i++)
        {
            //reset counters for each search
            int cmpI = 0;
            int cmpR = 0;
            int cmpL = 0;

            //returns index of target in arr or -1 if not found, and updates the comparison counter for all.
            //iterative search always searches the entire array.
            int idxI = binarySearchIterative(arr, targets[i], cmpI);

            //same idea, but we add 0(low) and high((int)arr.size() - 1) parameters.
            //this is because the recursive function needs to know the current search space, which is defined by low and high.
            int idxR = binarySearchRecursive(arr, 0, (int)arr.size() - 1,
                                            targets[i], cmpR);   

            //linear search always searches the entire array.
            int idxL = linearSearch(arr, targets[i], cmpL);

            //print the results for the test case
            printResult(labels[i] ,targets[i], idxI,cmpI,idxR,cmpR, idxL, cmpL);
        }

}