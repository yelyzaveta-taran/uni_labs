package lab2.services;

import lab2.model.AdditionalDetail;
import lab2.model.Dimensions;
import lab2.model.State;

import java.util.ArrayList;
import java.util.Scanner;

public class InputReader {
    // String input, validates the input
    public static String promptString(Scanner scanner, String sectionTitle, String promptMessage) {
        System.out.println(sectionTitle);
        String input;
        while (true) {
            System.out.print(promptMessage);
            input = scanner.nextLine().trim();
            if (!input.isEmpty()) {
                return input;
            }
            System.out.println("Input cannot be empty. Please try again.");
        }
    }

    // Dimensions input, validates the input, returns instantiated Dimensions object
    public static Dimensions readDimensions(Scanner scanner) {
        System.out.print("DIMENSIONS\n");
        double length = readPositiveDouble(scanner, "Enter the length value: ");
        double height = readPositiveDouble(scanner, "Enter the height value: ");
        double width = readPositiveDouble(scanner, "Enter the width value: ");
        return new Dimensions(length, height, width);
    }

    // Creating an array of additional details, receives the input, validates the input, initializes objects
    public static ArrayList<AdditionalDetail> readAdditionalDetails(Scanner scanner){
        System.out.print("ADDITIONAL DETAILS\n");
        int initialDetailsQuantity = readPositiveInteger(scanner, "Enter the initial quantity of details: ");
        ArrayList<AdditionalDetail> details = new ArrayList<>(initialDetailsQuantity);
        for (int i = 0; i < initialDetailsQuantity; i++){
            String name = promptString(scanner, "", "Enter the name of the detail:");
            String supplier = promptString(scanner, "", "Enter the name of supplier:");
            int quantity = readPositiveInteger(scanner, "Enter the quantity");

            details.add(new AdditionalDetail(name, supplier, quantity));
        }
        return details;
    }

    // Additional detail object input, validates the input, creates a single instance to add into the existing array
    public static AdditionalDetail readAdditionalDetail(Scanner scanner){
        String name = promptString(scanner, "", "Enter the name of the detail:");
        String supplier = promptString(scanner, "", "Enter the name of supplier:");
        int quantity = readPositiveInteger(scanner, "Enter the quantity");
        return new AdditionalDetail(name, supplier, quantity);
    }

    // State input, validates the input, returns the valid stated value
    public static State readState(Scanner scanner){
        System.out.println("STATE");
        System.out.println("Enter the device state. Choose one of the following:");
        for (State s : State.values()) {
            System.out.println("- " + s);
        }

        while(true){
            String input = promptString(scanner, "", "Type the state exactly as shown above: ").toUpperCase();
            try{
                return State.valueOf(input);
            } catch (IllegalArgumentException iae){
                System.out.println("Invalid input. Please enter one of the listed states.");
            }
        }
    }

    // Helper methods - validate receiving positive int/double values
    private static double readPositiveDouble(Scanner scanner, String prompt) {
        double value;
        while (true) {
            System.out.print(prompt);
            if(scanner.hasNextDouble()){
                value = scanner.nextDouble();
                scanner.nextLine();
                if (value >= 0) return value;
            } else {
                scanner.nextLine();
            }
            System.out.println("Please enter a non-negative double.");
        }
    }
    private static int readPositiveInteger(Scanner scanner, String prompt){
        int value;
        while (true){
            System.out.print(prompt);
            if(scanner.hasNextInt()){
                value = scanner.nextInt();
                scanner.nextLine();
                if(value >= 0) return value;
            } else {
                scanner.nextLine();
            }
            System.out.println("Please enter a non-negative integer.");
        }
    }
}
