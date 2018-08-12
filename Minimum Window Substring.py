#76
def minWindow( s, t):
    counts={};
    for i,t_i in enumerate(t):
        if t_i not in counts.keys():
            counts[t_i]=1
        else:counts[t_i]+=1
    missing=len(t)
    index_t=[]#存放t在s中的所有位置
    for i,ele in enumerate(s):
        if(missing==0):break;
        if ele in counts.keys():
            if counts[ele]>0:missing-=1
            counts[ele]-=1
            index_t.append(i)
        elif ele in counts.keys():
            index_t.append(i)
    if(len(index_t)<len(t)):return ""
    for i in counts.values():
        if i>0:return ""
    while (counts[s[index_t[0]]] < 0):
        counts[s[index_t[0]]] += 1
        del (index_t[0])
    start=index_t[0];
    end=index_t[-1];
    s_i=end+1
    min=start;max=end;
    for i,ele in enumerate(s[s_i:]):
        if ele==s[start]:
            index_t.append(i+s_i)
            del(index_t[0])
            while(counts[s[index_t[0]]]<0):
                counts[s[index_t[0]]]+=1
                del(index_t[0])
            start=index_t[0];end=index_t[-1]
            if(end-start<max-min):
                min=index_t[0]
                max=index_t[-1]

        elif ele in counts.keys():
            index_t.append(i+s_i)
            counts[ele]-=1
    return s[min:max+1]
s=minWindow("ADOBECODEBANC", "ABC")
print(s);



