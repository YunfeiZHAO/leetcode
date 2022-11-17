package java;

import java.util.Map;
import java.util.HashMap;




public class Main {
    // public static int[] twoSum(int[] nums, int target) {
      
    // }


    public static void main(String[] args) {
      float[][] p = { { 1, 2 , 5}, { 3, 4, 10 }, {4,6, 11} };
      int stocks = 2;

      int t = p.length;
      int n = p[0].length;

      float[] m = new float[n];
      for(float[] a : p) {
        for(int i=0; i<n; i++) {
          m[i] = m[i] + a[i];
        }
      }
      for(int i = 0; i<n; i++) {
        m[i] = m[i]/t;
      }


      for(float v : m) {
        System.out.printf("%.2f ", v);
      }
    }
  }