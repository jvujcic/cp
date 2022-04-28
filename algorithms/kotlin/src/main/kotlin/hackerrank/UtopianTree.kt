package hackerrank

import java.io.*

object UtopianTree {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)

        val t = br.readLine().toInt()
        for (i in 1..t) {
            val n = br.readLine().toLong()
            val solution = height(n)
            pw.println(solution)
        }
    }

    private fun height(n: Long): Long {
        var solution = 1L
        for (i in 1..n) {
            if (i % 2 == 0L) solution += 1
            else solution *= 2
        }
        return solution
    }
}

fun main(args: Array<String>) {
    UtopianTree.solve(System.`in`, System.out)
}