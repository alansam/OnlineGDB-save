
public class Main {
	public static void main(String[] args) {
		System.out.println("Swapper - call-by-reference");
		var i1 = 5;
		var j1 = 11;
		System.out.println("I: " + i1 + " J: " + j1);
		swap(i1, j1);
		System.out.println("I: " + i1 + " J: " + j1);

    var s1 = "String S";
    var t1 = "String T";
		System.out.println("S: '" + s1 + "' T: '" + t1 + "'");
		swap(s1, t1);
		System.out.println("S: '" + s1 + "' T: '" + t1 + "'");

    var v1 = new Integer(5);
    var w1 = new Integer(11);
		System.out.println("V: '" + v1 + "' W: '" + w1 + "'");
		swap(s1, t1);
		System.out.println("V: '" + v1 + "' W: '" + w1 + "'");

    var a1 = new Main.Int(5);
    var b1 = new Main.Int(11);
		System.out.println("A: " + a1.toString() + " B: " + b1.toString());
		swap(a1, b1);
		System.out.println("A: " + a1.toString() + " B: " + b1.toString());

    return;
	}

  private static void swap(int is, int js) {
    var ks = is;
    is = js;
    js = ks;
  }

  private static void swap(String is, String js) {
    var ks = is;
    is = js;
    js = ks;
  }

  private static void swap(Integer is, Integer js) {
    var ks = is;
    is = js;
    js = ks;
  }

  private static void swap(Main.Int is, Main.Int js) {
    var ks = is;
    is.val = js.val;
    js.val = ks.val;
  }

  static class Int {
    public Int(int v_) { val = v_; }
    public String toString() { return Integer.toString(val); }
    int val;
  }
}





