# Домашнее задание

* Прислать как минимум два вопроса по пройденным темам
* Создать перечисление с 3 значениями. Назовите ее, например, CharacterCondition(не забывайте про соблюдение name convention!!!)
	* Первое значение принимается, когда персонаж статичен (напр., Idle)
	* Второе - когда игрок движется (Moving)
	* Третье - когда у вас зажата кнопка действия (Action)

* Также создать структуру с тремя переменными типа int32 или int8(т.к. другими целочисленными типами Blueprint'ы не могут взаимодействовать). Назовите - ConditionCounter
	* Первое значение увеличивается, когда игрок статичен (IdleCount)
	* Второе - подвижен (MoveCount)
	* Третье - когда нажата кнопка действия (ActionCount)

##### Ожидаемое поведение:
У персонажа заведите две переменные: одна - созданный enum, другая - struct (не забудьте включить их файлы в заголовок персонажа, чтобы вы могли их использовать внутри класса персонажа)

* При нажатии кнопки действия (напр., пробел) выполняется метод OnActionButtonPressed(), в котором переменная enum принимает значение Action.
* После отжатия кнопки действия метод OnActionButtonReleased() меняет переменную перечисления на значение Idle, если вы стоите, или Moving, если вы двигаетесь 
* В методе Tick(float DeltaSeconds) необходимо увеличивать соответствующий состоянию компонент структуры.
	* С перечислениями можно работать при помощи switch
	``` c++
	switch(Test)
	{
		case ETestEnum::Idle :
		...
			break;
		case ETestEnum::Moving :
		...
			break;
		...
	}
	```
	* Компоненты структур по умолчанию публичны и с ними можно оперировать как с обычными переменными
	``` c++
	TestStruct.X += 1;
	TestStruct.Y += TestStruct.X;
	```
	
###### Подсказка: получить скорость передвижения можно из вектора ускорения Актера

# Видео с занятия
[Оно было провальное =-{](http://www.youtube.com/watch?v=ngO4J4V0zZ0) Качества 1080 еще может не быть, т.к. видео еще обрабатывается


# Вопросы

Вопросы сюда!
> **napolinkinpark3r@gmail.com** 

с темой письма **[DML][UE4]**

# Как сдавать 

Используйте сервис ГитХаба, называемый Gist

Имя даете согласно дате старта домашнего задания (напр. Oct21HomeTask_<ЗдесьФамилия_ИИмяЛатиницей>)

Формат:
``` c++
/*
 * /*Название файла*/
 */

	Внизу функционал, который вы реализовывали для выполнения задания. 
	Переменные, методы, возможно, include'ы и прочее.
	Код всего файла присылать не надо!

```
Пример:
``` c++
/*
 * Test2.h
 */
UPROPERTY(EditAnywhere, BlueprintReadWrite)
int32 Var;

UFUNCTION(BlueprintCallable)
void Func();

/*
 * Test2.cpp
 */
void TestClass::Func()
{
	Var += 1;
}
////////////////////////////////
/*
 * Test3.h
 */
 и т.д.
////////////////////////////////
```