const [_, ...paths] = require("fs").readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const sortedPaths = paths
    .map((path) => path.replaceAll('\\', ' '))
    .sort()
    .map((file) => file.split(' '));
    
const nowDepths = [];
let prevLastIdx = 0;

sortedPaths.forEach((path, test_idx) => {
    let depth = 0;
    let sameParentPath = true;
    
    path.forEach((file, idx) => {
        if(
            idx <= prevLastIdx && 
            sameParentPath && 
            nowDepths[idx] === file) return;
        
        if(nowDepths.length < idx + 1) nowDepths.push(file);
        else {
            sameParentPath = false;
            nowDepths[idx] = file;
        }
        
        console.log(' '.repeat(idx) + file);
    });
    
    prevLastIdx = path.length - 1;
});
