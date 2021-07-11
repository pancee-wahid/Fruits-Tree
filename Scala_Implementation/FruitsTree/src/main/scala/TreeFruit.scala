import scala.collection.mutable.ListBuffer

class TreeFruit {
  var root : Fruit = null
  def getRoot: Fruit = root


  def iterate(): Unit = {
    getFruitList().foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))

  }

  def filterByType[T](t : Class[T]): Unit ={
    getFruitList().filter(p => t.isAssignableFrom(p.getClass)).foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))
  }

  def filterByWeight(weight : Int): Unit ={
    getFruitList().filter(_.weight > weight).foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))
  }

  def magnifyByType[T](Type: Class[T], weight: Int): Unit ={
    val list = getFruitList().collect { case x if Type.isAssignableFrom(x.getClass) => x }
    list.foreach(x => remove(x.weight))
    list.foreach(x=>x.weight += weight)
    list.foreach(x => insert(x.weight, x.getClass.getSimpleName))
  }

  def findHeaviest() :Fruit = {
    findMaxValue(root)
  }

  def findLightest() :Fruit = {
    findSmallestValue(root)
  }


//helping methods
  def insert(weight: Int, Type: String): Unit = {
    var node : Fruit = new Fruit
    //pattern matching
    Type match {
      case "OvalShaped" => node = new OvalShaped()
      case "TinyFruit" => node = new TinyFruit()
      case "Berry" => node = new Berry()
      case "Citrus" => node = new Citrus()
      case "Apple" => node = new Apple()
      case "Avocado" => node = new Avocado()
      case "Blackberry" => node = new Blackberry()
      case "Elderberry" => node = new Elderberry()
      case "Lemon" => node = new Lemon()
      case "Orange" => node = new Orange()
      case "Tangerine" => node = new Tangerine()
      case _ => node = new Fruit()
    }
    node.weight = weight
    if(root == null){
      root = node
    }
    else{
      insertHelper(root, node)
    }
  }

  def insertHelper(node: Fruit, newNode: Fruit): Unit = {
    if(newNode.getWeight < node.getWeight) {
      if(node.getLeft == null){
        node.left = newNode
        node.left.parent = node
      }
      else
        insertHelper(node.left, newNode);
    } else if(newNode.getWeight > node.getWeight) {
      // if right is null insert node here
      if(node.getRight == null){
        node.right = newNode
        node.right.parent = node;
      }
      else
        insertHelper( node.right, newNode );
    }
    else{
      newNode.parent = node.parent;
      newNode.left = node.left;
      newNode.right = node.right;
      if(node.left != null){
        node.left.parent = newNode;
      }
      if(node.right != null){
        node.right.parent = newNode;
      }
      if(node.parent != null){
        if(node.parent.left == node){
          node.parent.left = newNode;
        }
        else{
          node.parent.right = newNode;
        }
      }
      else{
        this.root = newNode;
      }
    }
  }

  def remove(weight :Int): Unit ={
    removeNode(root, weight)
  }

  def removeNode(node: Fruit, weight: Int) : Unit = {
    var current: Fruit = node
    var prev: Fruit = null
    while(current != null && current.weight != weight){
      prev = current
      if(weight < current.weight){
        current = current.left
      } else{
        current = current.right
      }
    }
    if(current == null){
      return
    }
    if(current.left == null || current.right == null){
      var newCurrent : Fruit = null

      if(current.left == null){
        newCurrent = current.right
      } else {
        newCurrent = current.left
      }

      if(prev == null){

        root = newCurrent
        return //newCurrent
      }

      if(current == prev.left){
        prev.left = newCurrent
      } else{
        prev.right = newCurrent
      }
      if(newCurrent != null){
        newCurrent.parent = prev
      }

    }
    else{
      val successor: Fruit = getSuccessor(current)
      removeNode(root, successor.getWeight)
      if(prev == null){
        root = successor
      }
      else{
        if(prev.right == current){
          prev.right = successor
        }
        else{
          prev.left = successor
        }
        successor.parent = prev
      }
      successor.left = current.left
      if(current.left != null){
        current.left.parent = successor
      }
      if(current.right != successor){
        successor.right = current.right
        if(current.right != null){
          current.right.parent = successor
        }
      }
    }
  }

  def findSmallestValue(node: Fruit): Fruit = {
    if (node.left != null) {
      return findSmallestValue(node.left)
    }
    node
  }

  def findMaxValue(node: Fruit): Fruit = {
    if (node.right != null) {
      return findSmallestValue(node.right)
    }
    node
  }

  def getFruitList(): List[Fruit] = {
    val list = new ListBuffer[Fruit]()
    getFruits(root,list )
    val list2 = list.toList
    list2
  }

  def getFruits(node: Fruit, list:ListBuffer[Fruit]): Unit = {
    if(node != null){
      getFruits(node.getLeft, list)
      list += node
      getFruits(node.getRight, list)
    }
  }

  def getSuccessor(x: Fruit): Fruit = {
    if (x.right != null) return findSmallestValue(x.right)
    var y = x.getParent
    var temp = x
    while ({y != null && (temp eq y.right)}) {
      temp = y
      y = y.getParent
    }
    y
  }
}
