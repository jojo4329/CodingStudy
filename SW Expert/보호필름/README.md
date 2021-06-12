# 문제링크
[SW Export 보호필름](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu)

# 문제분석
1. 가로방향으로 W개, 두께 D, 합격기준 K
 D 3이상 13이하
 W 1이상 20이하
 K 1이상 D 이하
2. 특성 A(0), B(1)
3. 세로방향으로 동일한 특성의 셀들이 K개 이상 연속적으로 있는 경우에만 성능검사를 통과
4. 약품을 투입할 경우 해당 막의 모든 셀들은 하나의 특성으로 변경
5. 최소 약품 투입 횟수

# 문제풀이
 - 맵 정의
 - 합격기준 통과하는지 체크
 - 투약을 어느 row에 할 것인지(조합)
 - 투입 횟수(k)를 넘으면 return
 - 