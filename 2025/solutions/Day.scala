package solutions

trait Day(nbr: Int):
    val input =
        val source =
            scala.io.Source.fromFile(s"../input/day${nbr}.txt", "UTF-8")
        try source.getLines.toVector
        finally source.close
