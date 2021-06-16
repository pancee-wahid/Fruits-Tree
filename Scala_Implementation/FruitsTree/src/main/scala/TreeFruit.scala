import scala.collection.mutable.ListBuffer

class TreeFruit {
  var root : Fruit = null
  def getRoot: Fruit = root
  def insert(weight: Int, Type: String): Unit = {
    var node : Fruit = new Fruit
    Type match {
      case "OvalShaped" => node = new OvalShaped()
      case "Apple" => node = new Apple()
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
      // if left is null insert node here
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
      newCurrent.parent = prev
    }
    else{
      var successor : Fruit = getSuccessor(current)
      removeNode(root, successor.getWeight)
     /* if(successor.parent.left ==successor ){
        successor.parent.left = null
      }
      else{
        successor.parent.right = null
      }*/
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
  def iterate(): Unit = {
    getFruitList().foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))

  }
  /*def inOrder(node : Fruit): Unit = {
    if(node != null){
      inOrder(node.getLeft)
      println(node.getType + " " + node.getWeight)
      inOrder((node.getRight))
    }
  }*/



  def filterByType[T](t : Class[T]): Unit ={
    getFruitList().filter(p => t.isAssignableFrom(p.getClass)).foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))
  }
  def filterByWeight(weight : Int): Unit ={
    //filterByWeightHelper(root,weight)
    getFruitList().filter(_.weight > weight).foreach(x =>println(x.getClass.getSimpleName + " " + x.getWeight))
  }
  /*def filterByWeightHelper(node: Fruit, weight : Int): Unit = {
    if(node != null){
      filterByWeightHelper(node.getLeft, weight)
      if(weight < node.getWeight)
        println(node.getType + " " + node.getWeight)
      filterByWeightHelper(node.getRight, weight)
    }
  }*/
 /* def magnifyByType(Type: String, weight: Int): Unit ={
    val list = new ListBuffer[Int]()
    magnifyByTypeHelper(root, Type, weight, list)
    val list2 = list.toList
    list2.foreach(r => insert(r, Type))
  }
  def magnifyByTypeHelper(node: Fruit ,Type: String, weight: Int, list: ListBuffer[Int]): Unit = {
    if(node != null){
      magnifyByTypeHelper(node.left, Type, weight, list)
      if(node.getType == Type + " fruit"){
        var weightTemp = node.getWeight
        weightTemp = weightTemp + weight
        list+= weightTemp
      }
      magnifyByTypeHelper(node.right, Type, weight, list)

    }
  }*/



    def findLightest() :Fruit = {
    findSmallestValue(root)
  }
  def findSmallestValue(node: Fruit): Fruit = {
    if (node.left != null) {
      return findSmallestValue(node.left)
    }
    node
  }
  def findHeaviest() :Fruit = {
    findMaxValue(root)
  }
  def findMaxValue(node: Fruit): Fruit = {
    if (node.right != null) {
      return findSmallestValue(node.right)
    }
    node
  }
  def getFruitList(): List[Fruit] = {
    val list = new ListBuffer[Fruit]()
    //magnifyByTypeHelper(root, Type, weight, list)
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

  //used in TreeMap
  def getSuccessor(x: Fruit): Fruit = {
    if (x.right != null) return findSmallestValue(x.right)
    var y = x.getParent
    var temp = x
    while ( {
      y != null && (temp eq y.right)
    }) {
      temp = y
      y = y.getParent
    }
    y
  }
}
