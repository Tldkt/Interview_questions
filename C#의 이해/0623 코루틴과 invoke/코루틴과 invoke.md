# 코루틴(Coroutine)
- 여러 개의 루틴이 동시에 실행되며 서로 제어를 넘겨주는 방식.

- yield return을 사용하여 현재 위치를 기억하고 다른 루틴에게 수행 권한을 넘겨서 여러개의 쓰레드가 동시 동작하는 것과 같은 효과를 제공한다.

- 실제로는 단일 쓰레드 이기 때문에 멀티쓰레드가 가지는 교착 상태 경합 등의 문제에서 자유롭다는 장점이있다.

- 특정 조건이 충족될때까지 실행 상태를 지연시킬 수 있다.

- GameObject의 Active가 off가 된다면 이미 실행 중이었던 코루틴은 정지되며, StartCoroutine은 오류가 발생한다.

- 정지된 코루틴은 GameObject가 다시 Active가 되더라도 재 실행되지 않는다.
## 코루틴 예제코드

``` C#
public void MyMethod()
{
    StartCoroutine(MyCoroutine(int num));
}

IEnumerator MyCoroutine(int num)
{
    yield return new WaitForSeconds(3f); // 3초 지연
    Debug.Log(num);
}
```

# Invoke
 - 매개변수로 넘겨주는 시간 만큼 함수를 지연호출할 수 있다.

 - GameObject의 Active가 off 상태에서도 호출된다.

 - InvokeRepeat를 사용할 때 지연시간을 변수로 두고 변경하더라도 최초에 넘겼던 파라미터의 값으로 적용된다.

 - 지연시간 이외의 파라미터를 전달할 수 없다.

## invoke 예제 코드
``` c#
// 기본형
Invoke("함수이름", 시간);

// 반복 호출
InvokeRepeating("함수이름", 지연시간, 반복시간);

// 모든 Invoke 함수 취소
CancelInvoke(); 

// 함수가 실행되고있는지 조사
IsInvoking("함수이름");
```

# 차이점
<img width="484" alt="image" src="https://user-images.githubusercontent.com/43405887/175224677-b62d6c66-c421-4a2e-87e7-94e8c32ab623.png">
