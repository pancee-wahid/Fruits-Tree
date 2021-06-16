import {Fruit, ovalShaped, Berry, tinyFruit, Apple, Avocado, Blackberries, Elderberries} from './Fruit.mjs';
class Tree {
	constructor() {
		this.root = null;
	}

	insert(weight, type) {
		var newFruit;
		switch(type) {
			case "Oval-Shaped":
				newFruit = Object.create(ovalShaped.prototype);
				break;
			case "Tiny-Fruit":
				newFruit = Object.create(tinyFruit.prototype);
				break;
			case "Berry":
				newFruit = Object.create(Berry.prototype);
				break;
			case "Apple":
				newFruit = Object.create(Apple.prototype);
				break;
			case "Avocado":
				newFruit = Object.create(Avocado.prototype);
				break;
			case "Blackberry":
				newFruit = Object.create(Blackberries.prototype);
				break;
			case "Elderberry":
				newFruit = Object.create(Elderberries.prototype);
				break;
			default:
				newFruit = Object.create(Fruit.prototype);
				break;
		}
		newFruit.weight = weight;
		newFruit.left = null;
		newFruit.right = null;
		if (this.root === null)
			this.root = newFruit;
		else
			this.insertHelper.call(this, this.root, newFruit);
	}

	insertHelper(node, newFruit) {
		if (newFruit.getWeight() < node.getWeight()) {
			//if left is null insert node here
			if(node.getLeft() === null){
				node.left = newFruit;
				node.left.parent = node;
			} else {
				this.insertHelper.call(this, node.left, newFruit);
			}
		} else if (newFruit.getWeight() > node.getWeight()) {
			// if right is null insert node here
			if(node.getRight() === null){
				node.right = newFruit;
				node.right.parent = node;
			} else {
				this.insertHelper.call(this, node.right, newFruit );
			}
		} else {
			newFruit.parent = node.parent;
			newFruit.left = node.left;
			newFruit.right = node.right;
			if (node.left !== null)
				node.left.parent = newFruit;
			if (node.right !== null)
				node.right.parent = newFruit;

			if (node.parent !== null){
				if (node.parent.left === node)
					node.parent.left = newFruit;
				else
					node.parent.right = newFruit;
			} else {
				this.root = newFruit;
			}
	    }
	}
	
	iterate() {
		return this.inOrder.call(this, this.root);
	}
	
	inOrder(node) {
		if (node !== null) {
			//console.log(node.right.getWeight());
			this.inOrder.call(this, node.left);
			console.log(node.getType() + " " + node.getWeight() + " gm");
			this.inOrder.call(this, node.right);
		}
	}

	filterByType(type) {
		return this.filterByTypeHelper.call(this, this.root, type);
	}

	filterByTypeHelper(node, type) {
		if (node !== null) {
			//console.log(node.left.getType());
			this.filterByTypeHelper.call(this, node.left, type);
			if(node.getType() === type + " fruit")
				console.log(node.getType() + " " + node.getWeight() + " gm");
			this.filterByTypeHelper.call(this, node.right, type);
		}
	}

	filterByWeight(weight) {
		return this.filterByWeightHelper.call(this, this.root, weight);
	}

	filterByWeightHelper(node, weight){
		if (node !== null) {
			this.filterByWeightHelper.call(this, node.left, weight);
			if (node.getWeight() > weight)
				console.log(node.getType() + " " + node.getWeight() + " gm");
			this.filterByWeightHelper.call(this, node.right, weight);
		}
	}

	magnifyByType(type, weight) {
		let removed = [];
		this.magnifyByTypeHelper.call(this, this.root, type, weight, removed);
		for (let i = 0; i < removed.length; i++)
			this.insert(removed[i], Type);
	}

	magnifyByTypeHelper(node, type, weight, arr) {
		if (node !== null) {
			this.magnifyByTypeHelper.call(this, node.left, type, weight, arr);
			if (node.getType() === Type + " fruit") {
				var weightTemp = node.getWeight();
				weightTemp += weight;
				arr.push(weightTemp);
				this.remove.call(this, node.getWeight());
			}
			this.magnifyByTypeHelper.call(this, node.right, type, weight, arr);
		}
	}
	
	// helper method that calls the
	// removeNode with a given data
	remove(weight) {
		//root is re-initialized with
		//root of a modified tree.
		this.root = this.removeNode.call(this, this.root, weight);
	}

	removeNode(node, weight) {
		// if the root is null then tree is
		// empty
		if (node === null)
			return null;

		// if data to be delete is less than
		// roots data then move to left subtree
		else if (weight < node.getWeight()) {
			node.left = this.removeNode.call(this, node.left, weight);
			return node;
		}

		// if data to be delete is greater than
		// roots data then move to right subtree
		else if (weight > node.getWeight()) {
			node.right = this.removeNode.call(this,node.right, weight);
			return node;
		}

		// if data is similar to the root's data
		// then delete this node
		else {
			// deleting node with no children
			if (node.left === null && node.right === null) {
				node = null;
				return node;
			}

			if (node.left === null) {
				node = node.right;
				return node;
			} else if (node.right === null) {
				node = node.left;
				return node;
			}

			var aux = this.findMin.call(this, node.right);
			if (node.parent !== null){
				if(node.parent.getLeft === node)
					node.parent.left = aux;
				else
					node.parent.right = aux;
			}
			
			if (aux.parent.left === aux)
			  aux.parent.left = null;
			else
				aux.parent.right = null;
			aux.parent = node.parent;
			aux.right = node.right;
			aux.left = node.left;
			if (node.left !== null)
				node.left.parent = aux;
			if (node.right !== null)
				node.right.parent = aux;
			node = aux;
			return node;
		}
	}

	findLightest() {
		return this.findMin.call(this,this.root);
	}

	findMin(node) {
		if (node.left === null)
			return node;
		else
			return this.findMin.call(this,node.left);
	}

	findHeaviest() {
		return this.findMax.call(this,this.root);
	}

	findMax(node) {
		if (node.right === null)
			return node;
		else
			return this.findMax.call(this,node.right);
	}
}


var BST = new Tree();
BST.insert(12, "Apple");
BST.insert(5, "Avocado")
BST.insert(15, "Orange");
BST.insert(8,"Blackberry");
BST.insert(15,"Elderberry");

BST.iterate();
console.log("------------------------");
BST.filterByType("Apple");
console.log("------------------------");
BST.filterByWeight(12);
console.log("------------------------");
BST.magnifyByType("Apple", 3);

console.log("------------------------");
BST.iterate();
console.log("------------------------");
console.log(BST.findLightest().getWeight() + " " + BST.findLightest().getType());
console.log("------------------------");
console.log(BST.findHeaviest().getWeight() + " " + BST.findHeaviest().getType());