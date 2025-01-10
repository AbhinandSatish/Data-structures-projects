#include "video.h"
#include <iostream> 
#include <string>
#include <vector>
#include <ostream>



Video::Video(){
    ID = "";
    Text = "";
    ViewNum = 0;
    AuthorSound = "";
    MusicName = "";
    MusicID = "";
    CoverURL = "";
    WebVideo = "";
}

Video::Video(const std::string& id, const std::string& text, long viewNum, 
        const std::string& authorSound, const std::string& musicName, const std::string& musicID, 
        const std::string& coverURL, const std::string& webVideoURL, const std::vector<std::string>& hashtags){
    ID = id;
    Text = text;
    ViewNum = viewNum;
    AuthorSound = authorSound;
    MusicName = musicName;
    MusicID = musicID;
    CoverURL = coverURL;
    WebVideo = webVideoURL;
    Hashtags = hashtags;

}

std::string Video::getID() const{
    return ID;
}

std::string Video::getText() const{
    return Text;
}

long Video::getViewNum() const{
    return ViewNum;
}

std::string Video::getAuthorSound() const{
    return AuthorSound;
}

std::string Video::getMusicName() const{
    return MusicName;
}

std::string Video::getMusicID() const{
    return MusicID;
}

std::string Video::getCoverURL() const{
    return CoverURL;
}

std::string Video::getWebVideoURL() const{
    return WebVideo;
}

std::vector<std::string> Video::getHashtags() const{
    return Hashtags;
}

void Video::setID(const std::string& id){
    ID = id;
}

void Video::setText(const std::string& text){
    Text = text;
}

void Video::setViewNum(long viewNum){
    ViewNum = viewNum;
}

void Video::setAuthorSound(const std::string& authorSound){
    AuthorSound = authorSound;
}

void Video::setMusicName(const std::string& musicName){
    MusicName = musicName;
}

void Video::setMusicID(const std::string& musicID){
    MusicID = musicID;
}

void Video::setCoverURL(const std::string& coverURL){
    CoverURL = coverURL;
}

void Video::setWebVideoURL(const std::string& webVideoURL){
    WebVideo = webVideoURL;
}

void Video::setHashtags(const std::vector<std::string>& hashtags){
    Hashtags = hashtags;
}

bool operator<(const Video& lhs, const Video& rhs){
    return lhs.ViewNum < rhs.ViewNum;
}