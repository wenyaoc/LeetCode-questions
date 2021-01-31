#include <math.h>
struct hash_table_entry {
	int hash, key, value;
};
#define hash_fn(key) (abs(key % htable_size) + 1)
#define prob_fn(key) (abs(key % htable_size) + 1)
void  insert_htable(struct hash_table_entry *htable, int htable_size, int key, int value)
{
	int hash = hash_fn(key), tmphash = hash;
	while (htable[tmphash].hash)
		tmphash = prob_fn(tmphash);
	htable[tmphash] = (struct hash_table_entry){hash,key,value};
}
int find_htable(struct hash_table_entry *htable, int htable_size, int key, int*found_idx)
{
	int hash = hash_fn(key), tmphash = hash;
	while (htable[tmphash].hash && htable[tmphash].key != key)
		tmphash = prob_fn(tmphash);
    *found_idx = htable[tmphash].value;
	return htable[tmphash].hash == hash;
}
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int htable_size = numsSize * 2, *p = malloc(sizeof(int) * 2), found_idx;
	struct hash_table_entry *htable = calloc(htable_size + 1, sizeof(struct hash_table_entry));
    *returnSize = 2;
	for (int i = 0; i < numsSize; ++i) {
		if (find_htable(htable, htable_size, target - nums[i], &found_idx)) {
			p[0] = found_idx;
			p[1] = i;
			break;
		} else {
			insert_htable(htable, htable_size, nums[i], i);
		}
	}
    free(htable);
    return p;
}
