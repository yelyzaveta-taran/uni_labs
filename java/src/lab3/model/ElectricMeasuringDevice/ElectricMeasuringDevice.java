package lab3.model.ElectricMeasuringDevice;

import lab3.model.AbstractDevice.State;
import lab3.model.MeasuringDevice.AdditionalDetail;
import lab3.model.AbstractDevice.Dimensions;
import lab3.model.MeasuringDevice.MeasuringDevice;
import lab3.services.InputReader;

import java.util.ArrayList;
import java.util.Scanner;

public class ElectricMeasuringDevice extends MeasuringDevice {
    // Private fields
    private double batteryCapacity;
    private PowerSupply power;

    // Private static fields
    private static final double FUNCTIONAL_BATTERY_CAPACITY = 80.0;
    private static int ElectricMeasuringDeviceCount;

    public ElectricMeasuringDevice(String name, Dimensions dimensions, ArrayList<AdditionalDetail> additionalDetails, State state, PowerSupply power, double batteryCapacity) {
        super(name, dimensions, additionalDetails, state);
        this.power = power;
        this.batteryCapacity = batteryCapacity;

        ElectricMeasuringDeviceCount++;
    }

    // Factory method to create from input
    public static ElectricMeasuringDevice createFromInput(Scanner scanner) {
        MeasuringDevice base = MeasuringDevice.createFromInput(scanner);

        double voltage = InputReader.readPositiveDouble(scanner, "Enter voltage (V): ");
        double current = InputReader.readPositiveDouble(scanner, "Enter current (A): ");
        double frequency = InputReader.readPositiveDouble(scanner, "Enter frequency (Hz): ");

        PowerSupply power = new PowerSupply(voltage, current, frequency);

        double capacity = InputReader.readPositiveDouble(scanner, "Enter battery capacity: ");

        return new ElectricMeasuringDevice(
                base.getName(),
                base.getDimensions(),
                new ArrayList<>(base.getAdditionalDetails()),
                base.getState(),
                power,
                capacity
        );
    }

    // Getters and setters
    public PowerSupply getPower() {
        return power;
    }

    public void setPower(PowerSupply power) {
        this.power = power;
        System.out.println("[INFO]: The power value was updated.");
    }

    public double getBatteryCapacity() {
        return batteryCapacity;
    }

    public void setBatteryCapacity(double batteryCapacity) {
        this.batteryCapacity = batteryCapacity;
        System.out.println("[INFO]: The battery capacity was updated.");
    }


    // Overridden methods
    @Override
    public boolean isOperational() {
        return getState() == State.FUNCTIONING && batteryCapacity >= FUNCTIONAL_BATTERY_CAPACITY;
    }

    @Override
    public String getDeviceType() {
        return "Electric Measuring Device";
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Power Supply: ");
        System.out.println("  " + power);
        System.out.println("Battery Capacity: " + batteryCapacity + " mAh");
    }


    @Override
    public String toString() {
        return super.toString().replace("}", "  power=" + power + "\n}");
    }
}
