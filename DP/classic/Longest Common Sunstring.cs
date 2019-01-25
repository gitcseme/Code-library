using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/* Longest Common Substring */

namespace DevSkill_Problems
{
    class DCP_29
    {
        static void Main()
        {
            int[,] dp = new int[105, 105];
            for (int i = 0; i <= 101; i++) dp[0,i] = dp[i,0] = 0;

            int t = int.Parse(Console.ReadLine());
            StringBuilder sb;
            for (int caseno = 1; caseno <= t; caseno++)
            {
                string[] s = Console.ReadLine().Split(' ');
                string a = new StringBuilder(s[0]).Insert(0, '$').ToString();
                string b = new StringBuilder(s[1]).Insert(0, '@').ToString();

                

                int m = a.Length;
                int n = b.Length;

                int mx = 0;

                for (int i = 1; i < m; i++)
                {
                    for (int j = 1; j < n; j++)
                    {
                        if (a[i] == b[j])
                            dp[i, j] = 1 + dp[i - 1, j - 1];
                        else
                            dp[i, j] = 0;

                        if (dp[i, j] > mx) mx = dp[i, j];
                    }
                }

                Console.WriteLine("Case {0}: {1}", caseno, mx);
            }
        }
    }
}
