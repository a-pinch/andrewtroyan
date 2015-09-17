using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;

namespace HTTPrequest
{
    class Program
    {
        static void Main(string[] args)
        {
            string url = @"http://jobs.tut.by/search/vacancy?text=&specialization=3&area=1002&salary=&currency_code=BYR&experience=doesNotMatter&order_by=relevance&search_period=30&items_on_page=20&no_magic=true";

            WebRequest request = WebRequest.Create(url);
            WebResponse response = request.GetResponse();

            Console.WriteLine(response.ContentType);

            response.Close();
            Console.ReadKey();
        }
    }
}
