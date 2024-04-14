import 'dart:io';
import 'package:dio/dio.dart';

void main() async {
  int counter = 0;
  String numberFact = '';

  Dio dio = Dio();

  while (true) {
    print('1. Increment Counter');
    print('2. Get Random Number Fact');
    print('3. Exit');
    stdout.write('Choose an option: ');
    String? choice = stdin.readLineSync();

    if (choice == '1') {
      counter++;
      print('Counter incremented! Current value: $counter');
    } else if (choice == '2') {
      print('Fetching number fact...');
      try {
        final response = await dio.get('http://numbersapi.com/random/trivia');
        numberFact = response.data;
        print('Random Number Fact: $numberFact');
      } catch (e) {
        print('Error fetching number fact: $e');
        print('Failed to fetch fact!');
      }
    } else if (choice == '3') {
      print('Exiting the program.');
      break;
    } else {
      print('Invalid choice, please try again.');
    }
  }
}
