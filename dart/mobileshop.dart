class Product {
  String name;
  double price;
  int stock;

  Product(this.name, this.price, this.stock);

  void displayProduct() {
    print('Product: $name');
    print('Price: \$${price.toStringAsFixed(2)}');
    print('Stock: $stock');
  }
}

class ShoppingCart {
  List<Product> products = [];

  void addProduct(Product product) {
    products.add(product);
    print('${product.name} added to cart.');
  }

  void removeProduct(Product product) {
    if (products.contains(product)) {
      products.remove(product);
      print('${product.name} removed from cart.');
    } else {
      print('${product.name} is not in the cart.');
    }
  }

  void displayCart() {
    print('Shopping Cart:');
    for (Product product in products) {
      product.displayProduct();
      print('');
    }
  }
}

void main() {
  // Create some products
  Product iPhone = Product('iPhone 13', 999.99, 10);
  Product Samsung = Product('Samsung Galaxy S21', 799.99, 5);

  // Create a shopping cart
  ShoppingCart cart = ShoppingCart();

  // Add some products to the cart
  cart.addProduct(iPhone);
  cart.addProduct(Samsung);

  // Display the shopping cart
  cart.displayCart();

  // Remove a product from the cart
  cart.removeProduct(Samsung);

  // Display the updated shopping cart
  cart.displayCart();
}
