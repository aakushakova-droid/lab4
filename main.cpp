#include <iostream>
#include <cmath>
using namespace std;

// Proc 19
//
// Описати процедуру LoanPayment(S, r, n, P),
// яка обчислює щомісячний платіж P за кредитом:
//   P = (S·r·(1+r)^n)/((1+r)^n - 1),
//   де S - сума кредиту,
//     r - місячна процентна ставка,
//     n - кількість місяців
// (S, r, n - вхідні, P - вихідний параметр дійсного типу).
// За допомогою цієї процедури знайти платежі для трьох різних кредитів.
//
double LoanPayments(double S, double r, double n); // Визначення функції
void proc19_oneRun(); // Допоміжна фунція для одного набору даних
void task_Proc19(); // Задача Proc19 цілком

// Proc35
//
// Описати функцію Even(K) логічного типу, яка повертає True, якщо
// цілий параметр K є парним, і False в іншому випадку. З її допомогою
// знайти кількість парних чисел в наборі з 5 цілих чисел
bool Even(int K); // Визначення функції
void task_Proc35(); // Завдання Proc35 цілком

// Integer35 - Дано кількість годин.
// Дано прямокутник довжиною A і шириною B. Знайти, скільки
// квадратних плиток зі стороною C можна вмістити та яка частина
// прямокутника залишиться незаповненою?
//
bool in_data(int &A, int &B, int &C); // Введення з перевіркою Integer35
int fit_tiles(int &A, int &B, int &C); // Підрахунок Integer37
void out_res_Int37(int size, int tile, int fit); // Виведення результатів Integer37
void task_Int37(); // Задача Integer37 цілком

int main() {
  int menu;
  cout << "Номер завдання: ";
  cin >> menu;
  // перемикання між завданнями
  switch(menu) {
    case 1: task_Proc19(); break;
    case 2: task_Proc35(); break;
    case 3: task_Int37(); break;
    default: cout << "Невірний номер завдання! (Тільки 1, 2)" << endl;
  }
  return 0;
}

// Функція обчислення щомісячного платежа
double LoanPayments(double S, double r, double n) {
  double power = pow(1 + r, n);
  return (S * r * power) / (power - 1);
}

// Завадання Proc19 цілком
void task_Proc19() {
  cout << "Proc19" << endl << endl;
  proc19_oneRun();
  proc19_oneRun();
  proc19_oneRun();
}

// Виконання завдання Proc19 для одного набору даних
// Допоміжна функція для зменшення дублікації коду
void proc19_oneRun() {
  // Визначення зміниних
  double S, r, n;
  // Зчитування даних (без перевірки)
  cout << "Введіть суму кредиту: ";
  cin >> S;
  cout << "Введіть місячну процентну ставку: ";
  cin >> r;
  // Переводимо відсоткове значення у дробове
  r = r / 100;   cout << "Введіть кількість місяців: ";
  cin >> n;
  // Розрахунок та виваедення результату
  cout << "Щомісячний платіж: " << LoanPayments(S, r, n) << endl << endl;
}

// Функція перевірки парності числа
bool Even(int K) {
  return K % 2 == 0;
}

// Завдання Proc35 цілком
void task_Proc35() {
  cout << "Proc35" << endl << endl;
  // Визначення змінних
  int a, b, c, d, e;
  // Змінна-лічильник результату
  int count = 0;
  // Введення даних
  cout << "Введіть 5 цілих чисел: ";
  cin >> a >> b >> c >> d >> e;
  // Виконання перевірки та збільшення лічильника
  if (Even(a))
    count = count + 1;
  if (Even(b))
    count = count + 1;
  if (Even(c))
    count = count + 1;
  if (Even(d))
    count = count + 1;
  if (Even(e))
    count = count + 1;
  // Виведення результату
  cout << "Парних чисел у наборі: " << count << endl;
}

// Завдання Integer37 цілком
void task_Int37() {
  // Визначення змінних
  int A, B, C;
  int result;
  // Ввдення даних з перевіркою
  if (in_data(A, B, C))
    // Якщо не вдалося ввести дані, виводимо повідомлення помилки
    cout << "Помилка введення" << endl;
  else {
    // Обчислюємо кількість годин
    result = fit_tiles(A, B, C);
    // Виводимо результат
    out_res_Int37(A * B, C, result);
  }
}

// Функція введення годин з перевіркою
bool in_data(int &A, int &B, int &C) {
  cout << "Integer37" << endl << endl;
  cout << "Введіть сторони прямокутника: ";
  // Зчитуємо сторони пярмокутника
  cin >> A >> B;
  // Якщо не вдалося зчитати число, повертаємо true (помилка введення)
  if (cin.fail()) {
    cout << "Не вдалося зчитати дані" << endl;
    return true;
  }
  // Якщо сторона прямокутника менше 0, повертаємо true (помилка введення)
  else if (A <= 0 || B <= 0) {
    cout << "Сторона прямокутника має бути більша за 0" << endl;
    return true;
  }
  cout << "Введіть розмір плитки: ";
  // Зчитуємо розмір плитки
  cin >> C;
  // Якщо не вдалося зчитати число, повертаємо true (помилка введення)
  if (cin.fail()) {
    cout << "Не вдалося зчитати дані" << endl;
    return true;
  }
  // Якщо сторона плитки менше 0, повертаємо true (помилка введення)
  else if (C <= 0) {
    cout << "Сторона плитки має бути більша за 0" << endl;
    return true;
  }
  // Повертаємо false (успішне введення)
  else return false;
}

// Функція обчислення днів
int fit_tiles(int &A, int &B, int &C) {
  return (A / C) * (B / C);
}

// Функція виведення результату завдання Integer37
void out_res_Int37(int size, int tile, int fit) {
  cout << "Можна вмістити плиток: " << fit << endl;
  cout << "Залишиться незаповненою: " << size - fit * tile * tile << endl;
}
