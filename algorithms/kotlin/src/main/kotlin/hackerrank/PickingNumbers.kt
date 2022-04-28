package hackerrank

import java.io.*
import kotlin.math.max

object PickingNumbers {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)

        br.readLine()
        val numbers = br.readLine().split(" ").map { it.toInt() }

        val counts = LongArray(100)
        numbers.forEach { ++counts[it] }

        var solution = 1L

        for (i in 1 until 100) {
            solution = max(solution, counts[i] + counts[i - 1])
        }

        pw.println(solution)
    }
}

fun main(args: Array<String>) {
    PickingNumbers.solve(System.`in`, System.out)
}