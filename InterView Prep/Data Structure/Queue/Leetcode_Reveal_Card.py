class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort(reverse=True)
        result=[]
        result.insert(0,deck.pop(0))
        for i,elem in enumerate(deck):
            result.insert(0,result.pop(-1))
            result.insert(0,elem)
        return result

        