using System;
using System.Threading;
using System.IO.Ports;

namespace RealSimGear.XPlugin
{
    public class ArduinoController : IDeviceController
    {

        SerialPort currentPort;
        bool portFound;
        public void SetComPort()
        {
            try
            {
                string[] ports = SerialPort.GetPortNames();
                foreach (string port in ports)
                {
                    currentPort = new SerialPort(port, 9600);
                    if (DetectArduino())
                    {
                        portFound = true;
                        Console.WriteLine("Arduino found!");
                        break;
                    }
                    else
                    {
                        portFound = false;
                    }
                }

                if (!portFound)
                    Console.WriteLine("Could not find Arduino");
            }
            catch (Exception e)
            {
            }
        }
        private bool DetectArduino()
        {
            try
            {
                //The below setting are for the Hello handshake
                byte[] buffer = new byte[5];
                buffer[0] = Convert.ToByte(16);
                buffer[1] = Convert.ToByte(128);
                buffer[2] = Convert.ToByte(0);
                buffer[3] = Convert.ToByte(0);
                buffer[4] = Convert.ToByte(4);
                int intReturnASCII = 0;
                char charReturnValue = (Char)intReturnASCII;
                currentPort.Open();
                currentPort.Write(buffer, 0, 5);
                Thread.Sleep(1000);
                int count = currentPort.BytesToRead;
                string returnMessage = "";
                while (count > 0)
                {
                    intReturnASCII = currentPort.ReadByte();
                    returnMessage = returnMessage + Convert.ToChar(intReturnASCII);
                    count--;
                }
                //currentPort.name = returnMessage;
                currentPort.Close();
                if (returnMessage.Contains("0"))
                {
                    Console.WriteLine("Arduino says: " + returnMessage);
                    return true;
                }
                else
                {
                    return false;
                }
            }
            catch (Exception e)
            {
                return false;
            }
        }
    }
}