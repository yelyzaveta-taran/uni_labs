package lab5;

import lab5.model.AdditionalDetail;
import lab5.model.Dimensions;
import lab5.model.MeasuringDevice;
import lab5.model.State;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        // Create list of AdditionalDetail objects
        ArrayList<AdditionalDetail> details = new ArrayList<>();
        details.add(new AdditionalDetail("Button", "GenericSupplier", 3));

        // Create dimensions object
        Dimensions dimensions = new Dimensions(20.0, 10.0, 5.0);

        // Create MeasuringDevice object
        MeasuringDevice device = new MeasuringDevice(
                "Thermal Scanner",
                dimensions,
                details,
                State.FUNCTIONING
        );

        // Додати елемент у кінець списку
        device.addAdditionalDetail(new AdditionalDetail("Sensor", "Panasonic", 2));
        System.out.println("After adding new element: " + device.getAdditionalDetails() + "\n");

        // Видалити перший елемент зі списку
        device.removeFirstAdditionalDetail();
        System.out.println("After deleting the first element: " + device.getAdditionalDetails() + "\n");

        // Отримати кількість входжень елемента до списку (за ім'ям деталі)
        device.addAdditionalDetail(new AdditionalDetail("Sensor", "Lenovo", 1));
        device.addAdditionalDetail(new AdditionalDetail("Sensor", "Samsung", 1));
        System.out.println("Before counting by name: " + device.getAdditionalDetails());
        System.out.println("Quantity of details by name: " + device.countByName("Sensor") + "\n");

        // Видалити елемент з певним значенням деякого атрибуту (за ім'ям постачальника)
        System.out.println("Before deleting Samsung details: " + device.getAdditionalDetails());
        device.removeBySupplier("Samsung");
        System.out.println("After deleting Samsung details: " + device.getAdditionalDetails() + "\n");

        // Відсортувати за збільшенням значення деякого атрибуту (за кількістю деталей)
        System.out.println("Before sorting: " + device.getAdditionalDetails());
        device.sortByQuantityAscending();
        System.out.println("After sorting: " + device.getAdditionalDetails());
    }
}
