# 지역변수와 전역변수
클래스와 같은 레벨에서 선언된 변수를 전역 변수(global variable) 또는 필드(field)라고 하며, 함수 레벨에서 선언된 변수를 지역 변수(local variable)라고 합니다.

이때 동일한 이름으로 변수를 전역 변수와 함수 내의 지역 변수로 선언할 수 있습니다.

함수 내에서는 함수 범위에 있는 지역 변수를 사용하고, 함수 범위 내에 선언된 변수가 없으면 전역 변수 내에 선언된 변수를 사용합니다.

단 C#에서는 전역 변수가 아닌 필드라는 단어를 주로 사용하며, 전역 변수는 언더스코어(_) 또는 m_ 접두사를 붙이는 경향이 있습니다.

## 예제코드 (함수의 범위)
``` C#
using System;

public class FunctionScope
{
    static string message = "전역 변수";   //필드

    static void ShowMessage()
    {
        string message = "지역 변수";
        Console.WriteLine(message);   //지역 변수
    }

    static void Main()
    {
        ShowMessage();
        Console.WriteLine(message);   //전역 변수
    }
}
```

실행결과
```
지역 변수
전역 변수
```

Main() 메서드와 동일한 레벨에 static string message = "전역 변수"; 형태로 문자열 변수를 선언할 수 있습니다.

이렇게 클래스 내에서 선언하는 변수는 Main() 메서드와 ShowMessage() 함수에서 모두 사용할 수 있는 전역 변수가 됩니다. 다만 ShowMessage() 함수에서는 이름이 동일한 message 변수를 선언하고 사용하기에 전역 변수가 아닌 함수 내에서 선언된 지역 변수를 씁니다.
