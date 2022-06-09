# 구조체와 클래스
-----------
## 공통점은?
> 변수와 함수를 가질 수 있는 단위이다.
-----------
## 구현 코드

구조체
``` C#
struct Point
{
    public int X;
    public int Y;
    public int Z;
    public Point(int x, int y, int z)
    {
        this.X = x;
        this.Y = y;
        this.Z = z;
    }
    public static Point operator +(Point p1, Point p2)
    {
        return new Point(p1.X + p2.X, p1.Y + p2.Y, p1.Z + p2.Z);
    }
    public String toString()
    {
        return "x: " + X + ", y: " + Y + ", z: " + Z;
    }
}
```


클래스
``` C#
class Point
{
    public int X;
    public int Y;
    public int Z;
    public Point(int x, int y, int z)
    {
        this.X = x;
        this.Y = y;
        this.Z = z;
    }
    public static Point operator +(Point p1, Point p2)
    {
        return new Point(p1.X + p2.X, p1.Y + p2.Y, p1.Z + p2.Z);
    }
    public String toString()
    {
        return "x: " + X + ", y: " + Y + ", z: " + Z;
    }
}
```

코드상으론 선언을 하는 부분을 제외하면 아무런 차이가 없다.
클래스와 마찬가지로 구조체도 필드로 변수와 함수들을 가질 수 있으며 생성자 역시 가질 수 있다.

지만 큰 차이 2가지가 존재한다.
----
## 차이점 (중요)
1. 구조체(struct)는 상속을 할 수 없다.
2. 클래스(class) 객체는 힙(heap)에 할당되지만 구조체(struct) 객체는 스택(stack)에 할당된다.

두 가지 차이중 **2번**이 핵심이다. 
스택의 경우 사용할 수 있는 **메모리 크기가 작고 한정적**인 반면 힙은 **많은 메모리크기**를 가질 수 있다.
하지만 스택의 경우 가비지컬랙션에 의해 관리되지 않기 때문에 성능상 많은 장점이 있다.


실제 메모리 할당이 어떻게 되는지 아래 실험으로 보자.
우선 Main문 안에 아래와 같이 객체 1000개를 차례로 할당 받는 코드를 작성해보자.
Sleep(100)은 100ms 즉 0.1초간 딜레이는 거는 역할을 한다.
``` C#
static void Main(string[] args)
{
    Point []p = new Point[1000];
    for (int i=0; i< 1000; i++)
    {
        p[i] = new Point(i, i + 1, i + 2);
        System.Threading.Thread.Sleep(100);
    }
}
```

그리고 디버깅 모드로 실행시킨 후에 메모리 사용량을 보도록 하자. Visual studio 2017에서는 쉽게 메모리 사용양을 확인할 수가 있다. 중간중간 원하는 지점에서 메모리를 표시해줍니다. 개인적인 생각으론 C#이 가비지컬렉션이 완벽하지 않아서인지 메모리이슈가 많아서 해당기능을 강력하게 지원해주는 것 같다.

아래 구조체(struct)를 객체로 만들때에는 아래와 같이 힙 영역에 차이가 없는 것을 볼 수 있다. 힙을 사용하지 않고 스택을 사용하기 때문이다.
![image](https://user-images.githubusercontent.com/43405887/172782727-61b668db-2dd0-4dcf-bf9d-8e2f234f3d4b.png)

아래 클래스(class)의 경우 시간이 증가함에 따라 객체의 갯수와 힙 메모리의 크기역시 증가하는 것을 볼 수 있다. 
![image](https://user-images.githubusercontent.com/43405887/172782840-c10f602f-731c-4916-ade5-478128691e6e.png)


하지만 구조체로 선언을 했어도 객체를 힙영역에 메모리를 할당할 때가 있다. (예외)
> 1. 모든 필드의 합이 16byte를 넘는 경우
> 2. 구조체안에 클래스 타입을 필드로 가질 경우

C#에서는 **위의 두경우와 상속이 필요한 경우가 아닌 경우라면 구조체로 선언해서 스택(stack) 메모리 영역을 사용하기를 권장**한다.
스택은 기본적으로 가비지 컬렉션의 대상이 아니다.
선언한 **함수가 종료되면 그때그때 해제**가 되기때문에 heap영역을 사용하는 것보다 좋은점이 많다고 생각된다.
가비지 컬랙션이 자동으로 메모리를 해제시켜주긴 하지만 많은 오버해드가 발생할 수가 있다. 가비지 컬랙션에 동작원리를 알면 이해가 갈 것이다. 

되도록 16바이트가 넘지 않는다면 구조체를 사용하는 버릇을 들이는 것이 좋다.


번외로 **C++** 에서는 C#과 다르게 클래스는 public 선언을 하지 않으면 private이 되지만 구조체는 기본적으로 public 으로 된다.
