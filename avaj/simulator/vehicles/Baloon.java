package simulator.vehicles;

import simulator.WeatherTower;
import weather.Coordinates;

public class Baloon extends Aircraft implements Flyable{
    Baloon(String name, Coordinates co) {
        super (name, co);
    }
    public void updateConditions() {
        w = this.wt.getWeather(this.coordinates);
        int lo = this.coordinates.getLongitude();
        int la = this.coordinates.getLatitude();
        int h = this.coordinates.getHeight();
        Logger.log("\uD83C\uDF88 " + this.name + "(" + this.id + "): " + w);
        switch (w) {
            case "🌧":
                Logger.log(" Opps, I'm wet.\n");
                h -= 5;
                break;
            case "☀️":
                Logger.log("️ Working on my tan!\n");
                lo += 2;
                h += 4;
                if (h >= 100)
                    h = 100;
                break;
            case "☁️":
                Logger.log("️️ Did someone turn off the lights?\n");
                h -= 3;
                break;
            case "❄️":
                Logger.log("️ Hi Snowman!\n");
                h -= 15;
                break;
        }
        if (h <= 0) {
            Logger.log("Watch out, big ball coming down...\n");
            Logger.log("\uD83D\uDDFC \uD83C\uDF88 " + this.name + "(" + this.id + ") ");
            this.wt.unregister(this);
        }
        else {
            Coordinates n;
            n = new Coordinates(lo, la, h);
            this.coordinates = n;
        }
    }
    public void registerTower(WeatherTower wt) {
        Logger.log("\uD83C\uDF88 " + this.name + " Unique id: " + this.id);
        this.wt = wt;
    }
    public void printHeight() {
        Logger.log(this.name + "(" + this.id + ")");
        for (int i = 0; i <= 100; i++)
            if (i == coordinates.getHeight())
                Logger.log("🎈");
            else
                Logger.log("-");
        Logger.log(w + "\n");
    }
}
