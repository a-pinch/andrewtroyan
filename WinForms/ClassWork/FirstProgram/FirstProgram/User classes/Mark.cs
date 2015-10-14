using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstProgram
{
    class Mark
    {
        public enum Ground { homework, board, controlwork };

        public int pupilId;
        public Ground ground;

        public Mark(int pupilId_, Ground ground_)
        {
            pupilId = pupilId_;
            ground = ground_;
        }
    }
}
