#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class ErrorException {
public:
    int errNo;
    string errMsg;

    ErrorException(int e, string x) : errNo(e), errMsg(x) {}

    void showError() {
        cout << errNo << ":" << errMsg << endl;
    }
};
int flag=0;
int d=10;
int flag1=0;
class Subscription {
public:
    int subscriptionType;
    string benefits;
    float price;

    Subscription() {
        this->subscriptionType = 0;
    }

    Subscription(int a) {
        this->subscriptionType = a;
    }

    void getSubscription() {
        if (subscriptionType == 1) {
            benefits = "Ad-free music listening -- download upto 50 songs to listen "
                       "offline -- debit and credit card accepted";
            price = 1999;
        } else if (subscriptionType == 2) {
            benefits = "Ad-free music listening -- download upto 1000 songs to "
                       "listen offline, on upto 2 devices per account -- debit and "
                       "credit card accepted";
            price = 3799;
        } else if (subscriptionType == 3) {
            benefits = "Ad-free music listening -- download upto 2000 songs to "
                       "listen offline, on upto 5 devices per account -- debit and "
                       "credit card accepted";
            price = 7499;
        }
    }

    void getPrice() {
        cout << "Price= " << price << endl;
    }

    void getBenefits() {
        cout << "Benefits: " << benefits << endl;
    }
};
class Person {
public:
  string personName;
  string gender;
  Person() {
    this->personName = "";
    this->gender = "";
  }
  Person(string a, string b) {
    this->personName = a;
    this->gender = b;
  }

};


class User : public Person {
public:
    string password;
    string email;
    bool subscriptionStatus;
    string preferenceLanguage;
    string preferenceGenre;
    Subscription* sub;

    User() : Person() {
        this->password = "";
        this->email = "";
        this->subscriptionStatus = false;
        this->preferenceLanguage = "";
        this->preferenceGenre = "";
        this->sub = nullptr;
    }

    User(string a, string b, string c, string d, bool e, string f, string g)
        : Person(a, b), password(c), email(d), subscriptionStatus(e),
          preferenceLanguage(f), preferenceGenre(g), sub(nullptr) {}

    void registerUser() {
        bool has_upper = false, has_lower = false, has_digit = false, has_punct = false;
        for (char c : password) {
            if (isupper(c)) {
                has_upper = true;
            }
            if (islower(c)) {
                has_lower = true;
            }
            if (isdigit(c)) {
                has_digit = true;
            }
            if (ispunct(c)) {
                has_punct = true;
            }
        }

        if (has_upper && has_lower && has_digit && has_punct && password.length() >= 8) {
            // User registration successful
        } else {
            throw ErrorException(1002, "Password is weak.");
        }
    }
};


class SearchEngine {
public:
    void byLyrics(string pattern, string text, int q);
    void byTitle(string name, string pattern);
};
void SearchEngine::byLyrics(string pattern, string text, int q)
{
    int m = pattern.length();
  int n = text.length();
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;


  for (i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }


  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
      {
        flag=1;
      }

    }

    if (i < n - m) {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}



void SearchEngine::byTitle(string name, string pattern)
{
    if(name==pattern)
    {
        flag1=1;
    }
}



class Song {
public:
    string title;
    string language;
    string genre;
    string artist;
    string album;
    string duration;
    string lyrics;
    string ratings;
    SearchEngine* s1;

    Song() {
        this->title = "";
        this->language = "";
        this->genre = "";
        this->artist = "";
        this->album = "";
        this->duration = "";
        this->lyrics = "";
        this->ratings = "";
        this->s1 = nullptr;
    }

    Song(string a, string b, string c, string d, string e, string f, string g, string h)
        : title(a), language(b), genre(c), artist(d), album(e), duration(f), lyrics(g), ratings(h), s1(nullptr) {}

    void getLyrics() {
        ifstream fp1("songs_file.txt");
        string songName;
        cout << "Enter the name of the song to know the lyrics" << endl;
        cin >> songName;
        for (int i = 0; i < 10; i++) {
            Song p1;
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            if (songName == p1.title) {
                cout << "Lyrics of " << songName << endl;
                cout << p1.lyrics << endl;
            }
        }
    }

    void getSong() {
        ifstream fp1("songs_file.txt");
        for (int i = 0; i < 10; i++) {
            Song p1;
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            cout << i << " " << p1.title << endl;
        }
    }

    void getNoOfSong() {
        cout << "count=10" << endl;
    }
};

class Playlist {
public:
    string name;
    int c1, c2, c3;
    int l, j, k;
    string p0[10], p2[10], p3[10];
    string input;
    Song* songs;

    Playlist() {
        this->name = "";
        this->input = "";
        this->c1 = 0;
        this->c2 = 0;
        this->c3 = 0;
        this->l = 0;
        this->j = 0;
        this->k = 0;
    }

    void createPlaylist() {
        ifstream fp1("songs_file.txt");
        Song p1;
        for (int i = 0; i < 10; i++) {
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            string playlistname = p1.language;
            if (playlistname.compare("Hindi") == 0) {
                p0[j] = p1.title;
                j++;
            } else if (playlistname.compare("Kannada") == 0) {
                p2[k] = p1.title;
                k++;
            } else if (playlistname.compare("Telugu") == 0) {
                p3[l] = p1.title;
                l++;
            }
        }
        c1 = j;
        c2 = k;
        c3 = l;
    }

    void searchPlaylist() {
        cout << "Search the playlist of songs with language" << endl;
        cin >> input;
        if (input.compare("Hindi") == 0) {
            for (int i = 0; i < c1; i++) {
                cout << i << " " << p0[i] << endl;
            }
        } else if (input.compare("Kannada") == 0) {
            for (int i = 0; i < c2; i++) {
                cout << i << " " << p2[i] << endl;
            }
        } else if (input.compare("Telugu") == 0) {
            for (int i = 0; i < c3; i++) {
                cout << i << " " << p3[i] << endl;
            }
        }
    }
};
class Album {
public:
    string AlbumTitle;
    string artist;
    int year;
    Song* SongsInAlbums;

    Album() {
        this->AlbumTitle = "";
        this->artist = "";
        this->year = 0;
    }

    Album(string a, string b, int c) : AlbumTitle(a), artist(b), year(c) {}

    void getAlbum() {
        ifstream fp1("songs_file.txt");
        cout << "Albums are: " << endl;
        for (int i = 0; i < 10; i++) {
            Song p1;
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            cout << p1.album << endl;
        }
    }
};
class Artist {
public:
    string ArtistName;
    string genre;
    Song* s1;

    Artist() {
        this->ArtistName = "";
        this->genre = "";
    }

    Artist(string a, string b) : ArtistName(a), genre(b), s1(nullptr) {}

    void getArtist() {
        ifstream fp1("songs_file.txt");
        cout << "Artists are: " << endl;
        string artists[10];
        for (int i = 0; i < 10; i++) {
            Song p1;
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            artists[i] = p1.artist;
        }

        string z = artists[0];
        cout << artists[0] << endl;
        for (int j = 0; j < 10; j++) {
            if (z == artists[j]) {
                continue;
            } else {
                cout << artists[j] << endl;
            }
        }
    }
};
class MusicPlayer {
public:
    Song s1;
    string titles[10];
    string songName;
    int flag = 0;

    void playSong() {
        ifstream fp1("songs_file.txt");
        Song p1;
        for (int i = 0; i < 10; i++) {
            getline(fp1, p1.title);
            getline(fp1, p1.language);
            getline(fp1, p1.genre);
            getline(fp1, p1.artist);
            getline(fp1, p1.album);
            getline(fp1, p1.duration);
            getline(fp1, p1.lyrics);
            getline(fp1, p1.ratings);
            cout << i << "." << p1.title << endl;
            titles[i] = p1.title;
        }
        cout << "Select a song to be played" << endl;
        cin >> songName;
        for (int i = 0; i < 10; i++) {
            if (titles[i].compare(songName)) {
                flag = 0;
            } else {
                cout << "Playing song " << songName << endl;
            }
        }
    }

    void stopSong() {
        cout << "Stopping song." << endl;
    }

    void pauseSong() {
        cout << "Song paused." << endl;
    }

    void nextSong() {
        cout << "Play next song." << endl;
    }

    void previousSong() {
        cout << "Play previous song." << endl;
    }
};
class Recommendation {
public:
    string ratings;
    string title;
    vector<string> values;

    Recommendation() {
        this->ratings = "";
        this->title = "";
    }

    void sortRatings() {
        Recommendation r1;
        ifstream inputFile("Recommendation.txt");
        for (int i = 0; i < 10; i++) {
            getline(inputFile, r1.ratings);
            getline(inputFile, r1.title);
            values.push_back(r1.ratings);
        }
        sort(values.begin(), values.end());
        cout << "Sorted values: " << endl;
        for (string val : values) {
            cout << val << endl;
        }
    }
};

class UserFactory {
public:
    static User createUser(string name, string gender, string password, string email, bool subscriptionStatus, string preferenceLanguage, string preferenceGenre);
};

class SubscriptionFactory {
public:
    static Subscription* createSubscription(int subscriptionType);
};


class SongFactory {
public:
    static Song createSong(string title, string language, string genre, string artist, string album, string duration, string lyrics, string ratings);
};

class ArtistFactory {
public:
    static Artist createArtist(string artistName, string genre);
};

class AlbumFactory {
public:
    static Album createAlbum(string albumTitle, string artist, int year);
};

class RecommendationFactory {
public:
    static Recommendation createRecommendation(string ratings, string title);
};

class PlaylistFactory {
public:
    static Playlist createPlaylist();
};

class MusicPlayerFactory {
public:
    static MusicPlayer createMusicPlayer();
};


Subscription* SubscriptionFactory::createSubscription(int subscriptionType) {
    // Implementation of the createSubscription function here
    Subscription* subscription = nullptr;
    switch (subscriptionType) {
        case 1:
            subscription = new Subscription(1);
            break;
        case 2:
            subscription = new Subscription(2);
            break;
        case 3:
            subscription = new Subscription(3);
            break;
        default:
            // Handle invalid subscriptionType here
            break;
    }
    return subscription;
}
User UserFactory::createUser(string name, string gender, string password, string email, bool subscriptionStatus, string preferenceLanguage, string preferenceGenre) {
    Subscription* sub;

    User user(name, gender, password, email, subscriptionStatus, preferenceLanguage, preferenceGenre);


    try {
        user.registerUser();
    } catch (ErrorException e1) {
        e1.showError();
        cout << "Change the password" << endl;
        cout << "Set a Password\n";
        cin >> password;
        user.password = password;
        user.registerUser();
    }
    return user;
}


Song SongFactory::createSong(string title, string language, string genre, string artist, string album, string duration, string lyrics, string ratings) {
    Song song(title, language, genre, artist, album, duration, lyrics, ratings);
    return song;
}

Artist ArtistFactory::createArtist(string artistName, string genre) {
    Artist artist(artistName, genre);
    return artist;
}

Album AlbumFactory::createAlbum(string albumTitle, string artist, int year) {
    Album album(albumTitle, artist, year);
    return album;
}

Recommendation RecommendationFactory::createRecommendation(string ratings, string title) {
    Recommendation recommendation;
    recommendation.ratings = ratings;
    recommendation.title = title;
    return recommendation;
}

Playlist PlaylistFactory::createPlaylist() {
    Playlist playlist;
    playlist.createPlaylist();
    return playlist;
}

MusicPlayer MusicPlayerFactory::createMusicPlayer() {
    MusicPlayer musicPlayer;
    return musicPlayer;
}


// ... (Previous code)

// Main function
int main() {
    int n, k;
    string a, b, c, d, f, g;
    bool e;

    string line, name;
    ifstream fp1("songs_file.txt");
    int q = 13;

    cout << "Welcome to Swarajna - Enjoy your favorite music anywhere, anytime." << endl;
    cout << "1. New User? - Create Account" << endl;
    cout << "2. Already a User? - Login" << endl;
    cin >> n;

    switch (n) {
        case 1: {
            cout << "Enter name:";
            cin >> a;
            cout << "Gender:";
            cin >> b;
            cout << "Set a Password";
            cin >> c;
            cout << "Email:";
            cin >> d;
            cout << "Need any subscription" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> k;
            e = (k == 1);
            cout << "Preference Language: Hindi/English/Kannada/Telugu : ";
            cin >> f;
            cout << "Preference Genre: Party/Happy/Romantic : ";
            cin >> g;

            UserFactory userFactory;
            User u1 = userFactory.createUser(a, b, c, d, e, f, g);

            if (e) {
                int type;
                cout << "Select type of subscription" << endl;
                cout << "1. 3 months" << endl;
                cout << "2. 6 months" << endl;
                cout << "3. 1 year" << endl;
                cin >> type;

                SubscriptionFactory SubscriptionFactory;
                u1.sub = SubscriptionFactory.createSubscription(type);
                u1.sub->getBenefits();
                u1.sub->getPrice();
            }

            break;
        }
        case 2: {
            cout << "Enter name: " << endl;
            cin >> a;
            cout << "Enter password: " << endl;
            cin >> b;

            UserFactory userFactory;
            User u1 = userFactory.createUser(a, "male", b, "hello@gmail.com", true, "hindi", "happy");
            break;
        }
    }

    int choice1;
    cout << "Do you want to know the details of the song?" << endl;
    cout << "1. Know the lyrics" << endl;
    cout << "2. Know the songs available" << endl;
    cout << "3. Know the total number of songs" << endl;
    cout << "4. Get artists names" << endl;
    cout << "5. Album names" << endl;
    cout << "6. Get playlists details" << endl;
    cout << "7. Recommendation list" << endl;
    cout << "8. Want to play the songs" << endl;
    cin >> choice1;

    switch (choice1) {
        case 1: {
            SongFactory songFactory;
            Song p1 = songFactory.createSong("", "", "", "", "", "", "", "");
            p1.getLyrics();
            break;
        }
        case 2: {
            SongFactory songFactory;
            Song p1 = songFactory.createSong("", "", "", "", "", "", "", "");
            p1.getSong();
            break;
        }
        case 3: {
            SongFactory songFactory;
            Song p1 = songFactory.createSong("", "", "", "", "", "", "", "");
            p1.getNoOfSong();
            break;
        }
        case 4: {
            ArtistFactory artistFactory;
            Artist s1 = artistFactory.createArtist("", "");
            s1.getArtist();
            break;
        }
        case 5: {
            AlbumFactory albumFactory;
            Album B1 = albumFactory.createAlbum("", "", 0);
            B1.getAlbum();
            break;
        }
        case 6: {
            PlaylistFactory playlistFactory;
            Playlist L1 = playlistFactory.createPlaylist();
            L1.searchPlaylist();
            break;
        }
        case 7: {
            RecommendationFactory recommendationFactory;
            Recommendation r1 = recommendationFactory.createRecommendation("", "");
            r1.sortRatings();
            break;
        }
        case 8: {
            MusicPlayerFactory musicPlayerFactory;
            MusicPlayer m1 = musicPlayerFactory.createMusicPlayer();
            m1.playSong();
            break;
        }
    }

    cout << "Do you want to search a song?" << endl;
    cout << "1. By title" << endl;
    cout << "2. By lyrics" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Type the name of the song" << endl;
            cin >> name;
            SongFactory songFactory;
            Song p1 = songFactory.createSong("", "", "", "", "", "", "", "");
            for (int i = 0; i < 10; i++) {
                getline(fp1, p1.title);
                getline(fp1, p1.language);
                getline(fp1, p1.genre);
                getline(fp1, p1.artist);
                getline(fp1, p1.album);
                getline(fp1, p1.duration);
                getline(fp1, p1.lyrics);
                getline(fp1, p1.ratings);
                p1.s1->byTitle(name, p1.title);
                if (flag1 == 1) {
                    cout << p1.album << endl;
                    flag1 = 0;
                }
            }
            break;
        }
        case 2: {
            cout << "SEARCH A SONG" << endl;
            cout << "Enter song line" << endl;
            cin >> line;
            SongFactory songFactory;
            Song p1 = songFactory.createSong("", "", "", "", "", "", "", "");
            for (int i = 0; i < 10; i++) {
                getline(fp1, p1.title);
                getline(fp1, p1.language);
                getline(fp1, p1.genre);
                getline(fp1, p1.artist);
                getline(fp1, p1.album);
                getline(fp1, p1.duration);
                getline(fp1, p1.lyrics);
                getline(fp1, p1.ratings);
                p1.s1->byLyrics(line, p1.lyrics, q);
                if (flag == 1) {
                    cout << p1.title << endl;
                    flag = 0;
                }
            }
            break;
        }
    }

    return 0;
}


