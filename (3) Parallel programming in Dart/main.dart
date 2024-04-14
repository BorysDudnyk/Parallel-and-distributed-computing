import 'dart:async';
import 'dart:io';
import 'package:dio/dio.dart';

void main() async {
  int counter = 0;
  Dio dio = Dio();

  while (true) {
    print('\n--- Menu ---');
    print('1. Increment Counter');
    print('2. Get Random Number Fact');
    print('3. Calculate Fibonacci (10 * counter)');
    print('4. Exit');
    stdout.write('Choose an option: ');
    String? choice = stdin.readLineSync();

    if (choice == '1') {
      counter++;
      print('Counter incremented! Current value: $counter');
    } else if (choice == '2') {
      print('Fetching number fact...');
      try {
        final response = await dio.get('http://numbersapi.com/random/trivia');
        print('Random Number Fact: ${response.data}');
      } catch (e) {
        print('Error fetching number fact: $e');
      }
    } else if (choice == '3') {
      print('Calculating Fibonacci of ${10 * counter}...');
      int result = await computeFibonacci(10 * counter);
      print('Fibonacci result: $result');
    } else if (choice == '4') {
      print('Exiting the program.');
      break;
    } else {
      print('Invalid choice, please try again.');
    }
  }
}

Future<int> computeFibonacci(int n) async {
  if (n == 0 || n == 1) {
    return 1;
  }
  int a = 1;
  int b = 1;
  for (int i = 2; i <= n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }
  return b;
}
