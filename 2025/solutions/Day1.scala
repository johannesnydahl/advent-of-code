package solutions

object Day1 extends Day(1):
    enum Dir:
        case Right, Left

    @main def main(): Unit =
        var pos: Int = 50
        var sum: Int = 0

        for i <- input do
            val ticks = i.substring(1).toInt
            val dir = i(0) match
                case 'L' =>
                    val tempPos = (pos - ticks) % 100
                    if tempPos < 0 then pos = 100 + tempPos else pos = tempPos
                case 'R' =>
                    pos = (pos + ticks) % 100
                case _ => throw Exception("Neither L nor R")

            if pos == 0 then sum += 1
        end for

        println(sum)
