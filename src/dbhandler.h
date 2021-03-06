/*
 * dbhandler.h
 *
 *  Created on: Sep 1, 2012
 *      Author: frost
 */
#include <set>
#include <map>
#include <vector>
#include <mongo.h>
#include "tweet.h"
#include "word.h"

#define TWEETS "test.tweets"
#define PRICE_HISTORY "test.price_history"
#define LEXICON "test.lexicon"
//#define TWEETS "mimirswell.tweets"
//#define PRICE_HISTORY "mimirswell.price_history"
//#define LEXICON "mimirswell.lexicon"

#ifndef DBHANDLER_H_
#define DBHANDLER_H_

class DBHandler {
private:
	std::string host;
	int port;
	bool connect(mongo& db);
	std::string getMongoDBError(int status);
	bool writeDocs(const bson** docs, const char* ns, int numDocs);
	long getLastLexiconUpdate();
	void setLastLexiconUpdate(long lastUpdate);
	std::vector<Word> parseTweets(long sinceTime);
public:
	DBHandler();
	virtual ~DBHandler();
	bool addHistory(const std::map<long, double>& prices, const char* symbol);
	bool addTweets(const std::set<Tweet>& tweets);
	long getMostRecentID(const char* symbol);
	std::set<Tweet> getTweets();
	int addWords();
};

#endif /* DBHANDLER_H_ */
