package lab4.model.MeasuringDevice;


import lab4.model.AbstractDevice.Device;
import lab4.model.AbstractDevice.Dimensions;
import lab4.model.AbstractDevice.State;
import lab4.services.InputReader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


import java.time.LocalDateTime;
import java.util.*;

public interface MeasuringDevice extends Device {
   int MAX_ADDITIONAL_DETAILS = 10;

   List<AdditionalDetail> getAdditionalDetails();
   void addAdditionalDetails(AdditionalDetail newDetail);
}