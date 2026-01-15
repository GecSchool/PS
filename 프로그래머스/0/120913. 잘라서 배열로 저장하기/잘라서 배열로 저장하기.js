function solution(my_str, n) {
    return my_str.split('').reduce((acc, char) => {
        const last = acc[acc.length - 1];
        if (last && last.length < n) {
            acc[acc.length - 1] += char;
        } else {
            acc.push(char);
        }
        return acc;
    }, []);
}