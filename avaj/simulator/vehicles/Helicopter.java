package simulator.vehicles;

import simulator.WeatherTower;
import weather.Coordinates;

public class Helicopter extends Aircraft implements Flyable{
    Helicopter(String name, Coordinates co) {
        super (name, co);
    }
    public void updateConditions() {
        w = this.wt.getWeather(this.coordinates);
        int lo = this.coordinates.getLongitude();
        int la = this.coordinates.getLatitude();
        int h = this.coordinates.getHeight();
        Logger.log("\uD83D\uDE81 " + this.name + "(" + this.id + "): " + w);
        switch (w) {
            case "🌧":
                Logger.log(" Let it rain~~~️\n");
                lo += 5;
                break;
            case "☀️":
                Logger.log("️ My Sunshine~~~️️\n");
                lo += 10;
                h += 2;
                if (h >= 100)
                    h = 100;
                break;
            case "☁️":
                Logger.log(" ️@^&$#(*~~~\n");
                lo += 1;
                break;
            case "❄️":
                Logger.log(" Let it snow~~~️\n");
                h -= 12;
                break;
        }
        if (h <= 0) {
            Logger.log("Tatata~~~~landing~~~\n");
            Logger.log("\uD83D\uDDFC \uD83D\uDE81 " + this.name + "(" + this.id + ") ");
            this.wt.unregister(this);
        }
        else {
            Coordinates n;
            n = new Coordinates(lo, la, h);
            this.coordinates = n;
        }
    }
    public void registerTower(WeatherTower wt) {
        Logger.log("\uD83D\uDE81 " + this.name + " Unique id: " + this.id);
        this.wt = wt;
    }
    public void printHeight() {
        Logger.log(this.name + "(" + this.id + ")");
        for (int i = 0; i <= 100; i++)
            if (i == coordinates.getHeight())
                Logger.log("\uD83D\uDE81");
            else
                Logger.log("-");
        Logger.log(w + "\n");
    }
}