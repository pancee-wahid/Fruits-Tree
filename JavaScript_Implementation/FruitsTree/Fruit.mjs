function Fruit() {}
Fruit.prototype = {
	weight : 0,
	left : null,
	right : null,
	parent : null,

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
		return "Just a fruit";
	}
};

function ovalShaped() {}
ovalShaped.prototype = {
	__proto__: Fruit.prototype,

	getType: function() {
		return "Oval-Shaped fruit";
	}
};

function tinyFruit() {}
tinyFruit.prototype = {
	__proto__: Fruit.prototype,

	getType: function() {
		return "Tiny-Fruit";
	}
};

function Berry() {}
Berry.prototype = {
	__proto__: tinyFruit.prototype,

	getType: function() {
		return "Berry fruit";
	}
};


function Apple() {}
Apple.prototype = {
	__proto__: ovalShaped.prototype,

	getType: function() {
		return "Apple fruit";
	}
};

function Avocado() {}
Avocado.prototype = {
	__proto__: ovalShaped.prototype,

	getType: function() {
		return "Avocado fruit";
	}
};

function Blackberries() {}
Blackberries.prototype = {
	__proto__: Berry.prototype,

	getType: function() {
		return "Blackberries fruit";
	}
};

function Elderberries() {}
Elderberries.prototype = {
	__proto__: Berry.prototype,

	getType: function() {
		return "Elderberries fruit";
	}
}

export {Fruit, ovalShaped, Berry, tinyFruit, Apple, Avocado, Blackberries, Elderberries};