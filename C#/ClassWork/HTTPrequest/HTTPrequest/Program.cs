﻿using System;
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
            // creating webclient for connection and downloading html pages
            WebClient client = new WebClient();
            string page;

            HtmlWorkingOnSalary converter = new HtmlWorkingOnSalary(17720, 19950);

            // regular expression that checks currency type and amount of money
            Regex regexForSalary = new Regex(@"<meta itemprop=""salaryCurrency"" content=""[A-Z]+""><meta itemprop=""baseSalary"" content=""\d+"">");
            MatchCollection matchedValuesWithSalaries;

            using (StreamWriter file = new StreamWriter("..\\..\\salaries.csv"))
            {
                int currentPageIndex = 0;
                int salary = 0;
                bool isLastPage = false;

                while (isLastPage == false)
                { 
                    // getting html page
                    page = client.DownloadString(uri + currentPageIndex);
                    matchedValuesWithSalaries = regexForSalary.Matches(page);

                    // retrieving salaries in BYR from all matched values and writing them to the file
                    foreach (Match matchedValue in matchedValuesWithSalaries)
                    {
                        salary = converter.GetSalaryInBYR(matchedValue.Value);

                        // there's posibility that current salary is per a day or a week
                        // so we write salaries per month only to the file
                        if (salary >= 1000000)
                        {
                            file.WriteLine(converter.GetSalaryInBYR(matchedValue.Value));
                        }
                    }

                    // checking if current page is last
                    isLastPage = HtmlWorkingOnSalary.IsPageLast(page);
                    ++currentPageIndex;
                }
            }

            Console.ReadKey();
        }
    }
}
