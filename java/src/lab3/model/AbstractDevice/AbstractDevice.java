package lab3.model.AbstractDevice;

import java.time.LocalDateTime;
import java.util.UUID;

public abstract class AbstractDevice {
    // Protected instance fields that are present in all types of devices
    protected String name;
    protected State state;
    protected Dimensions dimensions;

    // Protected final instance fields that are present in all types of devices
    protected final String serialNumber = UUID.randomUUID().toString();
    protected final LocalDateTime createdAt = LocalDateTime.now();

    // Static variable
    protected static int deviceCount = 0;

    // Constructor
    public AbstractDevice(String name, State state, Dimensions dimensions) {
        this.name = name;
        this.state = state;
        this.dimensions = dimensions;
        // Incrementing device count every time the instance is created
        deviceCount++;
    }

    // Getters and Setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
        System.out.println("[INFO]: The name value was updated.");
    }

    public State getState() {
        return state;
    }

    public void setState(State state) {
        this.state = state;
        System.out.println("[INFO]: The state value was updated.");
    }

    public Dimensions getDimensions() { return dimensions; }

    public void setDimensions(Dimensions dimensions) {
        this.dimensions = dimensions;
        System.out.println("[INFO]: The dimensions object was updated.");
    }

    public String getSerialNumber() {
        return serialNumber;
    }
    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    // Static methods
    public static int getDeviceCount() {
        return deviceCount;
    }
    public static void printClassInfo() {
        System.out.println("AbstractDevice class — base class for all measuring devices.");
        System.out.println("Total devices created: " + deviceCount);
    }

    // Abstract methods
    public abstract boolean isOperational();
    public abstract String getDeviceType();

    public abstract void printInfo();
}
