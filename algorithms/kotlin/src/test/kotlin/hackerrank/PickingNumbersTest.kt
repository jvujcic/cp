package hackerrank

import org.junit.jupiter.api.Assertions
import org.junit.jupiter.api.Test
import java.io.ByteArrayOutputStream

internal class PickingNumbersTest {
    @Test
    fun test01() {
        val input = """
            6
            4 6 5 3 3 1
        """.trimIndent()
        val output = ByteArrayOutputStream()

        PickingNumbers.solve(input.byteInputStream(), output)

        Assertions.assertEquals("3\n", output.toString())
    }
}