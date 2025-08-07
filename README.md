# LyfeStyle

LyfeStyle is a Qt-based desktop application for managing and tracking personal wellness. It includes features for journaling, mood tracking, and task management.


## **Features**

- **Journal System** for personal entries
- **Mood Tracker** to record emotions
- **Task List Mananger** for dialy productivity
- **Secure Login Page**

## Binaries

[Windows](https://github.com/MaxRUnger/370Team8/releases/)


## Building

### Windows Build Requirements

* Qt 6.x and Qt Creator
* Git

### Setup

* Install Qt 6.x SDK and Qt Creator from the  [https://www.qt.io/download-dev](https://www.qt.io/download-dev)
* Install Git from [https://git-scm.com/downloads](https://git-scm.com/downloads)
* Clone the repository using Git:
    ```bash
    git clone https://github.com/MaxRUnger/370Team8.git
    ```
* Open Qt Creator and Select:
    * `File > Open File or Project`
    * Navigate to the `CmakeList.txt` inside the `370Team8` folder.
* Configure the project:
    * Select your Qt 6.x Kit with MinGW  or MSVC (whichever installed with Qt)
    * Click Configure Project
* Build and Run the project
    * `Build > Build project "Lyfestyle"` or `CTRL+B`
    * `Build > Run` or `CTRL+R`

## Screenshots
![login.png](images/login.png)  
![journal.png](images/journal.png)  
![moodtracker.png](images/mood-tracker.png)  
![tasklist.png](images/tasklist.png)

## Running Unit Tests in Qt Creator

This project includes unit tests located in [`tests/tests.cpp`](https://github.com/MaxRUnger/370Team8/blob/main/tests/tests.cpp). The tests use the `QTest` framework.

### Steps to Run the Tests:

1. Open `tests/tests.cpp` in Qt Creator.
2. Right-click anywhere in the file editor.
3. Select **"Run tests"** or **"Run 'tests' with the tools button"** from the context menu.
4. The **test results** will appear in the **Test Results panel** (usually at the bottom of Qt Creator).

> If the option doesn’t appear:
> - Ensure the file is part of the CMake project.
> - Check that you’ve defined `QTEST_MAIN(AllTests)` in `tests.cpp`.

## Contributors

* Max Unger
* Brody Estes
* Zyrus Tyson
* Kevin Truong
