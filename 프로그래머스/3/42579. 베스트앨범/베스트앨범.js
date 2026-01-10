function solution(genres, plays) {
    const genreMap = new Map();
    
    
    genres.forEach((genre, index) => {
        const play = plays[index];
        
        if (!genreMap.has(genre)) {
            genreMap.set(genre, {total: 0, songs: []});
        }
        
        const data = genreMap.get(genre);
        data.total += play;
        data.songs.push({index, play});
    });
    
    return [...genreMap.values()]
            .sort((a, b) => b.total - a.total)
            .flatMap(item => {
               return item.songs
                        .sort((a, b) => b.play - a.play || a.index - b.index)
                        .slice(0, 2)
                        .map(song => song.index);
            });
}