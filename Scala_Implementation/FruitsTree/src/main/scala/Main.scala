object Main extends App {
  var treeFruit = new TreeFruit

  treeFruit.insert(13, "Orange")
  treeFruit.insert(5, "Avocado")
  treeFruit.insert(8, "Apple")
  treeFruit.insert(4, "Lemon")
  treeFruit.insert(9, "Elderberry")
  treeFruit.iterate()
  println("--------------------------------")
  treeFruit.filterByType(classOf[Citrus])
  println("--------------------------------")
  treeFruit.filterByWeight(8)
  println("--------------------------------")
  println(treeFruit.findHeaviest().getClass.getSimpleName + " "+ treeFruit.findHeaviest().getWeight + " gm")
  println("--------------------------------")
  println(treeFruit.findLightest().getClass.getSimpleName + " " + treeFruit.findLightest().getWeight + " gm")
  println("--------------------------------")
  treeFruit.magnifyByType(classOf[Fruit], 1)
  treeFruit.iterate()
  println("--------------------------------")
  treeFruit.magnifyByType(classOf[Apple], 6)
  treeFruit.iterate()
}
