function solution(tickets) {
  let answer = [];
  tickets.sort();
  let done = false;
  dfs("ICN", tickets, []);

  function dfs(departure, remain, route) {
    if (done) return;

    const possibleTickets = remain.filter((item) => item[0] === departure);

    possibleTickets.forEach((possibleTkt) => {
      let tmp_remain = [...remain];
      let tmp_route = [...route];

      const idx = tmp_remain.findIndex((item) => item === possibleTkt);
      tmp_remain.splice(idx, 1);

      if (tmp_route.length === tickets.length - 1) {
        tmp_route = tmp_route.concat(possibleTkt);
        done = true;
        answer = tmp_route;
      } else {
        tmp_route.push(possibleTkt[0]);
        dfs(possibleTkt[1], tmp_remain, tmp_route);
      }
    });
  }

  return answer;
}

console.log(
  solution([
    ["ICN", "JFK"],
    ["HND", "IAD"],
    ["JFK", "HND"],
  ])
);

console.log(
  solution([
    ["ICN", "SFO"],
    ["ICN", "ATL"],
    ["SFO", "ATL"],
    ["ATL", "ICN"],
    ["ATL", "SFO"],
  ])
);
