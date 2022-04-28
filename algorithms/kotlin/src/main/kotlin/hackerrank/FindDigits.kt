package hackerrank

import java.io.*

object FindDigits {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)

        val t = br.readLine().toInt()

        repeat(t) {
            val nstr = br.readLine()
            val n = nstr.toLong()

            var solution = 0L
            nstr.forEach { c ->
                val digit = Character.getNumericValue(c)
                if (digit != 0 && n % digit == 0L) solution++
            }
            pw.println(solution)
        }
    }
}

fun main(args: Array<String>) {
    FindDigits.solve(System.`in`, System.out)
}