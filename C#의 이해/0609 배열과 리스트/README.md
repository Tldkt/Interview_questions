# 배열과 리스트
------
## 배열이란?
> 같은 종류의 데이터를 연속적으로 저장하는 변수 타입
> 하지만 실제로 C#은 Stack 메모리 할당이 없기 때문에 실제 메모리에 연속적으로 저장되지 않는다. 여기서 연속적이라는 것은 개념적인 의미
-------
## 배열 구현 코드
*배열 선언
``` C#
자료형[] 배열이름 = new 자료형[배열크기];
int[] a = new int[10];
```

*다차원배열 선언
``` C#
자료형[ , ] = new 자료형[ , ];자료형[ , ,] = new 자료형 [ , , ];자료형[][] = new 자료형[][];
int[,] a = new int[5, 5];
int[][] b = new int[5][];
```

-----
## 리스트란?
> 배열과 유사하게 다수의 데이터를 저장하지만 배열과는 달리 크기가 사전에 정해지지 않는다.
-----
## 리스트 구현 코드
*리스트 선언
``` C#
List<자료형> 변수명 = new List<자료형>();

List<int> list = new List<int>();
```
*리스트 사용
``` C#
// 데이터 입력
list.Add(1);
list.Add(2);
list.Add(3);
list.Add(4);

// list의 개수만큼 반복
for(int i = 0; i < list.Count; i++){
    // 리스트에 입력된 순서로 콘솔 출력
    Console.WriteLine(list[i]);
}
// list의 데이터를 foreach 반복문을 이용해서 데이터를 취득
foreach(var item in list)
{
    // 리스트에 입력된 순서로 콘솔 출력
    Console.WriteLine(item);
}
```

즉, 유저가 입력하는 만큼, 계속해서 데이터를 입력할 수 있습니다. 배열의 경우는 정해진 개수를 초과하게 되면 에러가 발생합니다.

여기까지 보면 리스트가 배열보다 많이 편리해 보입니다. 실무에서도 배열보다는 리스트를 많이 사용합니다.
그러나 리스트에는 치명적인 단점이 있습니다. 리스트라는 것은 연결 리스트 알고리즘으로 구성되어 있습니다. 즉, 입력은 빠릅니다만, 탐색이 매우 느린 알고리즘 구조입니다.
배열은 인덱스 번호로 바로 접근할 수 있지만 리스트는 for문으로 하나씩 탐색해야 하기 때문입니다.

즉, 대량의 데이터를 사용할 때는 리스트보다 배열의 경우가 탐색 속도가 빠릅니다. 그러나 사실, 이건 이론적인 이야기입니다. 최근에는 이런 이론적인 이야기를 무시할 만큼, 놀라운 성능의 하드웨어를 사용합니다. 그래서, 실무에서는 그냥 리스트를 사용합니다. 배열을 사용 함으로 괜히 버그를 만들 필요가 없는 것이지요.
그러나 이것도 엄청난 대량의 데이터(약 1억건 이상의 데이터)라고 한다면 리스트가 아닌 배열을 사용하는 것도 생각해 볼 필요가 있습니다.
