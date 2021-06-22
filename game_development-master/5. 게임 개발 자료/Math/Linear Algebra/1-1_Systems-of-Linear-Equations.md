### Systems of Linear Equations

#### Summary

* linear equation
* system of linear equations
* consistent / inconsistent
* elementary row  operations: replacement, interchange, and scaling
* equivalent / row equivalent



#### A linear equations in the variables

<p align="center">
	<img src="./images/1-1-01.gif" alt="images_1" style="margin: 50px 0 10px 0"/>
</p>

* coefficients : a1, a2, ..., an

* coefficients와 b는 실수 또는 허수

<p align="center">
	<img src="./images/1-1-02.gif" alt="images_2" style="margin: 50px 0 10px 0"/>
</p>


* 우측 항 x1x2 때문에 linear equation이 아님!

<p align="center">
	<img src="./images/1-1-03.gif" alt="images_3" style="margin: 50px 0 10px 0"/>
</p>

* 우측 항 루트 x1 때문에 linear equation이 아님



#### A system of linear equations

* 한 개 또는 한 개 이상의 linear equation의 집합

<p align="center">
	<img src="./images/1-1-04.gif" alt="images_4" style="margin: 0 0 10px 0"/>
	<br>
	<img src="./images/1-1-05.gif" alt="images_5" style="margin: 0 0 10px 0"/>
</p>


* Solution set: linear system이 있을 때, 모든 가능한 해의 집합

* 두 linear system이 **equivalent** => 같은 Solution set을 지닌다.



* linear system은...

1. 해가 없거나 (inconsistant)
2. 단 하나의 해만 있거나
3. 무수히 많은 해가 존재



#### Matrix notation

##### Example 1

<p align="center">
	<img src="./images/1-1-06.gif" alt="images_6" style="margin: 0 0 10px 0"/>
	<br>
	<img src="./images/1-1-07.gif" alt="images_7" style="margin: 0 0 10px 0"/>			<br>
	<img src="./images/1-1-08.gif" alt="images_8" style="margin: 0 0 10px 0"/>
</p>


* coefficient matrix (3×3)

<p align="center">
	<img src="./images/1-1-09.gif" alt="images_9" style="margin: 0px 0 10px 0"/>
</p>




* augmented matrix (3×4)

<p align="center">
	<img src="./images/1-1-10.gif" alt="images_10" style="margin: 0px 0 10px 0"/>
</p>


* replacement : row를 곱해서 다른 row에 더해 주는 행위
* scaling : 특정 row에 어떤 특정 값을 곱하거나 나누는 행위

<p align="center">
	<img src="./images/1-1-11.gif" alt="images_11" style="margin: 0px 0 10px 0"/>
</p>




##### Example 2

<p align="center">
	<img src="./images/1-1-12.gif" alt="images_12" style="margin: 0 0 10px 0"/>
	<br>
	<img src="./images/1-1-13.gif" alt="images_13" style="margin: 0 0 10px 0"/>			<br>
	<img src="./images/1-1-14.gif" alt="images_14" style="margin: 0 0 10px 0"/>
</p>


* interchange : 두 row를 교환하는 행위

<p align="center">
	<img src="./images/1-1-16.gif" alt="images_16" style="margin: 0px 0 10px 0"/>
</p>



<p align="center">
	<img src="./images/1-1-17.gif" alt="images_17" style="margin: 0 0 10px 0"/>
	<br>
	<img src="./images/1-1-18.gif" alt="images_18" style="margin: 0 0 10px 0"/>		<br>
	<img src="./images/1-1-19.gif" alt="images_19" style="margin: 0 0 10px 0"/>
</p>


* **inconsistent!!** 해당 linear system은 해가 없다.



#### Elementary row operations

* replacement
* interchange
* scaling
* row equivalent : row operation을 통해 서로 오갈 수 있다.
* 두 개의 augmented matrix가 row equivalent하다면, 같은 solution set을 지닌다.