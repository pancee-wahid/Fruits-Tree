import { Fruit, ovalShaped, Berry, tinyFruit, Citrus, Apple, Avocado, Blackberries, Elderberries, Lemon, Orange, Tangerine } from './Fruit.mjs';
class Tree {
    constructor() {
        this.root = null;
    }

    insert(weight, type) {
        var newFruit;
        switch (type) {
            case "ovalShaped":
                newFruit = Object.create(ovalShaped.prototype);
                break;
            case "TinyFruit":
                newFruit = Object.create(tinyFruit.prototype);
                break;
            case "Citrus":
                newFruit = Object.create(Citrus.prototype);
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
            case "Lemon":
                newFruit = Object.create(Lemon.prototype);
                break;
            case "Orange":
                newFruit = Object.create(Orange.prototype);
                break;
            case "Tangerine":
                newFruit = Object.create(Tangerine.prototype);
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
            if (node.getLeft() === null) {
                node.left = newFruit;
                node.left.parent = node;
            } else {
                this.insertHelper.call(this, node.left, newFruit);
            }
        } else if (newFruit.getWeight() > node.getWeight()) {
            // if right is null insert node here
            if (node.getRight() === null) {
                node.right = newFruit;
                node.right.parent = node;
            } else {
                this.insertHelper.call(this, node.right, newFruit);
            }
        } else {
            newFruit.parent = node.parent;
            newFruit.left = node.left;
            newFruit.right = node.right;
            if (node.left !== null)
                node.left.parent = newFruit;
            if (node.right !== null)
                node.right.parent = newFruit;

            if (node.parent !== null) {
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
        let list = [];
        this.getList.call(this, this.root, list);
        list.forEach(x => {
            console.log(x.getType() + " " + x.getWeight() + " gm");
        });
    }

    filterByType(type) {
        let list = [];
        let outputList = [];
        this.getList.call(this, this.root, list);
        list.forEach(x => {
            if (x instanceof type) {
                outputList.push(x)
            }
        });
        return outputList
    }

    filterByWeight(weight) {
        let list = [];
        this.getList.call(this, this.root, list);
        list.forEach(x => {
            if (x.getWeight() > weight) {
                console.log(x.getType() + " " + x.getWeight() + " gm");
            }
        });
    }

    magnifyByType(type, weight) {
        let removed = this.filterByType.call(this, type);
        removed.forEach(x => {
            this.remove.call(this, x.getWeight());
        });
        removed.forEach(x => {
            x.weight += weight;
        });
        removed.forEach(x => {
            this.insert.call(this, x.getWeight(), x.getType());
        });
    }

    findHeaviest() {
        return this.findMax.call(this, this.root);
    }

    findLightest() {
        return this.findMin.call(this, this.root);
    }

    getList(node, list) {
        if (node !== null) {
            this.getList.call(this, node.left, list);
            list.push(node)
            this.getList.call(this, node.right, list);
        }
    }

    remove(weight) {
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
            node.right = this.removeNode.call(this, node.right, weight);
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
            if (node.parent !== null) {
                if (node.parent.getLeft === node)
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

    findMin(node) {
        if (node.left === null)
            return node;
        else
            return this.findMin.call(this, node.left);
    }

    findMax(node) {
        if (node.right === null)
            return node;
        else
            return this.findMax.call(this, node.right);
    }
}


var BST = new Tree();
BST.insert(12, "Apple");
BST.insert(13, "Lemon");
BST.insert(5, "Avocado");
BST.insert(8, "Blackberry");

BST.iterate();
console.log("------------------------");
BST.filterByType(Citrus).forEach(x => {
    console.log(x.getWeight() + " " + x.getType());
});
console.log("------------------------");
BST.filterByWeight(12);
console.log("------------------------");
BST.magnifyByType(Apple, 4);
BST.iterate();
console.log("------------------------");
console.log(BST.findLightest().getWeight() + " " + BST.findLightest().getType());
console.log("------------------------");
console.log(BST.findHeaviest().getWeight() + " " + BST.findHeaviest().getType());
console.log("------------------------");
BST.magnifyByType(ovalShaped, 4);
BST.iterate();