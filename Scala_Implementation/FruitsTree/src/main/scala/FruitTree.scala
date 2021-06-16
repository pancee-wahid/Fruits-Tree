import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

/*class FruitTree {
  private val tree: Tree[Fruit] = new Tree[Fruit]

  def add(fruit: Fruit): Unit = tree.insert(fruit)

  def Iterate(): Unit =
    tree
      .getElements
      .foreach(printOredered())

  def filterByType[Type <: Fruit : ClassTag](): Unit = {
    tree
      .getElements
      .collect { case x: Type => x.asInstanceOf[Fruit] }
      .foreach(printOredered())
  }

  def filterByWeight(weight: Int): Unit = {
    tree
      .getElements
      .filter(_.weight >= weight)
      .foreach(printOredered())
  }

  def magnifyByType[Type <: Fruit : ClassTag](weightAdded: Int): Unit = {
    val list =
      tree
        .getElements
        .collect { case x: Type => x.asInstanceOf[Fruit] }

    list.foreach(e => tree.delete(e))
    list.foreach(_.weight += weightAdded)
    list.foreach(e => tree.insert(e))
  }

  def findHeaviest(): Option[Fruit] = tree.getMax

  def findLightest(): Option[Fruit] = tree.getMin

  def getFruits: ArrayBuffer[Fruit] = tree.getElements

  private def printOredered(): Fruit => Unit = {
    var index: Int = 1
    fruit => {
      val s = fruit.toString
      println(index + ".\tweight= " + fruit.weight + "\ttype: " + s.substring(s.indexOf('.') + 1, s.indexOf('@')))
      index = index + 1
    }
  }

}
*/
