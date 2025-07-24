# Write your MySQL query statement below
SELECT tweet_id 
FROM TWEETS
where char_length(content) > 15;