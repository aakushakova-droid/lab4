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
void task_Proc19(); // Задача Integer35 цілком

// Integer35 - Дано кількість годин.
// Визначити кількість діб і залишок годин
//
bool in_hours(int &hours); // Введення з перевіркою Integer35
int hours_to_days(int &hours); // Підрахунок Integer35
void out_res_Int35(int days, int hours); // Виведення результатів Integer35
void task_Int35(); // Задача Integer35 цілком

int main() {
  int menu;
  cout << "Номер завдання: ";
  cin >> menu;
  // перемикання між завданнями
  switch(menu) {
    case 1: task_Proc19(); break;
    case 2: task_Int35(); break;
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
  // Витзначення зміниних
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

// Завдання Integer35 цілком
void task_Int35() {
  // Визначення змінних
  int hours;
  int days;
  // Ввдення даних з перевіркою
  if (in_hours(hours))
    // Якщо не вдалося ввести дані, виводимо повідомлення помилки
    cout << "Кількість годин має бути більша або рівна 0" << endl;
  else {
    // Обчислюємо кількість годин
    days = hours_to_days(hours);
    // Виводимо результат
    out_res_Int35(days, hours);
  }
}

// Функція введення годин з перевіркою
bool in_hours(int &hours) {
  cout << "Integer35" << endl << endl;
  cout << "Кількість годин: ";
  // Зчитуємо кількість годин
  cin >> hours;
  // Якщо не вдалося зчитати число, повертаємо true (помилка введення)
  if (cin.fail())
    return true;
  // Якщо кілкість годин менше 0, повертаємо true (помилка введення)
  else if (hours < 0)
    return true;
  // Інакше повертаємо false (успішне введення)
  else return false;
}

// Функція обчислення днів
int hours_to_days(int &hours) {
  int days = hours / 24;
  hours = hours % 24;
  return days;
}

// Функція виведення результату завдання Integer35
void out_res_Int35(int days, int hours) {
  cout << "Днів: " << days << endl;
  cout << "Годин: " << hours << endl;
}
