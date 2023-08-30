/*
I only required one commit because i have clear approach,
it was fun experience.
*/
import java.util.HashMap;

public class Chandrayaan3 {

  private static final HashMap<String, int[]> DIRECTIONS = new HashMap<>();

  static {
    //using DIRECTIONS.put() to store the mapping from commands to directions.
    DIRECTIONS.put("f", new int[]{1, 0, 0});
    DIRECTIONS.put("b", new int[]{-1, 0, 0});
    DIRECTIONS.put("l", new int[]{0, -1, 0});
    DIRECTIONS.put("r", new int[]{0, 1, 0});
    DIRECTIONS.put("u", new int[]{0, 0, 1});
    DIRECTIONS.put("d", new int[]{0, 0, -1});
  }

  public static void moveCraft(Spacecraft craft, String command) {
    //changing co-ordinates...
    int[] direction = DIRECTIONS.get(command);
    craft.x += direction[0];
    craft.y += direction[1];
    craft.z += direction[2];
  }

  public static void turnCraft(Spacecraft craft, String command) {
    //repeating same direction by reminder of 4...
    int[] direction = DIRECTIONS.get(command);
    craft.direction = (craft.direction + 1) % 4;
  }

  public static void executeCommands(Spacecraft craft, String[] commands) {
    //executing each command in for loop...
    for (String command : commands) {
      moveCraft(craft, command);
      turnCraft(craft, command);
    }
  }

  @Test
  public void testMoveCraft() {
    //basic object initialization...
    Spacecraft craft = new Spacecraft();
    craft.x = 0;
    craft.y = 0;
    craft.z = 0;
    craft.direction = 0;

    moveCraft(craft, "f");

    assertEquals(1, craft.x);
    assertEquals(0, craft.y);
    assertEquals(0, craft.z);
  }

  @Test
  public void testTurnCraft() {
    Spacecraft craft = new Spacecraft();
    craft.x = 0;
    craft.y = 0;
    craft.z = 0;
    craft.direction = 0;

    turnCraft(craft, "r");

    assertEquals(0, craft.x);
    assertEquals(0, craft.y);
    assertEquals(0, craft.z);
    assertEquals(1, craft.direction);
  }

  @Test
  public void testExecuteCommands() {
    Spacecraft craft = new Spacecraft();
    craft.x = 0;
    craft.y = 0;
    craft.z = 0;
    craft.direction = 0;

    String[] commands = {"f", "r", "u", "b", "l"};

    executeCommands(craft, commands);

    assertEquals(0, craft.x);
    assertEquals(1, craft.y);
    assertEquals(-1, craft.z);
    assertEquals(0, craft.direction);
  }
}

class Spacecraft {

  int x;
  int y;
  int z;
  int direction;

  public Spacecraft() {}

  public Spacecraft(int x, int y, int z, int direction) {
    this.x = x;
    this.y = y;
    this.z = z;
    this.direction = direction;
  }
  //output...
  @Override
  public String toString() {
    return String.format("(x=%d, y=%d, z=%d, direction=%d)", x, y, z, direction);
  }
}