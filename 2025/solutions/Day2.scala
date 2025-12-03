package solutions

object Day2 extends Day(2):
    @main def main2 =
        // Life would be easier if I used longs...
        val ranges: Seq[(BigInt, BigInt)] = input(0).split(",").map(parseRange)
        var sum = BigInt(0);

        for range <- ranges yield
            var i = range._1
            while i <= range._2 do

                val s = i.toString()
                val split = s.splitAt(s.length() / 2)

                if split(0) == split(1) then sum = sum + i
                i = i + 1

        println(sum)

        // Part 2

        sum = BigInt(0);

        for range <- ranges yield
            var i = range._1
            while i <= range._2 do
                val s = i.toString()

                if """^(\w+)\1+$""".r matches s then sum = sum + i
                i = i + 1

        println(sum)

    def parseRange(s: String): (BigInt, BigInt) =
        val splittedString = s.split("-")
        BigInt(splittedString(0)) -> BigInt(splittedString(1))
