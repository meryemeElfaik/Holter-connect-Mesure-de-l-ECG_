function decodeUplink(input){
    var data = {};

    data.hr=input.bytes[0]

    return{
        data:data,
        warning:[],
        errors:[]
    };

}