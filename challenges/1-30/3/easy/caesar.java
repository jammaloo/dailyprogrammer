public class caesar
{
    public static void main(String[] args)
    {
        //make sure there are 3 arguments, but we just assume the args are correct
        if(args.length != 3)
        {
            System.out.println("Usage: java caesar encrypt|decrypt shift text");
            return;
        }
        int shift = Integer.parseInt(args[1]) % 26;
        if(args[0].equals("decrypt")) shift = 26 - shift;
        System.out.println(encrypt(shift, args[2]));
    }

    public static String encrypt(int shift, String text)
    {
        String alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String shifted_alphabet = "";
        int current_index = 0;
        for(int i = 0; i < alphabet.length(); i++)
        {
            if(i < 26)
            {
                current_index = (i + shift) % 26;
            }
            else
            {
                current_index = 26 + ((i - 26) + shift) % 26;
            }
            shifted_alphabet += alphabet.charAt(current_index);
        }

        System.out.println(shifted_alphabet);

        String output = "";
        int position = 0;

        for(int i = 0; i < text.length(); i++)
        {
            position = alphabet.indexOf(text.charAt(i));
            if(position == -1)
            {
                output = output + text.charAt(i);
                continue;
            }
            output = output + shifted_alphabet.charAt(position);
        }
        return output;
    }
}
