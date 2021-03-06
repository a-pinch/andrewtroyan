﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace HTTPrequest
{
    // - retrieves salary from html page and converts to BYR
    // - checks if given page is last on website

    class HtmlWorkingOnSalary
    {
        // non-static fields

        // for convertions
        private int indexFromUSDtoBYR, indexFromEURtoBYR;

        // properties

        public int IndexFromUSDtoBYR
        {
            get { return indexFromUSDtoBYR; }

            set
            {
                if (value <= 0)
                {
                    throw new ArgumentOutOfRangeException("In HtmlWorkingOnSalary.IndexFromUSDtoBYR: wrong value!");
                }
                indexFromUSDtoBYR = value;
            }
        }

        public int IndexFromEURtoBYR
        {
            get { return indexFromEURtoBYR; }

            set
            {
                if (value <= 0)
                {
                    throw new ArgumentOutOfRangeException("In HtmlWorkingOnSalary.IndexFromEURtoBYR: wrong value!");
                }
                indexFromEURtoBYR = value;
            }
        }

        // constructor

        public HtmlWorkingOnSalary(int indexFromUSDtoBYR_, int indexFromEURtoBYR_)
        {
            IndexFromUSDtoBYR = indexFromUSDtoBYR_;
            IndexFromEURtoBYR = indexFromEURtoBYR_;
        }

        // non-static methods
        
        public int GetSalaryInBYR(string htmlString)
        {
            Regex matching = new Regex(@"<meta itemprop=""salaryCurrency"" content=""");
            htmlString = matching.Replace(htmlString, "");

            int endOfIndex = htmlString.IndexOf("\"");
            string indexString = htmlString.Substring(0, endOfIndex);

            // retrieving salary
            matching = new Regex(@"[A-Z]+""><meta itemprop=""baseSalary"" content=""");
            htmlString = matching.Replace(htmlString, "");

            int endOfSum = htmlString.IndexOf("\"");
            string sumString = htmlString.Substring(0, endOfSum);
            int sumInt = Int32.Parse(sumString);

            int resultSum;

            // converting to BYR
            switch (indexString)
            {
                case "USD":
                    resultSum = sumInt * IndexFromUSDtoBYR;
                    break;

                case "EUR":
                    resultSum = sumInt * IndexFromEURtoBYR;
                    break;

                default:
                    resultSum = sumInt;
                    break;
            }

            return resultSum;
        }

        // static methods

        public static bool IsPageLast(string htmlString)
        {
            // starting to look from right to left (second parameter in Regex constructor) because "last-page" tag is located at the end
            // of a page
            Regex regex = new Regex(@"<span class=""b-pager__next-text"" data-qa=""pager-next-disabled"">", RegexOptions.RightToLeft);

            return regex.IsMatch(htmlString);
        }
    }
}
