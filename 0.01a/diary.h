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

    vector<Post> getPosts()
    {
        return posts;
    }

    void addPost(Post post)
    {
        posts.push_back(post);
    }


};

#endif // DIARY

