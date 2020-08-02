# :orange_book: algorithm-study

## 알고리즘 문제 사이트

**프로그래머스** https://programmers.co.kr/learn/challenges <br>
**백준** https://www.acmicpc.net/problem/tags <br>

## 알고리즘 공부 방법

### 알고리즘 스킬을 늘리기 위한 공부 순서


## 팀원 스터디 진행 방법

### 온라인 스터디

### 오프라인 스터디 

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

### 위의 readme는 아래 사이트를 참고하여 작성하였습니다. 
- [TehCopens/algorithm-study] (https://github.com/TheCopiens/algorithm-study/blob/master/README.md) <br>

