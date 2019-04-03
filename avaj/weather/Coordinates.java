package weather;

public class Coordinates {
    private int longitude;
    private int latitude;
    private int height;

    public Coordinates (int lo, int la, int h) {
        this.longitude = lo;
        this.latitude = la;
        if (h > 100)
            h = 100;
        if (h < 0)
            h = 0;
        this.height = h;
    }
    public int getLongitude() {
        return (longitude);
    }
    public int getLatitude() {
        return (latitude);
    }
    public int getHeight() {
        return (height);
    }
}
