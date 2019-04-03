package simulator.vehicles;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Logger {
    static private BufferedWriter logger;
    public static BufferedWriter getLogger() {
        if (logger == null) {
            try {
                logger = new BufferedWriter(new FileWriter("simulation.txt"));
            } catch (IOException e) {
                System.out.println("Something is wrong");
            }
        }
        return (logger);
    }
    public static void log(String str) {
        BufferedWriter l = getLogger();
        try {
            l.write(str);
        } catch (IOException e) {
            System.out.print("Cannot write into file\n");
        }
    }
}
