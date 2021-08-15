#!/usr/bin/env python

import rospy
from gtts import gTTS
from pygame import mixer
import pronouncing
from SimpleAudioIndexer import SimpleAudioIndexer as sai
import os
import csv
from std_msgs.msg import String
from head_pkg.msg import Head

headStore = Head()

def callbackSpeach(data):
    txt = data.data
    if txt != "":
        sayText(txt)

def callbackHead(data):
    global headStore
    headStore = data

def sendExpression(expres):
    print(expres)
    message = headStore
    message.expression = int(expres)
    pub.publish(message)

# Define a function to normalize a chunk to a target amplitude.
def match_target_amplitude(aChunk, target_dBFS):
    ''' Normalize given audio chunk '''
    change_in_dBFS = target_dBFS - aChunk.dBFS
    return aChunk.apply_gain(change_in_dBFS)

def TTS(speechTxt,filename):
    v =gTTS(text=speechTxt,lang="en")
    tempPath = os.path.dirname(os.path.realpath(__file__))+'/speech/temp.wav'
    v.save(tempPath)
    cmd = 'ffmpeg -i '+ os.path.abspath(tempPath)+' -af adelay=100 '+ os.path.abspath(filename)
    os.system(cmd)
    #ffmpeg.input('speech/temp.wav').filter_('adelay','delays=1000').output(filename).run()

def getAudioFilename(phrase,folder):
    if folder==False:
        filename = "phrase_"+phrase+".wav"
    else:
        filename = "speech/phrase_"+phrase+".wav"
    return filename

def getCsvFilename(phrase,folder):
    if folder==False:
        filename = "phrase_"+phrase+".csv"
    else:
        filename = "speech/phrase_"+phrase+".csv"
    return filename

def getPhonemesTiming(speechTxt,csvFilename):
    txtTmp = speechTxt.replace(" ", "_")
    
    indexer = sai(mode = "cmu", src_dir=os.path.abspath(os.path.dirname(os.path.realpath(__file__))+"/speech"))
    indexer.index_audio(basename=getAudioFilename(txtTmp,False))
    timestampes = indexer.get_timestamps()[getAudioFilename(txtTmp,False)]
    
    words = speechTxt.split()
    allPhonemes = getPhonemes(words)
    
    newTimestampes = []
    if len(timestampes) == len(words) or ( len(timestampes) == 1 and len(words) == 1 ):
        i = 0
        for item in timestampes:
            newTimestampes.append([words[i] , allPhonemes[i] , item[1] , item[2] ])
            i += 1
    elif len(timestampes) < len(words):
        print("--------------------error-----------------------")
    elif len(timestampes)>1 and len(words) == 1:
        newTimestampes = combineTimestamp(words[0],allPhonemes[0],timestampes[0],timestampes[-1])
    else:
        skip = False
        place = 0
        for i in range(len(timestampes)):
            if skip == True:
                skip = False
                continue
            elif timestampes[i][0] == words[place] or i == len(timestampes)-1 or timestampes[i+1][0] == words[place+1]:
                newTimestampes.append([ words[place] , allPhonemes[place] , timestampes[i][1] , timestampes[i][2] ])
            else:
                newTimestampes.append(combineTimestamp(words[place],allPhonemes[place],timestampes[i],timestampes[i+1]))
                skip = True
            if len(newTimestampes) == len(words):
                break
            place += 1
            
    with open(csvFilename,"w") as f:
        wr = csv.writer(f)
        if len(words) > 1:
            wr.writerows(newTimestampes)
        else:
            wr.writerow(newTimestampes)
    return newTimestampes
            
def combineTimestamp(word, phoneme , item1, item2):
    item = [ word , phoneme , item1[1] , item2[2] ]
    return item

def getPhonemes(words):
    allPhonemes = []
    for word in words:
        pronunciation_list = pronouncing.phones_for_word(word)[0]
        allPhonemes.append(pronunciation_list)
    return allPhonemes

'''
Replace a set of multiple sub strings with a new string in main string.
'''
def replaceMultiple(mainString, toBeReplaces, newString):
    # Iterate over the strings to be replaced
    for elem in toBeReplaces :
        # Check if string is in the main string
        if elem in mainString :
            # Replace the string
            mainString = mainString.replace(elem, newString)
    
    return  mainString

def sayText(txt):
    print("Saying: "+txt)
    txtTmp = txt.replace(" ", "_")
    audioFilename = os.path.dirname(os.path.realpath(__file__))+"/"+getAudioFilename(txtTmp,True)
    csvFilename = os.path.dirname(os.path.realpath(__file__))+"/"+getCsvFilename(txtTmp,True)
    
    if not os.path.exists(audioFilename):
        TTS(txt,audioFilename)
    
    timestampes = []
    if not os.path.exists(csvFilename):
        timestampes = getPhonemesTiming(txt,csvFilename)
    else:
        with open(csvFilename, 'r') as read_obj:
            csv_reader = csv.reader(read_obj)
            timestampes = list(csv_reader)
    #print(timestampes)
    
        
    allExpressions = [str]
    allDurations = [float]
    for word in timestampes:
        expressions = ''.join([i for i in word[1] if not i.isdigit()])
        
        expressions = replaceMultiple(expressions, ['AE','AX','AA','AH','AY','EH','ER'], '1')
        expressions = replaceMultiple(expressions, ['AO','KG','AW'], '2')
        expressions = replaceMultiple(expressions, ['FV'], '3')
        expressions = replaceMultiple(expressions, ['PV'], '4')
        expressions = replaceMultiple(expressions, ['CH','DH'], '5')
        expressions = replaceMultiple(expressions, ['HH'], '7')
        expressions = replaceMultiple(expressions, ['IY','EY','IH'], '8')
        expressions = replaceMultiple(expressions, ['TD'], '9')
        expressions = replaceMultiple(expressions, ['NG'], '10')
        expressions = replaceMultiple(expressions, ['OW','OY'], '11')
        expressions = replaceMultiple(expressions, ['SH','SZ','SZH','ZH','JH'], '12')
        expressions = replaceMultiple(expressions, ['TH'], '13')
        expressions = replaceMultiple(expressions, ['UH','UW'], '14')
        
        expressions = replaceMultiple(expressions, ['B','M','P'], '3')
        expressions = replaceMultiple(expressions, ['F','V'], '4')
        expressions = replaceMultiple(expressions, ['G','K','D'], '5')
        expressions = replaceMultiple(expressions, ['L'], '6')
        expressions = replaceMultiple(expressions, ['H'], '7')
        expressions = replaceMultiple(expressions, ['Y'], '8')
        expressions = replaceMultiple(expressions, ['T'], '9')
        expressions = replaceMultiple(expressions, ['N'], '10')
        expressions = replaceMultiple(expressions, ['W'], '11')
        expressions = replaceMultiple(expressions, ['Z','S'], '12')
        expressions = replaceMultiple(expressions, ['R'], '14')
        
        expressions = expressions.split()
        allExpressions.extend(expressions)
    
    print(allExpressions)
    
    for item in timestampes:
        start = float(item[2])
        end = float(item[3])
        num = len(item[1].split())
        duration = (end-start)/num
        times = []
        for i in range(num):
            times.append(start+duration*i)
        allDurations.extend(times)
    
    #print(allDurations)
    
    mixer.init()
    mixer.music.load(audioFilename)
    mixer.music.play(0)
    
    pos = 0
    #sendExpression(allExpressions[0])
    while mixer.music.get_busy() == True:
        if pos == len(allDurations)-1:
            pass
        elif mixer.music.get_pos() >= allDurations[pos+1]*1000:
            pos += 1
            sendExpression(allExpressions[pos])
            
    sendExpression('0')

if __name__ == '__main__':
    rospy.init_node('speechNode', anonymous=True)
    rospy.Subscriber('speach', String, callbackSpeach)
    pub = rospy.Publisher('head', Head, queue_size=10)
    rospy.Subscriber('head', Head, callbackHead)

    rospy.spin()
        