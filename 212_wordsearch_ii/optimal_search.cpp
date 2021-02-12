class Solution {
public:
  vector<string> result; // stores found words on board
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for(string word : words){
      // search one word at a time
      searchOneWord(board, word);
    }
    return result;
  }
  
  bool searchOneWord(vector<vector<char>>& board, string& word){
    // go through each char in board and search for the word[index] char
    for(int i=0; i<board.size(); i++){
      for(int j=0; j<board[0].size(); j++){
        // no (word[index]==board[i][j]) check required as dfs first condition takes care of it
        if(dfs(board, i, j, word, 0)){
          result.push_back(word); // if found then push in result
          return true;
        }
      }
    }
    return false;
  }
  
  bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index){
    // if the board [i][j] char is not as expected then word is not found "when looked from index i and j on board"
    // this also takes care of visited nodes no need of extra check
    if(word[index] != board[i][j]) return false;
    // when all char of word are present then we simply return true as word is found
    if(index == word.size()-1) return true;
    
    // work around for marking Visited nodes on board itself. We are assigning it back after conducting all dfs
    char temp = board[i][j];
    board[i][j] = '*';
    bool result = false;
    // anywhere we got result as true we are done
    if(i<board.size()-1) result = result || dfs(board, i+1, j, word, index+1); // one char vertically down
    if(j<board[0].size()-1) result = result || dfs(board, i, j+1, word, index+1); // one char to the right
    if(i>0) result = result || dfs(board, i-1, j, word, index+1); // one char upwards
    if(j>0) result = result || dfs(board, i, j-1, word, index+1); // one char to the left
    
    board[i][j] = temp;
    
    return result;
  }
  
};
