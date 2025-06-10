package lab2;

import lab2.model.AdditionalDetail;
import lab2.model.Dimensions;
import lab2.model.MeasuringDevice;
import lab2.model.State;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // TESTING PARAMETRIZED CONSTRUCTORS
        // Create Dimensions object
        Dimensions dimensions = new Dimensions(20.0, 10.0, 5.0);

        // Create list of AdditionalDetail objects
        ArrayList<AdditionalDetail> details = new ArrayList<>();
        details.add(new AdditionalDetail("Battery", "Panasonic", 4));
        details.add(new AdditionalDetail("Screen", "Samsung", 1));
        details.add(new AdditionalDetail("Button", "GenericSupplier", 3));

        // Create MeasuringDevice object
        MeasuringDevice device = new MeasuringDevice(
                "Thermal Scanner",
                dimensions,
                details,
                State.FUNCTIONING
        );

        // Set new name
//        device.setName("Thermal Scanner Version 2");

        // Set new dimensions
//        Dimensions newDimensions = new Dimensions(20.5, 10.5, 10.0);
//        device.setDimensions(newDimensions);

        // Setting each dimension value separately using Dimensions setters
//        device.getDimensions().setLength(25.5);
//        device.getDimensions().setHeight(11);
//        device.getDimensions().setWidth(15.5);

        //Impossible to set negative values
//        Dimensions newDimensionsError = new Dimensions(-20.5, 10.5, 10.0);
//        device.setDimensions(newDimensionsError);

        // Set new state
//        device.setState(State.UNDER_MAINTENANCE);

        // Add new detail
//        AdditionalDetail newDetail = new AdditionalDetail("Sensor", "Omron", 2);
//        device.addAdditionalDetails(newDetail);

        //Impossible to set negative quantity
//        AdditionalDetail newDetailError = new AdditionalDetail("Sensor", "Omron", -2);
//        device.addAdditionalDetails(newDetailError);
//
//        System.out.println(device);

        // TESTING DIALOGUE CONSTRUCTORS

        Scanner scanner = new Scanner(System.in);
        MeasuringDevice device1 = new MeasuringDevice(scanner);
        System.out.println(device1);
    }
}
