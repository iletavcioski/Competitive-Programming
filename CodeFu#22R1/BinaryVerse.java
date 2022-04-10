import java.util.*;

public class BinaryVerse {
  public String findPath(int N) {
    int[] list_l = new int[1001];
    int[] list_h = new int[1001];
    int nodes = 1;
    int nodes_line = 1;
    int right = 1;
    int depth = 1;
    list_l[0] = 1;
    list_h[0] = 1;
    while (nodes < N) {
        list_l[depth] = nodes + 1;
        nodes_line *= 2;
        nodes += nodes_line;
        list_h[depth] = nodes;
        right = 1 - right;
        depth += 1;
    }

    int[] res = new int[1001];
    int fin_depth = depth - 1;
    depth--;

    while (depth > 0) {
      res[depth] = N;
      int dist = 0;
      if (right == 1) {
        dist = N - list_l[depth];
      } else {
        dist = list_h[depth] - N;
      }
      //System.out.println(dist);
      dist = (dist) / 2;
      right = 1 - right;
      //System.out.println("->>>" + list_h[depth - 1]);
      if (right == 0) {
        N = list_h[depth - 1] - dist;
      } else {
        N = list_l[depth - 1] + dist;
      }
      depth--;
    }
    res[0] = N;
         
    
    String result = "";
    for (int i = 0; i <= fin_depth; i++) {
      if (i > 0) {
        result += ";";
      }
      result += Integer.toString(res[i]);
    }
    return result;
  }

  public static void main(String args[]) {
    BinaryVerse b = new BinaryVerse();
    System.out.println(b.findPath(1));
  }
}
  