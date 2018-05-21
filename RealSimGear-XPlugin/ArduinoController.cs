using System;
using System.Threading;
using System.IO.Ports;

namespace RealSimGear.XPlugin
{
    public class ArduinoController : IDeviceController
    {
        static SerialPort currentPort;
        bool portFound;
        static bool _continue;

        #region Exposed Methods
        public void InitiateConnection()
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

        public void BeginReading()
        {
            string name;
            string message;
            StringComparer stringComparer = StringComparer.OrdinalIgnoreCase;
            Thread readThread = new Thread(Read);

            if (currentPort == null || !portFound)
            {
                throw new NullReferenceException("Port has not been initialised");
            }

            currentPort.Open();
            _continue = true;
            readThread.Start();

            while (_continue)
            {
                message = Console.ReadLine();

                if (stringComparer.Equals("quit", message))
                {
                    _continue = false;
                }
                else
                {
                    currentPort.WriteLine(
                        String.Format("<{0}>: {1}", message));
                }
            }

            readThread.Join();
            currentPort.Close();
        }
        #endregion

        private static void Read()
        {
            while (_continue)
            {
                try
                {
                    string message = currentPort.ReadLine();
                    Console.WriteLine(message);
                    PluginAdapter.SendXplaneCommand(message);
                }
                catch (TimeoutException)
                {

                }
            }
        }
        
        #region Helper Methods
        private bool DetectArduino()
        {
            // TODO add some sort of connection handshake
            return true;
        }
        #endregion
    }
}