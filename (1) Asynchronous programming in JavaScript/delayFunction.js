// Оголошення функції delay, яка приймає один аргумент - кількість мілісекунд (ms)
function delay(ms) {
  // Створення нового промісу за допомогою конструктора Promise
  return new Promise(resolve => {
    // Виклик функції setTimeout, яка встановлює затримку
    setTimeout(resolve, ms); 
// Після завершення затримки викликається функція resolve
  });}
// Виклик функції delay з аргументом 2000 мілісекунд (тобто 2 секунди),
// після чого викликатиметься метод then для обробки результату промісу
delay(2000).then(() => alert('виконалось через 2 секунди'));