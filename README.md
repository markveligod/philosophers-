# :white_check_mark: Philosophers-(project 2020)  
## Description
The problem of dining philosophers is a classic example used in computer science to illustrate synchronization problems in the development of parallel algorithms and techniques for solving these problems.  
The problem was formulated in 1965 by Edsger Dijkstra as an examination exercise for students. Competing access to a tape drive was used as an example. Soon the problem was formulated by Richard Hoare in the form in which it is known today.  
### Problem statement
<img src="https://github.com/markveligod/philosophers-/raw/master/img/1.png" width="300">  
  
Five silent philosophers sit around a round table, with a plate of spaghetti in front of each philosopher. Forks are placed on the table between each pair of nearby philosophers.  
Every philosopher can either eat or think. The meal is not limited to the amount of remaining spaghetti-an infinite supply is implied. However, the philosopher can only eat when holding two forks-one taken from the right and the other from the left (an alternative formulation of the problem implies bowls of rice and chopsticks instead of plates of spaghetti and forks).  
Each philosopher can take the nearest fork (if it is available) or put it down — if he already holds it. Taking each fork and returning it to the table are separate actions that must be performed one after the other.  
The question of the problem is to develop a model of behavior (a parallel algorithm) in which none of the philosophers will starve, that is, they will always alternate between eating and thinking.  
  
## :page_facing_up: What is a semaphore?
**A semaphore is** a signaling mechanism, and a thread waiting for a semaphore can be signaled by another thread. It uses two atomic operations: 1) wait and 2) signal to synchronize the process.  
A semaphore allows or denies access to a resource, which depends on how it is configured.  
  
### Characteristics of semaphore
1. This is a mechanism that you can use to ensure that tasks are synchronized.
2. This is a low-level synchronization mechanism.
3. The semaphore will always contain a non-negative integer value.
4. A semaphore can be implemented using test operations and interrupts that must be performed using file descriptors.  
  
### Types of semaphores
1. Counting semaphores
1. Binary semaphore.
  
**Counting semaphores.** This type of semaphore uses a counter that helps the job be purchased or released many times. If the initial counter = 0, the account semaphore must be created in an unavailable state.  
![](https://github.com/markveligod/philosophers-/raw/master/img/2.png)  
  
**Binary semaphores** are very similar to counting semaphores, but their value is limited to 0 and 1. In this type of semaphore, the wait operation only works if semaphore = 1, and the signal operation succeeds when semaphore = 0. it is Easier to implement than to count semaphores.  
![](https://github.com/markveligod/philosophers-/raw/master/img/3.png)  
  
The program below is a step-by-step implementation that includes using and declaring a semaphore.  
```
Shared var mutex: semaphore = 1;
Process i
    begin
    .
    .
    P(mutex);
    execute CS;
    V(mutex);
    .
    .
    End;
```
### Waiting and signaling operations in semaphores...
Both of these operations are used to implement process synchronization. The purpose of this semaphore operation is to get a mutual exception.  
**Wait for the operation.** This type of semaphore operation helps you control the entry of a task into a critical section. However, if the wait value is positive, the value of the wait argument X is reduced. If the value is negative or zero, no operation is performed. This is also called the P (S) operation. After decreasing the semaphore value, which becomes negative, the command is held until the required conditions are met.  
```
Copy CodeP(S)
{ 
    while (S<=0);
    S--;
}
```
  
**Signal operation.** This type of semaphore operation is used to control the output of a task from a critical section. This helps increase the value of the argument by 1, which is denoted as V (S).  
```
Copy CodeP(S)
{ 
    while (S>=0);
    S++;
}
```  
### Difference between a semaphore and a mutex
|parameters|semaphore|Mutex|
|:--------:|:-------:|:---:|
|Mechanism|This is a type of signaling mechanism.|This is a locking mechanism.|
|Data type|A semaphore is an integer variable.|A mutex is just an object.|
|Modification|Wait and signal operations can change the semaphore.|It is only changed by the process that can request or release the resource.|
|Resource management|If no resource is available, the process requires a resource that must perform a wait operation. Wait until the semaphore counter is greater than 0.|If it is blocked, the process must wait. The process must be stored in a queue. This should only be accessed when the mutex is unlocked.|
|Thread|You can have multiple program threads.|You can have multiple program threads in a mutex, but not simultaneously.|
|Possession|The value can be changed by any process that releases or retrieves the resource.|An object's lock is released only by the process that received the lock for it.|  
|Types|Semaphore types are considered semaphore and binary semaphore|Mutex has no subtypes.|
|Operation|The semaphore value is changed using the wait() and signal() operations.|The mutex object is locked or unlocked.|
|Employment resources|It is busy if all resources are in use, and the process requesting the resource performs a wait () operation and blocks until the semaphore count is > 1.|If the object is already locked, the process requesting resources waits and is logged in by the system before releasing the lock.|
  
## Run the project
<img src="https://github.com/markveligod/philosophers-/raw/master/img/4.gif">  
  

## Useful links:
[Такие удивительные семафоры](https://habr.com/ru/post/261273/)  
[Знакомство с межпроцессным взаимодействием на Linux](https://habr.com/ru/post/122108/)  
  
## Other
**Author:**  
*[Mark Veligod](https://github.com/markveligod)*  
