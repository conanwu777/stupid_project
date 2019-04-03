package simulator;

import simulator.vehicles.Flyable;
import simulator.vehicles.Logger;
import simulator.vehicles.Coordinates;
import weather.WeatherProvider;

import java.util.Random;

public class WeatherTower extends Tower {
    public void register(Flyable flyable) {
        if (flyable != null) {
            Logger.log("*********\uD83D\uDDFC ");
            flyable.registerTower(this);
            super.register(flyable);
            Logger.log(" registered to the weather tower \uD83D\uDDFC*********\n");
        }
        else
            super.register(null);
    }
    public String getWeather(Coordinates co) {
        return (WeatherProvider.getProvider().getCurrentWeather(co));
    }
    void changeWeather() {
        Random rand = new Random();
        WeatherProvider.getProvider().r = rand.nextInt(4);
        this.conditionsChanged();
    }
}
