package lab1;

import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        System.out.println(checkTwoStrings("bbbccceeefff", "aaabbbcccddd")); // Результат: рядок символів (виконується умова)
        System.out.println(checkTwoStrings("aaabbbccc", "xxxyyyzzz")); // Результат: пустий рядок (умова не виконується - збігів немає)
    }

    public static String checkTwoStrings(String s1, String s2){
        // Використовуємо мутабельний рядок для результату
        StringBuilder result = new StringBuilder();

        // Отримуємо дві хеш-таблиці, які містять частоту потрапляння кожного символа в рядок
        HashMap<Character, Integer> charsFreqS1 = getFrequencyMap(s1);
        HashMap<Character, Integer> charsFreqS2 = getFrequencyMap(s2);

        // Ітеруємо по сету ключів (символів) з хеш-таблиці першого рядку
        for(char c: charsFreqS1.keySet()){
            if(charsFreqS1.get(c) >= 3 && charsFreqS2.getOrDefault(c, 0) >= 3){
                result.append(c);
            }
        };

        // Повертаємо результуючу строку
        return result.toString();
    };

    // Метод створення хеш-таблиці частоти потрапляння кожного символа в рядок
    public static HashMap<Character, Integer> getFrequencyMap(String str){
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c: str.toCharArray()){
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        return freq;
    }
}
