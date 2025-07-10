package lab6;

public class Main {
    public static void main(String[] args) {
        ProductSet set = new ProductSet();

        Product p1 = new Product("Phone", "Samsung", 10, 100, 150, 2);
        Product p2 = new Product("Phone", "Samsung", 15, 110, 200, 2);

        set.addProduct(p1);
        set.addProduct(p2);
    }
}
