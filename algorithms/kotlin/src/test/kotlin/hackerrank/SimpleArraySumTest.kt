package hackerrank

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class SimpleArraySumTest {
    @Test
    fun test01() {
        val input = """
            6
            1 2 3 4 10 11
        """.trimIndent()
        val output = ByteArrayOutputStream()

        SimpleArraySum.solve(input.byteInputStream(), output)

        Assertions.assertEquals("31\n", output.toString())
    }
}