class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        
        #hashmap = dict()
        #for i in words:
            
        #    if i in hashmap:
        #        hashmap[i] += 1
        #    else:
        #        hashmap[i] = 1
        
        #return sorted(hashmap.keys(), key= lambda w: (-hashmap[w], w))[:k]
        
        hashmap = dict()
        maxhash = 1
        returnList = []
        
        for x in words:
            
            if x in hashmap:
                hashmap[x] += 1
                maxhash = max(maxhash, hashmap[x])
            else:
                hashmap[x] = 1
                
        maximum = maxhash
        
        while maximum >= 1:
            
            templist = []
            for item in hashmap:
                if hashmap[item] == maximum:
                    templist.append(item)
                
            templist.sort()
            for n in templist:
                returnList.append(n)
                if len(returnList) == k:
                    return returnList
                   
            maximum -= 1
                
            
            
            
            
            
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        