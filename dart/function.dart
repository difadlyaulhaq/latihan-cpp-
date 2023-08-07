void main(){
/*List<int> numberlist = [1,2,3,4,5];
List<dynamic> dynamicList = [3,"amcc",4,"jogja"];
List <String> stringlist = ["amcc","amikom","jogja"];
stringlist.add("senia");
stringlist.insert(0,"aku");
//insert dapat menambahkan data sesuai index
stringlist.remove("aku");
stringlist.removeAt(1);
stringlist.removeLast();
stringlist.removeRange(0,2);
var nama = ["senia","difa"] ;
var bulan = ["desember","mei"] ;
var spread = [...nama,...bulan];
print(spread);

var alfaset = {19,25,07};
Set<int> anotherset = new Set.from([19,25,19,07,25]);
alfaset.add(5);
anotherset.add(8);
print(alfaset);*/
var setA = {1,2,3,4,5};
var setB = {3,4,5,6,7,8};
var union = setA.union(setB);
var intersection = setA.intersection(setB);

print(union);
print (intersection);
}