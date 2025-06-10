package lab2.model;

import lab2.utils.Validator;

public class Dimensions {
    // Instance fields - private (supporting encapsulation)
    private double length;
    private double height;
    private double width;

    // Parametrized constructor
    public Dimensions(double length, double height, double width){
        Validator.validate("Length", length);
        Validator.validate("Height", height);
        Validator.validate("Width", width);

        this.length = length;
        this.height = height;
        this.width = width;
    }

    // Getters and Setters
    public double getLength() {
        return length;
    }
    public void setLength(double length) {
        Validator.validate("Length", length);
        this.length = length;
        System.out.println("Length value was updated");
    }

    public double getHeight() {
        return height;
    }
    public void setHeight(double height) {
        Validator.validate("Height", height);
        this.height = height;
        System.out.println("Height value was updated");
    }

    public double getWidth() {
        return width;
    }
    public void setWidth(double width) {
        Validator.validate("Width", width);
        this.width = width;
        System.out.println("Width value was updated");
    }

    // Overridden string representation method
    @Override
    public String toString() {
        return String.format("%.2f x %.2f x %.2f", length, height, width);
    }
}

