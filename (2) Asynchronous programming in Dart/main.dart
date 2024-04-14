import 'package:flutter/material.dart';
import 'package:dio/dio.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Counter & Random Number Fact',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key}) : super(key: key);

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;
  String _numberFact = '';

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  Future<void> _fetchNumberFact() async {
    print('Fetching number fact...');
    try {
      Dio dio = Dio();
      final response = await dio.get('http://numbersapi.com/random/trivia');
      print('Response received: ${response.data}');
      setState(() {
        _numberFact = response.data;
      });
    } catch (e) {
      print('Error fetching number fact: $e');
      setState(() {
        _numberFact = 'Failed to fetch fact!';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Counter & Random Number Fact'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headline4,
            ),
            const SizedBox(height: 20),
            ElevatedButton(
              onPressed: _fetchNumberFact,
              child: const Text('Get Random Number Fact'),
            ),
            const SizedBox(height: 20),
            Text(
              '$_numberFact',
              style: const TextStyle(fontSize: 16),
              textAlign: TextAlign.center,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
    );
  }
}
