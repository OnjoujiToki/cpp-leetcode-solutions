class Solution:
    def reformatDate(self, date: str) -> str:
        month = {"Jan": "01",
             "Feb": "02", 
             "Mar": "03", 
             "Apr": "04", 
             "May": "05", 
             "Jun": "06", 
             "Jul": "07", 
             "Aug": "08", 
             "Sep": "09", 
             "Oct": "10", "Nov": "11", 
             "Dec": "12"}
        s = date.split(" ")
        res  = s[0][:-2]
        if len(res) == 1:
            res = s[2] + "-" +month[s[1]]+"-"+"0" + res
        else:
            res = s[2] + "-" + month[s[1]]+"-"+ res
        return res