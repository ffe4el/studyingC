struct Customer
{
    int id;
    int tArrival; //고객이 도착한 시간
    int tService; //이 고객의 서비스에 필요한 시간
    Customer(int i=0, int tArr=0, int tServ=0)
        :id(i), tArrival(tArr), tService(tServ){}
};
