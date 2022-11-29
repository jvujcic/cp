package hackerrank

import java.io.*
import java.lang.Integer.min

object AppendAndDelete {
    fun solve(inputStream: InputStream, outputStream: OutputStream) {
        val br = BufferedReader(InputStreamReader(inputStream))
        val pw = PrintWriter(outputStream, true)

        val s = br.readLine()
        val t = br.readLine()
        val k = br.readLine().toInt()

        val minlen = min(s.length, t.length)
        var maxmatch = 0
        for(i in 0 until minlen) {
            if(s[i] == t[i]) maxmatch++
            else break
        }

        val minmoves = (s.length - maxmatch) + (t.length - maxmatch)

        if(k >= s.length + t.length) pw.println("Yes")
        else if (minmoves <= k && (k - minmoves) % 2 == 0) pw.println("Yes")
        else pw.println("No")
    }
}

fun main(args: Array<String>) {
    AppendAndDelete.solve(System.`in`, System.out)
}