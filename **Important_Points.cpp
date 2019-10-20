
->n is Fibonacii number if : 5*n*n+4 or 5*n*n-4 is a perfect square
->Find nth Fibonacci : f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)       //n is even n = 2*k
                     f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)   //n is odd and n = 2*k + 1
->Goldbachs Conjecture
->if(isp(n))//prime has a factor of 1
        cout<<1<<endl;
    else if(n%2 == 0)//even number can be expressed as sum of 2 primes (goldbachs conjecture
        cout<<2<<endl;
    else if(isp(n-2))//for odd numbers if (n-2) is prime then it can be expressed as sum of two primes
        cout<<2<<endl;
    else 
        cout<<3<<endl;//3 + (n-3) here n-3 is even which can be expressed as sum of two primes  

->Thought process
* Think about how to reduce the number of combinations in the input, by solving different combinations differently.
* If you get a brute force DP solution for a problem then for larger constraints try to look for a pattern in dp values.
