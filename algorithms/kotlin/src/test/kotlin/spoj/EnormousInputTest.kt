package spoj

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class EnormousInputTest {
    @Test
    fun test01() {
        val input = """
            7 3
            1
            51
            966369
            7
            9
            999996
            11
        """.trimIndent()
        val output = ByteArrayOutputStream()

        EnormousInput.solve(input.byteInputStream(), output)

        Assertions.assertEquals("4\n", output.toString())
    }
}