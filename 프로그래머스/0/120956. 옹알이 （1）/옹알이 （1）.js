function solution(babbling) {
    const speakable = [ "aya", "ye", "woo", "ma",];
    let count = 0;
    return babbling.map((b) => {
        for (const word of speakable) {
            b = b.replace(word, ' ');
        }
        return b;
    }).filter((w) => w.trim().length === 0).length;
}