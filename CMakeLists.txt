project ( project C )

set (CMAKE_C_STANDARD 11)
# определение точки входа. Будет запущен файл main . c .
# указывается произвольная метка, в данном случае - project
add_executable (project main.c)

 # создаём библиотеку
 add_library ( str string/string_.h string/string_.c
         string/tasks/removeNonLetters.h
         string/tasks/removeExtraSpaces.h
         string/tasks/convertStringDigitsTheEnd.h
         string/tasks/digitCorrespondingNumberOfSpaces.h
         string/tasks/replace.h
         string/tasks/isWordsLexicographicallyOrdered.h
         string/tasks/wordsReverseOrder.h
         string/tasks/countOfPalindromeWords.h
         string/tasks/mergingStrings.h
         string/tasks/reverseWordOrderInAString.h
         string/tasks/getWordBeforeFirstWordWithA.h
         string/tasks/lastWordInFirstStringInSecondString.h
         string/tasks/isIdenticalWordsInString.h
         string/tasks/isPairOfWordsMadeOfIdenticalLetters.h
         string/tasks/getStringFromTheWordsOfDifferentFromTheLastWord.h
         string/tasks/lastWordInTheFirstLineThatIsInTheSecondLine.h
         string/tasks/removeWordsThatMatchLastWord.h
         string/tasks/addToAStringContainingFewerWords.h
         string/tasks/isEachLetterOfTheWordIncludedInTheString.h
)

 # описываем, что для запуска project потребуется сборка tasks
 target_link_libraries (project str)
