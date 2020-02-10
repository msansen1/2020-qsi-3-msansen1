open ReasonUrql;

module GetGitInfos = [%graphql
  {|
    query MyQuery {
        user(login: "msansen1") {
          avatarUrl(size: 10)
          followers {
            totalCount
          }
          following {
            totalCount
          }
          name
          bio
          status {
            message
            emojiHTML
          }
        }
      }
|}
];

[@react.component]
let make = (~user: string) => {
  let request = GetGitInfos.make(~name=pokemon, ());
  let ({response}, _) = useQuery(~request, ());

  switch (response) {
  | Data(data) =>
    switch (data##user) {
    | Some(pokemon) =>
      switch (
        user##avatarUrl,
        user##followers,
        user##following,
        user##bio,
        user##status##message,
      ) {
      | (
          Some(avatarUrl),
          Some(followers),
          Some(following),
          Some(bio),
          Some(message),
        ) =>
        <section>
          <div>
            <div>
              <img className=Styles.dexImage src=avatarUrl />
            </div>
            <div>
              <h1> bio->React.string </h1>
              <h2>
              message->React.string
              </h2>
              {switch (followers##totalcount, following##totalcount) {
               | (Some(followersTotal), Some(followingTotal)) =>
                 <div className=Styles.dexGrid>
                   <p> {("Followers: " ++ followersTotal)->React.string} </p>
                   <p> {("Following: " ++ followingTotal)->React.string} </p>
                 </div>
               | (_, _) => React.null
               }}
            </div>
          </div>
        </section>
      | (_, _, _, _, _) => React.null
      }
    | None => React.null
    }
  | Fetching => <div> "Loading"->React.string </div>
  | Error(e) => <div> e.message->React.string </div>
  | NotFound => <div> "Not Found"->React.string </div>
  };
};