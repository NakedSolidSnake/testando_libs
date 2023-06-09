#include <hiredis/hiredis.h>

int main (int argc, char *argv[])
{
	redisContext *c = redisConnect("redis", 6379);

	if (c != NULL && c->err)
	{
		printf("Error: %s\n", c->errstr);
		// handle error
	}

	else	
	{
		printf("Connected to Redis\n");

		redisReply *reply;

		reply = redisCommand(c,"SET %s %s","foo","bar");
		freeReplyObject(reply);

		reply = redisCommand(c,"GET %s","foo");
		printf("%s\n",reply->str);
		freeReplyObject(reply);
	}

	redisFree(c);
}
