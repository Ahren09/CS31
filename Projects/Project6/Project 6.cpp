#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;
/*
void removeS(char ch[]){
    int index=0;
    while(*ch!='\0'){
        if(tolower(*ch)=='s'){
            index++;
        }
        else{
            *(ch-index)=*ch;
        }
        ch++;
    }
    *(ch-index)='\0';
}

int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}
*/
/*
//4.
int* maxwell(int* a, int* b)
{
    if (*a > *b)
        return a;
    else
        return b;
}

void swap1(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[6] = { 5, 3, 4, 17, 22, 19 };
    
    int* ptr = maxwell(array, &array[2]);
    *ptr = -1;
    ptr += 2;
    ptr[1] = 9;
    *(array+1) = 79;
    
    cout << &array[5] - ptr << endl;
    
    swap1(&array[0], &array[1]);
    swap2(array, &array[2]);
    
    int i=0;
    while(i<6){
         cout << *array << endl;
        array++;
    }
    
    cout<<"surprise: "<<array[0];
}
*/

/*

double mean(const double* scores, int numScores)
{
    int i=0;
    double tot = 0;
    while (i != numScores)
    {
        tot += *(scores+i);
        i++;
    }
    return tot/numScores;
}
 
/* //3.b
const char* findTheChar(const char* str, char chr)
{
    for (int k = 0; *(str+k) != 0; k++)
        if (*(str+k) == chr)
            return &str[k];
    
    return nullptr;
}
*/

/* //3.c
const char* findTheChar(char* str, char chr)
{
    
    while(*str!=0){ // Same as while(*str!='\0')
        if (*str == chr)
            return str;
        str++;
    }
    return nullptr;
}

int main()
{
    double scores[]={0.0,1.0,2.0,3.0,4.0};
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<<mean(scores,5)<<endl;
    char ch[]="yeap";
    cout<<findTheChar(ch, 'e');
}

*/
/*
int main()
{
    
    double* cat = new double;
    
    double mouse[5];
    
    cat = mouse+4;
    
    *cat = 25;
    
    *(mouse+3) = 42;
    
    cat -=3;
    
    cat[1]=27;
    
    cat[0]=54;
    
    bool* b = new bool(*cat == *(cat+1));
    
    bool* d = new bool(cat==mouse);
    
    
}
 
 */



int* nochange(int* p)
{
    return p;
}

int* getPtrToArray(int& m)
{
    int anArray[100];
    for (int j = 0; j < 100; j++)
        anArray[j] = 100-j;
    m = 100;
    return nochange(anArray);
}

void f()
{
    int junk[100];
    for (int k = 0; k < 100; k++)
        junk[k] = 123400000 + k;
    junk[50]++;
}

int main()
{
    int n;
    int* ptr = getPtrToArray(n);
    cout<<*(ptr+1);
    f();
    for (int i = 0; i < 3; i++)
        cout << ptr[i] << ' ';
    for (int i = n-3; i < n; i++)
        cout << ptr[i] << ' ';
    cout << endl;
}

/*
bool strequal(char str1[], char str2[])
{
    while (*str1 != 0  &&  *str2 != 0)
    {
        if (*str1 != *str2)  // compare corresponding characters
            return false;
        str1++;            // advance to the next character
        str2++;
    }
    return *str1==*str2; // both ended at same time?
    
}

int main()
{
    char a[15] = "Zhou";
    char b[15] = "Zhou";
    
    if (strequal(a,b))
        cout << "They're the same person!\n";
    
}
*/

/*
void computeCube(int n, int* ncubed)
{
    *ncubed = n * n * n;
}

int main()
{
    int* ptr=new int;
    
    computeCube(5, ptr);
    
    cout << "Five cubed is " << *ptr << endl;
    int *a = new int(5);
    cout<<*a;
}
*/
 
/*
void findMax(int arr[], int n, int* &pToMax)
{
    if (n <= 0)
        return;      // no items, no maximum!
    
   pToMax = arr;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *pToMax)
            pToMax = arr + i;
    }
}

int main()
{
    int nums[4] = { 5, 3, 15, 6 };
    int* ptr;
    
    findMax(nums, 4, ptr);
    cout << "The maximum is at address " << ptr << endl;
    cout << "It's at position " << ptr - nums << endl;
    cout << "Its value is " << *ptr << endl;
}
*/

/*
int main()
{
    int arr[3] = { 5, 10, 15 };
    int* ptr = arr;
    
    *ptr = 30;          // set arr[0] to 30
    *(ptr + 1) = 20;      // set arr[1] to 20
    ptr += 2;
    *ptr= 10;        // set arr[2] to 10
    // OR: ptr[0] = 10;
    ptr-=2;
    while (ptr < arr+3)
    {
        cout << *ptr << endl;    // print values
        ptr++;
    }
}
*/
