package hackerrank

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class AppendAndDeleteTest {
    @Test
    fun test01() {
        val input = """
            hackerhappy
            hackerrank
            9
        """.trimIndent()

        val output = """
            Yes
            
        """.trimIndent()

        val outputStream = ByteArrayOutputStream()

        AppendAndDelete.solve(input.byteInputStream(), outputStream)

        Assertions.assertEquals(output, outputStream.toString())
    }

    @Test
    fun test02() {
        val input = """
            aba
            aba
            7
        """.trimIndent()

        val output = """
            Yes
            
        """.trimIndent()

        val outputStream = ByteArrayOutputStream()

        AppendAndDelete.solve(input.byteInputStream(), outputStream)

        Assertions.assertEquals(output, outputStream.toString())
    }

    @Test
    fun test03() {
        val input = """
            ashley
            ash
            2
        """.trimIndent()

        val output = """
            No
            
        """.trimIndent()

        val outputStream = ByteArrayOutputStream()

        AppendAndDelete.solve(input.byteInputStream(), outputStream)

        Assertions.assertEquals(output, outputStream.toString())
    }
}