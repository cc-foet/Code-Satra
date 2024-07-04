import javax.swing.*;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;

public class cc extends JFrame {

    private JTextField ifield;
    private JComboBox<String> ccBox;
    private JLabel result;


    private Map<String, Double> rates;

    public cc() {

        setTitle("Currency Converter");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationRelativeTo(null);


        rates = new HashMap<>();
        rates.put("INDIAN RUPEES", 1.0); 
        rates.put("US DOLLOR",0.012003);
        rates.put("EUR", 0.011006);
        rates.put("BRITISH POUND", 0.009578);
        rates.put("PAKISTANI RUPEE", 3.387299);
        rates.put("SAUDI ARABIAN RIYAL", 0.045012        );
        rates.put("SINGAPORE DOLLOR", 0.016098);
        rates.put("CANADIAN DOLLOW",0.016440);
        rates.put("JAPANESE YEN", 1.795608);
        rates.put("KUWAITI DINAR", 0.003701        );
        rates.put("SWISS FRANC",0.010606        );
        rates.put("HONG KONG DOLLOR", 0.093596);
        rates.put("ARGENTINE PESO", 4.285303);
        rates.put("GBP", 0.75);
        rates.put("SRILANKAN RUPEE", 3.948764        );


        JLabel ilabel = new JLabel("Please Enter Amount in Indian Rupees:");
        ifield = new JTextField(100);
        ifield.setBackground(Color.black);
        ifield.setFont(new Font("Areial",Font.PLAIN,18));
        ifield.setForeground(Color.red);
        ifield.setCaretColor(Color.green);
        add(ilabel);
        add(ifield);

        JLabel clabel = new JLabel("Choose Currency from the following list:");
        ccBox = new JComboBox<>(rates.keySet().toArray(new String[0]));
        add(clabel);
        add(ccBox);

        JButton cbutton = new JButton("Convert");
        result = new JLabel("Converted Amount: ");
        result.setForeground(Color.blue);
        result.setBounds(10,80,400,50);
        add(cbutton);
        add(result);


        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));

        cbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                cCurrency();
            }
        });
    }

    private void cCurrency() {

        try {
            double amount = Double.parseDouble(ifield.getText());


            String cCurrency = (String) ccBox.getSelectedItem();


            double crates = rates.get(cCurrency);


            double camount = amount * crates;


            result.setText("Converted Amount to " + cCurrency + ": " + camount);
        } catch (NumberFormatException ex) {
            result.setText("Invalid input. Please enter a valid number.");
        }
    }

    public static void main(String[] args) {

        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new cc().setVisible(true);
            }
        });
    }
}
