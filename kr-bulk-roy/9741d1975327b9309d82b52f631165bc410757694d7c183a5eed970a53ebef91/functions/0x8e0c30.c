
void FUN_008e0c30(uint *param_1,int *param_2)

{
  int in_EAX;
  
  *param_1 = (uint)*(byte *)(*(int *)(in_EAX + 0x3a0) + 0xb0);
  *param_2 = *(int *)(in_EAX + 0x3a0) + 0xb4;
  return;
}

