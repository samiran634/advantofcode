package org.example

import java.io.File
import kotlin.math.max

fun main() {
    val input = File("inputs/day03.txt").readLines()
    val testInput=File("inputs/test.txt").readLines()
    val testResult1=solvePart1Day03(input)
    val testResult2=solvePart2Day03(input)
    val sample=solvePart1Day03(testInput)

    println(sample)
    println(testResult1)
    println(testResult2)

}
fun solvePart1Day03(data:List<String>): Int {
    var ans:Long=0
    for(i in 0 until data.size){
        val num: String=data[i]
        //println("{$num} this is real one")
        var maxe:Long=0;
        for(j in 0 until num.length){//here i want to take two number in sequence which is max
            for(k in j+1 until num.length){
                var num2:Long=(num[j]-'0')*1L
                num2=1L*num2*10+(num[k]-'0')
                maxe= max(num2,maxe)
            }
        }
       // println(maxe)
            ans+=maxe;
    }
    println(ans)

    return 0
}
fun solvePart2Day03(data: List<String>): Int {
    var ans = 0L

    for (num in data) {
        val arr = num.toCharArray()
        arr.sort() // ascending

        // take last 12 digits (largest ones)
        val s = arr.takeLast(12).joinToString("")

        ans += s.toLong()
    }

    println(ans)
    return 0
}

