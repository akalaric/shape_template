
# Shape Template

A modern C++ template-based project for calculating properties of geometric shapes.  
Supports both **command-line** and **interactive** modes. Includes **Docker** support and **GitHub Actions CI**.

---

## 📦 Features

- Object-oriented design with polymorphism
- Template-based `Shape` base class
- Runtime shape creation and display
- Scalable and extensible design
- CI workflow with GitHub Actions
- Dockerized build and run

---

## 🚀 Supported Shapes

| Shape | Parameters |
|-------|------------|
| Circle | radius |
| Rectangle | length, width |
| Square | side |
| Triangle | hypotenuse, adjacent, opposite |
| Sphere | radius |

---

## 🔨 Build Instructions

### 🛠️ Using Makefile

```bash
make run
```

### 🛠️ Manual build

```bash
g++ src/main.cpp -o shapes -Wall -Wextra -std=c++17
```

---

## 🚀 Run Instructions

### ▶️ Command-line mode

```bash
./shapes circle 5
./shapes rectangle 4 6
./shapes square 7
./shapes triangle 3 4 5
./shapes sphere 5
```

### ▶️ Interactive mode

```bash
./shapes
# Example input:
circle 5
rectangle 4 6
triangle 3 4 5
sphere 5
exit
```

---

## 🐳 Run inside Docker

```bash
docker build -t shapes .
docker run --rm shapes circle 10
```

---

## 🧪 Integration test

```bash
./run_shapes.sh
```

---

## ⚙️ Continuous Integration (CI)

- GitHub Actions: `.github/workflows/ci_workflow.yml`
- Runs `make all`, Docker build, Docker test
- Uploads logs on failure

---

