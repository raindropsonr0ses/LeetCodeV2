// Instead of comparing every pair that would take O(n^2), an effient way is to use a hash map
//The big picture to go through the array once: For each number, we will check if the number needed to reach the target(the compliment) is already in our hash table
//If it is, we are done. And if it's not we'll add the current number and continue with our search.

#define HASH_SIZE 10000
typedef struct {
    int key;
    int value;
} HashNode; //Each hash table entry will contain a key and corresponding value. 
//Here key will be nums[i] and value will be i

// Next defining the Hash function:

int hash (int key){
    return abs(key) % HASH_SIZE;
}

int *twoSum(int* nums, int numSize, int target, int*returnSize){
    *returnSize =2;
    int* result =(int*)malloc(2*sizeof(int)); // Allocating Space for the result

    HashNode* hashTable[HASH_SIZE]={0}; //created hash table and initialized to all 0. hashTable is an array of pointers to HashNOde structs

    for(int i=0; i<numSize; i++){
        int complement = target - nums[i]; // for each number we'll calculate how much we need to reach the target
        int h =hash(complement); // then we compute the above number's hash ie we do this to locate the number in the table

 //Now checking if that number is in the hash table: (Read the next step below if confused, will make sense more)
        while(hashTable[h] != NULL){
             if(hashTable[h]->key == complement){
            result[0]=hashTable[h]->value;
            result[1]=i;
            return result;
             }

            h=(h+1)% HASH_SIZE;
        }
 
// Next step: Insert current number and its index into hash table

        int index= hash(nums[i]);
        while(hashTable[index] != NULL){
            index=(index+1)% HASH_SIZE;
        }

        hashTable[index]=(HashNode*)malloc(sizeof(HashNode));
        hashTable[index]->key=nums[i];
        hashTable[index]->value =i;

    }

        free(result);
        *returnSize =0;
        return NULL;
}    


