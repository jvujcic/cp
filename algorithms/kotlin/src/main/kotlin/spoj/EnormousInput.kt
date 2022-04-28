package spoj

import java.io.*

object EnormousInput {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)
        val (n, k) = br.readLine().split(" ").map { it.toLong() }

        var solution = 0L

        for (i in 1..n) {
            val x = br.readLine().toLong()
            if (x % k == 0L) solution++
        }

        pw.println(solution)
    }
}

fun main(args: Array<String>) {
    EnormousInput.solve(System.`in`, System.out)
}