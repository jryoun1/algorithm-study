# :orange_book: algorithm-study

## 알고리즘 문제 사이트

**프로그래머스** https://programmers.co.kr/learn/challenges <br>
**백준** https://www.acmicpc.net/problem/tags <br>
**sw_expert academy** https://swexpertacademy.com/main/code/problem/problemList.do <br>

## 알고리즘 공부 방법

### 알고리즘 스킬을 늘리기 위한 공부 순서

## 알고리즘 스터디 모임 일정 (2020.08.06 ~ )

매주 수요일 오후 13:00-15:00 <del>목요일 오전 10:00-12:00</del> <br>
스터디 진행 순서 : 개념 10-15 분, 코드 리뷰 30-40분, 다음주 문제 정하기 20-30분 <br>
진행자 순서 : 김현도 -> 연정민 -> 전종혁 -> 김성진 <br>

## 모임 규칙

회의시간 지각 시 : 분당 300원 (20분까지) <br>
문제 안 풀어올 시 : 문제당 2000원<br>
문제 못 풀어올 시 : 문제당 500원<br>
결석 시 : 1회 7000원 (3회 무단 결석 스터디 퇴출) <br>
벌금 계좌 : 카카오 뱅크 공동 계좌 사용 (벌금 발생 시 스터디 당일 날 바로 보내기)<br>
벌금 사용 : 회식<br>

## Git 저장소 이용하는 방법

### 폴더 설명 

### GitBash 명령어 사용 방법

- [원격저장소의 브랜치를 생성하는 방법]
- [원격저장소의 브랜치를 로컬로 가져오는 방법]
- [fork한 저장소 최신으로 동기화하는 방법]

#### 원격저장소 로컬에 가져오기

<code> git clone https://github.com/BreakAlgorithm/algorithm-study.git </code>

#### 로컬에서 개인 브랜치 생성하기

local workspace에 'yeon(본인이름)'라는 이름으로 브랜치 생성<br>
<code> git branch yeon(본인이름) </code>

#### 로컬에서 브랜치 작업후 원격저장소에 반영하기

로컬 브랜치가 있는 폴더에서 개인작업을 마친 후 공동 저장소에 반영한다.

1. <code> **git checkout yeon** </code> - master에서 yeon 브랜치로 전환
2. workspace에서 작업
3. <code> **git commit -m "message"**</code>
4. <code> **git push origin yeon** </code> - 원격저장소 yeon 브랜치에 반영
5. <code> **git checkout master** </code> - 브랜치 전환
6. <code> **git pull** </code> - 원격저장소 master의 최신 정보를 로컬에 업데이트 시키기
7. <code> **git merge yeon** </code> - master에 yeon 브랜치 작업 반영
8. <code> **git push origin master** </code> - 원격저장소 master에 반영

## <br><br>

### 알고리즘 공부 순서

1주차 : 선택 정렬, 버블 정렬, 삽입 정렬 공부 후 Programmers K-번째 수 문제 각각의 정렬로 풀어보기 <br>
2주차 : 쉘 정렬, 퀵 정렬, 합병 정렬 개념 및 코드 짜보기, 백준 [1181: 단어 정렬], [10814:나이순 정렬] 문제는 따로 풀어보기 <br>
3주차 : 힙 정렬, 계수 정렬 개념 및 코드 짜보기, 백준 [1018: 체스판 다시 칠하기], [2805 :나무 자르기], [1874 : 스택수열] 문제 풀기 <br>
4주차 : 기수 정렬, 버킷 정렬 개념 및 코드 짜보기, 백준 [1978 : 알파벳], [1261 : 알고스팟], [1038 : 감소하는 수] 문제 풀기 <br>
5주차 : 완전 탐색 알고리즘 (Brute-force Algorithm) 개념 공부, 백준 [2309 : 일곱 난쟁이], [2503 : 숫자야구], [1182 : 부분 수열의 합], [3085 : 사탕 게임] 문제 풀기 <br>
6주차 : 그리디 알고리즘 (Greedy Algorithm) 공부, 백준 [13904 : 과제], [4796 : 캠핑], [1449 : 수리공 항승], [1520 : 내리막길] 문제풀기 <br>
7주차 : 분할 정복 알고리즘 (Divide and Conquer) 공부, 백준 [2104 : 부분배열 고르기], [1725 : 히스토그램], [1992 : 쿼드트리], [1074 : Z] 문제풀기 <br>
8주차 : 동적계획법 (Dynamic Programming) 공부, 백준 [2098 : 외판원 순회], [2156 : 포도주 시식], [10942 : 팰린드롬], [10844 : 쉬운 계단수] 문제풀기 <br>
9주차 : <<추석연휴>> 복습 및 휴식 <br>
10주차 : 이분탐색 (Binary Search) 공부, 백준 [1300 : K번째 수], [2343 : 기타레슨], [3020 : 개똥벌레], [14003 : 가장 긴 증가하는 부분 수열5] 문제풀기 <br>
11주차 : 리스트, 배열, 연결리스트 공부, 백준  [1021 : 회전하는 큐], [1158 : 요세푸스 문제], [2346 : 풍선 터뜨리기], [5397 : 키로거] <br>
12주차 : 스택, 큐, 덱 공부, 백준 [3015 : 오아시스 재결합], [3190 : 뱀], [5430 : AC], [17298 : 오큰수] <br>
13주차 : BFS(Breadth First Search) 너비 우선 탐색 공부, 백준 [1012 : 유기농 배추], [2606 : 바이러스], [2667 : 단지번호 붙이기], [10026 : 적록색약] <br>
14주차 : DFS(Depth First Search) 깊이 우선 탐색 공부, 백준 [1405 : 미친 로봇], [2468 : 안전영역], [2668 : 숫자 고르기], [11725 : 트리의 부모찾기] <br>
### :rainbow: Week Study Question

|        | 1  | 2 | 3 |4|5|6| 날짜 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1주차  | [k번째 수](https://programmers.co.kr/learn/courses/30/lessons/42748)   |   ||||   | 2020.08.06(목)
| 2주차  | [1181: 단어정렬](https://www.acmicpc.net/problem/1181)   | [10814 :나이순 정렬](https://www.acmicpc.net/problem/10814) ||||   | 2020.08.13(목)
| 3주차  | [1018: 체스판 다시 칠하기](https://www.acmicpc.net/problem/1018)   | [2805 :나무 자르기](https://www.acmicpc.net/problem/2805) | [1874 : 스택수열](https://www.acmicpc.net/problem/1874)  |||| 2020.08.21(금)
| 4주차  |  [1987 : 알파벳](https://www.acmicpc.net/problem/1987)   | [1261 : 알고스팟](https://www.acmicpc.net/problem/1261) | [1038 : 감소하는 수](https://www.acmicpc.net/problem/1038)  |||| 2020.08.28(금)
| 5주차  |  [2309 : 일곱 난쟁이](https://www.acmicpc.net/problem/2309)   | [2503 : 숫자야구](https://www.acmicpc.net/problem/2503) | [1182 : 부분 수열의 합](https://www.acmicpc.net/problem/1182)  |[3085 : 사탕 게임](https://www.acmicpc.net/problem/3085)||| 2020.09.03(목)
| 6주차  |  [13904 : 과제](https://www.acmicpc.net/problem/13904)   | [4796 : 캠핑](https://www.acmicpc.net/problem/4796) | [1449 : 수리공 항승](https://www.acmicpc.net/problem/1449)  |[1520 : 내리막길](https://www.acmicpc.net/problem/1520)||| 2020.09.10(목)
| 7주차  |  [2104 : 부분배열 고르기](https://www.acmicpc.net/problem/2104)   | [1725 : 히스토그램](https://www.acmicpc.net/problem/1725) | [1992 : 쿼드트리](https://www.acmicpc.net/problem/1992)  |[1074 : Z](https://www.acmicpc.net/problem/1074)||| 2020.09.17(목)
| 8주차  |  [2098 : 외판원 순회](https://www.acmicpc.net/problem/2098)   | [2156 : 포도주 시식](https://www.acmicpc.net/problem/2156) | [10942 : 팰린드롬](https://www.acmicpc.net/problem/10942)  |[10844 : 쉬운 계단수](https://www.acmicpc.net/problem/10844)||| 2020.09.24(목)
| 10주차  |  [1300 : K번째 수](https://www.acmicpc.net/problem/1300)   | [2343 : 기타레슨](https://www.acmicpc.net/problem/2343) | [3020 : 개똥벌레](https://www.acmicpc.net/problem/3020)  |[14003 : 가장 긴 증가하는 부분 수열5](https://www.acmicpc.net/problem/14003)||| 2020.10.08(목)
| 11주차  |  [1021 : 회전하는 큐](https://www.acmicpc.net/problem/1021)   | [1158 : 요세푸스 문제](https://www.acmicpc.net/problem/1158) | [2346 : 풍선 터뜨리기](https://www.acmicpc.net/problem/2346)  |[5397 : 키로거](https://www.acmicpc.net/problem/5397)||| 2020.10.15(목)
| 12주차  |  [3015 : 오아시스 재결합](https://www.acmicpc.net/problem/3015)   | [3190 : 뱀](https://www.acmicpc.net/problem/3190) | [5430 : AC](https://www.acmicpc.net/problem/5430)  |[17298 : 오큰수](https://www.acmicpc.net/problem/17298)||| 2020.10.22(목)
| 13주차  |  [1012 : 유기농 배추](https://www.acmicpc.net/problem/1012)   | [2606 : 바이러스](https://www.acmicpc.net/problem/2606) | [2667 : 단지번호 붙이기](https://www.acmicpc.net/problem/2667)  |[10026 : 적록색약](https://www.acmicpc.net/problem/10026)||| 2020.10.29(목)
| 14주차  |  [1405 : 미친 로봇](https://www.acmicpc.net/problem/1405)   | [2468 : 안전영역](https://www.acmicpc.net/problem/2468) | [2668 : 숫자 고르기](https://www.acmicpc.net/problem/2668)  |[11725 : 트리의 부모찾기](https://www.acmicpc.net/problem/11725)||| 2020.11.04(수)
### 위의 readme는 아래 사이트를 참고하여 작성하였습니다. 

- [TehCopens/algorithm-study](https://github.com/TheCopiens/algorithm-study/blob/master/README.md) <br>

