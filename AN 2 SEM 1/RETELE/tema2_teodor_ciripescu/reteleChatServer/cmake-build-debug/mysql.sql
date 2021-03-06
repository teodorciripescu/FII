PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "users" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"username"	TEXT NOT NULL UNIQUE,
	"password"	TEXT NOT NULL
);
INSERT INTO users VALUES(1,'teodor','parola');
CREATE TABLE IF NOT EXISTS "friend_lists" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"owner"	INTEGER NOT NULL,
	"friend" INTEGER NOT NULL,
	FOREIGN KEY("owner") REFERENCES users("id"),
	FOREIGN KEY("friend") REFERENCES users("id")
);
CREATE TABLE IF NOT EXISTS "conversations" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"owner"	INTEGER NOT NULL,
	"other_participant" INTEGER NOT NULL,
	FOREIGN KEY("owner") REFERENCES users("id"),
	FOREIGN KEY("other_participant") REFERENCES users("id")
);
CREATE TABLE IF NOT EXISTS "messages" (
	"id"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	"id_conversation"	INTEGER NOT NULL,
	"sender" INTEGER NOT NULL,
	"content" TEXT NOT NULL,
	"seen" INTEGER DEFAULT 0,
	"time" TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
	"reply_to" INTEGER,
	FOREIGN KEY("id_conversation") REFERENCES conversations("id"),
	FOREIGN KEY("sender") REFERENCES users("id"),
	FOREIGN KEY("reply_to") REFERENCES messages("id")
);
DELETE FROM sqlite_sequence;
INSERT INTO sqlite_sequence VALUES('users',1);
COMMIT;
