package exp1;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
public class time
{

public static void main( String[] args )

{

	DateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");

	Date date = new Date();

	System.out.println(dateFormat.format(date));

}

}