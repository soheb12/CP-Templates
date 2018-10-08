import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class Main
{
    public static Scanner inp = new Scanner(System.in);
	public static boolean returnPrime(BigInteger number) 
	{
	    //check via BigInteger.isProbablePrime(certainty)
	    if (!number.isProbablePrime(5))
		return false;
	    //check if even
	    BigInteger two = new BigInteger("2");
	    if (!two.equals(number) && BigInteger.ZERO.equals(number.mod(two)))
		return false;
	    //find divisor if any from 3 to 'number'
	    for (BigInteger i = new BigInteger("3"); i.multiply(i).compareTo(number) < 1; i = i.add(two)) { //start from 3, 5, etc. the odd number, and look for a divisor if any
		if (BigInteger.ZERO.equals(number.mod(i))) //check if 'i' is divisor of 'number'
			return false;
	    }
	    return true;
	}

	public static void main (String[] args) throws java.lang.Exception
	{
	    int t;
	    t = inp.nextInt();
	    for(int i=0;i<t;i++)
	    {
	    BigInteger a = inp.nextBigInteger();
		BigInteger b = inp.nextBigInteger();
		a = a.multiply(a);
		b = b.multiply(b);
		a = a.subtract(b);
		if(returnPrime(a))
		System.out.println("YES");
		else
		System.out.println("NO");
	    }
	}
	
}
