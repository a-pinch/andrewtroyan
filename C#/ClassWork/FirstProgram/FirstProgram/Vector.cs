using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstProgram
{
    class Vector
    {
        // non-static fields
        private int x, y, z;

        // constructor
        public Vector(int x_, int y_, int z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        // non-static methods
        public Vector VectorMultiply(Vector operand)
        {
            int x_temp = this.x, y_temp = this.y, z_temp = this.z;
            this.x = y_temp * operand.z - z_temp * operand.y;
            this.y = x_temp * operand.z - z_temp * operand.x;
            this.z = x_temp * operand.y - y_temp * operand.x;
            return this;
        }

        public int ScalarMultiply(Vector operand)
        {
            int result;
            result = this.x * operand.x + this.y * operand.y + this.z * operand.z;
            return result;
        }

        public void Print()
        {
            Console.WriteLine("x = " + this.x + ", y = " + this.y + ", z = " + this.z);
        }

        // static methods
        public static Vector VectorMultiply(Vector operand_1, Vector operand_2)
        {
            int x_res, y_res, z_res;
            x_res = operand_1.y * operand_2.z - operand_1.z * operand_2.y;
            y_res = operand_1.x * operand_2.z - operand_1.z * operand_2.x;
            z_res = operand_1.x * operand_2.y - operand_1.y * operand_2.x;
            return new Vector(x_res, y_res, z_res);
        }

        public static int ScalarMultiply(Vector operand_1, Vector operand_2)
        {
            int result;
            result = operand_1.x * operand_2.x + operand_1.y * operand_2.y + operand_1.z * operand_2.z;
            return result;
        }
    }
}
