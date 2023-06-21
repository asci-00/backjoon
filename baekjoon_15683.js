const input = require("fs").readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');
const [size, ...field_input] = input;
const [N, M] = size.split(' ');

const field = Array.from({ length: N * 1 }, () => Array(M * 1));
const visited = Array.from({ length: N * 1 }, () => Array(M * 1).fill(false));
const cctvs = [];

const ways = [
    null,
    [
        [[0, +1]],
        [[+1, 0]],
        [[0, -1]],
        [[-1, 0]],
    ],
    [
        [[0, +1], [0, -1]],
        [[+1, 0], [-1, 0]],
    ],
    [
        [[-1, 0], [0, +1]],
        [[0, +1], [+1, 0]],
        [[+1, 0], [0, -1]],
        [[0, -1], [-1, 0]],
    ],
    [
        [[0, -1], [-1, 0], [0, +1]],
        [[-1, 0], [0, +1], [+1, 0]],
        [[0, +1], [+1, 0], [0, -1]],
        [[+1, 0], [0, -1], [-1, 0]],
    ],
    [[[0, +1], [+1, 0], [0, -1], [-1, 0]],],
    
];

let blindSpot = 0;

field_input.forEach((row, y) => {
    row.trim().split(' ').forEach((item, x) => {
        const _item = item * 1;
        
        if(!_item) blindSpot ++;
        else if(_item < 6) cctvs.push([y, x]);
        
        field[y][x] = _item;
    });
});

const fillField = ([y, x], [wy, wx]) => {
    let ny = y, nx = x;
    const fill_arr = [];
    
    while(true) {
        ny += wy;
        nx += wx;
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || field[ny][nx] === 6) break;
        if(field[ny][nx] || visited[ny][nx]) continue;
        
        fill_arr.push([ny, nx]);
        visited[ny][nx] = true;
    }
    
    return fill_arr;
}

const dfs = (idx, view_cnt) => {
    if(idx === cctvs.length) return view_cnt;
    
    let max_cnt = 0;
    
    const [y, x] = cctvs[idx];
    const target = ways[field[y][x]];
    target.forEach((way, way_idx) => {
        const fill_pos = way.reduce((acc, curr) => [...acc, ...fillField([y, x], curr)], []);
        if(!fill_pos.length && way_idx !== target.length - 1) return;
        max_cnt = Math.max(max_cnt, dfs(idx + 1, fill_pos.length + view_cnt));
        fill_pos.forEach(([fy, fx]) => visited[fy][fx] = false);
    });
    
    return max_cnt;
}

if(cctvs.length) console.log(blindSpot - dfs(0, 0));
else console.log(blindSpot);
