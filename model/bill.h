
SalesCheck* createBill(int id, Seller* seller, Client* client, Article* list, int discount, long int totalAmount, long int discountedAmount){
    SalesCheck *bill = new SalesCheck();
    bill->id = id;
    bill->seller = *seller;
    bill->client = *client;
    bill->listArticles = list;

    bill->discount = discount;
    bill->totalAmount = totalAmount;
    bill->discountedAmount = discountedAmount;
    
    return bill;
}