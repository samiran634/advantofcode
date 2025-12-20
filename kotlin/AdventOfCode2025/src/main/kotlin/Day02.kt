package org.example


import java.io.File

fun main() {
    // 1. Read the input file
    // "inputs/day01.txt" looks for the folder we created in the root
    val input: String = File("inputs/day02.txt").readLines()[0]
    val testInput: String=File("inputs/test.txt").readLines()[0]
    val testResult1=solvePart1Day02(input)
    val testResult2=solvePart2Day02(input)
    val sample=solvePart1Day02(testInput)

    println(sample)
    println(testResult1)
    println(testResult2)


}

fun solvePart1Day02(data: String): Int {
    val arr=data.split(",").map{it.split("-").map{it.toLong()}};
    var cnt:Long=0;
    val check = { num: Long ->
        val s = num.toString()
        if (s.length % 2 != 0) false
        else s.substring(0, s.length / 2) == s.substring(s.length / 2)
    }

    for((first, last) in arr){
        var t=first;
        while(t<=last){
            if(check(t))cnt+=t;
            t++;
        }
    }
    println(cnt)

    return 0
}

fun solvePart2Day02(data: String): Int {
    val arr=data.split(",").map{it.split("-").map{it.toLong()}};
    var cnt:Long=0;
    val construct = construct@{ str: String, num: Int, s: String ->
        if (num % str.length != 0) return@construct false

        val x = num / str.length
        val sb = StringBuilder()

        repeat(x) {
            sb.append(str)
        }

        sb.toString() == s
    }

    val check = check@{ num: Long ->
        val s = num.toString()
        val n = s.length
        val sb = StringBuilder()

        for (i in 0 until n / 2) {   // only valid prefixes
            sb.append(s[i])
            if (construct(sb.toString(), n, s)) return@check true
        }
        false
    }

    for((first, last) in arr){
        var t=first;
        while(t<=last){
            if(check(t))cnt+=t;
            t++;
        }
    }
    println(cnt)
    return 0
}