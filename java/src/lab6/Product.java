package lab6;

public class Product {
      private String name;
      private String manufacturer;
      private int quantity;
      private double wholesalePrice;
      private double retailPrice;
      private int warrantyMonths;

    public Product(String name, String manufacturer, int quantity, double wholesalePrice, double retailPrice, int warrantyMonths) {
        setName(name);
        setManufacturer(manufacturer);
        setQuantity(quantity);
        setWholesalePrice(wholesalePrice);
        setRetailPrice(retailPrice);
        setWarrantyMonths(warrantyMonths);
    }

    // Обробка винятку: 8. Найменування товару містить менше 3 символів
    public String getName() { return name; }
    public void setName(String name){
        if(name.length() < 3) throw new IllegalArgumentException("Product name must have at least 3 characters.");
        this.name = name;
    }

    // Обробка винятку: 9. Ім'я виробника містить менше 5 символів
    public String getManufacturer() { return manufacturer; }
    public void setManufacturer(String manufacturer) {
        if (manufacturer.length() < 5) throw new IllegalArgumentException("Manufacturer name must have at least 5 characters.");
        this.manufacturer = manufacturer;
    }

    // Обробка винятку: 6. Негативна кількість товару
    public int getQuantity() { return quantity; }
    public void setQuantity(int quantity) {
        if (quantity < 0) throw new IllegalArgumentException("Quantity can't be negative.");
        this.quantity = quantity;
    }

    // Обробка винятку: 7. Ціна менше нуля або дорівнює нулю
    public double getWholesalePrice() { return wholesalePrice; }
    public void setWholesalePrice(double wholesalePrice) {
        if (wholesalePrice <= 0) throw new IllegalArgumentException("Wholesale price must be positive.");
        this.wholesalePrice = wholesalePrice;
    }

    // Обробка винятку:
    // 7. Ціна менше нуля або дорівнює нулю
    // 8. Не можна знизити ціну товару більш ніж на 0.5 від оптової ціни
    // 9. Оптова ціна виявилася вище роздрібної
    public double getRetailPrice() { return retailPrice; }
    public void setRetailPrice(double retailPrice) {
        if (retailPrice <= 0) throw new IllegalArgumentException("Retail price must be positive.");
        if (wholesalePrice > 0 && retailPrice < 0.5 * wholesalePrice) {
            throw new IllegalArgumentException("Retail price can't be more than 50% less than wholesale price.");
        }
        if (wholesalePrice > retailPrice) {
            throw new IllegalArgumentException("Wholesale price can't be higher than retail price.");
        }
        this.retailPrice = retailPrice;
    }

    //
    public int getWarrantyMonths() { return warrantyMonths; }
    public void setWarrantyMonths(int warrantyMonths) {
        if (warrantyMonths < 1) throw new IllegalArgumentException("Warranty must be at least 1 month.");
        this.warrantyMonths = warrantyMonths;
    }

    @Override
    public String toString() {
        return String.format("%s by %s: %d pcs, wholesale %.2f, retail %.2f, warranty %d months",
                name, manufacturer, quantity, wholesalePrice, retailPrice, warrantyMonths);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Product)) return false;
        Product p = (Product) o;
        return name.equalsIgnoreCase(p.name) && manufacturer.equalsIgnoreCase(p.manufacturer)
                && warrantyMonths == p.warrantyMonths;
    }

    @Override
    public int hashCode() {
        return name.toLowerCase().hashCode() + manufacturer.toLowerCase().hashCode() + warrantyMonths;
    }
}