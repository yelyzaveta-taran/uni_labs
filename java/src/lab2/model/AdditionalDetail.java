package lab2.model;

import lab2.utils.Validator;

public class AdditionalDetail {
    // Instance fields - private (supporting encapsulation)
    private String name;
    private String supplier;
    private int quantity;

    // Parametrized constructor
    public AdditionalDetail(String name, String supplier, int quantity) {
        Validator.validate("Quantity", quantity);

        this.name = name;
        this.supplier = supplier;
        this.quantity = quantity;
    }

    // Getters and Setters
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }

    public String getSupplier() {
        return supplier;
    }
    public void setSupplier(String supplier) {
        this.supplier = supplier;
    }

    public int getQuantity() {
        return quantity;
    }
    public void setQuantity(int quantity) {
        Validator.validate("Quantity", quantity);

        this.quantity = quantity;
    }

    // Overridden string representation method
    @Override
    public String toString() {
        return String.format("{name='%s', supplier='%s', quantity=%d}", name, supplier, quantity);
    }

}
