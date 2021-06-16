function Fruit() {}
Fruit.prototype = {
    weight: 0,
    left: null,
    right: null,
    parent: null,

    getParent: function() {
        return this.parent;
    },

    getLeft: function() {
        return this.left;
    },

    getRight: function() {
        return this.right;
    },

    getWeight: function() {
        return this.weight;
    },

    getType: function() {
        return "Regular";
    }
};

function ovalShaped() {}
ovalShaped.prototype = {
    __proto__: Fruit.prototype,

    getType: function() {
        return "OvalShaped ";
    }
};

function tinyFruit() {}
tinyFruit.prototype = {
    __proto__: Fruit.prototype,

    getType: function() {
        return "TinyFruit";
    }
};

function Berry() {}
Berry.prototype = {
    __proto__: tinyFruit.prototype,

    getType: function() {
        return "Berry";
    }
};


function Apple() {}
Apple.prototype = {
    __proto__: ovalShaped.prototype,

    getType: function() {
        return "Apple";
    }
};

function Avocado() {}
Avocado.prototype = {
    __proto__: ovalShaped.prototype,

    getType: function() {
        return "Avocado";
    }
};

function Blackberries() {}
Blackberries.prototype = {
    __proto__: Berry.prototype,

    getType: function() {
        return "Blackberries";
    }
};

function Elderberries() {}
Elderberries.prototype = {
    __proto__: Berry.prototype,

    getType: function() {
        return "Elderberries";
    }
}

export { Fruit, ovalShaped, Berry, tinyFruit, Apple, Avocado, Blackberries, Elderberries };