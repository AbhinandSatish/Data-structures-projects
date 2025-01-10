#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <queue>
#include <ostream>


class Video{

public:

    //default constructor
    Video();

    //constructor
    Video(const std::string& id, const std::string& text, long viewNum, 
        const std::string& authorSound, const std::string& musicName, const std::string& musicID, 
        const std::string& coverURL, const std::string& webVideoURL, const std::vector<std::string>& hashtags);

    
    //ACCESSORS
    std::string getID() const;
    std::string getText() const;
    long getViewNum() const;
    std::string getAuthorSound() const;
    std::string getMusicName() const;
    std::string getMusicID() const;
    std::string getCoverURL() const;
    std::string getWebVideoURL() const;
    std::vector<std::string> getHashtags() const;

    //MUTATORS
    void setID(const std::string& id);
    void setText(const std::string& text);
    void setViewNum(long viewNum);
    void setAuthorSound(const std::string& authorSound);
    void setMusicName(const std::string& musicName);
    void setMusicID(const std::string& musicID);
    void setCoverURL(const std::string& coverURL);
    void setWebVideoURL(const std::string& webVideoURL);
    void setHashtags(const std::vector<std::string>& hashtags);


private:
    std::string ID;
    std::string Text;
    long ViewNum;
    std::string AuthorSound;
    std::string MusicName;
    std::string MusicID;
    std::string CoverURL;
    std::string WebVideo;
    std::vector<std::string> Hashtags;

    friend bool operator<(const Video& lhs, const Video& rhs);

};
#endif


