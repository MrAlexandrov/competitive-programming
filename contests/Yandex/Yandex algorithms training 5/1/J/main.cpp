#include <bits/stdc++.h>
using namespace std;

//#define FILE 1
//#define DEBUGE 1
//#define READER 1

struct coord {
    int x = 0;
    int y = 0;

    void clear() {
        x = 0;
        y = 0;
    }

    friend ostream& operator << (ostream& out, const coord& item) {
        out << item.x << ' ' << item.y;
        return out;
    }
};

struct Image {
    int width = 0;
    int height = 0;
    string layout;
    coord shift;
    coord answer;

    void clear() {
        width = 0;
        height = 0;
        layout.clear();
        shift.clear();
        answer.clear();
    }

    bool read_image(istringstream& line) {
        this->clear();
        bool is_last_parametr = false;
        bool is_line_ended = false;

        while (!is_last_parametr) {
            string parametr;
            if (!(line >> parametr)) {
                #if READER
                cout << "Next parametr was not read" << endl;
                #endif // READER
                string current_line;
                do {
                    getline(cin, current_line);
                } while (current_line.empty());
                #if READER
                cout << "current_line: " << '\"' << current_line << '\"' << endl;
                #endif // READER
                line.clear();
                line.str(current_line);
                line >> parametr;
            }
            #if READER
            cout << "current parametr: \"" << parametr << "\"" << endl;
            #endif // READER
            is_last_parametr = (parametr.back() == ')');
            if (parametr.substr(0, 5) == "width") {
                this->width = stoi(parametr.substr(6, parametr.size() - 6 - (int)is_last_parametr));
            }
            if (parametr.substr(0, 6) == "height") {
                this->height = stoi(parametr.substr(7, parametr.size() - 7 - (int)is_last_parametr));
            }
            if (parametr.substr(0, 6) == "layout") {
                this->layout = parametr.substr(7, parametr.size() - 7 - (int)is_last_parametr);
            }
            //if (this->layout == "floating") {
            if (parametr.substr(0, 2) == "dx") {
                this->shift.x = stoi(parametr.substr(3, parametr.size() - 3 - (int)is_last_parametr));
            }
            if (parametr.substr(0, 2) == "dy") {
                this->shift.y = stoi(parametr.substr(3, parametr.size() - 3 - (int)is_last_parametr));
            }
            //}
        }
        return true;
    }

    bool operator < (const Image& other) const {
        return answer.x < other.answer.x;
    }
    #if DEBUGE
    friend ostream& operator << (ostream& out, const Image& img) {
        out << "width = " << img.width << endl;
        out << "height = " << img.height << endl;
        out << "layout = " << img.layout << endl;
        if (img.layout == "floating") {
            out << "dx = " << img.shift.x << endl;
            out << "dy = " << img.shift.y << endl;
        }
        return out;
    }
    #endif // DEBUGE
};

struct Document {
    int w = 0;
    int h = 0;
    int c = 0;

    coord current_position{0, 0};
    coord last_right_up{0, 0};
    coord next_line{0, h};
    coord next_paragraph{0, h};

    bool need_new_paragraph = false;
    bool was_space_added = false;

    vector <Image> current_line_surrounded_images;

    void update_current_line_surrounded_images() {
        vector <Image> new_array;
        for (int i = 0; i < current_line_surrounded_images.size(); ++i) {
            Image& current_image = current_line_surrounded_images[i];
            if (current_image.answer.y + current_image.height <= current_position.y) {
                continue;
            }
            new_array.push_back(current_image);
        }
        swap(current_line_surrounded_images, new_array);
    }

    void update_next_line(int add) {
        next_line.y = current_position.y + add;
        assert(next_line.x == 0);
    }

    void update_next_paragraph() {
        //if (current_position.x) {
        int max_from_images = next_line.y;
        for (int i = 0; i < current_line_surrounded_images.size(); ++i) {
            Image& current_image = current_line_surrounded_images[i];
            max_from_images = max(max_from_images, current_image.answer.y + current_image.height);
        }
        current_position = {0, max_from_images};
        update_next_line(h);
        last_right_up = current_position;
        next_paragraph.y += h;
        #if DEBUGE
        cout << "Now it's a new paragraph" << endl;
        cout << "current_position = " << current_position;
        #endif // DEBUGE
        //}
        update_current_line_surrounded_images();
    }

    void new_line(int add) {
        #if DEBUGE
        cout << "new_line, add = " << add << endl;
        #endif // DEBUGE
        current_position = next_line;
        update_next_line(add);
        update_current_line_surrounded_images();
    }

    void new_paragraph(int add) {
        // TODO: write newx_paragraph handler
        #if DEBUGE
        cout << "new_paragraph, add = " << add << endl;
        #endif // DEBUGE
        current_position = next_paragraph;
        next_paragraph.y += add;
    }

    coord find_fragment(int needed_width, bool need_space = false) {
        #if DEBUGE
        cout << "find_fragment, needed_width = " << needed_width << " need_space = " << need_space << endl;
        #endif // DEBUGE
        for (;;) {
            coord result(current_position);
            int current_left = current_position.x, current_right = w;
            #if DEBUGE
            cout << "current_position: " << current_position << endl;
            #endif // DEFIND
            bool found = false;
            for (int i = 0; i < current_line_surrounded_images.size(); ++i) {
                Image& current_image = current_line_surrounded_images[i];
                #if DEBUGE
                cout << "Image in line:\n";
                cout << current_image;
                cout << "current_image.answer.x = " << current_image.answer.x << endl;
                cout << "current_image.answer.x + current_image.width = " << current_image.answer.x + current_image.width << endl;
                #endif // DEBUGE
                if (current_image.answer.x + current_image.width < current_position.x) {
                    #if DEBUGE
                    cout << "skip this image, it's lefter than current_position\n";
                    #endif // DEBUGE
                    continue;
                }
                current_right = current_line_surrounded_images[i].answer.x;
                if (needed_width +
                    ((need_space && (current_left == current_position.x && current_left != 0)) ? c : 0) <= current_right - current_left) {
                    found = true;
                    break;
                    //result.x = current_left;
                    //result.y = current_position.y;
                    //return result;
                }
                current_left = current_image.answer.x + current_image.width;
                current_right = (i == current_line_surrounded_images.size() - 1 ?
                                 w :
                                 current_line_surrounded_images[i + 1].answer.x);
                if (needed_width <= current_right - current_left)
                {
                    need_space = false;
                    found = true;
                    break;
                    //result.x = current_left;
                    //result.y = current_position.y;
                    //return result;
                }
            }
            was_space_added = (need_space && (current_left == current_position.x && current_left != 0));
            if (found || (needed_width + (was_space_added ? c : 0) <= current_right - current_left)) {
                #if DEBUGE
                cout << "current_left = " << current_left << endl;
                cout << "was_space_added = " << was_space_added << endl;
                #endif // DEBUGE
                result.x = current_left + (was_space_added ? c : 0);
                result.y = current_position.y;
                #if DEBUGE
                cout << "founded fragment: " << result << endl;
                #endif // DEBUGE
                return result;
            }
            new_line(h);
            need_space = false;
            //was_first_word = true;
        }
        assert(false);
    }

    void add_word(const string& s) {
        coord place = find_fragment((int)s.size() * c, true);
        last_right_up.x = place.x + (int)s.size() * c;
        last_right_up.y = place.y;
        current_position = last_right_up;
    }

    void add_image(Image& img) {
        coord ans(current_position);
        if (img.layout == "floating") {
            ans.x = last_right_up.x + img.shift.x;
            ans.y = last_right_up.y + img.shift.y;
            int left_board = ans.x;
            if (left_board < 0) {
                ans.x += (0 - left_board);
            }
            int right_board = ans.x + img.width;
            if (right_board > w) {
                ans.x -= (right_board - w);
            }
            last_right_up.x = ans.x + img.width;
            last_right_up.y = ans.y;
        }

        if (img.layout == "surrounded") {
            #if DEBUGE
            cout << "surrounded handler" << endl;
            #endif // DEBUGE
            coord place = find_fragment(img.width, false);
            #if DEBUGE
            cout << "place: " << place << endl;
            #endif // DEBUGE
            ans = place;
            img.answer = place;
            last_right_up.x = place.x + img.width;
            last_right_up.y = place.y;
            current_position = last_right_up;
            current_line_surrounded_images.push_back(img);
            sort(current_line_surrounded_images.begin(), current_line_surrounded_images.end());
        }

        if (img.layout == "embedded") {
            #if DEBUGE
            cout << "embedded handler" << endl;
            #endif // DEBUGE
            coord place = find_fragment(img.width, true);
            #if DEBUGE
            cout << "place: " << place << endl;
            #endif // DEBUGE
            ans = place;
            if (h < img.height) {
                next_line.y = max(next_line.y, place.y + img.height);
            }
            last_right_up.x = place.x + img.width;
            last_right_up.y = place.y;
            current_position = last_right_up;
        }

        #if DEBUGE
        for (int i = 0; i < 100; ++i) {
            cout << '*';
        }
        cout << endl;
        #endif // DEBUGE
        cout << ans << endl;
        #if DEBUGE
        for (int i = 0; i < 100; ++i) {
            cout << '*';
        }
        cout << endl;
        #endif // DEBUGE
    }
} doc;

struct Reader {
    istringstream line;
    string current_word;

    Image img;

    bool Read() {
        if (!(line >> current_word)) {
            string current_line;
            do {
                if (!getline(cin, current_line)) {
                    return false;
                }
                #if DEBUGE
                cout << "current_line: " << current_line << endl;
                #endif // DEBUGE
                if (current_line.empty()) {
                    #if DEBUGE
                    cout << "New paragraph handler" << endl;
                    #endif // DEBUGE
                    doc.update_next_paragraph();
                    continue;
                }
                #if DEBUGE
                cout << "current_line.empty(): " << current_line.empty() << endl;
                #endif
            } while (current_line.empty());
            line.clear();
            line.str(current_line);
            //line.seekg(0, ios::beg);
            #if DEBUGE
            //cout << "before line >> current_word;" << endl;
            //cout << "current_line: " << '\"' << current_line << '\"' << endl;
            //cout << line.str() << endl;
            //streampos pos = line.tellg();
            //cout << "pos: " << pos << endl;
            #endif // DEBUGE
            line >> current_word;
            #if DEBUGE
            //cout << "current_word: " << '\"' << current_word << '\"' << endl;
            //cout << "after line >> current_word;" << endl;
            #endif // DEBUGE
        }

        do {
            #if DEBUGE
            cout << "current_word: " << '\"' << current_word << '\"' << endl;
            #endif // DEBUGE
            if (current_word[0] == '(') {           /// It's an image
                if (!img.read_image(line)) {
                    cout << "Something gone wrong while loading image" << endl;
                }
                #if DEBUGE
                cout << img << endl;
                #endif // DEBUGE
                doc.add_image(img);
                #if DEBUGE
                cout << "Added image" << endl;
                #endif // DEBUGE
            } else {
                doc.add_word(current_word);
                #if DEBUGE
                cout << "Added word" << endl;
                cout << endl;
                #endif // DEBUGE
            }
            #if DEBUGE
            cout << "current_position: " << doc.current_position << endl;
            cout << "last_right_up: " << doc.last_right_up << endl;
            cout << "next_line: " << doc.next_line << endl;
            #endif // DEBUGE
        } while (line >> current_word);
        return true;
    }
} main_reader;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #if FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // DEBUGE
    cin >> doc.w >> doc.h >> doc.c;
    doc.next_line.y = doc.h;
    cin.ignore();
    while (main_reader.Read()) {
        ///
    }
    return 0;
}

/**


**/

