package simulator;

import simulator.vehicles.Flyable;
import simulator.vehicles.Logger;

import java.util.ArrayList;

public class Tower {
    private int b;
    private static ArrayList<Flyable> flyables = new ArrayList<>();
    public void register(Flyable flyable) {
        if (flyable != null)
            flyables.add(flyable);
        else
            flyables.add(null);
    }
    public void unregister(Flyable flyable) {
        flyables.remove(flyable);
        Logger.log("unregistered from the weather tower \uD83D\uDDFC\n");
        b = 1;
    }
    void conditionsChanged() {
        Logger.log("*********\uD83D\uDDFC Another day! How's everybody? \uD83D\uDDFC*********\n");
        int i = 0;
        while (flyables.get(i) != null) {
            flyables.get(i).updateConditions();
            if (b == 1) {
                b = 0;
                continue;
            }
            i++;
        }
        Logger.log("*********\uD83D\uDDFC Current height report: \uD83D\uDDFC*********\n");
        i = 0;
        while (flyables.get(i) != null) {
            flyables.get(i).printHeight();
            i++;
        }
        Logger.log("\n");
    }
}
