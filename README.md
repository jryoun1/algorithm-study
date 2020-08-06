# :orange_book: algorithm-study

## 알고리즘 문제 사이트

**프로그래머스** https://programmers.co.kr/learn/challenges <br>
**백준** https://www.acmicpc.net/problem/tags <br>
**sw_expert academy** https://swexpertacademy.com/main/code/problem/problemList.do <br>

## 알고리즘 공부 방법

### 알고리즘 스킬을 늘리기 위한 공부 순서

## 알고리즘 스터디 모임 일정 (2020.08.06 ~ )

매주 목요일 오전 10:00-12:00 <br>
스터디 진행 순서 : 개념 10-15 분, 코드 리뷰 30-40분, 다음주 문제 정하기 20-30분 <br>
진행자 순서 : 김현도 -> 연정민 -> 전종혁 -> 김성진 <br>

## 모임 규칙

회의시간 지각 시 : 분당 300원<br>
문제 안 풀어올 시 : 문제당 2000원<br>
문제 못 풀어올 시 : 문제당 500원<br>
결석 시 : 1회 7000원 (3회 무단 결석 스터디 퇴출)
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

### :rainbow: Week Study Question

|        | 1  | 2 | 3 | 날짜 |
| :---: | :---: | :---: | :---: | :---: |
| 1주차  | [k번째 수](https://programmers.co.kr/learn/courses/30/lessons/42748)   |   |   | 2020.08.06(목)
| 2주차  | [1181: 단어정렬](https://www.acmicpc.net/problem/1181)   | [10814 :나이순 정렬](https://www.acmicpc.net/problem/10814) |   | 2020.08.013(목)

### 위의 readme는 아래 사이트를 참고하여 작성하였습니다. 

- [TehCopens/algorithm-study](https://github.com/TheCopiens/algorithm-study/blob/master/README.md) <br>

