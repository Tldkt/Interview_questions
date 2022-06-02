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
위 코드로 설명해보자면,
>모든 몬스터가 Monster라는 하나의 클래스로 만들어지면 좋겠지만, 각자의 특징에 따라 Monster 하위 클래스가 만들어질 수 있습니다. 
>그리고 Player가 몬스터를 때렸을때, 해당 몬스터의 hit를 호출한다고 칩시다.

### 만약에 virtual을 사용하지 않으면?
``` C#
void attack(Orc monster)
 {
     monster.hit();
 }
 void attack(Elf monster)
 {
     monster.hit();
 }
 void attack(Wolf monster)
 {
     monster.hit();
 }
 ```
 ->  모든 해당 몬스터 즉, orc, elf, wolf 별로 hit 함수를 오버로딩하여 별도로 호출해야 합니다.  
 왜냐하면 virtual을 사용하지 않으면 저렇게 해야만 해당 몬스터의 hit를 호출할 수 있으니까요. ( 사용하는 입장에서 Orc가 hit를 override를 했을지, 안했을지 모르잖아요?)
 
 ### 만약에 virtual 함수를 사용해서 하위 클래스에서 해당 함수를 override 했다면?
 ``` C#
 void attack(Monster monster)
{
    monster.hit();
}
```
이게 끝이다.
monster.hit() 가 호출될 때 Monster 변수에 담긴 인스턴트별로 재정의 되어있는 hit 함수를 호출해 줄테니까요.  
몬스터 종류가 무수히 많아졌을 때, 마냥 몬스터별로 함수를 오버로딩해서 작성할 수는 없습니다. 반드시 virtual이 필요해지죠.



**사실 위와 같은 방식은 abstract 또는 interface로도 가능은 하죠.**
하지만 abstract, interface와는 달리 **virtual은 선택적으로 재정의가 가능하다는 점**과 virtual 함수를 가진 상위 클래스도 인스턴스 생성이 가능하다는 점이 있습니다.

 솔직히 위의 Hit함수만 보면 어차피 모든 클래스가 구현을 해야한다면 abstract로 만드는게 맞지 않냐고 할 수 있습니다. Hit만 있다면 맞는 말이죠. 그리고 Monster라는 하나의 그룹을 정의하는 거라면 abstract가 맞습니다. 하지만 Orc 중에서 엘리트 Orc는 Hit시 반격을 하고 싶다면? 모든 Orc의 함수는 동일하게 상속받아 행동하고, Move만 재정의 해야 한다면, virtual이 필요해지게 되죠. Orc도 하나의 인스턴스로써 동작해야하고, 엘리트 Orc는 hit를 재정의해서 만들어져야 하니까요. 즉, 특정 개체로부터 특정 함수만을 선택적으로 재정의하고, 그 외에는 그대로 상속 해야할 경우인거죠.

 결국 각자의 특징에 알맞게 사용해야겠죠. 예를 들어
 1. abstract는 하위 클래스가 **반드시 구현**해야하는 것을 명시하거나 하나로 묶을 때
 2. interface는 class에 한정되지 않고, **범용적으로 사용할 때 또는 디자인 정의**가 필요할 때
 3. virtual은 일부 함수에 대해 **선택적으로 재정의**가 필요할 때
