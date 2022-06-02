# 가상함수
-----------
## 가상함수란?
> 부모 클래스에서 **virtual** 키워드를 사용하여 함수를 만들면, **자식 클래스에서 이 함수를 재정의 할 수 있도록 허용**하겠다는 의미입니다.
-----------
## 특징
1. virtual 이 붙은 함수는 자식 클래스에서 재정의가 가능합니다. -> 정의
2. 자식 클래스에서는 new 또는 override 키워드가 사용가능하다.  
2.1 override는 재정의를 하겠다는 **확장**의 의미이고, new 는 **기본 클래스를 숨기는 의미**이다. 
4. 자식클래스의 함수 **시그니쳐가 동일**해야 재정의가 가능하다.
5. 자식클래스의 함수는 **base** 키워드를 사용해 부모 클래스의 함수를 호출 할 수 있습니다.
6. abstract 와는 달리 자식클래스에서 구현은 **선택**이다. (구현 안하면 부모의 함수 사용)
7. static, abstract, private, override 키워드와는 사용이 불가능하다.

------------
## 예제
``` C#
public class Monster
{
    //부모 
    public virtual void hit()
    {
        Console.WriteLine("Monster hit");
    }
}
 
public class Orc : Monster
{
    //override 키워드 사용
    public override void hit()
    {
        Console.WriteLine("Orc hit");
    }
}
 
public class Elf : Monster
{
    //new 키워드 사용
    public new void hit()
    {
        Console.WriteLine("Elf hit");
    }
}
 
public class Wolf : Monster
{
    //어떤 키워드도 사용하지 않음
    public void hit()
    {
        Console.WriteLine("Wolf hit");
    }
}
```

위 코드를 실행해보겠습니다.

``` C#
class Program
 {
     static void Main(string[] args)
     {
         Monster monster1 = new Monster();
         Orc monster2 = new Orc();
         Elf monster3 = new Elf();
         Wolf monster4 = new Wolf();
 
         monster1.hit();
         monster2.hit();
         monster3.hit();
         monster4.hit();
 
         Monster monster5 = new Orc();
         Monster monster6 = new Elf();
         Monster monster7 = new Wolf();
 
 
         Console.WriteLine("////////////////////");
         monster5.hit();
         monster6.hit();
         monster7.hit();
 
     }
 }
 ```
 
 <img width="241" alt="image" src="https://user-images.githubusercontent.com/43405887/171586893-fd9071c1-837e-4c7d-b1f2-c5e04902768f.png">

monster 1~4 는 그대로 잘 출력됩니다. 사실 각 클래스에 자기 자신을 인스턴스로 담으면 virtual의 의미가 전혀 없습니다.
하지만 monster 5~7은 결과가 다릅니다.
ovrride를 한 Orc만 제대로 재정의되어 자신의 hit를 출력하고 있고, **나머지는 상위 클래스의 hit를 출력합니다.**

여기서 new 키워드의 기본 클래스를 숨긴다는 의미도 알 수 있습니다. 상위 클래스 변수에 담기면 하위 클래스가 아닌 상위 클래스의 함수를 호출한다는 것입니다. ( new 키워드를 사용하지 않은 경우, 즉 Wolf의 경우에는 new와 동일한 동작을 합니다.)

> 결국 virtual과 override를 사용하여 재정의하는 이유는 상위 클래스 변수에 하위 클래스 인스턴스를 담을 때, 하위 클래스의 함수를 호출하고 싶기 때문입니다.  
> ```Monster monster5 = new Orc(); ```

----------
## 가상함수(virtual)의 활용
그럼 대체 언제 활용하는 걸까
