#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <regex>
#include <fstream>
#include "video.h"
using namespace std;



class Hashtag{
    public:
        Hashtag() : seenCount(0), useCount(1) {}
        Hashtag(std::string tagName) : tag(tagName), seenCount(0), useCount(1) {}

        std::vector<Video> posts;
        std::string tag;
        long seenCount;
        int useCount;

};



class Sound {
public:
    Sound() : playCount(0) {}  // Default constructor initializes playCount.

    // Constructor initializes members with given parameters.
    Sound(const std::string& soundName, const std::string& author, const std::string& id)
        : sound(soundName), Author(author), soundID(id), playCount(0) {}

    std::vector<Video> posts;    
    std::string sound;          // Name of the sound.
    std::string Author;         // Author of the sound.
    std::string soundID;        // Identifier for the sound.
    long playCount;             // Number of times the sound has been played.

    // Operator overloads to define the sorting criteria for sounds.
    bool operator<(const Sound& other) const {
        if (playCount != other.playCount) {
            return playCount < other.playCount;
        }
        return sound > other.sound;  // Fallback to alphabetical order if playCount is the same.
    }
};




struct HashtagCMP{

    //compare the number of times the hashtag was used, the number of times it was seen 
    //and the name of the hashtag
    bool operator()(const Video& v1, const Video& v2){
        if(v1.getHashtags().size() == v2.getHashtags().size()){
            if(v1.getViewNum() == v2.getViewNum()){
                return v1.getHashtags()[0] > v2.getHashtags()[0];
            }
            return v1.getViewNum() < v2.getViewNum();
        }
        return v1.getHashtags().size() < v2.getHashtags().size();
    }
};

struct SoundCMP{
    bool operator()(const Video& v1, const Video& v2){
        return v1.getAuthorSound() < v2.getAuthorSound();
    }
};


bool sort_tiktoks(const Video& v1, const Video& v2){
    return v1.getViewNum() > v2.getViewNum();
}



void outputHashtag(std::ofstream& output, std::priority_queue<Hashtag, std::vector<Hashtag>, HashtagCMP>& hashtagQueue){
    Hashtag h = hashtagQueue.top();
    output << "========================" << endl; 
    output << "#" << h.tag << endl;
    output << "used " << h.useCount << " times" << endl;
    output << h.seenCount << " views" << endl;
    
    
}


void outputSound(std::ofstream& output, std::priority_queue<Sound, std::vector<Sound>, SoundCMP>& soundQueue){

    
        
    

}

// void hashtagQueue( std::map<std::string, std::vector<Hashtag>>& hashtagMap, std::priority_queue<Video, std::vector<Video>>& hashtagQueue) {
//     // Loop through each entry in the map
//     for (std::map<std::string, std::vector<Video>>::iterator it = hashtagMap.begin(); it != hashtagMap.end(); ++it) {
//         // Push the first video of each vector to the priority queue
//         if (!it->second.empty()) {
//             hashtagQueue.push(it->second[0]);
//         }
//     }
// }



void songQueue(std::unordered_map<std::string, Sound>& musicMap, std::priority_queue<Sound>& musicQueue) {
    // Loop through each entry in the map
    for (std::unordered_map<std::string, Sound>::iterator it = musicMap.begin(); it != musicMap.end(); ++it) {
        // Push the sound to the priority queue
        musicQueue.push(it->second);
    }
    
}




// void hashtagMap(std::vector<Video>& videos, std::priority_queue<Video, std::vector<Video>, HashtagCMP> viewMap){

//     //key is the number of views, the value is the hashtag
//     for(int i = 0; i < videos.size(); i++){
//         std::vector<std::string> hashtags = videos[i].getHashtags();
//         for(int j = 0; j < hashtags.size(); j++){

//             //if the hashtag does not exist in the map, create a new entry
//             if(viewMap.find(hashtags[j]) == viewMap.end()){
//                 Hashtag h = hashtags[j];
//                 h.posts.push_back(videos[i]);
//                 h.seenCount += videos[i].getViewNum();
//                 h.useCount++;
//                 viewMap[hashtags[j]] = h;
//             }
//             //if it already exist, update the hashtag
//             else{
//                 viewMap[hashtags[j]].posts.push_back(videos[i]);
//                 viewMap[hashtags[j]].seenCount += videos[i].getViewNum();
//                 viewMap[hashtags[j]].useCount++;
//             }

            
//         }
//     }

// }


void SoundMap(std::vector<Video>& videos, std::unordered_map<std::string, Sound>& soundMap){

    for(int i = 0; i < videos.size(); i++){
        //iterate through the sound map if there is a sound that is not in the map, create a new entry
        std::unordered_map<std::string, Sound>::iterator it = soundMap.find(videos[i].getID());
            if(it == soundMap.end()){
                Sound s = Sound(videos[i].getMusicName(), videos[i].getAuthorSound(), videos[i].getMusicID());
                s.posts.push_back(videos[i]);
                s.playCount += videos[i].getViewNum();
                soundMap[videos[i].getMusicID()] = s;
            }
            else{
                soundMap[videos[i].getMusicID()].posts.push_back(videos[i]);
                soundMap[videos[i].getMusicID()].playCount += videos[i].getViewNum();
            
    }
    }
    
}


std::vector<std::string> getHashtag(std::string& text, std::vector<std::string>& hashtags){
    std::string currentHashtag;
    bool inHashtag = false;

    for (char ch : text) {
        if (ch == '#') {
            if (inHashtag && !currentHashtag.empty()) {
                hashtags.push_back(currentHashtag);
            }
            currentHashtag = "#";
            inHashtag = true;
        } else if (inHashtag) {
            if (isalnum(ch) || ch == '_') {  // Check if the character is alphanumeric or underscore
                currentHashtag += ch;
            } else {
                if (!currentHashtag.empty() && currentHashtag != "#") {
                    hashtags.push_back(currentHashtag);
                }
                inHashtag = false;
                currentHashtag = "";
            }
        }
    }

    if (inHashtag && !currentHashtag.empty() && currentHashtag != "#") {
        hashtags.push_back(currentHashtag);
    }

    return hashtags;
}


void parseJson(std::string& line, std::vector<Video>& videos){

    std::unordered_map<std::string, std::string> hashtagMap;
    std::string videoID;
    std::string text;
    std::string coverURL;
    std::string webVideoURL;
    long viewCount;

    int startID = line.find("id");
    int endID = line.find(",", startID);
    videoID = line.substr(startID + 6, endID - startID - 7);

    int startText = line.find("text");
    int endText = line.find(",", startText);
    text = line.substr(startText + 8, endText - startText - 9);

    int startCoverURL = line.find("coverURL");
    int endCoverURL = line.find(",", startCoverURL);
    coverURL = line.substr(startCoverURL + 11, endCoverURL - startCoverURL - 12);

    int startWebVideoURL = line.find("webVideoURL");
    int endWebVideoURL = line.find(",", startWebVideoURL);
    webVideoURL = line.substr(startWebVideoURL + 14, endWebVideoURL - startWebVideoURL - 15);

    int startViewCount = line.find("viewNum");
    int endViewCount = line.find(",", startViewCount);
    viewCount = std::stol(line.substr(startViewCount + 10, endViewCount - startViewCount - 11));

    std::vector<std::string> hashtags = getHashtag(text, hashtags);

    //create an object for the tiktok
    Video video = Video(videoID, text, viewCount, "", "", "", coverURL, webVideoURL, hashtags);
    videos.push_back(video);
    
}






int main(int argc, char* argv[]) {

    //check number of arguments
    if(argc != 4){
        std::cout << "Usage: " << argv[0] << " input.json output.txt hashtag" << std::endl;
        return 1;
    }

    //open the input file
    std::string inputFile = std::string(argv[1]);
    std::ifstream input(inputFile);
    if(!input.is_open()){
        std::cout << "Error: cannot open file " << inputFile << std::endl;
        return 1;
    }

    std::string outputFile = std::string(argv[2]);
    std::ofstream output(outputFile);
    if(!output.is_open()){
        std::cout << "Error: cannot open file " << outputFile << std::endl;
        return 1;
    }

    std::string action = std::string(argv[3]);


    //priority queue for hashtags and music
    std::priority_queue<Video, std::vector<Video>, HashtagCMP> hashtagQueue;
    std::priority_queue<Sound> musicQueue;

    //parsing the information
    std::string line;
    std::vector<Video> videos;
    

    while(std::getline(input, line)){
        parseJson(line, videos);
    }

    // if(action == "hashtag"){
    //     std::unordered_map<std::string, Hashtag> viewMap;
    //     hashtagMap(videos, viewMap);
    //     hashtagQueue(viewMap, viewMap); // Fixed: changed to function call
    // }

    if(action == "sound"){

        std::unordered_map<std::string, Sound> musicMap;
        SoundMap(videos, musicMap);
        songQueue(musicMap, musicQueue); // Fixed: changed to function call
    }

    return 0;



}