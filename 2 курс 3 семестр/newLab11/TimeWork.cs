using LibraryLab10;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace newLab11
{
    public class TimeWork
    {
        public static string OrganizationQueue<T>(Queue<T> queue, T org)
        {
            var stopWatch = Stopwatch.StartNew();
            var flag = queue.Contains(org);
            stopWatch.Stop();
            return stopWatch.ElapsedTicks.ToString() + $" Заданный объект найден: {flag}";
        }
        public static string DictionaryOrgKey<TKey>(SortedDictionary<TKey, Library> sortedDict, TKey key)
        {
            var stopWatch = Stopwatch.StartNew();
            var flag = sortedDict.ContainsKey(key);
            stopWatch.Stop();
            return stopWatch.ElapsedTicks.ToString() + $" Заданный объект найден:{flag} ";
        }
        public static string DictionaryOrgValue(SortedDictionary<string, Library> sortedDict, Library value)
        {
            var stopWatch = Stopwatch.StartNew();
            var flag = sortedDict.ContainsValue(value);
            stopWatch.Stop();
            return stopWatch.ElapsedTicks.ToString() + $" Заданный объект найден:{flag} ";
        }
    }
}
