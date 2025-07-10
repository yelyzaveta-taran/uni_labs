package lab5.model;

import lab5.model.AdditionalDetail;
import lab5.model.Dimensions;
import lab5.model.State;
import lab5.services.InputReader;

import java.util.*;

public class MeasuringDevice {
   // Instance fields - private (supporting encapsulation)
   private String name;
   private Dimensions dimensions;
   private final ArrayList<AdditionalDetail> additionalDetails;
   private State state;

   // Parametrized constructor
   public MeasuringDevice(String name, Dimensions dimensions, ArrayList<AdditionalDetail> additionalDetails, State state) {
      this.name = name;
      this.dimensions = dimensions;
      this.additionalDetails = additionalDetails;
      this.state = state;
   }

   // Dialogue constructor
   public MeasuringDevice(Scanner scanner) {
      this.name = InputReader.promptString(scanner, "NAME", "Enter the name of device: ");
      this.dimensions = InputReader.readDimensions(scanner);
      this.additionalDetails = InputReader.readAdditionalDetails(scanner);
      this.state = InputReader.readState(scanner);
   }

   // Setters and Getters
   public String getName() {
      return name;
   }
   public void setName(String name) {
      this.name = name;
      System.out.println("[INFO]: The name value was updated.");
   }

   public Dimensions getDimensions() {
      return dimensions;
   }
   public void setDimensions(Dimensions dimensions) {
      this.dimensions = dimensions;
      System.out.println("[INFO]: The dimensions object was updated.");
   }

   public List<AdditionalDetail> getAdditionalDetails() {
      return Collections.unmodifiableList(this.additionalDetails);
   }

   public State getState() {
      return state;
   }
   public void setState(State state) {
      this.state = state;
   }

   // Overridden string representation method
   @Override
   public String toString() {
      StringBuilder sb = new StringBuilder();

      sb.append("Device {\n")
              .append("  name='").append(this.name).append("'\n")
              .append("  dimensions=").append(this.dimensions).append("\n")
              .append("  state='").append(this.state).append("'\n");

      if (this.additionalDetails != null && !this.additionalDetails.isEmpty()) {
         sb.append("  additionalDetails=[\n");
         for (AdditionalDetail detail : this.additionalDetails) {
            sb.append("    ").append(detail).append("\n");
         }
         sb.append("  ]\n");
      }

      sb.append("}");
      return sb.toString();
   }

   // 1. Додати елемент у кінець списку
public void addAdditionalDetail(AdditionalDetail detail) {
        additionalDetails.add(detail);
    }


    // 6. Видалити перший елемент
    public void removeFirstAdditionalDetail() {
        if (!additionalDetails.isEmpty()) {
            additionalDetails.remove(0);
        } else {
            throw new IllegalStateException("Impossible to remove element if the array is empty.");
        }
    }

    // 10. Отримати кількість входжень елемента до списку (обраний атрибут - ім'я деталі)
    public long countByName(String name) {
        return additionalDetails.stream()
                .filter(detail -> detail.getName().equalsIgnoreCase(name))
                .count();
    }

    // 14. Відсортувати колекцію за збільшенням деякого атрибуту (обраний атрибут - кількість деталей)
    public void sortByQuantityAscending() {
        additionalDetails.sort(Comparator.comparingInt(AdditionalDetail::getQuantity));
    }

    // 21. Видалити з певним значенням деякого атрибуту (обраний атрибут - ім'я постачальника)
    public void removeBySupplier(String supplier) {
        additionalDetails.removeIf(detail -> detail.getSupplier().equalsIgnoreCase(supplier));
    }
}
