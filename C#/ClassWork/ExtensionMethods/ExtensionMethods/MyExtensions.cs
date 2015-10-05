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

        public static string ToJSON<T>(this T obj)
        {
            if (obj is int || obj is string || obj is float || obj is double)
            {
                return obj.ToString();
            }
            else if (obj is IDictionary)
            {
                return DictionaryToJSON((IDictionary)obj);
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

        private static string DictionaryToJSON(IDictionary storage)
        {
            string result = "{ ";
            var iterator = storage.GetEnumerator();

            if (iterator.MoveNext())
            {
                result += "\"" + iterator.Key + "\" : \"" + iterator.Value + "\"";

                while (iterator.MoveNext())
                {
                    result += ", \"" + iterator.Key + "\" : \"" + iterator.Value + "\"";
                }
            }

            result += " }";

            return result;
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
                  result += "\"" + fields[0].Name + "\" : \"" + fields[0].GetValue(obj).ToJSON() + "\"";
                  firstValue = false;

                  for (int i = 1; i < fields.Length; ++i)
                  {
                      result += ", \"" + fields[i].Name + "\" : \"" + fields[i].GetValue(obj).ToJSON() + "\"";
                  }
              }

              var properties = typeof(T).GetProperties();

              if (properties.Length != 0)
              {
                  bool fromStart = true;

                  if (firstValue)
                  {
                      result += "\"" + properties[0].Name + "\" : \"" + properties[0].GetValue(obj).ToJSON() + "\"";
                      fromStart = false;
                  }

                  for (int i = fromStart ? 0 : 1; i < properties.Length; ++i)
                  {
                      result += ", \"" + properties[i].Name + "\" : \"" + properties[i].GetValue(obj).ToJSON() + "\"";
                  }
              }

              result += " }";

              return result;
        }
    }
}
