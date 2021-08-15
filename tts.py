from gtts import gTTS
import threading
import pygame
import ffmpeg
from mutagen.mp3 import MP3
import pronouncing

def TTS(txt,filename):
    v =gTTS(text=txt,lang="en")
    v.save(filename)
    #stream = ffmpeg.input(filename)

def getFilename(i):
    filename = "speech/word_"+str(i)+".mp3"
    return filename

def getPhonemes(word):
    pronunciation_list = pronouncing.phones_for_word(word)[0]
    return pronunciation_list

while True:
    thread_list = []
    
    txt = input("say somthing: ")
    words = txt.split()
    
    i = 0
    for word in words:
        # Instantiates the thread
        t = threading.Thread(target=TTS, args=(word,getFilename(i)))
        i += 1
        # Sticks the thread in a list so that it remains accessible
        thread_list.append(t)
        #print(word)

    # from the main-thread, starts child threads
    for thread in thread_list:
        thread.start()
    
    # main-thread 'sleeping' in join-method, waiting for child-thread to finish 
    for thread in thread_list:
        thread.join()
        
    allPhonemes = []
    allDurations = []
    i = 0
    for word in words:
        filename = getFilename(i)
        i += 1
        phonemes = getPhonemes(word).split()
        #print(phonemes)
        audio = MP3(filename)
        duration = (audio.info.length*1000)/len(phonemes)
        #print(audio.info.length)
        allDurations.append(duration)
        allPhonemes.append(phonemes)
    
    i = 0
    for word in words:
        pygame.mixer.init()
        pygame.mixer.music.load(getFilename(i))
        pygame.mixer.music.play()
        
        lastPhon = -1
        while pygame.mixer.music.get_busy() == True:
            phon = int(pygame.mixer.music.get_pos()/allDurations[i])
            if(phon != lastPhon and phon < len(allPhonemes[i])):
                print(allPhonemes[i][phon])
                lastPhon = phon
            continue
        print(" ")
        i += 1
    