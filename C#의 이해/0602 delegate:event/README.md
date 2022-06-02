# Delegate(대리자)
> 메서드를 대신 호출해주는 기법
> C/C++의 참조 포인터와 유사하지만 데이터를 안전하게 처리할 수 있다는 특징이 있다.
-----------
## 대리자란?
예시
대리자 선언
``` C#
public delegate void myDelegate(string msg);
```

대리자가 참조할 메소드
``` C#
public static void methodA(string msg){
  Console.WriteLine("method A :"+msg);
}

public static void methodB(string msg){
  Console.WriteLine("mothod B:"+msg):
}
```

대리자가 메소드를 참조 후 호출
``` C#
//대리자 인스턴스 생성
MyDelegate del;

//대리자 인스턴스 del은 methodA 메소드의 주소를 참조합니다.
del new myDelegate(methodA);

//대리자 인스턴스 del은 methodA를 참조하고 있으므로 methodA메소드를 사용할 수 있습니다.
//대리자 인스턴스가 마치 methodA 함수처럼 쓰이고 있습니다.
del("AAA");

del new myDelegate(methodB);
del("BBB");
```

실행결과
```
method A :AAA
method B :BBB
```

<img width="862" alt="image" src="https://user-images.githubusercontent.com/43405887/171602809-e8daa3a3-1b8b-43c8-bd2b-843c8942f7ec.png">


------
## 왜 사용해야 하는 걸까?
예제문제
> 예제
``` C#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CsTest
{
  class Program
  {
    delegate void DelegateMethod(int a);

    static void Method1(int a)
    {
      Console.WriteLine("Method1이 호출되었습니다. a == {0}", ++a);
    }
    static void Method2(int a)
    {
      Console.WriteLine("Method2이 호출되었습니다. a == {0}", ++a);
    }
    static void Method3(int a)
    {
      Console.WriteLine("Method3이 호출되었습니다. a == {0}", ++a);
    }
    static void Method4(int a)
    {
      Console.WriteLine("Method4이 호출되었습니다. a == {0}", ++a);
    }
    static void Method5(int a)
    {
      Console.WriteLine("Method5이 호출되었습니다. a == {0}", ++a);
    }
    static void Method6(int a)
    {
      Console.WriteLine("Method6이 호출되었습니다. a == {0}", ++a);
    }
    static void Method7(int a)
    {
      Console.WriteLine("Method7이 호출되었습니다. a == {0}", ++a);
    }
    static void Method8(int a)
    {
      Console.WriteLine("Method8이 호출되었습니다. a == {0}", ++a);
    }
    static void Method9(int a)
    {
      Console.WriteLine("Method9이 호출되었습니다. a == {0}", ++a);
    }

    static void Main(params string[] args)
    {
      DelegateMethod method = null;

      method += Method1;
      method += Method2;
      method += Method3;
      method += Method4;
      method += Method5;
      method += Method6;
      method += Method7;
      method += Method8;
      method += Method9;

      method(0);

      Console.WriteLine("끝.");
      Console.ReadLine();
      }
    }
  }
```

<img width="497" alt="image" src="https://user-images.githubusercontent.com/43405887/171604159-efa81070-400a-4d3c-9900-a0de56447b46.png">

 C의 함수 포인터에는 없었던 기가 막힌 기능입니다.
바로 한 대리자가 여러 메서드를 끌어 안고 있다가 연쇄적으로 몽땅 실행할 수 있다는 거죠.
단, 이 때 조건은 반환 형이 void이어야 된다는 겁니다. 생각해 보세요.
여러 개의 메서드가 같은 매개변수를 받기는 했지만, 반환 값이 제각각 다르다면
그 다른 것 중에서 무엇을 선택해야 할 지가 .NET Framework의 입장에서는 모호합니다.
그렇기 때문에 여러 개의 메서드를 대리자 안에 넣고 싶다면 반드시 반환형이 void이어야 합니다.
위의 예제를 그림으로 표현하면 다음과 같습니다.

<img width="281" alt="image" src="https://user-images.githubusercontent.com/43405887/171604284-43856a04-5596-4e8e-b0b5-5f5dd5bdc224.png">

``` C#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CsTest
{
class Program
{
delegate void DelegateMethod(int a);

static void Method1(int a)
{
Console.WriteLine("Method1이 호출되었습니다. a == {0}", ++a);
}
static void Method2(int a)
{
Console.WriteLine("Method2이 호출되었습니다. a == {0}", ++a);
}
static void Method3(int a)
{
Console.WriteLine("Method3이 호출되었습니다. a == {0}", ++a);
}
static void Method4(int a)
{
Console.WriteLine("Method4이 호출되었습니다. a == {0}", ++a);
}
static void Method5(int a)
{
Console.WriteLine("Method5이 호출되었습니다. a == {0}", ++a);
}
static void Method6(int a)
{
Console.WriteLine("Method6이 호출되었습니다. a == {0}", ++a);
}
static void Method7(int a)
{
Console.WriteLine("Method7이 호출되었습니다. a == {0}", ++a);
}
static void Method8(int a)
{
Console.WriteLine("Method8이 호출되었습니다. a == {0}", ++a);
}
static void Method9(int a)
{
Console.WriteLine("Method9이 호출되었습니다. a == {0}", ++a);
}

static void Main(params string[] args)
{
DelegateMethod method = null;

method += Method1;
method += Method2;
method += Method3;
method += Method4;
method += Method5;
method += Method6;
method += Method7;
method += Method8;
method += Method9;

method -= Method2;
method -= Method4;
method -= Method6;
method -= Method8;

method(0);

Console.WriteLine("끝.");
Console.ReadLine();
}
}
}
```

<img width="317" alt="image" src="https://user-images.githubusercontent.com/43405887/171604692-060aa1e2-4d8d-4457-9ce4-bd4593f31007.png">
