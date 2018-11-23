#include <bits/stdc++.h>
using namespace std;

class Solution	{
public:
	int lengthLongestPath(string input)	{
		if(input.length() == 0)	{
			return 0;
		}
		int maxx = 0;
		input += '\n';
		for(int i = 0; i < input.length(); i++)	{
			if(input[i] == '\n')	{
				maxx++;
			}
		}
		vector<int> atLevel(maxx);
		int ans = 0, prev = 0;
		string temp = "";
		for(int i = 0; i < input.length(); i++)	{
			if(input[i] != '\n')	{
				temp += input[i];
			}
			else	{
				int depth = 0;
				for(int j = 0; j < temp.length(); j++)	{
					if(temp[j] == '\t')	{
						depth++;
					}
					else	{
						break;
					}
				}
				if(depth == 0)	{
					atLevel[depth] = temp.length() - depth;
				}
				else	{
					atLevel[depth] = temp.length() - depth + atLevel[depth - 1] + 1;
				}
				for(int j = 0; j < temp.length(); j++)	{
					if(temp[j] == '.')	{
						ans = max(ans, atLevel[depth]);
						break;
					}
				}
				//cout << temp << endl;
				temp = "";
			}
		}
		return ans;
	}
};

int main()	{
	Solution ob;
	string inp = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout << ob.lengthLongestPath(inp) << endl;
	return 0;
}