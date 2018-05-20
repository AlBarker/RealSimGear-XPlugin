using RealSimGear.XPlugin;
using System;

namespace ArduinoTester
{
    class Program
    {
        static void Main(string[] args)
        {
            IDeviceController deviceController = new ArduinoController();

            Console.WriteLine("Trying to detect Arduino...");
            deviceController.SetComPort();
            Console.WriteLine("Detecting Arduino finished");
            Console.Read();

        }
    }
}
