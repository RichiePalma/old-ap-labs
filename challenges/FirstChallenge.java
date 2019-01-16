// Ricardo Palma 

public class FirstChallenge{
	public static void main(String[] args){
		String input = "pwwkew"; // Test cases: abcabcbb       bbbbb 		pwwkew  
		String subString = "" + input.charAt(0);
		//char subString = input.charAt(0);
		//String subString = Character.toString(input.charAt(0));
		boolean notRepeated = true;
		int longest = 1;
		String longestString = subString;
		
		for(int i = 0; i < input.length() ; i++){
			for(int j = 0; j < subString.length(); j++){ //subString.length() < input.length()

				if(input.charAt(i) != subString.charAt(j)){
					 subString += input.charAt(i);
				}
				else{
					if(longest < subString.length()){
						longest = subString.length();
						longestString = subString;
					}	

					subString = "" + input.charAt(i);
				}
				

				j++;
			}
			
		}
		
		System.out.println(" longest "+ longest);
		
	
	}	
}
