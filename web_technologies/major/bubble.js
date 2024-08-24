function bubbleSort(array){
    for(var i=0;i<array.length;i++){
        for(var j=0;j<array.length-1;j++){
            if(array[j]>array[j+1]){
                let temp=array[j]
                array[j]=array[j+1]
                array[j+1]=temp
            }
        }
    }
}

let barry= [4,3,8,2,9,1]
console.log(barry)
bubbleSort(barry)
console.log(barry)