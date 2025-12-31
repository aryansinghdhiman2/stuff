def initdb(conn):
    curs = conn.cursor()

    curs.execute("""create table if not exists user_table (
                    email varchar(254) primary key,
                    password text NOT NULL
                 );
    """)

    curs.execute("""create sequence if not exists url_seq
                    as bigint
                    start with 100000000000;""")

    curs.execute("""create table if not exists url_table (
                    hash uuid,
                    url_no bigint NOT NULL DEFAULT nextval('url_seq'),
                    url text NOT NULL,
                    user_email varchar(254) NOT NULL references user_table(email),
                    primary key (hash,user_email)
    )""")

    curs.execute("""alter sequence url_seq owned by url_table.url_no""")


    conn.commit()

    curs.close()