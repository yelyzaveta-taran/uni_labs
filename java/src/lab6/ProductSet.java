package lab6;

import java.util.*;

public class ProductSet {
    private ArrayList<Product> products = new ArrayList<>();

    // Adding product only if it's unique, handling the exception if the product already exists
    public void addProduct(Product p) {
        for (Product existing : products) {
            if (existing.equals(p)) {
                throw new IllegalArgumentException("Product with same name, manufacturer and warranty already exists.");
            }
        }
        products.add(p);
    }

    // Displaying the list of products if it's not empty
    public void displayAll() {
        if (products.isEmpty()) {
            System.out.println("No products available.");
        } else {
            products.forEach(System.out::println);
        }
    }

    // Finding all products with the same retail price
    public ArrayList<Product> findByRetailPrice(double price) {
        ArrayList<Product> result = new ArrayList<>();
        for (Product p : products) {
            // Comparing double by Double.compare to avoid mistakes
            if (Double.compare(p.getRetailPrice(), price) == 0) {
                result.add(p);
            }
        }
        return result;
    }

    // Sorting products by retail price
    public void sortByRetailPriceDescending() {
        products.sort(Comparator.comparingDouble(Product::getRetailPrice).reversed());
    }
}