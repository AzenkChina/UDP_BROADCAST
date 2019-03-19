using System;
using System.Linq;

using COMM_SOCKET;

namespace TEST
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] Buff1 = Enumerable.Repeat((byte)0x30, 16).ToArray();
            byte[] Buff2 = new byte[16];

            //实例化接收器
            CommReceiver Receiver = new CommReceiver(20002);

            //实例化发送器
            CommEmitter Emitter = new CommEmitter(20002);

            //发送数据
            Emitter.Send(ref Buff1, Buff1.Length);

            //清空接收数组,接收数据
            Array.Clear(Buff2, 0, Buff2.Length);
            Receiver.Receive(ref Buff2, Buff2.Length);

            //打印接收到的数据
            string String = BitConverter.ToString(Buff2, 0);
            Console.WriteLine(String);

            Console.ReadLine();
        }
    }
}
