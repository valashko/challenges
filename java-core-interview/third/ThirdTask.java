import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class AnimalSounds {
  public void saySomething(String animal) {
    switch(animal) {
      case "cat":
        System.out.println("Meow!");
        break;
      case "dog":
        System.out.println("Bow-wow!");
        break;
      case "fish":
        System.out.println("*silence*");
        break;
      default:
        System.out.println("ERROR: unknown animal!");
        break;
    }
  }
}

public class ThirdTask {
  public static void main(String[] args) throws IOException {
    System.out.println("Enter the animal: ");
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String animal = br.readLine();
    AnimalSounds sounds = new AnimalSounds();
    sounds.saySomething(animal);
  }
}

