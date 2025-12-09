package org.example

import java.io.File

fun main() {
    // 1. Read the input file
    // "inputs/day01.txt" looks for the folder we created in the root
    val input = File("inputs/day01.txt").readLines()
    val textInput=File("inputs/test.txt").readLines()

    // 2. Solve Part 1
    val part1Result = solvePart1(input)
    println("Part 1: $part1Result")
    val testResult = solvePart2(textInput)
    println("test2: $testResult")

    // 3. Solve Part 2
    val part2Result = solvePart2(input)
    println("Part 2: $part2Result")
}

fun solvePart1(data: List<String>): Int {
    var ind=0;
    var num=50;
    val n=data.size
    var cnt=0;
    repeat(n){
        val dir =data[ind][0];
       val steps = data[ind].substring(1).toInt();


        if(dir=='L')num-=steps;
        else num+=steps;
        num=(num % 100 + 100) % 100
        if(num==0)cnt++;
        ind++;
    }
        println(cnt)
   // println(data)
    return 0
}

fun solvePart2(data: List<String>): Int {

    var num=50;
    var cnt=0;
    for ( s in data){
        val dir =s[0];
        val steps = s.substring(1).toInt();


        if(dir=='R'){
            repeat(steps){
                num=(num+1)%100;
                if(num==0)cnt++;
            }

        }
        else {
            repeat(steps){
                num=(num-1)%100;
                if(num<0)num+=100
                if(num==0)cnt++;
            }
        };

       

    }
    println(cnt)
    // println(data)
    return 0
}