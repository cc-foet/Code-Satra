def subsequence(str1, str2, str3, len1, len2, len3):
    L= [[[0 for i in range(len3+1)] for j in range(len2+1)] for k in range(len1+1)]

    for i in range(len1+1):
        for j in range(len2+1):
            for k in range(len3+1):
                if i==0 or j==0 or k==0:
                    L[i][j][k] = 0
                elif str1[i-1] == str2[j-1] and str2[j-1] == str3[k-1]:
                    L[i][j][k] = L[i-1][j-1][k-1] + 1
                else:
                    L[i][j][k] = max(L[i-1][j][k], L[i][j-1][k], L[i][j][k-1])

    return L[len1][len2][len3]

str1 = "abcd1e2"
str2 = "bc12ea"
str3 = "bd1ea"

len1 = len(str1)
len2 = len(str2)
len3 = len(str3)

print(subsequence(str1, str2, str3, len1, len2, len3))