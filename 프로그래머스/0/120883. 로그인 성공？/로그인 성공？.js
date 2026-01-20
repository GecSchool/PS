function solution(id_pw, db) {
    let result = 'fail';
    for (const db_id_pw of db){
        db_id_pw[0] === id_pw[0] &&
            (result = db_id_pw[1] === id_pw[1] ? 'login' : 'wrong pw'); 
    }
    
    return result;
}