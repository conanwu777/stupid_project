package simulator.vehicles;

import simulator.WeatherTower;

public class Aircraft {
    protected WeatherTower wt;
    protected long id;
    protected String name;
    protected Coordinates coordinates;
    protected String w;
    private static long idCounter = 0;

    Aircraft(String name, Coordinates co) {
        this.id = idCounter;
        this.name = name;
        this.coordinates = co;
        idCounter = nextId();
    }

    private long nextId() {
        return (idCounter + 1);
    }
}
