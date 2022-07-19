#include <iostream>

int numOfAddition = 0;
int* memoryArr;

int fibonacciIterative(int n)
{
    int b = 0, c = 1, a = 0;

    if (n <= 1) return n;
    else {
        for (int i = 2; i <= n; i++)
        {
            numOfAddition++;
            a = b + c;
            b = c;
            c = a;
        }
    }
    return a;
}

int fibonacciNaiveRecursive(int n) {


    if (n <= 1) {
        return n;
    }
    else {
        numOfAddition++;
        return fibonacciNaiveRecursive(n - 1) + fibonacciNaiveRecursive(n - 2);
    }
}

int fibonacciRecursiveWithMmorization(int n) {


    if (n <= 1) {
        return n;
    }

    else if (memoryArr[n - 1] != 0)
        return memoryArr[n - 1];
    else {
        numOfAddition++;
        return memoryArr[n - 1] = fibonacciRecursiveWithMmorization(n - 1) + fibonacciRecursiveWithMmorization(n - 2);
    }
   

}

int fibonacciTailRecursive(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    numOfAddition++;
    //std::cout << "n: " << n << " a: " << a << " b: " << b << std::endl;
    return fibonacciTailRecursive(n - 1, b, a + b);
}



int main() {
   
    int n=0;
    std::cout << "Enter number of element Fibonacci sequence: >>";
    std::cin >> n;
    std::cout << std::endl;

    int m = n;
    memoryArr = new int[m];
    for (int i = 0; i < m; i++)
    {
        memoryArr[i] = 0;
    }
    numOfAddition = 0;
    std::cout << "fibonacciIterative(" << n << ") = " << fibonacciIterative(n) << std::endl;
    std::cout << "The number of addition operations needed for the result: "<<numOfAddition << std::endl << std::endl;

    numOfAddition = 0;
    std::cout << "fibonacciNaiveRecursive" << n << ") = " << fibonacciNaiveRecursive(n) << std::endl;
    std::cout << "The number of addition operations needed for the result: " << numOfAddition << std::endl << std::endl;

    numOfAddition = 0;
    std::cout << "fibonacciRecursiveWithMmorization(" << n << ") = " << fibonacciRecursiveWithMmorization(n) << std::endl;
    std::cout << "The number of addition operations needed for the result: " << numOfAddition << std::endl << std::endl;
    delete[] memoryArr;

    numOfAddition = 0;
    std::cout << "fibonacciTailRecursive(" << n << ") = " << fibonacciTailRecursive(n) << std::endl;
    std::cout << "The number of addition operations needed for the result: " << numOfAddition << std::endl << std::endl;


    return 0;
}