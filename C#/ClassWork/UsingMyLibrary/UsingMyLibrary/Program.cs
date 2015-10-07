using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace UsingMyLibrary
{
    class Program
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate int MultiplyByTen(int numberToMultiply);

        static void Main(string[] args)
        {
            IntPtr myLibrary = MyLibraryMethods.LoadLibrary("MyLibrary.dll");
            IntPtr procAddress = MyLibraryMethods.GetProcAddress(myLibrary, "MultiplyByTen");
            MultiplyByTen multiplyByTen = (MultiplyByTen)Marshal.GetDelegateForFunctionPointer(procAddress, typeof(MultiplyByTen));
            int result = multiplyByTen(112);

            MyLibraryMethods.FreeLibrary(myLibrary);
            Console.WriteLine(result);

            MyLibraryMethods.MessageBox(default(IntPtr), "MessageBox via WINAPI", "Hello!", 1);

            Console.WriteLine(default(IntPtr));
            Console.ReadKey();
        }
    }
}
