#ifndef DIARY
#define DIARY
#include <vector>
#include <algorithm>
#include <QDateTime>
#include "post.h"
class Diary{
private:
    vector<Post> posts;
public:
    Diary (vector<Post> posts)
    {
        this->posts = posts;
    }

    Post getPost(int pos)
    {
        return posts.at(pos);
    }

    void addPost(Post post)
    {
        posts.pushBack(post);
    }


};

#endif // DIARY

