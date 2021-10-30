const time_val = [3600, 60, 1]

function solution(lines) {
    let ans = 0, sum = 0
    const N = lines.length

    const data = new Array(N * 2)

    lines.map((line, idx) => {
        const [_date, _last_time, _range] = line.split(' ')

        const exit = _last_time.split(':').reduce((prev, curr, idx) => (prev + curr * time_val[idx]), 0)
        const range = _range.split('s')[0] * 1
        const start = (exit - range + 0.001) < 0 ? 0 : (exit - range + 0.001)

        data[idx] = [start, 1]; data[idx + N] = [exit + 1, -1]
    })

    data.sort((prev, curr) => {
        const ret = prev[0] - curr[0]
        if(ret == 0) return prev[1] - curr[1]
        return ret
    })

    data.forEach(time => {
        sum += time[1]
        ans = Math.max(ans, sum)
    })
    return ans
}