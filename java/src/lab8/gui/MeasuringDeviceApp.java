package lab8.gui;

import lab8.model.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class MeasuringDeviceApp extends JFrame {
        private JTextField nameField;
        private JTextField lengthField;
        private JTextField heightField;
        private JTextField widthField;
        private JTextField detailNameField;
        private JTextField detailSupplierField;
        private JTextField detailQuantityField;
        private JComboBox<State> stateComboBox;
        private DefaultListModel<AdditionalDetail> detailsModel;
        private JList<AdditionalDetail> detailsList;
        private JTextArea outputArea;
        private final ArrayList<MeasuringDevice> createdDevices = new ArrayList<>();

        public MeasuringDeviceApp() {
            setTitle("Measuring Device GUI");
            setDefaultCloseOperation(EXIT_ON_CLOSE);
            setSize(600, 700);
            setLayout(new BorderLayout());

            JPanel formPanel = new JPanel(new GridBagLayout());
            JScrollPane scrollPane = new JScrollPane(formPanel);
            scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

            GridBagConstraints gbc = new GridBagConstraints();
            gbc.insets = new Insets(5, 5, 5, 5);
            gbc.fill = GridBagConstraints.HORIZONTAL;
            gbc.gridx = 0;
            gbc.gridy = 0;

            formPanel.add(new JLabel("Name:"), gbc);
            gbc.gridx = 1;
            nameField = new JTextField(10);
            formPanel.add(nameField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Length:"), gbc);
            gbc.gridx = 1;
            lengthField = new JTextField(10);
            formPanel.add(lengthField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Height:"), gbc);
            gbc.gridx = 1;
            heightField = new JTextField(10);
            formPanel.add(heightField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Width:"), gbc);
            gbc.gridx = 1;
            widthField = new JTextField(10);
            formPanel.add(widthField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Detail Name:"), gbc);
            gbc.gridx = 1;
            detailNameField = new JTextField(10);
            formPanel.add(detailNameField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Detail Supplier:"), gbc);
            gbc.gridx = 1;
            detailSupplierField = new JTextField(10);
            formPanel.add(detailSupplierField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("Detail Quantity:"), gbc);
            gbc.gridx = 1;
            detailQuantityField = new JTextField(10);
            formPanel.add(detailQuantityField, gbc);

            gbc.gridx = 0; gbc.gridy++;
            formPanel.add(new JLabel("State:"), gbc);
            gbc.gridx = 1;
            stateComboBox = new JComboBox<>(State.values());
            formPanel.add(stateComboBox, gbc);

            gbc.gridx = 0; gbc.gridy++;
            JButton addDetailButton = new JButton("Add Detail");
            addDetailButton.addActionListener(e -> addDetail());
            formPanel.add(addDetailButton, gbc);

            gbc.gridx = 1;
            JButton removeDetailButton = new JButton("Remove Selected Detail");
            removeDetailButton.addActionListener(e -> removeSelectedDetail());
            formPanel.add(removeDetailButton, gbc);

            gbc.gridx = 0; gbc.gridy++;
            gbc.gridwidth = 2;
            detailsModel = new DefaultListModel<>();
            detailsList = new JList<>(detailsModel);
            JScrollPane detailsScroll = new JScrollPane(detailsList);
            detailsScroll.setPreferredSize(new Dimension(250, 100));
            formPanel.add(detailsScroll, gbc);

            JButton createButton = new JButton("Create Device");
            createButton.addActionListener(e -> createDevice());

            outputArea = new JTextArea(5, 40);
            outputArea.setEditable(false);
            JScrollPane outputScroll = new JScrollPane(outputArea);
            outputScroll.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

            add(scrollPane, BorderLayout.NORTH);
            add(createButton, BorderLayout.CENTER);
            add(outputScroll, BorderLayout.SOUTH);

            setVisible(true);
        }

        private void addDetail() {
            String name = detailNameField.getText();
            String supplier = detailSupplierField.getText();
            String quantityText = detailQuantityField.getText();

            if (!name.isEmpty() && !supplier.isEmpty() && !quantityText.isEmpty()) {
                try {
                    int quantity = Integer.parseInt(quantityText);
                    detailsModel.addElement(new AdditionalDetail(name, supplier, quantity));
                    detailNameField.setText("");
                    detailSupplierField.setText("");
                    detailQuantityField.setText("");
                } catch (NumberFormatException e) {
                    JOptionPane.showMessageDialog(this, "Invalid quantity. Please enter a number.", "Input Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        }

        private void removeSelectedDetail() {
            int selectedIndex = detailsList.getSelectedIndex();
            if (selectedIndex != -1) {
                detailsModel.remove(selectedIndex);
            }
        }

        private void createDevice() {
            try {
                String name = nameField.getText();
                double length = Double.parseDouble(lengthField.getText());
                double height = Double.parseDouble(heightField.getText());
                double width = Double.parseDouble(widthField.getText());
                Dimensions dimensions = new Dimensions(length, height, width);

                ArrayList<AdditionalDetail> details = new ArrayList<>();
                for (int i = 0; i < detailsModel.getSize(); i++) {
                    details.add(detailsModel.getElementAt(i));
                }

                State state = (State) stateComboBox.getSelectedItem();

                MeasuringDevice device = new MeasuringDevice(name, dimensions, details, state);
                createdDevices.add(device);

                StringBuilder summary = new StringBuilder("Created Devices:\n");
                for (int i = 0; i < createdDevices.size(); i++) {
                    MeasuringDevice d = createdDevices.get(i);
                    summary.append(String.format("%d. %s [%s] (%.1fx%.1fx%.1f)\n",
                            i + 1, d.getName(), d.getState(),
                            d.getDimensions().getLength(),
                            d.getDimensions().getHeight(),
                            d.getDimensions().getWidth()));
                    summary.append("   Additional Details:\n");
                    for (AdditionalDetail ad : d.getAdditionalDetails()) {
                        summary.append(String.format("     - %s (Supplier: %s, Quantity: %d)\n",
                                ad.getName(), ad.getSupplier(), ad.getQuantity()));
                    }
                }
                outputArea.setText(summary.toString());

            } catch (Exception e) {
                JOptionPane.showMessageDialog(this, "Invalid input: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
            }
        }

        public static void main(String[] args) {
            SwingUtilities.invokeLater(MeasuringDeviceApp::new);
        }
    }