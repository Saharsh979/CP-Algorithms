var url = 'https://www.google.com';
console.log(__filename);
function log(message)
{
    console.log(message);
}

module.exports.log = log;
module.exports.endPoint = url;