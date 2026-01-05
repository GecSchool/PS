function solution(records) {
    const MSG = {
        Enter: '님이 들어왔습니다.',
        Leave: '님이 나갔습니다.'
    };
    
    const nameById = new Map();
    const actions = [];
    
    for (const record of records) {
        const [cmd, id, name] = record.split(' ');
        if (name) nameById.set(id, name);
        if (MSG[cmd]) actions.push({ cmd, id });
    }
    
    return actions.map(({ cmd, id }) => 
        `${nameById.get(id)}${MSG[cmd]}`
    );
}