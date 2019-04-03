package simulator;

import simulator.vehicles.AircraftFactory;
import simulator.vehicles.Flyable;
import simulator.vehicles.Logger;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class Simulator {
    private static WeatherTower wt;

    public static void main(String[] arg) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(arg[0]));
            String line = reader.readLine();
            if (line != null) {
                wt = new WeatherTower();
                int simulations = Integer.parseInt(line.split(" ")[0]);
                if (simulations < 0) {
                    System.out.println("I cannot predict the past...>.<");
                    System.exit(1);
                }
                while ((line = reader.readLine()) != null) {
                    Flyable flyable = AircraftFactory.newAircraft(
                        line.split(" ")[0],
                        line.split(" ")[1],
                        Integer.parseInt(line.split(" ")[2]),
                        Integer.parseInt(line.split(" ")[3]),
                        Integer.parseInt(line.split(" ")[4]));
                    wt.register(flyable);
                }
                Logger.log("\n");
                wt.register(null);
                for (int i = 1; i <= simulations; i++)
                    wt.changeWeather();
            }
        } catch (FileNotFoundException e) {
            System.out.println("Sorry, I tried and cannot find file " + arg[0]);
            System.exit(1);
        } catch (IOException e) {
            System.out.println("Sorry, there was an error reading " + arg[0]);
            System.exit(1);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Simulation file is not in the right format");
            System.exit(1);
        } catch (java.lang.NumberFormatException e) {
                System.out.println("Simulation file is not in the right format");
                System.exit(1);
        } catch (Exception e) {
            System.out.println("Something mysterious is wrong");
            System.exit(1);
        } finally {
            try {
                Logger.getLogger().close();
                System.out.println("Simulation complete! output successfully saved to simulation.txt");
            } catch (IOException e) {
                System.out.println("Sorry, there was an error closing output file");
                System.exit(1);
            }
        }
    }
}
