import java.util.Scanner;

class MirrorImage
{
    public static void main(String[] args) {
        {
            Scanner scanner = new Scanner(System.in);
            
            System.out.println("Enter number of rows : ");            
            int row = scanner.nextInt();
            System.out.println("Enter number of Columns:");
            int col = scanner.nextInt();

            int[][] Image = new int[row][col];
            int[][] MirrorImage = new int[row][col];

            System.out.println("Enter Values :");

            for(int i=0;i<row;i++)
            {
                for(int j= 0;j<col;j++)
                {
                    Image[i][j] = scanner.nextInt();
                }
            }

            System.out.println("Given Image : ( " + row + " X " + col + " matrix )");

            for(int i = 0;i<row;i++)
            {
                for(int j = 0 ; j<col;j++)
                {
                    System.out.print(Image[i][j] + "\t");
                }
                System.out.println();
            }

            for(int i=0;i<row;i++)
            {
                int k = 0;
                for(int j=col-1;j>=0;j--)
                {
                    MirrorImage[i][k] = Image[i][j];
                    k++;
                }
            }

            System.out.println("Mirror Image : ");

            for(int i = 0;i<row;i++)
            {
                for(int j =0;j<col;j++)
                {

                    System.out.print(MirrorImage[i][j] + "\t");
                }
                System.out.println();
            }
            scanner.close();
        }
    }
}
