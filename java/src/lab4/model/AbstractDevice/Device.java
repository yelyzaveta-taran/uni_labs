package lab4.model.AbstractDevice;

import java.time.LocalDateTime;

public interface Device {
    String SERIAL_PREFIX = "DEV-";

    String getName();
    void setName(String name);

    State getState();
    void setState(State state);

    Dimensions getDimensions();
    void setDimensions(Dimensions dimensions);

    String getSerialNumber();
    LocalDateTime getCreatedAt();

    boolean isOperational();
    String getDeviceType();
    void printInfo();
}
