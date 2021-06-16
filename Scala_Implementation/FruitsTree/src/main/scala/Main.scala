object Main extends App {
  var treeFruit = new TreeFruit

  treeFruit.insert(13, "Orange")
  treeFruit.insert(5, "kiwi")
  treeFruit.insert(8, "Apple")
  treeFruit.insert(4, "mango")
  treeFruit.insert(9, "mango")
  treeFruit.iterate()
  println("--------------------------------")
  treeFruit.filterByType(classOf[OvalShaped])
  println("--------------------------------")
  treeFruit.filterByWeight(10)
  println("--------------------------------")
  println(treeFruit.findHeaviest().getClass.getSimpleName + " "+ treeFruit.findHeaviest().getWeight + " gm")
  println("--------------------------------")
  println(treeFruit.findLightest().getClass.getSimpleName + " " + treeFruit.findLightest().getWeight + " gm")
  println("--------------------------------")
  treeFruit.magnifyByType(classOf[Fruit], 0)
  treeFruit.iterate()
  println("--------------------------------")
  treeFruit.magnifyByType(classOf[Apple], 5)
  treeFruit.iterate()


























  /*treeFruit.insert(11, "mango")
  treeFruit.insert(1, "mango")*/
  //treeFruit.remove( 5)
  //println(treeFruit.getRoot.getWeight, treeFruit.getRoot.getLeft.getWeight /*, treeFruit.getRoot.getRight */)
 /* treeFruit.iterate()
  println("--------------------------------")
  treeFruit.filterByType("Oval-Shaped")
  println("--------------------------------")
  treeFruit.filterByWeight(10)
  println("--------------------------------")
  println(treeFruit.findHeaviest().getType + " " + treeFruit.findHeaviest().getWeight + "gm")
  println("--------------------------------")
  println(treeFruit.findLightest().getType + " " + treeFruit.findLightest().getWeight + "gm")
*/

  //treeFruit.remove( 5)
  //println(treeFruit.getRoot.getWeight, treeFruit.getRoot.getLeft.getWeight /*, treeFruit.getRoot.getRight */)
  //treeFruit.remove( 13)
  //println(treeFruit.getRoot)

}
