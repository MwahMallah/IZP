const airports = 'PHX BKK OKC JFK LAX MEX EZE HEL LOS LAP LIM'.split(' ');

const routes = [
    ['PHX', 'LAX'],
    ['PHX', 'JFK'],
    ['JFK', 'OKC'],
    ['JFK', 'HEL'],
    ['JFK', 'LOS'],
    ['MEX', 'LAX'],
    ['MEX', 'BKK'],
    ['MEX', 'LIM'],
    ['MEX', 'EZE'], 
    ['LIM', 'BKK'],
];

const adjacencyLIst = new Map();

function addNode(airport)
{
    adjacencyLIst.set(airport, []);
}

function addEdge(origin, destination)
{
    adjacencyLIst.get(origin).push(destination);
    adjacencyLIst.get(destination).push(origin);
}

airports.forEach(addNode);
routes.forEach(route=>addEdge(...route));

console.log(adjacencyLIst);


