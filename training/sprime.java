/*
ID: lgwong11
PROG: sprime
LANG: JAVA
*/
import java.io.*;
import java.util.*;

class sprime {
	public static void main (String [] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("sprime.in"));
		int i = Integer.parseInt((new StringTokenizer(f.readLine())).nextToken());
		Queue<Integer> nums = new LinkedList<>();
		nums.add(2); nums.add(3); nums.add(5); nums.add(7);
		for (int d = 1; d < i; d++) {
			int l = nums.size();
			for (int j = 0; j < l; j++) {
				int curr = nums.poll();
				for (int n = 1; n <= 9; n+=2) {
					if (isPrime(curr*10+n))
						nums.add(curr*10+n);
				}
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));
		while(nums.peek() != null)
			out.println(nums.poll());
		out.close();
	}
	
	public static boolean isPrime(int n) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
}
