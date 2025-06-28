
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
- Demonstrates advanced C++ features and design patterns

---

## 🎓 Design Intent

This project intentionally overengineers certain components to **demonstrate C++ fluency**, especially:

- Use of **smart pointers** (`shared_ptr`) to show memory-safe dynamic allocation
- Application of **design patterns**:
  - **Factory** and **Command**: via `process_input()` dispatcher
  - **Template Method**: shape interface with polymorphic overrides
  - **Mixin (modShape)**: central shape counter and scale validation
- Usage of **C++ templates** to enable flexibility in numeric types
- CI/CD and Docker support for real-world development

---

## 🚀 Supported Shapes

| Shape     | Parameters                         |
|-----------|------------------------------------|
| Circle    | radius [scale optional]            |
| Rectangle | length, width                      |
| Square    | side                               |
| Triangle  | side1, side2, side3 (validated)    |
| Sphere    | radius                             |
| Cube      | side [scale optional]              |

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
./shapes circle 5 scale 2
./shapes rectangle 4 6
./shapes square 7
./shapes triangle 3 4 5
./shapes sphere 5
./shapes cube 6
./shapes cube 6 scale 1.5
```

### ▶️ Interactive mode

```bash
./shapes
# Example input:
circle 5
rectangle 4 6
triangle 3 4 5
sphere 5
cube 6
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
- Runs:
  - `make all`
  - Docker build
  - Docker run validation
- Logs output to `./build/docker.log` on failure

---

