package COTEMaster.baekjoon;

import java.math.BigInteger; // BigInteger를 사용하기 위해 임포트합니다.
import java.util.Scanner;

public class massive_rich_2_1271 {
    public static void main(String[] args) {
        // 문자열로 큰 정수 생성
        Scanner sc = new Scanner(System.in);
        String tmp = sc.next();
        BigInteger largeNumber1 = new BigInteger(tmp);
        tmp = sc.nextLine().trim();
        BigInteger largeNumber2 = new BigInteger(tmp);

        // 덧셈 연산
        BigInteger share = largeNumber1.divide(largeNumber2);
        System.out.println(share.toString());

        // 곱셈 연산
        BigInteger remain = largeNumber1.mod(largeNumber2);
        System.out.println(remain.toString());
    }
}
