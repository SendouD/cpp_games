import java.util.*;


public class tic_tac_toe{
    static char[][] board =new char[3][3];
    static char player='X';
    static boolean gameOver = false;
    public static void main(String[] args) {

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j] =' ';
            }
        }
        Scanner sc = new Scanner(System.in);
        System.out.println("1.single player");
        System.out.println("2.multiplayer player");

        int mode = sc.nextInt();
        if(mode ==1){
            modeai();

        }
        else modemulti();




        }
    public static void printboard(char[][] board) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j]);
                if (j < 2) {
                    System.out.print(" | ");
                }
            }
            System.out.println();
            if (i < 2) {
                System.out.println("---------");
            }
        }
    }

    public static boolean check(int row, int col){
        return board[row][col] == ' ';

        }
        public static boolean checkboard (char[][] board,char player) {
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == player && board[i][1] == player && player == board[i][2])
                    return true;
            }
            for (int i = 0; i < 3; i++) {
                if (board[0][i] == player && player == board[1][i] && player == board[2][i])
                    return true;
            }
            for (int i = 0; i < 3; i++) {
                if (board[0][0]==player&&board[1][1]==player&&board[2][2]==player){
                    return true;

                }
            }
            for (int i = 0; i < 3; i++) {
                if (board[0][2]==player&&board[1][1]==player&&board[2][0]==player){
                    return true;

                }
            }
            return false;


        }
        public static void modemulti(){
            Scanner sc=new Scanner(System.in);
            while (!gameOver){
                if(draw()){
                    System.out.println("DRAW!!!!");
                    gameOver=true;
                    break;
                }
                printboard(board);
                System.out.println("\nplayer " + player );
                System.out.println("x and y Co-ordinates: " );
                int row = sc.nextInt();
                int col = sc.nextInt();



                if(check(row, col)){
                    board[row][col] = player;
                    if(!checkboard(board,player)) {
                        if(player=='X'){
                            player='O';

                        }
                        else player='X';
                    }
                    else {
                        printboard(board);
                        System.out.println("player "+player+" won");
                        gameOver=true;
                    }
                }
                else {
                    System.out.println("incorrect coordinates");
                }





            }

        }

        public static void generatepostion(){
        int occupied=1;
            Random random = new Random();


        while (occupied==1){
            int row=random.nextInt(3);
            int col=random.nextInt(3);
            if(board[row][col]==' '){
                board[row][col] ='O';
                occupied=0;
            }
        }

        }
        public static boolean draw(){
            int flag=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (board[i][j] == ' ') {
                    flag = 1;
                    break;
                }
                }

            }
            return flag == 0;

        }


    public static void modeai(){
        Scanner sc=new Scanner(System.in);
        int row,col;
        while (!gameOver){
            if(draw()){
                System.out.println("DRAW!!!!");
                gameOver=true;
                break;
            }
            printboard(board);
            System.out.println("\nplayer " + player );


            if(player=='X'){

                System.out.println("x and y Co-ordinates: " );
                row = sc.nextInt();
                col = sc.nextInt();
                if(check(row, col)){
                    board[row][col] = player;
                    if(!checkboard(board,player)) {
                        if(player=='X'){
                            player='O';

                        }
                        else player='X';
                    }
                    else {
                        printboard(board);
                        System.out.println("player "+player+" won");
                        gameOver=true;
                    }
                }
                else {
                    System.out.println("incorrect coordinates");
                }
            }
            else {
                generatepostion();
                if(!checkboard(board,player)) {
                  player = 'X';
                }
                else {
                    printboard(board);
                    System.out.println("player "+player+" won");
                    gameOver=true;
                }


            }






    }

        }}



