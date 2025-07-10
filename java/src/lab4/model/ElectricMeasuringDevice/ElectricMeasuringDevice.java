package lab4.model.ElectricMeasuringDevice;

import lab4.model.AbstractDevice.Device;
import lab4.model.AbstractDevice.Dimensions;
import lab4.model.AbstractDevice.State;
import lab4.model.MeasuringDevice.AdditionalDetail;
import lab4.model.MeasuringDevice.MeasuringDevice;
import lab4.services.InputReader;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Scanner;

public class ElectricMeasuringDevice implements MeasuringDevice {
    private String name;
    private Dimensions dimensions;
    private ArrayList<AdditionalDetail> additionalDetails;
    private State state;
    private final String serialNumber;
    private final LocalDateTime createdAt;

    private double batteryCapacity;
    private PowerSupply power;

    public static final double FUNCTIONAL_BATTERY_CAPACITY = 80.0;
    public static int electricMeasuringDeviceCount = 0;

    public ElectricMeasuringDevice(
            String name,
            Dimensions dimensions,
            ArrayList<AdditionalDetail> additionalDetails,
            State state,
            PowerSupply power,
            double batteryCapacity
    ) {
        this.name = name;
        this.dimensions = dimensions;
        this.additionalDetails = additionalDetails;
        this.state = state;
        this.power = power;
        this.batteryCapacity = batteryCapacity;
        this.serialNumber = Device.SERIAL_PREFIX + (++electricMeasuringDeviceCount);
        this.createdAt = LocalDateTime.now();
    }

    // Factory method
    public static ElectricMeasuringDevice createFromInput(Scanner scanner) {
        String name = InputReader.promptString(scanner, "NAME", "Enter the name of device: ");
        Dimensions dimensions = InputReader.readDimensions(scanner);
        ArrayList<AdditionalDetail> additionalDetails = InputReader.readAdditionalDetails(scanner);
        State state = InputReader.readState(scanner);

        double voltage = InputReader.readPositiveDouble(scanner, "Enter voltage (V): ");
        double current = InputReader.readPositiveDouble(scanner, "Enter current (A): ");
        double frequency = InputReader.readPositiveDouble(scanner, "Enter frequency (Hz): ");
        PowerSupply power = new PowerSupply(voltage, current, frequency);

        double batteryCapacity = InputReader.readPositiveDouble(scanner, "Enter battery capacity: ");

        return new ElectricMeasuringDevice(name, dimensions, additionalDetails, state, power, batteryCapacity);
    }

    // Implementation of Device and MeasuringDevice interfaces

    @Override
    public String getName() {
        return name;
    }

    @Override
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public State getState() {
        return state;
    }

    @Override
    public void setState(State state) {
        this.state = state;
    }

    @Override
    public Dimensions getDimensions() {
        return dimensions;
    }

    @Override
    public void setDimensions(Dimensions dimensions) {
        this.dimensions = dimensions;
    }

    @Override
    public String getSerialNumber() {
        return serialNumber;
    }

    @Override
    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    @Override
    public boolean isOperational() {
        return batteryCapacity >= FUNCTIONAL_BATTERY_CAPACITY;
    }

    @Override
    public String getDeviceType() {
        return "Electric Measuring Device";
    }

    @Override
    public void printInfo() {
        System.out.println("=== Electric Measuring Device ===");
        System.out.println("- Name: " + name);
        System.out.println("- State: " + state);
        System.out.println("- Dimensions: " + dimensions);
        System.out.println("- Serial Number: " + serialNumber);
        System.out.println("- Created At: " + createdAt);
        System.out.println("- Power: " + power);
        System.out.println("- Battery Capacity: " + batteryCapacity + " mAh");
        System.out.println("- Is Operational: " + isOperational());
    }

    @Override
    public ArrayList<AdditionalDetail> getAdditionalDetails() {
        return additionalDetails;
    }

    @Override
    public void addAdditionalDetails(AdditionalDetail newDetail) {
        if (additionalDetails.size() < MAX_ADDITIONAL_DETAILS) {
            additionalDetails.add(newDetail);
        } else {
            System.out.println("[WARNING]: Maximum number of additional details reached.");
        }
    }

    // Extra getters/setters
    public PowerSupply getPower() {
        return power;
    }

    public void setPower(PowerSupply power) {
        this.power = power;
    }

    public double getBatteryCapacity() {
        return batteryCapacity;
    }

    public void setBatteryCapacity(double batteryCapacity) {
        this.batteryCapacity = batteryCapacity;
    }

    public static int getElectricMeasuringDeviceCount() {
        return electricMeasuringDeviceCount;
    }
}

