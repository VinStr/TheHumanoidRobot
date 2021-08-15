import re
import pronouncing

texts = "april is the cruelest month breeding lilacs out of the dead"
words = texts.split()
WordToPhn=[]
for word in words:
    pronunciation_list = pronouncing.phones_for_word(word)[0] # choose the first version of the phoneme
    WordToPhn.append(pronunciation_list)

SentencePhn='  '.join(WordToPhn)
Output = re.sub(r'\d+', '', SentencePhn) #Remove the digits in phonemes
print(Output)



from g2p_en import G2p

g2p = G2p()
for text in texts:
    out = g2p(text)
    print(out)

#SentencePhn: EY1 P R AH0 L  IH1 Z  DH AH0  K R UW1 L AH0 S T  M AH1 N TH  B R IY1 D IH0 NG  L AY1 L AE2 K S  AW1 T  AH1 V  DH AH0  D EH1 D

#Output:EY P R AH L  IH Z  DH AH  K R UW L AH S T  M AH N TH  B R IY D IH NG  L AY L AE K S  AW T  AH V  DH AH  D EH D