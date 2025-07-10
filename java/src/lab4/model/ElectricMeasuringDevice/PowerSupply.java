package lab4.model.ElectricMeasuringDevice;

import lab4.utils.Validator;

public class PowerSupply {
    private double voltage;
    private double current;
    private double frequency;

    public PowerSupply(double voltage, double current, double frequency) {
        Validator.validate("Voltage", voltage);
        Validator.validate("Current", current);
        Validator.validate("Frequency", frequency);

        this.voltage = voltage;
        this.current = current;
        this.frequency = frequency;
    }

    public double getVoltage() {
        return voltage;
    }

    public void setVoltage(double voltage) {
        Validator.validate("Voltage", voltage);
        this.voltage = voltage;
        System.out.println("[INFO]: The voltage value was updated.");
    }

    public double getCurrent() {
        return current;
    }

    public void setCurrent(double current) {
        Validator.validate("Current", current);
        this.current = current;
        System.out.println("[INFO]: The current value was updated.");
    }

    public double getFrequency() {
        return frequency;
    }

    public void setFrequency(double frequency) {
        Validator.validate("Frequency", frequency);
        this.frequency = frequency;
        System.out.println("[INFO]: The frequency value was updated.");
    }

    @Override
    public String toString() {
        return String.format("Voltage: %.2f V, Current: %.2f A, Frequency: %.2f Hz",
                voltage, current, frequency);
    }
}
