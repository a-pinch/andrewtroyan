using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.Collections;

namespace ExtensionMethods
{
    public static class MyExtensions
    {
        public static bool GreaterThan(this string a, string b)
        {
            return a.Length > b.Length;
        }

        public static bool LessThan(this string a, string b)
        {
            return a.Length < b.Length;
        }

        public static string Implode<T>(this IEnumerable<T> storage)
        {
            string result = "";
            var iterator = storage.GetEnumerator();

            while (iterator.MoveNext())
            {
                result += iterator.Current + " ";
            }

            return result;
        }

        public static string ToJSON<TKey, TValue>(this IDictionary<TKey, TValue> storage)
        {
            string result = "{ ";
            var iterator = storage.GetEnumerator();

            if (iterator.MoveNext())
            {
                result += "\"" + iterator.Current.Key + "\" : \"" + iterator.Current.Value + "\"";

                while (iterator.MoveNext())
                {
                    result += ", \"" + iterator.Current.Key + "\" : \"" + iterator.Current.Value + "\"";
                }
            }

            result += " }";

            return result;
        }

        public static string ToJSON<T>(this T obj)
        {
            if (obj is int || obj is string || obj is float || obj is double)
            {
                return obj.ToString();
            }
            else if (obj is IEnumerable)
            {
                return EnumerableToJSON((IEnumerable)obj);
            }
            else
            {
                return CommonToJSON(obj);
            }
        }

        private static string EnumerableToJSON(IEnumerable storage)
        {
            string result = "[ ";
            var iterator = storage.GetEnumerator();

            if (iterator.MoveNext())
            {
                result += iterator.Current;

                while (iterator.MoveNext())
                {
                    result += ", " + iterator.Current;
                }
            }

            result += " ]";

            return result;
        }

        private static string CommonToJSON<T>(T obj)
        {
              string result = "{ ";
              bool firstValue = true;

              var fields = typeof(T).GetFields();

              if (fields.Length != 0)
              {
                  result += "\"" + fields[0].Name + "\" : \"" + fields[0].GetValue(obj) + "\"";
                  firstValue = false;

                  for (int i = 1; i < fields.Length; ++i)
                  {
                      result += ", \"" + fields[0].Name + "\" : \"" + fields[0].GetValue(obj) + "\"";
                  }
              }

              var properties = typeof(T).GetProperties();

              if (properties.Length != 0)
              {
                  if (firstValue)
                  {
                      result += "\"" + properties[0].Name + "\" : \"" + properties[0].GetValue(obj) + "\"";
                      firstValue = false;
                  }

                  for (int i = firstValue ? 0 : 1; i < fields.Length; ++i)
                  {
                      result += ", \"" + properties[0].Name + "\" : \"" + properties[0].GetValue(obj) + "\"";
                  }
              }

              result += " }";

              return result;
        }
    }
}
