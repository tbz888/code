import java.time.LocalDate;
import java.util.logging.Logger;
import java.util.logging.Level;

public class testLogger {
	private static final Logger myLog = Logger.getLogger("com.company.tbz");

	public static void main(String[] args) {
		// Logger.getGlobal().info(LocalDate.now() + " begin.");
		// Logger.getGlobal().setLevel(Level.OFF);
		// Logger.getGlobal().info("test");
		// Logger.getGlobal().setLevel(Level.INFO);
		// Logger.getGlobal().info("open");

		myLog.setLevel(Level.INFO);
		myLog.log(Level.INFO, "info");
		myLog.log(Level.WARNING, "warning");
		myLog.log(Level.SEVERE, "severe");
	}
}