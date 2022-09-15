import java.io.*;
import java.util.Scanner;

//Nico Maldonado 4/27/2022
public class GameOfLife
{
    public static char[] board;
    public static int[] live;
    public static int[] death;
    public static int listL = 0, listD = 0;
    public static int iterations = 0;
    public static File file = new File("gameboard.txt");

    //All methods used to create the Game Of Life
    static void createArr() throws IOException{
        String theString = "";
        Scanner scanner = new Scanner(file);

        theString = scanner.nextLine();
        while (scanner.hasNextLine()) {
            theString = theString + "" + scanner.nextLine();
        }
        board = theString.toCharArray();
    }
    static void display() throws IOException{
        for(int i = 0; i < 400; i = i+20){
            System.out.println(board[i] + " " + board[i+1] + " " + board[i+2] + " " + board[i+3] + " " + board[i+4] + " " +
                    board[i+5] + " " + board[i+6] + " " + board[i+7] + " " + board[i+8] + " " + board[i+9] + " " +
                    board[i+10] + " " + board[i+11] + " " + board[i+12] + " " + board[i+13] + " " + board[i+14] + " " +
                    board[i+15] + " " + board[i+16] + " " + board[i+17] + " " + board[i+18] + " " + board[i+19] + "\n");
        }
    }
    static void getGen() throws IOException {
        FileReader fileReader = new FileReader("gameboard.txt");
        BufferedReader buffReader = new BufferedReader(fileReader);
        String currentLine = "", lastLine = "";
        while (null != (currentLine = buffReader.readLine()))
        {
            lastLine = currentLine;
        }
        int lastLineValue = Integer.parseInt(lastLine);
        iterations = lastLineValue;
    }
    static void findLife(){
        for(int i = 0; i < 400; i++){
            int counter = 0;
            if(board[i] == '.'){
                if(i >= 1 && board[i-1] == 'X'){
                    counter++;
                }
                if(i<=398 && board[i+1] == 'X'){
                    counter++;
                }
                if(i>=20 && board[i-20] == 'X'){
                    counter++;
                }
                if(i<=379 && board[i+20] == 'X'){
                    counter++;
                }
                if(counter == 3){
                    listL++;
                }
                counter =0;
            }
        }
        live = new int[listL];
        listL = 0;
        for(int i = 0; i < 400; i++){
            int counter = 0;
            if(board[i] == '.'){
                if(i >= 1 && board[i-1] == 'X'){
                    counter++;
                }
                if(i<=398 && board[i+1] == 'X'){
                    counter++;
                }
                if(i>=20 && board[i-20] == 'X'){
                    counter++;
                }
                if(i<=379 && board[i+20] == 'X'){
                    counter++;
                }
                if(counter == 3){
                    live[listL] = i;
                    listL++;
                }
                counter =0;
            }
        }
    }
    static void findDeath(){
        int counter = 0;
        for(int i = 0; i < 400; i++) {
            if (board[i] == 'X') {
                counter = 0;
                if (i >= 1 && board[i - 1] == 'X') {
                    counter++;
                }
                if (i <= 398 && board[i + 1] == 'X') {
                    counter++;
                }
                if (i >= 20 && board[i - 20] == 'X') {
                    counter++;
                }
                if (i <= 379 && board[i + 20] == 'X') {
                    counter++;
                }
                if (counter > 3 || counter < 2) {
                    listD++;
                }
            }
        }
        death = new int[listD];
        listD = 0;
        for(int i = 0; i < 400; i++) {
            if (board[i] == 'X') {
                counter = 0;
                if (i >= 1 && board[i - 1] == 'X') {
                    counter++;
                }
                if (i <= 398 && board[i + 1] == 'X') {
                    counter++;
                }
                if (i >= 20 && board[i - 20] == 'X') {
                    counter++;
                }
                if (i <= 379 && board[i + 20] == 'X') {
                    counter++;
                }
                if (counter > 3 || counter < 2) {
                    death[listD] = i;
                    listD++;
                }
            }
        }
    }
    static void nextGen(){
        findLife();
        findDeath();
        for(int i = 0; i < listD; i++){
            board[death[i]] = '.';
        }
        for(int i = 0; i < listL; i++){
            board[live[i]] = 'X';
        }
    }

    public static void main(String[] args) throws IOException {
        createArr();
        getGen();
        System.out.println("*****************************************");
        System.out.println("Generation : 1");
        display();
        System.out.println("*****************************************");

        for(int i = 0; i < iterations; i++){
            System.out.println("Generation : " + (i+2));
            nextGen();
            display();
            System.out.println("*****************************************");
        }
    }
}