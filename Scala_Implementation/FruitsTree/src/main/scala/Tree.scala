import scala.collection.mutable.ArrayBuffer

/*class Tree[A <: Ordered[A]] {
  case class Node(var data: A,
                  var left: Option[Node] = None,
                  var right: Option[Node] = None,
                  var parent: Option[Node] = None)

  private var root: Option[Node] = None
  private var size: Int = 0

  def getSize: Int = size

  def insert(data: A): Unit = {
    if (data == null) return

    size = size + 1
    root match {
      case None => root = Some(Node(data))
      case Some(_) =>
        root = insertHelper(root, data)
       /* var currentNode: Option[Node] = None
        var nextNode = root
        var biggerThan: Boolean = true

        /*Get node place.*/
        do {
          currentNode = nextNode
          biggerThan = data > currentNode.get.data

          if (biggerThan) nextNode = currentNode.get.right
          else nextNode = currentNode.get.left

        } while (nextNode.isDefined)*/
    }
  }
  def insertHelper(node: Option[Node], data: A): Option[Node] = {
    if (node != null && data <= node.get.data) {
      node.get.left = insertHelper(node.get.left , data)
    }
      if (node != null && data > node.get.data) {
        node.get.right = insertHelper(node.get.right, data)
      }
         node
  }
  private def removeRecursion(node: Option[Node], value: A): Option[Node] = {
    if (node == null) {
      return node
    }

    if (value < node.get.data) {
      node.get.left=removeRecursion(node.get.left, value)
    } else if (value > node.get.data) {
      node.get.right = removeRecursion(node.get.right, value)
    } else {
      if (node.get.left == null && node.get.right == null) {
        return null
      }

      if (node.get.left == null) {
        return node.get.right
      }

      if (node.get.right == null) {
        return node.get.left
      }

      val smallest: A = findSmallestValue(node.get.right)
      node.get.data=(smallest)
      node.get.right=(removeRecursion(node.get.right, value))
    }

    node
  }
  private def findSmallestValue(node: Option[Node]): A = {
    if (node.get.left != null) {
      return findSmallestValue(node.get.left)
    }
    node.get.data
  }


}
*/
