package lab3;

import lab3.model.AbstractDevice.AbstractDevice;
import lab3.model.ElectricMeasuringDevice.ElectricMeasuringDevice;
import lab3.model.MeasuringDevice.MeasuringDevice;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MeasuringDevice device1 = MeasuringDevice.createFromInput(scanner);

        System.out.println("The device1 serial number: " + device1.getSerialNumber());
        System.out.println("The device1 creation date: " + device1.getCreatedAt());
        System.out.println("The device1 type: " + device1.getDeviceType());
        System.out.println("The device1 operational state: " + device1.isOperational());

        device1.printInfo();

        ElectricMeasuringDevice device2 = ElectricMeasuringDevice.createFromInput(scanner);

        System.out.println("The device1 serial number: " + device2.getSerialNumber());
        System.out.println("The device1 creation date: " + device2.getCreatedAt());
        System.out.println("The device1 type: " + device2.getDeviceType());
        System.out.println("The device1 operational state: " + device2.isOperational());

        device2.printInfo();
    }
}
