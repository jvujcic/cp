package hackerrank

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class UtopianTreeTest {
    @Test
    fun test01() {
        val input = """
            3
            0
            1
            4
        """.trimIndent()

        val output = """
            1
            2
            7
            
        """.trimIndent()

        val outputStream = ByteArrayOutputStream()

        UtopianTree.solve(input.byteInputStream(), outputStream)

        Assertions.assertEquals(output, outputStream.toString())
    }
}