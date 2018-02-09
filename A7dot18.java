import java.util.*;

public class A7dot18 {
	public static void main(String[] args) {
		double[] list = readData();
		
		sortArray(list);
		
		printArray(list);
		
	}
	
	private static void printArray(double[] list) {
		for (double value: list) {
			System.out.print(value + " ");
		}
		
	}
	
	private static void sortArray(double[] list) {
		
		for (int i = 0; i < list.length; i++) {
			for (int j = 0; j < list.length - 1 - i; j++) {
				if (list[j] > list[j + 1]) {
					double temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
			}
		}
		
	}
	
	private static double[] readData() {
		
		double[] list = new double[10];
		Scanner input = new Scanner(System.in);
		System.out.print("Please enter ten doubles: ");
		for (int i = 0; i < list.length; i++) {
			list[i] = input.nextDouble();
		}
		
		return list;
	}
}