interface Input {
	void add(char c);
	String getValue();
}

class TextInput implements Input {
	String text = "";
	public void add(char c) {
		text += c;
	}
	public String getValue() {
		return text;
	}
}

class NumericInput extends TextInput {
	@Override
	public void add(char c) {
		if (c <= '9' && c >= '0') {
			text += c;
		}
	}
}


public class App {
	public static void main(String[] args) {
		TextInput input = new NumericInput();
		input.add('1');
		input.add('a');
		input.add('9');
		System.out.println(input.getValue());
	}
}
