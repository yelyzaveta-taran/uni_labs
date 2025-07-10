package lab3.model.MeasuringDevice;

import lab3.model.AbstractDevice.AbstractDevice;
import lab3.model.AbstractDevice.Dimensions;
import lab3.model.AbstractDevice.State;
import lab3.services.InputReader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class MeasuringDevice extends AbstractDevice {
   // Instance fields - protected (supporting encapsulation and accessible from subclasses)
   protected final ArrayList<AdditionalDetail> additionalDetails;

   static int MeasuringDeviceCount;

   // Parametrized constructor
   public MeasuringDevice(String name, Dimensions dimensions, ArrayList<AdditionalDetail> additionalDetails, State state) {
      super(name, state, dimensions);
      this.additionalDetails = additionalDetails;
      MeasuringDeviceCount++;
   }

   // Dialogue constructor replaced with static factory method
   public static MeasuringDevice createFromInput(Scanner scanner){
      String name = InputReader.promptString(scanner, "NAME", "Enter the name of device: ");
      State state = InputReader.readState(scanner);
      Dimensions dimensions = InputReader.readDimensions(scanner);
      ArrayList<AdditionalDetail> details = InputReader.readAdditionalDetails(scanner);
      return new MeasuringDevice(name, dimensions, details, state);
   }

   public List<AdditionalDetail> getAdditionalDetails() {
      return Collections.unmodifiableList(this.additionalDetails);
   }
   public void addAdditionalDetails(AdditionalDetail newDetail) {
      additionalDetails.add(newDetail);
      System.out.println("[INFO]: The list of additional details was updated.");
   }

   public static int getMeasuringDeviceCount(){
      return MeasuringDeviceCount;
   }

   @Override
   public boolean isOperational() {
      return this.state == State.FUNCTIONING;
   }

   @Override
   public String getDeviceType() {
      return "Generic Measuring Device";
   }

   @Override
   public void printInfo() {
      System.out.println("Device: " + name);
      System.out.println("State: " + state);
      System.out.println("Dimensions: " + dimensions);
      if (!additionalDetails.isEmpty()) {
         System.out.println("Additional Details:");
         additionalDetails.forEach(detail -> System.out.println("  - " + detail));
      }
   }

   // Overridden string representation method
   @Override
   public String toString() {
      StringBuilder sb = new StringBuilder();

      sb.append("Device {\n")
              .append("  name='").append(this.name).append("'\n")
              .append("  dimensions=").append(this.dimensions).append("\n")
              .append("  state='").append(this.state).append("'\n");

      if (!this.additionalDetails.isEmpty()) {
         sb.append("  additionalDetails=[\n");
         this.additionalDetails.forEach(detail -> { sb.append("    ").append(detail).append("\n");});
         sb.append("  ]\n");
      }

      sb.append("}");
      return sb.toString();
   }
}
