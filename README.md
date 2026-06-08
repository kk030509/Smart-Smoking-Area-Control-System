# 🚬 Smart Smoking Area Control System

## 📌 프로젝트 개요
버튼 입력에 따라 흡연장 내부 인원 수를 관리하고  
DC 모터, 서보모터, 7세그먼트를 이용하여  
자동 환기 및 출입 제어를 수행하는 시스템입니다.

---

## ⚙️ 주요 기능

### 🔹 인원 카운트
- UP 버튼 → 인원 증가
- DOWN 버튼 → 인원 감소

---

### 🔹 7-Segment 표시
- 현재 인원 수 출력
- 한 자리 → 오른쪽 정렬
- 6 이상 → FULL 표시

---

### 🔹 DC 모터 (환기 시스템)
| 인원 수 | 동작 |
|--------|------|
| 0 | 정지 |
| 1 | 1단 |
| 2 | 2단 |
| 3 이상 | 3단 |

---

### 🔹 서보모터 (자동문)
버튼 입력 시:
닫힘 → 열림 → 대기 → 닫힘

---

## 🧱 프로젝트 구조
```
/project
├── src/
│   ├── main.c
│   ├── button/
│   │   ├── button.c
│   │   └── button.h
│   ├── motor/
│   │   ├── motor.c
│   │   └── motor.h
│   ├── servo/
│   │   ├── servo.c
│   │   └── servo.h
│   ├── segment/
│   │   ├── segment.c
│   │   └── segment.h
```

---

## 🔌 사용 핀

| 기능 | 핀 |
|------|----|
| 버튼 | PG0, PG1 |
| 서보 | PB5 |
| DC 모터 | PB4 |
| 세그먼트 | PORTA, PORTC |

---

## ⚠️ 주의사항

- DC 모터는 MOSFET 사용 필수
- 외부 전원 사용 필요
- GND 공통 연결 필수

---

## 🚀 개발 환경

- ATmega MCU
- Microchip Studio
