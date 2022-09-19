# 1 лабораторная (Хаммурапи)
## Реализация
### Структуры
```
City: содержит ресурсы города
Gameplay: содержит псевдо-рандомные поля игрового процесса и статистику
PlayerDecision: содержит данные, вводимые игроком во время каждого раунда
```

### Константы
Константы, используемые в качестве граничных значений и коэффициентов вынесены в начало кода
```
const float kMinRatCoef = 0.0f;
const float kMaxRatCoef = 0.07f;
const int kMinRipeWheatBushelsPerAcre = 1;
const int kMaxRipeWheatBushelsPerAcre = 6;
const int kMinAcrePrice = 17;
const int kMaxAcrePrice = 26;
const int kMaxAcresPerCitizen = 10;
const int kWheatBushelsPerCitizen = 20;
const float kWheatBushelsToPlantPerAcre = 0.5f;
const float kDeathPercentToLose = 0.45f;
const float kPlagueChance = 0.15f;
const int kReignLenth = 10;
```

### Логика игры
Для псевдо-рандомной генерации чисел был использован std::default_random_engine
Все логика игры разделена не несколько функций:
```
void CalculateResourcesAndEvents(City& city, Gameplay& gameplay, PlayerDecision& decision):
Вычисление псевдо-рандомных значений и изменение количества ресурсов для последующего вывода статистики советником

void AdviserReport(City& city, Gameplay& gameplay):
  Доклад советника с собранной статистикой
  
template <typename T> void InputVar(T& input):
  Ввод переменной, чтобы не плодить много схожих обработок неправильного ввода пользователя
  
void InputPlayerDecision(City& city, Gameplay& gameplay, PlayerDecision& decision):
  Ввод решений игрока в каждом раунде
  
void SummarizeReign(City& city, Gameplay& gameplay):
  Вывод результата качества правления игрока
  
void SaveGame(City& city, Gameplay& gameplay):
  Сохранить прогресс в файл
  
void LoadGame(City& city, Gameplay& gameplay):
  Загрузить прогресс из файла
```

## Пример вывода программы (сохранение сделано на этом примере)
```
Повелитель, желаешь продолжить сохранённую игру? (1 - Да, 0 - Нет): 0
Мой повелитель, твоё правление начинается
Население города составляет 100 человек;
В амбарах лежит 2800 бушелей пшеницы;
Город занимает 1000 акров;
1 акр земли стоит сейчас 24 бушель.

Что пожелаешь, повелитель?
Сколько акров земли повелеваешь купить? 0
Сколько акров земли повелеваешь продать? 0
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 2000) 2000
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 1000

Мой повелитель, соизволь поведать тебе
в 1 году  твоего высочайшего правления
0 человек умерли с голоду, и 12 человек прибыли в наш великий город;
Население города сейчас составляет 112 человек;
Мы собрали 2000 бушелей пшеницы, по 2 бушеля с акра;
Крысы истребили 79 бушелей пшеницы, оставив 2221 бушеля в амбарах;
Город сейчас занимает 1000 акров;
1 акр земли стоит сейчас 26 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 0
Сколько акров земли повелеваешь купить? 0
Сколько акров земли повелеваешь продать? 0
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 2240) 2000
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 440

Мой повелитель, соизволь поведать тебе
в 2 году  твоего высочайшего правления
12 человек умерли с голоду, и 9 человек прибыли в наш великий город;
Чума уничтожила половину населения;
Население города сейчас составляет 54 человек;
Мы собрали 440 бушелей пшеницы, по 1 бушеля с акра;
Крысы истребили 13 бушелей пшеницы, оставив 428 бушеля в амбарах;
Город сейчас занимает 1000 акров;
1 акр земли стоит сейчас 19 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 0
Сколько акров земли повелеваешь купить? 0
Сколько акров земли повелеваешь продать? 500
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 1080) 1080
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 500

Мой повелитель, соизволь поведать тебе
в 3 году  твоего высочайшего правления
0 человек умерли с голоду, и 50 человек прибыли в наш великий город;
Население города сейчас составляет 104 человек;
Мы собрали 500 бушелей пшеницы, по 1 бушеля с акра;
Крысы истребили 294 бушелей пшеницы, оставив 8804 бушеля в амбарах;
Город сейчас занимает 500 акров;
1 акр земли стоит сейчас 20 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 0
Сколько акров земли повелеваешь купить? 200
Сколько акров земли повелеваешь продать? 0
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 2080) 2080
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 600

Мой повелитель, соизволь поведать тебе
в 4 году  твоего высочайшего правления
0 человек умерли с голоду, и 20 человек прибыли в наш великий город;
Население города сейчас составляет 124 человек;
Мы собрали 600 бушелей пшеницы, по 1 бушеля с акра;
Крысы истребили 124 бушелей пшеницы, оставив 2900 бушеля в амбарах;
Город сейчас занимает 700 акров;
1 акр земли стоит сейчас 18 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 0
Сколько акров земли повелеваешь купить? 0
Сколько акров земли повелеваешь продать? 0
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 2480) 2480
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 700

Мой повелитель, соизволь поведать тебе
в 5 году  твоего высочайшего правления
0 человек умерли с голоду, и 5 человек прибыли в наш великий город;
Население города сейчас составляет 129 человек;
Мы собрали 2800 бушелей пшеницы, по 4 бушеля с акра;
Крысы истребили 71 бушелей пшеницы, оставив 2799 бушеля в амбарах;
Город сейчас занимает 700 акров;
1 акр земли стоит сейчас 17 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 0
Сколько акров земли повелеваешь купить? 0
Сколько акров земли повелеваешь продать? 0
Сколько бушелей пшеницы повелеваешь съесть? (Для выживания жителю необходимо 20 бушелей; всего 2580) 2580
Сколько акров земли повелеваешь засеять? (На один акр расходуется 0.5 бушеля пшеницы) 250

Мой повелитель, соизволь поведать тебе
в 6 году  твоего высочайшего правления
0 человек умерли с голоду, и 0 человек прибыли в наш великий город;
Население города сейчас составляет 129 человек;
Мы собрали 1500 бушелей пшеницы, по 6 бушеля с акра;
Крысы истребили 6 бушелей пшеницы, оставив 1588 бушеля в амбарах;
Город сейчас занимает 700 акров;
1 акр земли стоит сейчас 24 бушель.

Что пожелаешь, повелитель?
Желаешь ли на время прервать игру? (1 - Да, 0 - Нет) 1
```