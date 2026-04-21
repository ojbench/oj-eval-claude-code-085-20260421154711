# Problem 085 - 修剪二叉树

**ACMOJ Problem ID**: 2048

## Table of Contents

- [Problem 085 - 修剪二叉树](#problem-085-修剪二叉树)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2048. 修剪二叉树** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/085/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

这是一道给二叉树剪枝的题，祝大家开心AC，么么哒o(*￣▽￣*)ブ

给定一个二叉树（通过扩展前序遍历构建，其中空节点用`-1`表示），二叉树总共有`N`个节点。树的每个节点的值要么是 `0`，要么是 `1`。**请剪除该二叉树中所有节点的值为 `0` 的子树。**

提示：**内存泄露在这道题中是值得注意的**，但为了避免同学们因为内存泄漏爆零Φ(*∏ 0 ∏)，所以只有部分点加了内存泄漏检测~(●'◡'●)

节点 `node` 的子树为 `node` 本身，以及所有 `node` 的后代。



### 前序遍历示例

例如用扩展前序遍历构建一棵树（见样例输入1），输入为

```
1 -1 0 0 -1 -1 1 -2
```

它的前序遍历为

```
1 -1 0 0 -1 -1 1 -1 -1
```

### 样例输入1

```
1 -1 0 0 -1 -1 1 -2
```

### 样例输出1

```
1 -1 0 -1 1 -1 -1
```

[<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png" style="zoom:50%;" />](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

### 样例输入2

```
1 0 0 -1 -1 0 -1 -1 1 0 -1 -1 1 -2
```

### 样例输出2

```
1 -1 1 -1 1 -1 -1
```

[<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png" style="zoom:50%;" />](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

### 样例输入3

```
1 1 1 0 -1 -1 -1 1 -1 -1 0 0 -1 -1 1 -2
```

### 样例输出3

```
1 1 1 -1 -1 1 -1 -1 0 -1 1 -1 -1
```

[<img src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png" style="zoom:50%;" />](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

### Input Format

一行整型数字，数字之间用空格隔开，表示树的拓展前序遍历序列，-1表示节点为空，-2表示输入序列的结束

### Output Format

一行整型数字，数字之间用空格隔开，表示剪枝后的树的前序遍历，注意要把空指针输出，用-1表示。

### Samples

No sample data provided for this problem.

### Data Constraints

N<50000

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 244 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/085/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
