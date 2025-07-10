package lab3.utils;

public class Validator {
    public static void validate(String name, double value){
        if(value < 0){
            throw new IllegalArgumentException(name + " must be non-negative.");
        }
    }
}
