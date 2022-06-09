# Event
>객체에 특정 작업의 실행을 알리는 메시지, 예를 들면 사용자와의 인터랙션(Interaction)과 같은 처리.
>ex) 버튼을 터치했을 경우나 속성값 변경 등의 사건.
---------
## Event란?
 - 이벤트는 일반적으로 delegate model을 기반으로 하며, 이는 관찰자 디자인 패턴(Observer Design Pattern)을 따른다.
 - Observer Design Pattern : 구독자(Subscriber)가 공급자(Provider)를 등록하고 공급자(Provider)로부터 알림을 수신하는 데 사용
 <img width="643" alt="image" src="https://user-images.githubusercontent.com/43405887/172790578-5acaed29-0b4f-4b50-890b-47a9a2729152.png">

## 코드
---------
``` C#
class Counter
{
    public event EventHandler ThresholdReached;

    protected virtual void OnThresholdReached(EventArgs e)
    {
        EventHandler handler = ThresholdReached;
        handler?.Invoke(this, e);
    }
    // provide remaining implementation for the class
}
```

 * 여기서 EventHandler는 Delegate이다. Delegate임으로 여기에 연결된 함수들은 호출(Invoke)와 동시에 호출되게 된다.
 <img width="692" alt="image" src="https://user-images.githubusercontent.com/43405887/172790927-bf23c5d3-34fe-4f50-9b04-79716ed5d38a.png">

 .Net에서 제공하고 있는 Event 처리 관련 delegate, 이 두가지를 이용하여 대부분의 이벤트 시나리오를 처리할 수 있다.
 EventHandler의 경우엔 데이터가 없는 이벤트 처리, EventHandler<TEventArgs>는 데이터를 포함하는 이벤트에 대해서 처리할 수 있다.

---------
## 예제코드
``` C#
  using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication42
{
    public delegate void MyEventHandler(string message);

    class Publisher
    {
        public event MyEventHandler Active;

        public void DoActive(int number)
        {
            if (number % 10 == 0)
                Active("Active!" + number);
            else
                Console.WriteLine(number);
        }
    }

    class Subscriber
    {
        static public void MyHandler(string message)
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            Publisher publisher = new Publisher();
            publisher.Active += new MyEventHandler(MyHandler);

            for (int i = 1; i < 50; i++)
                publisher.DoActive(i);
        }
    }
}
```
실행 결과
  ```
1

..

Active!10

..

Active!40

..

49

계속하려면 아무 키나 누르십시오 . . .
                                   ```
