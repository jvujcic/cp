package hackerrank

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class FindDigitsTest {
    @Test
    fun test01() {
        val input = """
            2
            12
            1012
        """.trimIndent()

        val output = """
            2
            3
            
        """.trimIndent()

        val outputStream = ByteArrayOutputStream()

        FindDigits.solve(input.byteInputStream(), outputStream)

        Assertions.assertEquals(output, outputStream.toString())
    }
}