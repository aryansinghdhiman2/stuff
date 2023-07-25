function matrixMultiply(first,second){
    var result=new Array(first.length);
    for(let t=0;t<first.length;t++){
        result[t]=new Array(first.length);
    }
    for(var i=0;i<first.length;i++){
        for(var j=0;j<second.length;j++){
            result[i][j]=0;
            for(var k=0;k<first.length;k++){
                result[i][j]+=first[i][k] * second[k][j];
            }
        }   
    }
    return result;
}

let first = [[1,2,3],[4,5,6],[7,8,9]]
let second = [[1,2,3],[4,5,6],[7,8,9]]

console.log(matrixMultiply(first,second))