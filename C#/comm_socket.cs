using System.Net.Sockets;
using System.Net;

namespace COMM_SOCKET
{
    class CommReceiver
    {
        public CommReceiver(int Port)
        {
            Receiver = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            IPEndPoint EndPoint = new IPEndPoint(IPAddress.Any, Port);
            Receiver.Bind(EndPoint);
            Receiver.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 1);
        }

        ~CommReceiver()
        {
            Receiver.Close();
        }

        private Socket Receiver;

        public int Receive(ref byte[] Buffer, int BufferLength)
        {
            IPEndPoint EP = new IPEndPoint(IPAddress.Any, 0);
            EndPoint ep = EP;
            return Receiver.ReceiveFrom(Buffer, BufferLength, 0, ref ep);
        }
    };


    class CommEmitter
    {
        public CommEmitter(int Port)
        {
            Emitter = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            EndPoint = new IPEndPoint(IPAddress.Broadcast, Port);
            Emitter.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.Broadcast, true);
            Emitter.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout, 1);
        }

        public CommEmitter(string IPaddr, int Port)
        {
            Emitter = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            EndPoint = new IPEndPoint(IPAddress.Parse(IPaddr), Port);
        }

        ~CommEmitter()
        {
            Emitter.Close();
        }

        private Socket Emitter;
        private IPEndPoint EndPoint;

        public int Send(ref byte[] Buffer, int Length)
        {
            return Emitter.SendTo(Buffer, Length, 0, EndPoint);
        }
    };
}
