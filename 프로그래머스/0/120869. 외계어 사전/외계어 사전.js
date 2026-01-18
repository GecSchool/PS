function solution(spell, dic) {
    for (const word of dic) {
        const splitWord = word.split('');
        let result = 1;
        for (const s of spell) {
            const idx = splitWord.indexOf(s);
            if (idx === -1) {
                result = 2;
                break;
            }
            splitWord.splice(idx, 1);
            if (splitWord.some(ele => ele === s)) result = 2;
        }
        if (result === 1) return 1;
    }
    return 2;
}