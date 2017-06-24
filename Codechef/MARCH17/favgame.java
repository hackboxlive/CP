import java.io.*;
import java.util.*;
class node	{
	int day,hrs,skip;
}
class favgame	{
	static int inf=1000000000;
	static int n,h;
	static int tl[] = new int[1100];
	static int tree[][] = new int[1100][11];
	static int child[] = new int[1100];
	static int day_dp[][][] = new int[25][1010][1050];
	static int hrs_dp[][][] = new int[25][1010][1050];
	static int skip[][][] = new int[25][1010][1050];
    static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
	static node solve_dp(int t,int src,int mask)	{
		node tempx = new node();
		if(day_dp[t][src][mask]!=-1)	{
			tempx.day = day_dp[t][src][mask];
			tempx.hrs = hrs_dp[t][src][mask];
			tempx.skip = skip[t][src][mask];
			return tempx;
		}
		if(child[src] == 0)	{
			if(t>=tl[src])	{
				tempx.day = day_dp[t][src][mask] = 0;
				tempx.hrs = hrs_dp[t][src][mask] = t - tl[src];
				tempx.skip = skip[t][src][mask] = 0;
				return tempx;
			}
			else	{
				tempx.day = day_dp[t][src][mask] = 1;
				tempx.hrs = hrs_dp[t][src][mask] = h - tl[src];
				tempx.skip = skip[t][src][mask] = t;
				return tempx;
			}
		}
		if(mask == (1<<child[src])-1)	{
			tempx.day = day_dp[t][src][mask] = 0;
			tempx.hrs = hrs_dp[t][src][mask] = t;
			tempx.skip = skip[t][src][mask] = 0;
			return tempx;
		}
		int ans = inf, mint = 0 , skipans = inf, rem = t, flag = 0, flagskip = 0, v;
		if(mask == 0)	{
			if(rem >= tl[src])	{
				rem = rem - tl[src];
			}
			else	{
				flag = 1;
				flagskip = rem;
				rem = h - tl[src];
			}
		}
		int cc = child[src];
		node tempy = new node();
		for(int j = 0 ; j < cc ; ++j)	{
			v = tree[src][j];
			if((mask & (1<<j)) == 0)	{
				tempx = favgame.solve_dp(rem,v,0);
				if(tempx.skip + flagskip > skipans)	{
					continue;
				}
				tempy =favgame.solve_dp(tempx.hrs,src,mask | (1<<j));
				if(tempx.day + tempy.day + flag < ans)	{
					ans = tempx.day + tempy.day + flag;
					mint = tempy.hrs;
					skipans = tempx.skip + tempy.skip + flagskip;
				}
				else if(tempx.day + tempy.day + flag == ans)	{
					if(mint < tempy.hrs)	{
						mint = tempy.hrs;
						skipans = tempx.skip + tempy.skip + flagskip;
					}
				}
				if(skipans == 0)	{
					break;
				}
			}
		}
		tempx.day = day_dp[t][src][mask] = ans;
		tempx.skip = skip[t][src][mask] = skipans;
		tempx.hrs = hrs_dp[t][src][mask] = mint;
		return tempx;
	}
	public static void main(String args[])throws Exception	{
//		Scanner in = new Scanner(System.in);
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Reader in = new Reader();
		int t,u,x;
		t = in.nextInt();
		while(t-- > 0)	{
			n = in.nextInt();
			h = in.nextInt();
			for(int i = 1 ; i <= n ; ++i)	{
				tl[i] = in.nextInt();
			}
			for(int i = 1 ; i <= n ; ++i)	{
				x = in.nextInt();
				child[i] = x;
				for(int j = 0 ; j < x ; ++j)	{
					u = in.nextInt();
					tree[i][j]=u;
				}
			}
			for(int i = 0 ; i <= h; ++i)	{
				for(int j = 1 ; j <= n ; ++j)	{
					Arrays.fill(day_dp[i][j],-1);
				}
			}
			node ans = new node();
			ans = favgame.solve_dp(h,1,0);
			System.out.println(1+ans.day);
		}
	}
}