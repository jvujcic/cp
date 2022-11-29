package hackerrank

import java.io.*

object SimpleArraySum {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)

        val n = br.readLine().toLong()
        val numbers = br.readLine().split(" ").map { it.toLong() }.toLongArray();
        val res = numbers.sum()

        pw.println(res)
    }
}

fun main(args: Array<String>) {
    SimpleArraySum.solve(System.`in`, System.out)
}