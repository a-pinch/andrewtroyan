using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;
using System.Text.RegularExpressions;

namespace HTTPrequest
{
    class Program
    {
        static void Main(string[] args)
        {
            string uri = @"http://jobs.tut.by/search/vacancy?specialization=1&area=1002&enable_snippets=true&no_magic=true&clusters=true&search_period=30&currency_code=BYR&page=";
            WebClient client = new WebClient();
            string page;

            HtmlWorkingOnSalary converter = new HtmlWorkingOnSalary(17720, 19950);

            Regex regexForSalary = new Regex(@"<meta itemprop=""salaryCurrency"" content=""[A-Z]+""><meta itemprop=""baseSalary"" content=""\d+"">");
            MatchCollection matchedValuesWithSalaries;

            using (StreamWriter file = new StreamWriter("..\\..\\salaries.csv"))
            {
                int currentPageIndex = 0;
                bool isLastPage = false;

                while (isLastPage == false)
                { 
                    page = client.DownloadString(uri + currentPageIndex);
                    matchedValuesWithSalaries = regexForSalary.Matches(page);

                    foreach (Match matchedValue in matchedValuesWithSalaries)
                    {
                        file.WriteLine(converter.GetSalaryInBYR(matchedValue.Value));
                    }

                    isLastPage = HtmlWorkingOnSalary.IsPageLast(page);
                    ++currentPageIndex;
                }
            }

            Console.ReadKey();
        }
    }
}
